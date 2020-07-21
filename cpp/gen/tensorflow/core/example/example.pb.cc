// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/example/example.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "tensorflow/core/example/example.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/port.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace tensorflow {

namespace {

const ::google::protobuf::Descriptor* Example_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Example_reflection_ = NULL;
const ::google::protobuf::Descriptor* SequenceExample_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SequenceExample_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_tensorflow_2fcore_2fexample_2fexample_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_tensorflow_2fcore_2fexample_2fexample_2eproto() {
  protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "tensorflow/core/example/example.proto");
  GOOGLE_CHECK(file != NULL);
  Example_descriptor_ = file->message_type(0);
  static const int Example_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Example, features_),
  };
  Example_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      Example_descriptor_,
      Example::default_instance_,
      Example_offsets_,
      -1,
      -1,
      -1,
      sizeof(Example),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Example, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Example, _is_default_instance_));
  SequenceExample_descriptor_ = file->message_type(1);
  static const int SequenceExample_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SequenceExample, context_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SequenceExample, feature_lists_),
  };
  SequenceExample_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      SequenceExample_descriptor_,
      SequenceExample::default_instance_,
      SequenceExample_offsets_,
      -1,
      -1,
      -1,
      sizeof(SequenceExample),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SequenceExample, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SequenceExample, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_tensorflow_2fcore_2fexample_2fexample_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      Example_descriptor_, &Example::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      SequenceExample_descriptor_, &SequenceExample::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_tensorflow_2fcore_2fexample_2fexample_2eproto() {
  delete Example::default_instance_;
  delete Example_reflection_;
  delete SequenceExample::default_instance_;
  delete SequenceExample_reflection_;
}

void protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::tensorflow::protobuf_AddDesc_tensorflow_2fcore_2fexample_2ffeature_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n%tensorflow/core/example/example.proto\022"
    "\ntensorflow\032%tensorflow/core/example/fea"
    "ture.proto\"1\n\007Example\022&\n\010features\030\001 \001(\0132"
    "\024.tensorflow.Features\"i\n\017SequenceExample"
    "\022%\n\007context\030\001 \001(\0132\024.tensorflow.Features\022"
    "/\n\rfeature_lists\030\002 \001(\0132\030.tensorflow.Feat"
    "ureListsB\201\001\n\026org.tensorflow.exampleB\rExa"
    "mpleProtosP\001ZSgithub.com/tensorflow/tens"
    "orflow/tensorflow/go/core/example/exampl"
    "e_protos_go_proto\370\001\001b\006proto3", 388);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "tensorflow/core/example/example.proto", &protobuf_RegisterTypes);
  Example::default_instance_ = new Example();
  SequenceExample::default_instance_ = new SequenceExample();
  Example::default_instance_->InitAsDefaultInstance();
  SequenceExample::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_tensorflow_2fcore_2fexample_2fexample_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_tensorflow_2fcore_2fexample_2fexample_2eproto {
  StaticDescriptorInitializer_tensorflow_2fcore_2fexample_2fexample_2eproto() {
    protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  }
} static_descriptor_initializer_tensorflow_2fcore_2fexample_2fexample_2eproto_;

// ===================================================================

void Example::_slow_mutable_features() {
  features_ = ::google::protobuf::Arena::CreateMessage< ::tensorflow::Features >(
      GetArenaNoVirtual());
}
::tensorflow::Features* Example::_slow_release_features() {
  if (features_ == NULL) {
    return NULL;
  } else {
    ::tensorflow::Features* temp = new ::tensorflow::Features;
    temp->MergeFrom(*features_);
    features_ = NULL;
    return temp;
  }
}
::tensorflow::Features* Example::unsafe_arena_release_features() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.Example.features)
  
  ::tensorflow::Features* temp = features_;
  features_ = NULL;
  return temp;
}
void Example::_slow_set_allocated_features(
    ::google::protobuf::Arena* message_arena, ::tensorflow::Features** features) {
    if (message_arena != NULL && 
        ::google::protobuf::Arena::GetArena(*features) == NULL) {
      message_arena->Own(*features);
    } else if (message_arena !=
               ::google::protobuf::Arena::GetArena(*features)) {
      ::tensorflow::Features* new_features = 
            ::google::protobuf::Arena::CreateMessage< ::tensorflow::Features >(
            message_arena);
      new_features->CopyFrom(**features);
      *features = new_features;
    }
}
void Example::unsafe_arena_set_allocated_features(
    ::tensorflow::Features* features) {
  if (GetArenaNoVirtual() == NULL) {
    delete features_;
  }
  features_ = features;
  if (features) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.Example.features)
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int Example::kFeaturesFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

Example::Example()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.Example)
}

