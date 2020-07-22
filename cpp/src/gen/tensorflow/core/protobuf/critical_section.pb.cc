// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/protobuf/critical_section.proto

#include "tensorflow/core/protobuf/critical_section.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
namespace tensorflow {
class CriticalSectionDefDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CriticalSectionDef> _instance;
} _CriticalSectionDef_default_instance_;
class CriticalSectionExecutionDefDefaultTypeInternal {
 public:
  ::PROTOBUF_NAMESPACE_ID::internal::ExplicitlyConstructed<CriticalSectionExecutionDef> _instance;
} _CriticalSectionExecutionDef_default_instance_;
}  // namespace tensorflow
static void InitDefaultsscc_info_CriticalSectionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_CriticalSectionDef_default_instance_;
    new (ptr) ::tensorflow::CriticalSectionDef();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::CriticalSectionDef::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CriticalSectionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_CriticalSectionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto}, {}};

static void InitDefaultsscc_info_CriticalSectionExecutionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  {
    void* ptr = &::tensorflow::_CriticalSectionExecutionDef_default_instance_;
    new (ptr) ::tensorflow::CriticalSectionExecutionDef();
    ::PROTOBUF_NAMESPACE_ID::internal::OnShutdownDestroyMessage(ptr);
  }
  ::tensorflow::CriticalSectionExecutionDef::InitAsDefaultInstance();
}

::PROTOBUF_NAMESPACE_ID::internal::SCCInfo<0> scc_info_CriticalSectionExecutionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto =
    {{ATOMIC_VAR_INIT(::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase::kUninitialized), 0, InitDefaultsscc_info_CriticalSectionExecutionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto}, {}};

static ::PROTOBUF_NAMESPACE_ID::Metadata file_level_metadata_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto[2];
static constexpr ::PROTOBUF_NAMESPACE_ID::EnumDescriptor const** file_level_enum_descriptors_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto = nullptr;
static constexpr ::PROTOBUF_NAMESPACE_ID::ServiceDescriptor const** file_level_service_descriptors_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto = nullptr;

const ::PROTOBUF_NAMESPACE_ID::uint32 TableStruct_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto::offsets[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::CriticalSectionDef, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::CriticalSectionDef, critical_section_name_),
  ~0u,  // no _has_bits_
  PROTOBUF_FIELD_OFFSET(::tensorflow::CriticalSectionExecutionDef, _internal_metadata_),
  ~0u,  // no _extensions_
  ~0u,  // no _oneof_case_
  ~0u,  // no _weak_field_map_
  PROTOBUF_FIELD_OFFSET(::tensorflow::CriticalSectionExecutionDef, execute_in_critical_section_name_),
  PROTOBUF_FIELD_OFFSET(::tensorflow::CriticalSectionExecutionDef, exclusive_resource_access_),
};
static const ::PROTOBUF_NAMESPACE_ID::internal::MigrationSchema schemas[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) = {
  { 0, -1, sizeof(::tensorflow::CriticalSectionDef)},
  { 6, -1, sizeof(::tensorflow::CriticalSectionExecutionDef)},
};

static ::PROTOBUF_NAMESPACE_ID::Message const * const file_default_instances[] = {
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_CriticalSectionDef_default_instance_),
  reinterpret_cast<const ::PROTOBUF_NAMESPACE_ID::Message*>(&::tensorflow::_CriticalSectionExecutionDef_default_instance_),
};

const char descriptor_table_protodef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto[] =
  "\n/tensorflow/core/protobuf/critical_sect"
  "ion.proto\022\ntensorflow\"3\n\022CriticalSection"
  "Def\022\035\n\025critical_section_name\030\001 \001(\t\"j\n\033Cr"
  "iticalSectionExecutionDef\022(\n execute_in_"
  "critical_section_name\030\001 \001(\t\022!\n\031exclusive"
  "_resource_access\030\002 \001(\010B\200\001\n\030org.tensorflo"
  "w.frameworkB\025CriticalSectionProtosP\001ZHgi"
  "thub.com/tensorflow/tensorflow/tensorflo"
  "w/go/core/core_protos_go_proto\370\001\001b\006proto"
  "3"
  ;
