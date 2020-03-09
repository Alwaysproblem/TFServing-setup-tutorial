// Code generated by protoc-gen-go. DO NOT EDIT.
// source: tensorflow/core/example/feature.proto

package example

import proto "github.com/golang/protobuf/proto"
import fmt "fmt"
import math "math"

// Reference imports to suppress errors if they are not otherwise used.
var _ = proto.Marshal
var _ = fmt.Errorf
var _ = math.Inf

// Containers to hold repeated fundamental values.
type BytesList struct {
	Value [][]byte `protobuf:"bytes,1,rep,name=value,proto3" json:"value,omitempty"`
}

func (m *BytesList) Reset()                    { *m = BytesList{} }
func (m *BytesList) String() string            { return proto.CompactTextString(m) }
func (*BytesList) ProtoMessage()               {}
func (*BytesList) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{0} }

func (m *BytesList) GetValue() [][]byte {
	if m != nil {
		return m.Value
	}
	return nil
}

type FloatList struct {
	Value []float32 `protobuf:"fixed32,1,rep,packed,name=value" json:"value,omitempty"`
}

func (m *FloatList) Reset()                    { *m = FloatList{} }
func (m *FloatList) String() string            { return proto.CompactTextString(m) }
func (*FloatList) ProtoMessage()               {}
func (*FloatList) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{1} }

func (m *FloatList) GetValue() []float32 {
	if m != nil {
		return m.Value
	}
	return nil
}

type Int64List struct {
	Value []int64 `protobuf:"varint,1,rep,packed,name=value" json:"value,omitempty"`
}

func (m *Int64List) Reset()                    { *m = Int64List{} }
func (m *Int64List) String() string            { return proto.CompactTextString(m) }
func (*Int64List) ProtoMessage()               {}
func (*Int64List) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{2} }

func (m *Int64List) GetValue() []int64 {
	if m != nil {
		return m.Value
	}
	return nil
}

// Containers for non-sequential data.
type Feature struct {
	// Each feature can be exactly one kind.
	//
	// Types that are valid to be assigned to Kind:
	//	*Feature_BytesList
	//	*Feature_FloatList
	//	*Feature_Int64List
	Kind isFeature_Kind `protobuf_oneof:"kind"`
}

func (m *Feature) Reset()                    { *m = Feature{} }
func (m *Feature) String() string            { return proto.CompactTextString(m) }
func (*Feature) ProtoMessage()               {}
func (*Feature) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{3} }

type isFeature_Kind interface {
	isFeature_Kind()
}

type Feature_BytesList struct {
	BytesList *BytesList `protobuf:"bytes,1,opt,name=bytes_list,json=bytesList,oneof"`
}
type Feature_FloatList struct {
	FloatList *FloatList `protobuf:"bytes,2,opt,name=float_list,json=floatList,oneof"`
}
type Feature_Int64List struct {
	Int64List *Int64List `protobuf:"bytes,3,opt,name=int64_list,json=int64List,oneof"`
}

func (*Feature_BytesList) isFeature_Kind() {}
func (*Feature_FloatList) isFeature_Kind() {}
func (*Feature_Int64List) isFeature_Kind() {}

func (m *Feature) GetKind() isFeature_Kind {
	if m != nil {
		return m.Kind
	}
	return nil
}

func (m *Feature) GetBytesList() *BytesList {
	if x, ok := m.GetKind().(*Feature_BytesList); ok {
		return x.BytesList
	}
	return nil
}

func (m *Feature) GetFloatList() *FloatList {
	if x, ok := m.GetKind().(*Feature_FloatList); ok {
		return x.FloatList
	}
	return nil
}

func (m *Feature) GetInt64List() *Int64List {
	if x, ok := m.GetKind().(*Feature_Int64List); ok {
		return x.Int64List
	}
	return nil
}

// XXX_OneofFuncs is for the internal use of the proto package.
func (*Feature) XXX_OneofFuncs() (func(msg proto.Message, b *proto.Buffer) error, func(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error), func(msg proto.Message) (n int), []interface{}) {
	return _Feature_OneofMarshaler, _Feature_OneofUnmarshaler, _Feature_OneofSizer, []interface{}{
		(*Feature_BytesList)(nil),
		(*Feature_FloatList)(nil),
		(*Feature_Int64List)(nil),
	}
}

func _Feature_OneofMarshaler(msg proto.Message, b *proto.Buffer) error {
	m := msg.(*Feature)
	// kind
	switch x := m.Kind.(type) {
	case *Feature_BytesList:
		b.EncodeVarint(1<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.BytesList); err != nil {
			return err
		}
	case *Feature_FloatList:
		b.EncodeVarint(2<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.FloatList); err != nil {
			return err
		}
	case *Feature_Int64List:
		b.EncodeVarint(3<<3 | proto.WireBytes)
		if err := b.EncodeMessage(x.Int64List); err != nil {
			return err
		}
	case nil:
	default:
		return fmt.Errorf("Feature.Kind has unexpected type %T", x)
	}
	return nil
}

