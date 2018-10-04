/*
 * Generated by asn1c-0.9.24 (http://lionet.info/asn1c)
 * From ASN.1 module "ITS-Container"
 * 	found in "its_facilities_pdu_all.asn"
 * 	`asn1c -fnative-types -gen-PER`
 */

#include "DangerousGoodsExtended.h"

static int check_permitted_alphabet_7(const void *sptr) {
	/* The underlying type is IA5String */
	const IA5String_t *st = (const IA5String_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!(cv <= 127)) return -1;
	}
	return 0;
}

static int check_permitted_alphabet_8(const void *sptr) {
	/* The underlying type is IA5String */
	const IA5String_t *st = (const IA5String_t *)sptr;
	const uint8_t *ch = st->buf;
	const uint8_t *end = ch + st->size;
	
	for(; ch < end; ch++) {
		uint8_t cv = *ch;
		if(!(cv <= 127)) return -1;
	}
	return 0;
}

static int
memb_unNumber_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	long value;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	value = *(const long *)sptr;
	
	if((value >= 0 && value <= 9999)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_emergencyActionCode_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const IA5String_t *st = (const IA5String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 24)
		 && !check_permitted_alphabet_7(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_phoneNumber_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const IA5String_t *st = (const IA5String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = st->size;
	
	if((size >= 1 && size <= 24)
		 && !check_permitted_alphabet_8(st)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static int
memb_companyName_constraint_1(asn_TYPE_descriptor_t *td, const void *sptr,
			asn_app_constraint_failed_f *ctfailcb, void *app_key) {
	const UTF8String_t *st = (const UTF8String_t *)sptr;
	size_t size;
	
	if(!sptr) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: value not given (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	size = UTF8String_length(st);
	if((ssize_t)size < 0) {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: UTF-8: broken encoding (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
	
	if((size >= 1 && size <= 24)) {
		/* Constraint check succeeded */
		return 0;
	} else {
		_ASN_CTFAIL(app_key, td, sptr,
			"%s: constraint failed (%s:%d)",
			td->name, __FILE__, __LINE__);
		return -1;
	}
}

static asn_per_constraints_t asn_PER_memb_unNumber_constr_3 = {
	{ APC_CONSTRAINED,	 14,  14,  0,  9999 }	/* (0..9999) */,
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_per_constraints_t asn_PER_memb_emergencyActionCode_constr_7 = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_CONSTRAINED,	 5,  5,  1,  24 }	/* (SIZE(1..24)) */,
	0, 0	/* No PER character map necessary */
};
static asn_per_constraints_t asn_PER_memb_phoneNumber_constr_8 = {
	{ APC_CONSTRAINED,	 7,  7,  0,  127 }	/* (0..127) */,
	{ APC_CONSTRAINED,	 5,  5,  1,  24 }	/* (SIZE(1..24)) */,
	0, 0	/* No PER character map necessary */
};
static asn_per_constraints_t asn_PER_memb_companyName_constr_9 = {
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	{ APC_UNCONSTRAINED,	-1, -1,  0,  0 },
	0, 0	/* No PER value map */
};
static asn_TYPE_member_t asn_MBR_DangerousGoodsExtended_1[] = {
	{ ATF_NOFLAGS, 0, offsetof(struct DangerousGoodsExtended, dangerousGoodsType),
		(ASN_TAG_CLASS_CONTEXT | (0 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_DangerousGoodsBasic,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"dangerousGoodsType"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DangerousGoodsExtended, unNumber),
		(ASN_TAG_CLASS_CONTEXT | (1 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_NativeInteger,
		memb_unNumber_constraint_1,
		&asn_PER_memb_unNumber_constr_3,
		0,
		"unNumber"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DangerousGoodsExtended, elevatedTemperature),
		(ASN_TAG_CLASS_CONTEXT | (2 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"elevatedTemperature"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DangerousGoodsExtended, tunnelsRestricted),
		(ASN_TAG_CLASS_CONTEXT | (3 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"tunnelsRestricted"
		},
	{ ATF_NOFLAGS, 0, offsetof(struct DangerousGoodsExtended, limitedQuantity),
		(ASN_TAG_CLASS_CONTEXT | (4 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_BOOLEAN,
		0,	/* Defer constraints checking to the member type */
		0,	/* No PER visible constraints */
		0,
		"limitedQuantity"
		},
	{ ATF_POINTER, 3, offsetof(struct DangerousGoodsExtended, emergencyActionCode),
		(ASN_TAG_CLASS_CONTEXT | (5 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IA5String,
		memb_emergencyActionCode_constraint_1,
		&asn_PER_memb_emergencyActionCode_constr_7,
		0,
		"emergencyActionCode"
		},
	{ ATF_POINTER, 2, offsetof(struct DangerousGoodsExtended, phoneNumber),
		(ASN_TAG_CLASS_CONTEXT | (6 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_IA5String,
		memb_phoneNumber_constraint_1,
		&asn_PER_memb_phoneNumber_constr_8,
		0,
		"phoneNumber"
		},
	{ ATF_POINTER, 1, offsetof(struct DangerousGoodsExtended, companyName),
		(ASN_TAG_CLASS_CONTEXT | (7 << 2)),
		-1,	/* IMPLICIT tag at current level */
		&asn_DEF_UTF8String,
		memb_companyName_constraint_1,
		&asn_PER_memb_companyName_constr_9,
		0,
		"companyName"
		},
};
static int asn_MAP_DangerousGoodsExtended_oms_1[] = { 5, 6, 7 };
static ber_tlv_tag_t asn_DEF_DangerousGoodsExtended_tags_1[] = {
	(ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static asn_TYPE_tag2member_t asn_MAP_DangerousGoodsExtended_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* dangerousGoodsType at 923 */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* unNumber at 924 */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* elevatedTemperature at 925 */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* tunnelsRestricted at 926 */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* limitedQuantity at 927 */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* emergencyActionCode at 928 */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* phoneNumber at 929 */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 } /* companyName at 930 */
};
static asn_SEQUENCE_specifics_t asn_SPC_DangerousGoodsExtended_specs_1 = {
	sizeof(struct DangerousGoodsExtended),
	offsetof(struct DangerousGoodsExtended, _asn_ctx),
	asn_MAP_DangerousGoodsExtended_tag2el_1,
	8,	/* Count of tags in the map */
	asn_MAP_DangerousGoodsExtended_oms_1,	/* Optional members */
	3, 0,	/* Root/Additions */
	-1,	/* Start extensions */
	-1	/* Stop extensions */
};
asn_TYPE_descriptor_t asn_DEF_DangerousGoodsExtended = {
	"DangerousGoodsExtended",
	"DangerousGoodsExtended",
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
	asn_DEF_DangerousGoodsExtended_tags_1,
	sizeof(asn_DEF_DangerousGoodsExtended_tags_1)
		/sizeof(asn_DEF_DangerousGoodsExtended_tags_1[0]), /* 1 */
	asn_DEF_DangerousGoodsExtended_tags_1,	/* Same as above */
	sizeof(asn_DEF_DangerousGoodsExtended_tags_1)
		/sizeof(asn_DEF_DangerousGoodsExtended_tags_1[0]), /* 1 */
	0,	/* No PER visible constraints */
	asn_MBR_DangerousGoodsExtended_1,
	8,	/* Elements count */
	&asn_SPC_DangerousGoodsExtended_specs_1	/* Additional specs */
};

