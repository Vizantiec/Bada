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
 * @file		FSecCertTypes.h
 * @brief		This is the header file for the %CertTypes definition.
 *
 * This header file contains the %CertTypes definitions.
 */
#ifndef _FSEC_CERT_TYPES_H_
#define _FSEC_CERT_TYPES_H_


namespace Osp{ namespace Security { namespace Cert
{
/** 
 * @enum ValidationResult
 * Defines the validation result.
 *
 * @since		1.0
 */
enum ValidationResult
{
	VALIDATION_SUCCESS = 0,				/**<	Success */
	VALIDATION_ERROR_INVALID_PATH,		/**<	The certificate path does not validate */
	VALIDATION_ERROR_NO_ROOT,			/**<	The root certificate is not found */
	VALIDATION_ERROR_CERT_EXPIRED,		/**<	The certificate date falls outside the validity period */
	VALIDATION_ERROR_CERT_REVOKED,		/**<	The certificate has been revoked */
	VALIDATION_ERROR_INVALID_SIGNATURE,	/**<	The signature is not valid */

};


}; }; }; //Osp::Security::Cert

#endif // _FSEC_CERT_TYPES_H_
