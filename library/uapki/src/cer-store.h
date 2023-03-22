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

#ifndef UAPKI_CER_STORE_H
#define UAPKI_CER_STORE_H


#include "uapkic.h"
#include "uapkif.h"
#include "uapki-ns.h"
#include "attribute-helper.h"
#include "uapki-export.h"


//#define DEBUG_CERSTOREITEM_INFO


class CerStore {

public:
    enum class ValidationType : uint32_t {
        UNDEFINED   = 0,
        NONE        = 1,
        CHAIN       = 2,
        CRL         = 3,
        OCSP        = 4
    };  //  end enum ValidationType

    enum class VerifyStatus : uint32_t {
        UNDEFINED               = 0,
        INDETERMINATE           = 1,
        FAILED                  = 2,
        INVALID                 = 3,
        VALID_WITHOUT_KEYUSAGE  = 4,
        VALID                   = 5
    };  //  end enum VerifyStatus

    struct CertStatusInfo {
        const ValidationType
                    type;
        ByteArray*  baResult;
        UapkiNS::CertStatus
                    status;
        uint64_t    validTime;

        CertStatusInfo (
            const ValidationType validationType
        );
        ~CertStatusInfo (void);

        bool isExpired (
            const uint64_t time
        ) const;
        void reset (void);
        int set (
            const UapkiNS::CertStatus status,
            const uint64_t validTime,
            const ByteArray* baResult
        );

    };  //  end struct CertStatusInfo

    struct Item {
#ifdef DEBUG_CERSTOREITEM_INFO
        std::string devsSubject;
        std::string devsIssuerAndSn;
        std::string devsValidity;
#endif
        const ByteArray*
                    baEncoded;
        const Certificate_t*
                    cert;
        const ByteArray*
                    baAuthorityKeyId;
        const ByteArray*
                    baCertId;
        const char* keyAlgo;
        const ByteArray*
                    baSerialNumber;
        const ByteArray*
                    baKeyId;
        const ByteArray*
                    baIssuer;
        const ByteArray*
                    baSubject;
        const ByteArray*
                    baSPKI;
        HashAlg     algoKeyId;
        uint64_t    notBefore;
        uint64_t    notAfter;
        uint32_t    keyUsage;
        bool        trusted;
        VerifyStatus
                    verifyStatus;
        CertStatusInfo
                    certStatusByCrl;
        CertStatusInfo
                    certStatusByOcsp;

        Item (void);
        ~Item (void);

        int checkValidity (
            const uint64_t validateTime
        ) const;
        int generateEssCertId (
            const UapkiNS::AlgorithmIdentifier& aidDigest,
            UapkiNS::EssCertId& essCertId
        ) const;
        int getCrlUris (
            const bool isFull, std::vector<std::string>& uris
        ) const;
        int getIssuerAndSN (
            ByteArray** baIssuerAndSN
        ) const;
        int getOcspUris (
            std::vector<std::string>& uris
        ) const;
        int getTspUris (
            std::vector<std::string>& uris
        ) const;
        int keyUsageByBit (
            const uint32_t bitNum,
            bool& bitValue
        ) const;
        int verify (const CerStore::Item* cerIssuer);

    };  //  end struct Item

private:
    std::string m_Path;
    std::vector<Item*>
                m_Items;

public:
    CerStore (void);
    ~CerStore (void);

    int addCert (
        const ByteArray* baEncoded,
        const bool copyWithAlloc,
        const bool permanent,
        const bool trusted,
        bool& isUnique,
        Item** cerStoreItem
    );
    int getCertByCertId (
        const ByteArray* baCertId,
        Item** cerStoreItem
    );
    int getCertByEncoded (
        const ByteArray* baEncoded,
        Item** cerStoreItem
    );
    int getCertByIndex (
        const size_t index,
        Item** cerStoreItem
    );
    int getCertByIssuerAndSN (
        const ByteArray* baIssuer,
        const ByteArray* baSerialNumber,
        Item** cerStoreItem
    );
    int getCertByKeyId (
        const ByteArray* baKeyId,
        Item** cerStoreItem
    );
    int getCertBySID (
        const ByteArray* baSID,
        Item** cerStoreItem
    );
    int getCertBySPKI (
        const ByteArray* baSPKI,
        Item** cerStoreItem
    );
    int getCertBySubject (
        const ByteArray* baSubject,
        Item** cerStoreItem
    );
    int getChainCerts (
        const Item* cerSubject,
        std::vector<Item*>& chainCerts
    );
    int getChainCerts (
        const Item* cerSubject,
        std::vector<Item*>& chainCerts,
        const ByteArray** baIssuerKeyId
    );
    int getCount (
        size_t& count
    );
    int getCountTrusted (
        size_t& count
    );
    int getIssuerCert (
        const Item* cerSubject,
        Item** cerIssuer,
        bool& isSelfSigned
    );
    int load (
        const char* path
    );
    int reload (void);
    int removeCert (
        const ByteArray* baCertId,
        const bool permanent
    );
    void reset (void);

public:
    static bool addCertIfUnique (
        std::vector<Item*>& cerStoreItems,
        Item* cerStoreItem
    );
    static int calcKeyId (
        const HashAlg algoKeyId,
        const ByteArray* baPubkey,
        ByteArray** baKeyId
    );
    static int encodeIssuerAndSN (
        const ByteArray* baIssuer,
        const ByteArray* baSerialNumber,
        ByteArray** baIssuerAndSN
    );
    static Item* findCertByCertId (
        const std::vector<Item*>& cerStoreItems,
        const ByteArray* baCertId
    );
    static int generateEssCertId (
        const Item* cerStoreItem,
        const UapkiNS::AlgorithmIdentifier& aidDigest,
        UapkiNS::EssCertId& essCertId
    );
    static int issuerFromGeneralNames (
        const ByteArray* baEncoded,
        ByteArray** baIssuer
    );
    static int issuerToGeneralNames (
        const ByteArray* baIssuer,
        ByteArray** baEncoded
    );
    static int keyIdFromSid (
        const ByteArray* baSidEncoded,
        ByteArray** baKeyId
    );
    static int keyIdToSid (
        const ByteArray* baKeyId,
        ByteArray** baSidEncoded
    );
    static int parseCert (
        const ByteArray* baEncoded,
        Item** cerStoreItem
    );
    static int parseSid (
        const ByteArray* baSidEncoded,
        ByteArray** baIssuer,
        ByteArray** baSerialNumber,
        ByteArray** baKeyId
    );
    static ValidationType validationTypeFromStr (
        const std::string& validationType
    );
    static const char* verifyStatusToStr (
        const VerifyStatus status
    );

private:
    //  addItem - added unique item, return new-item or exists-item
    Item* addItem (
        Item* cerStoreItem
    );
    int loadDir (void);
    int saveToFile (
        const Item* cerStoreItem
    );

public:
    void saveStatToLog (
        const std::string& message
    );

};  //  end class CerStore


#endif
