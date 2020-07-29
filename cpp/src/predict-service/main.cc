#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <map>
// #include <cstdint>

#include <grpcpp/grpcpp.h>
#include <boost/program_options.hpp>
#include <boost/any.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"
#include "google/protobuf/map.h"

#include "tensorflow/core/framework/types.grpc.pb.h"
#include "tensorflow/core/framework/tensor.grpc.pb.h"
#include "tensorflow/core/framework/tensor_shape.grpc.pb.h"
#include "tensorflow_serving/apis/predict.grpc.pb.h"
#include "tensorflow_serving/apis/prediction_service.grpc.pb.h"
#include "tensorflow/core/example/example.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using tensorflow::TensorProto;
using tensorflow::TensorShapeProto;
using tensorflow::serving::PredictRequest;
using tensorflow::serving::PredictResponse;
using tensorflow::serving::PredictionService;

using namespace boost::program_options;

typedef google::protobuf::Map<std::string, tensorflow::TensorProto> OutMap;


// std::unique_ptr<TensorProto> can be used without memory release.
std::unique_ptr<TensorProto> make_tensor_proto(std::vector<boost::any> inputs, 
                        tensorflow::DataType dtype, std::vector<int> input_shape){
    TensorProto* proto = new tensorflow::TensorProto() ;

    switch (dtype){

      case tensorflow::DataType::DT_STRING:
        proto->set_dtype(tensorflow::DataType::DT_STRING);
        for (auto e : inputs){
          const char* tp_data = boost::any_cast<const char*>(e);
          proto->add_string_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_INT64:
        proto->set_dtype(tensorflow::DataType::DT_INT64);
        for (auto e : inputs){
          long tp_data = boost::any_cast<long>(e);
          proto->add_int64_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_FLOAT:
        proto->set_dtype(tensorflow::DataType::DT_FLOAT);
        for (auto e : inputs){
          float tp_data = float(boost::any_cast<double>(e));
          proto->add_float_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_DOUBLE:
        proto->set_dtype(tensorflow::DataType::DT_DOUBLE);
        for (auto e : inputs){
          double tp_data = boost::any_cast<double>(e);
          proto->add_double_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_COMPLEX64:
        proto->set_dtype(tensorflow::DataType::DT_COMPLEX64);
        for (auto e : inputs){
          float tp_data = float(boost::any_cast<double>(e));
          proto->add_float_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_HALF:
        proto->set_dtype(tensorflow::DataType::DT_HALF);
        for (auto e : inputs){
          int tp_data = boost::any_cast<int>(e);
          proto->add_int_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_INT8:
        proto->set_dtype(tensorflow::DataType::DT_INT8);
        for (auto e : inputs){
          int tp_data = boost::any_cast<int>(e);
          proto->add_int_val(tp_data);
        }
        break;
      case tensorflow::DataType::DT_INT32:
        proto->set_dtype(tensorflow::DataType::DT_INT32);
        for (auto e : inputs){
          int tp_data = boost::any_cast<int>(e);
          proto->add_int_val(tp_data);
        }
        break;
      // case tensorflow::DataType::DT_VARIANT:
      //   proto.set_dtype(tensorflow::DataType::DT_VARIANT);
      //   tp_data = boost::any_cast<>;
        // for (const float& e : tp_data){
        //   proto.add_float_val(e);
        // }
      //   break;
      default:
        throw "Unkown dataType";
    };

    for (int& s : input_shape){
      proto->mutable_tensor_shape()->add_dim()->set_size(s);
    }

    return std::unique_ptr<TensorProto>(proto);
}

/*
Application entry point
*/
int main(int argc, char** argv) {

  std::string server_addr = "172.17.0.3:8500";
  std::string model_name = "FC";
  int model_version = -1;
  std::string model_version_label = "";
  const std::string model_signature_name = "serving_default";

  // for parse argument
  variables_map vm;

  // grpc context
  ClientContext context;
  unsigned int timout_in_sec = 5;

  // predict request
  PredictRequest request;
  PredictResponse response;

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

  // start a
  std::shared_ptr<Channel> channel = grpc::CreateChannel(server_addr, grpc::InsecureChannelCredentials());
  std::unique_ptr<PredictionService::Stub> stub =PredictionService::NewStub(channel);

  request.mutable_model_spec()->set_name(model_name);
  request.mutable_model_spec()->set_signature_name(model_signature_name);

  if (model_version > -1){
    request.mutable_model_spec()->mutable_version()->set_value(model_version);
  }

  if (model_version_label != ""){
    request.mutable_model_spec()->set_version_label(model_version_label);
  }

  std::map<std::string, std::vector<boost::any>> inputs;

  inputs["aid"] = std::vector<boost::any> {static_cast<const char *>("dgadfadsfag"), 
                                                static_cast<const char *>("sdfgad")};

  inputs["click_adid"] = std::vector<boost::any> {
      static_cast<const char *>("sdfgad"), 
      static_cast<const char *>("adgas"), 
      static_cast<const char *>("adgasdfd"), 
      static_cast<const char *>("asdgadsg"),
      static_cast<const char *>("asdgadsfa"), 
      static_cast<const char *>("Asdgasd"), 
      static_cast<const char *>("Asdga"), 
      static_cast<const char *>(""),

      static_cast<const char *>("sdfgad"), 
      static_cast<const char *>("adgas"), 
      static_cast<const char *>("adgasdfd"), 
      static_cast<const char *>(""), 
      static_cast<const char *>(""), 
      static_cast<const char *>(""), 
      static_cast<const char *>(""), 
      static_cast<const char *>(""),
    };

  inputs["age"] = std::vector<boost::any> {63L, 67L};
  inputs["cp"] = std::vector<boost::any> {1L, 4L};
  inputs["chol"] = std::vector<boost::any> {233L, 286L};
  inputs["oldpeak"] = std::vector<boost::any> {2.3, 1.5};
  
  std::map<std::string, std::vector<int>>inputShape {
  	{"aid", {2, 1}},
  	{"click_adid", {2, 8}},
  	{"age", {2, 1}},
  	{"cp", {2, 1}},
  	{"chol", {2, 1}},
  	{"oldpeak", {2, 1}},
  };
  
  std::map<std::string, tensorflow::DataType> DataType {
    {"aid", tensorflow::DataType::DT_STRING},
    {"click_adid", tensorflow::DataType::DT_STRING},
    {"age", tensorflow::DataType::DT_INT64},
    {"cp", tensorflow::DataType::DT_INT64},
    {"chol", tensorflow::DataType::DT_INT64},
    {"oldpeak", tensorflow::DataType::DT_FLOAT},
  };

  OutMap& minputs = *request.mutable_inputs();

  for (auto x : inputs){
    std::string key = x.first;
    std::vector<boost::any> data = x.second;
    std::unique_ptr<TensorProto> proto = make_tensor_proto(data, DataType[key], inputShape[key]);
    minputs[key].CopyFrom(*proto);
  }

  // std::cout << request.DebugString() << std::endl;

  // request.mutable_output_filter()->Add("output_2");
  // request.mutable_output_filter()->Add("output_2");

  std::cout << "calling prediction service on " << server_addr << std::endl;
  Status status = stub->Predict(&context, request, &response);

  // Act upon its status.
  if (status.ok()) {

    const std::string output_label = "output_1";

    std::cout << "call predict ok" << std::endl;
    std::cout << "outputs size is " << response.outputs_size() << std::endl;

    std::cout << response.DebugString() << std::endl;

    // OutMap& map_outputs = *response.mutable_outputs();

    // tensorflow::TensorProto& result_tensor_proto = map_outputs[output_label];

    // std::cout << std::endl << output_label << ":" << std::endl;

    // for (int titer = 0; titer != result_tensor_proto.float_val_size(); ++titer) {
    //   std::cout << result_tensor_proto.float_val(titer) << "\n";
    // }
    std::cout << "Done." << std::endl;
  } else {
    std::cout << "gRPC call return code: " << status.error_code() << ": "
              << status.error_message() << std::endl;
    std::cout << "RPC failed" << std::endl;
  }

  return 0;
}
