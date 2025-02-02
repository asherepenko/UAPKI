/*
 * Copyright (c) 2023, The UAPKI Project Authors.
 * Generated by asn1c-0.9.28 (http://lionet.info/asn1c)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 * 1. Redistributions of source code must retain the above copyright
 * notice, this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright
 * notice, this list of conditions and the following disclaimer in the
 * documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
 * IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
 * TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
 * PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include "CertTemplate.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/CertTemplate.c"

static asn_TYPE_member_t asn_MBR_CertTemplate_1[] = {
    { ATF_POINTER, 10, offsetof(struct CertTemplate, version),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &NativeInteger_desc,
        0,	/* No check because of -fno-constraints */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "version"
        },
    { ATF_POINTER, 9, offsetof(struct CertTemplate, serialNumber),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &INTEGER_desc,
        0,	/* No check because of -fno-constraints */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "serialNumber"
        },
    { ATF_POINTER, 8, offsetof(struct CertTemplate, signingAlg),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &AlgorithmIdentifier_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "signingAlg"
        },
    { ATF_POINTER, 7, offsetof(struct CertTemplate, issuer),
        (ASN_TAG_CLASS_CONTEXT | (3 << 2)),
        +1,	/* EXPLICIT tag at current level */
        &ANY_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "issuer"
        },
    { ATF_POINTER, 6, offsetof(struct CertTemplate, validity),
        (ASN_TAG_CLASS_CONTEXT | (4 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &OptionalValidity_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "validity"
        },
    { ATF_POINTER, 5, offsetof(struct CertTemplate, subject),
        (ASN_TAG_CLASS_CONTEXT | (5 << 2)),
        +1,	/* EXPLICIT tag at current level */
        &ANY_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "subject"
        },
    { ATF_POINTER, 4, offsetof(struct CertTemplate, publicKey),
        (ASN_TAG_CLASS_CONTEXT | (6 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &SubjectPublicKeyInfo_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "publicKey"
        },
    { ATF_POINTER, 3, offsetof(struct CertTemplate, issuerUID),
        (ASN_TAG_CLASS_CONTEXT | (7 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &BIT_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "issuerUID"
        },
    { ATF_POINTER, 2, offsetof(struct CertTemplate, subjectUID),
        (ASN_TAG_CLASS_CONTEXT | (8 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &BIT_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "subjectUID"
        },
    { ATF_POINTER, 1, offsetof(struct CertTemplate, extensions),
        (ASN_TAG_CLASS_CONTEXT | (9 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &SequenceOfANY_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "extensions"
        },
};
static const ber_tlv_tag_t CertTemplate_desc_tags_1[] = {
    (ASN_TAG_CLASS_UNIVERSAL | (16 << 2))
};
static const asn_TYPE_tag2member_t asn_MAP_CertTemplate_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* version */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* serialNumber */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* signingAlg */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* issuer */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 }, /* validity */
    { (ASN_TAG_CLASS_CONTEXT | (5 << 2)), 5, 0, 0 }, /* subject */
    { (ASN_TAG_CLASS_CONTEXT | (6 << 2)), 6, 0, 0 }, /* publicKey */
    { (ASN_TAG_CLASS_CONTEXT | (7 << 2)), 7, 0, 0 }, /* issuerUID */
    { (ASN_TAG_CLASS_CONTEXT | (8 << 2)), 8, 0, 0 }, /* subjectUID */
    { (ASN_TAG_CLASS_CONTEXT | (9 << 2)), 9, 0, 0 } /* extensions */
};
static asn_SEQUENCE_specifics_t asn_SPC_CertTemplate_specs_1 = {
    sizeof(struct CertTemplate),
    offsetof(struct CertTemplate, _asn_ctx),
    asn_MAP_CertTemplate_tag2el_1,
    10,	/* Count of tags in the map */
    0, 0, 0,	/* Optional elements (not needed) */
    -1,	/* Start extensions */
    -1	/* Stop extensions */
};
asn_TYPE_descriptor_t CertTemplate_desc = {
    "CertTemplate",
    "CertTemplate",
    SEQUENCE_free,
    SEQUENCE_print,
    SEQUENCE_constraint,
    SEQUENCE_decode_ber,
    SEQUENCE_encode_der,
    SEQUENCE_decode_xer,
    SEQUENCE_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    0,	/* Use generic outmost tag fetcher */
    CertTemplate_desc_tags_1,
    sizeof(CertTemplate_desc_tags_1)
        /sizeof(CertTemplate_desc_tags_1[0]), /* 1 */
    CertTemplate_desc_tags_1,	/* Same as above */
    sizeof(CertTemplate_desc_tags_1)
        /sizeof(CertTemplate_desc_tags_1[0]), /* 1 */
    0,	/* No PER visible constraints */
    asn_MBR_CertTemplate_1,
    10,	/* Elements count */
    &asn_SPC_CertTemplate_specs_1	/* Additional specs */
};

asn_TYPE_descriptor_t* get_CertTemplate_desc(void)
{
    return &CertTemplate_desc;
}
