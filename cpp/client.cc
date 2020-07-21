#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"
#include "google/protobuf/map.h"

#include "types.grpc.pb.h"
#include "tensor.grpc.pb.h"
#include "tensor_shape.grpc.pb.h"
#include "predict.grpc.pb.h"
#include "prediction_service.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using tensorflow::TensorProto;
using tensorflow::TensorShapeProto;
using tensorflow::serving::PredictRequest;
using tensorflow::serving::PredictResponse;
using tensorflow::serving::PredictionService;

typedef google::protobuf::Map<std::string, tensorflow::TensorProto> OutMap;

class ServingClient {
 public:
  ServingClient(std::shared_ptr<Channel> channel)
      : stub_(PredictionService::NewStub(channel)) {}

  // Assembles the client's payload, sends it and presents the response back
  // from the server.
  std::string callPredict(const std::string& model_name,
                          const float& measurement) {

    // Data we are sending to the server.
    PredictRequest request;
    request.mutable_model_spec()->set_name(model_name);

    // Container for the data we expect from the server.
    PredictResponse response;

    // Context for the client. It could be used to convey extra information to
    // the server and/or tweak certain RPC behaviors.
    ClientContext context;

    google::protobuf::Map<std::string, tensorflow::TensorProto>& inputs =
      *request.mutable_inputs();

    tensorflow::TensorProto proto;
    proto.set_dtype(tensorflow::DataType::DT_FLOAT);
    proto.add_float_val(measurement);

    proto.mutable_tensor_shape()->add_dim()->set_size(5);
    proto.mutable_tensor_shape()->add_dim()->set_size(8);
    proto.mutable_tensor_shape()->add_dim()->set_size(105);

    inputs["inputs"] = proto;

    // The actual RPC.
    Status status = stub_->Predict(&context, request, &response);

    // Act upon its status.
    if (status.ok()) {
      std::cout << "call predict ok" << std::endl;
      std::cout << "outputs size is " << response.outputs_size() << std::endl;

      OutMap& map_outputs = *response.mutable_outputs();
      OutMap::iterator iter;
      int output_index = 0;

      for (iter = map_outputs.begin(); iter != map_outputs.end(); ++iter) {
        tensorflow::TensorProto& result_tensor_proto = iter->second;
        std::string section = iter->first;
        std::cout << std::endl << section << ":" << std::endl;

        if ("classes" == section) {
          int titer;
          for (titer = 0; titer != result_tensor_proto.int64_val_size(); ++titer) {
            std::cout << result_tensor_proto.int64_val(titer) << ", ";
          }
        } else if ("scores" == section) {
          int titer;
          for (titer = 0; titer != result_tensor_proto.float_val_size(); ++titer) {
            std::cout << result_tensor_proto.float_val(titer) << ", ";
          }
        }
        std::cout << std::endl;
        ++output_index;
      }
      return "Done.";
    } else {
      std::cout << "gRPC call return code: " << status.error_code() << ": "
                << status.error_message() << std::endl;
      return "RPC failed";
    }
  }

 private:
  std::unique_ptr<PredictionService::Stub> stub_;
};