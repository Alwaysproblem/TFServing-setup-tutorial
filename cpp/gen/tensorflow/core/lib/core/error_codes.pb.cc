// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/lib/core/error_codes.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "tensorflow/core/lib/core/error_codes.pb.h"

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

namespace {


}  // namespace


void protobuf_AssignDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto() {
  protobuf_AddDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "tensorflow/core/lib/core/error_codes.proto");
  GOOGLE_CHECK(file != NULL);
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
}

}  // namespace

void protobuf_ShutdownFile_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto() {
}

void protobuf_AddDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AddDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::tensorflow::error::protobuf_AddDesc_tensorflow_2fcore_2fprotobuf_2ferror_5fcodes_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n*tensorflow/core/lib/core/error_codes.p"
    "roto\032*tensorflow/core/protobuf/error_cod"
    "es.protoP\000b\006proto3", 98);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "tensorflow/core/lib/core/error_codes.proto", &protobuf_RegisterTypes);
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto {
  StaticDescriptorInitializer_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto() {
    protobuf_AddDesc_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto();
  }
} static_descriptor_initializer_tensorflow_2fcore_2flib_2fcore_2ferror_5fcodes_2eproto_;

// @@protoc_insertion_point(namespace_scope)

// @@protoc_insertion_point(global_scope)