Example::Example(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.Example)
}

void Example::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  features_ = const_cast< ::tensorflow::Features*>(&::tensorflow::Features::default_instance());
}

Example::Example(const Example& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tensorflow.Example)
}

void Example::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  features_ = NULL;
}

Example::~Example() {
  // @@protoc_insertion_point(destructor:tensorflow.Example)
  SharedDtor();
}

void Example::SharedDtor() {
  if (GetArenaNoVirtual() != NULL) {
    return;
  }

  if (this != default_instance_) {
    delete features_;
  }
}

void Example::ArenaDtor(void* object) {
  Example* _this = reinterpret_cast< Example* >(object);
  (void)_this;
}
void Example::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void Example::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Example::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Example_descriptor_;
}

const Example& Example::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  return *default_instance_;
}

Example* Example::default_instance_ = NULL;

Example* Example::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<Example>(arena);
}

void Example::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.Example)
  if (GetArenaNoVirtual() == NULL && features_ != NULL) delete features_;
  features_ = NULL;
}

bool Example::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.Example)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .tensorflow.Features features = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_features()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.Example)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.Example)
  return false;
#undef DO_
}

void Example::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.Example)
  // optional .tensorflow.Features features = 1;
  if (this->has_features()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->features_, output);
  }

  // @@protoc_insertion_point(serialize_end:tensorflow.Example)
}

::google::protobuf::uint8* Example::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.Example)
  // optional .tensorflow.Features features = 1;
  if (this->has_features()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->features_, false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.Example)
  return target;
}

int Example::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.Example)
  int total_size = 0;

  // optional .tensorflow.Features features = 1;
  if (this->has_features()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->features_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Example::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.Example)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const Example* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const Example>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.Example)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.Example)
    MergeFrom(*source);
  }
}

void Example::MergeFrom(const Example& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.Example)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.has_features()) {
    mutable_features()->::tensorflow::Features::MergeFrom(from.features());
  }
}

void Example::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.Example)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Example::CopyFrom(const Example& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.Example)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Example::IsInitialized() const {

  return true;
}

void Example::Swap(Example* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    Example temp;
    temp.MergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void Example::UnsafeArenaSwap(Example* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void Example::InternalSwap(Example* other) {
  std::swap(features_, other->features_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata Example::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Example_descriptor_;
  metadata.reflection = Example_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// Example

// optional .tensorflow.Features features = 1;
bool Example::has_features() const {
  return !_is_default_instance_ && features_ != NULL;
}
void Example::clear_features() {
  if (GetArenaNoVirtual() == NULL && features_ != NULL) delete features_;
  features_ = NULL;
}
const ::tensorflow::Features& Example::features() const {
  // @@protoc_insertion_point(field_get:tensorflow.Example.features)
  return features_ != NULL ? *features_ : *default_instance_->features_;
}
::tensorflow::Features* Example::mutable_features() {
  
  if (features_ == NULL) {
    _slow_mutable_features();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.Example.features)
  return features_;
}
::tensorflow::Features* Example::release_features() {
  // @@protoc_insertion_point(field_release:tensorflow.Example.features)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_features();
  } else {
    ::tensorflow::Features* temp = features_;
    features_ = NULL;
    return temp;
  }
}
 void Example::set_allocated_features(::tensorflow::Features* features) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete features_;
  }
  if (features != NULL) {
    _slow_set_allocated_features(message_arena, &features);
  }
  features_ = features;
  if (features) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.Example.features)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

void SequenceExample::_slow_mutable_context() {
  context_ = ::google::protobuf::Arena::CreateMessage< ::tensorflow::Features >(
      GetArenaNoVirtual());
}
::tensorflow::Features* SequenceExample::_slow_release_context() {
  if (context_ == NULL) {
    return NULL;
  } else {
    ::tensorflow::Features* temp = new ::tensorflow::Features;
    temp->MergeFrom(*context_);
    context_ = NULL;
    return temp;
  }
}
::tensorflow::Features* SequenceExample::unsafe_arena_release_context() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.SequenceExample.context)
  
  ::tensorflow::Features* temp = context_;
  context_ = NULL;
  return temp;
}
void SequenceExample::_slow_set_allocated_context(
    ::google::protobuf::Arena* message_arena, ::tensorflow::Features** context) {
    if (message_arena != NULL && 
        ::google::protobuf::Arena::GetArena(*context) == NULL) {
      message_arena->Own(*context);
    } else if (message_arena !=
               ::google::protobuf::Arena::GetArena(*context)) {
      ::tensorflow::Features* new_context = 
            ::google::protobuf::Arena::CreateMessage< ::tensorflow::Features >(
            message_arena);
      new_context->CopyFrom(**context);
      *context = new_context;
    }
}
void SequenceExample::unsafe_arena_set_allocated_context(
    ::tensorflow::Features* context) {
  if (GetArenaNoVirtual() == NULL) {
    delete context_;
  }
  context_ = context;
  if (context) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.SequenceExample.context)
}
void SequenceExample::_slow_mutable_feature_lists() {
  feature_lists_ = ::google::protobuf::Arena::CreateMessage< ::tensorflow::FeatureLists >(
      GetArenaNoVirtual());
}
::tensorflow::FeatureLists* SequenceExample::_slow_release_feature_lists() {
  if (feature_lists_ == NULL) {
    return NULL;
  } else {
    ::tensorflow::FeatureLists* temp = new ::tensorflow::FeatureLists;
    temp->MergeFrom(*feature_lists_);
    feature_lists_ = NULL;
    return temp;
  }
}
::tensorflow::FeatureLists* SequenceExample::unsafe_arena_release_feature_lists() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.SequenceExample.feature_lists)
  
  ::tensorflow::FeatureLists* temp = feature_lists_;
  feature_lists_ = NULL;
  return temp;
}
void SequenceExample::_slow_set_allocated_feature_lists(
    ::google::protobuf::Arena* message_arena, ::tensorflow::FeatureLists** feature_lists) {
    if (message_arena != NULL && 
        ::google::protobuf::Arena::GetArena(*feature_lists) == NULL) {
      message_arena->Own(*feature_lists);
    } else if (message_arena !=
               ::google::protobuf::Arena::GetArena(*feature_lists)) {
      ::tensorflow::FeatureLists* new_feature_lists = 
            ::google::protobuf::Arena::CreateMessage< ::tensorflow::FeatureLists >(
            message_arena);
      new_feature_lists->CopyFrom(**feature_lists);
      *feature_lists = new_feature_lists;
    }
}
void SequenceExample::unsafe_arena_set_allocated_feature_lists(
    ::tensorflow::FeatureLists* feature_lists) {
  if (GetArenaNoVirtual() == NULL) {
    delete feature_lists_;
  }
  feature_lists_ = feature_lists;
  if (feature_lists) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.SequenceExample.feature_lists)
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SequenceExample::kContextFieldNumber;
const int SequenceExample::kFeatureListsFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SequenceExample::SequenceExample()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.SequenceExample)
}

