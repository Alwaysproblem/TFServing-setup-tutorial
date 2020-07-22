// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow_serving/core/logging.proto

#include "tensorflow_serving/core/logging.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
extern PROTOBUF_INTERNAL_EXPORT_tensorflow_5fserving_2fapis_2fmodel_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<1> scc_info_ModelSpec_tensorflow_5fserving_2fapis_2fmodel_2eproto;
extern PROTOBUF_INTERNAL_EXPORT_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto ::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_SamplingConfig_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto;
namespace tensorflow {
namespace serving {
class LogMetadataDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<LogMetadata> _instance;
} _LogMetadata_default_instance_;
}  // namespace serving
}  // namespace tensorflow
static void InitDefaultsscc_info_LogMetadata_tensorflow_5fserving_2fcore_2flogging_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::serving::_LogMetadata_default_instance_;
    new (ptr) ::tensorflow::serving::LogMetadata();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::serving::LogMetadata::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<2> scc_info_LogMetadata_tensorflow_5fserving_2fcore_2flogging_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 2, 0, InitDefaultsscc_info_LogMetadata_tensorflow_5fserving_2fcore_2flogging_2eproto}, {
      &scc_info_ModelSpec_tensorflow_5fserving_2fapis_2fmodel_2eproto.base,
      &scc_info_SamplingConfig_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto.base,}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_tensorflow_5fserving_2fcore_2flogging_2eproto[1];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_tensorflow_5fserving_2fcore_2flogging_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_tensorflow_5fserving_2fcore_2flogging_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_tensorflow_5fserving_2fcore_2flogging_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, model_spec_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, sampling_config_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::serving::LogMetadata, saved_model_tags_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::tensorflow::serving::LogMetadata)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::serving::_LogMetadata_default_instance_),
};

