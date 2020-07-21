// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/protobuf/transport_options.proto

#ifndef PROTOBUF_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto__INCLUDED
#define PROTOBUF_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 3000000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 3000000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace tensorflow {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto();
void protobuf_AssignDesc_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto();
void protobuf_ShutdownFile_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto();

class RecvBufRespExtra;

// ===================================================================

class RecvBufRespExtra : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.RecvBufRespExtra) */ {
 public:
  RecvBufRespExtra();
  virtual ~RecvBufRespExtra();

  RecvBufRespExtra(const RecvBufRespExtra& from);

  inline RecvBufRespExtra& operator=(const RecvBufRespExtra& from) {
    CopyFrom(from);
    return *this;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RecvBufRespExtra& default_instance();

  void Swap(RecvBufRespExtra* other);

  // implements Message ----------------------------------------------

  inline RecvBufRespExtra* New() const { return New(NULL); }

  RecvBufRespExtra* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RecvBufRespExtra& from);
  void MergeFrom(const RecvBufRespExtra& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* InternalSerializeWithCachedSizesToArray(
      bool deterministic, ::google::protobuf::uint8* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const {
    return InternalSerializeWithCachedSizesToArray(false, output);
  }
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  void InternalSwap(RecvBufRespExtra* other);
  private:
  inline ::google::protobuf::Arena* GetArenaNoVirtual() const {
    return _internal_metadata_.arena();
  }
  inline void* MaybeArenaPtr() const {
    return _internal_metadata_.raw_arena_ptr();
  }
  public:

  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated bytes tensor_content = 1;
  int tensor_content_size() const;
  void clear_tensor_content();
  static const int kTensorContentFieldNumber = 1;
  const ::std::string& tensor_content(int index) const;
  ::std::string* mutable_tensor_content(int index);
  void set_tensor_content(int index, const ::std::string& value);
  void set_tensor_content(int index, const char* value);
  void set_tensor_content(int index, const void* value, size_t size);
  ::std::string* add_tensor_content();
  void add_tensor_content(const ::std::string& value);
  void add_tensor_content(const char* value);
  void add_tensor_content(const void* value, size_t size);
  const ::google::protobuf::RepeatedPtrField< ::std::string>& tensor_content() const;
  ::google::protobuf::RepeatedPtrField< ::std::string>* mutable_tensor_content();

  // @@protoc_insertion_point(class_scope:tensorflow.RecvBufRespExtra)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  bool _is_default_instance_;
  ::google::protobuf::RepeatedPtrField< ::std::string> tensor_content_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto();

  void InitAsDefaultInstance();
  static RecvBufRespExtra* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// RecvBufRespExtra

// repeated bytes tensor_content = 1;
inline int RecvBufRespExtra::tensor_content_size() const {
  return tensor_content_.size();
}
inline void RecvBufRespExtra::clear_tensor_content() {
  tensor_content_.Clear();
}
inline const ::std::string& RecvBufRespExtra::tensor_content(int index) const {
  // @@protoc_insertion_point(field_get:tensorflow.RecvBufRespExtra.tensor_content)
  return tensor_content_.Get(index);
}
inline ::std::string* RecvBufRespExtra::mutable_tensor_content(int index) {
  // @@protoc_insertion_point(field_mutable:tensorflow.RecvBufRespExtra.tensor_content)
  return tensor_content_.Mutable(index);
}
inline void RecvBufRespExtra::set_tensor_content(int index, const ::std::string& value) {
  // @@protoc_insertion_point(field_set:tensorflow.RecvBufRespExtra.tensor_content)
  tensor_content_.Mutable(index)->assign(value);
}
inline void RecvBufRespExtra::set_tensor_content(int index, const char* value) {
  tensor_content_.Mutable(index)->assign(value);
  // @@protoc_insertion_point(field_set_char:tensorflow.RecvBufRespExtra.tensor_content)
}
inline void RecvBufRespExtra::set_tensor_content(int index, const void* value, size_t size) {
  tensor_content_.Mutable(index)->assign(
    reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:tensorflow.RecvBufRespExtra.tensor_content)
}
inline ::std::string* RecvBufRespExtra::add_tensor_content() {
  // @@protoc_insertion_point(field_add_mutable:tensorflow.RecvBufRespExtra.tensor_content)
  return tensor_content_.Add();
}
inline void RecvBufRespExtra::add_tensor_content(const ::std::string& value) {
  tensor_content_.Add()->assign(value);
  // @@protoc_insertion_point(field_add:tensorflow.RecvBufRespExtra.tensor_content)
}
inline void RecvBufRespExtra::add_tensor_content(const char* value) {
  tensor_content_.Add()->assign(value);
  // @@protoc_insertion_point(field_add_char:tensorflow.RecvBufRespExtra.tensor_content)
}
inline void RecvBufRespExtra::add_tensor_content(const void* value, size_t size) {
  tensor_content_.Add()->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_add_pointer:tensorflow.RecvBufRespExtra.tensor_content)
}
inline const ::google::protobuf::RepeatedPtrField< ::std::string>&
RecvBufRespExtra::tensor_content() const {
  // @@protoc_insertion_point(field_list:tensorflow.RecvBufRespExtra.tensor_content)
  return tensor_content_;
}
inline ::google::protobuf::RepeatedPtrField< ::std::string>*
RecvBufRespExtra::mutable_tensor_content() {
  // @@protoc_insertion_point(field_mutable_list:tensorflow.RecvBufRespExtra.tensor_content)
  return &tensor_content_;
}

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tensorflow_2fcore_2fprotobuf_2ftransport_5foptions_2eproto__INCLUDED
