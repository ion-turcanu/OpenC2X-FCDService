/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "CAM-PDU-Descriptions"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "DangerousGoodsContainer.h"

static asn_TYPE_member_t asn_MBR_DangerousGoodsContainer_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DangerousGoodsContainer, dangerousGoodsBasic),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DangerousGoodsBasic,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dangerousGoodsBasic"
		},
};
static ber_tlv_tag_t asn_DEF_DangerousGoodsContainer_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_DangerousGoodsContainer_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 } /* dangerousGoodsBasic at 226 */
};
static asn_SEQUENCE_specifics_t asn_SPC_DangerousGoodsContainer_specs_1 = {
	sizeof(struct DangerousGoodsContainer),
	offsetof(struct DangerousGoodsContainer, _asn_ctx),
	asn_MAP_DangerousGoodsContainer_tag2el_1,
	1,	/* Count of tags in the map */
	0, 0, 0,	/* Optional elements (not needed) */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DangerousGoodsContainer = {
	"DangerousGoodsContainer",
	"DangerousGoodsContainer",
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
	asn_DEF_DangerousGoodsContainer_tags_1,
	sizeof(asn_DEF_DangerousGoodsContainer_tags_1)
		/sizeof(asn_DEF_DangerousGoodsContainer_tags_1[0]), /* 1 */
	asn_DEF_DangerousGoodsContainer_tags_1,	/* Same as above */
	sizeof(asn_DEF_DangerousGoodsContainer_tags_1)
		/sizeof(asn_DEF_DangerousGoodsContainer_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DangerousGoodsContainer_1,
	1,	/* Elements count */
	&asn_SPC_DangerousGoodsContainer_specs_1	/* Additional specs */
};