SequenceExample::SequenceExample(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.SequenceExample)
}

void SequenceExample::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  context_ = const_cast< ::tensorflow::Features*>(&::tensorflow::Features::default_instance());
  feature_lists_ = const_cast< ::tensorflow::FeatureLists*>(&::tensorflow::FeatureLists::default_instance());
}

SequenceExample::SequenceExample(const SequenceExample& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tensorflow.SequenceExample)
}

void SequenceExample::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  context_ = NULL;
  feature_lists_ = NULL;
}

SequenceExample::~SequenceExample() {
  // @@protoc_insertion_point(destructor:tensorflow.SequenceExample)
  SharedDtor();
}

void SequenceExample::SharedDtor() {
  if (GetArenaNoVirtual() != NULL) {
    return;
  }

  if (this != default_instance_) {
    delete context_;
    delete feature_lists_;
  }
}

void SequenceExample::ArenaDtor(void* object) {
  SequenceExample* _this = reinterpret_cast< SequenceExample* >(object);
  (void)_this;
}
void SequenceExample::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void SequenceExample::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SequenceExample::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SequenceExample_descriptor_;
}

const SequenceExample& SequenceExample::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  return *default_instance_;
}

SequenceExample* SequenceExample::default_instance_ = NULL;

SequenceExample* SequenceExample::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<SequenceExample>(arena);
}

void SequenceExample::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.SequenceExample)
  if (GetArenaNoVirtual() == NULL && context_ != NULL) delete context_;
  context_ = NULL;
  if (GetArenaNoVirtual() == NULL && feature_lists_ != NULL) delete feature_lists_;
  feature_lists_ = NULL;
}

bool SequenceExample::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.SequenceExample)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .tensorflow.Features context = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_context()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_feature_lists;
        break;
      }

      // optional .tensorflow.FeatureLists feature_lists = 2;
      case 2: {
        if (tag == 18) {
         parse_feature_lists:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_feature_lists()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.SequenceExample)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.SequenceExample)
  return false;
#undef DO_
}

void SequenceExample::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.SequenceExample)
  // optional .tensorflow.Features context = 1;
  if (this->has_context()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->context_, output);
  }

  // optional .tensorflow.FeatureLists feature_lists = 2;
  if (this->has_feature_lists()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->feature_lists_, output);
  }

  // @@protoc_insertion_point(serialize_end:tensorflow.SequenceExample)
}

