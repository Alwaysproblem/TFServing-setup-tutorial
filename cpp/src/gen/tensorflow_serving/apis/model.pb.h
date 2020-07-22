// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow_serving/apis/model.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_tensorflow_5fserving_2fapis_2fmodel_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_tensorflow_5fserving_2fapis_2fmodel_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3008000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3008000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include <google/protobuf/wrappers.pb.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_tensorflow_5fserving_2fapis_2fmodel_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_tensorflow_5fserving_2fapis_2fmodel_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tensorflow_5fserving_2fapis_2fmodel_2eproto;
namespace tensorflow {
namespace serving {
class ModelSpec;
class ModelSpecDefaultTypeInternal;
extern ModelSpecDefaultTypeInternal _ModelSpec_default_instance_;
}  // namespace serving
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> ::tensorflow::serving::ModelSpec* Arena::CreateMaybeMessage<::tensorflow::serving::ModelSpec>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace tensorflow {
namespace serving {

// ===================================================================

class ModelSpec :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:tensorflow.serving.ModelSpec) */ {
 public:
  ModelSpec();
  virtual ~ModelSpec();

  ModelSpec(const ModelSpec& from);
  ModelSpec(ModelSpec&& from) noexcept
    : ModelSpec() {
    *this = ::std::move(from);
  }

  inline ModelSpec& operator=(const ModelSpec& from) {
    CopyFrom(from);
    return *this;
  }
  inline ModelSpec& operator=(ModelSpec&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArena() const final {
    return GetArenaNoVirtual();
  }
  inline void* GetMaybeArenaPointer() const final {
    return MaybeArenaPtr();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const ModelSpec& default_instance();

  enum VersionChoiceCase {
    kVersion = 2,
    kVersionLabel = 4,
    VERSION_CHOICE_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ModelSpec* internal_default_instance() {
    return reinterpret_cast<const ModelSpec*>(
               &_ModelSpec_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  void UnsafeArenaSwap(ModelSpec* other);
  void Swap(ModelSpec* other);
  friend void swap(ModelSpec& a, ModelSpec& b) {
    a.Swap(&b);
  }

  // implements Message ----------------------------------------------

  inline ModelSpec* New() const final {
    return CreateMaybeMessage<ModelSpec>(nullptr);
  }

  ModelSpec* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ModelSpec>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ModelSpec& from);
  void MergeFrom(const ModelSpec& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  #if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  #else
  bool MergePartialFromCodedStream(
      ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) final;
  #endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
  void SerializeWithCachedSizes(
      ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const final;
  ::PROTOBUF_NAMESPACE_ID::uint8* InternalSerializeWithCachedSizesToArray(
      ::PROTOBUF_NAMESPACE_ID::uint8* target) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(ModelSpec* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "tensorflow.serving.ModelSpec";
  }
  protected:
  explicit ModelSpec(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_tensorflow_5fserving_2fapis_2fmodel_2eproto);
    return ::descriptor_table_tensorflow_5fserving_2fapis_2fmodel_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // string name = 1;
  void clear_name();
  static const int kNameFieldNumber = 1;
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_name();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_name(
      std::string* name);

  // string signature_name = 3;
  void clear_signature_name();
  static const int kSignatureNameFieldNumber = 3;
  const std::string& signature_name() const;
  void set_signature_name(const std::string& value);
  void set_signature_name(std::string&& value);
  void set_signature_name(const char* value);
  void set_signature_name(const char* value, size_t size);
  std::string* mutable_signature_name();
  std::string* release_signature_name();
  void set_allocated_signature_name(std::string* signature_name);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_signature_name();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_signature_name(
      std::string* signature_name);

  // .google.protobuf.Int64Value version = 2;
  bool has_version() const;
  void clear_version();
  static const int kVersionFieldNumber = 2;
  const PROTOBUF_NAMESPACE_ID::Int64Value& version() const;
  PROTOBUF_NAMESPACE_ID::Int64Value* release_version();
  PROTOBUF_NAMESPACE_ID::Int64Value* mutable_version();
  void set_allocated_version(PROTOBUF_NAMESPACE_ID::Int64Value* version);
  void unsafe_arena_set_allocated_version(
      PROTOBUF_NAMESPACE_ID::Int64Value* version);
  PROTOBUF_NAMESPACE_ID::Int64Value* unsafe_arena_release_version();

  // string version_label = 4;
  private:
  bool has_version_label() const;
  public:
  void clear_version_label();
  static const int kVersionLabelFieldNumber = 4;
  const std::string& version_label() const;
  void set_version_label(const std::string& value);
  void set_version_label(std::string&& value);
  void set_version_label(const char* value);
  void set_version_label(const char* value, size_t size);
  std::string* mutable_version_label();
  std::string* release_version_label();
  void set_allocated_version_label(std::string* version_label);
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  std::string* unsafe_arena_release_version_label();
  GOOGLE_PROTOBUF_RUNTIME_DEPRECATED("The unsafe_arena_ accessors for"
  "    string fields are deprecated and will be removed in a"
  "    future release.")
  void unsafe_arena_set_allocated_version_label(
      std::string* version_label);

  void clear_version_choice();
  VersionChoiceCase version_choice_case() const;
  // @@protoc_insertion_point(class_scope:tensorflow.serving.ModelSpec)
 private:
  class HasBitSetters;
  void set_has_version();
  void set_has_version_label();

  inline bool has_version_choice() const;
  inline void clear_has_version_choice();

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr signature_name_;
  union VersionChoiceUnion {
    VersionChoiceUnion() {}
    PROTOBUF_NAMESPACE_ID::Int64Value* version_;
    ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr version_label_;
  } version_choice_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_tensorflow_5fserving_2fapis_2fmodel_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ModelSpec

// string name = 1;
inline void ModelSpec::clear_name() {
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const std::string& ModelSpec::name() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.name)
  return name_.Get();
}
inline void ModelSpec::set_name(const std::string& value) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.name)
}
inline void ModelSpec::set_name(std::string&& value) {
  
  name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_rvalue:tensorflow.serving.ModelSpec.name)
}
inline void ModelSpec::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.serving.ModelSpec.name)
}
inline void ModelSpec::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.serving.ModelSpec.name)
}
inline std::string* ModelSpec::mutable_name() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.name)
  return name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline std::string* ModelSpec::release_name() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.name)
  
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void ModelSpec::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.ModelSpec.name)
}
inline std::string* ModelSpec::unsafe_arena_release_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.ModelSpec.name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  
  return name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ModelSpec::unsafe_arena_set_allocated_name(
    std::string* name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  if (name != nullptr) {
    
  } else {
    
  }
  name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.ModelSpec.name)
}

