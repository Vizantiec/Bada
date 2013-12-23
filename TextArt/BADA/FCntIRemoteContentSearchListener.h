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
 * @file		FCntIRemoteContentSearchListener.h 
 * @brief		This is the header file for the %IRemoteContentSearchListener interface. 
 *
 * This header file contains the declarations of the %IRemoteContentSearchListener interface. 
 */

#ifndef _FCNT_IREMOTE_CONTENT_SEARCH_LISTENER_H_
#define _FCNT_IREMOTE_CONTENT_SEARCH_LISTENER_H_

#include <FBaseRt.h>
#include <FCntConstants.h>

namespace Osp { namespace Content {


/**
 * @interface	IRemoteContentSearchListener
 * @brief	This interface provides a listener that receives events associated with RemoteContentSearch.
 * @deprecated	This interface is deprecated due to the operation policy of the bada Server. An alternate interface will be introduced in the near future.
 * @since	1.0
 *
 *  The %IRemoteContentSearchListener interface provides a listener that receives events associated with RemoteContentSearch.
 * All methods that have interactions with the server are operated asynchronously. An application should
 * implement the listener according to its usage. @n
 *
 * The error can be first checked in the listener. If the result is an error, the error code and
 * the error message give more information. An application developer can compare the listener's request ID with
 * the request ID received, when the asynchronous method is called. If it is the same, it means that 
 * the listener's result is the same as the requested result.
 * 
 * The following example demonstrates how to use the %IRemoteContentSearchListener interface.
 *
 * @code
 *
 * /////////////////////////////////////
 * //MyClass.h
 *
 * #include <FContent.h>
 *
 * class RemoteContentSearchListenerImpl : public Osp::Content::IRemoteContentSearchListener
 * {
 *	public:
 *		RemoteContentSearchListenerImpl(void);
 *		~RemoteContentSearchListenerImpl(void);
 *
 *		void OnContentTypesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pContentTypeList, 
 *		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 *
 *		void OnCategoriesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pCategoryList, 
 *		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 *
 *		void OnRemoteContentSearchResultReceivedN(RequestId reqId, 
 *		Osp::Base::Collection::IList* pRemoteContentInfoList, 
 *		int currentPage, int countPerPage, int totalPageCount, int totalCount, result r, 
 *		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 * };
 *
 * /////////////////////////////////////
 * //MyClass.cpp
 *
 * #include "MyClass.h"
 *
 * using namespace Osp::Base;
 * using namespace Osp::Base::Collection;
 * using namespace Osp::Content;
 *
 * void
 * RemoteContentSearchListenerImpl::OnContentTypesReceivedN(RequestId reqId, IList* pContentTypeList, 
 *		result r, const String& errorCode, const String& errorMessage)
 * {
 *	//Do something
 * }
 * 
 * void
 * RemoteContentSearchListenerImpl::OnCategoriesReceivedN(RequestId reqId, IList* pCategoryList, 
 *		result r, const String& errorCode, const String& errorMessage)
 * {
 *	//Do something
 * }
 * 
 * void
 * RemoteContentSearchListenerImpl::OnRemoteContentSearchResultReceivedN(RequestId reqId, 
 *		IList* pRemoteContentInfoList, 
 *		int currentPage, int countPerPage, int totalPageCount, int totalCount, result r, 
 *		const String& errorCode, const String& errorMessage)
 * {
 *	//Do something
 * }
 * 
 * @endcode
 *
 */
class _EXPORT_CONTENT_ IRemoteContentSearchListener
	: public virtual Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * This is the virtual destructor for this class.
	 *
	 *  @since		1.0
	 */
	virtual ~IRemoteContentSearchListener(void) {}

// Operation
public:
	/**
	* Called when the GetContentTypeList() method of RemoteContentSearch class returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	pContentTypeList	A pointer to the content type list @n
  *                                     The list consists of String instances with the content type name or @c null if an error occurs. 
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVER			An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	*/
	virtual void OnContentTypesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pContentTypeList, 
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when the GetCategoryList() method of RemoteContentSearch class returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	pCategoryList		A pointer to the category list @n
	* 									The list consists of RemoteCategory instances or
	* 									@c null if an error occurs.
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVER			An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	*/
	virtual void OnCategoriesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pCategoryList, 
		result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when the Search() method of RemoteContentSearch class returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId						The request ID
	* @param[in]	pRemoteContentInfoList		A pointer to the remote search result list
	* 											The list consists of RemoteContentInfo instances or
	* 											@c null if an error occurs.
	* @param[in]	currentPage					The current page 
	* @param[in]	countPerPage				The count per page
	* @param[in]	totalPageCount				The total page count
	* @param[in]	totalCount					The total count 
	* @param[in]	r							The result
	* @param[in]	errorCode					The error code
	* @param[in]	errorMessage				The error message
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVER			An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED	The network connection has failed.
	*/
	virtual void OnRemoteContentSearchResultReceivedN(RequestId reqId, Osp::Base::Collection::IList* pRemoteContentInfoList, 
		int currentPage, int countPerPage, int totalPageCount, int totalCount, result r, 
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

};

}; }; // Osp::Content

#endif// _FCNT_IREMOTE_CONTENT_SEARCH_LISTENER_H_
