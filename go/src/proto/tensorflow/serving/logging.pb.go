// Code generated by protoc-gen-go. DO NOT EDIT.
// versions:
// 	protoc-gen-go v1.24.0-devel
// 	protoc        v3.6.1
// source: tensorflow_serving/core/logging.proto

package serving

import (
	proto "github.com/golang/protobuf/proto"
	protoreflect "google.golang.org/protobuf/reflect/protoreflect"
	protoimpl "google.golang.org/protobuf/runtime/protoimpl"
	reflect "reflect"
	sync "sync"
)

const (
	// Verify that this generated code is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(20 - protoimpl.MinVersion)
	// Verify that runtime/protoimpl is sufficiently up-to-date.
	_ = protoimpl.EnforceVersion(protoimpl.MaxVersion - 20)
)

// This is a compile-time assertion that a sufficiently up-to-date version
// of the legacy proto package is being used.
const _ = proto.ProtoPackageIsVersion4

// Metadata logged along with the request logs.
type LogMetadata struct {
	state         protoimpl.MessageState
	sizeCache     protoimpl.SizeCache
	unknownFields protoimpl.UnknownFields

	ModelSpec      *ModelSpec      `protobuf:"bytes,1,opt,name=model_spec,json=modelSpec,proto3" json:"model_spec,omitempty"`
	SamplingConfig *SamplingConfig `protobuf:"bytes,2,opt,name=sampling_config,json=samplingConfig,proto3" json:"sampling_config,omitempty"`
	// List of tags used to load the relevant MetaGraphDef from SavedModel.
	SavedModelTags []string `protobuf:"bytes,3,rep,name=saved_model_tags,json=savedModelTags,proto3" json:"saved_model_tags,omitempty"` // TODO(b/33279154): Add more metadata as mentioned in the bug.
}

func (x *LogMetadata) Reset() {
	*x = LogMetadata{}
	if protoimpl.UnsafeEnabled {
		mi := &file_tensorflow_serving_core_logging_proto_msgTypes[0]
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		ms.StoreMessageInfo(mi)
	}
}

func (x *LogMetadata) String() string {
	return protoimpl.X.MessageStringOf(x)
}

func (*LogMetadata) ProtoMessage() {}

func (x *LogMetadata) ProtoReflect() protoreflect.Message {
	mi := &file_tensorflow_serving_core_logging_proto_msgTypes[0]
	if protoimpl.UnsafeEnabled && x != nil {
		ms := protoimpl.X.MessageStateOf(protoimpl.Pointer(x))
		if ms.LoadMessageInfo() == nil {
			ms.StoreMessageInfo(mi)
		}
		return ms
	}
	return mi.MessageOf(x)
}

// Deprecated: Use LogMetadata.ProtoReflect.Descriptor instead.
func (*LogMetadata) Descriptor() ([]byte, []int) {
	return file_tensorflow_serving_core_logging_proto_rawDescGZIP(), []int{0}
}

func (x *LogMetadata) GetModelSpec() *ModelSpec {
	if x != nil {
		return x.ModelSpec
	}
	return nil
}

func (x *LogMetadata) GetSamplingConfig() *SamplingConfig {
	if x != nil {
		return x.SamplingConfig
	}
	return nil
}

func (x *LogMetadata) GetSavedModelTags() []string {
	if x != nil {
		return x.SavedModelTags
	}
	return nil
}

var File_tensorflow_serving_core_logging_proto protoreflect.FileDescriptor

