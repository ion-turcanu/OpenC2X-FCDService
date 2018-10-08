/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "FCD-PDU-Descriptions"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#ifndef	_FCDBasicHeader_H_
#define	_FCDBasicHeader_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "StationID.h"
#include "RequestID.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum protocolVersion {
	protocolVersion_currentVersion	= 1
} e_protocolVersion;

/* FCDBasicHeader */
typedef struct FCDBasicHeader {
	long	 protocolVersion;
	long	 reserved;
	StationID_t	 stationID;
	RequestID_t	 requestID;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FCDBasicHeader_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FCDBasicHeader;

#ifdef __cplusplus
}
#endif

#endif	/* _FCDBasicHeader_H_ */
#include <asn_internal.h>
