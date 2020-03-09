// Code generated by protoc-gen-go. DO NOT EDIT.
// source: tensorflow_serving/apis/regression.proto

package tensorflow_serving

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// Regression result for a single item (tensorflow.Example).
type Regression struct {
	Value float32 `protobuf:"fixed32,1,opt,name=value" json:"value,omitempty"`
}

func (m *Regression) Reset()                    { *m = Regression{} }
func (m *Regression) String() string            { return proto.CompactTextString(m) }
func (*Regression) ProtoMessage()               {}
func (*Regression) Descriptor() ([]byte, []int) { return fileDescriptor7, []int{0} }

func (m *Regression) GetValue() float32 {
	if m != nil {
		return m.Value
	}
	return 0
}

// Contains one result per input example, in the same order as the input in
// RegressionRequest.
type RegressionResult struct {
	Regressions []*Regression `protobuf:"bytes,1,rep,name=regressions" json:"regressions,omitempty"`
}

func (m *RegressionResult) Reset()                    { *m = RegressionResult{} }
func (m *RegressionResult) String() string            { return proto.CompactTextString(m) }
func (*RegressionResult) ProtoMessage()               {}
func (*RegressionResult) Descriptor() ([]byte, []int) { return fileDescriptor7, []int{1} }

func (m *RegressionResult) GetRegressions() []*Regression {
	if m != nil {
		return m.Regressions
	}
	return nil
}

type RegressionRequest struct {
	// Model Specification.
	ModelSpec *ModelSpec `protobuf:"bytes,1,opt,name=model_spec,json=modelSpec" json:"model_spec,omitempty"`
	// Input data.
	Input *Input `protobuf:"bytes,2,opt,name=input" json:"input,omitempty"`
}

func (m *RegressionRequest) Reset()                    { *m = RegressionRequest{} }
func (m *RegressionRequest) String() string            { return proto.CompactTextString(m) }
func (*RegressionRequest) ProtoMessage()               {}
func (*RegressionRequest) Descriptor() ([]byte, []int) { return fileDescriptor7, []int{2} }

func (m *RegressionRequest) GetModelSpec() *ModelSpec {
	if m != nil {
		return m.ModelSpec
	}
	return nil
}

func (m *RegressionRequest) GetInput() *Input {
	if m != nil {
		return m.Input
	}
	return nil
}

type RegressionResponse struct {
	Result *RegressionResult `protobuf:"bytes,1,opt,name=result" json:"result,omitempty"`
}

func (m *RegressionResponse) Reset()                    { *m = RegressionResponse{} }
func (m *RegressionResponse) String() string            { return proto.CompactTextString(m) }
func (*RegressionResponse) ProtoMessage()               {}
func (*RegressionResponse) Descriptor() ([]byte, []int) { return fileDescriptor7, []int{3} }

func (m *RegressionResponse) GetResult() *RegressionResult {
	if m != nil {
		return m.Result
	}
	return nil
}

func init() {
	proto.RegisterType((*Regression)(nil), "tensorflow.serving.Regression")
	proto.RegisterType((*RegressionResult)(nil), "tensorflow.serving.RegressionResult")
	proto.RegisterType((*RegressionRequest)(nil), "tensorflow.serving.RegressionRequest")
	proto.RegisterType((*RegressionResponse)(nil), "tensorflow.serving.RegressionResponse")
}

func init() { proto.RegisterFile("tensorflow_serving/apis/regression.proto", fileDescriptor7) }

var fileDescriptor7 = []byte{
	// 251 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x84, 0x90, 0x31, 0x4f, 0xc3, 0x30,
	0x10, 0x85, 0xe5, 0x56, 0xad, 0xc4, 0x65, 0x81, 0x13, 0x43, 0x40, 0x02, 0x55, 0x86, 0x21, 0x53,
	0x22, 0x95, 0xb5, 0x03, 0x62, 0x63, 0x60, 0x31, 0xec, 0x55, 0x29, 0x47, 0x15, 0x29, 0xb5, 0x8d,
	0xcf, 0x2e, 0x3b, 0xbf, 0x9a, 0x11, 0xd5, 0x0e, 0x24, 0x88, 0x46, 0x6c, 0xb6, 0xf4, 0x7d, 0x77,
	0xef, 0x1d, 0x14, 0x9e, 0x34, 0x1b, 0xf7, 0xda, 0x98, 0xf7, 0x25, 0x93, 0xdb, 0xd5, 0x7a, 0x53,
	0xad, 0x6c, 0xcd, 0x95, 0xa3, 0x8d, 0x23, 0xe6, 0xda, 0xe8, 0xd2, 0x3a, 0xe3, 0x0d, 0x62, 0x47,
	0x96, 0x2d, 0x79, 0x7e, 0x35, 0x64, 0xd7, 0xda, 0x06, 0x9f, 0xc4, 0x61, 0x68, 0x6b, 0x5e, 0xa8,
	0x49, 0x90, 0x94, 0x00, 0xea, 0x67, 0x23, 0x9e, 0xc2, 0x64, 0xb7, 0x6a, 0x02, 0xe5, 0x62, 0x26,
	0x8a, 0x91, 0x4a, 0x1f, 0xf9, 0x04, 0xc7, 0x1d, 0xa3, 0x88, 0x43, 0xe3, 0xf1, 0x16, 0xb2, 0x2e,
	0x29, 0xe7, 0x62, 0x36, 0x2e, 0xb2, 0xf9, 0x65, 0xf9, 0x37, 0x6b, 0xd9, 0x53, 0xfb, 0x8a, 0xfc,
	0x10, 0x70, 0xd2, 0x1f, 0xfb, 0x16, 0x88, 0x3d, 0x2e, 0x00, 0x62, 0xbc, 0x25, 0x5b, 0x5a, 0xc7,
	0x18, 0xd9, 0xfc, 0xe2, 0xd0, 0xd8, 0x87, 0x3d, 0xf5, 0x68, 0x69, 0xad, 0x8e, 0xb6, 0xdf, 0x4f,
	0xac, 0x60, 0x12, 0x2f, 0x90, 0x8f, 0xa2, 0x78, 0x76, 0x48, 0xbc, 0xdf, 0x03, 0x2a, 0x71, 0x52,
	0x01, 0xfe, 0xaa, 0x66, 0x8d, 0x66, 0xc2, 0x05, 0x4c, 0x5d, 0xac, 0xd9, 0x06, 0xb8, 0xfe, 0xa7,
	0x57, 0x64, 0x55, 0xeb, 0xdc, 0x8d, 0x3f, 0x85, 0x78, 0x9e, 0xc6, 0xf3, 0xde, 0x7c, 0x05, 0x00,
	0x00, 0xff, 0xff, 0xe1, 0x57, 0x98, 0xf1, 0xe8, 0x01, 0x00, 0x00,
}
