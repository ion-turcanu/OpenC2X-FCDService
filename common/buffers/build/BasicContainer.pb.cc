// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: BasicContainer.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "BasicContainer.pb.h"

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

const ::google::protobuf::Descriptor* BasicContainer_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  BasicContainer_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_BasicContainer_2eproto() {
  protobuf_AddDesc_BasicContainer_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "BasicContainer.proto");
  GOOGLE_CHECK(file != NULL);
  BasicContainer_descriptor_ = file->message_type(0);
  static const int BasicContainer_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, stationtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, latitude_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, longitude_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, semimajorconfidence_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, semiminorconfidence_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, semimajororientation_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, altitude_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, altitudeconfidence_),
  };
  BasicContainer_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      BasicContainer_descriptor_,
      BasicContainer::default_instance_,
      BasicContainer_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(BasicContainer, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(BasicContainer));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_BasicContainer_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    BasicContainer_descriptor_, &BasicContainer::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_BasicContainer_2eproto() {
  delete BasicContainer::default_instance_;
  delete BasicContainer_reflection_;
}

void protobuf_AddDesc_BasicContainer_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\024BasicContainer.proto\022\003its\"\320\001\n\016BasicCon"
    "tainer\022\023\n\013stationType\030\001 \002(\003\022\020\n\010latitude\030"
    "\002 \002(\003\022\021\n\tlongitude\030\003 \002(\003\022\033\n\023semiMajorCon"
    "fidence\030\004 \002(\003\022\033\n\023semiMinorConfidence\030\005 \002"
    "(\003\022\034\n\024semiMajorOrientation\030\006 \002(\003\022\020\n\010alti"
    "tude\030\007 \002(\003\022\032\n\022altitudeConfidence\030\010 \002(\003", 238);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "BasicContainer.proto", &protobuf_RegisterTypes);
  BasicContainer::default_instance_ = new BasicContainer();
  BasicContainer::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_BasicContainer_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_BasicContainer_2eproto {
  StaticDescriptorInitializer_BasicContainer_2eproto() {
    protobuf_AddDesc_BasicContainer_2eproto();
  }
} static_descriptor_initializer_BasicContainer_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int BasicContainer::kStationTypeFieldNumber;
const int BasicContainer::kLatitudeFieldNumber;
const int BasicContainer::kLongitudeFieldNumber;
const int BasicContainer::kSemiMajorConfidenceFieldNumber;
const int BasicContainer::kSemiMinorConfidenceFieldNumber;
const int BasicContainer::kSemiMajorOrientationFieldNumber;
const int BasicContainer::kAltitudeFieldNumber;
const int BasicContainer::kAltitudeConfidenceFieldNumber;
#endif  // !_MSC_VER

BasicContainer::BasicContainer()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:its.BasicContainer)
}

void BasicContainer::InitAsDefaultInstance() {
}

BasicContainer::BasicContainer(const BasicContainer& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:its.BasicContainer)
}

void BasicContainer::SharedCtor() {
  _cached_size_ = 0;
  stationtype_ = GOOGLE_LONGLONG(0);
  latitude_ = GOOGLE_LONGLONG(0);
  longitude_ = GOOGLE_LONGLONG(0);
  semimajorconfidence_ = GOOGLE_LONGLONG(0);
  semiminorconfidence_ = GOOGLE_LONGLONG(0);
  semimajororientation_ = GOOGLE_LONGLONG(0);
  altitude_ = GOOGLE_LONGLONG(0);
  altitudeconfidence_ = GOOGLE_LONGLONG(0);
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

BasicContainer::~BasicContainer() {
  // @@protoc_insertion_point(destructor:its.BasicContainer)
  SharedDtor();
}

void BasicContainer::SharedDtor() {
  if (this != default_instance_) {
  }
}

void BasicContainer::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* BasicContainer::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return BasicContainer_descriptor_;
}

const BasicContainer& BasicContainer::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_BasicContainer_2eproto();
  return *default_instance_;
}

BasicContainer* BasicContainer::default_instance_ = NULL;

BasicContainer* BasicContainer::New() const {
  return new BasicContainer;
}

void BasicContainer::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<BasicContainer*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(stationtype_, altitudeconfidence_);
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool BasicContainer::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:its.BasicContainer)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // required int64 stationType = 1;
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &stationtype_)));
          set_has_stationtype();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_latitude;
        break;
      }

      // required int64 latitude = 2;
      case 2: {
        if (tag == 16) {
         parse_latitude:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &latitude_)));
          set_has_latitude();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_longitude;
        break;
      }

      // required int64 longitude = 3;
      case 3: {
        if (tag == 24) {
         parse_longitude:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &longitude_)));
          set_has_longitude();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_semiMajorConfidence;
        break;
      }

      // required int64 semiMajorConfidence = 4;
      case 4: {
        if (tag == 32) {
         parse_semiMajorConfidence:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &semimajorconfidence_)));
          set_has_semimajorconfidence();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_semiMinorConfidence;
        break;
      }

      // required int64 semiMinorConfidence = 5;
      case 5: {
        if (tag == 40) {
         parse_semiMinorConfidence:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &semiminorconfidence_)));
          set_has_semiminorconfidence();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_semiMajorOrientation;
        break;
      }

      // required int64 semiMajorOrientation = 6;
      case 6: {
        if (tag == 48) {
         parse_semiMajorOrientation:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &semimajororientation_)));
          set_has_semimajororientation();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_altitude;
        break;
      }

      // required int64 altitude = 7;
      case 7: {
        if (tag == 56) {
         parse_altitude:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &altitude_)));
          set_has_altitude();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_altitudeConfidence;
        break;
      }

      // required int64 altitudeConfidence = 8;
      case 8: {
        if (tag == 64) {
         parse_altitudeConfidence:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &altitudeconfidence_)));
          set_has_altitudeconfidence();
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
  // @@protoc_insertion_point(parse_success:its.BasicContainer)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:its.BasicContainer)
  return false;