const char descriptor_table_protodef_tensorflow_5fserving_2fcore_2flogging_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n%tensorflow_serving/core/logging.proto\022"
  "\022tensorflow.serving\032#tensorflow_serving/"
  "apis/model.proto\032.tensorflow_serving/con"
  "fig/logging_config.proto\"\227\001\n\013LogMetadata"
  "\0221\n\nmodel_spec\030\001 \001(\0132\035.tensorflow.servin"
  "g.ModelSpec\022;\n\017sampling_config\030\002 \001(\0132\".t"
  "ensorflow.serving.SamplingConfig\022\030\n\020save"
  "d_model_tags\030\003 \003(\tB\003\370\001\001b\006proto3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto_deps[2] = {
  &::descriptor_table_tensorflow_5fserving_2fapis_2fmodel_2eproto,
  &::descriptor_table_tensorflow_5fserving_2fconfig_2flogging_5fconfig_2eproto,
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto_sccs[1] = {
  &scc_info_LogMetadata_tensorflow_5fserving_2fcore_2flogging_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto_once;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto = {
  false, false, descriptor_table_protodef_tensorflow_5fserving_2fcore_2flogging_2eproto, "tensorflow_serving/core/logging.proto", 311,
  &descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto_once, descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto_sccs, descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto_deps, 1, 2,
  schemas, file_default_instances, TableStruct_tensorflow_5fserving_2fcore_2flogging_2eproto::offsets,
  file_level_metadata_tensorflow_5fserving_2fcore_2flogging_2eproto, 1, file_level_enum_descriptors_tensorflow_5fserving_2fcore_2flogging_2eproto, file_level_service_descriptors_tensorflow_5fserving_2fcore_2flogging_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_tensorflow_5fserving_2fcore_2flogging_2eproto = (static_cast<void>(::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_tensorflow_5fserving_2fcore_2flogging_2eproto)), true);
namespace tensorflow {
namespace serving {

// ===================================================================

void LogMetadata::InitAsDefaultInstance() {
  ::tensorflow::serving::_LogMetadata_default_instance_._instance.get_mutable()->model_spec_ = const_cast< ::tensorflow::serving::ModelSpec*>(
      ::tensorflow::serving::ModelSpec::internal_default_instance());
  ::tensorflow::serving::_LogMetadata_default_instance_._instance.get_mutable()->sampling_config_ = const_cast< ::tensorflow::serving::SamplingConfig*>(
      ::tensorflow::serving::SamplingConfig::internal_default_instance());
}
class LogMetadata::_Internal {
 public:
  static const ::tensorflow::serving::ModelSpec& model_spec(const LogMetadata* msg);
  static const ::tensorflow::serving::SamplingConfig& sampling_config(const LogMetadata* msg);
};

const ::tensorflow::serving::ModelSpec&
LogMetadata::_Internal::model_spec(const LogMetadata* msg) {
  return *msg->model_spec_;
}
const ::tensorflow::serving::SamplingConfig&
LogMetadata::_Internal::sampling_config(const LogMetadata* msg) {
  return *msg->sampling_config_;
}
void LogMetadata::clear_model_spec() {
  if (GetArena() == nullptr && model_spec_ != nullptr) {
    delete model_spec_;
  }
  model_spec_ = nullptr;
}
void LogMetadata::clear_sampling_config() {
  if (GetArena() == nullptr && sampling_config_ != nullptr) {
    delete sampling_config_;
  }
  sampling_config_ = nullptr;
}
LogMetadata::LogMetadata(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(arena),
  saved_model_tags_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.serving.LogMetadata)
}
LogMetadata::LogMetadata(const LogMetadata& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      saved_model_tags_(from.saved_model_tags_) {
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  if (from._internal_has_model_spec()) {
    model_spec_ = new ::tensorflow::serving::ModelSpec(*from.model_spec_);
  } else {
    model_spec_ = nullptr;
  }
  if (from._internal_has_sampling_config()) {
    sampling_config_ = new ::tensorflow::serving::SamplingConfig(*from.sampling_config_);
  } else {
    sampling_config_ = nullptr;
  }
  // @@protoc_insertion_point(copy_constructor:tensorflow.serving.LogMetadata)
}

void LogMetadata::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_LogMetadata_tensorflow_5fserving_2fcore_2flogging_2eproto.base);
  ::memset(&model_spec_, 0, static_cast<size_t>(
      reinterpret_cast<char*>(&sampling_config_) -
      reinterpret_cast<char*>(&model_spec_)) + sizeof(sampling_config_));
}

LogMetadata::~LogMetadata() {
  // @@protoc_insertion_point(destructor:tensorflow.serving.LogMetadata)
  SharedDtor();
  _internal_metadata_.Delete<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

void LogMetadata::SharedDtor() {
  GOOGLE_DCHECK(GetArena() == nullptr);
  if (this != internal_default_instance()) delete model_spec_;
  if (this != internal_default_instance()) delete sampling_config_;
}

void LogMetadata::ArenaDtor(void* object) {
  LogMetadata* _this = reinterpret_cast< LogMetadata* >(object);
  (void)_this;
}
void LogMetadata::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void LogMetadata::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const LogMetadata& LogMetadata::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_LogMetadata_tensorflow_5fserving_2fcore_2flogging_2eproto.base);
  return *internal_default_instance();
}


void LogMetadata::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.serving.LogMetadata)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  saved_model_tags_.Clear();
  if (GetArena() == nullptr && model_spec_ != nullptr) {
    delete model_spec_;
  }
  model_spec_ = nullptr;
  if (GetArena() == nullptr && sampling_config_ != nullptr) {
    delete sampling_config_;
  }
  sampling_config_ = nullptr;
  _internal_metadata_.Clear<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>();
}

const char* LogMetadata::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArena(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // .tensorflow.serving.ModelSpec model_spec = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ctx->ParseMessage(_internal_mutable_model_spec(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // .tensorflow.serving.SamplingConfig sampling_config = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 18)) {
          ptr = ctx->ParseMessage(_internal_mutable_sampling_config(), ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // repeated string saved_model_tags = 3;
      case 3:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 26)) {
          ptr -= 1;
          do {
            ptr += 1;
            auto str = _internal_add_saved_model_tags();
            ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParser(str, ptr, ctx);
            CHK_(::PROTOBUF_NAMESPACE_ID::internal::VerifyUTF8(str, "tensorflow.serving.LogMetadata.saved_model_tags"));
            CHK_(ptr);
            if (!ctx->DataAvailable(ptr)) break;
          } while (::PROTOBUF_NAMESPACE_ID::internal::ExpectTag<26>(ptr));
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag,
            _internal_metadata_.mutable_unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(),
            ptr, ctx);
        CHK_(ptr != nullptr);
        continue;
      }
    }  // switch
  }  // while
