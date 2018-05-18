// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: DENMessage.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "DENMessage.pb.h"

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

namespace its {

namespace {

const ::google::protobuf::Descriptor* DENMessage_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  DENMessage_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_DENMessage_2eproto() {
  protobuf_AddDesc_DENMessage_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "DENMessage.proto");
  GOOGLE_CHECK(file != NULL);
  DENMessage_descriptor_ = file->message_type(0);
  static const int DENMessage_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DENMessage, managementcontainer_),
  };
  DENMessage_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      DENMessage_descriptor_,
      DENMessage::default_instance_,
      DENMessage_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DENMessage, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(DENMessage, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(DENMessage));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_DENMessage_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    DENMessage_descriptor_, &DENMessage::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_DENMessage_2eproto() {
  delete DENMessage::default_instance_;
  delete DENMessage_reflection_;
}

void protobuf_AddDesc_DENMessage_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::its::protobuf_AddDesc_DENMManagementContainer_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\020DENMessage.proto\022\003its\032\035DENMManagementC"
    "ontainer.proto\"G\n\nDENMessage\0229\n\023manageme"
    "ntContainer\030\001 \002(\0132\034.its.DENMManagementCo"
    "ntainer", 127);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "DENMessage.proto", &protobuf_RegisterTypes);
  DENMessage::default_instance_ = new DENMessage();
  DENMessage::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_DENMessage_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_DENMessage_2eproto {
  StaticDescriptorInitializer_DENMessage_2eproto() {
    protobuf_AddDesc_DENMessage_2eproto();
  }
} static_descriptor_initializer_DENMessage_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int DENMessage::kManagementContainerFieldNumber;
#endif  // !_MSC_VER

DENMessage::DENMessage()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:its.DENMessage)
}

void DENMessage::InitAsDefaultInstance() {
  managementcontainer_ = const_cast< ::its::DENMManagementContainer*>(&::its::DENMManagementContainer::default_instance());
}

DENMessage::DENMessage(const DENMessage& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:its.DENMessage)
}

void DENMessage::SharedCtor() {
  _cached_size_ = 0;
  managementcontainer_ = NULL;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

DENMessage::~DENMessage() {
  // @@protoc_insertion_point(destructor:its.DENMessage)
  SharedDtor();
}

void DENMessage::SharedDtor() {
  if (this != default_instance_) {
    delete managementcontainer_;
  }
}

void DENMessage::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* DENMessage::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return DENMessage_descriptor_;
}

const DENMessage& DENMessage::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_DENMessage_2eproto();
  return *default_instance_;
}

DENMessage* DENMessage::default_instance_ = NULL;

DENMessage* DENMessage::New() const {
  return new DENMessage;
}

void DENMessage::Clear() {
  if (has_managementcontainer()) {
    if (managementcontainer_ != NULL) managementcontainer_->::its::DENMManagementContainer::Clear();
  }
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool DENMessage::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:its.DENMessage)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required .its.DENMManagementContainer managementContainer = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
               input, mutable_managementcontainer()));
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
  // @@protoc_insertion_point(parse_success:its.DENMessage)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:its.DENMessage)
  return false;
#undef DO_
}

void DENMessage::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:its.DENMessage)
  // required .its.DENMManagementContainer managementContainer = 1;
  if (has_managementcontainer()) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->managementcontainer(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:its.DENMessage)
}

::google::protobuf::uint8* DENMessage::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:its.DENMessage)
  // required .its.DENMManagementContainer managementContainer = 1;
  if (has_managementcontainer()) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->managementcontainer(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:its.DENMessage)
  return target;
}

int DENMessage::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required .its.DENMManagementContainer managementContainer = 1;
    if (has_managementcontainer()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
          this->managementcontainer());
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

void DENMessage::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const DENMessage* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const DENMessage*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void DENMessage::MergeFrom(const DENMessage& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_managementcontainer()) {
      mutable_managementcontainer()->::its::DENMManagementContainer::MergeFrom(from.managementcontainer());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void DENMessage::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void DENMessage::CopyFrom(const DENMessage& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool DENMessage::IsInitialized() const {
  if ((_has_bits_[0] & 0x00000001) != 0x00000001) return false;

  if (has_managementcontainer()) {
    if (!this->managementcontainer().IsInitialized()) return false;
  }
  return true;
}

void DENMessage::Swap(DENMessage* other) {
  if (other != this) {
    std::swap(managementcontainer_, other->managementcontainer_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata DENMessage::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = DENMessage_descriptor_;
  metadata.reflection = DENMessage_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace its

// @@protoc_insertion_point(global_scope)
