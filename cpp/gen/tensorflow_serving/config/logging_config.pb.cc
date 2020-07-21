// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow_serving/config/logging_config.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "tensorflow_serving/config/logging_config.pb.h"

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
namespace serving {

namespace {

const ::google::protobuf::Descriptor* SamplingConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  SamplingConfig_reflection_ = NULL;
const ::google::protobuf::Descriptor* LoggingConfig_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  LoggingConfig_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto() {
  protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "tensorflow_serving/config/logging_config.proto");
  GOOGLE_CHECK(file != NULL);
  SamplingConfig_descriptor_ = file->message_type(0);
  static const int SamplingConfig_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SamplingConfig, sampling_rate_),
  };
  SamplingConfig_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      SamplingConfig_descriptor_,
      SamplingConfig::default_instance_,
      SamplingConfig_offsets_,
      -1,
      -1,
      -1,
      sizeof(SamplingConfig),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SamplingConfig, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(SamplingConfig, _is_default_instance_));
  LoggingConfig_descriptor_ = file->message_type(1);
  static const int LoggingConfig_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoggingConfig, log_collector_config_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoggingConfig, sampling_config_),
  };
  LoggingConfig_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      LoggingConfig_descriptor_,
      LoggingConfig::default_instance_,
      LoggingConfig_offsets_,
      -1,
      -1,
      -1,
      sizeof(LoggingConfig),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoggingConfig, _internal_metadata_),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(LoggingConfig, _is_default_instance_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      SamplingConfig_descriptor_, &SamplingConfig::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      LoggingConfig_descriptor_, &LoggingConfig::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto() {
  delete SamplingConfig::default_instance_;
  delete SamplingConfig_reflection_;
  delete LoggingConfig::default_instance_;
  delete LoggingConfig_reflection_;
}

void protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::tensorflow::serving::protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flog_5fcollector_5fconfig_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n.tensorflow_serving/config/logging_conf"
    "ig.proto\022\022tensorflow.serving\0324tensorflow"
    "_serving/config/log_collector_config.pro"
    "to\"\'\n\016SamplingConfig\022\025\n\rsampling_rate\030\001 "
    "\001(\001\"\222\001\n\rLoggingConfig\022D\n\024log_collector_c"
    "onfig\030\001 \001(\0132&.tensorflow.serving.LogColl"
    "ectorConfig\022;\n\017sampling_config\030\002 \001(\0132\".t"
    "ensorflow.serving.SamplingConfigB\003\370\001\001b\006p"
    "roto3", 325);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "tensorflow_serving/config/logging_config.proto", &protobuf_RegisterTypes);
  SamplingConfig::default_instance_ = new SamplingConfig();
  LoggingConfig::default_instance_ = new LoggingConfig();
  SamplingConfig::default_instance_->InitAsDefaultInstance();
  LoggingConfig::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto {
  StaticDescriptorInitializer_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto() {
    protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto();
  }
} static_descriptor_initializer_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto_;

// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int SamplingConfig::kSamplingRateFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

SamplingConfig::SamplingConfig()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.serving.SamplingConfig)
}

SamplingConfig::SamplingConfig(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.serving.SamplingConfig)
}

void SamplingConfig::InitAsDefaultInstance() {
  _is_default_instance_ = true;
}

SamplingConfig::SamplingConfig(const SamplingConfig& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tensorflow.serving.SamplingConfig)
}

void SamplingConfig::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  sampling_rate_ = 0;
}

SamplingConfig::~SamplingConfig() {
  // @@protoc_insertion_point(destructor:tensorflow.serving.SamplingConfig)
  SharedDtor();
}

void SamplingConfig::SharedDtor() {
  if (GetArenaNoVirtual() != NULL) {
    return;
  }

  if (this != default_instance_) {
  }
}

void SamplingConfig::ArenaDtor(void* object) {
  SamplingConfig* _this = reinterpret_cast< SamplingConfig* >(object);
  (void)_this;
}
void SamplingConfig::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void SamplingConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* SamplingConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return SamplingConfig_descriptor_;
}

const SamplingConfig& SamplingConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto();
  return *default_instance_;
}

SamplingConfig* SamplingConfig::default_instance_ = NULL;

