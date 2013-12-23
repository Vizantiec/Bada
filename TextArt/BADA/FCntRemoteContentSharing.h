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
* @file			FCntRemoteContentSharing.h
* @brief		This is the header file for the %RemoteContentSharing class.
*
* This header file contains the declarations of the %RemoteContentSharing class.
*/
#ifndef _FCNT_REMOTE_CONTENT_SHARING_H_
#define _FCNT_REMOTE_CONTENT_SHARING_H_

// includes
#include "FCntIRemoteContentSharingListener.h"

struct MOspRestClient;
struct MRemoteContentSharingRestClient;

namespace Osp { namespace Content {
class RemoteContentSharingEx;
/**
 * @class	RemoteContentSharing
 * @brief	This class contains the methods to share contents on the bada Server.
 * @deprecated	This class is deprecated due to the operation policy of the bada Server. An alternate class will be introduced in the near future.
 * @since	1.0
 *
 * The %RemoteContentSharing class contains the methods to share contents on the bada Server. @n
 * It provides the following functionalities: @n
 * - Sets/Gets an access level to the content on the bada Server @n
 * - Sets/Gets user's access control to the content on the bada Server @n
 * - Removes an access level and the user's access control @n
 *
 * The applications set the access level to other users, who can search the published remote content and download a remote content file. 
 * However, as only read rights are available, no modifications can be made to the content of another user.
 * When a remote content is created, ACCESS_NONE is set as default value. It means that only the owner
 * can access the content. @n
 *
 * @b Access @b Level @n
 *
 * 	ACCESS_NONE		: Share with no one in particular. Can add specific users later. @n
 *	ACCESS_BUDDY	: Only buddies can access. @n
 *	ACCESS_ALL_USERS	: Share with all. No restrictions.
 *
 * The following example demonstrates how to set access level to all users.
 * 
 *
 * @code
	//Declaration of MyClass.
 class  MyClass
 :public Osp::Content::IRemoteContentSharing
 {
 // Lifecycle
 public:
	MyClass(void);
	virtual ~MyClass(void);

 // Implementation
 public:
	void  OnSetAccessLevelReceived(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
	void OnGetAccessLevelReceived(RequestId reqId, Osp::Social::Services::AccessLevel level, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
	void OnAddUsersToAclReceived(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
	void OnRemoveUsersFromAclReceived(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
	void OnRemoveAllUsersFromAclReceived(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
	void OnGetUsersInAclReceivedN(RequestId reqId, Osp::Base::Collection::IList* pUserIdList, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage);
 private:
	Osp::Content::RemoteContentSharing __sharing;
 };
 *
 *
 * The following sample explains how to set access level to all users.
 * @code
 result
 MyClass::RequestSetAccessLevel(const String& remoteContentInfo)
 {
	result r = E_SUCCESS;
	RequestId requestId;

	__sharing.Construct(*this);

	r = __sharing.SetAccessLevel(__contentId, Osp::Social::Services::ACCESS_ALL_USERS, requestId);
 }
 * @endcode
 */
class _EXPORT_CONTENT_ RemoteContentSharing :
		public Osp::Base::Object
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	RemoteContentSharing(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual~RemoteContentSharing(void);

	/**
	* Initializes this instance of %RemoteContentSharing with the specified listener. @n
	* This method should be called after an instance is constructed.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]      listener             A reference to IRemoteContentSharingListener
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE This instance has already been constructed.
	*/
	result Construct(const IRemoteContentSharingListener& listener);

// Operation
public:
	/**
	* Sets an access level to a file on the bada Server. @n
	* An application is notified via the IRemoteContentSharingListener::OnSetAccessLevelReceived() method when the result is received.
	*
	* @since			1.0
	* @privlevel	SYSTEM
	* @privgroup 	REMOTE_CONTENT
	*
  * @pre			User should be authenticated. @n 
  *				For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	* 
	* @return	An error code
	* @param[in]	remoteContentId		The remote content ID
	* @param[in]	level				The access level (all, buddy, close)
	* @param[out]	reqId				The request ID
	*
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result SetAccessLevel(const Osp::Base::String& remoteContentId, Osp::Social::Services::AccessLevel level, RequestId& reqId);

	/**
	* Gets the access level of the specified file. @n
	* An application is notified via the IRemoteContentSharingListener::OnGetAccessLevelReceived() method when the result is received.
	*
	* @since		1.0
  * @pre			User should be authenticated. @n 
  *				For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @privlevel	SYSTEM
	* @privgroup 	REMOTE_CONTENT
	*
	* @return	An error code
	* @param[in]	remoteContentId		The remote content ID
	* @param[out]	reqId				The request ID
	*
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* @see	IRemoteContentSharingListener::OnGetAccessLevelReceived()
	*/
	result GetAccessLevel(const Osp::Base::String& remoteContentId, RequestId& reqId);

	/**
	* Adds the user ID list. @n
	* An application is notified via the IRemoteContentSharingListener::OnAddUserIdListReceived() method when the result is received.
	*
	* @since			1.0
	* @privlevel	SYSTEM
	* @privgroup 	REMOTE_CONTENT
	*
  * @pre			User should be authenticated. @n 
  *				For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return	An error code
	* @param[in]	remoteContentId		The remote content ID
	* @param[in]	userIdList			The user ID list
	* @param[out]	reqId				The request ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* @see	IRemoteContentSharingListener::OnAddUsersToAclReceived()
	*/
	result AddUsersToAcl(const Osp::Base::String& remoteContentId, const Osp::Base::Collection::IList& userIdList, RequestId& reqId);

	/**
	* Removes the user ID list. @n
	* An application is notified via the IRemoteContentSharingListener::OnRemoveUserIdListReceived() method when the result is received.
	*
	* @since			1.0
	* @privlevel	SYSTEM
	* @privgroup 	REMOTE_CONTENT
	*
  * @pre			User should be authenticated. @n 
  *				For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	remoteContentId		The remote content ID
	* @param[in]	userIdList			The user ID list
	* @param[out]	reqId				The request ID
	*
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* @see	IRemoteContentSharingListener::OnRemoveUsersFromAclReceived()
	*/
	result RemoveUsersFromAcl(const Osp::Base::String& remoteContentId, const Osp::Base::Collection::IList& userIdList, RequestId& reqId);

	/**
	* Removes all the users. @n
	* An application is notified via the IRemoteContentSharingListener::OnRemoveAllUserReceived() method when the result is received.
	*
	* @since			1.0
	* @privlevel	SYSTEM
	* @privgroup 	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
  *				For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return		An error code
	* @param[in]	remoteContentId		The remote content ID
	* @param[out]	reqId				The request ID
	*
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	*/
	result RemoveAllUsersFromAcl(const Osp::Base::String& remoteContentId, RequestId& reqId);

	/**
	* Gets the user ID list. @n
	* An application is notified via the IRemoteContentSharingListener::OnGetUserIDListReceived() method when the result is received. 
	*
	* @since			1.0
	* @privlevel	SYSTEM
	* @privgroup 	REMOTE_CONTENT
	*
	* @pre			User should be authenticated. @n 
  *				For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return	An error code
	* @param[in]	remoteContentId		The remote content ID
	* @param[out]	reqId				The request ID
	*
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* @see	IRemoteContentSharingListener::OnGetUsersInAclReceivedN()
	*/
	result GetUsersInAcl(const Osp::Base::String& remoteContentId, RequestId& reqId);

// Attribute
private:
	MOspRestClient* __pRestClient;
	MRemoteContentSharingRestClient* __pRemoteContentSharingRestClient;

	friend class RemoteContentSharingEx;
	class RemoteContentSharingEx* __pRemoteContentSharingEx;

};
};};// Osp::Content
#endif //_FCNT_REMOTE_CONTENT_SHARING_H_
