// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: ADVwap.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "ADVwap.pb.h"

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

namespace com {
namespace htsc {
namespace mdc {
namespace insight {
namespace model {

namespace {

const ::google::protobuf::Descriptor* ADVwap_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  ADVwap_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_ADVwap_2eproto() GOOGLE_ATTRIBUTE_COLD;
void protobuf_AssignDesc_ADVwap_2eproto() {
  protobuf_AddDesc_ADVwap_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "ADVwap.proto");
  GOOGLE_CHECK(file != NULL);
  ADVwap_descriptor_ = file->message_type(0);
  static const int ADVwap_offsets_[11] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, htscsecurityid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, mddate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, mdtime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, datatimestamp_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, securityidsource_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, securitytype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, periodtype_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, volume_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, vwap_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, exchangedate_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, exchangetime_),
  };
  ADVwap_reflection_ =
    ::google::protobuf::internal::GeneratedMessageReflection::NewGeneratedMessageReflection(
      ADVwap_descriptor_,
      ADVwap::internal_default_instance(),
      ADVwap_offsets_,
      -1,
      -1,
      -1,
      sizeof(ADVwap),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(ADVwap, _internal_metadata_));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_ADVwap_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) GOOGLE_ATTRIBUTE_COLD;
void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
      ADVwap_descriptor_, ADVwap::internal_default_instance());
}

}  // namespace

void protobuf_ShutdownFile_ADVwap_2eproto() {
  ADVwap_default_instance_.Shutdown();
  delete ADVwap_reflection_;
}

void protobuf_InitDefaults_ADVwap_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::com::htsc::mdc::model::protobuf_InitDefaults_EMDPeriodType_2eproto();
  ::com::htsc::mdc::model::protobuf_InitDefaults_ESecurityType_2eproto();
  ::com::htsc::mdc::model::protobuf_InitDefaults_ESecurityIDSource_2eproto();
  ::google::protobuf::internal::GetEmptyString();
  ADVwap_default_instance_.DefaultConstruct();
  ADVwap_default_instance_.get_mutable()->InitAsDefaultInstance();
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_InitDefaults_ADVwap_2eproto_once_);
void protobuf_InitDefaults_ADVwap_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_InitDefaults_ADVwap_2eproto_once_,
                 &protobuf_InitDefaults_ADVwap_2eproto_impl);
}
void protobuf_AddDesc_ADVwap_2eproto_impl() {
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  protobuf_InitDefaults_ADVwap_2eproto();
  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\014ADVwap.proto\022\032com.htsc.mdc.insight.mod"
    "el\032\023EMDPeriodType.proto\032\023ESecurityType.p"
    "roto\032\027ESecurityIDSource.proto\"\322\002\n\006ADVwap"
    "\022\026\n\016HTSCSecurityID\030\001 \001(\t\022\016\n\006MDDate\030\002 \001(\005"
    "\022\016\n\006MDTime\030\003 \001(\005\022\025\n\rDataTimestamp\030\004 \001(\003\022"
    "\?\n\020securityIDSource\030\005 \001(\0162%.com.htsc.mdc"
    ".model.ESecurityIDSource\0227\n\014securityType"
    "\030\006 \001(\0162!.com.htsc.mdc.model.ESecurityTyp"
    "e\0225\n\nPeriodType\030\007 \001(\0162!.com.htsc.mdc.mod"
    "el.EMDPeriodType\022\016\n\006Volume\030\010 \001(\003\022\014\n\004Vwap"
    "\030\t \001(\003\022\024\n\014ExchangeDate\030\n \001(\005\022\024\n\014Exchange"
    "Time\030\013 \001(\005B/\n\032com.htsc.mdc.insight.model"
    "B\014ADVwapProtosH\001\240\001\001b\006proto3", 507);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "ADVwap.proto", &protobuf_RegisterTypes);
  ::com::htsc::mdc::model::protobuf_AddDesc_EMDPeriodType_2eproto();
  ::com::htsc::mdc::model::protobuf_AddDesc_ESecurityType_2eproto();
  ::com::htsc::mdc::model::protobuf_AddDesc_ESecurityIDSource_2eproto();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_ADVwap_2eproto);
}

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AddDesc_ADVwap_2eproto_once_);
void protobuf_AddDesc_ADVwap_2eproto() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AddDesc_ADVwap_2eproto_once_,
                 &protobuf_AddDesc_ADVwap_2eproto_impl);
}
// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_ADVwap_2eproto {
  StaticDescriptorInitializer_ADVwap_2eproto() {
    protobuf_AddDesc_ADVwap_2eproto();
  }
} static_descriptor_initializer_ADVwap_2eproto_;