SamplingConfig* SamplingConfig::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<SamplingConfig>(arena);
}

void SamplingConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.serving.SamplingConfig)
  sampling_rate_ = 0;
}

bool SamplingConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.serving.SamplingConfig)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional double sampling_rate = 1;
      case 1: {
        if (tag == 9) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   double, ::google::protobuf::internal::WireFormatLite::TYPE_DOUBLE>(
                 input, &sampling_rate_)));

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
  // @@protoc_insertion_point(parse_success:tensorflow.serving.SamplingConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.serving.SamplingConfig)
  return false;
#undef DO_
}

void SamplingConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.serving.SamplingConfig)
  // optional double sampling_rate = 1;
  if (this->sampling_rate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteDouble(1, this->sampling_rate(), output);
  }

  // @@protoc_insertion_point(serialize_end:tensorflow.serving.SamplingConfig)
}

::google::protobuf::uint8* SamplingConfig::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.serving.SamplingConfig)
  // optional double sampling_rate = 1;
  if (this->sampling_rate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteDoubleToArray(1, this->sampling_rate(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.serving.SamplingConfig)
  return target;
}

int SamplingConfig::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.serving.SamplingConfig)
  int total_size = 0;

  // optional double sampling_rate = 1;
  if (this->sampling_rate() != 0) {
    total_size += 1 + 8;
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void SamplingConfig::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.serving.SamplingConfig)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const SamplingConfig* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const SamplingConfig>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.serving.SamplingConfig)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.serving.SamplingConfig)
    MergeFrom(*source);
  }
}

void SamplingConfig::MergeFrom(const SamplingConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.serving.SamplingConfig)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.sampling_rate() != 0) {
    set_sampling_rate(from.sampling_rate());
  }
}

