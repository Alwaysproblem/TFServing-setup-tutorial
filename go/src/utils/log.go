package utils

import (
	// framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework"
	pb "github.com/alwaysproblem/tensorflow_serving"
)

func NewLogMetadata() (pl *pb.LogMetadata) {
	return &pb.LogMetadata{
		ModelSpec: NewModelSpec(),
		// SamplingRate: 0.5 float64,
		// you can set this value outside.
		// 	SavedModelTags []string for now only "signature_def"
	}
}

// NewPredictRequest declare a new request proto
func NewPredictionLog(request *pb.PredictRequest, response *pb.PredictResponse) (pl *pb.PredictionLog) {
	return &pb.PredictionLog{
		LogMetadata: NewLogMetadata(),
		LogType: &pb.PredictionLog_PredictLog{
			PredictLog: &pb.PredictLog{
				Request: request,
				Response: response,
			},
		},
	}
}

// // NewPredictRequest declare a new request proto
// func NewPredictionLog(logmetedata *pb.LogMetadata, logtype *pb.isPredictionLog_LogType) (pl *pb.PredictionLog) {
// 	return &pb.PredictionLog{
// 		LogMetadata: logmetedata,
// 		LogType: logtype,
// 	}
// }

// // NewPredictRequest declare a new request proto
// func NewPredictionLogPredictLog(request *pb.PredictRequest, response *pb.PredictResponse) (pl *pb.PredictionLog_PredictLog) {
// 	return &pb.PredictionLog_PredictLog{
// 			PredictLog: &pb.PredictLog{
// 				Request: request,
// 				Response: response,
// 			},
// 		}
// }

// // TODO: finish it
// // NewPredictRequest declare a new request proto
// func NewPredictionLogClassifyLog(request *pb.PredictRequest, response *pb.PredictResponse) (pl *pb.PredictionLog_ClassifyLog) {
// 	return &pb.PredictionLog_ClassifyLog{
// 			ClassifyLog: &pb.ClassifyLog{
// 				Request: request,
// 				Response: response,
// 			},
// 		}
// }

// // TODO: finish it
// // NewPredictRequest declare a new request proto
// func NewPredictionLogRegressLog(request *pb.PredictRequest, response *pb.PredictResponse) (pl *pb.PredictionLog_RegressLog) {
// 	return &pb.PredictionLog_RegressLog{
// 			RegressLog: &pb.RegressLog{
// 				Request: request,
// 				Response: response,
// 			},
// 		}
// }

// // TODO: finish it
// // NewPredictRequest declare a new request proto
// func NewPredictionLogMultiInferenceLog(request *pb.PredictRequest, response *pb.PredictResponse) (pl *pb.PredictionLog_MultiInferenceLog) {
// 	return &pb.PredictionLog_MultiInferenceLog{
// 			MultiInferenceLog: &pb.MultiInferenceLog{
// 				Request: request,
// 				Response: response,
// 			},
// 		}
// }

// // TODO: finish it
// // NewPredictRequest declare a new request proto
// func NewPredictionLogSessionRunLog(request *pb.PredictRequest, response *pb.PredictResponse) (pl *pb.PredictionLog_SessionRunLog) {
// 	return &pb.PredictionLog_SessionRunLog{
// 			SessionRunLog: &pb.SessionRunLog{
// 				Request: request,
// 				Response: response,
// 			},
// 		}
// }

// TODO: finish it
// Metadata logged along with the request logs.
// type LogMetadata struct {
// 	state         protoimpl.MessageState
// 	sizeCache     protoimpl.SizeCache
// 	unknownFields protoimpl.UnknownFields

// 	ModelSpec      *ModelSpec      `protobuf:"bytes,1,opt,name=model_spec,json=modelSpec,proto3" json:"model_spec,omitempty"`
// 	SamplingConfig *SamplingConfig `protobuf:"bytes,2,opt,name=sampling_config,json=samplingConfig,proto3" json:"sampling_config,omitempty"`
// 	// List of tags used to load the relevant MetaGraphDef from SavedModel.
// 	SavedModelTags []string `protobuf:"bytes,3,rep,name=saved_model_tags,json=savedModelTags,proto3" json:"saved_model_tags,omitempty"` // TODO(b/33279154): Add more metadata as mentioned in the bug.
// }
// type SamplingConfig struct {
// 	state         protoimpl.MessageState
// 	sizeCache     protoimpl.SizeCache
// 	unknownFields protoimpl.UnknownFields

// 	// Requests will be logged uniformly at random with this probability. Valid
// 	// range: [0, 1.0].
// 	SamplingRate float64 `protobuf:"fixed64,1,opt,name=sampling_rate,json=samplingRate,proto3" json:"sampling_rate,omitempty"`
// }
// NewPredictRequest declare a new request proto