var file_tensorflow_serving_core_logging_proto_rawDesc = []byte{
	0x0a, 0x25, 0x74, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x66, 0x6c, 0x6f, 0x77, 0x5f, 0x73, 0x65, 0x72,
	0x76, 0x69, 0x6e, 0x67, 0x2f, 0x63, 0x6f, 0x72, 0x65, 0x2f, 0x6c, 0x6f, 0x67, 0x67, 0x69, 0x6e,
	0x67, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f, 0x12, 0x12, 0x74, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x66,
	0x6c, 0x6f, 0x77, 0x2e, 0x73, 0x65, 0x72, 0x76, 0x69, 0x6e, 0x67, 0x1a, 0x23, 0x74, 0x65, 0x6e,
	0x73, 0x6f, 0x72, 0x66, 0x6c, 0x6f, 0x77, 0x5f, 0x73, 0x65, 0x72, 0x76, 0x69, 0x6e, 0x67, 0x2f,
	0x61, 0x70, 0x69, 0x73, 0x2f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x1a, 0x2e, 0x74, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x66, 0x6c, 0x6f, 0x77, 0x5f, 0x73, 0x65, 0x72,
	0x76, 0x69, 0x6e, 0x67, 0x2f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2f, 0x6c, 0x6f, 0x67, 0x67,
	0x69, 0x6e, 0x67, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x2e, 0x70, 0x72, 0x6f, 0x74, 0x6f,
	0x22, 0xc2, 0x01, 0x0a, 0x0b, 0x4c, 0x6f, 0x67, 0x4d, 0x65, 0x74, 0x61, 0x64, 0x61, 0x74, 0x61,
	0x12, 0x3c, 0x0a, 0x0a, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x5f, 0x73, 0x70, 0x65, 0x63, 0x18, 0x01,
	0x20, 0x01, 0x28, 0x0b, 0x32, 0x1d, 0x2e, 0x74, 0x65, 0x6e, 0x73, 0x6f, 0x72, 0x66, 0x6c, 0x6f,
	0x77, 0x2e, 0x73, 0x65, 0x72, 0x76, 0x69, 0x6e, 0x67, 0x2e, 0x4d, 0x6f, 0x64, 0x65, 0x6c, 0x53,
	0x70, 0x65, 0x63, 0x52, 0x09, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x53, 0x70, 0x65, 0x63, 0x12, 0x4b,
	0x0a, 0x0f, 0x73, 0x61, 0x6d, 0x70, 0x6c, 0x69, 0x6e, 0x67, 0x5f, 0x63, 0x6f, 0x6e, 0x66, 0x69,
	0x67, 0x18, 0x02, 0x20, 0x01, 0x28, 0x0b, 0x32, 0x22, 0x2e, 0x74, 0x65, 0x6e, 0x73, 0x6f, 0x72,
	0x66, 0x6c, 0x6f, 0x77, 0x2e, 0x73, 0x65, 0x72, 0x76, 0x69, 0x6e, 0x67, 0x2e, 0x53, 0x61, 0x6d,
	0x70, 0x6c, 0x69, 0x6e, 0x67, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x52, 0x0e, 0x73, 0x61, 0x6d,
	0x70, 0x6c, 0x69, 0x6e, 0x67, 0x43, 0x6f, 0x6e, 0x66, 0x69, 0x67, 0x12, 0x28, 0x0a, 0x10, 0x73,
	0x61, 0x76, 0x65, 0x64, 0x5f, 0x6d, 0x6f, 0x64, 0x65, 0x6c, 0x5f, 0x74, 0x61, 0x67, 0x73, 0x18,
	0x03, 0x20, 0x03, 0x28, 0x09, 0x52, 0x0e, 0x73, 0x61, 0x76, 0x65, 0x64, 0x4d, 0x6f, 0x64, 0x65,
	0x6c, 0x54, 0x61, 0x67, 0x73, 0x42, 0x03, 0xf8, 0x01, 0x01, 0x62, 0x06, 0x70, 0x72, 0x6f, 0x74,
	0x6f, 0x33,
}

var (
	file_tensorflow_serving_core_logging_proto_rawDescOnce sync.Once
	file_tensorflow_serving_core_logging_proto_rawDescData = file_tensorflow_serving_core_logging_proto_rawDesc
)

func file_tensorflow_serving_core_logging_proto_rawDescGZIP() []byte {
	file_tensorflow_serving_core_logging_proto_rawDescOnce.Do(func() {
		file_tensorflow_serving_core_logging_proto_rawDescData = protoimpl.X.CompressGZIP(file_tensorflow_serving_core_logging_proto_rawDescData)
	})
	return file_tensorflow_serving_core_logging_proto_rawDescData
}

var file_tensorflow_serving_core_logging_proto_msgTypes = make([]protoimpl.MessageInfo, 1)
var file_tensorflow_serving_core_logging_proto_goTypes = []interface{}{
	(*LogMetadata)(nil),    // 0: tensorflow.serving.LogMetadata
	(*ModelSpec)(nil),      // 1: tensorflow.serving.ModelSpec
	(*SamplingConfig)(nil), // 2: tensorflow.serving.SamplingConfig
}
var file_tensorflow_serving_core_logging_proto_depIdxs = []int32{
	1, // 0: tensorflow.serving.LogMetadata.model_spec:type_name -> tensorflow.serving.ModelSpec
	2, // 1: tensorflow.serving.LogMetadata.sampling_config:type_name -> tensorflow.serving.SamplingConfig
	2, // [2:2] is the sub-list for method output_type
	2, // [2:2] is the sub-list for method input_type
	2, // [2:2] is the sub-list for extension type_name
	2, // [2:2] is the sub-list for extension extendee
	0, // [0:2] is the sub-list for field type_name
}

func init() { file_tensorflow_serving_core_logging_proto_init() }
func file_tensorflow_serving_core_logging_proto_init() {
	if File_tensorflow_serving_core_logging_proto != nil {
		return
	}
	file_tensorflow_serving_apis_model_proto_init()
	file_tensorflow_serving_config_logging_config_proto_init()
	if !protoimpl.UnsafeEnabled {
		file_tensorflow_serving_core_logging_proto_msgTypes[0].Exporter = func(v interface{}, i int) interface{} {
			switch v := v.(*LogMetadata); i {
			case 0:
				return &v.state
			case 1:
				return &v.sizeCache
			case 2:
				return &v.unknownFields
			default:
				return nil
			}
		}
	}
	type x struct{}
	out := protoimpl.TypeBuilder{
		File: protoimpl.DescBuilder{
			GoPackagePath: reflect.TypeOf(x{}).PkgPath(),
			RawDescriptor: file_tensorflow_serving_core_logging_proto_rawDesc,
			NumEnums:      0,
			NumMessages:   1,
			NumExtensions: 0,
			NumServices:   0,
		},
		GoTypes:           file_tensorflow_serving_core_logging_proto_goTypes,
		DependencyIndexes: file_tensorflow_serving_core_logging_proto_depIdxs,
		MessageInfos:      file_tensorflow_serving_core_logging_proto_msgTypes,
	}.Build()
	File_tensorflow_serving_core_logging_proto = out.File
	file_tensorflow_serving_core_logging_proto_rawDesc = nil
	file_tensorflow_serving_core_logging_proto_goTypes = nil
	file_tensorflow_serving_core_logging_proto_depIdxs = nil
}
