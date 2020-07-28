package utils

import (
	// framework "github.com/tensorflow/tensorflow/tensorflow/go/core/framework"
	pb "github.com/alwaysproblem/tensorflow_serving"
	google_protobuf "github.com/golang/protobuf/ptypes/wrappers"
)

func ModelVersion(version int64) (VersionSpec *pb.ModelSpec_Version){
	return &pb.ModelSpec_Version{
		Version: &google_protobuf.Int64Value{
			Value: version,
		},
	}
}

func ModelVersionLabel(label string) (VersionLabelSpec *pb.ModelSpec_VersionLabel){
	return &pb.ModelSpec_VersionLabel{
		VersionLabel: label,
	}
}

// TODO: finish it 
// NewPredictRequest declare a new request proto
func NewModelSpec() (pm *pb.ModelSpec) {
	return &pb.ModelSpec{
			Name:          "",
			SignatureName: "serving_default",
			// `VersionChoice` need to be specified by function ModelVersion,
			// ModelVersionLabel in the util.go if needed.
			// Recommended to be left unset in the common case.
		}
}

// TODO: finish it 
// NewPredictRequest declare a new request proto
func NewGetModelStatusRequest() (pr *pb.GetModelStatusRequest) {
	return &pb.GetModelStatusRequest{
		ModelSpec: NewModelSpec(),
	}
}

// this is the same as versionctl.config file
func NewModelConfig() (mc *pb.ModelConfig){
	return &pb.ModelConfig{
		Name: "",
		BasePath: "",
		ModelPlatform: "",
	}
}

func ModelServerConfigModelConfigList() (mcs *pb.ModelServerConfig_ModelConfigList){
	// please append model condfig to this list.
	return &pb.ModelServerConfig_ModelConfigList{
		ModelConfigList: &pb.ModelConfigList{
			Config: make([]*pb.ModelConfig, 0),
		},
	}
}

func ModelServerConfigCustomModelConfig(){

}

// TODO: finish it
// NewPredictRequest declare a new request proto
func NewReloadConfigRequest() (pr *pb.ReloadConfigRequest) {
	return &pb.ReloadConfigRequest{
		Config: &pb.ModelServerConfig{
			// Config: 
			// Types that are assignable to Config:
			// ModelServerConfig_ModelConfigList
			// ModelServerConfig_CustomModelConfig
		},
	}
}
