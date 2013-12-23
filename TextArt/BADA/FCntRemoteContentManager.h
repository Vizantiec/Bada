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
* @file			FCntRemoteContentManager.h 
* @brief		This is the header file for the %RemoteContentManager class.
*
* This header file contains the declarations of the %RemoteContentManager class.
*/

#ifndef _FCNT_REMOTE_CONTENT_MANAGER_H_
#define _FCNT_REMOTE_CONTENT_MANAGER_H_

#include <FCntConstants.h>
#include <FCntIRemoteContentManagerListener.h>

struct IRemoteContentManager;
struct __ContentManagerSCListener;

namespace Osp { namespace Content {

class RemoteContentManagerEx;

/**
* @class		RemoteContentManager
* @brief		This class manages the remote content management.
* @deprecated	This class is deprecated due to the operation policy of the bada Server. An alternate class will be introduced in the near future.
* @since		1.0
*
* @pre		User should be authenticated. @n 
*
*			For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN)
* @pre		RemoteContent type setup, <a href="#" onClick="window.open('http://developer.bada.com/apis/myapp/setUpYourComponent.do')">
*            Component Setup</a> should be done.
*
* The %RemoteContentManager class manages the server content. 
* The contents information for the server content can be created, read, deleted, or updated through RemoteContentInfo.
* 
* The following example demonstrates how to use the %RemoteContentManager class.
*
* @code
* /////////////////////////////////////
* // TestApp.h
*
* class UtsContentManagerListener : public IRemoteContentManagerListener
* {
*  public:
*		UtsContentManagerListener() {}
*		~UtsContentManagerListener() {}
*
*		virtual void OnContentInfoReceivedN(RequestId reqId, RemoteContentInfo* pRemoteContentInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentCreated(RequestId reqId, const Osp::Base::String& contentId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentStatusReceived(RequestId reqId, RemoteContentStatus contentStatus, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
*		virtual void OnContentUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
* };
*
*
* /////////////////////////////////////
* // TestApp.cpp
*
* void 
* UtsContentManagerListener::OnContentInfoReceivedN(RequestId reqId, RemoteContentInfo* pRemoteContentInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void 
* UtsContentManagerListener::OnContentCreated(RequestId reqId, const Osp::Base::String& contentId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void 
* UtsContentManagerListener::OnContentDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void 
* UtsContentManagerListener::OnContentStatusReceived(RequestId reqId, RemoteContentStatus contentStatus, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* void 
* UtsContentManagerListener::OnContentUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage)
* {
*		// Do something
* }
*
* result
* MyClass::TestRemoteContentManager()
* {
*		RemoteContentManager remoteContentManager;
*		RemoteContentInfo remoteContentInfo;
*		UtsContentManagerListener managerListener;
*		Osp::Base::String contentId;
*		RequestId reqId;
*		result r = E_SUCCESS;
*
*		r = remoteContentManager.Construct(managerListener);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		Osp::Base::Utility::Uri uri;
*		uri.SetPath(L"Image.jpg");
*		r = remoteContentInfo.Construct(L"Image", uri, 12345);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		r = remoteContentInfo.SetContentName(L"UTcGetContentInfoP01");
*		TryReturn(!IsFailed(r), r, "SetContentName failed.");
*		r = remoteContentInfo.SetKeyword(L"lee, kyeong, woo");
*		TryReturn(!IsFailed(r), r, "SetKeyword failed.");
*
*		// Creates
*		r = remoteContentManager.CreateContent(remoteContentInfo, reqId);
*		TryReturn(!IsFailed(r), r, "CreateContent failed.");
*
*		// The result will be returned to UtsContentManagerListener::OnContentCreated().
*		// The result is the content ID.
*	
*		// Gets
*		r = remoteContentManager.GetContentInfo(contentId, reqId);
*		TryReturn(!IsFailed(r), r, "GetContentInfo failed.");
*
*		// The result will be returned to UtsContentManagerListener::OnContentInfoReceivedN().
*		// The result is an instance of RemoteContentInfo.
*
*		// Updates
*		r = remoteContentInfo.SetContentName(L"sample code");
*		TryReturn(!IsFailed(r), r, "SetContentName failed.");
*		r = remoteContentInfo.SetKeyword(L"lee, kyeong, woo, hi");
*		TryReturn(!IsFailed(r), r, "SetKeyword failed.");
*		r = remoteContentInfo.SetProvider(L"smybag");
*		TryReturn(!IsFailed(r), r, "SetProvider failed.");
*		r = remoteContentManager.UpdateContent(remoteContentInfo, reqId);
*		TryReturn(!IsFailed(r), r, "UpdateContent failed.");
*
*		// The result is returned to UtsContentManagerListener::OnContentUpdated().
*
*		// Checks the contents status
*		r = remoteContentManager.GetContentStatus(contentId, reqId);
*		TryReturn(!IsFailed(r), r, "GetContentStatus failed.");
*
*		// The result is returned to UtsContentManagerListener::OnContentStatusReceived().
*
*		// Delete
*		r = remoteContentManager.DeleteContent(contentId, reqId);
*		TryReturn(!IsFailed(r), r, "DeleteContent failed.");
*
*		// The result is returned to UtsContentManagerListener::OnContentDeleted().
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ RemoteContentManager :	public Osp::Base::Object
{

public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	RemoteContentManager(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~RemoteContentManager(void);

	/**
	* Initializes this instance of %RemoteContentManager with the specified listener of type IRemoteContentManagerListener.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	listener			A reference to %IRemoteContentManagerListener
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	result Construct(const IRemoteContentManagerListener& listener);

	/**
	* Gets the information of the content.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n
	*               For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	serverContentId		The server content ID
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result GetContentInfo(const Osp::Base::String& serverContentId, RequestId& reqId) const;

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Gets the content item information.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
	*				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	serverContentId		The server content ID
	* @param[in]	serverContentItemId	The server content item ID
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		Insufficient memory.
	*/
	result GetContentItemInfo(const Osp::Base::String& serverContentId, const Osp::Base::String& serverContentItemId, RequestId& reqId) const;

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* Publishes the content.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
    *				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	serverContentId		The server contents ID
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		Insufficient memory.
	*/
	result PublishContent(const Osp::Base::String& serverContentId, RequestId& reqId);

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	*		 	and security-related issues that might arise after using this method.
	*
	* Archive the contents.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
    *				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	serverContentId		The server contents ID
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		Insufficient memory.
	*/
	result ArchiveContent(const Osp::Base::String& serverContentId, RequestId& reqId);

