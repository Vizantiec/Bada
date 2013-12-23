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
 * @file		FSecCertICertificate.h
 * @brief		This is the header file for the %ICertificate interface.
 *
 * This header file contains the declarations of the %ICertificate interface. 
 */
#ifndef _FSEC_CERT_ICERTIFICATE_H_
#define _FSEC_CERT_ICERTIFICATE_H_


// Includes
#include "FBaseString.h"
#include "FBaseByteBuffer.h"
#include "FSecConfig.h"
//#include "FSecCertISubjectPublicKeyInfo.h"
#include "FSecIPublicKey.h"


namespace Osp { namespace Security { namespace Cert {
/**
 * @enum CertificateType
 * Defines the type of certificate.
 * 
 *
 * @since		1.0
 */
enum CertificateType 
{
	ROOT_CA,					/**< The Factory-supplied certificates for SSL: ROOT CA */
	OPERATOR_DOMAIN,			/**< The Operator Domain */
	TRUSTED_THIRD_PARTY_DOMAIN,	/**< The Trusted Third Party Domain */
	UNKNOWN_TYPE = 10,          /**< The unknown type */
};


/**
 * @enum ValidityPeriod
 * Defines the validity period.
 *
 * @since		1.0
 */
enum ValidityPeriod
{
	VALIDITY_PERIOD_VALID,				/**< The validity period */
	VALIDITY_PERIOD_EXPIRED,			/**< The expiry period */
	VALIDITY_PERIOD_NOT_YET_VALID,		/**< The period that is not yet valid */
};


/**
 * @interface	ICertificate 
 * @brief		This interface manages a variety of identity certificates.
 * @since		1.0
 *
 *
 * The %ICertificate interface is an abstraction for certificates having different formats. For example, different types of certificates, such as X.509 and PGP, share 
 * general functionalities, namely encoding and verifying, and some type of information like public keys. Despite containing different sets of information and having different ways for storing, and retrieving them, 
 * the X.509, X.968, and WTLS certificates can all be implemented by using the %ICertificate interface. 
 *
 * An identity certificate is a binding of a principal to a public key, which is vouched for by another principal.
 * A principal represents an entity, such as an individual user, a group, or a corporation. 
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/certificate_namespace.htm">Certificates</a>.
 *
 * The following example demonstrates how to use the %ICertificate interface. 

 *
 *  @code
 *
 *  void
 *  MyCertificate::Sample()
 *  {
 *		X509Certificate	*pCertificate	= null;
 *		String			certificateFormat	= "X509";
 *		String			serialNumber;
 *		String			algorithm;
 *		String			start;
 *		String			end;
 *		String			subjectName;
 *		String			issuerName;
 *		ByteBuffer		*pSignature = null;
 *		ByteBuffer		*pFingerprint = null;
 *		ByteBuffer		input;
 *		result			r = E_FAILURE;
 *
 *		String fileName(L"/Home/UTsSecurity/Security/Domain3Certs/TestCert1-1.der");
 *		File			file;
 *		FileAttributes	attribute;
 *
 *		r = file.Construct(fileName, L"r");
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = file.GetAttributes(fileName, attribute);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = input.Construct((int)attribute.GetFileSize());
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = file.Read(input);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		input.Flip();
 *	
 *		pCertificate	= new X509Certificate;
 *		pCertificate->Construct(input);
 *	
 *		serialNumber	= pCertificate->GetSerialNumber();
 *		algorithm		= pCertificate->GetSignatureAlgorithm();
 *		start			= pCertificate->GetNotBefore();
 *		end				= pCertificate->GetNotAfter();
 *		subjectName		= pCertificate->GetSubject();
 *		issuerName		= pCertificate->GetIssuer();
 *
 *		pSignature = pCertificate->GetSignatureN();
 *		if (pSignature == null)
 *			goto CATCH;
 *
 *		pFingerprint = pCertificate->GetFingerprintN();
 *		if (pFingerprint == null)
 *			goto CATCH;
 *	
 *		r = E_SUCCESS;
 *	
 *	CATCH:
 *		if (pCertificate)
 *			delete pCertificate;
 *		if (pSignature)
 *			delete pSignature;
 *		if (pFingerprint)
 *			delete pFingerprint;
 *		if (pCertificate)
 *			delete pCertificate;
 *	}
 *
 *  @endcode
 *
 */
class _EXPORT_SECURITY_ ICertificate
{
// Lifecycle
public:
	/** 
	 * This is the destructor for this class. 
	 *
	 * @since		1.0
	 */	
	virtual ~ICertificate(void) {}


// Operation
public:
	/** 
	 * Gets the format name for this certificate.
	 *
	 * @since		1.0
	 * @return		The format of this certificate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual Osp::Base::String	GetFormat(void) const = 0;


	/**
	 * Gets the certificate type.
	 *	
	 * @since		1.0
	 * @return 		The type of this certificate
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_SYSTEM		A system error has occurred.
	 */
	virtual CertificateType	GetType(void) const  = 0;

	
	/** 
	 * Gets the encoded form of the certificate. @n
	 * It is assumed that each certificate type has a single form of encoding. For example, X.509 certificates can be encoded as ASN.1 DER.
	 *
	 * @since		1.0
	 * @return		A pointer to the %ByteBuffer class that contains the output, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_OBJ_NOT_FOUND		The certificate is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::ByteBuffer*	GetEncodedDataN(void) const	= 0;
	

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
	virtual Osp::Base::ByteBuffer*	GetFingerprintN(void) const = 0;


	/** 
	 *  Verifies whether the certificate is signed using the private key corresponding to the specified public key. 
	 *
	 *	@since		1.0
	 *	@return		@c true if the certificate is signed using the private key corresponding to the specified public key, @n
	 *				else @c false
	 *	@param[in]	publicKey			A reference to %IPublicKey
	 *	@exception	E_SUCCESS			The method is successful.
	 *	@exception	E_INVALID_ARG		The specified @c publicKey is invalid or empty.
	 *	@exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 *	@exception	E_SYSTEM			A system error has occurred.
	 */
	virtual bool Verify(const Osp::Security::IPublicKey& publicKey)  = 0;