static const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable*const descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_deps[1] = {
};
static ::PROTOBUF_NAMESPACE_ID::internal::SCCInfoBase*const descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_sccs[2] = {
  &scc_info_CriticalSectionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto.base,
  &scc_info_CriticalSectionExecutionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto.base,
};
static ::PROTOBUF_NAMESPACE_ID::internal::once_flag descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_once;
static bool descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_initialized = false;
const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto = {
  &descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_initialized, descriptor_table_protodef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto, "tensorflow/core/protobuf/critical_section.proto", 361,
  &descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_once, descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_sccs, descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto_deps, 2, 0,
  schemas, file_default_instances, TableStruct_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto::offsets,
  file_level_metadata_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto, 2, file_level_enum_descriptors_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto, file_level_service_descriptors_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto,
};

// Force running AddDescriptors() at dynamic initialization time.
static bool dynamic_init_dummy_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto = (  ::PROTOBUF_NAMESPACE_ID::internal::AddDescriptors(&descriptor_table_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto), true);
namespace tensorflow {

// ===================================================================

void CriticalSectionDef::InitAsDefaultInstance() {
}
class CriticalSectionDef::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CriticalSectionDef::kCriticalSectionNameFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CriticalSectionDef::CriticalSectionDef()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.CriticalSectionDef)
}
CriticalSectionDef::CriticalSectionDef(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.CriticalSectionDef)
}
CriticalSectionDef::CriticalSectionDef(const CriticalSectionDef& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  critical_section_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.critical_section_name().size() > 0) {
    critical_section_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.critical_section_name(),
      GetArenaNoVirtual());
  }
  // @@protoc_insertion_point(copy_constructor:tensorflow.CriticalSectionDef)
}

void CriticalSectionDef::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CriticalSectionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto.base);
  critical_section_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

CriticalSectionDef::~CriticalSectionDef() {
  // @@protoc_insertion_point(destructor:tensorflow.CriticalSectionDef)
  SharedDtor();
}

void CriticalSectionDef::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == nullptr);
  critical_section_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CriticalSectionDef::ArenaDtor(void* object) {
  CriticalSectionDef* _this = reinterpret_cast< CriticalSectionDef* >(object);
  (void)_this;
}
void CriticalSectionDef::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CriticalSectionDef::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CriticalSectionDef& CriticalSectionDef::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CriticalSectionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto.base);
  return *internal_default_instance();
}


void CriticalSectionDef::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.CriticalSectionDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  critical_section_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* CriticalSectionDef::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaNoVirtual(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string critical_section_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(mutable_critical_section_name(), ptr, ctx, "tensorflow.CriticalSectionDef.critical_section_name");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
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
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool CriticalSectionDef::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.CriticalSectionDef)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string critical_section_name = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_critical_section_name()));
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->critical_section_name().data(), static_cast<int>(this->critical_section_name().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE,
            "tensorflow.CriticalSectionDef.critical_section_name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.CriticalSectionDef)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.CriticalSectionDef)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void CriticalSectionDef::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.CriticalSectionDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string critical_section_name = 1;
  if (this->critical_section_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->critical_section_name().data(), static_cast<int>(this->critical_section_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.CriticalSectionDef.critical_section_name");
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->critical_section_name(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.CriticalSectionDef)
}

::PROTOBUF_NAMESPACE_ID::uint8* CriticalSectionDef::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.CriticalSectionDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string critical_section_name = 1;
  if (this->critical_section_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->critical_section_name().data(), static_cast<int>(this->critical_section_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.CriticalSectionDef.critical_section_name");
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringToArray(
        1, this->critical_section_name(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.CriticalSectionDef)
  return target;
}

size_t CriticalSectionDef::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.CriticalSectionDef)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string critical_section_name = 1;
  if (this->critical_section_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->critical_section_name());
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CriticalSectionDef::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.CriticalSectionDef)
  GOOGLE_DCHECK_NE(&from, this);
  const CriticalSectionDef* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CriticalSectionDef>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.CriticalSectionDef)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.CriticalSectionDef)
    MergeFrom(*source);
  }
}

void CriticalSectionDef::MergeFrom(const CriticalSectionDef& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.CriticalSectionDef)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.critical_section_name().size() > 0) {
    set_critical_section_name(from.critical_section_name());
  }
}

