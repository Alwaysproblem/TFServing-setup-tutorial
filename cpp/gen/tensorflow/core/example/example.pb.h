// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: tensorflow/core/example/example.proto

#ifndef PROTOBUF_tensorflow_2fcore_2fexample_2fexample_2eproto__INCLUDED
#define PROTOBUF_tensorflow_2fcore_2fexample_2fexample_2eproto__INCLUDED

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
#include "tensorflow/core/example/feature.pb.h"
// @@protoc_insertion_point(includes)

namespace tensorflow {

// Internal implementation detail -- do not call these.
void protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
void protobuf_AssignDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
void protobuf_ShutdownFile_tensorflow_2fcore_2fexample_2fexample_2eproto();

class Example;
class SequenceExample;

// ===================================================================

class Example : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.Example) */ {
 public:
  Example();
  virtual ~Example();

  Example(const Example& from);

  inline Example& operator=(const Example& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const { return GetArenaNoVirtual(); }
  inline void* GetMaybeArenaPointer() const {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const Example& default_instance();

  void UnsafeArenaSwap(Example* other);
  void Swap(Example* other);

  // implements Message ----------------------------------------------

  inline Example* New() const { return New(NULL); }

  Example* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Example& from);
  void MergeFrom(const Example& from);
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
  void InternalSwap(Example* other);
  protected:
  explicit Example(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
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

  // optional .tensorflow.Features features = 1;
  bool has_features() const;
  void clear_features();
  static const int kFeaturesFieldNumber = 1;
  private:
  void _slow_mutable_features();
  void _slow_set_allocated_features(
      ::google::protobuf::Arena* message_arena, ::tensorflow::Features** features);
  ::tensorflow::Features* _slow_release_features();
  public:
  const ::tensorflow::Features& features() const;
  ::tensorflow::Features* mutable_features();
  ::tensorflow::Features* release_features();
  void set_allocated_features(::tensorflow::Features* features);
  ::tensorflow::Features* unsafe_arena_release_features();
  void unsafe_arena_set_allocated_features(
      ::tensorflow::Features* features);

  // @@protoc_insertion_point(class_scope:tensorflow.Example)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool _is_default_instance_;
  ::tensorflow::Features* features_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2fcore_2fexample_2fexample_2eproto();

  void InitAsDefaultInstance();
  static Example* default_instance_;
};
// -------------------------------------------------------------------

class SequenceExample : public ::google::protobuf::Message /* @@protoc_insertion_point(class_definition:tensorflow.SequenceExample) */ {
 public:
  SequenceExample();
  virtual ~SequenceExample();

  SequenceExample(const SequenceExample& from);

  inline SequenceExample& operator=(const SequenceExample& from) {
    CopyFrom(from);
    return *this;
  }

  inline ::google::protobuf::Arena* GetArena() const { return GetArenaNoVirtual(); }
  inline void* GetMaybeArenaPointer() const {
    return MaybeArenaPtr();
  }
  static const ::google::protobuf::Descriptor* descriptor();
  static const SequenceExample& default_instance();

  void UnsafeArenaSwap(SequenceExample* other);
  void Swap(SequenceExample* other);

  // implements Message ----------------------------------------------

  inline SequenceExample* New() const { return New(NULL); }

  SequenceExample* New(::google::protobuf::Arena* arena) const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const SequenceExample& from);
  void MergeFrom(const SequenceExample& from);
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
  void InternalSwap(SequenceExample* other);
  protected:
  explicit SequenceExample(::google::protobuf::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::google::protobuf::Arena* arena);
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

  // optional .tensorflow.Features context = 1;
  bool has_context() const;
  void clear_context();
  static const int kContextFieldNumber = 1;
  private:
  void _slow_mutable_context();
  void _slow_set_allocated_context(
      ::google::protobuf::Arena* message_arena, ::tensorflow::Features** context);
  ::tensorflow::Features* _slow_release_context();
  public:
  const ::tensorflow::Features& context() const;
  ::tensorflow::Features* mutable_context();
  ::tensorflow::Features* release_context();
  void set_allocated_context(::tensorflow::Features* context);
  ::tensorflow::Features* unsafe_arena_release_context();
  void unsafe_arena_set_allocated_context(
      ::tensorflow::Features* context);

  // optional .tensorflow.FeatureLists feature_lists = 2;
  bool has_feature_lists() const;
  void clear_feature_lists();
  static const int kFeatureListsFieldNumber = 2;
  private:
  void _slow_mutable_feature_lists();
  void _slow_set_allocated_feature_lists(
      ::google::protobuf::Arena* message_arena, ::tensorflow::FeatureLists** feature_lists);
  ::tensorflow::FeatureLists* _slow_release_feature_lists();
  public:
  const ::tensorflow::FeatureLists& feature_lists() const;
  ::tensorflow::FeatureLists* mutable_feature_lists();
  ::tensorflow::FeatureLists* release_feature_lists();
  void set_allocated_feature_lists(::tensorflow::FeatureLists* feature_lists);
  ::tensorflow::FeatureLists* unsafe_arena_release_feature_lists();
  void unsafe_arena_set_allocated_feature_lists(
      ::tensorflow::FeatureLists* feature_lists);

  // @@protoc_insertion_point(class_scope:tensorflow.SequenceExample)
 private:

  ::google::protobuf::internal::InternalMetadataWithArena _internal_metadata_;
  friend class ::google::protobuf::Arena;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  bool _is_default_instance_;
  ::tensorflow::Features* context_;
  ::tensorflow::FeatureLists* feature_lists_;
  mutable int _cached_size_;
  friend void  protobuf_AddDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  friend void protobuf_AssignDesc_tensorflow_2fcore_2fexample_2fexample_2eproto();
  friend void protobuf_ShutdownFile_tensorflow_2fcore_2fexample_2fexample_2eproto();

  void InitAsDefaultInstance();
  static SequenceExample* default_instance_;
};
// ===================================================================


// ===================================================================

#if !PROTOBUF_INLINE_NOT_IN_HEADERS
// Example

// optional .tensorflow.Features features = 1;
inline bool Example::has_features() const {
  return !_is_default_instance_ && features_ != NULL;
}
inline void Example::clear_features() {
  if (GetArenaNoVirtual() == NULL && features_ != NULL) delete features_;
  features_ = NULL;
}
inline const ::tensorflow::Features& Example::features() const {
  // @@protoc_insertion_point(field_get:tensorflow.Example.features)
  return features_ != NULL ? *features_ : *default_instance_->features_;
}
inline ::tensorflow::Features* Example::mutable_features() {
  
  if (features_ == NULL) {
    _slow_mutable_features();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.Example.features)
  return features_;
}
inline ::tensorflow::Features* Example::release_features() {
  // @@protoc_insertion_point(field_release:tensorflow.Example.features)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_features();
  } else {
    ::tensorflow::Features* temp = features_;
    features_ = NULL;
    return temp;
  }
}
inline  void Example::set_allocated_features(::tensorflow::Features* features) {
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

// -------------------------------------------------------------------

// SequenceExample

// optional .tensorflow.Features context = 1;
inline bool SequenceExample::has_context() const {
  return !_is_default_instance_ && context_ != NULL;
}
inline void SequenceExample::clear_context() {
  if (GetArenaNoVirtual() == NULL && context_ != NULL) delete context_;
  context_ = NULL;
}
inline const ::tensorflow::Features& SequenceExample::context() const {
  // @@protoc_insertion_point(field_get:tensorflow.SequenceExample.context)
  return context_ != NULL ? *context_ : *default_instance_->context_;
}
inline ::tensorflow::Features* SequenceExample::mutable_context() {
  
  if (context_ == NULL) {
    _slow_mutable_context();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.SequenceExample.context)
  return context_;
}
inline ::tensorflow::Features* SequenceExample::release_context() {
  // @@protoc_insertion_point(field_release:tensorflow.SequenceExample.context)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_context();
  } else {
    ::tensorflow::Features* temp = context_;
    context_ = NULL;
    return temp;
  }
}
inline  void SequenceExample::set_allocated_context(::tensorflow::Features* context) {
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
inline bool SequenceExample::has_feature_lists() const {
  return !_is_default_instance_ && feature_lists_ != NULL;
}
inline void SequenceExample::clear_feature_lists() {
  if (GetArenaNoVirtual() == NULL && feature_lists_ != NULL) delete feature_lists_;
  feature_lists_ = NULL;
}
inline const ::tensorflow::FeatureLists& SequenceExample::feature_lists() const {
  // @@protoc_insertion_point(field_get:tensorflow.SequenceExample.feature_lists)
  return feature_lists_ != NULL ? *feature_lists_ : *default_instance_->feature_lists_;
}
inline ::tensorflow::FeatureLists* SequenceExample::mutable_feature_lists() {
  
  if (feature_lists_ == NULL) {
    _slow_mutable_feature_lists();
  }
  // @@protoc_insertion_point(field_mutable:tensorflow.SequenceExample.feature_lists)
  return feature_lists_;
}
inline ::tensorflow::FeatureLists* SequenceExample::release_feature_lists() {
  // @@protoc_insertion_point(field_release:tensorflow.SequenceExample.feature_lists)
  
  if (GetArenaNoVirtual() != NULL) {
    return _slow_release_feature_lists();
  } else {
    ::tensorflow::FeatureLists* temp = feature_lists_;
    feature_lists_ = NULL;
    return temp;
  }
}
inline  void SequenceExample::set_allocated_feature_lists(::tensorflow::FeatureLists* feature_lists) {
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

#endif  // !PROTOBUF_INLINE_NOT_IN_HEADERS
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace tensorflow

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_tensorflow_2fcore_2fexample_2fexample_2eproto__INCLUDED
