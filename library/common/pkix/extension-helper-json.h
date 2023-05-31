/*
 * Copyright (c) 2023, The UAPKI Project Authors.
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

#ifndef UAPKI_EXTENSION_HELPER_JSON_H
#define UAPKI_EXTENSION_HELPER_JSON_H


#include "byte-array.h"
#include "parson.h"


namespace UapkiNS {

namespace ExtensionHelper {

namespace DecodeToJsonObject {

    int accessDescriptions          (const ByteArray* baEncoded, JSON_Object* joResult);
    int alternativeName             (const ByteArray* baEncoded, JSON_Object* joResult);
    int authorityKeyId              (const ByteArray* baEncoded, JSON_Object* joResult, ByteArray** baKeyId);
    int basicConstraints            (const ByteArray* baEncoded, JSON_Object* joResult);
    int certificatePolicies         (const ByteArray* baEncoded, JSON_Object* joResult);
    int distributionPoints          (const ByteArray* baEncoded, JSON_Object* joResult);
    int extendedKeyUsage            (const ByteArray* baEncoded, JSON_Object* joResult);
    int keyUsage                    (const ByteArray* baEncoded, JSON_Object* joResult);
    int qcStatements                (const ByteArray* baEncoded, JSON_Object* joResult);
    int subjectDirectoryAttributes  (const ByteArray* baEncoded, JSON_Object* joResult);
    int subjectKeyId                (const ByteArray* baEncoded, JSON_Object* joResult, ByteArray** baKeyId);

}   //  end namespace DecodeToJsonObject

}   //  end namespace ExtensionHelper

}   //  end namespace UapkiNS


#endif
