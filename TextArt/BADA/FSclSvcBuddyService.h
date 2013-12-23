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
* @file		FSclSvcBuddyService.h
* @brief	This is the header file for the %BuddyService class.
*
* This header file contains the declarations of the %BuddyService class.
*/
#ifndef _FSCL_SVC_BUDDY_SERVICE_H_
#define _FSCL_SVC_BUDDY_SERVICE_H_

// Includes
#include "FBaseTypes.h" // for using UserId and RequestId
#include "FBaseColIList.h"
#include "FSclConfig.h"
#include "FSclSvcIBuddyServiceListener.h"
#include "FSclSvcBuddyCategory.h"
#include "FSclSvcSentBuddyRequest.h"
#include "FSclSvcReceivedBuddyRequest.h"
#include "FSclSvcBuddyResponse.h"
#include "FSclSvcBuddy.h"

struct IBuddyService;

namespace Osp { namespace Social { namespace Services {



/**
* @class	BuddyService 
* @brief	This class provides a way to manage the buddies on the bada Server side.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since	1.0
*
* 	The %BuddyService class manages the buddies on the bada Server side. All the member methods defined in this class operate asynchronously. To 
*	receive the result of a member method, a listener class that implements IBuddyServiceListener must be specified. @n
*
* This class provides a way to manage the buddies on the server side.
*
* The following example demonstrates how to use the %BuddyService class. 
* @code
	#include <FBase.h>
	#include <FSocial.h>

	using namespace Osp::Base;
	using namespace Osp::Social::Services;

	class BuddySample :
		public IBuddyServiceListener
	{
	public:
		BuddySample(void);
		~BuddySample(void);
	public:
		result GetMyBuddyList(void);
	private:
		void OnBuddiesReceivedN(RequestId reqId, Collection::IList* pBuddyList, int pageNo, int countPerPage, int totalPageCount, int totalCount, result r, const String& errorCode, const String& errorMsg);
		// ...
		// Defines the methods that implement IBuddyServiceListener.
		// ...
	private:
		BuddyService __buddyService;
	};

	result
	BuddySample::GetMyBuddyList(void)
	{
		result r = E_SUCCESS;
		RequestId reqId;

		// Initializes an instance of BuddyService.
		r = __buddyService.Construct(*this);
		if (IsFailed(r))
			return r;

		r = __buddyService.GetAllBuddies(reqId, 1, 30);
		if (IsFailed(r))
			return r;

		return E_SUCCESS;
	}

	void
	BuddySample::OnBuddiesReceivedN(RequestId reqId, Collection::IList* pBuddyList, int pageNo, int countPerPage, int totalPageCount, int totalCount, result r, const String& errorCode, const String& errorMsg)
	{
		if (IsFailed(r))
		{
			AppLogException("Failed to get buddies. [Exception:%s, Error message:%S]", GetErrorMessage(r), errorMsg.GetPointer());
		}
		else
		{
			AppLog("Succeeded to get buddies.");

			// Use the buddy list.
			//...

			// Release the buddy list.
			pBuddyList->RemoveAll(true);
			delete pBuddyList;
		}
	}

* @endcode
*
*
*/
class  _EXPORT_SOCIAL_ BuddyService:
	public Osp::Base::Object
{

	// Construct Operations
public:
	/**
	* This is the default constructor for this class.
	* This constructor creates an uninitialized instance of BuddyService.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	* @see			Construct()
	*/
	BuddyService(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since			1.0
	*/
	virtual ~BuddyService(void);

	/**
	* Initializes this instance of a %BuddyService.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	listener			The event listener
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.	
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	*/
	result Construct(const IBuddyServiceListener& listener);

private:
	// No implementation. Force to private
	BuddyService(const BuddyService& value);
	BuddyService& operator =(const BuddyService& value);

	// Operations
public:
	/**
	* Sends a buddy request to the specified user. @n
	* The bi-directional buddy relationship is built only after the receiver accepts the request. @n
	* However, if the receiver already has the unidirectional buddy relationship with the logged-in user, the buddy relationship is built automatically
	* because the acceptance step is unnecessary. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyRequestSent() is called.
	*
	* If the specified @c userId contains whitespace, this method uses the trimmed result.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[in]	userId					The ID of the user who receives the buddy request
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c userId is an empty string.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see			Construct(), IBuddyServiceListener::OnBuddyRequestSent()
	*/
	result RequestBuddy(const UserId& userId, RequestId& reqId);

	/**
	* Sends a buddy request to the user who has the specified login ID. @n
	* The bi-directional buddy relationship is built only after the receiver accepts the request. @n	
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyRequestSent() is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
    * @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[in]	loginId					The login ID of the user who receives the buddy request
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c loginId is an empty string.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyRequestSent()
	*/
	result RequestBuddyByLoginId(const LoginId& loginId, RequestId& reqId);

	/**
	* Deletes the specified buddy. @n
	* When a buddy is deleted, the target buddy does not get a notification. @n	
	* After the successful deletion of the buddy, the buddy relationship becomes unidirectional. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyDeleted() is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[in]	buddy					The buddy to be deleted
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c buddy is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyDeleted()
	*/
	result DeleteBuddy(const Buddy& buddy , RequestId& reqId);

	/**
	* Responds to an incoming (received) buddy request. @n
	* The response can be one of [RESPONSE_ACCEPT | RESPONSE_DENY | RESPONSE_IGNORE]. @n
	* @li If the request is accepted, the requester and receiver become each other's buddies.
	* @li If the request is denied, an appropriate response is sent to the requester.
	* @li If the request is ignored, no response is sent to the requester.
	*
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyResponseSent() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[in]	receivedRequest			The buddy request to respond to
	* @param[in]	response				The response value (accept, deny, or ignore)
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c receivedRequest is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyResponseSent()
	*/
	result RespondToBuddyRequest(const ReceivedBuddyRequest& receivedRequest, BuddyResponseType response, RequestId& reqId);

	/**
	* Gets the unanswered outgoing (sent) buddy requests. @n	
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnSentBuddyRequestsReceivedN() is called.		
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @param[in]	pageNo					The page number of the result list @n
	*										It starts from @c 1.
	* @param[in]	countPerPage			The desired maximum count of the result items on the page
	*
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c pageNo is less than @c 1, or @n
	*										the specified @c countPerPage is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnSentBuddyRequestsReceivedN()
	*/
	result GetSentBuddyRequests(RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	* Gets the unanswered incoming (received) buddy requests. @n	
	* This method sends the request to the server, and receives the response asynchronously.
	* When the request is completed, IBuddyServiceListener::OnReceivedBuddyRequestsReceivedN() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @param[in]	pageNo					The page number of the result list @n
	*										It starts from @c 1.
	* @param[in]	countPerPage			The desired maximum count of the result items on the page
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c pageNo is less than @c 1, or @n
	*										the specified @c countPerPage is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnReceivedBuddyRequestsReceivedN()
	*/
	result GetReceivedBuddyRequests(RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	* Gets the received buddy responses. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnReceivedBuddyResponsesReceivedN() is called.		
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code		
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @param[in]	pageNo					The page number of the result list @n
	*										It starts from @c 1.
	* @param[in]	countPerPage			The desired maximum count of the result items on the page
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c pageNo is less than @c 1, or @n
	*										the specified @c countPerPage is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnReceivedBuddyResponsesReceivedN()
	*/
	result GetReceivedResponses(RequestId& reqId, int pageNo=1, int countPerPage=20);
	
	/**
	* Deletes the received buddy responses. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnReceivedBuddyResponsesDeleted() is called.			
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code		
	* @param[in]	responseList			The list of buddy responses to delete @n
	*										The items of this list must be instances of Osp::Social::Services::BuddyResponse.	
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c responseList is empty.	
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnReceivedBuddyResponsesDeleted()
	*/
	result DeleteReceivedResponses(const Osp::Base::Collection::IList& responseList, RequestId& reqId);

	/**
	* Cancels the unanswered outgoing (sent) buddy request. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnSentBuddyRequestCanceled() is called.		
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	sentRequest				The sent buddy request
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c sentRequest is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnSentBuddyRequestCanceled()
	*/
	result CancelSentBuddyRequest(const SentBuddyRequest& sentRequest, RequestId& reqId);

	/**
	* Updates the attributes of the specified buddy. @n
	* This method saves the attributes (buddy label and friendship level) in Osp::Social::Services::Buddy on the server side. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyAttributeUpdated() is called.			
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	buddy					The buddy record containing the modified attributes	(buddy label and friendship level)	
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c buddy is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyAttributeUpdated()
	*/
	result UpdateBuddyAttribute(const Buddy& buddy, RequestId& reqId);

	/**
	* Gets all the buddies. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddiesReceivedN() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code		
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @param[in]	pageNo					The page number of the result list @n
	*										It starts from @c 1.
	* @param[in]	countPerPage			The desired maximum count of the result items on the page
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c pageNo is less than @c 1, or @n
	*										the specified @c countPerPage is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddiesReceivedN()
	*/
	result GetAllBuddies(RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	* Creates a buddy category. @n
	* Since the buddy category is identified by the name, the name must be unique within the scope of the user. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyCategoryCreated() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	categoryName			The name of category to be created
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified @c categoryName is an empty String, or @n
	*										the length of the specified @c categoryName exceeds #MAX_BUDDY_CATEGORY_NAME_LENGTH.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyCategoryCreated()
	*/
	result CreateCategory(const Osp::Base::String& categoryName, RequestId& reqId);

	/**
	* Deletes the specified buddy category. @n
	* A buddy category that contains buddies cannot be deleted. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyCategoryDeleted() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	category				The buddy category to be deleted
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c category is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyCategoryDeleted()
	*/
	result DeleteCategory(const BuddyCategory& category, RequestId& reqId);

	/**
	* Updates the name of the specified buddy category. @n
	* Since the buddy category is identified by the name, the name must be unique within the scope of the user. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyCategoryUpdated() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	category				The buddy category whose name is to be updated
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.	
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c category is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyCategoryUpdated()
	*/
	result UpdateCategory(const BuddyCategory& category, RequestId& reqId);

	/**
	* Gets all the buddy categories. @n
	* This method sends the request to the server and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyCategoriesReceivedN() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyCategoriesReceivedN()
	*/
	result GetAllCategories(RequestId& reqId);

	/**
	* Adds a buddy to the specified buddy category. @n
	* A buddy can belong to multiple categories. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddyAddedToCategory() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[in]	buddy					The buddy to be added
	* @param[in]	category				The buddy category to that the buddy is to be added
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c buddy or @c category is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyAddedToCategory()
	*/
	result AddBuddyToCategory(const Buddy& buddy, const BuddyCategory& category, RequestId& reqId);

	/**
	* Removes a buddy from the specified buddy category. @n
	* The removed member still remains a buddy.
	* This method sends the request to the server, and receives the response asynchronously.
	* When the request is completed, IBuddyServiceListener::OnBuddyRemovedFromCategory() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code	
	* @param[in]	buddy					The buddy to be removed
	* @param[in]	category				The buddy category from which the buddy is to be removed
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			The specified @c buddy or @c category is invalid.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddyRemovedFromCategory()
	*/
	result RemoveBuddyFromCategory(const Buddy& buddy, const BuddyCategory& category, RequestId& reqId);

	/**
	* Gets all the buddies from the specified buddy category. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddiesInCategoryReceivedN() is called.	
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n 
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code		
	* @param[in]	category				The buddy category from which all the buddies are to be displayed
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @param[in]	pageNo					The page number of the result list @n
	*										It starts from @c 1.
	* @param[in]	countPerPage			The desired maximum count of the result items on the page
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			Either of the following conditions has occurred: @n
	*										- The specified @c category is invalid.  @n
	*										- The specified @c pageNo is less than @c 1. @n
	*										- The specified @c countPerPage is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddiesInCategoryReceivedN()
	*/
	result GetAllBuddiesInCategory(const BuddyCategory& category, RequestId& reqId, int pageNo=1, int countPerPage=20);

	/**
	* Gets all the buddies signed up for the calling application. @n
	* This method sends the request to the server, and receives the response asynchronously. @n
	* When the request is completed, IBuddyServiceListener::OnBuddiesReceivedN() is called.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	BUDDY_SERVICE
	*
	* @pre			The user should be authenticated. @n
    *				For more information, see the sign-in application control (Osp::App::APPCONTROL_PROVIDER_SIGNIN).
	*
	* @return		An error code
	* @param[out]	reqId					The ID of the request that is sent to the server
	* @param[in]	pageNo					The page number of the result list @n
	*										It starts from @c 1.
	* @param[in]	countPerPage			The desired maximum count of the result items on the page
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG 			The specified @c pageNo is less than @c 1, or @n
	*										the specified @c countPerPage is less than @c 1.
	* @exception	E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @see	Construct(), IBuddyServiceListener::OnBuddiesReceivedN()
	*/
	result GetBuddiesUsingApp(RequestId& reqId, int pageNo=1, int countPerPage=20);

private:		
	IBuddyService* __pIBuddyService;
	void* __pMResponseListener; // class that implements _IBuddyServiceListener on Sc

	friend class BuddyServiceEx;
	class BuddyServiceEx* __pBuddyServiceEx;
}; // class BuddyService

};};};// Osp::Social::Services

#endif// _FSCL_SVC_BUDDY_SERVICE_H_