#undef DO_
}

void BasicContainer::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:its.BasicContainer)
  // required int64 stationType = 1;
  if (has_stationtype()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(1, this->stationtype(), output);
  }

  // required int64 latitude = 2;
  if (has_latitude()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(2, this->latitude(), output);
  }

  // required int64 longitude = 3;
  if (has_longitude()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(3, this->longitude(), output);
  }

  // required int64 semiMajorConfidence = 4;
  if (has_semimajorconfidence()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->semimajorconfidence(), output);
  }

  // required int64 semiMinorConfidence = 5;
  if (has_semiminorconfidence()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(5, this->semiminorconfidence(), output);
  }

  // required int64 semiMajorOrientation = 6;
  if (has_semimajororientation()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(6, this->semimajororientation(), output);
  }

  // required int64 altitude = 7;
  if (has_altitude()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(7, this->altitude(), output);
  }

  // required int64 altitudeConfidence = 8;
  if (has_altitudeconfidence()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(8, this->altitudeconfidence(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:its.BasicContainer)
}

::google::protobuf::uint8* BasicContainer::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:its.BasicContainer)
  // required int64 stationType = 1;
  if (has_stationtype()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(1, this->stationtype(), target);
  }

  // required int64 latitude = 2;
  if (has_latitude()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(2, this->latitude(), target);
  }

  // required int64 longitude = 3;
  if (has_longitude()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(3, this->longitude(), target);
  }

  // required int64 semiMajorConfidence = 4;
  if (has_semimajorconfidence()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->semimajorconfidence(), target);
  }

  // required int64 semiMinorConfidence = 5;
  if (has_semiminorconfidence()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(5, this->semiminorconfidence(), target);
  }

  // required int64 semiMajorOrientation = 6;
  if (has_semimajororientation()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(6, this->semimajororientation(), target);
  }

  // required int64 altitude = 7;
  if (has_altitude()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(7, this->altitude(), target);
  }

  // required int64 altitudeConfidence = 8;
  if (has_altitudeconfidence()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(8, this->altitudeconfidence(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:its.BasicContainer)
  return target;
}

int BasicContainer::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // required int64 stationType = 1;
    if (has_stationtype()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->stationtype());
    }

    // required int64 latitude = 2;
    if (has_latitude()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->latitude());
    }

    // required int64 longitude = 3;
    if (has_longitude()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->longitude());
    }

    // required int64 semiMajorConfidence = 4;
    if (has_semimajorconfidence()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->semimajorconfidence());
    }

    // required int64 semiMinorConfidence = 5;
    if (has_semiminorconfidence()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->semiminorconfidence());
    }

    // required int64 semiMajorOrientation = 6;
    if (has_semimajororientation()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->semimajororientation());
    }

    // required int64 altitude = 7;
    if (has_altitude()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->altitude());
    }

    // required int64 altitudeConfidence = 8;
    if (has_altitudeconfidence()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int64Size(
          this->altitudeconfidence());
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

void BasicContainer::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const BasicContainer* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const BasicContainer*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void BasicContainer::MergeFrom(const BasicContainer& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_stationtype()) {
      set_stationtype(from.stationtype());
    }
    if (from.has_latitude()) {
      set_latitude(from.latitude());
    }
    if (from.has_longitude()) {
      set_longitude(from.longitude());
    }
    if (from.has_semimajorconfidence()) {
      set_semimajorconfidence(from.semimajorconfidence());
    }
    if (from.has_semiminorconfidence()) {
      set_semiminorconfidence(from.semiminorconfidence());
    }
    if (from.has_semimajororientation()) {
      set_semimajororientation(from.semimajororientation());
    }
    if (from.has_altitude()) {
      set_altitude(from.altitude());
    }
    if (from.has_altitudeconfidence()) {
      set_altitudeconfidence(from.altitudeconfidence());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void BasicContainer::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void BasicContainer::CopyFrom(const BasicContainer& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool BasicContainer::IsInitialized() const {
  if ((_has_bits_[0] & 0x000000ff) != 0x000000ff) return false;

  return true;
}

void BasicContainer::Swap(BasicContainer* other) {
  if (other != this) {
    std::swap(stationtype_, other->stationtype_);
    std::swap(latitude_, other->latitude_);
    std::swap(longitude_, other->longitude_);
    std::swap(semimajorconfidence_, other->semimajorconfidence_);
    std::swap(semiminorconfidence_, other->semiminorconfidence_);
    std::swap(semimajororientation_, other->semimajororientation_);
    std::swap(altitude_, other->altitude_);
    std::swap(altitudeconfidence_, other->altitudeconfidence_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata BasicContainer::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = BasicContainer_descriptor_;
  metadata.reflection = BasicContainer_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace its

// @@protoc_insertion_point(global_scope)