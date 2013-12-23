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
 * @file		FSecCertICertificatePath.h
 * @brief		This is the header file for the %ICertificatePath interface.
 *
 * This header file contains the declarations of the %ICertificatePath interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_PATH_H_
#define _FSEC_CERT_ICERTIFICATE_PATH_H_


// Includes
#include "FBaseString.h"
#include "FSecConfig.h"
#include "FSecCertICertificate.h"
#include "FSecCertICertificatePathValidationParameter.h"
//#include "FSecCertICertificatePathValidationResult.h"
#include "FSecCertTypes.h"


namespace Osp { namespace Security { namespace Cert {
	class ICertificatePathValidationResult;
/**
 *  @interface	ICertificatePath 
 *  @brief		This interface validates the certificate path and gets more information about it.
 *  @since		1.0
 *
 * The %ICertificatePath interface validates the certificate path and gets more information about it.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/security/certificate_namespace.htm">Certificates</a>.
 *
 *  The following example demonstrates how to use the %ICertificatePath interface.
 *
 *  @code
 *
 *  void
 *  MyCertificatePath::Sample()
 *  {
 *		X509Certificate	*pCertificate1	= null;
 *		X509Certificate	*pCertificate2	= null;
 *
 *		ICertificate 	*pTrustCa = null;
 *		ByteBuffer		input1, input2;
 *		int 			depth = 0;
 *		ValidationResult valResult;
 *		result			r = E_FAILURE;
 *
 *		ICertificatePath	*pCertPath	= null;
 *
 *		String fileName1(L"/Home/UTsSecurity/Security/Domain3Certs/TestCert1-1.der");
 *		String fileName2(L"/Home/UTsSecurity/Security/Domain3Certs/TestCert1-2.der");
 *		File			file1, file2;
 *		FileAttributes	attribute1, attribute2;
 *
 *		r = file1.Construct(fileName1, L"r");
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = file1.GetAttributes(fileName1, attribute1);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = input1.Construct((int)attribute1.GetFileSize());
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = file1.Read(input1);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		input1.Flip();
 *	
 *		r = file2.Construct(fileName2, L"r");
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		r = file2.GetAttributes(fileName2, attribute2);
 *		if (IsFailed(r))
 *			goto CATCH;
 *
 *		r = input2.Construct((int)attribute2.GetFileSize());
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = file2.Read(input2);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		input2.Flip();
 *	
 *		// Certificate1
 *		pCertificate1	= new X509Certificate;
 *		pCertificate1->Construct(input1);
 *	
 *		// Certificate2
 *		pCertificate2	= new X509Certificate;
 *		pCertificate2->Construct(input2);
 *	
 *		// Certificate Path
 *		pCertPath	= new X509CertificatePath();
 *		if (pCertPath == null)
 *			goto CATCH;
 *	
 *		r = pCertPath->AddCertificate(*pCertificate1);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *		r = pCertPath->AddCertificate(*pCertificate2);
 *		if (IsFailed(r))
 *			goto CATCH;
 *	
 *
 *		// Certificate Path Validation Result
 *		valResult = pCertPath->Validate();
 *		if (valResult != VALIDATION_SUCCESS)
 *			goto CATCH;
 *
 *		depth = pCertPath->GetLength();
 *		if (depth == 0)
 *			goto CATCH;
 *	
 *		for (int i = 0; i < depth; i++)
 *		{
 *			ICertificate *pOutCert = pCertPath->GetCertificateN(i);
 *
 *			if (pOutCert)
 *			{
 *				String subjectName;
 *				subjectName		= pOutCert->GetSubject();
 *			}
 *
 *			delete pOutCert;
 *		}
 *
 *		pTrustCa = pCertPath->GetTrustAnchorN();
 *		if (pTrustCa)
 *		{
 *			String subjectName;
 *			subjectName		= pTrustCa->GetSubject();
 *		}
 *
 *		delete pTrustCa;
 *
 *		r = E_SUCCESS;
 *	
 *	CATCH:
 *		delete pCertificate1;
 *		delete pCertificate2;
 *		delete pCertPath;
 *	}
 *
 *  @endcode
 *
 */
class _EXPORT_SECURITY_ ICertificatePath
{
// Lifecycle
public:
	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	virtual ~ICertificatePath(void) {}


// Operation
public:
	/** 
	 *  Gets the format of the certificate path.
	 *
	 *	@since		1.0
	 *	@return		The format of the certificate
	 */
	virtual Osp::Base::String	GetFormat(void) const = 0;


	/** 
	 *  Adds a certificate to the certificate chain.
	 *
	 *	@since		1.0
	 *	@return		An error code
	 *  @param[in]	certificate				A reference to a certificate
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_INVALID_ARG			The specified @c certificate or the certificate data is invalid.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
 	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual	result AddCertificate(const Osp::Security::Cert::ICertificate& certificate) = 0;


	/** 
	 *  Validates the specified certificate path.
	 *
	 *	@since		1.0
	 *	@return		The result of the certificate path validation
	 */
	virtual Osp::Security::Cert::ValidationResult	Validate(void) = 0;

	
	/** 
	 *  Validates the specified certificate path.
	 *
	 *	@since		1.0
	 *	@return		The result of the certificate path validation
	 *  @param[in]	trustAnchor				The most trusted Certificate Authority (CA)
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The specified input parameter is invalid.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */	
	virtual Osp::Security::Cert::ValidationResult	Validate(const Osp::Security::Cert::ICertificate& trustAnchor) = 0;


	/**
	 *	Gets the trust anchor for the certificate path.
	 *
	 *	@since		1.0
	 *	@return		The root certificate, @n
	 *				else @c null if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual Osp::Security::Cert::ICertificate*	GetTrustAnchorN(void)  = 0;


	/** 
	 *  Gets the length of the certificate path.
	 *
	 *	@since		1.0
	 *	@return		The length of the certificate path, @n
	 *				else @c -1 if an error occurs
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual int GetLength(void)  = 0;


	/**
	 *	Gets the list of certificates in this certificate path.
	 *
	 *	@since		1.0
	 *	@return		A pointer to the %ICertificate class, @n
	 *				else @c null if an error occurs
	 *  @param[in]	nth						The nth certificate in the certificate path (starts from @c 0)
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 *	@exception	E_INVALID_ARG			The value of the specified @c nth is out of the valid range. @n
	 *										It should be less than GetLength().
	 *	@exception	E_OBJ_NOT_FOUND			The certificate is not found.
	 *	@exception	E_SYSTEM				A system error has occurred.
	 */
	virtual	Osp::Security::Cert::ICertificate*	GetCertificateN(int nth) = 0;


};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_ICERTIFICATE_PATH_H_
