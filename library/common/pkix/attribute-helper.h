//  Last update: 2022-11-06

#ifndef UAPKI_NS_ATTRIBUTE_HELPER_H
#define UAPKI_NS_ATTRIBUTE_HELPER_H


#include "uapki-ns.h"
#include "byte-array.h"
#include "CompleteRevocationRefs.h"
#include "CrlOcspRef.h"
#include "RevocationValues.h"
#include <vector>


namespace UapkiNS {

    struct AttrCertId {
        UapkiNS::AlgorithmIdentifier
                    hashAlgorithm;
        ByteArray*  baHashValue;
        struct IssuerSerial {
            ByteArray*  baIssuer;
            ByteArray*  baSerialNumber;
            IssuerSerial (void)
                : baIssuer(nullptr), baSerialNumber(nullptr) {
            }
            ~IssuerSerial (void) {
                ba_free(baIssuer);
                ba_free(baSerialNumber);
            }
            bool isPresent (void) const {
                return (baIssuer && baSerialNumber);
            }
        }           issuerSerial;

        AttrCertId (void)
            : baHashValue(nullptr) {
        }
        ~AttrCertId (void) {
            ba_free(baHashValue);
        }
        bool isPresent (void) const {
            return (hashAlgorithm.isPresent() && baHashValue);
        }
    };  //  end struct AttrCertId

    using EssCertId = AttrCertId;
    using OtherCertId = AttrCertId;

namespace AttributeHelper {

    int decodeCertValues (const ByteArray* baEncoded, std::vector<ByteArray*>& certValues);
    int decodeCertificateRefs (const ByteArray* baEncoded, std::vector<OtherCertId>& otherCertIds);
    int decodeContentType (const ByteArray* baEncoded, std::string& contentType);
    int decodeMessageDigest (const ByteArray* baEncoded, ByteArray** baMessageDigest);
    int decodeSignaturePolicy (const ByteArray* baEncoded, std::string& sigPolicyId);
    int decodeSigningCertificate (const ByteArray* baEncoded, std::vector<EssCertId>& essCertIds);
    int decodeSigningTime (const ByteArray* baEncoded, uint64_t& signingTime);

    int encodeCertValues (const std::vector<const ByteArray*>& certValues, ByteArray** baEncoded);
    int encodeCertificateRefs (const std::vector<OtherCertId>& otherCertIds, ByteArray** baEncoded);
    int encodeSignaturePolicy (const std::string& sigPolicyId, ByteArray** baEncoded);
    int encodeSigningCertificate (const std::vector<EssCertId>& essCertIds, ByteArray** baEncoded);

    class RevocationRefsBuilder {
    public:
        class CrlOcspRef {
            CrlOcspRef_t*
                        m_RefCrlOcspRef;

        public:
            CrlOcspRef (CrlOcspRef_t* iRefCrlOcspRef);
            ~CrlOcspRef (void);

            int addCrlValidatedId (const ByteArray* baCrlHash, const ByteArray* baCrlIdentifier = nullptr);//TODO: param baCrlIdentifier need check
            int addOcspResponseId (const ByteArray* baOcspIdentifier, const ByteArray* baOcspRespHash = nullptr);
            int setOtherRevRefs (const char* otherRevRefType, const ByteArray* baOtherRevRefs);
            int setOtherRevRefs (const std::string& otherRevRefType, const ByteArray* baOtherRevRefs);

        };  //  end class CrlOcspRef

    private:
        CompleteRevocationRefs_t*
                    m_RevRefs;
        std::vector<CrlOcspRef*>
                    m_CrlOcspRefs;
        ByteArray*  m_BaEncoded;

    public:
        RevocationRefsBuilder (void);
        ~RevocationRefsBuilder (void);

        int init (void);
        int addCrlOcspRef (void);
        CrlOcspRef* getCrlOcspRef (const size_t index = 0) const;

        int encode (void);
        ByteArray* getEncoded (const bool move = false);

    };  //  end class RevocationRefsBuilder

    class RevocationRefsParser {
    public:
        struct CrlOcspId {
            ByteArray*  baHash;
            ByteArray*  baId;
            CrlOcspId (void)
            : baHash(nullptr), baId(nullptr) {}
            ~CrlOcspId(void) {
                ba_free(baHash);
                ba_free(baId);
            }
            bool isPresentHash (void) const {
                return (baHash);
            }
            bool isPresentId (void) const {
                return (baId);
            }
        };  //  end struct CrlOcspId

        class CrlOcspRef {
            std::vector<CrlOcspId>
                        m_CrlIds;
            std::vector<CrlOcspId>
                        m_OcspIds;
            Attribute   m_OtherRevRefs;

        public:
            CrlOcspRef (void);
            ~CrlOcspRef (void);

            int parse (const CrlOcspRef_t& crlOcspRef);

            const std::vector<CrlOcspId>& getCrlIds (void) const { return m_CrlIds; }
            const std::vector<CrlOcspId>& getOcspIds (void) const { return m_OcspIds; }
            const Attribute& getOtherRevRefs (void) const { return m_OtherRevRefs; }

        };  //  end class CrlOcspRef

    private:
        CompleteRevocationRefs_t*
                    m_RevRefs;
        size_t      m_CountCrlOcspRefs;

    public:
        RevocationRefsParser (void);
        ~RevocationRefsParser (void);

        int parse (const ByteArray* baEncoded);
        int parseCrlOcspRef (const size_t index, CrlOcspRef& crlOcspRef);

        const size_t getCountCrlOcspRefs (void) const { return m_CountCrlOcspRefs; }

    };  //  end class RevocationRefsParser

    class RevocationValuesBuilder {
    private:
        RevocationValues_t*
                    m_RevValues;
        ByteArray*  m_BaEncoded;

    public:
        RevocationValuesBuilder (void);
        ~RevocationValuesBuilder (void);

        int init (void);
        int addCrl (const ByteArray* baCrlEncoded);
        int addOcspResponse (const ByteArray* baBasicOcspResponse);
        int setOtherRevVals (const char* otherRevValType, const ByteArray* baOtherRevVals);
        int setOtherRevVals (const std::string& otherRevValType, const ByteArray* baOtherRevVals);

        int encode (void);
        ByteArray* getEncoded (const bool move = false);

    };  //  end class RevocationValuesBuilder

    class RevocationValuesParser {
        VectorBA    m_CrlVals;
        VectorBA    m_OcspVals;
        Attribute   m_OtherRevVals;

    public:
        RevocationValuesParser (void);
        ~RevocationValuesParser (void);

        int parse (const ByteArray* baEncoded);

        const VectorBA& getCrlVals (void) const { return m_CrlVals; }
        const VectorBA& getOcspVals (void) const { return m_OcspVals; }
        const Attribute& getOtherRevVals (void) const { return m_OtherRevVals; }

    };  //  end class RevocationValuesParser

}   //  end namespace AttributeHelper

}   //  end namespace UapkiNS


#endif
