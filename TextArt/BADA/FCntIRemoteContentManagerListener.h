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
 * @file		FCntIRemoteContentManagerListener.h
 * @brief		This is the header file for the %IRemoteContentManagerListener interface.
 *
 * This header file contains the declarations of the %IRemoteContentManagerListener interface.
 */

#ifndef _FCNT_IREMOTE_CONTENT_MANAGER_LISTENER_H_
#define _FCNT_IREMOTE_CONTENT_MANAGER_LISTENER_H_

#include <FCntRemoteContentInfo.h>
#include <FCntRemoteContentItemInfo.h>
#include <FBaseRt.h>
#include <FBaseTypes.h>

typedef Osp::Base::String ServerContentID;

namespace Osp { namespace Content {

/**
 * @interface	IRemoteContentManagerListener
 * @brief		This interface provides a listener that receives the events associated with RemoteContentManager.
 * @deprecated	This interface is deprecated due to the operation policy of the bada Server. An alternate interface will be introduced in the near future.
 * @since		1.0
 *
 * The %IRemoteContentManagerListener interface provides a listener that receives the events associated with RemoteContentManager.
 * An application needs to implement this interface to obtain notifications about the status of the content.
 *
 * The following example demonstrates how to use the %IRemoteContentManagerListener interface.
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
 * @endcode
 */
class IRemoteContentManagerListener : public virtual Osp::Base::Runtime::IEventListener
{

public:
	/**
	 * Called when the RemoteContentManager::GetContentInfo() method is implemented.
	 * 
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	pRemoteContentInfo	A pointer to RemoteContentInfo
	 * @param[in]	r					The result @n
	 *									This parameter can contain one of the exception codes. 
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server has failed.
	 * @exception	E_CONNECTION_FAILED	The network connection has failed.
	 */
	virtual void OnContentInfoReceivedN(RequestId reqId, RemoteContentInfo* pRemoteContentInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Notifies when the RemoteContentManager::GetContentItemInfo() method is implemented.
	 *
	 * @since		1.0
	 * @param[in]	reqId					The request ID
	 * @param[in]	pRemoteContentItemInfo	A pointer of RemoteContentItemInfo
	 * @param[in]	r						The result @n
	 *										This parameter can contain one of the exception codes.
	 * @param[in]	errorCode				The error code from the server
	 * @param[in]	errorMessage			The error message from the server
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SERVER				The request to the server failed.
	 * @exception	E_CONNECTION_FAILED 	Network connection failed.
	 */
	virtual void OnContentItemInfoReceivedN(RequestId reqId, RemoteContentItemInfo* pRemoteContentItemInfo, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) { }

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Notifies when the RemoteContentManager::ArchiveContent() method is implemented.
	 * 
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	r					The result @n
	 *									This parameter can contain one of the exception codes.
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server failed.
	 * @exception	E_CONNECTION_FAILED	Network connection failed.
	 */
	virtual void OnContentArchived(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage){ }

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	 * 			 and security-related issues that might arise after using this method.
	 *
	 * Notifies when the RemoteContentManager::PublishContent() method is implemented.
	 * 
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	r					The result @n
	 *									This parameter can contain one of the exception codes.
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server failed.
	 * @exception	E_CONNECTION_FAILED	Network connection failed.
	 */
	virtual void OnContentPublished(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage){ }

	/**
	 * Called when the RemoteContentManager::CreateContent() method is implemented.
	 * 
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	contentId			The content ID
	 * @param[in]	r					The result @n
	 *									This parameter can contain one of the exception codes. 
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server has failed.
	 * @exception	E_CONNECTION_FAILED	The network connection has failed.
	 */
	virtual void OnContentCreated(RequestId reqId, const Osp::Base::String& contentId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	 * Called when the RemoteContentManager::GetContentStatus() method is implemented.
	 *
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	contentStatus		The content's status
	 * @param[in]	r					The result @n
	 * 									This parameter can contain one of the exception codes.
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server has failed.
	 * @exception	E_CONNECTION_FAILED	The network connection has failed.
	 */
	virtual void OnContentStatusReceived(RequestId reqId, RemoteContentStatus contentStatus, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	 * Called when the RemoteContentManager::DeleteContent() method is implemented.
	 * 
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	r					The result @n
	 *									This parameter can contain one of the exception codes.
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server has failed.
	 * @exception	E_CONNECTION_FAILED	The network connection has failed.
	 */
	virtual void OnContentDeleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	 * Called when the RemoteContentManager::UpdateContent() method is implemented.
	 * 
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	r					The result @n
	 *									This parameter can contain one of the exception codes. 
	 * @param[in]	errorCode			The error code from the server
	 * @param[in]	errorMessage		The error message from the server
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SERVER			The request to the server has failed.
	 * @exception	E_CONNECTION_FAILED	The network connection has failed.
	 */
	virtual void OnContentUpdated(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

};	// class IRemoteContentManagerListener

}; };	// Osp::Content

#endif	// _FCNT_IREMOTE_CONTENT_MANAGER_LISTENER_H_
