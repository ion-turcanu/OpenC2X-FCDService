// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: cam.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "cam.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace camPackage {

namespace {

const ::google::protobuf::Descriptor* CAM_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  CAM_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_cam_2eproto() {
  protobuf_AddDesc_cam_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "cam.proto");
  GOOGLE_CHECK(file != NULL);
  CAM_descriptor_ = file->message_type(0);
  static const int CAM_offsets_[2] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAM, header_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAM, coop_),
  };
  CAM_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      CAM_descriptor_,
      CAM::default_instance_,
      CAM_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAM, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(CAM, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(CAM));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_cam_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    CAM_descriptor_, &CAM::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_cam_2eproto() {
  delete CAM::default_instance_;
  delete CAM_reflection_;
}

void protobuf_AddDesc_cam_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::its::protobuf_AddDesc_ItsPduHeader_2eproto();
  ::its::protobuf_AddDesc_CoopAwareness_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\tcam.proto\022\ncamPackage\032\022ItsPduHeader.pr"
    "oto\032\023CoopAwareness.proto\"J\n\003CAM\022!\n\006heade"
    "r\030\001 \002(\0132\021.its.ItsPduHeader\022 \n\004coop\030\002 \002(\013"
    "2\022.its.CoopAwareness", 140);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "cam.proto", &protobuf_RegisterTypes);
  CAM::default_instance_ = new CAM();
  CAM::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_cam_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_cam_2eproto {
  StaticDescriptorInitializer_cam_2eproto() {
    protobuf_AddDesc_cam_2eproto();
  }
} static_descriptor_initializer_cam_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int CAM::kHeaderFieldNumber;
const int CAM::kCoopFieldNumber;
#endif  // !_MSC_VER

CAM::CAM()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:camPackage.CAM)
}

void CAM::InitAsDefaultInstance() {
  header_ = const_cast< ::its::ItsPduHeader*>(&::its::ItsPduHeader::default_instance());
  coop_ = const_cast< ::its::CoopAwareness*>(&::its::CoopAwareness::default_instance());
}

CAM::CAM(const CAM& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:camPackage.CAM)
}

void CAM::SharedCtor() {
  _cached_size_ = 0;
  header_ = NULL;
  coop_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

CAM::~CAM() {
  // @@protoc_insertion_point(destructor:camPackage.CAM)
  SharedDtor();
}

void CAM::SharedDtor() {
  if (this != default_instance_) {
    delete header_;
    delete coop_;
  }
}

void CAM::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* CAM::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return CAM_descriptor_;
}

const CAM& CAM::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_cam_2eproto();
  return *default_instance_;
}

CAM* CAM::default_instance_ = NULL;

CAM* CAM::New() const {
  return new CAM;
}

void CAM::Clear() {
  if (_has_bits_[0 / 32] & 3) {
    if (has_header()) {
      if (header_ != NULL) header_->::its::ItsPduHeader::Clear();
    }
    if (has_coop()) {
      if (coop_ != NULL) coop_->::its::CoopAwareness::Clear();
    }
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool CAM::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:camPackage.CAM)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .its.ItsPduHeader header = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_header()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(18)) goto parse_coop;
        break;
      }

      // required .its.CoopAwareness coop = 2;
      case 2: {
        if (tag == 18) {
         parse_coop:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_coop()));
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
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:camPackage.CAM)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:camPackage.CAM)
  return false;
#undef DO_
}

void CAM::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:camPackage.CAM)
  // required .its.ItsPduHeader header = 1;
  if (has_header()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->header(), output);
  }

  // required .its.CoopAwareness coop = 2;
  if (has_coop()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      2, this->coop(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:camPackage.CAM)
}

::google::protobuf::uint8* CAM::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:camPackage.CAM)
  // required .its.ItsPduHeader header = 1;
  if (has_header()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->header(), target);
  }

  // required .its.CoopAwareness coop = 2;
  if (has_coop()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        2, this->coop(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:camPackage.CAM)
  return target;
}

int CAM::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .its.ItsPduHeader header = 1;
    if (has_header()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->header());
    }

    // required .its.CoopAwareness coop = 2;
    if (has_coop()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->coop());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void CAM::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const CAM* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const CAM*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void CAM::MergeFrom(const CAM& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_header()) {
      mutable_header()->::its::ItsPduHeader::MergeFrom(from.header());
    }
    if (from.has_coop()) {
      mutable_coop()->::its::CoopAwareness::MergeFrom(from.coop());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void CAM::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void CAM::CopyFrom(const CAM& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool CAM::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000003) != 0x00000003) return false;

  if (has_header()) {
    if (!this->header().IsInitialized()) return false;
  }
  if (has_coop()) {
    if (!this->coop().IsInitialized()) return false;
  }
  return true;
}

void CAM::Swap(CAM* other) {
  if (other != this) {
    std::swap(header_, other->header_);
    std::swap(coop_, other->coop_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata CAM::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = CAM_descriptor_;
  metadata.reflection = CAM_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace camPackage

// @@protoc_insertion_point(global_scope)
