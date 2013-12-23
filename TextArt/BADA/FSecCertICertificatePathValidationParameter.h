/* $Change: 1265123 $ */
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
 * @file		FSecCertICertificatePathValidationParameter.h
 * @brief		This is the header file for the %ICertificatePathValidationParameter interface.
 *
 * This header file contains the declarations of the %ICertificatePathValidationParameter interface.
 */
#ifndef _FSEC_CERT_ICERTIFICATE_PATH_VALIDATION_PARAMETER_H_
#define _FSEC_CERT_ICERTIFICATE_PATH_VALIDATION_PARAMETER_H_


// Includes
#include "FBaseString.h"
#include "FSecConfig.h"


namespace Osp { namespace Security { namespace Cert {
/**
 *  @interface	ICertificatePathValidationParameter 
 *  @brief		This interface is used for certificate path validation.
 *  @deprecated This interface is deprecated because the platform does not support certificate path validation parameter. Do not use this interface in your application.
 *	@since		1.0
 *
 * The %ICertificatePathValidationParameter interface is used for certificate path validation.
 */
class _EXPORT_SECURITY_ ICertificatePathValidationParameter 
{
// Lifecycle
public:
	/** 
	 *	This is the destructor for this class. 
	 *
	 *	@since		1.0
	 */	
	virtual ~ICertificatePathValidationParameter(void) {}


// Operation
public:
	/** 
	 *  Checks the value of the RevocationEnabled flag. @n
	 *	If this flag is set to @c true, the default revocation checking mechanism is used.
	 *	If this flag is set to @c false, the default revocation checking mechanism is disabled (not used). 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		The current value of the RevocationEnabled flag
	 *	@see			Osp::Security::Cert::ICertificatePathValidationParameter::SetRevocationEnabled (bool value)
	 */
	virtual bool IsRevocationEnabled(void)  = 0;


	/** 
	 *  Sets the value of the RevocationEnabled flag to the specified value. @n
	 *	If this flag is set to @c true, the default revocation checking mechanism is used.
	 *	If this flag is set to @c false, the default revocation checking mechanism is disabled (not used).
	 *  When a %ICertificatePathValidationParameter type object is created, this flag is set to @c false. 
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since			1.0
	 *	@param[in]	value	The new value of the RevocationEnabled flag
	 */
	virtual void SetRevocationEnabled(bool value)  = 0;


	/** 
	 *  Sets the RevocationType flag. @n
	 *	It specifies the scheme that is to be used when checking the revocation status of the certificate.
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since			1.0
	 *	@return			An error code
	 *	@param[in]	revocationType	The revocation type
	 *	@exception	E_SUCCESS				The method is successful.
	 *	@exception	E_UNSUPPORTED_ALGORITHM	The specified @c revocationType is not supported.
	 *  @remarks   	Currently "OCSP" is only supported.
	 */
	virtual result SetRevocationType(Osp::Base::String revocationType)  = 0;


	/**
	 *  Gets the name of the RevocationType flag. @n
	 *	It specifies the scheme that is to be used when checking the revocation status of the certificate.
	 *
	 * 	@deprecated    This method is deprecated.
	 *	@since		1.0
	 *	@return		The name of the RevocationType flag
	 */
	virtual Osp::Base::String GetRevocationType(void)  = 0;


};
}; }; }; // Osp::Security::Cert


#endif//_FSEC_CERT_ICERTIFICATE_PATH_VALIDATION_PARAMETER_H_
