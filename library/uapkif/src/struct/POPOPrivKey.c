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

#include "POPOPrivKey.h"

#include "asn_internal.h"

#undef FILE_MARKER
#define FILE_MARKER "pkix/struct/POPOPrivKey.c"

static asn_TYPE_member_t asn_MBR_POPOPrivKey_1[] = {
    { ATF_NOFLAGS, 0, offsetof(struct POPOPrivKey, choice.thisMessage),
        (ASN_TAG_CLASS_CONTEXT | (0 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &BIT_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "thisMessage"
        },
    { ATF_NOFLAGS, 0, offsetof(struct POPOPrivKey, choice.subsequentMessage),
        (ASN_TAG_CLASS_CONTEXT | (1 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &NativeInteger_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "subsequentMessage"
        },
    { ATF_NOFLAGS, 0, offsetof(struct POPOPrivKey, choice.dhMAC),
        (ASN_TAG_CLASS_CONTEXT | (2 << 2)),
        (ber_tlv_tag_t)-1,	/* IMPLICIT tag at current level */
        &BIT_STRING_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "dhMAC"
        },
    { ATF_NOFLAGS, 0, offsetof(struct POPOPrivKey, choice.agreeMAC),
        (ASN_TAG_CLASS_CONTEXT | (3 << 2)),
        +1,	/* EXPLICIT tag at current level */
        &ANY_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "agreeMAC"
        },
    { ATF_NOFLAGS, 0, offsetof(struct POPOPrivKey, choice.encryptedKey),
        (ASN_TAG_CLASS_CONTEXT | (4 << 2)),
        +1,	/* EXPLICIT tag at current level */
        &ANY_desc,
        0,	/* Defer constraints checking to the member type */
        0,	/* PER is not compiled, use -gen-PER */
        0,
        "encryptedKey"
        },
};
static const asn_TYPE_tag2member_t asn_MAP_POPOPrivKey_tag2el_1[] = {
    { (ASN_TAG_CLASS_CONTEXT | (0 << 2)), 0, 0, 0 }, /* thisMessage */
    { (ASN_TAG_CLASS_CONTEXT | (1 << 2)), 1, 0, 0 }, /* subsequentMessage */
    { (ASN_TAG_CLASS_CONTEXT | (2 << 2)), 2, 0, 0 }, /* dhMAC */
    { (ASN_TAG_CLASS_CONTEXT | (3 << 2)), 3, 0, 0 }, /* agreeMAC */
    { (ASN_TAG_CLASS_CONTEXT | (4 << 2)), 4, 0, 0 } /* encryptedKey */
};
static asn_CHOICE_specifics_t asn_SPC_POPOPrivKey_specs_1 = {
    sizeof(struct POPOPrivKey),
    offsetof(struct POPOPrivKey, _asn_ctx),
    offsetof(struct POPOPrivKey, present),
    sizeof(((struct POPOPrivKey *)0)->present),
    asn_MAP_POPOPrivKey_tag2el_1,
    5,	/* Count of tags in the map */
    0,
    -1	/* Extensions start */
};
asn_TYPE_descriptor_t POPOPrivKey_desc = {
    "POPOPrivKey",
    "POPOPrivKey",
    CHOICE_free,
    CHOICE_print,
    CHOICE_constraint,
    CHOICE_decode_ber,
    CHOICE_encode_der,
    CHOICE_decode_xer,
    CHOICE_encode_xer,
    0, 0,	/* No PER support, use "-gen-PER" to enable */
    CHOICE_outmost_tag,
    0,	/* No effective tags (pointer) */
    0,	/* No effective tags (count) */
    0,	/* No tags (pointer) */
    0,	/* No tags (count) */
    0,	/* No PER visible constraints */
    asn_MBR_POPOPrivKey_1,
    5,	/* Elements count */
    &asn_SPC_POPOPrivKey_specs_1	/* Additional specs */
};

asn_TYPE_descriptor_t* get_POPOPrivKey_desc(void)
{
    return &POPOPrivKey_desc;
}