namespace {

static void MergeFromFail(int line) GOOGLE_ATTRIBUTE_COLD GOOGLE_ATTRIBUTE_NORETURN;
static void MergeFromFail(int line) {
  ::google::protobuf::internal::MergeFromFail(__FILE__, line);
}

}  // namespace


// ===================================================================

#if !defined(_MSC_VER) || _MSC_VER >= 1900
const int ADVwap::kHTSCSecurityIDFieldNumber;
const int ADVwap::kMDDateFieldNumber;
const int ADVwap::kMDTimeFieldNumber;
const int ADVwap::kDataTimestampFieldNumber;
const int ADVwap::kSecurityIDSourceFieldNumber;
const int ADVwap::kSecurityTypeFieldNumber;
const int ADVwap::kPeriodTypeFieldNumber;
const int ADVwap::kVolumeFieldNumber;
const int ADVwap::kVwapFieldNumber;
const int ADVwap::kExchangeDateFieldNumber;
const int ADVwap::kExchangeTimeFieldNumber;
#endif  // !defined(_MSC_VER) || _MSC_VER >= 1900

ADVwap::ADVwap()
  : ::google::protobuf::Message(), _internal_metadata_(NULL) {
  if (this != internal_default_instance()) protobuf_InitDefaults_ADVwap_2eproto();
  SharedCtor();
  // @@protoc_insertion_point(constructor:com.htsc.mdc.insight.model.ADVwap)
}

void ADVwap::InitAsDefaultInstance() {
}

ADVwap::ADVwap(const ADVwap& from)
  : ::google::protobuf::Message(),
    _internal_metadata_(NULL) {
  SharedCtor();
  UnsafeMergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:com.htsc.mdc.insight.model.ADVwap)
}

void ADVwap::SharedCtor() {
  htscsecurityid_.UnsafeSetDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(&mddate_, 0, reinterpret_cast<char*>(&exchangetime_) -
    reinterpret_cast<char*>(&mddate_) + sizeof(exchangetime_));
  _cached_size_ = 0;
}

ADVwap::~ADVwap() {
  // @@protoc_insertion_point(destructor:com.htsc.mdc.insight.model.ADVwap)
  SharedDtor();
}

void ADVwap::SharedDtor() {
  htscsecurityid_.DestroyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}

void ADVwap::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* ADVwap::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return ADVwap_descriptor_;
}

const ADVwap& ADVwap::default_instance() {
  protobuf_InitDefaults_ADVwap_2eproto();
  return *internal_default_instance();
}

::google::protobuf::internal::ExplicitlyConstructed<ADVwap> ADVwap_default_instance_;

ADVwap* ADVwap::New(::google::protobuf::Arena* arena) const {
  ADVwap* n = new ADVwap;
  if (arena != NULL) {
    arena->Own(n);
  }
  return n;
}

void ADVwap::Clear() {
// @@protoc_insertion_point(message_clear_start:com.htsc.mdc.insight.model.ADVwap)
#if defined(__clang__)
#define ZR_HELPER_(f) \
  _Pragma("clang diagnostic push") \
  _Pragma("clang diagnostic ignored \"-Winvalid-offsetof\"") \
  __builtin_offsetof(ADVwap, f) \
  _Pragma("clang diagnostic pop")
#else
#define ZR_HELPER_(f) reinterpret_cast<char*>(\
  &reinterpret_cast<ADVwap*>(16)->f)
#endif

#define ZR_(first, last) do {\
  ::memset(&(first), 0,\
           ZR_HELPER_(last) - ZR_HELPER_(first) + sizeof(last));\
} while (0)

  ZR_(mddate_, periodtype_);
  htscsecurityid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ZR_(exchangedate_, exchangetime_);

#undef ZR_HELPER_
#undef ZR_

}

