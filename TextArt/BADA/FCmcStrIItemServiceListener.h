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
 * @file		FCmcStrIItemServiceListener.h
 * @brief		This is the header file for the %IItemServiceListener interface.
 *
 * This header file contains the declarations of the %IItemServiceListener interface.
 */

#ifndef _FCMC_STORE_IITEM_SERVICE_LISTENER_H_
#define _FCMC_STORE_IITEM_SERVICE_LISTENER_H_

// Includes
#include "FBaseRt.h"
#include "FCmcStrConstants.h"

namespace Osp { namespace Commerce { namespace Store{
/**
 * @interface	IItemServiceListener
 * @brief		This interface provides a listener that receives the events associated with the ItemService class.
 * @since		1.0
 *
 * The %IItemServiceListener interface provides a listener that receives the events associated with the ItemService class.
 * Applications must implement this interface and register it with the ItemService::GetItemList() method. This interface notifies the application when the list items are retrieved from Samsung Apps.
 *
 * @see			Osp::Commerce::Store::ItemService
 */
class _EXPORT_COMMERCE_ IItemServiceListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:

	/**
	 * This is the destructor for this interface.
	 *
	 * @since		1.0
	 */
	virtual ~IItemServiceListener(void) {}

public:
	/**
	 * Called when the ItemService::GetItemList() method is completed.
	 *
	 * @since		1.0
	 * @param[in]	reqId					The request ID
	 * @param[in]	pItemInfoList			The list of item information
	 * @param[in]	r						The result for the request
	 * @param[in]	errorCode				<a href="servererror.html">The error code</a>
	 * @param[in]	errorMsg				The error message that is related to the error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_CONNECTION_FAILED		The network connection has failed.
	 * @exception	E_SERVICE_LIMITED		The application is retired from Samsung Apps.
	 * @exception	E_SERVICE_UNAVAILABLE	The server is unavailable or returns an abnormal response, or
	 * 										the application ID is invalid.
	 * @exception	E_SERVER				An error has occurred on the server side. @n
	 *                                      Check @c errorCode and @c errorMsg for details.
	 *
	 */
	virtual void OnItemListReceivedN(RequestId reqId, Osp::Base::Collection::IList* pItemInfoList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};
};};};// Osp::Commerce::Store
#endif // _FCMC_STORE_IITEM_SERVICE_LISTENER_H_
