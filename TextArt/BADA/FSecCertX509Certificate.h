/* $Change: 1142016 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/** 
 * @file		FSecCertX509Certificate.h
 * @brief		This is the header file for the %X509Certificate class.
 *
 * This header file contains the declarations of the %X509Certificate class.
 */
#ifndef _FSEC_CERT_X509_CERTIFICATE_H_
#define _FSEC_CERT_X509_CERTIFICATE_H_

// Includes
#include "FBase.h"
#include "FSecConfig.h"
#include "FSecCertICertificate.h"


namespace Osp { namespace Security { namespace Cert {

class ICertificatePi;

/**
 * @class	X509Certificate 
 * @brief	This class is used for managing a variety of identity certificates.
 * @since	1.0
 * 
 * The %X509Certificate class is used for managing a variety of identity certificates.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/certificate_namespace.htm">Certificates</a>.
 *	
 * @see		ICertificate
 */
class _EXPORT_SECURITY_ X509Certificate:
	public virtual ICertificate,
	public Osp::Base::Object
{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */	
	X509Certificate(void);


	/** 
	 * This is the destructor for this class. 
	 *
	 * @since		1.0
	 */	
	~X509Certificate(void);


// Operation
public:
	/** 
	 * Initializes this instance of X509Certificate with the specified input buffer.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	input				The input %ByteBuffer instance
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result	Construct(const Osp::Base::ByteBuffer& input);


	/** 
	 * Gets the format name for this certificate.
	 *
	 * @since		1.0
	 * @return		The format of this certificate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual Osp::Base::String GetFormat(void) const;


	/**
	 * Gets the certificate type.
	 *	
	 * @since		1.0
	 * @return 		The certificate type
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.

	 */
	virtual CertificateType GetType(void) const;


	/** 
	 * Gets the encoded form of the certificate. @n
	 * It is assumed that each certificate type will have only a single form of encoding. For example, X.509 certificates will be encoded as ASN.1 DER.
	 *
	 * @since		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The certificate is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetEncodedDataN(void) const;


	/** 
	 * Gets the fingerprint of the certificate. @n
	 * It is the hashed value of the encoding of the certificate.
	 *
	 * @since		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetFingerprintN(void) const;


	/** 
	 * Verifies whether the certificate is signed using the private key that corresponds to the specified public key. 
	 *
	 * @since		1.0
	 * @return		@c true if the certificate is signed using the private key that corresponds to the specified public key, @n
	 *				else @c false
	 * @param[in]	publicKey			A reference to IPublicKey
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The specified @c publicKey is invalid or empty.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual bool Verify(const Osp::Security::IPublicKey& publicKey);


// Basic Fields

	/** 
	 * Gets the public key of this certificate.
	 *
	 * @since		1.0
	 * @return		A pointer to %IPublicKey, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND		The key is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Security::IPublicKey*	GetPublicKeyN(void) const;


	// (X.509 only, that is, not inherited from the ICertificate interface)
	/** 
	 * Gets the specification version value (version number) from the certificate. @n
	 * The ASN.1 definition for this is as follows: 
	 *
	 * <pre>
	 * version  [0] EXPLICIT Version DEFAULT v1
	 * Version ::=  INTEGER  {  v1(0), v2(1), v3(2)  }
	 * </pre>
	 *
	 * @since		1.0
	 * @return		The version number of the X.509 certificate (that is, 1, 2, or 3)
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	int GetSpecVersion(void);	


	/**
	 * Gets the serial number value from the certificate. @n
	 * The serial number is an integer assigned by the Certification Authority (CA) to each certificate. It is unique for each certificate issued by a given 
	 * CA (that is, the issuer name and serial number must identify a unique certificate). @n
	 * The ASN.1 definition for this is as follows: 
	 *
	 * <pre>
	 * serialNumber     CertificateSerialNumber
	 *	
	 * CertificateSerialNumber  ::=  INTEGER
	 * </pre>		@n
	 *
	 * This serial number can be greater than the system's maximum defined value for @c int, the output parameter type is @c ByteBuffer, instead of @c int.
	 *
	 * @since		1.0
	 * @return		The serial number of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::String	GetSerialNumber(void) const;


	/** 
	 * Checks whether the certificate is currently valid. @n
	 * It is valid if the current date and time are within the validity period given in the certificate. The validity period consists of two date and time 
	 * values: the initial date and time, and the final date and time until the validity of the certificate. @n
	 * It is defined in ASN.1 as: 
	 *
	 *  <pre>
	 *	validity             Validity
	 *
	 *	Validity ::= SEQUENCE {
     *		notBefore      CertificateValidityDate,
     *		notAfter       CertificateValidityDate }
	 *
	 *	CertificateValidityDate ::= CHOICE {
     *		utcTime        UTCTime,
     *		generalTime    GeneralizedTime }
	 *  </pre> @n
	 *
	 * @since		1.0
	 * @return		The validity period of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual ValidityPeriod	CheckValidityPeriod(void);


	/** 
	 *  Gets the notBefore value of @c String type from the validity period of the certificate. @n
	 *	This value represents the date and time before which the certificate is not valid.
	 *
	 * @since		1.0
	 * @return		A string representing the date and time value before which the certificate is not valid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @see			Osp::Security::Cert::X509Certificate::CheckValidityPeriod(void) for relevant ASN.1 definitions.   
	 */
	virtual Osp::Base::String	GetNotBefore(void) const;


	/** 
	 *	Gets the notAfter value of @c String type from the validity period of the certificate. @n
	 *	This value represents the date and time after which the certificate is not valid.
	 *
	 * @since		1.0
	 * @return		A string representing the date and time value after which the certificate is not valid
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 *
	 * @see			Osp::Security::Cert::X509Certificate::CheckValidityPeriod(void) for relevant ASN.1 definitions.   
	 */
	virtual Osp::Base::String	GetNotAfter(void) const;


	/**
	 * Gets the name of the issuer of the certificate.
	 *
	 * @since		1.0
	 * @return		The name of the issuer of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::String	GetIssuer(void) const;


	/**
	 * Gets the subject name of the certificate.
	 *
	 * @since		1.0
	 * @return		The subject name of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::String	GetSubject(void) const;


	/**
	 * Gets the signature algorithm identifier from the given certificate. For example, the string "SHA-1/DSA". @n
	 * The ASN.1 definition for this is as follows: 
	 *
	 *  <pre>
	 *	signatureAlgorithm   AlgorithmIdentifier
	 *		AlgorithmIdentifier  ::=  SEQUENCE  {
     *		algorithm               OBJECT IDENTIFIER,
     *		parameters              ANY DEFINED BY algorithm OPTIONAL  }
     *		                        - contains a value of the type
     *		                        - registered for use with the
     *		                        - algorithm object identifier value
	 *  </pre>		@n
	 *
	 * The algorithm name is determined from the algorithm OID string. 
	 *
	 * @since		1.0
	 * @return		The signature algorithm of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	Osp::Base::String	GetSignatureAlgorithm(void) const;


	/**
	 * Gets the signature of the certificate.
	 *
	 * @since		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetSignatureN(void) const;


private:
	ICertificatePi			*m_pCertPi;
	friend class 			X509CertificateEx;
	class X509CertificateEx*	__pX509CertificateEx;



};
}; }; }; // Osp::Security::Cert

#endif // _FSEC_CERT_X509_CERTIFICATE_H_