bool ADVwap::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!GOOGLE_PREDICT_TRUE(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:com.htsc.mdc.insight.model.ADVwap)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional string HTSCSecurityID = 1;
      case 1: {
        if (tag == 10) {
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_htscsecurityid()));
          DO_(::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
            this->htscsecurityid().data(), this->htscsecurityid().length(),
            ::google::protobuf::internal::WireFormatLite::PARSE,
            "com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID"));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_MDDate;
        break;
      }

      // optional int32 MDDate = 2;
      case 2: {
        if (tag == 16) {
         parse_MDDate:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &mddate_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(24)) goto parse_MDTime;
        break;
      }

      // optional int32 MDTime = 3;
      case 3: {
        if (tag == 24) {
         parse_MDTime:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &mdtime_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_DataTimestamp;
        break;
      }

      // optional int64 DataTimestamp = 4;
      case 4: {
        if (tag == 32) {
         parse_DataTimestamp:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &datatimestamp_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(40)) goto parse_securityIDSource;
        break;
      }

      // optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
      case 5: {
        if (tag == 40) {
         parse_securityIDSource:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_securityidsource(static_cast< ::com::htsc::mdc::model::ESecurityIDSource >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(48)) goto parse_securityType;
        break;
      }

      // optional .com.htsc.mdc.model.ESecurityType securityType = 6;
      case 6: {
        if (tag == 48) {
         parse_securityType:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_securitytype(static_cast< ::com::htsc::mdc::model::ESecurityType >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_PeriodType;
        break;
      }

      // optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
      case 7: {
        if (tag == 56) {
         parse_PeriodType:
          int value;
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   int, ::google::protobuf::internal::WireFormatLite::TYPE_ENUM>(
                 input, &value)));
          set_periodtype(static_cast< ::com::htsc::mdc::model::EMDPeriodType >(value));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(64)) goto parse_Volume;
        break;
      }

      // optional int64 Volume = 8;
      case 8: {
        if (tag == 64) {
         parse_Volume:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &volume_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(72)) goto parse_Vwap;
        break;
      }

      // optional int64 Vwap = 9;
      case 9: {
        if (tag == 72) {
         parse_Vwap:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int64, ::google::protobuf::internal::WireFormatLite::TYPE_INT64>(
                 input, &vwap_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(80)) goto parse_ExchangeDate;
        break;
      }

      // optional int32 ExchangeDate = 10;
      case 10: {
        if (tag == 80) {
         parse_ExchangeDate:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &exchangedate_)));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(88)) goto parse_ExchangeTime;
        break;
      }

      // optional int32 ExchangeTime = 11;
      case 11: {
        if (tag == 88) {
         parse_ExchangeTime:

          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &exchangetime_)));
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
        DO_(::google::protobuf::internal::WireFormatLite::SkipField(input, tag));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:com.htsc.mdc.insight.model.ADVwap)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:com.htsc.mdc.insight.model.ADVwap)
  return false;
#undef DO_
}

void ADVwap::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:com.htsc.mdc.insight.model.ADVwap)
  // optional string HTSCSecurityID = 1;
  if (this->htscsecurityid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->htscsecurityid().data(), this->htscsecurityid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      1, this->htscsecurityid(), output);
  }

  // optional int32 MDDate = 2;
  if (this->mddate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->mddate(), output);
  }

  // optional int32 MDTime = 3;
  if (this->mdtime() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(3, this->mdtime(), output);
  }

  // optional int64 DataTimestamp = 4;
  if (this->datatimestamp() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(4, this->datatimestamp(), output);
  }

  // optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
  if (this->securityidsource() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      5, this->securityidsource(), output);
  }

  // optional .com.htsc.mdc.model.ESecurityType securityType = 6;
  if (this->securitytype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      6, this->securitytype(), output);
  }

  // optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
  if (this->periodtype() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteEnum(
      7, this->periodtype(), output);
  }

  // optional int64 Volume = 8;
  if (this->volume() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(8, this->volume(), output);
  }

  // optional int64 Vwap = 9;
  if (this->vwap() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt64(9, this->vwap(), output);
  }

  // optional int32 ExchangeDate = 10;
  if (this->exchangedate() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(10, this->exchangedate(), output);
  }

  // optional int32 ExchangeTime = 11;
  if (this->exchangetime() != 0) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(11, this->exchangetime(), output);
  }

  // @@protoc_insertion_point(serialize_end:com.htsc.mdc.insight.model.ADVwap)
}

