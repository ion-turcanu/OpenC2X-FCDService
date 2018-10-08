/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "FCD-PDU-Descriptions"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#ifndef	_FCDREQ_H_
#define	_FCDREQ_H_


#include <asn_application.h>

/* Including external dependencies */
#include <NativeInteger.h>
#include "FCDBasicHeader.h"
#include "FCDRequestHeader.h"
#include <constr_SEQUENCE.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Dependencies */
typedef enum messageID {
	messageID_request	= 1,
	messageID_reply	= 2
} e_messageID;

/* FCDREQ */
typedef struct FCDREQ {
	long	 messageID;
	FCDBasicHeader_t	 fcdBasicHeader;
	FCDRequestHeader_t	 fcdRequestHeader;
	
	/* Context for parsing across buffer boundaries */
	asn_struct_ctx_t _asn_ctx;
} FCDREQ_t;

/* Implementation */
extern asn_TYPE_descriptor_t asn_DEF_FCDREQ;

#ifdef __cplusplus
}
#endif

#endif	/* _FCDREQ_H_ */
#include <asn_internal.h>
