#include <iostream>
#include <memory>
#include <string>

#include <grpcpp/grpcpp.h>
#include <boost/program_options.hpp>
#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"
#include "google/protobuf/map.h"

#include "tensorflow/core/framework/types.grpc.pb.h"
#include "tensorflow/core/framework/tensor.grpc.pb.h"
#include "tensorflow/core/framework/tensor_shape.grpc.pb.h"
#include "tensorflow_serving/apis/predict.grpc.pb.h"
#include "tensorflow_serving/apis/prediction_service.grpc.pb.h"
#include "tensorflow_serving/apis/get_model_metadata.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using tensorflow::TensorProto;
using tensorflow::TensorShapeProto;
using tensorflow::serving::PredictionService;
using tensorflow::serving::GetModelMetadataRequest;
using tensorflow::serving::GetModelMetadataResponse;

using namespace boost::program_options;
typedef google::protobuf::Map<std::string, google::protobuf::Any> MetadataMap;


/*
Application entry point
*/
int main(int argc, char** argv) {

  std::string server_addr = "172.17.0.2:8500";
  std::string model_name = "Toy";
  int model_version = -1;
  std::string model_version_label = "";
  const std::string model_signature_name = "serving_default";

  // for parse argument
  variables_map vm;

  // grpc context
  ClientContext context;
  unsigned int timout_in_sec = 5;

  // get model metadata request & response
  GetModelMetadataRequest request;
  GetModelMetadataResponse response;

  // parse arguments
  options_description desc("Allowed options");
  desc.add_options()
      // First parameter describes option name/short name
      // The second is parameter to option
      // The third is description
      ("help,h", "print usage message")
      ("server_addr,s", value(&server_addr)->default_value(server_addr),
              "the destination address host:port")
      ("model_name,m", value(&model_name)->default_value(model_name), 
              "the mode name for prediction")
      ("model_version,v", value<int>(&model_version)->default_value(model_version), 
              "the model version for prediction")
      ("model_version_label,l", value(&model_version_label)->default_value(model_version_label), 
              "the annotation name of model version for prediction")
      ;
  
  store(parse_command_line(argc, argv, desc), vm);

  if (vm.count("help")) {  
      std::cout << desc << "\n";
      return 0;
  }

  // set grpc timeout
  std::chrono::system_clock::time_point deadline =
        std::chrono::system_clock::now() + std::chrono::seconds(timout_in_sec);
  context.set_deadline(deadline);
  
  server_addr = vm["server_addr"].as<std::string>();
  model_name = vm["model_name"].as<std::string>();
  model_version = vm["model_version"].as<int>();
  model_version_label = vm["model_version_label"].as<std::string>();

  // crate a channel
  std::shared_ptr<Channel> channel = grpc::CreateChannel(server_addr, grpc::InsecureChannelCredentials());
  std::unique_ptr<PredictionService::Stub> stub =PredictionService::NewStub(channel);

  request.mutable_model_spec()->set_name(model_name);
  request.mutable_metadata_field()->Add("signature_def");
  request.mutable_model_spec()->set_signature_name(model_signature_name);

  if (model_version > -1){
    request.mutable_model_spec()->mutable_version()->set_value(model_version);
  }

  if (model_version_label != ""){
    request.mutable_model_spec()->set_version_label(model_version_label);
  }


  std::cout << "calling prediction service on " << server_addr << std::endl;
  // Status status = stub->Predict(&context, request, &response);
  Status status = stub->GetModelMetadata(&context, request, &response);


  // Act upon its status.
  if (status.ok()) {

    const std::string output_label = "signature_def";

    std::cout << "call predict ok" << std::endl;
    std::cout << "metadata size is " << response.metadata_size() << std::endl;
    std::cout << "metadata DebugString is \n" << response.DebugString() << std::endl;

  } else {
    std::cout << "gRPC call return code: " << status.error_code() << ": "
              << status.error_message() << std::endl;
    std::cout << "RPC failed" << std::endl;
  }

  return 0;
}