// .google.protobuf.Int64Value version = 2;
inline bool ModelSpec::has_version() const {
  return version_choice_case() == kVersion;
}
inline void ModelSpec::set_has_version() {
  _oneof_case_[0] = kVersion;
}
inline PROTOBUF_NAMESPACE_ID::Int64Value* ModelSpec::release_version() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.version)
  if (has_version()) {
    clear_has_version_choice();
      PROTOBUF_NAMESPACE_ID::Int64Value* temp = version_choice_.version_;
    if (GetArenaNoVirtual() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    version_choice_.version_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const PROTOBUF_NAMESPACE_ID::Int64Value& ModelSpec::version() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.version)
  return has_version()
      ? *version_choice_.version_
      : *reinterpret_cast< PROTOBUF_NAMESPACE_ID::Int64Value*>(&PROTOBUF_NAMESPACE_ID::_Int64Value_default_instance_);
}
inline PROTOBUF_NAMESPACE_ID::Int64Value* ModelSpec::unsafe_arena_release_version() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.ModelSpec.version)
  if (has_version()) {
    clear_has_version_choice();
    PROTOBUF_NAMESPACE_ID::Int64Value* temp = version_choice_.version_;
    version_choice_.version_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void ModelSpec::unsafe_arena_set_allocated_version(PROTOBUF_NAMESPACE_ID::Int64Value* version) {
  clear_version_choice();
  if (version) {
    set_has_version();
    version_choice_.version_ = version;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.ModelSpec.version)
}
inline PROTOBUF_NAMESPACE_ID::Int64Value* ModelSpec::mutable_version() {
  if (!has_version()) {
    clear_version_choice();
    set_has_version();
    version_choice_.version_ = CreateMaybeMessage< PROTOBUF_NAMESPACE_ID::Int64Value >(
        GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.version)
  return version_choice_.version_;
}

// string version_label = 4;
inline bool ModelSpec::has_version_label() const {
  return version_choice_case() == kVersionLabel;
}
inline void ModelSpec::set_has_version_label() {
  _oneof_case_[0] = kVersionLabel;
}
inline void ModelSpec::clear_version_label() {
  if (has_version_label()) {
    version_choice_.version_label_.Destroy(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
        GetArenaNoVirtual());
    clear_has_version_choice();
  }
}
inline const std::string& ModelSpec::version_label() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.version_label)
  if (has_version_label()) {
    return version_choice_.version_label_.Get();
  }
  return *&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited();
}
inline void ModelSpec::set_version_label(const std::string& value) {
  if (!has_version_label()) {
    clear_version_choice();
    set_has_version_label();
    version_choice_.version_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  version_choice_.version_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.version_label)
}
inline void ModelSpec::set_version_label(std::string&& value) {
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.version_label)
  if (!has_version_label()) {
    clear_version_choice();
    set_has_version_label();
    version_choice_.version_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  version_choice_.version_label_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_rvalue:tensorflow.serving.ModelSpec.version_label)
}
inline void ModelSpec::set_version_label(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  if (!has_version_label()) {
    clear_version_choice();
    set_has_version_label();
    version_choice_.version_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  version_choice_.version_label_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.serving.ModelSpec.version_label)
}
inline void ModelSpec::set_version_label(const char* value,
                             size_t size) {
  if (!has_version_label()) {
    clear_version_choice();
    set_has_version_label();
    version_choice_.version_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  version_choice_.version_label_.Set(
      &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size),
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.serving.ModelSpec.version_label)
}
inline std::string* ModelSpec::mutable_version_label() {
  if (!has_version_label()) {
    clear_version_choice();
    set_has_version_label();
    version_choice_.version_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  return version_choice_.version_label_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.version_label)
}
inline std::string* ModelSpec::release_version_label() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.version_label)
  if (has_version_label()) {
    clear_has_version_choice();
    return version_choice_.version_label_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
        GetArenaNoVirtual());
  } else {
    return nullptr;
  }
}
inline void ModelSpec::set_allocated_version_label(std::string* version_label) {
  if (has_version_choice()) {
    clear_version_choice();
  }
  if (version_label != nullptr) {
    set_has_version_label();
    version_choice_.version_label_.UnsafeSetDefault(version_label);
  }
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.ModelSpec.version_label)
}
inline std::string* ModelSpec::unsafe_arena_release_version_label() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.ModelSpec.version_label)
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  if (has_version_label()) {
    clear_has_version_choice();
    return version_choice_.version_label_.UnsafeArenaRelease(
        &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
  } else {
    return nullptr;
  }
}
inline void ModelSpec::unsafe_arena_set_allocated_version_label(std::string* version_label) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  if (!has_version_label()) {
    version_choice_.version_label_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  }
  clear_version_choice();
  if (version_label) {
    set_has_version_label();
    version_choice_.version_label_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), version_label, GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.ModelSpec.version_label)
}

