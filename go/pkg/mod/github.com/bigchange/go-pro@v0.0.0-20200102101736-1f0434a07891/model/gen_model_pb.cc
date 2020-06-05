// Produce binary model proto from text proto file. This is needed because
// currently the Go API expect only serialized proto.
#include <memory>

#include "gflags/gflags.h"
#include "glog/logging.h"
#include "tensorflow/core/framework/graph.pb.h"
#include "tensorflow/core/lib/core/status.h"
#include "tensorflow/core/platform/env.h"

namespace tf = ::tensorflow;

DEFINE_string(model_pb_txt, "", "Model text proto file.");
DEFINE_string(model_pb, "", "Model binary proto file.");

int main(int argc, char* argv[]) {
  google::InitGoogleLogging(argv[0]);
  gflags::ParseCommandLineFlags(&argc, &argv, true);
  tf::GraphDef model;
  TF_CHECK_OK(
      tf::ReadTextProto(tf::Env::Default(), FLAGS_model_pb_txt, &model));
  TF_CHECK_OK(tf::WriteBinaryProto(tf::Env::Default(), FLAGS_model_pb, model));
  return 0;
}