func _Feature_OneofUnmarshaler(msg proto.Message, tag, wire int, b *proto.Buffer) (bool, error) {
	m := msg.(*Feature)
	switch tag {
	case 1: // kind.bytes_list
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(BytesList)
		err := b.DecodeMessage(msg)
		m.Kind = &Feature_BytesList{msg}
		return true, err
	case 2: // kind.float_list
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(FloatList)
		err := b.DecodeMessage(msg)
		m.Kind = &Feature_FloatList{msg}
		return true, err
	case 3: // kind.int64_list
		if wire != proto.WireBytes {
			return true, proto.ErrInternalBadWireType
		}
		msg := new(Int64List)
		err := b.DecodeMessage(msg)
		m.Kind = &Feature_Int64List{msg}
		return true, err
	default:
		return false, nil
	}
}

func _Feature_OneofSizer(msg proto.Message) (n int) {
	m := msg.(*Feature)
	// kind
	switch x := m.Kind.(type) {
	case *Feature_BytesList:
		s := proto.Size(x.BytesList)
		n += proto.SizeVarint(1<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case *Feature_FloatList:
		s := proto.Size(x.FloatList)
		n += proto.SizeVarint(2<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case *Feature_Int64List:
		s := proto.Size(x.Int64List)
		n += proto.SizeVarint(3<<3 | proto.WireBytes)
		n += proto.SizeVarint(uint64(s))
		n += s
	case nil:
	default:
		panic(fmt.Sprintf("proto: unexpected type %T in oneof", x))
	}
	return n
}

type Features struct {
	// Map from feature name to feature.
	Feature map[string]*Feature `protobuf:"bytes,1,rep,name=feature" json:"feature,omitempty" protobuf_key:"bytes,1,opt,name=key" protobuf_val:"bytes,2,opt,name=value"`
}

func (m *Features) Reset()                    { *m = Features{} }
func (m *Features) String() string            { return proto.CompactTextString(m) }
func (*Features) ProtoMessage()               {}
func (*Features) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{4} }

func (m *Features) GetFeature() map[string]*Feature {
	if m != nil {
		return m.Feature
	}
	return nil
}

// Containers for sequential data.
//
// A FeatureList contains lists of Features.  These may hold zero or more
// Feature values.
//
// FeatureLists are organized into categories by name.  The FeatureLists message
// contains the mapping from name to FeatureList.
//
type FeatureList struct {
	Feature []*Feature `protobuf:"bytes,1,rep,name=feature" json:"feature,omitempty"`
}

func (m *FeatureList) Reset()                    { *m = FeatureList{} }
func (m *FeatureList) String() string            { return proto.CompactTextString(m) }
func (*FeatureList) ProtoMessage()               {}
func (*FeatureList) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{5} }

func (m *FeatureList) GetFeature() []*Feature {
	if m != nil {
		return m.Feature
	}
	return nil
}

type FeatureLists struct {
	// Map from feature name to feature list.
	FeatureList map[string]*FeatureList `protobuf:"bytes,1,rep,name=feature_list,json=featureList" json:"feature_list,omitempty" protobuf_key:"bytes,1,opt,name=key" protobuf_val:"bytes,2,opt,name=value"`
}

func (m *FeatureLists) Reset()                    { *m = FeatureLists{} }
func (m *FeatureLists) String() string            { return proto.CompactTextString(m) }
func (*FeatureLists) ProtoMessage()               {}
func (*FeatureLists) Descriptor() ([]byte, []int) { return fileDescriptor2, []int{6} }

func (m *FeatureLists) GetFeatureList() map[string]*FeatureList {
	if m != nil {
		return m.FeatureList
	}
	return nil
}

func init() {
	proto.RegisterType((*BytesList)(nil), "tensorflow.BytesList")
	proto.RegisterType((*FloatList)(nil), "tensorflow.FloatList")
	proto.RegisterType((*Int64List)(nil), "tensorflow.Int64List")
	proto.RegisterType((*Feature)(nil), "tensorflow.Feature")
	proto.RegisterType((*Features)(nil), "tensorflow.Features")
	proto.RegisterType((*FeatureList)(nil), "tensorflow.FeatureList")
	proto.RegisterType((*FeatureLists)(nil), "tensorflow.FeatureLists")
}

func init() {
	proto.RegisterFile("github.com/tensorflow/tensorflow/tensorflow/go/core/example/feature.proto", fileDescriptor2)
}