// string signature_name = 3;
inline void ModelSpec::clear_signature_name() {
  signature_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline const std::string& ModelSpec::signature_name() const {
  // @@protoc_insertion_point(field_get:tensorflow.serving.ModelSpec.signature_name)
  return signature_name_.Get();
}
inline void ModelSpec::set_signature_name(const std::string& value) {
  
  signature_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set:tensorflow.serving.ModelSpec.signature_name)
}
inline void ModelSpec::set_signature_name(std::string&& value) {
  
  signature_name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_rvalue:tensorflow.serving.ModelSpec.signature_name)
}
inline void ModelSpec::set_signature_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  signature_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_char:tensorflow.serving.ModelSpec.signature_name)
}
inline void ModelSpec::set_signature_name(const char* value,
    size_t size) {
  
  signature_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_pointer:tensorflow.serving.ModelSpec.signature_name)
}
inline std::string* ModelSpec::mutable_signature_name() {
  
  // @@protoc_insertion_point(field_mutable:tensorflow.serving.ModelSpec.signature_name)
  return signature_name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline std::string* ModelSpec::release_signature_name() {
  // @@protoc_insertion_point(field_release:tensorflow.serving.ModelSpec.signature_name)
  
  return signature_name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
}
inline void ModelSpec::set_allocated_signature_name(std::string* signature_name) {
  if (signature_name != nullptr) {
    
  } else {
    
  }
  signature_name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), signature_name,
      GetArenaNoVirtual());
  // @@protoc_insertion_point(field_set_allocated:tensorflow.serving.ModelSpec.signature_name)
}
inline std::string* ModelSpec::unsafe_arena_release_signature_name() {
  // @@protoc_insertion_point(field_unsafe_arena_release:tensorflow.serving.ModelSpec.signature_name)
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  
  return signature_name_.UnsafeArenaRelease(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      GetArenaNoVirtual());
}
inline void ModelSpec::unsafe_arena_set_allocated_signature_name(
    std::string* signature_name) {
  GOOGLE_DCHECK(GetArenaNoVirtual() != nullptr);
  if (signature_name != nullptr) {
    
  } else {
    
  }
  signature_name_.UnsafeArenaSetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      signature_name, GetArenaNoVirtual());
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:tensorflow.serving.ModelSpec.signature_name)
}

inline bool ModelSpec::has_version_choice() const {
  return version_choice_case() != VERSION_CHOICE_NOT_SET;
}
inline void ModelSpec::clear_has_version_choice() {
  _oneof_case_[0] = VERSION_CHOICE_NOT_SET;
}
inline ModelSpec::VersionChoiceCase ModelSpec::version_choice_case() const {
  return ModelSpec::VersionChoiceCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace serving
}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_tensorflow_5fserving_2fapis_2fmodel_2eproto