::google::protobuf::uint8* ADVwap::InternalSerializeWithCachedSizesToArray(
    bool deterministic, ::google::protobuf::uint8* target) const {
  (void)deterministic; // Unused
  // @@protoc_insertion_point(serialize_to_array_start:com.htsc.mdc.insight.model.ADVwap)
  // optional string HTSCSecurityID = 1;
  if (this->htscsecurityid().size() > 0) {
    ::google::protobuf::internal::WireFormatLite::VerifyUtf8String(
      this->htscsecurityid().data(), this->htscsecurityid().length(),
      ::google::protobuf::internal::WireFormatLite::SERIALIZE,
      "com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        1, this->htscsecurityid(), target);
  }

  // optional int32 MDDate = 2;
  if (this->mddate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->mddate(), target);
  }

  // optional int32 MDTime = 3;
  if (this->mdtime() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(3, this->mdtime(), target);
  }

  // optional int64 DataTimestamp = 4;
  if (this->datatimestamp() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(4, this->datatimestamp(), target);
  }

  // optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
  if (this->securityidsource() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      5, this->securityidsource(), target);
  }

  // optional .com.htsc.mdc.model.ESecurityType securityType = 6;
  if (this->securitytype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      6, this->securitytype(), target);
  }

  // optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
  if (this->periodtype() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteEnumToArray(
      7, this->periodtype(), target);
  }

  // optional int64 Volume = 8;
  if (this->volume() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(8, this->volume(), target);
  }

  // optional int64 Vwap = 9;
  if (this->vwap() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt64ToArray(9, this->vwap(), target);
  }

  // optional int32 ExchangeDate = 10;
  if (this->exchangedate() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(10, this->exchangedate(), target);
  }

  // optional int32 ExchangeTime = 11;
  if (this->exchangetime() != 0) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(11, this->exchangetime(), target);
  }

  // @@protoc_insertion_point(serialize_to_array_end:com.htsc.mdc.insight.model.ADVwap)
  return target;
}

size_t ADVwap::ByteSizeLong() const {
// @@protoc_insertion_point(message_byte_size_start:com.htsc.mdc.insight.model.ADVwap)
  size_t total_size = 0;

  // optional string HTSCSecurityID = 1;
  if (this->htscsecurityid().size() > 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::StringSize(
        this->htscsecurityid());
  }

  // optional int32 MDDate = 2;
  if (this->mddate() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->mddate());
  }

  // optional int32 MDTime = 3;
  if (this->mdtime() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->mdtime());
  }

  // optional int64 DataTimestamp = 4;
  if (this->datatimestamp() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->datatimestamp());
  }

  // optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
  if (this->securityidsource() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->securityidsource());
  }

  // optional .com.htsc.mdc.model.ESecurityType securityType = 6;
  if (this->securitytype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->securitytype());
  }

  // optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
  if (this->periodtype() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::EnumSize(this->periodtype());
  }

  // optional int64 Volume = 8;
  if (this->volume() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->volume());
  }

  // optional int64 Vwap = 9;
  if (this->vwap() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int64Size(
        this->vwap());
  }

  // optional int32 ExchangeDate = 10;
  if (this->exchangedate() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->exchangedate());
  }

  // optional int32 ExchangeTime = 11;
  if (this->exchangetime() != 0) {
    total_size += 1 +
      ::google::protobuf::internal::WireFormatLite::Int32Size(
        this->exchangetime());
  }

  int cached_size = ::google::protobuf::internal::ToCachedSize(total_size);
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = cached_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void ADVwap::MergeFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_merge_from_start:com.htsc.mdc.insight.model.ADVwap)
  if (GOOGLE_PREDICT_FALSE(&from == this)) MergeFromFail(__LINE__);
  const ADVwap* source =
      ::google::protobuf::internal::DynamicCastToGenerated<const ADVwap>(
          &from);
  if (source == NULL) {
  // @@protoc_insertion_point(generalized_merge_from_cast_fail:com.htsc.mdc.insight.model.ADVwap)
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
  // @@protoc_insertion_point(generalized_merge_from_cast_success:com.htsc.mdc.insight.model.ADVwap)
    UnsafeMergeFrom(*source);
  }
}

void ADVwap::MergeFrom(const ADVwap& from) {
// @@protoc_insertion_point(class_specific_merge_from_start:com.htsc.mdc.insight.model.ADVwap)
  if (GOOGLE_PREDICT_TRUE(&from != this)) {
    UnsafeMergeFrom(from);
  } else {
    MergeFromFail(__LINE__);
  }
}

