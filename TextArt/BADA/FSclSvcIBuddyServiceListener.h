/* $Change: 1144988 $ */
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
* @file		FSclSvcIBuddyServiceListener.h
* @brief	This is the header file for the %IBuddyServiceListener interface.
*
* This header file contains declarations of the %IBuddyServiceListener interface.
*/
#ifndef _FSCL_SVC_IBUDDY_SERVICE_LISTENER_H_
#define _FSCL_SVC_IBUDDY_SERVICE_LISTENER_H_

// Includes

#include "FBaseTypes.h" // for using UserId and RequestId
#include "FBaseRtIEventListener.h"
#include "FBaseColIList.h"
#include "FSclConfig.h"
#include "FSclSvcBuddyCategory.h"


namespace Osp { namespace Social { namespace Services {

/**
* @interface	IBuddyServiceListener 
* @brief		This listener interface is for receiving the responses to requests, which are initiated from BuddyService.
* @deprecated	This interface is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* 	The %IBuddyServiceListener interface is for receiving responses to requests, which are initiated from BuddyService. All the member methods defined in 
*	BuddyService operate asynchronously. To receive the result of member methods, a class which implements IBuddyServiceListener must be specified.
*
*/
class  _EXPORT_SOCIAL_ IBuddyServiceListener
	: public Osp::Base::Runtime::IEventListener
{
	// Operations
public:
	/**
	* Called to notify when the response to BuddyService::RequestBuddy() or BuddyService::RequestBuddyByLoginId() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED		The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	BuddyService::RequestBuddy(), BuddyService::RequestBuddyByLoginId()
	*/
	virtual void	OnBuddyRequestSent(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::DeleteBuddy() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::DeleteBuddy()
	*/
	virtual void	OnBuddyDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::RespondToBuddyRequest() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	BuddyService::RespondToBuddyRequest()
	*/
	virtual void	OnBuddyResponseSent(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::GetSentBuddyRequests() is received. @n
	* The sent buddy requests are sorted in ascending order of the requested date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pRequestList			The list of the sent requests, @n
	*										else @c null if an error occurs @n
	*										An item of this list is an instance of Osp::Social::Services::SentBuddyRequest.								
	* @param[in]	pageNo					The page number of the resulting list
	* @param[in]	countPerPage			The maximum count of the result items on a page
	* @param[in]	totalPageCount			The resulting count of pages from this search  
	* @param[in]	totalCount				The number of results generated by this search
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*										Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_CONNECTION_FAILED		The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	BuddyService::GetSentBuddyRequests()
	*/
	virtual void	OnSentBuddyRequestsReceivedN(RequestId reqId, Osp::Base::Collection::IList* pRequestList, 
									int pageNo, int countPerPage, int totalPageCount, int totalCount, 
									result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::GetReceivedBuddyRequests() is received.
	* The received buddy requests are sorted in ascending order of the requested date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pRequestList			The list of the received request, @n
	*										else @c null if an error occurs @n
	*										An item of this list is an instance of Osp::Social::Services::ReceivedBuddyRequest.								
	* @param[in]	pageNo					The page number of the resulting list
	* @param[in]	countPerPage			The maximum count of the result items on a page
	* @param[in]	totalPageCount			The resulting count of pages from this search  
	* @param[in]	totalCount				The number of results generated by this search
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::GetReceivedBuddyRequests()
	*/
	virtual void	OnReceivedBuddyRequestsReceivedN(RequestId reqId, Osp::Base::Collection::IList* pRequestList, 
						int pageNo, int countPerPage, int totalPageCount, int totalCount,
						result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::GetReceivedResponses() is received.
	* The buddy responses are sorted in the ascending order of the requested date.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pResponseList			The list of the received responses, @n
	*										else @c null if an error occurs @n
	*										An item of this list is an instance of Osp::Social::Services::BuddyResponse.
	* @param[in]	pageNo					The page number of the resulting list
	* @param[in]	countPerPage			The maximum count of the result items on a page
	* @param[in]	totalPageCount			The resulting count of pages from this search  
	* @param[in]	totalCount				The number of results generated by this search
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see		BuddyService::GetReceivedResponses()
	*/
	virtual void	OnReceivedBuddyResponsesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pResponseList, 
						int pageNo, int countPerPage, int totalPageCount, int totalCount,
						result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::DeleteReceivedResponses() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::DeleteReceivedResponses()
	*/
	virtual void	OnReceivedBuddyResponsesDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::CancelSentBuddyRequest() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::CancelSentBuddyRequest()
	*/
	virtual void	OnSentBuddyRequestCanceled(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::UpdateBuddyAttribute() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED		The response data from the server cannot be parsed.
	* @see	BuddyService::UpdateBuddyAttribute()
	*/
	virtual void	OnBuddyAttributeUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::GetAllBuddies() or BuddyService::GetBuddiesUsingApp() is received.
	* The buddies are sorted in the ascending order of the buddy name.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pBuddyList				The list of buddies, @n
	*										else @c null if an error occurs @n
	*										An item of this list is an instance of Osp::Social::Services::Buddy.								
	* @param[in]	pageNo					The page number of the resulting list
	* @param[in]	countPerPage			The maximum count of the result items on a page
	* @param[in]	totalPageCount			The resulting count of pages from this search  
	* @param[in]	totalCount				The number of results generated by this search
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::GetAllBuddies(), BuddyService::GetBuddiesUsingApp()
	*/
	virtual void	OnBuddiesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pBuddyList, 
								int pageNo, int countPerPage, int totalPageCount, int totalCount,
								result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::CreateCategory() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pBuddyCategory			The created BuddyCategory, @n
	*										else @c null if an error occurs
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::CreateCategory()
	*/
	virtual void	OnBuddyCategoryCreated(RequestId reqId, BuddyCategory* pBuddyCategory, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::DeleteCategory() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::DeleteCategory()
	*/
	virtual void	OnBuddyCategoryDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::UpdateCategory() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::UpdateCategory()
	*/
	virtual void	OnBuddyCategoryUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**
	* Called to notify when the response to BuddyService::GetAllCategories() is received.
	* The categories are sorted in the ascending order of the category name.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pCategoryList			The list of categories, @n
	*										else @c null if an error occurs @n
	*										An item of this list is an instance of Osp::Social::Services::BuddyCategory. 								
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::GetAllCategories()
	*/
	virtual void	OnBuddyCategoriesReceivedN(RequestId reqId, Osp::Base::Collection::IList* pCategoryList,								
								result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::AddBuddyToCategory() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::AddBuddyToCategory()
	*/
	virtual void	OnBuddyAddedToCategory(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::RemoveBuddyFromCategory() is received.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see	BuddyService::RemoveBuddyFromCategory()
	*/
	virtual void	OnBuddyRemovedFromCategory(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;

	/**	
	* Called to notify when the response to BuddyService::GetAllBuddiesInCategory() is received.
	* The buddies are sorted in the ascending order of the buddy name.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @param[in]	reqId					The ID of the request	
	* @param[in]	pBuddyList				The list of buddies who belong to the category, @n
	*										else @c null if an error occurs @n
	*										An item of this list is an instance of Osp::Social::Services::Buddy.								
	* @param[in]	pageNo					The page number of the resulting list
	* @param[in]	countPerPage			The maximum count of the result items on a page
	* @param[in]	totalPageCount			The resulting count of pages from this search  
	* @param[in]	totalCount				The number of results generated by this search
	* @param[in]	r						The result of the request
	* @param[in]	errorCode				The error code from the server
	* @param[in]	errorMsg				The error message from the server
	* @exception	E_SUCCESS 				The request is successful.
	* @exception	E_SERVER 				An error has occurred on the server side. @n
	*								  		Please check the @c errorCode and @c errorMsg.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_CONNECTION_FAILED 	The network connection has failed.
	* @exception	E_PARSING_FAILED 		The response data from the server cannot be parsed.
	* @see		BuddyService::GetAllBuddiesInCategory()
	*/
	virtual void	OnBuddiesInCategoryReceivedN(RequestId reqId, Osp::Base::Collection::IList* pBuddyList, 
								int pageNo, int countPerPage, int totalPageCount, int totalCount,
								result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) = 0;
}; // class IBuddyServiceListener

};};};// Osp::Social::Services

#endif// _FSCL_SVC_IBUDDY_SERVICE_LISTENER_H_