var fileDescriptor2 = []byte{
	// 371 bytes of a gzipped FileDescriptorProto
	0x1f, 0x8b, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0xff, 0x74, 0x92, 0xdf, 0x4a, 0xc3, 0x30,
	0x14, 0xc6, 0x4d, 0xab, 0x9b, 0x3d, 0x9d, 0x30, 0xe2, 0xbf, 0xb1, 0xab, 0xad, 0x30, 0xd8, 0xc0,
	0x6d, 0x30, 0xa5, 0x88, 0x7a, 0x55, 0x70, 0x28, 0x0c, 0x1c, 0xbd, 0xf1, 0x52, 0x3a, 0x4d, 0xa5,
	0xac, 0x36, 0xa3, 0xc9, 0xd4, 0xbd, 0x89, 0x2f, 0xe2, 0x85, 0x6f, 0xe6, 0xa5, 0xa4, 0x4d, 0xbb,
	0x6c, 0xad, 0x77, 0x3d, 0xc9, 0xf7, 0x9d, 0xfc, 0xbe, 0xd3, 0x03, 0x1d, 0x4e, 0x22, 0x46, 0x63,
	0x3f, 0xa4, 0x1f, 0xc3, 0x67, 0x1a, 0x93, 0x21, 0xf9, 0xf4, 0xde, 0x16, 0x21, 0x19, 0xfa, 0xc4,
	0xe3, 0xcb, 0x98, 0x0c, 0x16, 0x31, 0xe5, 0x14, 0xc3, 0x5a, 0x66, 0xb5, 0xc1, 0x70, 0x56, 0x9c,
	0xb0, 0x49, 0xc0, 0x38, 0x3e, 0x82, 0xbd, 0x77, 0x2f, 0x5c, 0x92, 0x06, 0x6a, 0xe9, 0xdd, 0x9a,
	0x9b, 0x16, 0x56, 0x07, 0x8c, 0x71, 0x48, 0x3d, 0x9e, 0x48, 0x1a, 0xaa, 0x44, 0x73, 0xb4, 0x3a,
	0x52, 0x64, 0xf7, 0x11, 0xb7, 0x2f, 0x8a, 0x32, 0x5d, 0x95, 0xfd, 0x20, 0xa8, 0x8e, 0x53, 0x1c,
	0x6c, 0x03, 0xcc, 0xc4, 0xe3, 0x4f, 0x61, 0xc0, 0x78, 0x03, 0xb5, 0x50, 0xd7, 0x1c, 0x1d, 0x0f,
	0xd6, 0x74, 0x83, 0x1c, 0xed, 0x6e, 0xc7, 0x35, 0x66, 0x39, 0xa7, 0x0d, 0xe0, 0x0b, 0xa2, 0xd4,
	0xa7, 0x15, 0x7d, 0x39, 0xaf, 0xf0, 0xf9, 0x39, 0xbc, 0x0d, 0x10, 0x08, 0xc4, 0xd4, 0xa7, 0x17,
	0x7d, 0x79, 0x00, 0xe1, 0x0b, 0xb2, 0xc2, 0xa9, 0xc0, 0xee, 0x3c, 0x88, 0x5e, 0xac, 0x2f, 0x04,
	0xfb, 0x92, 0x9d, 0xe1, 0x6b, 0xa8, 0xca, 0xb1, 0x26, 0x21, 0xcd, 0x51, 0x7b, 0x83, 0x40, 0xca,
	0xb2, 0x8f, 0xdb, 0x88, 0xc7, 0x2b, 0x37, 0x73, 0x34, 0x1f, 0xa0, 0xa6, 0x5e, 0xe0, 0x3a, 0xe8,
	0x73, 0xb2, 0x4a, 0x46, 0x60, 0xb8, 0xe2, 0x13, 0xf7, 0xb2, 0x09, 0xa6, 0xf1, 0x0e, 0x4b, 0x9a,
	0xcb, 0x91, 0x5e, 0x69, 0x97, 0xc8, 0xba, 0x01, 0x53, 0x9e, 0x26, 0x49, 0xfb, 0xdb, 0x70, 0xa5,
	0xfe, 0x4c, 0x63, 0x7d, 0xa3, 0x9c, 0x47, 0xd8, 0x19, 0x9e, 0x40, 0x4d, 0xde, 0x65, 0xff, 0x46,
	0x34, 0xe9, 0x95, 0x34, 0x49, 0xf4, 0x6a, 0x91, 0x26, 0x35, 0xfd, 0xf5, 0x49, 0xf3, 0x11, 0xea,
	0xdb, 0x82, 0x92, 0xc4, 0xfd, 0xcd, 0xc4, 0xa7, 0xff, 0x3c, 0xa6, 0xa4, 0x76, 0xce, 0xe0, 0x84,
	0xc6, 0xaf, 0xaa, 0x50, 0x6e, 0xbc, 0x73, 0x20, 0x1d, 0x53, 0xb1, 0xf1, 0x6c, 0x8a, 0x7e, 0x11,
	0x9a, 0x55, 0x92, 0xf5, 0x3f, 0xff, 0x0b, 0x00, 0x00, 0xff, 0xff, 0xd3, 0x38, 0x1c, 0x54, 0x27,
	0x03, 0x00, 0x00,
}