void CriticalSectionDef::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.CriticalSectionDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CriticalSectionDef::CopyFrom(const CriticalSectionDef& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.CriticalSectionDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CriticalSectionDef::IsInitialized() const {
  return true;
}

void CriticalSectionDef::Swap(CriticalSectionDef* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    CriticalSectionDef* temp = New(GetArenaNoVirtual());
    temp->MergeFrom(*other);
    other->CopyFrom(*this);
    InternalSwap(temp);
    if (GetArenaNoVirtual() == nullptr) {
      delete temp;
    }
  }
}
void CriticalSectionDef::UnsafeArenaSwap(CriticalSectionDef* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void CriticalSectionDef::InternalSwap(CriticalSectionDef* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  critical_section_name_.Swap(&other->critical_section_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
}

::PROTOBUF_NAMESPACE_ID::Metadata CriticalSectionDef::GetMetadata() const {
  return GetMetadataStatic();
}


// ===================================================================

void CriticalSectionExecutionDef::InitAsDefaultInstance() {
}
class CriticalSectionExecutionDef::HasBitSetters {
 public:
};

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int CriticalSectionExecutionDef::kExecuteInCriticalSectionNameFieldNumber;
const int CriticalSectionExecutionDef::kExclusiveResourceAccessFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

CriticalSectionExecutionDef::CriticalSectionExecutionDef()
  : ::PROTOBUF_NAMESPACE_ID::Message(), _internal_metadata_(nullptr) {
  SharedCtor();
  // @@protoc_insertion_point(constructor:tensorflow.CriticalSectionExecutionDef)
}
CriticalSectionExecutionDef::CriticalSectionExecutionDef(::PROTOBUF_NAMESPACE_ID::Arena* arena)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
  _internal_metadata_(arena) {
  SharedCtor();
  RegisterArenaDtor(arena);
  // @@protoc_insertion_point(arena_constructor:tensorflow.CriticalSectionExecutionDef)
}
CriticalSectionExecutionDef::CriticalSectionExecutionDef(const CriticalSectionExecutionDef& from)
  : ::PROTOBUF_NAMESPACE_ID::Message(),
      _internal_metadata_(nullptr) {
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  execute_in_critical_section_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  if (from.execute_in_critical_section_name().size() > 0) {
    execute_in_critical_section_name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), from.execute_in_critical_section_name(),
      GetArenaNoVirtual());
  }
  exclusive_resource_access_ = from.exclusive_resource_access_;
  // @@protoc_insertion_point(copy_constructor:tensorflow.CriticalSectionExecutionDef)
}

void CriticalSectionExecutionDef::SharedCtor() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&scc_info_CriticalSectionExecutionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto.base);
  execute_in_critical_section_name_.UnsafeSetDefault(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  exclusive_resource_access_ = false;
}

CriticalSectionExecutionDef::~CriticalSectionExecutionDef() {
  // @@protoc_insertion_point(destructor:tensorflow.CriticalSectionExecutionDef)
  SharedDtor();
}

void CriticalSectionExecutionDef::SharedDtor() {
  GOOGLE_DCHECK(GetArenaNoVirtual() == nullptr);
  execute_in_critical_section_name_.DestroyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}

void CriticalSectionExecutionDef::ArenaDtor(void* object) {
  CriticalSectionExecutionDef* _this = reinterpret_cast< CriticalSectionExecutionDef* >(object);
  (void)_this;
}
void CriticalSectionExecutionDef::RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena*) {
}
void CriticalSectionExecutionDef::SetCachedSize(int size) const {
  _cached_size_.Set(size);
}
const CriticalSectionExecutionDef& CriticalSectionExecutionDef::default_instance() {
  ::PROTOBUF_NAMESPACE_ID::internal::InitSCC(&::scc_info_CriticalSectionExecutionDef_tensorflow_2fcore_2fprotobuf_2fcritical_5fsection_2eproto.base);
  return *internal_default_instance();
}


void CriticalSectionExecutionDef::Clear() {
// @@protoc_insertion_point(message_clear_start:tensorflow.CriticalSectionExecutionDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  execute_in_critical_section_name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArenaNoVirtual());
  exclusive_resource_access_ = false;
  _internal_metadata_.Clear();
}