void SamplingConfig::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.serving.SamplingConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void SamplingConfig::CopyFrom(const SamplingConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.serving.SamplingConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool SamplingConfig::IsInitialized() const {

  return true;
}

void SamplingConfig::Swap(SamplingConfig* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    SamplingConfig temp;
    temp.MergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void SamplingConfig::UnsafeArenaSwap(SamplingConfig* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void SamplingConfig::InternalSwap(SamplingConfig* other) {
  std::swap(sampling_rate_, other->sampling_rate_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata SamplingConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = SamplingConfig_descriptor_;
  metadata.reflection = SamplingConfig_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// SamplingConfig

// optional double sampling_rate = 1;
void SamplingConfig::clear_sampling_rate() {
  sampling_rate_ = 0;
}
 double SamplingConfig::sampling_rate() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.SamplingConfig.sampling_rate)
  return sampling_rate_;
}
 void SamplingConfig::set_sampling_rate(double value) {
  
  sampling_rate_ = value;
  // @@protoc_insertion_point(field_set:tensorflow.serving.SamplingConfig.sampling_rate)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// ===================================================================

void LoggingConfig::_slow_mutable_log_collector_config() {
  log_collector_config_ = ::google::protobuf::Arena::CreateMessage< ::tensorflow::serving::LogCollectorConfig >(
      GetArenaNoVirtual());
}
::tensorflow::serving::LogCollectorConfig* LoggingConfig::_slow_release_log_collector_config() {
  if (log_collector_config_ == NULL) {
    return NULL;
  } else {
    ::tensorflow::serving::LogCollectorConfig* temp = new ::tensorflow::serving::LogCollectorConfig;
    temp->MergeFrom(*log_collector_config_);
    log_collector_config_ = NULL;
    return temp;
  }
}
::tensorflow::serving::LogCollectorConfig* LoggingConfig::unsafe_arena_release_log_collector_config() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.LoggingConfig.log_collector_config)
  
  ::tensorflow::serving::LogCollectorConfig* temp = log_collector_config_;
  log_collector_config_ = NULL;
  return temp;
}
void LoggingConfig::_slow_set_allocated_log_collector_config(
    ::google::protobuf::Arena* message_arena, ::tensorflow::serving::LogCollectorConfig** log_collector_config) {
    if (message_arena != NULL && 
        ::google::protobuf::Arena::GetArena(*log_collector_config) == NULL) {
      message_arena->Own(*log_collector_config);
    } else if (message_arena !=
               ::google::protobuf::Arena::GetArena(*log_collector_config)) {
      ::tensorflow::serving::LogCollectorConfig* new_log_collector_config = 
            ::google::protobuf::Arena::CreateMessage< ::tensorflow::serving::LogCollectorConfig >(
            message_arena);
      new_log_collector_config->CopyFrom(**log_collector_config);
      *log_collector_config = new_log_collector_config;
    }
}
void LoggingConfig::unsafe_arena_set_allocated_log_collector_config(
    ::tensorflow::serving::LogCollectorConfig* log_collector_config) {
  if (GetArenaNoVirtual() == NULL) {
    delete log_collector_config_;
  }
  log_collector_config_ = log_collector_config;
  if (log_collector_config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.LoggingConfig.log_collector_config)
}
void LoggingConfig::_slow_mutable_sampling_config() {
  sampling_config_ = ::google::protobuf::Arena::CreateMessage< ::tensorflow::serving::SamplingConfig >(
      GetArenaNoVirtual());
}
::tensorflow::serving::SamplingConfig* LoggingConfig::_slow_release_sampling_config() {
  if (sampling_config_ == NULL) {
    return NULL;
  } else {
    ::tensorflow::serving::SamplingConfig* temp = new ::tensorflow::serving::SamplingConfig;
    temp->MergeFrom(*sampling_config_);
    sampling_config_ = NULL;
    return temp;
  }
}
::tensorflow::serving::SamplingConfig* LoggingConfig::unsafe_arena_release_sampling_config() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.LoggingConfig.sampling_config)
  
  ::tensorflow::serving::SamplingConfig* temp = sampling_config_;
  sampling_config_ = NULL;
  return temp;
}
void LoggingConfig::_slow_set_allocated_sampling_config(
    ::google::protobuf::Arena* message_arena, ::tensorflow::serving::SamplingConfig** sampling_config) {
    if (message_arena != NULL && 
        ::google::protobuf::Arena::GetArena(*sampling_config) == NULL) {
      message_arena->Own(*sampling_config);
    } else if (message_arena !=
               ::google::protobuf::Arena::GetArena(*sampling_config)) {
      ::tensorflow::serving::SamplingConfig* new_sampling_config = 
            ::google::protobuf::Arena::CreateMessage< ::tensorflow::serving::SamplingConfig >(
            message_arena);
      new_sampling_config->CopyFrom(**sampling_config);
      *sampling_config = new_sampling_config;
    }
}
void LoggingConfig::unsafe_arena_set_allocated_sampling_config(
    ::tensorflow::serving::SamplingConfig* sampling_config) {
  if (GetArenaNoVirtual() == NULL) {
    delete sampling_config_;
  }
  sampling_config_ = sampling_config;
  if (sampling_config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.LoggingConfig.sampling_config)
}
#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int LoggingConfig::kLogCollectorConfigFieldNumber;
const int LoggingConfig::kSamplingConfigFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

LoggingConfig::LoggingConfig()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.serving.LoggingConfig)
}

LoggingConfig::LoggingConfig(::google::protobuf::Arena* arena)
  : ::google::protobuf::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.serving.LoggingConfig)
}

void LoggingConfig::InitAsDefaultInstance() {
  _is_default_instance_ = true;
  log_collector_config_ = const_cast< ::tensorflow::serving::LogCollectorConfig*>(&::tensorflow::serving::LogCollectorConfig::default_instance());
  sampling_config_ = const_cast< ::tensorflow::serving::SamplingConfig*>(&::tensorflow::serving::SamplingConfig::default_instance());
}

LoggingConfig::LoggingConfig(const LoggingConfig& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:tensorflow.serving.LoggingConfig)
}

void LoggingConfig::SharedCtor() {
    _is_default_instance_ = false;
  _cached_size_ = 0;
  log_collector_config_ = NULL;
  sampling_config_ = NULL;
}

LoggingConfig::~LoggingConfig() {
  // @@protoc_insertion_point(destructor:tensorflow.serving.LoggingConfig)
  SharedDtor();
}

