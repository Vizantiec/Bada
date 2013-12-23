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
* @file			FCntIRemoteContentSharingListener.h 
* @brief		This is the header file for the %IRemoteContentSharingListener interface.
*
* This header file contains the declarations of the %IRemoteContentSharingListener interface.
*/
#ifndef _FCNT_IREMOTE_CONTENT_SHARING_LISTENER_H_
#define _FCNT_IREMOTE_CONTENT_SHARING_LISTENER_H_

// includes
#include "FBaseRt.h"
#include "FCntConstants.h"
#include "FSclSvcTypes.h"

namespace Osp { namespace Content { 
/**
 * @interface IRemoteContentSharingListener
 * @brief	This interface provides a listener that receives the events associated with RemoteContentSharing.
 * @deprecated	This interface is deprecated due to the operation policy of the bada Server. An alternate interface will be introduced in the near future.
 * @since	1.0
 *
 * The %IRemoteContentSharingListener interface provides a listener that receives the events associated with RemoteContentSharing.
 */
class _EXPORT_CONTENT_ IRemoteContentSharingListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * This is the virtual destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IRemoteContentSharingListener(void) {}

// Operation
public:
	/**
	* Called when the SetAccessLevel() method of RemoteContentSharing returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void  OnSetAccessLevelReceived(RequestId reqId, result r, 
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when the GetAccessLevel() method of RemoteContentSharing returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	level				The access level
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void OnGetAccessLevelReceived(RequestId reqId, Osp::Social::Services::AccessLevel level, result r,
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when the AddUserIdList() method of RemoteContentSharing returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void OnAddUsersToAclReceived(RequestId reqId, result r, 
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when the RemoveUserIdList() method of RemoteContentSharing returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void OnRemoveUsersFromAclReceived(RequestId reqId, result r, 
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;
	
	/**
	* Called when the RemoveAllUser() method of RemoteContentSharing returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void OnRemoveAllUsersFromAclReceived(RequestId reqId, result r, 
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when the GetUserIDList() method of RemoteContentSharing returns a result.
	* 
	* @since			1.0
	* @param[in]	reqId				The request ID
	* @param[in]	pUserIdList			The user ID list
	* @param[in]	r					The result
	* @param[in]	errorCode			The error code
	* @param[in]	errorMessage		The error message
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void OnGetUsersInAclReceivedN(RequestId reqId, Osp::Base::Collection::IList* pUserIdList, result r, 
		const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

};
};};// Osp::Content
#endif // _FCNT_IREMOTE_CONTENT_SHARING_LISTENER_H_