#if GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
const char* CriticalSectionExecutionDef::_InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) {
#define CHK_(x) if (PROTOBUF_PREDICT_FALSE(!(x))) goto failure
  ::PROTOBUF_NAMESPACE_ID::Arena* arena = GetArenaNoVirtual(); (void)arena;
  while (!ctx->Done(&ptr)) {
    ::PROTOBUF_NAMESPACE_ID::uint32 tag;
    ptr = ::PROTOBUF_NAMESPACE_ID::internal::ReadTag(ptr, &tag);
    CHK_(ptr);
    switch (tag >> 3) {
      // string execute_in_critical_section_name = 1;
      case 1:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 10)) {
          ptr = ::PROTOBUF_NAMESPACE_ID::internal::InlineGreedyStringParserUTF8(mutable_execute_in_critical_section_name(), ptr, ctx, "tensorflow.CriticalSectionExecutionDef.execute_in_critical_section_name");
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      // bool exclusive_resource_access = 2;
      case 2:
        if (PROTOBUF_PREDICT_TRUE(static_cast<::PROTOBUF_NAMESPACE_ID::uint8>(tag) == 16)) {
          exclusive_resource_access_ = ::PROTOBUF_NAMESPACE_ID::internal::ReadVarint(&ptr);
          CHK_(ptr);
        } else goto handle_unusual;
        continue;
      default: {
      handle_unusual:
        if ((tag & 7) == 4 || tag == 0) {
          ctx->SetLastTag(tag);
          goto success;
        }
        ptr = UnknownFieldParse(tag, &_internal_metadata_, ptr, ctx);
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
#else  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER
bool CriticalSectionExecutionDef::MergePartialFromCodedStream(
    ::PROTOBUF_NAMESPACE_ID::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!PROTOBUF_PREDICT_TRUE(EXPRESSION)) goto failure
  ::PROTOBUF_NAMESPACE_ID::uint32 tag;
  // @@protoc_insertion_point(parse_start:tensorflow.CriticalSectionExecutionDef)
  for (;;) {
    ::std::pair<::PROTOBUF_NAMESPACE_ID::uint32, bool> p = input->ReadTagWithCutoffNoLastTag(127u);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // string execute_in_critical_section_name = 1;
      case 1: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (10 & 0xFF)) {
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadString(
                input, this->mutable_execute_in_critical_section_name()));
          DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
            this->execute_in_critical_section_name().data(), static_cast<int>(this->execute_in_critical_section_name().length()),
            ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::PARSE,
            "tensorflow.CriticalSectionExecutionDef.execute_in_critical_section_name"));
        } else {
          goto handle_unusual;
        }
        break;
      }

      // bool exclusive_resource_access = 2;
      case 2: {
        if (static_cast< ::PROTOBUF_NAMESPACE_ID::uint8>(tag) == (16 & 0xFF)) {

          DO_((::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::ReadPrimitive<
                   bool, ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::TYPE_BOOL>(
                 input, &exclusive_resource_access_)));
        } else {
          goto handle_unusual;
        }
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0) {
          goto success;
        }
        DO_(::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SkipField(
              input, tag, _internal_metadata_.mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:tensorflow.CriticalSectionExecutionDef)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:tensorflow.CriticalSectionExecutionDef)
  return false;
#undef DO_
}
#endif  // GOOGLE_PROTOBUF_ENABLE_EXPERIMENTAL_PARSER

void CriticalSectionExecutionDef::SerializeWithCachedSizes(
    ::PROTOBUF_NAMESPACE_ID::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:tensorflow.CriticalSectionExecutionDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string execute_in_critical_section_name = 1;
  if (this->execute_in_critical_section_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->execute_in_critical_section_name().data(), static_cast<int>(this->execute_in_critical_section_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.CriticalSectionExecutionDef.execute_in_critical_section_name");
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->execute_in_critical_section_name(), output);
  }

  // bool exclusive_resource_access = 2;
  if (this->exclusive_resource_access() != 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBool(2, this->exclusive_resource_access(), output);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFields(
        _internal_metadata_.unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:tensorflow.CriticalSectionExecutionDef)
}

::PROTOBUF_NAMESPACE_ID::uint8* CriticalSectionExecutionDef::InternalSerializeWithCachedSizesToArray(
    ::PROTOBUF_NAMESPACE_ID::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:tensorflow.CriticalSectionExecutionDef)
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  // string execute_in_critical_section_name = 1;
  if (this->execute_in_critical_section_name().size() > 0) {
    ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::VerifyUtf8String(
      this->execute_in_critical_section_name().data(), static_cast<int>(this->execute_in_critical_section_name().length()),
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::SERIALIZE,
      "tensorflow.CriticalSectionExecutionDef.execute_in_critical_section_name");
    target =
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteStringToArray(
        1, this->execute_in_critical_section_name(), target);
  }

  // bool exclusive_resource_access = 2;
  if (this->exclusive_resource_access() != 0) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::WriteBoolToArray(2, this->exclusive_resource_access(), target);
  }

  if (_internal_metadata_.have_unknown_fields()) {
    target = ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::SerializeUnknownFieldsToArray(
        _internal_metadata_.unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:tensorflow.CriticalSectionExecutionDef)
  return target;
}

