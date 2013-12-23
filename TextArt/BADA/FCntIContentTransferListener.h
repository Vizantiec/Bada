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
* @file			FCntIContentTransferListener.h 
* @brief		This is the header file for the %IContentTransferListener interface.
*
* This header file contains the declarations of the %IContentTransferListener interface.
*/
#ifndef _FCNT_ICONTENT_TRANSFER_LISTENER_H_
#define _FCNT_ICONTENT_TRANSFER_LISTENER_H_

// Includes
#include "FBaseRt.h"
#include "FCntConstants.h"
#include "FCntDownloadDescriptor.h"

namespace Osp { namespace Content { 
/**
 * @interface IContentTransferListener
 * @brief	This interface provides the event handlers that receive the events associated with ContentTransfer.
 * @since	1.0
 *
 * The %IContentTransferListener interface handles the content download events.
 */
class _EXPORT_CONTENT_ IContentTransferListener :
	public Osp::Base::Runtime::IEventListener
{
// Lifecycle
public:

	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency,
	* 			and security-related issues that might arise after using this method.
	*
	* This is the virtual destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~IContentTransferListener(void) {}

// Operation
public:

	/**
	 * Gets the progress information when the data is being uploaded or downloaded.
	 *
	 * @since			1.0
	 * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompOnContentTransferInProgressPage "here".
	 *
	 * @param[in]	reqId			The request ID
	 * @param[in]	totalTransferedSize		The total size of the data to be transferred in bytes 
	 */
	virtual void OnContentTransferInProgress(RequestId reqId, int totalTransferedSize) = 0;

	/**
	* @page          CompOnContentTransferInProgressPage Compatibility for OnContentTransferInProgress( )
	* @section       CompOnContentTransferInProgressPageIssueSection Issues
	*                Implementation of this method in bada API versions prior to 2.0 has the following issue:
	* -# The specified @c reqId does not contain a similar value as compared to the one specified for the relative methods, such as Download() and Upload().
	*
	* @section        CompOnContentTransferInProgressPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/

	/**
	* Called when an upload operation is completed.
	*
	* @deprecated  This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future.
	* @since			1.0
	* @param[in]	reqId		The request ID
	* @param[in]	r			The result of the upload
	* @param[in]	errorCode	The error code from the server
	* @param[in]	errorMessage	The error message from the server
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*/
	virtual void OnContentUploadCompleted(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when a download operation is completed.
	*
	* @since			1.0
	* @param[in]	reqId		The request ID
	* @param[in]	contentId	The registered content ID
	* @param[in]	r			The result of the download
	* @param[in]	errorCode	The error code from the server
	* @param[in]	errorMessage	The error message from the server
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	* @exception	E_ILLEGAL_ACCESS	The request to access a server is illegal.
	* @exception	E_STORAGE_FULL		The storage is full.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM		A system error has occurred.
	*/
	virtual void OnContentDownloadCompleted(RequestId reqId, ContentId contentId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when a download-to-buffer operation is completed.
	*
	* @since			1.0
	* @param[in]	reqId		The request ID
	* @param[in]	pBuffer		The binary buffer that has been downloaded
	* @param[in]	r			The result of the download
	* @param[in]	errorCode	The error code from the server
	* @param[in]	errorMessage	The error message from the server
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	* @exception	E_FILE_ALREADY_EXIST The specified file already exists.
	* @exception	E_STORAGE_FULL		The storage is full.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	* @exception	E_ILLEGAL_ACCESS	The request to access a server is illegal.
	* @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	* @exception	E_SYSTEM		A system error has occurred.
	*/
	virtual void OnContentDownloadToBufferCompleted(RequestId reqId, Osp::Base::ByteBuffer* pBuffer, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;

	/**
	* Called when an OMA download descriptor is received.
	*
	* @deprecated This method is deprecated as OMA download is currently not supported.
	* @since			1.0
	* @param[in]	reqId		The request ID
	* @param[in]	descriptor		The download descriptor
	*/
	virtual void OnDownloadDescriptorReceived(RequestId reqId, const DownloadDescriptor& descriptor) = 0;

	/**
	* Called when a transfer (upload/download) operation is cancelled.
	*
	* @since			1.0
	* @param[in]	reqId		The request ID
	* @param[in]	r			The result of the transfer
	* @param[in]	errorCode	The error code from the server
	* @param[in]	errorMessage	The error message from the server
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SERVER		An error has occurred on the server side.
	*/
	virtual void OnContentTransferCanceled(RequestId reqId, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMessage) = 0;
};
};};// Osp::Content
#endif // _FCNT_ICONTENT_TRANSFER_LISTENER_H_