void LoggingConfig::SharedDtor() {
  if (GetArenaNoVirtual() != NULL) {
    return;
  }

  if (this != default_instance_) {
    delete log_collector_config_;
    delete sampling_config_;
  }
}

void LoggingConfig::ArenaDtor(void* object) {
  LoggingConfig* _this = reinterpret_cast< LoggingConfig* >(object);
  (void)_this;
}
void LoggingConfig::RegisterArenaDtor(::google::protobuf::Arena* arena) {
}
void LoggingConfig::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* LoggingConfig::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return LoggingConfig_descriptor_;
}

const LoggingConfig& LoggingConfig::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto();
  return *default_instance_;
}

LoggingConfig* LoggingConfig::default_instance_ = NULL;

LoggingConfig* LoggingConfig::New(::google::protobuf::Arena* arena) const {
  return ::google::protobuf::Arena::CreateMessage<LoggingConfig>(arena);
}

void LoggingConfig::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.serving.LoggingConfig)
  if (GetArenaNoVirtual() == NULL && log_collector_config_ != NULL) delete log_collector_config_;
  log_collector_config_ = NULL;
  if (GetArenaNoVirtual() == NULL && sampling_config_ != NULL) delete sampling_config_;
  sampling_config_ = NULL;
}

bool LoggingConfig::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.serving.LoggingConfig)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional .tensorflow.serving.LogCollectorConfig log_collector_config = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_log_collector_config()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_sampling_config;
        break;
      }

      // optional .tensorflow.serving.SamplingConfig sampling_config = 2;
      case 2: {
        if (tag == 18) {
         parse_sampling_config:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_sampling_config()));
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
  // @@protoc_insertion_point(parse_success:tensorflow.serving.LoggingConfig)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.serving.LoggingConfig)
  return false;
#undef DO_
}

void LoggingConfig::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.serving.LoggingConfig)
  // optional .tensorflow.serving.LogCollectorConfig log_collector_config = 1;
  if (this->has_log_collector_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, *this->log_collector_config_, output);
  }

  // optional .tensorflow.serving.SamplingConfig sampling_config = 2;
  if (this->has_sampling_config()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, *this->sampling_config_, output);
  }

  // @@protoc_insertion_point(serialize_end:tensorflow.serving.LoggingConfig)
}

::google::protobuf::uint8* LoggingConfig::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.serving.LoggingConfig)
  // optional .tensorflow.serving.LogCollectorConfig log_collector_config = 1;
  if (this->has_log_collector_config()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        1, *this->log_collector_config_, false, target);
  }

  // optional .tensorflow.serving.SamplingConfig sampling_config = 2;
  if (this->has_sampling_config()) {
    target = ::google::protobuf::internal::WireFormatLite::
      InternalWriteMessageNoVirtualToArray(
        2, *this->sampling_config_, false, target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.serving.LoggingConfig)
  return target;
}

int LoggingConfig::ByteSize() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.serving.LoggingConfig)
  int total_size = 0;

  // optional .tensorflow.serving.LogCollectorConfig log_collector_config = 1;
  if (this->has_log_collector_config()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->log_collector_config_);
  }

  // optional .tensorflow.serving.SamplingConfig sampling_config = 2;
  if (this->has_sampling_config()) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        *this->sampling_config_);
  }

  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void LoggingConfig::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.serving.LoggingConfig)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  const LoggingConfig* source = 
      ::google::protobuf::internal::DynamicCastToGenerated<const LoggingConfig>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.serving.LoggingConfig)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.serving.LoggingConfig)
    MergeFrom(*source);
  }
}

void LoggingConfig::MergeFrom(const LoggingConfig& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.serving.LoggingConfig)
  if (GOOGLE_PREDICT_FALSE(&from == this)) {
    ::google::protobuf::internal::MergeFromFail(__FILE__, __LINE__);
  }
  if (from.has_log_collector_config()) {
    mutable_log_collector_config()->::tensorflow::serving::LogCollectorConfig::MergeFrom(from.log_collector_config());
  }
  if (from.has_sampling_config()) {
    mutable_sampling_config()->::tensorflow::serving::SamplingConfig::MergeFrom(from.sampling_config());
  }
}