size_t CriticalSectionExecutionDef::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:tensorflow.CriticalSectionExecutionDef)
  size_t total_size = 0;

  if (_internal_metadata_.have_unknown_fields()) {
    total_size +=
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormat::ComputeUnknownFieldsSize(
        _internal_metadata_.unknown_fields());
  }
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  // Prevent compiler warnings about cached_has_bits being unused
  (void) cached_has_bits;

  // string execute_in_critical_section_name = 1;
  if (this->execute_in_critical_section_name().size() > 0) {
    total_size += 1 +
      ::PROTOBUF_NAMESPACE_ID::internal::WireFormatLite::StringSize(
        this->execute_in_critical_section_name());
  }

  // bool exclusive_resource_access = 2;
  if (this->exclusive_resource_access() != 0) {
    total_size += 1 + 1;
  }

  int cached_size = ::PROTOBUF_NAMESPACE_ID::internal::ToCachedSize(total_size);
  SetCachedSize(cached_size);
  return total_size;
}

void CriticalSectionExecutionDef::MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:tensorflow.CriticalSectionExecutionDef)
  GOOGLE_DCHECK_NE(&from, this);
  const CriticalSectionExecutionDef* source =
      ::PROTOBUF_NAMESPACE_ID::DynamicCastToGenerated<CriticalSectionExecutionDef>(
          &from);
  if (source == nullptr) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:tensorflow.CriticalSectionExecutionDef)
    ::PROTOBUF_NAMESPACE_ID::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:tensorflow.CriticalSectionExecutionDef)
    MergeFrom(*source);
  }
}

void CriticalSectionExecutionDef::MergeFrom(const CriticalSectionExecutionDef& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:tensorflow.CriticalSectionExecutionDef)
  GOOGLE_DCHECK_NE(&from, this);
  _internal_metadata_.MergeFrom(from._internal_metadata_);
  ::PROTOBUF_NAMESPACE_ID::uint32 cached_has_bits = 0;
  (void) cached_has_bits;

  if (from.execute_in_critical_section_name().size() > 0) {
    set_execute_in_critical_section_name(from.execute_in_critical_section_name());
  }
  if (from.exclusive_resource_access() != 0) {
    set_exclusive_resource_access(from.exclusive_resource_access());
  }
}

void CriticalSectionExecutionDef::CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:tensorflow.CriticalSectionExecutionDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CriticalSectionExecutionDef::CopyFrom(const CriticalSectionExecutionDef& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:tensorflow.CriticalSectionExecutionDef)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CriticalSectionExecutionDef::IsInitialized() const {
  return true;
}

void CriticalSectionExecutionDef::Swap(CriticalSectionExecutionDef* other) {
  if (other == this) return;
  if (GetArenaNoVirtual() == other->GetArenaNoVirtual()) {
    InternalSwap(other);
  } else {
    CriticalSectionExecutionDef* temp = New(GetArenaNoVirtual());
    temp->MergeFrom(*other);
    other->CopyFrom(*this);
    InternalSwap(temp);
    if (GetArenaNoVirtual() == nullptr) {
      delete temp;
    }
  }
}
void CriticalSectionExecutionDef::UnsafeArenaSwap(CriticalSectionExecutionDef* other) {
  if (other == this) return;
  GOOGLE_DCHECK(GetArenaNoVirtual() == other->GetArenaNoVirtual());
  InternalSwap(other);
}
void CriticalSectionExecutionDef::InternalSwap(CriticalSectionExecutionDef* other) {
  using std::swap;
  _internal_metadata_.Swap(&other->_internal_metadata_);
  execute_in_critical_section_name_.Swap(&other->execute_in_critical_section_name_, &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
    GetArenaNoVirtual());
  swap(exclusive_resource_access_, other->exclusive_resource_access_);
}

::PROTOBUF_NAMESPACE_ID::Metadata CriticalSectionExecutionDef::GetMetadata() const {
  return GetMetadataStatic();
}


// @@protoc_insertion_point(namespace_scope)
}  // namespace tensorflow
PROTOBUF_NAMESPACE_OPEN
template<> PROTOBUF_NOINLINE ::tensorflow::CriticalSectionDef* Arena::CreateMaybeMessage< ::tensorflow::CriticalSectionDef >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::CriticalSectionDef >(arena);
}
template<> PROTOBUF_NOINLINE ::tensorflow::CriticalSectionExecutionDef* Arena::CreateMaybeMessage< ::tensorflow::CriticalSectionExecutionDef >(Arena* arena) {
  return Arena::CreateMessageInternal< ::tensorflow::CriticalSectionExecutionDef >(arena);
}
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>