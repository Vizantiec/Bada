/* $Change: 797580 $ */
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
 * @file	FNetHttpIHttpEntity.h
 * @brief	This is the header file for the %IHttpEntity interface.
 *
 * This header file contains the declarations of the %IHttpEntity interface.
 */

#ifndef _FNET_HTTP_IHTTPENTITY_H_
#define _FNET_HTTP_IHTTPENTITY_H_

// Includes
#include "FBaseTypes.h"
#include "FBaseRtIEventListener.h"
#include "FNetHttpHttpTypes.h"

namespace Osp { namespace Net { namespace Http {
/**
 * @interface	IHttpEntity
 * @brief		This interface provides common functions for the HTTP entity.
 * @since 		2.0
 *
 *	The %IHttpEntity interface represents the %HTTP entity for the data exchanged between the client and the server.
 */

class __HttpTransactionEvent;
class HttpRequest;
class _EXPORT_NET_ IHttpEntity
{
// Lifecycle
public:
	/** This is the destructor for this class.
	 *
	 * @since 		2.0
	 */
	virtual ~IHttpEntity(void) {}

// Operation
public:
	/**
	 * Gets the length of the request content.
	 *
	 * @since 		2.0
	 * @return		The length of the content, @n
	 *				else @c -1 if the content length is unknown
	 */
	virtual long long GetContentLength(void) const = 0;

	/**
	 * Gets the type of the request content.
	 *
	 * @since 		2.0
	 * @return		The type of the content
	 */
	virtual Osp::Base::String GetContentType(void) const = 0;

protected:

	/**
	 * Checks whether the next data exists.
	 *
	 * @since 		2.0
	 * @return		@c true if the next data exists, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual	bool	HasNextData(void) = 0;

	/**
	 * Gets the next data.
	 *
	 * @since 		2.0
	 * @return		The buffer to be read.
	 * @param[in]	recommendedSize			The recommended size of the data to be sent
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 * @exception 	E_INVALID_STATE			The method invoked is invalid.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	virtual Osp::Base::ByteBuffer*	GetNextDataN(int recommendedSize) = 0;


protected:
    // Reserved virtual methods for later extension.

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IHttpEntity_Reserved1(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IHttpEntity_Reserved2(void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not responsible
	 * for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 *
	 * Following method is reserved and may change its name at any time without prior notice.
	 *
	 * @since       2.0
	 */
	virtual void IHttpEntity_Reserved3(void) {}

	friend class __HttpTransactionEvent;
	friend class HttpRequest;

};

}; }; }; // Osp::Net::Http
#endif // _FNET_HTTP_IHTTPENTITY_H_