	/** 
	 * Gets the public key of this certificate.
	 *
	 * @since		1.0
	 * @return		A pointer to the %IPublicKey class, @n
	 *				else @c null if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_KEY_NOT_FOUND		The key is not found.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Security::IPublicKey* GetPublicKeyN(void) const	= 0;


	/**
	 * Gets the @c serialNumber value from the certificate. @n
	 * The serial number is an integer assigned by the certification authority (CA) to each certificate. It is unique for each certificate issued by a 
	 * given CA (that is, the issuer name and serial number must identify a unique certificate). @n
	 * The ASN.1 definition for this is as follows: 
	 *
	 *	<pre>
	 *	serialNumber     CertificateSerialNumber
	 *	
	 *	CertificateSerialNumber  ::=  INTEGER
	 *  </pre> @n
	 *
	 * Since the serial number can be greater than the system's maximum value for @c int, the output parameter type is @c ByteBuffer, instead of @c int.
	 *
	 * @since		1.0
	 * @return		The serial number of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::String	GetSerialNumber(void) const	= 0;


	/** 
	 * Checks whether the certificate is currently valid. @n
	 * It is valid if the current date and time are within the validity period given in the certificate. @n
	 *
	 * The validity period consists of two date and time values: the initial date and time, and the final date and time until the validity of the certificate. @n
	 * It is defined in ASN.1 as: 
	 *
	 * <pre>
	 * validity             Validity
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
	virtual ValidityPeriod	CheckValidityPeriod(void) = 0;


	/** 
    * Gets the notBefore value of @c String type from the validity period of the certificate. @n
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
	virtual Osp::Base::String	GetNotBefore(void) const = 0;


	/** 
	 * Gets the notAfter value of @c String type from the validity period of the certificate. @n
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
	virtual Osp::Base::String	GetNotAfter(void) const = 0;


	/**
	 * Gets the name of the issuer of the certificate.
	 *
	 * @since		1.0
	 * @return		The name of the issuer of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::String	GetIssuer(void) const = 0;


	/**
	 * Gets the subject name of the certificate.
	 *
	 * @since		1.0
	 * @return		The subject name of the certificate
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	virtual Osp::Base::String	GetSubject(void) const = 0;


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
	virtual Osp::Base::ByteBuffer*	GetSignatureN(void) const = 0;

	
};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_ICERTIFICATE_H_
