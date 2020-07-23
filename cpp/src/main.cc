#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>

#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"
#include "google/protobuf/map.h"

#include "gen/tensorflow/core/framework/types.grpc.pb.h"
#include "gen/tensorflow/core/framework/tensor.grpc.pb.h"
#include "gen/tensorflow/core/framework/tensor_shape.grpc.pb.h"
#include "gen/tensorflow_serving/apis/predict.grpc.pb.h"
#include "gen/tensorflow_serving/apis/prediction_service.grpc.pb.h"

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
  std::string callPredict(const std::string& model_name, const std::string& model_signature_name,
                          std::vector<float>& measurement) {

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

    for (const float& e : measurement){
      proto.add_float_val(e);
    }

    proto.mutable_tensor_shape()->add_dim()->set_size(3);
    proto.mutable_tensor_shape()->add_dim()->set_size(2);

    inputs["input_1"] = proto;

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

        if ("predict" == section) {
          int titer;
          for (titer = 0; titer != result_tensor_proto.int64_val_size(); ++titer) {
            std::cout << result_tensor_proto.int64_val(titer) << ", ";
          }
        } else if ("output_1" == section) {
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


/*
Application entry point
*/
int main(int argc, char** argv) {
  const std::string model_name = "Toy";
  const std::string model_signature_name = "serving_default";

  std::vector<float> data {
    1., 2.,
    1., 3.,
    1., 4.,
  };
  
  std::string server = "172.17.0.3:8500";

  // // parse arguments
  // for (int i = 0; i < argc; ++i) {
  //   if (std::string(argv[i]) == "--server" && i + 1 < argc) {
  //     server = argv[++i];
  //   }
  // }

  std::cout << "calling prediction service on " << server << std::endl;

  // create and call serving client
  ServingClient guide(grpc::CreateChannel(server, grpc::InsecureChannelCredentials()));
  // std::cout << "calling predict using file: " << image_file << "  ..." << std::endl;
  std::cout << guide.callPredict(model_name, model_signature_name, data) << std::endl;
  return 0;
}
