package utils

import (
	framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework/tensor_go_proto"
	pb "github.com/alwaysproblem/tensorflow_serving"
)

// NewPredictRequest declare a new request proto
func NewPredictRequest() (pr *pb.PredictRequest) {
	return &pb.PredictRequest{
		ModelSpec: &pb.ModelSpec{
			Name:          "",
			SignatureName: "serving_default",
			// `VersionChoice` need to be specified by function ModelVersion,
			// ModelVersionLabel in the util.go if needed.
			// Recommended to be left unset in the common case.
		},
		Inputs: make(map[string]*framework.TensorProto),
		OutputFilter: []string{},
	}
}

// // TODO: finish it 
// // NewPredictRequest declare a new request proto
// func NewClassifyRequest() (pr *pb.PredictRequest) {
// 	return &pb.PredictRequest{
// 		ModelSpec: &pb.ModelSpec{
// 			Name:          "",
// 			SignatureName: "serving_default",
// 			// `VersionChoice` need to be specified by function ModelVersion,
// 			// ModelVersionLabel in the util.go if needed.
// 			// Recommended to be left unset in the common case.
// 		},
// 		Inputs: make(map[string]*framework.TensorProto),
// 	}
// }

// // TODO: finish it 
// // NewPredictRequest declare a new request proto
// func NewRegressRequest() (pr *pb.PredictRequest) {
// 	return &pb.PredictRequest{
// 		ModelSpec: &pb.ModelSpec{
// 			Name:          "",
// 			SignatureName: "serving_default",
// 			// `VersionChoice` need to be specified by function ModelVersion,
// 			// ModelVersionLabel in the util.go if needed.
// 			// Recommended to be left unset in the common case.
// 		},
// 		Inputs: make(map[string]*framework.TensorProto),
// 	}
// }

// // TODO: finish it 
// // NewPredictRequest declare a new request proto
// func NewMultiInferenceRequest() (pr *pb.PredictRequest) {
// 	return &pb.PredictRequest{
// 		ModelSpec: &pb.ModelSpec{
// 			Name:          "",
// 			SignatureName: "serving_default",
// 			// `VersionChoice` need to be specified by function ModelVersion,
// 			// ModelVersionLabel in the util.go if needed.
// 			// Recommended to be left unset in the common case.
// 		},
// 		Inputs: make(map[string]*framework.TensorProto),
// 	}
// }

// TODO: finish it 
// NewPredictRequest declare a new request proto
func NewGetModelMetadataRequest(field []string) (pr *pb.GetModelMetadataRequest) {
	return &pb.GetModelMetadataRequest{
		ModelSpec: &pb.ModelSpec{
			Name:          "",
			SignatureName: "serving_default",
			// `VersionChoice` need to be specified by function ModelVersion,
			// ModelVersionLabel in the util.go if needed.
			// Recommended to be left unset in the common case.
		},
		MetadataField: field,
	}
}