success:
  return ptr;
failure:
  ptr = nullptr;
  goto success;
#undef CHK_
}

::PROTOBUF_NAMESPACE_ID::uint8* LogMetadata::_InternalSerialize(
    ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.serving.LogMetadata)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // .tensorflow.serving.ModelSpec model_spec = 1;
  if (this->has_model_spec()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        1, _Internal::model_spec(this), target, stream);
  }

  // .tensorflow.serving.SamplingConfig sampling_config = 2;
  if (this->has_sampling_config()) {
    target = stream->EnsureSpace(target);
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::
      InternalWriteMessage(
        2, _Internal::sampling_config(this), target, stream);
  }

  // repeated string saved_model_tags = 3;
  for (int i = 0, n = this->_internal_saved_model_tags_size(); i < n; i++) {
    const auto& s = this->_internal_saved_model_tags(i);
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      s.data(), static_cast<int>(s.length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.serving.LogMetadata.saved_model_tags");
    target = stream->WriteString(3, s, target);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::InternalSerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(::PROTOBUF_NAMESPACE_ID::UnknownFieldSet::default_instance), target, stream);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.serving.LogMetadata)
  return target;
}

size_t LogMetadata::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.serving.LogMetadata)
  size_t total_size = 0;

  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // repeated string saved_model_tags = 3;
  total_size += 1 *
      ::PROTOBUF_NAMESPACE_ID::internal::FromIntSize(saved_model_tags_.size());
  for (int i = 0, n = saved_model_tags_.size(); i < n; i++) {
    total_size += ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
      saved_model_tags_.Get(i));
  }

  // .tensorflow.serving.ModelSpec model_spec = 1;
  if (this->has_model_spec()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *model_spec_);
  }

  // .tensorflow.serving.SamplingConfig sampling_config = 2;
  if (this->has_sampling_config()) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::MessageSize(
        *sampling_config_);
  }

  if (PROTOBUF_PREDICT_FALSE(_internal_metadata_.have_unknown_fields())) {
    return ::PROTOBUF_NAMESPACE_ID::internal::ComputeUnknownFieldsSize(
        _internal_metadata_, total_size, &_cached_size_);
  }
  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void LogMetadata::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.serving.LogMetadata)
  GOOGLE_DCHECK_NE(&from, this);
  const LogMetadata* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<LogMetadata>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.serving.LogMetadata)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.serving.LogMetadata)
    MergeFrom(*source);
  }
}

void LogMetadata::MergeFrom(const LogMetadata& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.serving.LogMetadata)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  saved_model_tags_.MergeFrom(from.saved_model_tags_);
  if (from.has_model_spec()) {
    _internal_mutable_model_spec()->::tensorflow::serving::ModelSpec::MergeFrom(from._internal_model_spec());
  }
  if (from.has_sampling_config()) {
    _internal_mutable_sampling_config()->::tensorflow::serving::SamplingConfig::MergeFrom(from._internal_sampling_config());
  }
}

void LogMetadata::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.serving.LogMetadata)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void LogMetadata::CopyFrom(const LogMetadata& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.serving.LogMetadata)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool LogMetadata::IsInitialized() const {
  return true;
}

void LogMetadata::InternalSwap(LogMetadata* other) {
  using std::swap;
  _internal_metadata_.Swap<::PROTOBUF_NAMESPACE_ID::UnknownFieldSet>(&other->_internal_metadata_);
  saved_model_tags_.InternalSwap(&other->saved_model_tags_);
  ::PROTOBUF_NAMESPACE_ID::internal::memswap<
      PROTOBUF_FIELD_OFFSET(LogMetadata, sampling_config_)
      + sizeof(LogMetadata::sampling_config_)
      - PROTOBUF_FIELD_OFFSET(LogMetadata, model_spec_)>(
          reinterpret_cast<char*>(&model_spec_),
          reinterpret_cast<char*>(&other->model_spec_));
}

::PROTOBUF_NAMESPACE_ID::Metadata LogMetadata::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace serving
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tensorflow::serving::LogMetadata* Arena::CreateMaybeMessage< ::tensorflow::serving::LogMetadata >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::serving::LogMetadata >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>
