// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cam.proto

#ifndef PROTOBUF_cam_2eproto__INCLUDED
#define PROTOBUF_cam_2eproto__INCLUDED

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
#include "ItsPduHeader.pb.h"
#include "CoopAwareness.pb.h"
// @@protoc_insertion_point(includes)

namespace camPackage {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_cam_2eproto();
void protobuf_AssignDesc_cam_2eproto();
void protobuf_ShutdownFile_cam_2eproto();

class CAM;

// ===================================================================

class CAM : public ::google::protobuf::Message {
 public:
  CAM();
  virtual ~CAM();

  CAM(const CAM& from);

  inline CAM& operator=(const CAM& from) {
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
  static const CAM& default_instance();

  void Swap(CAM* other);

  // implements Message ----------------------------------------------

  CAM* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const CAM& from);
  void MergeFrom(const CAM& from);
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

  // required .its.ItsPduHeader header = 1;
  inline bool has_header() const;
  inline void clear_header();
  static const int kHeaderFieldNumber = 1;
  inline const ::its::ItsPduHeader& header() const;
  inline ::its::ItsPduHeader* mutable_header();
  inline ::its::ItsPduHeader* release_header();
  inline void set_allocated_header(::its::ItsPduHeader* header);

  // required .its.CoopAwareness coop = 2;
  inline bool has_coop() const;
  inline void clear_coop();
  static const int kCoopFieldNumber = 2;
  inline const ::its::CoopAwareness& coop() const;
  inline ::its::CoopAwareness* mutable_coop();
  inline ::its::CoopAwareness* release_coop();
  inline void set_allocated_coop(::its::CoopAwareness* coop);

  // @@protoc_insertion_point(class_scope:camPackage.CAM)
 private:
  inline void set_has_header();
  inline void clear_has_header();
  inline void set_has_coop();
  inline void clear_has_coop();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::its::ItsPduHeader* header_;
  ::its::CoopAwareness* coop_;
  friend void  protobuf_AddDesc_cam_2eproto();
  friend void protobuf_AssignDesc_cam_2eproto();
  friend void protobuf_ShutdownFile_cam_2eproto();

  void InitAsDefaultInstance();
  static CAM* default_instance_;
};
// ===================================================================


// ===================================================================

// CAM

// required .its.ItsPduHeader header = 1;
inline bool CAM::has_header() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void CAM::set_has_header() {
  _has_bits_[0] |= 0x00000001u;
}
inline void CAM::clear_has_header() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void CAM::clear_header() {
  if (header_ != NULL) header_->::its::ItsPduHeader::Clear();
  clear_has_header();
}
inline const ::its::ItsPduHeader& CAM::header() const {
  // @@protoc_insertion_point(field_get:camPackage.CAM.header)
  return header_ != NULL ? *header_ : *default_instance_->header_;
}
inline ::its::ItsPduHeader* CAM::mutable_header() {
  set_has_header();
  if (header_ == NULL) header_ = new ::its::ItsPduHeader;
  // @@protoc_insertion_point(field_mutable:camPackage.CAM.header)
  return header_;
}
inline ::its::ItsPduHeader* CAM::release_header() {
  clear_has_header();
  ::its::ItsPduHeader* temp = header_;
  header_ = NULL;
  return temp;
}
inline void CAM::set_allocated_header(::its::ItsPduHeader* header) {
  delete header_;
  header_ = header;
  if (header) {
    set_has_header();
  } else {
    clear_has_header();
  }
  // @@protoc_insertion_point(field_set_allocated:camPackage.CAM.header)
}

// required .its.CoopAwareness coop = 2;
inline bool CAM::has_coop() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void CAM::set_has_coop() {
  _has_bits_[0] |= 0x00000002u;
}
inline void CAM::clear_has_coop() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void CAM::clear_coop() {
  if (coop_ != NULL) coop_->::its::CoopAwareness::Clear();
  clear_has_coop();
}
inline const ::its::CoopAwareness& CAM::coop() const {
  // @@protoc_insertion_point(field_get:camPackage.CAM.coop)
  return coop_ != NULL ? *coop_ : *default_instance_->coop_;
}
inline ::its::CoopAwareness* CAM::mutable_coop() {
  set_has_coop();
  if (coop_ == NULL) coop_ = new ::its::CoopAwareness;
  // @@protoc_insertion_point(field_mutable:camPackage.CAM.coop)
  return coop_;
}
inline ::its::CoopAwareness* CAM::release_coop() {
  clear_has_coop();
  ::its::CoopAwareness* temp = coop_;
  coop_ = NULL;
  return temp;
}
inline void CAM::set_allocated_coop(::its::CoopAwareness* coop) {
  delete coop_;
  coop_ = coop;
  if (coop) {
    set_has_coop();
  } else {
    clear_has_coop();
  }
  // @@protoc_insertion_point(field_set_allocated:camPackage.CAM.coop)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace camPackage

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_cam_2eproto__INCLUDED