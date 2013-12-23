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
 * @file	FCmcStrItemService.h
 * @brief	This is the header file for the %ItemService class.
 *
 * This header file contains the declarations of the %ItemService class.
 */

#ifndef _FCMC_STORE_ITEM_SERVICE_H_
#define _FCMC_STORE_ITEM_SERVICE_H_

#include "FCmcStrIItemServiceListener.h"

struct MRestClient;
struct MOspRestClient;

namespace Osp { namespace Commerce { namespace Store {

class ItemServiceEx;

/**
 * @class	ItemService
 * @brief	This class provides the functionalities to query information pertaining to the item.
 * @since	1.0 
 *
 * The %ItemService class provides services for managing items registered in Samsung Apps Seller Office and obtaining the item information. 
 * The methods provided by the %ItemService class work asynchronously. To get the result of the request, its listener should be implemented.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/commerce/itemservice.htm">ItemService</a>.
 *
 * @see		Osp::Commerce::Store::IItemServiceListener
 *
 * The following example demonstrates how to use the %ItemService class.
 *
 * @code
 * /////////////////////////////////////
 * //MyClass.h
 *
 * #include <FCommerce.h>
 *
 * class ItemServiceListenerImpl : public Osp::Commerce::Store::IItemServiceListener
 * {
 *	public:
 *		ItemServiceListenerImpl(void) {}
 *		~ItemServiceListenerImpl(void) {}
 *
 *		void OnItemListReceivedN(RequestId reqId, Osp::Base::Collection::IList* pItemInfoList,
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
 * void ItemServiceListenerImpl::OnItemListReceivedN(RequestId reqId, IList* pItemInfoList,
 *		result r, const String& errorCode, const String& errorMsg)
 * {
 *	//Checks result
 *	if(IsFailed(r)){
 *		//Check errorCode
 *		//Check errorMessage
 *	}
 *
 *	//Do something
 *
 * }
 *
 * void
 * MyClass::Test(void)
 * {
 *	ItemServiceListenerImpl* pListener = new ItemServiceListenerImpl;
 *
 *	//Constructs ItemService
 *	ItemService* pItemService = new ItemService;
 *	result r = pItemService->Construct(*pListener);
 *	if(IsFailed(r)){
 *		//do something for an error
 *	}
 *
 *	//Gets item list
 *	RequestId requestId = INVALID_REQUEST_ID;
 *	r = pItemService->GetItemList(L"100000000006", 1, 10, requestId);
 *	if(IsFailed(r)){
 *		//Do something for an error
 *	}
 *
 *	//Checks its listener
 *
 *	//delete resources
 *	delete pItemService;
 *	delete pListener;
 *
 * }
 *
 * @endcode
 *
 */

class _EXPORT_COMMERCE_ ItemService :
	public Osp::Base::Object
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks	After creating an instance of ItemService, the construct() method should be explicitly called to initialize this instance.
	 *
	 */
	ItemService(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ItemService(void);

	/**
	 * Initializes this instance of %ItemService with the specified listener.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup	COMMERCE_STORE
	 *
	 * @return		An error code
	 * @param[in]	listener				A reference to %IItemServiceListener  
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			This instance has already been constructed.
	 * @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	 */
	result Construct(const IItemServiceListener &listener);

public:

	/**
	 * Gets the item list from Samsung Apps.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup	COMMERCE_STORE
	 *
	 * @return		An error code
	 * @param[in]	itemGroupId				The item group ID
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
	 * @remarks		After calling this method, the result can be checked using the IItemServiceListener::OnItemListReceivedN() method.
	 */
	result GetItemList(const Osp::Base::String& itemGroupId, int startNum, int endNum, RequestId& reqId);

private:
	ItemService(const ItemService& value);

	ItemService& operator =(const ItemService& rhs);

private:
	MRestClient*				__pRestClient;
	MOspRestClient*				__pOspRestClient;
	const IItemServiceListener* __pIListener;
	int*						__pAppStatus;

private:
	friend class ItemServiceEx;
	class ItemServiceEx* __pItemServiceEx;
};	// class ItemService

};};}; // Osp::Commerce::Store

#endif// _FCMC_STORE_ITEM_SERVICE_H_
