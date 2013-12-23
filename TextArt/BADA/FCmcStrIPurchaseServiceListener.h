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
 * @file		FCmcStrIPurchaseServiceListener.h
 * @brief		This is the header file for the %IPurchaseServiceListener interface.
 *
 * This header file contains the declarations of the %IPurchaseServiceListener interface.
 */

#ifndef _FCMC_STORE_IPURCHASE_SERVICE_LISTENER_H_
#define _FCMC_STORE_IPURCHASE_SERVICE_LISTENER_H_

// Includes
#include "FBaseRt.h"
#include "FCmcStrConstants.h"

#define OnPurchaseInfoReceievedN OnPurchaseInfoReceivedN

namespace Osp { namespace Commerce { namespace Store{
/**
 * @interface	IPurchaseServiceListener
 * @brief		This interface provides a listener that receives the events associated with the PurchaseService class.
 *
 * @since		1.0
 *
 * The %IPurchaseServiceListener interface provides a listener that receives the events associated with the PurchaseService class.
 * Applications must implement this interface and register it with the PurchaseService::PurchaseItem() and PurchaseService::GetPurchaseInfo() methods. This interface notifies the application when purchase records are retrieved from Samsung Apps or when a purchase is made.
 *
 * @see			Osp::Commerce::Store::PurchaseService
 */
class _EXPORT_COMMERCE_ IPurchaseServiceListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:

	/**
	 * This is the destructor for this interface.
	 *
	 * @since		1.0
	 */
	virtual ~IPurchaseServiceListener(void) {}

public:
	/**
	 * Called when the PurchaseService::PurchaseItem() method is completed.
	 *
	 * @since			1.0
	 * @param[in]	reqId					The request ID
	 * @param[in]	paymentId				The payment ID
	 * @param[in]	itemId					The item ID
	 * @param[in]	itemName				The item name
	 * @param[in]	price					The price of the purchase
	 * @param[in]	currency				The currency of the item price
	 * @param[in]	purchaseDate			The purchase date
	 * @param[in]	r						The result for the request
	 * @param[in]	errorCode				<a href="servererror.html">The error code</a>
	 * @param[in]	errorMsg				The error message that is related to the error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_INVALID_ARG			The item is not registered at Samsung Apps.
	 * @exception	E_OPERATION_CANCELED	The user has cancelled the purchase.
	 * @exception	E_CONNECTION_FAILED		The network connection has failed.
	 * @exception	E_SERVICE_LIMITED		The application is retired from Samsung Apps.
	 * @exception	E_SERVICE_UNAVAILABLE	The server is unavailable or returns an abnormal response, or
	 * 										the application ID is invalid.
	 * @exception	E_SERVER				An error has occurred on the server side. @n
	 *                                      Check @c errorCode and @c errorMsg for details.
	 *
	 */
	virtual void OnItemPurchaseCompleted(RequestId reqId, const PaymentId& paymentId, const ItemId& itemId, const Osp::Base::String& itemName, double price, const Osp::Base::String& currency, const Osp::Base::DateTime& purchaseDate, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	 * Called when the PurchaseService::GetPurchaseInfo() method is completed.
	 *
	 * @since			1.0
	 * @param[in]	reqId					The request ID
	 * @param[in]	pPurchaseInfoList		The list of purchase information
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
	virtual void OnPurchaseInfoReceivedN(RequestId reqId, Osp::Base::Collection::IList* pPurchaseInfoList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

};
};};};// Osp::Commerce::Store
#endif // _FCMC_STORE_IPURCHASE_SERVICE_LISTENER_H_
