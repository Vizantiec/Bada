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
 * @file	FCmcStrPurchaseService.h
 * @brief	This is the header file for the %PurchaseService class.
 *
 * This header file contains the declarations of the %PurchaseService class.
 */

#ifndef _FCMC_STORE_PURCHASE_SERVICE_H_
#define _FCMC_STORE_PURCHASE_SERVICE_H_

#include "FCmcStrIPurchaseServiceListener.h"
#include "FAppIAppControlEventListener.h"

struct MRestClient;
struct MOspRestClient;

namespace Osp { namespace Commerce { namespace Store {

class PurchaseServiceEx;

/**
 * @class	PurchaseService
 * @brief   This class provides methods to purchase an item and to obtain purchase information.

 * @since	1.0
 *
 * The %PurchaseService class provides services to purchase items registered in Samsung Apps Seller Office and obtaining the item's purchase information.

 * The methods provided by the %PurchaseService class work asynchronously. To get the result of the request, its listener should be implemented.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/commerce/purchaseservice.htm">PurchaseService</a>.
 *
 * @see		Osp::Commerce::Store::IPurchaseServiceListener
 *
 * The following example demonstrates how to use the %PurchaseService class.
 *
 * @code
 * /////////////////////////////////////
 * //MyClass.h
 *
 * #include <FCommerce.h>
 *
 * class PurchaseServiceListenerImpl : public Osp::Commerce::Store::IPurchaseServiceListener
 * {
 *	public:
 *		PurchaseServiceListenerImpl(void) {}
 *		~PurchaseServiceListenerImpl(void) {}
 *
 *		void OnItemPurchaseCompleted(RequestId reqId, const Osp::Commerce::Store::PaymentId& paymentId,
 *		const Osp::Commerce::Store::ItemId& itemId, const Osp::Base::String& itemName, double price,
 *		const Osp::Base::String& currency, const Osp::Base::DateTime& purchaseDate,
 *		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg);
 *
 *		void OnPurchaseInfoReceivedN(RequestId reqId, Osp::Base::Collection::IList* pPurchaseInfoList,
 *		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg);
 * };
 *
 * class MyClass
 * {
 *	public:
 *		MyClass(void){};
 *		~MyClass(void){};
 *		void Test(void);
 * };
 *
 * /////////////////////////////////////
 * //MyClass.cpp
 *
 * #include "MyClass.h"
 *
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Commerce::Store;
 *
 * void PurchaseServiceListenerImpl::OnItemPurchaseCompleted(RequestId reqId,
 *		const PaymentId& paymentId, const ItemId& itemId, const String& itemName,
 *		double price, const String& currency, const DateTime& purchaseDate,
 *		result r, const String& errorCode, const String& errorMsg)
 * {
 *	//check result
 *	if(IsFailed(r)){
 *		//check errorCode
 *		//check errorMessage
 *	}
 *
 *	//do something
 *
 * }
 *
 * void PurchaseServiceListenerImpl::OnPurchaseInfoReceivedN(RequestId reqId,
 * 		IList* pPurchaseInfoList, result r,
 * 		const String& errorCode, const String& errorMsg)
 * {
 *	//check result
 *	if(IsFailed(r)){
 *		//check errorCode
 *		//check errorMessage
 *	}
 *
 *	//do something
 *
 * }
 *
 * void
 * MyClass::Test(void)
 * {
 *	PurchaseServiceListenerImpl* pListener = new PurchaseServiceListenerImpl;
 *
 *	//construct %PurchaseService
 *	PurchaseService* pPurchaseService = new PurchaseService;
 *	result r = pPurchaseService->Construct(*pListener);
 *	if(IsFailed(r)){
 *		//do something for an error
 *	}
 *
 *	//purchase item
 *	RequestId requestId = INVALID_REQUEST_ID;
 *	r = pPurchaseService->PurchaseItem(L"100000000006", L"000000001547", requestId);
 *	if(IsFailed(r)){
 *		//do something for an error
 *	}
 *
 *	//check its listener
 *
 *	//delete resources
 *	delete pPurchaseService;
 *	delete pListener;
 *
 * }
 *
 * @endcode
 *
 */

class _EXPORT_COMMERCE_ PurchaseService :
	public Osp::Base::Object,
	public Osp::App::IAppControlEventListener
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks	After creating an instance of PurchaseService, you must explicitly call the Construct() method to initialize the instance.
	 *
	 */
	PurchaseService(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~PurchaseService(void);

	/**
	 * Initializes this instance of PurchaseService with the specified listener.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup	COMMERCE_STORE
	 *
	 * @return		An error code
	 * @param[in]	listener				A reference to %IPurchaseServiceListener 

	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(const IPurchaseServiceListener &listener);

public:
	/**
	 * Requests purchase item to Samsung Apps.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup	COMMERCE_STORE
	 *
	 * @return		An error code
	 * @param[in]	itemGroupId				The item group ID
	 * @param[in]	itemId					The item ID
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_SERVICE_LIMITED		The application is retired from Samsung Apps.
	 * @exception	E_INVALID_OPERATION		The prior purchase operation has not finished as yet.
	 * @remarks		After calling this method, the result can be checked in the IPurchaseServiceListener::OnItemPurchaseCompleted() method.
	 */
	result PurchaseItem(const Osp::Base::String& itemGroupId, const ItemId& itemId, RequestId& reqId);

	/**
	 * Gets the records of the purchases made on the device using Samsung Apps
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup	COMMERCE_STORE
	 *
	 * @return		An error code
	 * @param[in]	itemGroupId				The item group ID
	 * @param[in]	pPaymentId				The payment ID (optional)
	 * @param[in]	pStartDate				The start date of the search range (optional)
	 * @param[in]	pEndDate				The end date of the search range (optional)
	 * @param[in]	startNum				The number of the start point in the list
	 * @param[in]	endNum					The number of the end point in the list
	 * @param[out]	reqId					The request ID
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_INVALID_ARG			The specified @c startNum or @c endNum is zero or negative, @n
	 * 										or the specified @c endNum is less than @c startNum.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception	E_SERVICE_LIMITED		The application is retired from Samsung Apps.
	 * @remarks		After calling this method, the result can be checked in the IPurchaseServiceListener::OnPurchaseInfoReceivedN() method.
	 * @remarks		If @c pPaymentId is not @c null, other parameters (@c pStartDate, @c pEndDate, @c startNum, @c endNum) are ignored.
	 * @remarks		If @c pPaymentId is @c null, @c pStartDate and @c pEndDate have to be set.
	 */
	result GetPurchaseInfo(const Osp::Base::String& itemGroupId, PaymentId* pPaymentId, Osp::Base::DateTime* pStartDate, Osp::Base::DateTime* pEndDate, int startNum, int endNum, RequestId& reqId);

private:
	PurchaseService(const PurchaseService& value);

	PurchaseService& operator =(const PurchaseService& rhs);

	void OnAppControlCompleted(const Osp::Base::String& appControlId, const Osp::Base::String& operationId, const Osp::Base::Collection::IList* pResultList);

private:
	MRestClient*						__pRestClient;
	MOspRestClient*						__pOspRestClient;
	const IPurchaseServiceListener*		__pIListener;
	int*								__pAppStatus;
	Osp::Base::Collection::IList*		__pItemList;
	bool*								__pPurchasing;

	void*								__pUserData;
	void*								__pHttpResponseListener;

private:
	friend class PurchaseServiceEx;
	class PurchaseServiceEx* __pPurchaseServiceEx;

};	// class PurchaseService

};};}; // Osp::Commerce::Store

#endif// _FCMC_STORE_PURCHASE_SERVICE_H_