void ADVwap::UnsafeMergeFrom(const ADVwap& from) {
  GOOGLE_DCHECK(&from != this);
  if (from.htscsecurityid().size() > 0) {

    htscsecurityid_.AssignWithDefault(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), from.htscsecurityid_);
  }
  if (from.mddate() != 0) {
    set_mddate(from.mddate());
  }
  if (from.mdtime() != 0) {
    set_mdtime(from.mdtime());
  }
  if (from.datatimestamp() != 0) {
    set_datatimestamp(from.datatimestamp());
  }
  if (from.securityidsource() != 0) {
    set_securityidsource(from.securityidsource());
  }
  if (from.securitytype() != 0) {
    set_securitytype(from.securitytype());
  }
  if (from.periodtype() != 0) {
    set_periodtype(from.periodtype());
  }
  if (from.volume() != 0) {
    set_volume(from.volume());
  }
  if (from.vwap() != 0) {
    set_vwap(from.vwap());
  }
  if (from.exchangedate() != 0) {
    set_exchangedate(from.exchangedate());
  }
  if (from.exchangetime() != 0) {
    set_exchangetime(from.exchangetime());
  }
}

void ADVwap::CopyFrom(const ::google::protobuf::Message& from) {
// @@protoc_insertion_point(generalized_copy_from_start:com.htsc.mdc.insight.model.ADVwap)
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void ADVwap::CopyFrom(const ADVwap& from) {
// @@protoc_insertion_point(class_specific_copy_from_start:com.htsc.mdc.insight.model.ADVwap)
  if (&from == this) return;
  Clear();
  UnsafeMergeFrom(from);
}

bool ADVwap::IsInitialized() const {

  return true;
}

void ADVwap::Swap(ADVwap* other) {
  if (other == this) return;
  InternalSwap(other);
}
void ADVwap::InternalSwap(ADVwap* other) {
  htscsecurityid_.Swap(&other->htscsecurityid_);
  std::swap(mddate_, other->mddate_);
  std::swap(mdtime_, other->mdtime_);
  std::swap(datatimestamp_, other->datatimestamp_);
  std::swap(securityidsource_, other->securityidsource_);
  std::swap(securitytype_, other->securitytype_);
  std::swap(periodtype_, other->periodtype_);
  std::swap(volume_, other->volume_);
  std::swap(vwap_, other->vwap_);
  std::swap(exchangedate_, other->exchangedate_);
  std::swap(exchangetime_, other->exchangetime_);
  _internal_metadata_.Swap(&other->_internal_metadata_);
  std::swap(_cached_size_, other->_cached_size_);
}

::google::protobuf::Metadata ADVwap::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = ADVwap_descriptor_;
  metadata.reflection = ADVwap_reflection_;
  return metadata;
}

#if PROTOBUF_INLINE_NOT_IN_HEADERS
// ADVwap

// optional string HTSCSecurityID = 1;
void ADVwap::clear_htscsecurityid() {
  htscsecurityid_.ClearToEmptyNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
const ::std::string& ADVwap::htscsecurityid() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
  return htscsecurityid_.GetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void ADVwap::set_htscsecurityid(const ::std::string& value) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), value);
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
}
void ADVwap::set_htscsecurityid(const char* value) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
}
void ADVwap::set_htscsecurityid(const char* value, size_t size) {
  
  htscsecurityid_.SetNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
}
::std::string* ADVwap::mutable_htscsecurityid() {
  
  // @@protoc_insertion_point(field_mutable:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
  return htscsecurityid_.MutableNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
::std::string* ADVwap::release_htscsecurityid() {
  // @@protoc_insertion_point(field_release:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
  
  return htscsecurityid_.ReleaseNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
}
void ADVwap::set_allocated_htscsecurityid(::std::string* htscsecurityid) {
  if (htscsecurityid != NULL) {
    
  } else {
    
  }
  htscsecurityid_.SetAllocatedNoArena(&::google::protobuf::internal::GetEmptyStringAlreadyInited(), htscsecurityid);
  // @@protoc_insertion_point(field_set_allocated:com.htsc.mdc.insight.model.ADVwap.HTSCSecurityID)
}

// optional int32 MDDate = 2;
void ADVwap::clear_mddate() {
  mddate_ = 0;
}
::google::protobuf::int32 ADVwap::mddate() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.MDDate)
  return mddate_;
}
void ADVwap::set_mddate(::google::protobuf::int32 value) {
  
  mddate_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.MDDate)
}

