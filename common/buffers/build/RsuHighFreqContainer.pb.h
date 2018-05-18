// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: RsuHighFreqContainer.proto

#ifndef PROTOBUF_RsuHighFreqContainer_2eproto__INCLUDED
#define PROTOBUF_RsuHighFreqContainer_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006001 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
#include "ProtectedCommunicationZone.pb.h"
// @@protoc_insertion_point(includes)

namespace its {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_RsuHighFreqContainer_2eproto();
void protobuf_AssignDesc_RsuHighFreqContainer_2eproto();
void protobuf_ShutdownFile_RsuHighFreqContainer_2eproto();

class RsuHighFreqContainer;

// ===================================================================

class RsuHighFreqContainer : public ::google::protobuf::Message {
 public:
  RsuHighFreqContainer();
  virtual ~RsuHighFreqContainer();

  RsuHighFreqContainer(const RsuHighFreqContainer& from);

  inline RsuHighFreqContainer& operator=(const RsuHighFreqContainer& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const RsuHighFreqContainer& default_instance();

  void Swap(RsuHighFreqContainer* other);

  // implements Message ----------------------------------------------

  RsuHighFreqContainer* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const RsuHighFreqContainer& from);
  void MergeFrom(const RsuHighFreqContainer& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // repeated .its.ProtectedCommunicationZone protectedCommZone = 1;
  inline int protectedcommzone_size() const;
  inline void clear_protectedcommzone();
  static const int kProtectedCommZoneFieldNumber = 1;
  inline const ::its::ProtectedCommunicationZone& protectedcommzone(int index) const;
  inline ::its::ProtectedCommunicationZone* mutable_protectedcommzone(int index);
  inline ::its::ProtectedCommunicationZone* add_protectedcommzone();
  inline const ::google::protobuf::RepeatedPtrField< ::its::ProtectedCommunicationZone >&
      protectedcommzone() const;
  inline ::google::protobuf::RepeatedPtrField< ::its::ProtectedCommunicationZone >*
      mutable_protectedcommzone();

  // @@protoc_insertion_point(class_scope:its.RsuHighFreqContainer)
 private:

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::its::ProtectedCommunicationZone > protectedcommzone_;
  friend void  protobuf_AddDesc_RsuHighFreqContainer_2eproto();
  friend void protobuf_AssignDesc_RsuHighFreqContainer_2eproto();
  friend void protobuf_ShutdownFile_RsuHighFreqContainer_2eproto();

  void InitAsDefaultInstance();
  static RsuHighFreqContainer* default_instance_;
};
// ===================================================================


// ===================================================================

// RsuHighFreqContainer

// repeated .its.ProtectedCommunicationZone protectedCommZone = 1;
inline int RsuHighFreqContainer::protectedcommzone_size() const {
  return protectedcommzone_.size();
}
inline void RsuHighFreqContainer::clear_protectedcommzone() {
  protectedcommzone_.Clear();
}
inline const ::its::ProtectedCommunicationZone& RsuHighFreqContainer::protectedcommzone(int index) const {
  // @@protoc_insertion_point(field_get:its.RsuHighFreqContainer.protectedCommZone)
  return protectedcommzone_.Get(index);
}
inline ::its::ProtectedCommunicationZone* RsuHighFreqContainer::mutable_protectedcommzone(int index) {
  // @@protoc_insertion_point(field_mutable:its.RsuHighFreqContainer.protectedCommZone)
  return protectedcommzone_.Mutable(index);
}
inline ::its::ProtectedCommunicationZone* RsuHighFreqContainer::add_protectedcommzone() {
  // @@protoc_insertion_point(field_add:its.RsuHighFreqContainer.protectedCommZone)
  return protectedcommzone_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::its::ProtectedCommunicationZone >&
RsuHighFreqContainer::protectedcommzone() const {
  // @@protoc_insertion_point(field_list:its.RsuHighFreqContainer.protectedCommZone)
  return protectedcommzone_;
}
inline ::google::protobuf::RepeatedPtrField< ::its::ProtectedCommunicationZone >*
RsuHighFreqContainer::mutable_protectedcommzone() {
  // @@protoc_insertion_point(field_mutable_list:its.RsuHighFreqContainer.protectedCommZone)
  return &protectedcommzone_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace its

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_RsuHighFreqContainer_2eproto__INCLUDED
