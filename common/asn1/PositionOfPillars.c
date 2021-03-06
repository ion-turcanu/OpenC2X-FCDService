/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "PositionOfPillars.h"

static asn_per_constraints_t asn_PER_type_PositionOfPillars_constr_1 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_CONSTRAINED,	 2,  2,  1,  3 }	/* (SIZE(1..3)) */,
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_PositionOfPillars_1[] = {
	{ ATF_POINTER, 0, 0,
		(ASN_TAG_CLASS_UNIVERSAL | (2 << 2)),
		0,
		&asn_DEF_PosPillar,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		""
		},
};
static ber_tlv_tag_t asn_DEF_PositionOfPillars_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_SET_OF_specifics_t asn_SPC_PositionOfPillars_specs_1 = {
	sizeof(struct PositionOfPillars),
	offsetof(struct PositionOfPillars, _asn_ctx),
	0,	/* XER encoding is XMLDelimitedItemList */
};
asn_TYPE_descriptor_t asn_DEF_PositionOfPillars = {
	"PositionOfPillars",
	"PositionOfPillars",
	SEQUENCE_OF_free,
	SEQUENCE_OF_print,
	SEQUENCE_OF_constraint,
	SEQUENCE_OF_decode_ber,
	SEQUENCE_OF_encode_der,
	SEQUENCE_OF_decode_xer,
	SEQUENCE_OF_encode_xer,
	SEQUENCE_OF_decode_uper,
	SEQUENCE_OF_encode_uper,
	0,	/* Use generic outmost tag fetcher */
	asn_DEF_PositionOfPillars_tags_1,
	sizeof(asn_DEF_PositionOfPillars_tags_1)
		/sizeof(asn_DEF_PositionOfPillars_tags_1[0]), /* 1 */
	asn_DEF_PositionOfPillars_tags_1,	/* Same as above */
	sizeof(asn_DEF_PositionOfPillars_tags_1)
		/sizeof(asn_DEF_PositionOfPillars_tags_1[0]), /* 1 */
	&asn_PER_type_PositionOfPillars_constr_1,
	asn_MBR_PositionOfPillars_1,
	1,	/* Single element */
	&asn_SPC_PositionOfPillars_specs_1	/* Additional specs */
};