void LoggingConfig::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.serving.LoggingConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LoggingConfig::CopyFrom(const LoggingConfig& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.serving.LoggingConfig)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LoggingConfig::IsInitialized() const {

  return true;
}

void LoggingConfig::Swap(LoggingConfig* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    LoggingConfig temp;
    temp.MergeFrom(*this);
    CopyFrom(*other);
    other->CopyFrom(temp);
  }
}
void LoggingConfig::UnsafeArenaSwap(LoggingConfig* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void LoggingConfig::InternalSwap(LoggingConfig* other) {
  std::swap(log_collector_config_, other->log_collector_config_);
  std::swap(sampling_config_, other->sampling_config_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata LoggingConfig::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = LoggingConfig_descriptor_;
  metadata.reflection = LoggingConfig_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// LoggingConfig

// optional .tensorflow.serving.LogCollectorConfig log_collector_config = 1;
bool LoggingConfig::has_log_collector_config() const {
  return !_is_default_instance_ && log_collector_config_ != NULL;
}
void LoggingConfig::clear_log_collector_config() {
  if (GetArenaNoVirtual() == NULL && log_collector_config_ != NULL) delete log_collector_config_;
  log_collector_config_ = NULL;
}
const ::tensorflow::serving::LogCollectorConfig& LoggingConfig::log_collector_config() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.LoggingConfig.log_collector_config)
  return log_collector_config_ != NULL ? *log_collector_config_ : *default_instance_->log_collector_config_;
}
::tensorflow::serving::LogCollectorConfig* LoggingConfig::mutable_log_collector_config() {
  
  if (log_collector_config_ == NULL) {
    _slow_mutable_log_collector_config();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.LoggingConfig.log_collector_config)
  return log_collector_config_;
}
::tensorflow::serving::LogCollectorConfig* LoggingConfig::release_log_collector_config() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.LoggingConfig.log_collector_config)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_log_collector_config();
  } else {
    ::tensorflow::serving::LogCollectorConfig* temp = log_collector_config_;
    log_collector_config_ = NULL;
    return temp;
  }
}
 void LoggingConfig::set_allocated_log_collector_config(::tensorflow::serving::LogCollectorConfig* log_collector_config) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete log_collector_config_;
  }
  if (log_collector_config != NULL) {
    _slow_set_allocated_log_collector_config(message_arena, &log_collector_config);
  }
  log_collector_config_ = log_collector_config;
  if (log_collector_config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.LoggingConfig.log_collector_config)
}

// optional .tensorflow.serving.SamplingConfig sampling_config = 2;
bool LoggingConfig::has_sampling_config() const {
  return !_is_default_instance_ && sampling_config_ != NULL;
}
void LoggingConfig::clear_sampling_config() {
  if (GetArenaNoVirtual() == NULL && sampling_config_ != NULL) delete sampling_config_;
  sampling_config_ = NULL;
}
const ::tensorflow::serving::SamplingConfig& LoggingConfig::sampling_config() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.LoggingConfig.sampling_config)
  return sampling_config_ != NULL ? *sampling_config_ : *default_instance_->sampling_config_;
}
::tensorflow::serving::SamplingConfig* LoggingConfig::mutable_sampling_config() {
  
  if (sampling_config_ == NULL) {
    _slow_mutable_sampling_config();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.LoggingConfig.sampling_config)
  return sampling_config_;
}
::tensorflow::serving::SamplingConfig* LoggingConfig::release_sampling_config() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.LoggingConfig.sampling_config)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_sampling_config();
  } else {
    ::tensorflow::serving::SamplingConfig* temp = sampling_config_;
    sampling_config_ = NULL;
    return temp;
  }
}
 void LoggingConfig::set_allocated_sampling_config(::tensorflow::serving::SamplingConfig* sampling_config) {
  ::google::protobuf::Arena* message_arena = GetArenaNoVirtual();
  if (message_arena == NULL) {
    delete sampling_config_;
  }
  if (sampling_config != NULL) {
    _slow_set_allocated_sampling_config(message_arena, &sampling_config);
  }
  sampling_config_ = sampling_config;
  if (sampling_config) {
    
  } else {
    
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.LoggingConfig.sampling_config)
}

#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace serving
}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)
