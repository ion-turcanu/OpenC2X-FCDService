/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "FCD-PDU-Descriptions"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#ifndef	_FCDRequestHeader_H_
#define	_FCDRequestHeader_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "Longitude.h"
#include "Latitude.h"
#include "Altitude.h"
#include "TimestampIts.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* FCDRequestHeader */
typedef struct FCDRequestHeader {
	long	 dMax;
	long	 hMax;
	long	 hCur;
	unsigned long	 tMaxReq;
	unsigned long	 tMaxRep;
	Longitude_t	 longitude;
	Latitude_t	 latitude;
	Altitude_t	 altitude;
	TimestampIts_t	 generationTime;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FCDRequestHeader_t;

/* Implementation */
/* extern asn_TYPE_descriptor_t asn_DEF_tMaxReq_5;	// (Use -fall-defs-global to expose) */
/* extern asn_TYPE_descriptor_t asn_DEF_tMaxRep_6;	// (Use -fall-defs-global to expose) */
extern asn_TYPE_descriptor_t asn_DEF_FCDRequestHeader;

#ifdef __cplusplus
}
#endif

#endif	/* _FCDRequestHeader_H_ */
#include <asn_internal.h>