::google::protobuf::uint8* SequenceExample::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.SequenceExample)
  // optional .tensorflow.Features context = 1;
  if (this->has_context()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->context_, false, target);
  }

  // optional .tensorflow.FeatureLists feature_lists = 2;
  if (this->has_feature_lists()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, *this->feature_lists_, false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.SequenceExample)
  return target;
}

int SequenceExample::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.SequenceExample)
  int total_size = 0;

  // optional .tensorflow.Features context = 1;
  if (this->has_context()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->context_);
  }

  // optional .tensorflow.FeatureLists feature_lists = 2;
  if (this->has_feature_lists()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->feature_lists_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SequenceExample::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.SequenceExample)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const SequenceExample* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const SequenceExample>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.SequenceExample)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.SequenceExample)
    MergeFrom(*source);
  }
}

void SequenceExample::MergeFrom(const SequenceExample& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.SequenceExample)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.has_context()) {
    mutable_context()->::tensorflow::Features::MergeFrom(from.context());
  }
  if (from.has_feature_lists()) {
    mutable_feature_lists()->::tensorflow::FeatureLists::MergeFrom(from.feature_lists());
  }
}

void SequenceExample::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.SequenceExample)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SequenceExample::CopyFrom(const SequenceExample& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.SequenceExample)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SequenceExample::IsInitialized() const {

  return true;
}

void SequenceExample::Swap(SequenceExample* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    SequenceExample temp;
    temp.MergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void SequenceExample::UnsafeArenaSwap(SequenceExample* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void SequenceExample::InternalSwap(SequenceExample* other) {
  std::swap(context_, other->context_);
  std::swap(feature_lists_, other->feature_lists_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SequenceExample::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SequenceExample_descriptor_;
  metadata.reflection = SequenceExample_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SequenceExample

// optional .tensorflow.Features context = 1;
bool SequenceExample::has_context() const {
  return !_is_default_instance_ && context_ != NULL;
}
void SequenceExample::clear_context() {
  if (GetArenaNoVirtual() == NULL && context_ != NULL) delete context_;
  context_ = NULL;
}
const ::tensorflow::Features& SequenceExample::context() const {
  // @@protoc_insertion_point(field_get:tensorflow.SequenceExample.context)
  return context_ != NULL ? *context_ : *default_instance_->context_;
}
::tensorflow::Features* SequenceExample::mutable_context() {
  
  if (context_ == NULL) {
    _slow_mutable_context();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.SequenceExample.context)
  return context_;
}
::tensorflow::Features* SequenceExample::release_context() {
  // @@protoc_insertion_point(field_release:tensorflow.SequenceExample.context)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_context();
  } else {
    ::tensorflow::Features* temp = context_;
    context_ = NULL;
    return temp;
  }
}
 void SequenceExample::set_allocated_context(::tensorflow::Features* context) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete context_;
  }
  if (context != NULL) {
    _slow_set_allocated_context(message_arena, &context);
  }
  context_ = context;
  if (context) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.SequenceExample.context)
}

// optional .tensorflow.FeatureLists feature_lists = 2;
bool SequenceExample::has_feature_lists() const {
  return !_is_default_instance_ && feature_lists_ != NULL;
}
void SequenceExample::clear_feature_lists() {
  if (GetArenaNoVirtual() == NULL && feature_lists_ != NULL) delete feature_lists_;
  feature_lists_ = NULL;
}
const ::tensorflow::FeatureLists& SequenceExample::feature_lists() const {
  // @@protoc_insertion_point(field_get:tensorflow.SequenceExample.feature_lists)
  return feature_lists_ != NULL ? *feature_lists_ : *default_instance_->feature_lists_;
}
::tensorflow::FeatureLists* SequenceExample::mutable_feature_lists() {
  
  if (feature_lists_ == NULL) {
    _slow_mutable_feature_lists();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.SequenceExample.feature_lists)
  return feature_lists_;
}
::tensorflow::FeatureLists* SequenceExample::release_feature_lists() {
  // @@protoc_insertion_point(field_release:tensorflow.SequenceExample.feature_lists)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_feature_lists();
  } else {
    ::tensorflow::FeatureLists* temp = feature_lists_;
    feature_lists_ = NULL;
    return temp;
  }
}
 void SequenceExample::set_allocated_feature_lists(::tensorflow::FeatureLists* feature_lists) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete feature_lists_;
  }
  if (feature_lists != NULL) {
    _slow_set_allocated_feature_lists(message_arena, &feature_lists);
  }
  feature_lists_ = feature_lists;
  if (feature_lists) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.SequenceExample.feature_lists)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)
