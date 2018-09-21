/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "PosConfidenceEllipse.h"

static asn_TYPE_member_t asn_MBR_PosConfidenceEllipse_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct PosConfidenceEllipse, semiMajorConfidence),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SemiAxisLength,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"semiMajorConfidence"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosConfidenceEllipse, semiMinorConfidence),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_SemiAxisLength,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"semiMinorConfidence"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct PosConfidenceEllipse, semiMajorOrientation),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_HeadingValue,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"semiMajorOrientation"
		},
};
static ber_tlv_tag_t asn_DEF_PosConfidenceEllipse_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_PosConfidenceEllipse_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* semiMajorConfidence at 361 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* semiMinorConfidence at 362 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 } /* semiMajorOrientation at 364 */
};
static asn_SEQUENCE_specifics_t asn_SPC_PosConfidenceEllipse_specs_1 = {
	sizeof(struct PosConfidenceEllipse),
	offsetof(struct PosConfidenceEllipse, _asn_ctx),
	asn_MAP_PosConfidenceEllipse_tag2el_1,
	3,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_PosConfidenceEllipse = {
	"PosConfidenceEllipse",
	"PosConfidenceEllipse",
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
	asn_DEF_PosConfidenceEllipse_tags_1,
	sizeof(asn_DEF_PosConfidenceEllipse_tags_1)
		/sizeof(asn_DEF_PosConfidenceEllipse_tags_1[0]), /* 1 */
	asn_DEF_PosConfidenceEllipse_tags_1,	/* Same as above */
	sizeof(asn_DEF_PosConfidenceEllipse_tags_1)
		/sizeof(asn_DEF_PosConfidenceEllipse_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_PosConfidenceEllipse_1,
	3,	/* Elements count */
	&asn_SPC_PosConfidenceEllipse_specs_1	/* Additional specs */
};

