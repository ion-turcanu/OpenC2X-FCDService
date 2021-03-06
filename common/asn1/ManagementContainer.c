/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "DENM-PDU-Descriptions"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "ManagementContainer.h"

static int asn_DFL_9_set_600(int set_value, void **sptr) {
	ValidityDuration_t *st = *sptr;
	
	if(!st) {
		if(!set_value) return -1;	/* Not a default value */
		st = (*sptr = CALLOC(1, sizeof(*st)));
		if(!st) return -1;
	}
	
	if(set_value) {
		/* Install default value 600 */
		*st = 600;
		return 0;
	} else {
		/* Test default value 600 */
		return (*st == 600);
	}
}
static asn_TYPE_member_t asn_MBR_ManagementContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct ManagementContainer, actionID),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ActionID,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"actionID"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ManagementContainer, detectionTime),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimestampIts,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"detectionTime"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ManagementContainer, referenceTime),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TimestampIts,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"referenceTime"
		},
	{ ATF_POINTER, 1, offsetof(struct ManagementContainer, termination),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_Termination,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"termination"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ManagementContainer, eventPosition),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ReferencePosition,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"eventPosition"
		},
	{ ATF_POINTER, 4, offsetof(struct ManagementContainer, relevanceDistance),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RelevanceDistance,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"relevanceDistance"
		},
	{ ATF_POINTER, 3, offsetof(struct ManagementContainer, relevanceTrafficDirection),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_RelevanceTrafficDirection,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"relevanceTrafficDirection"
		},
	{ ATF_POINTER, 2, offsetof(struct ManagementContainer, validityDuration),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_ValidityDuration,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		asn_DFL_9_set_600,	/* DEFAULT 600 */
		"validityDuration"
		},
	{ ATF_POINTER, 1, offsetof(struct ManagementContainer, transmissionInterval),
		(ASN_TAG_CLASS_CONTEXT | (8 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_TransmissionInterval,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"transmissionInterval"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct ManagementContainer, stationType),
		(ASN_TAG_CLASS_CONTEXT | (9 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_StationType,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"stationType"
		},
};
static int asn_MAP_ManagementContainer_oms_1[] = { 3, 5, 6, 7, 8 };
static ber_tlv_tag_t asn_DEF_ManagementContainer_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_ManagementContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* actionID at 36 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* detectionTime at 37 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* referenceTime at 38 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* termination at 39 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* eventPosition at 40 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* relevanceDistance at 41 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* relevanceTrafficDirection at 42 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* validityDuration at 43 */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* transmissionInterval at 44 */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* stationType at 45 */
};
static asn_SEQUENCE_specifics_t asn_SPC_ManagementContainer_specs_1 = {
	sizeof(struct ManagementContainer),
	offsetof(struct ManagementContainer, _asn_ctx),
	asn_MAP_ManagementContainer_tag2el_1,
	10,	/* Count of tags in the map */
	asn_MAP_ManagementContainer_oms_1,	/* Optional members */
	5, 0,	/* Root/Additions */
	9,	/* Start extensions */
	11	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_ManagementContainer = {
	"ManagementContainer",
	"ManagementContainer",
	SEQUENCE_free,
	SEQUENCE_print,
	SEQUENCE_constraint,
	SEQUENCE_decode_ber,
	SEQUENCE_encode_der,
	SEQUENCE_decode_xer,
	SEQUENCE_encode_xer,
	SEQUENCE_decode_uper,
	SEQUENCE_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_ManagementContainer_tags_1,
	sizeof(asn_DEF_ManagementContainer_tags_1)
		/sizeof(asn_DEF_ManagementContainer_tags_1[0]), /* 1 */
	asn_DEF_ManagementContainer_tags_1,	/* Same as above */
	sizeof(asn_DEF_ManagementContainer_tags_1)
		/sizeof(asn_DEF_ManagementContainer_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_ManagementContainer_1,
	10,	/* Elements count */
	&asn_SPC_ManagementContainer_specs_1	/* Additional specs */
};

