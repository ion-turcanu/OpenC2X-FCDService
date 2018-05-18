// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BasicVehicleLowFreqContainer.proto

#ifndef PROTOBUF_BasicVehicleLowFreqContainer_2eproto__INCLUDED
#define PROTOBUF_BasicVehicleLowFreqContainer_2eproto__INCLUDED

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
#include "PathPoint.pb.h"
// @@protoc_insertion_point(includes)

namespace its {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_BasicVehicleLowFreqContainer_2eproto();
void protobuf_AssignDesc_BasicVehicleLowFreqContainer_2eproto();
void protobuf_ShutdownFile_BasicVehicleLowFreqContainer_2eproto();

class BasicVehicleLowFreqContainer;

// ===================================================================

class BasicVehicleLowFreqContainer : public ::google::protobuf::Message {
 public:
  BasicVehicleLowFreqContainer();
  virtual ~BasicVehicleLowFreqContainer();

  BasicVehicleLowFreqContainer(const BasicVehicleLowFreqContainer& from);

  inline BasicVehicleLowFreqContainer& operator=(const BasicVehicleLowFreqContainer& from) {
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
  static const BasicVehicleLowFreqContainer& default_instance();

  void Swap(BasicVehicleLowFreqContainer* other);

  // implements Message ----------------------------------------------

  BasicVehicleLowFreqContainer* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const BasicVehicleLowFreqContainer& from);
  void MergeFrom(const BasicVehicleLowFreqContainer& from);
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

  // required int64 vehicleRole = 1;
  inline bool has_vehiclerole() const;
  inline void clear_vehiclerole();
  static const int kVehicleRoleFieldNumber = 1;
  inline ::google::protobuf::int64 vehiclerole() const;
  inline void set_vehiclerole(::google::protobuf::int64 value);

  // required int64 exteriorLights = 2;
  inline bool has_exteriorlights() const;
  inline void clear_exteriorlights();
  static const int kExteriorLightsFieldNumber = 2;
  inline ::google::protobuf::int64 exteriorlights() const;
  inline void set_exteriorlights(::google::protobuf::int64 value);

  // repeated .its.PathPoint pathPoint = 3;
  inline int pathpoint_size() const;
  inline void clear_pathpoint();
  static const int kPathPointFieldNumber = 3;
  inline const ::its::PathPoint& pathpoint(int index) const;
  inline ::its::PathPoint* mutable_pathpoint(int index);
  inline ::its::PathPoint* add_pathpoint();
  inline const ::google::protobuf::RepeatedPtrField< ::its::PathPoint >&
      pathpoint() const;
  inline ::google::protobuf::RepeatedPtrField< ::its::PathPoint >*
      mutable_pathpoint();

  // @@protoc_insertion_point(class_scope:its.BasicVehicleLowFreqContainer)
 private:
  inline void set_has_vehiclerole();
  inline void clear_has_vehiclerole();
  inline void set_has_exteriorlights();
  inline void clear_has_exteriorlights();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int64 vehiclerole_;
  ::google::protobuf::int64 exteriorlights_;
  ::google::protobuf::RepeatedPtrField< ::its::PathPoint > pathpoint_;
  friend void  protobuf_AddDesc_BasicVehicleLowFreqContainer_2eproto();
  friend void protobuf_AssignDesc_BasicVehicleLowFreqContainer_2eproto();
  friend void protobuf_ShutdownFile_BasicVehicleLowFreqContainer_2eproto();

  void InitAsDefaultInstance();
  static BasicVehicleLowFreqContainer* default_instance_;
};
// ===================================================================


// ===================================================================

// BasicVehicleLowFreqContainer

// required int64 vehicleRole = 1;
inline bool BasicVehicleLowFreqContainer::has_vehiclerole() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void BasicVehicleLowFreqContainer::set_has_vehiclerole() {
  _has_bits_[0] |= 0x00000001u;
}
inline void BasicVehicleLowFreqContainer::clear_has_vehiclerole() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void BasicVehicleLowFreqContainer::clear_vehiclerole() {
  vehiclerole_ = GOOGLE_LONGLONG(0);
  clear_has_vehiclerole();
}
inline ::google::protobuf::int64 BasicVehicleLowFreqContainer::vehiclerole() const {
  // @@protoc_insertion_point(field_get:its.BasicVehicleLowFreqContainer.vehicleRole)
  return vehiclerole_;
}
inline void BasicVehicleLowFreqContainer::set_vehiclerole(::google::protobuf::int64 value) {
  set_has_vehiclerole();
  vehiclerole_ = value;
  // @@protoc_insertion_point(field_set:its.BasicVehicleLowFreqContainer.vehicleRole)
}

// required int64 exteriorLights = 2;
inline bool BasicVehicleLowFreqContainer::has_exteriorlights() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void BasicVehicleLowFreqContainer::set_has_exteriorlights() {
  _has_bits_[0] |= 0x00000002u;
}
inline void BasicVehicleLowFreqContainer::clear_has_exteriorlights() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void BasicVehicleLowFreqContainer::clear_exteriorlights() {
  exteriorlights_ = GOOGLE_LONGLONG(0);
  clear_has_exteriorlights();
}
inline ::google::protobuf::int64 BasicVehicleLowFreqContainer::exteriorlights() const {
  // @@protoc_insertion_point(field_get:its.BasicVehicleLowFreqContainer.exteriorLights)
  return exteriorlights_;
}
inline void BasicVehicleLowFreqContainer::set_exteriorlights(::google::protobuf::int64 value) {
  set_has_exteriorlights();
  exteriorlights_ = value;
  // @@protoc_insertion_point(field_set:its.BasicVehicleLowFreqContainer.exteriorLights)
}

// repeated .its.PathPoint pathPoint = 3;
inline int BasicVehicleLowFreqContainer::pathpoint_size() const {
  return pathpoint_.size();
}
inline void BasicVehicleLowFreqContainer::clear_pathpoint() {
  pathpoint_.Clear();
}
inline const ::its::PathPoint& BasicVehicleLowFreqContainer::pathpoint(int index) const {
  // @@protoc_insertion_point(field_get:its.BasicVehicleLowFreqContainer.pathPoint)
  return pathpoint_.Get(index);
}
inline ::its::PathPoint* BasicVehicleLowFreqContainer::mutable_pathpoint(int index) {
  // @@protoc_insertion_point(field_mutable:its.BasicVehicleLowFreqContainer.pathPoint)
  return pathpoint_.Mutable(index);
}
inline ::its::PathPoint* BasicVehicleLowFreqContainer::add_pathpoint() {
  // @@protoc_insertion_point(field_add:its.BasicVehicleLowFreqContainer.pathPoint)
  return pathpoint_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::its::PathPoint >&
BasicVehicleLowFreqContainer::pathpoint() const {
  // @@protoc_insertion_point(field_list:its.BasicVehicleLowFreqContainer.pathPoint)
  return pathpoint_;
}
inline ::google::protobuf::RepeatedPtrField< ::its::PathPoint >*
BasicVehicleLowFreqContainer::mutable_pathpoint() {
  // @@protoc_insertion_point(field_mutable_list:its.BasicVehicleLowFreqContainer.pathPoint)
  return &pathpoint_;
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

#endif  // PROTOBUF_BasicVehicleLowFreqContainer_2eproto__INCLUDED