	/**
	* Creates the content.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
	*				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	remoteContentInfo	A reference to the RemoteContentInfo instance
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result CreateContent(const RemoteContentInfo& remoteContentInfo, RequestId& reqId);

	/**
	* Updates the content.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
	*				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	remoteContentInfo	A reference to the RemoteContentInfo instance
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result UpdateContent(const RemoteContentInfo& remoteContentInfo, RequestId& reqId);

	/**
	* Gets the contents status.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
	*				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	serverContentId		The server contents ID
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result GetContentStatus(const Osp::Base::String& serverContentId, RequestId& reqId);

	/**
	* Deletes the contents.
	*
	* @since		1.0
	* @privlevel	SYSTEM
	* @privgroup	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
	*				For more information, see the sign in Application control (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	serverContentId		The server content ID
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result DeleteContent(const Osp::Base::String& serverContentId, RequestId& reqId);


private:
	IRemoteContentManager* __pIRemoteContentManager;			// SC instance
	IRemoteContentManagerListener* __pIContentManagerListener;	// for applications
	__ContentManagerSCListener* __pContentManagerListener;		// for SC Listener

	friend class RemoteContentManagerEx;
	class RemoteContentManagerEx* __pRemoteContentManagerEx;

};	// class RemoteContentManager

}; };	// Osp::Content

#endif	// _FCNT_REMOTE_CONTENT_MANAGER_H_