// optional int32 MDTime = 3;
void ADVwap::clear_mdtime() {
  mdtime_ = 0;
}
::google::protobuf::int32 ADVwap::mdtime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.MDTime)
  return mdtime_;
}
void ADVwap::set_mdtime(::google::protobuf::int32 value) {
  
  mdtime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.MDTime)
}

// optional int64 DataTimestamp = 4;
void ADVwap::clear_datatimestamp() {
  datatimestamp_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 ADVwap::datatimestamp() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.DataTimestamp)
  return datatimestamp_;
}
void ADVwap::set_datatimestamp(::google::protobuf::int64 value) {
  
  datatimestamp_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.DataTimestamp)
}

// optional .com.htsc.mdc.model.ESecurityIDSource securityIDSource = 5;
void ADVwap::clear_securityidsource() {
  securityidsource_ = 0;
}
::com::htsc::mdc::model::ESecurityIDSource ADVwap::securityidsource() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.securityIDSource)
  return static_cast< ::com::htsc::mdc::model::ESecurityIDSource >(securityidsource_);
}
void ADVwap::set_securityidsource(::com::htsc::mdc::model::ESecurityIDSource value) {
  
  securityidsource_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.securityIDSource)
}

// optional .com.htsc.mdc.model.ESecurityType securityType = 6;
void ADVwap::clear_securitytype() {
  securitytype_ = 0;
}
::com::htsc::mdc::model::ESecurityType ADVwap::securitytype() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.securityType)
  return static_cast< ::com::htsc::mdc::model::ESecurityType >(securitytype_);
}
void ADVwap::set_securitytype(::com::htsc::mdc::model::ESecurityType value) {
  
  securitytype_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.securityType)
}

// optional .com.htsc.mdc.model.EMDPeriodType PeriodType = 7;
void ADVwap::clear_periodtype() {
  periodtype_ = 0;
}
::com::htsc::mdc::model::EMDPeriodType ADVwap::periodtype() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.PeriodType)
  return static_cast< ::com::htsc::mdc::model::EMDPeriodType >(periodtype_);
}
void ADVwap::set_periodtype(::com::htsc::mdc::model::EMDPeriodType value) {
  
  periodtype_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.PeriodType)
}

// optional int64 Volume = 8;
void ADVwap::clear_volume() {
  volume_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 ADVwap::volume() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.Volume)
  return volume_;
}
void ADVwap::set_volume(::google::protobuf::int64 value) {
  
  volume_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.Volume)
}

// optional int64 Vwap = 9;
void ADVwap::clear_vwap() {
  vwap_ = GOOGLE_LONGLONG(0);
}
::google::protobuf::int64 ADVwap::vwap() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.Vwap)
  return vwap_;
}
void ADVwap::set_vwap(::google::protobuf::int64 value) {
  
  vwap_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.Vwap)
}

// optional int32 ExchangeDate = 10;
void ADVwap::clear_exchangedate() {
  exchangedate_ = 0;
}
::google::protobuf::int32 ADVwap::exchangedate() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.ExchangeDate)
  return exchangedate_;
}
void ADVwap::set_exchangedate(::google::protobuf::int32 value) {
  
  exchangedate_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.ExchangeDate)
}

// optional int32 ExchangeTime = 11;
void ADVwap::clear_exchangetime() {
  exchangetime_ = 0;
}
::google::protobuf::int32 ADVwap::exchangetime() const {
  // @@protoc_insertion_point(field_get:com.htsc.mdc.insight.model.ADVwap.ExchangeTime)
  return exchangetime_;
}
void ADVwap::set_exchangetime(::google::protobuf::int32 value) {
  
  exchangetime_ = value;
  // @@protoc_insertion_point(field_set:com.htsc.mdc.insight.model.ADVwap.ExchangeTime)
}

inline const ADVwap* ADVwap::internal_default_instance() {
  return &ADVwap_default_instance_.get();
}
#endif  // PROTOBUF_INLINE_NOT_IN_HEADERS

// @@protoc_insertion_point(namespace_scope)

}  // namespace model
}  // namespace insight
}  // namespace mdc
}  // namespace htsc
}  // namespace com

// @@protoc_insertion_point(global_scope)
