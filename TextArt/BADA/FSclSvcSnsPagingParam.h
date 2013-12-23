/* $Change: 1202329 $ */
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
* @file		FSclSvcSnsPagingParam.h
* @brief	This is the header file for the %SnsPagingParam class.
*
* This header file contains the declarations of the %SnsPagingParam class.
*/
#ifndef _FSCL_SVC_SNS_PAGINGPARAM_H_
#define _FSCL_SVC_SNS_PAGINGPARAM_H_

#include "FBaseObject.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

	class __SnsUtil;

/**
* @class		SnsPagingParam
* @brief		This class provides the information of a paging parameter to use the SnsGateway methods that support paging.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0
*
* The %SnsPagingParam class represents paging parameters like page number and the maximum count of items in that page. When this instance is created, the maximum count of 
* items is to be set. Changes to this maximum count of items is done using SnsPagingParam::Reset(int countPerPage). But the page number is also reset to page 
* 1. The page number is set to @c 1 the first time when this instance is created and increased by @c 1 using SnsPagingParam::Next(). When a result 
* of request is received using the listeners, this class and a boolean value that represents whether the next page exists, is obtained. @n
* An important thing to remember is that %SnsGateway allows only sequential page increase. @n
* The first time when some method supporting paging is called, the page number has to be @c 1. It means a pagingParam is to be passed that is created without 
* calling SnsPagingParam::Next(). After the response is received using the listener method, the page number has to be increased using SnsPagingParam::Next() 
* if the next page items are to be requested. More than one execution of SnsPagingParam::Next() without calling some method supporting paging, is not 
* allowed. @n
*
* See the following example. @n
* The following example is a good use case.
* @code
* void
* MyClass::GetBuddies(void)
* {
*    result r = E_SUCCESS;
*    RequestId reqId;
*    String providerName = L"twitter";
*
*    SnsPagingParam pagingParam(5);
*
*    r = pSnsGateway->GetMyBuddies(providerName, pagingParam, reqId);
*
* }
*
*
* void
* MySnsPeopleListener::OnMySnsBuddiesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pBuddyProfileList,
*	bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
* {
*    if (pBuddyProfileList)
*    {
*  	    // Do something.
*     }
*
*    // Deletes the list and deallocates the memory.
*    pBuddyProfileList->RemoveAll(true);
*    delete pBuddyProfileList;
* }
*
* void
* MyClass::GetMoreBuddies(SnsPagingParam pagingParam)
* {
*    result r = E_SUCCESS;
*    RequestId reqId;
*    String providerName = L"twitter";
*
*    pagingParam.Next();
*
*    r = pSnsGateway->GetMyBuddies(providerName, pagingParam, reqId);
*
* }
* @endcode
*
* The following three examples are bad use cases.
* @code
* void
* MyClass::GetBuddies(void)
* {
*    result r = E_SUCCESS;
*    RequestId reqId;
*    String providerName = L"twitter";
*
*    SnsPagingParam pagingParam(5);
*    r = pagingParam.Next();   // Returns exception.
*
*    r = pSnsGateway->GetMyBuddies(providerName, pagingParam, reqId);
*
* }
* @endcode
* @code
* void
* MyClass::GetMoreBuddies(SnsPagingParam pagingParam)
* {
*    result r = E_SUCCESS;
*    RequestId reqId;
*    String providerName = L"twitter";
*
*    r = pagingParam.Next();
*    r = pagingParam.Next();   // Returns exception.
*
*    r = pSnsGateway->GetMyBuddies(providerName, pagingParam, reqId);
*
* }
* @endcode
* @code
* void
* MySnsPeopleListener::OnMySnsBuddiesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pBuddyProfileList,
*	bool hasNext, SnsPagingParam& pagingParam, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg)
* {
*    if (pBuddyProfileList)
*    {
*  	    // Do something.
*    }
*
*    if (hasNext == false)
*    {
*         r = pagingParam.Next();    // Returns exception when the value of hasNext is false. It means no more page.
*    }
*
*    // Deletes list and deallocates the memory.
*    pBuddyProfileList->RemoveAll(true);
*    delete pBuddyProfileList;
* }
* @endcode
*
*/

class  _EXPORT_SOCIAL_ SnsPagingParam :
	public Osp::Base::Object
{

	friend class __SnsUtil;

private:

	/**
	* This is the constructor for this class.
	*/
	SnsPagingParam(int pageNo, int countPerPage, Osp::Base::String& startContext, bool isAvailableNext);

public:
	/**
	* This is the constructor for this class. @n
	* The available maximum value of @c countPerPage is @c 16. If you set to a count greater than @c 16, the @c countPerPage will be @c 16.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	countPerPage		The desired maximum count of the result items on the page
	*/
	SnsPagingParam(int countPerPage);

	/**
	* This is the copy constructor for the %SnsPagingParam class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An instance of %SnsPagingParam
	*/
	SnsPagingParam(const SnsPagingParam& value);

	 /**
	 * This assignment operator copies the data contained in the specified instance of %SnsPagingParam to this instance.
	 *
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	 * @since 		1.0
	 * @param[in]	value	An instance of %SnsPagingParam
	 */
	SnsPagingParam& operator =(const SnsPagingParam& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsPagingParam(void);

public:

	/**
	* Sets the page to the next page. @n
	* More than one execution at one instance is not allowed.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_OPERATION	This method cannot be called twice in a row, or @n
	*                                   or there are no more pages available.
	*/
	result Next(void);

	/**
	* Resets the page count to @c 1 and changes the maximum count of items. @n
	* The available maximum value of the @c countPerPage is @c 16. If a count greater than @c 16 is set, the count per page will be @c 16.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	void Reset(int countPerPage);

	/**
	* Resets the page count to @c 1.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	void Reset();

	/**
	* Gets the page number that this instance indicates.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The page number
	*/
	int GetCurrentPageNumber(void) const;

	/**
	* Gets the maximum count of items that this instance indicates.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The maximum count of items
	*/
	int GetCountPerPage(void) const;

private:
	int __countPerPage;
	int __pageNo;
	Osp::Base::String __startContext;
	bool __isAvailableNext;

	friend class SnsPagingParamEx;
	class SnsPagingParamEx* __pSnsPagingParamEx;

};

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_PAGINGPARAM_H_
