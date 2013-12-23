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
* @file			FCntContentTransfer.h
* @brief		This is the header file for the %ContentTransfer class.
*
* This header file contains the declarations of the %ContentTransfer class.
*/
#ifndef _FCNT_CONTENT_TRANSFER_H_
#define _FCNT_CONTENT_TRANSFER_H_

struct IContentTransfer;

// Includes
#include "FCntConstants.h"
#include "FCntIContentTransferListener.h"
#include "FCntRemoteContentInfo.h"
#include "FCntContentTransferInfo.h"
#include "FBaseRtTimer.h"

struct __IContentTransferListenerImpl;


namespace Osp { namespace Content {
class __ContentTransferEvent;
class ContentTransferEx;
/**
 * @class	ContentTransfer
 * @brief	This class provides the methods to download the content.
 * @since	1.0
 *
 *
 * The %ContentTransfer class provides the following features:
 * - Downloading the content from the servers that support HTTP access
 * - Cancelling a download operation @n
 *
 * HTTP download (ContentTransfer::Download()) is a standard HTTP transaction using the HTTP GET request and response methods.
 *
 * The following example demonstrates how to download a content file.
 *
 * @code
 class  MyClass
 :public Osp::Content::IContentTransferListener
 {
 public:
	MyClass(void);
	virtual ~MyClass(void);

 public:
	void OnContentTransferInProgress(RequestId requestID, int totalReceivedSize);
	void OnContentUploadCompleted(RequestId requestID, result res, const String& errorCode, const String& errorMessage);
	void OnContentDownloadCompleted(RequestId requestID, ContentId contentID, result res, const String& errorCode, const String& errorMessage);
	void OnContentDownloadToBufferCompleted(RequestId reqId, ByteBuffer* pBuffer, result r, const String& errorCode, const String& errorMessage);
	void OnDownloadDescriptorReceived(RequestId requestID, const DownloadDescriptor& description);
	void OnContentTransferCanceled(RequestId reqId, result res, const String& errorCode, const String& errorMessage);
 };

 // Implementation for the listener function and Implementation of other listener function is
 void MyClass::OnContentDownloadCompleted(RequestId requestID, ContentId contentID, result res, const String& errorCode, const String& errorMessage)
 {
 	 result r = E_SUCCESS;
 	 ContentManager contentManager;
 	 ContentInfo* pContentInfo = null;

 	 // Error check
 	 TryReturn(!IsFailed(res), r, "Download Error [%s]", GetErrorMessage(res));

 	 // Do something
 	 r = contentManager.Construct();
     TryCatch(!IsFailed(r), r, "Construct failed.");

     // Get ContentInfo
     pContentInfo = contentManager.GetContentInfoN(contentID);
 CATCH:
  	 if (pContentInfo)
  	 	 delete pContentInfo;
 }
 
 result
 MyClass::RequestDownload(void)
 {
	RequestId requestId;
	Uri contentUri;
	int contentSize;
	String downloadPath;

	result r = contentTransfer.Construct(*this);
	TryReturn(!IsFailed(r), r, ("Construct is failed.\n"));

	// TODO: set uri and download path

	r = contentTransfer.Download(contentUri, downloadPath, requestId, false);
	TryReturn(!IsFailed(r), r, ("Download Request is failed.\n"));
 }
 * @endcode
 *
 */
class _EXPORT_CONTENT_ ContentTransfer :
		public Osp::Base::Object,
		public Osp::Base::Runtime::ITimerEventListener
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	ContentTransfer(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual~ContentTransfer(void);

	/**
	* Initializes this instance of %ContentTransfer with the specified parameter. @n
	* This method should be called after every instance of %ContentTransfer is constructed.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	listener		A reference to IContentTransferListener
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE This instance has already been constructed.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_SYSTEM	A system error has occurred.
	*/
	result Construct(const IContentTransferListener& listener);

// Operation
public:
	/**
	* Downloads a content file from the bada Server or from any other content provider's server. @n
	* The @c filesize parameter is used to check the limitation of the local volume. If this parameter is set to @c 0, this method will not check the volume.
	* An application should set the full destination path for the downloaded contents. When the content is downloaded to one of the following paths, this method internally registers the content using ContentManager.
	* - /Media/
	* - /Storagecard/Media/ @n
	*
	* When the download is completed, the application is notified via the IContentTransferListener::OnContentDownloadCompleted() method. @n
	* When the data is being downloaded, the application is notified of the progress via the IContentTransferListener::OnContentTransferInProgress() method. @n
	* When the Open Mobile Alliance (OMA) Download Descriptor is received, the application is notified via the IContentTransferListener::OnDownloadDescriptorReceived() method.
	*
	* @deprecated This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future. 
	* When downloading the contents from a third party server, it is recommended to use the Download(const Osp::Base::Utility::Uri& uri, const Osp::Base::String& filePath, RequestId& reqId, bool replace = false, int timeout = 0, int progessInterval = 0) method.
	*
	* @since				 1.0
	* @compatibility This method has compatibility issues with different bada API versions. @n
	*                For more information, see issues in version @ref CompContentTransferDownloadPage "1.2" and @ref CompContentTransferDownloadPage2 "2.0".
	*
	* @privlevel	SYSTEM
	* @privgroup 	CONTENT_TRANSFER
	*
	* @pre If the user accesses the bada Server with workspace path (remote://),
	*      the user should be authenticated.
	*
    *  For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	*
	* @return	An error code
	* @param[in]	uri					The content URL (http://, remote://)
	* @param[in]	fileSize			The content file size in bytes  @n
	*									If set to @c 0, the method does not check the storage limitation.
	* @param[in]	destFilePath		The full destination path
	* @param[in]	replace				The replace option of the destination file @n
	*									Set to @c true to replace the file, @n
	*									else @c false.
	* @param[out]	reqId				The request ID
	* @param[in]	pListener			A pointer to the IContentTransferListener instance
	* @param[in]	sec					The timeout period in seconds
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST The specified file already exists.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception 	E_IN_PROGRESS		A previous request is in progress.
	* @see	IContentTransferListener::OnContentDownloadCompleted()
	* @see	IContentTransferListener::OnContentTransferInProgress()
	* @see	IContentTransferListener::OnDownloadDescriptorReceived()
	*/
	result Download(const Osp::Base::Utility::Uri& uri, int fileSize, const Osp::Base::String& destFilePath, bool replace, RequestId& reqId,
		const IContentTransferListener* pListener = null, int sec = 0);

	/**
	* @page          CompContentTransferDownloadPage Compatibility for Download( )
	* @section       CompContentTransferDownloadPageIssueSection Issues
	*                Implementation of this method in bada API versions prior to 1.2 has the following issue:
	* -# When the %Web server of the given URI does not give the MIME type in its response, the download fails.
	*
	* @section        CompContentTransferDownloadPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*/
	
	/**
	* @page          CompContentTransferDownloadPage2 Compatibility for Download( )
	* @section       CompContentTransferDownloadPageIssueSection Issues
	*                Implementation of this method in bada API versions prior to 2.0 has the following issues:
	* -# When the MIME type of the given URI is not the media type, the content is not internally registered. @n
	* -# When the destination path is invalid, Download() returns E_SUCCESS and IContentTransferListener::OnContentDownloadCompleted() returns several error codes.
	* @section        CompContentTransferDownloadPageIssueSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0 as follows:
	* -# When the destination path is invalid, Download() returns E_INVALID_ARG and %IContentTransferListener::OnContentDownloadCompleted() is not invoked.
	*/

	/**
	* Downloads a content file to a buffer from the bada Server or from any other content provider's servers.
	* This method does not register the content. @n
	*
	* When the download is completed, the application is notified via the IContentTransferListener::OnContentDownloadToBufferCompleted() method. @n
	* When the data is being downloaded, the application is notified of the progress via the IContentTransferListener::OnContentTransferInProgress() method.
	*
	* @deprecated This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future. 
	* When downloading the contents to a buffer from a third party server, it is recommended to use the DownloadToBuffer(const Osp::Base::Utility::Uri& uri, RequestId& reqId, int timeout = 0, int progressInterval = 0) method.
	*
	* @since				 1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*                    For more information, see @ref CompContentTransferDownloadToBufferPage "here".	
	*
	* @privlevel	SYSTEM
	* @privgroup 	CONTENT_TRANSFER
	*
	* @pre If the user accesses the bada Server with workspace path (remote://),
	*      the user should be authenticated.
	*
	*      For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	* @return	An error code
	* @param[in]	uri					The content URL (http://, remote://)
	* @param[in]	fileSize			The content file size in bytes @n
	*									If set to @c 0, the method does not check the storage limitation.
	* @param[out]	reqId				The request ID
	* @param[in]	pListener			A pointer to the IContentTransferListener instance
	* @param[in]	sec					The timeout period in seconds
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* @see	IContentTransferListener::OnContentDownloadToBufferCompleted()
	* @see	IContentTransferListener::OnContentTransferInProgress()
	*/
	result DownloadToBuffer(const Osp::Base::Utility::Uri& uri, int fileSize, RequestId& reqId,
		const IContentTransferListener* pListener = null, int sec = 0);

	/**
	* @page          CompContentTransferDownloadToBufferPage Compatibility for Download( )
	* @section       CompContentTransferDownloadToBufferPageIssueSection Issues
	*                Implementation of this method in bada API versions prior to 1.2 has the following issue:
	* -# When the %Web server of the given URI does not give the MIME type in its response, the download fails.
	*
	* @section        CompContentTransferDownloadToBufferPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*/

	/**
	* Downloads a content file from the server with the OMA Download Descriptor received from IContentTransferListener::OnDownloadDescriptorReceived(). @n
	*
	* When the download is completed, the application is notified via the IContentTransferListener::OnContentDownloadCompleted method(). @n
	* When the data is being downloaded, the application is notified of the progress via the IContentTransferListener::OnContentTransferInProgress method().
	*
	* @deprecated    This method is deprecated because it does not work as expected. From bada API version 2.0, invoking this method will always return E_UNSUPPORTED_OPERATION.
	* @since			1.0
	* @privlevel	SYSTEM
	* @privgroup 	CONTENT_TRANSFER
	*
	* @pre If the user accesses the bada Server with workspace path (remote://),
	*      the user should be authenticated.
	*
    *      For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	* @return	An error code
	* @param[in]	descriptor			An instance of the DownloadDescriptor class
	* @param[in]	destFilePath		The full destination path
	* @param[in]	replace				The replace option of the destination file @n
	*									Set to @c true to replace the file, @n
	*									else @c false.
	* @param[out]	reqId				The request ID
	* @param[in]	pListener			A pointer to the IContentTransferListener instance
	* @param[in]	sec					The timeout period in seconds
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	* @exception	E_FILE_ALREADY_EXIST The specified file already exists.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception 	E_UNSUPPORTED_OPERATION This operation is not supported. @b since: @b 2.0.
	*
	* @see	IContentTransferListener::OnContentDownloadCompleted()
	* @see	IContentTransferListener::OnContentTransferInProgress()
	* @see	IContentTransferListener::OnDownloadDescriptorReceived()
	*/
	result OmaDownload(const DownloadDescriptor& descriptor, const Osp::Base::String& destFilePath, bool replace, RequestId& reqId,
		const IContentTransferListener* pListener = null, int sec = 0);

	/**
	* Uploads a content file to the bada Server's workspace. The logical path is internally created using a destination file path on the device. @n
	* The bada Server needs a file size to check for the user's storage limit. @n
	*
	* When the upload is completed, the application is notified via the IContentTransferListener::OnContentUploadCompleted() method. @n
	* When data is being uploaded or downloaded, the application is notified via the IContentTransferListener::OnContentTransferInProgress() method.
	*
	* @deprecated  This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future.
	* @since			1.0
	* @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                   For more information, see @ref CompContentTransferUploadPage "here".
	*
	* @privlevel	SYSTEM
	* @privgroup 	CONTENT_TRANSFER
	*
	* @pre User should be authenticated.
	*
    *      For more information, see Sign-in AppControl (Osp::App::APPCONTROL_SIGNIN).
	* @return	An error code
	* @param[in]	srcFilePath		The source file path
	* @param[in]	destFilePath	The destination path to the bada Server's workspace (cf. /image/a.jpg) @n
	* 								The path should be an absolute path. @n
	* 								Reserved characters ( \ / ? % * : ; | " < > ).
	* @param[in]	replace			The replace option of the destination file @n
	*								Set to @c true to replace the file, @n
	*                           else @c false.
	* @param[out]	uri				The logical path of the bada Server (cf. remote://app/[myappid]/user/[userid]/image/a.jpg)
	* @param[out]	reqId			The request ID
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	* @exception	E_FILE_NOT_FOUND The specified file cannot be found or accessed.
	* @exception	E_ILLEGAL_ACCESS	The request to access a server is illegal.
	* @exception	E_STORAGE_FULL		The storage is full.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_CONNECTION_FAILED The server connection has failed.
	*
	* @see	IContentTransferListener::OnContentUploadCompleted()
	* @see	IContentTransferListener::OnContentTransferInProgress()
	*/
	result Upload(const Osp::Base::String& srcFilePath, const Osp::Base::String& destFilePath, bool replace, Osp::Base::Utility::Uri& uri, RequestId& reqId);

	/**
	* @page          CompContentTransferUploadPage Compatibility for Upload()
	* @section       CompContentTransferUploadPageIssueSection Issues
	*                Implementation of this method in bada API versions prior to 2.0 has the following issue:
	* -# If the destFilePath does not start with '/', this method returns E_INVALID_ARG. Subsequently, this method will return E_INVALID_STATE from the next upload request.
	*
	* @section        CompContentTransferUploadPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/
	
	/**
	* Cancels a transfer operation. @n
	* The downloaded file is deleted from the file system.
	*
	* When a transfer (upload/download) operation is canceled, the application is notified via the IContentTransferListener::OnContentTransferCanceled() method.
	*
	* @since			1.0
	* @return			An error code
	* @param[in]	reqId			The request ID
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OBJ_NOT_FOUND The specified @c reqId is not found.
	* @exception	E_INVALID_ARG	The specified input parameter is invalid.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	*
	* @see IContentTransferListener::OnContentTransferCanceled()
	*/
	result Cancel(RequestId reqId);

	/**
	* Sets the default timeout period. @n
	* If the server does not respond during the timeout period, the network connection is closed.
	* @c 0 or minus second means unlimited period.
	*
	* @since			1.0
	* @param[in]	sec			The default timeout period in seconds @n
	* 							The default value is @c 0.
	*/
	void SetDefaultTimeout(int sec);

	/**
	* Gets the default timeout period.
	*
	* @since	1.0
	* @return	The default timeout period
	*/
	int GetDefaultTimeout(void);

	/**
	* Removes a transfer operation. @n
	* This operation removes a request for multiple downloads.
	* A download operation in progress is not removed by this operation.
	*
	* @since			1.0
	* @compatibility    This method has compatibility issues between bada API versions @b prior @b to @b 2.0. @n
	*                   For more information, see @ref CompContentTransferRemovePage "here".
	* 
	* @return			An error code
	* @param[in] reqId The request ID
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OBJ_NOT_FOUND The specified @c reqId is not found.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	* @remarks 		To stop an on-going transfer, use the Cancel() method.
	*/
	result Remove(RequestId reqId);

	/**
	* @page          CompContentTransferRemovePage Compatibility for Remove( )
	* @section       CompContentTransferRemovePageIssueSection Issues
	*                Implementation of this method in API versions prior to 2.0 has the following issue: @n
	*
	* -# When this method is used without construct(), this method does not work as per expectations. 
	* @section        CompContentTransferRemovePageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 @n
	* When this method is used without construct(), Remove() returns E_INVALID_STATE.
	*/

	/**
	* Removes all the transfer operations. @n
	* This operation removes all the requests for multiple downloads.
	* The download operations in progress are not removed by this operation.
	*
	* @since			1.0
	* @compatibility    This method has compatibility issues between bada API versions @b prior @b to @b 2.0. @n
	* 		For more information, see @ref CompContentTransferRemoveAllPage "here".
	* @return			An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	* @remarks 		To stop an on-going transfer, use the Cancel() method.
	*/
	result RemoveAll(void);

	/**
	* @page          CompContentTransferRemoveAllPage Compatibility for RemoveAll( )
	* @section       CompContentTransferRemoveAllPageIssueSection Issues
	*                Implementation of this method in API versions prior to 2.0 has the following issue: @n
	*
	* -# When this method is used without construct(), this method does not work as per expectations. 
	* @section        CompContentTransferRemoveAllPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 @n
	* When this method is used without construct(), RemoveAll() returns E_INVALID_STATE.
	*/

	/**
	* Cancels all the operations in progress.
	*
	* @since			1.0
	* @compatibility    This method has compatibility issues between bada API versions @b prior @b to @b 2.0. @n
	*                   For more information, see @ref CompContentTransferCancelAllPage "here".
	* 
	* @return			An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE This instance has not been constructed as yet.
	*/
	result CancelAll(void);

	/**
	* @page          CompContentTransferCancelAllPage Compatibility for CancelAll( )
	* @section       CompContentTransferCancelAllPageIssueSection Issues
	*                Implementation of this method in API versions prior to 2.0 has the following issue: @n
	*
	* -# When this method is used without construct(), this method does not work as per expectations. 
	* @section        CompContentTransferCancelAllPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 @n
	* When this method is used without construct(), CancelAll() returns E_INVALID_STATE.
	*/


	/**
	* Gets the content transfer information list.
	*
	* @since	1.0
	* @compatibility    This method has compatibility issues between bada API versions @b prior @b to @b 2.0. @n
	*                   For more information, see @ref CompGetContentTransferInfoListNPage "here".
	* 
	* @return	A pointer to a list containing the ContentTransferInfo instances, @n
	*			else an empty list if there is no result and no error
	*/
	Osp::Base::Collection::IList* GetContentTransferInfoListN(void);

	/**
	* @page          CompGetContentTransferInfoListNPage Compatibility for GetContentTransferInfoListN( )
	* @section       CompGetContentTransferInfoListNPageIssueSection Issues
	*                Implementation of this method in API versions prior to 2.0 has the following issue: @n
	*
	* -# When this method is used without construct(), this method does not work as per expectations. 
	* @section        CompGetContentTransferInfoListNPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 @n
	*/
	
	/**
	* Gets the list of transfers that are in progress.
	*
	* @since	1.0
	* @compatibility    This method has compatibility issues between bada API versions @b prior @b to @b 2.0. @n
	*                   For more information, see @ref CompGetContentTransferInfoListInProgressNPage "here".
	* 
	* @return	A pointer to a list containing the ContentTransferInfo instances, @n
	*			else an empty list if there is no result and no error
	*/
	Osp::Base::Collection::IList* GetContentTransferInfoListInProgressN(void);

	/**
	* @page          CompGetContentTransferInfoListInProgressNPage Compatibility for GetContentTransferInfoListInProgressN( )
	* @section       CompGetContentTransferInfoListInProgressNPageIssueSection Issues
	*	 	 Implementation of this method in API versions prior to 2.0 has the following issue: @n
	*
	* -# When this method is used without construct(), this method does not work as per expectations. 
	* @section        CompGetContentTransferInfoListInProgressNPageIssueSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0 @n
	*/

	/**
	* Sets the interval of the progress. @n
	* The input is a percentage value between @c 0 and @c 100. The default value is @c 0.
	* @c 0 means the application would not receive progress events.
	*
	* @since			1.0
	* @param[in]	percent		The progress period interval as a percentage value
	* @remarks If a server does not provide the information about the content size, then the content module cannot verify the information. In that case,
	*  		  progress event will occur randomly.
	*/
	void SetProgressIntervalByPercent(int percent);


	/**
	* Downloads a content file from the content provider's server. @n
	* An application should set the full destination path for the downloaded contents.
	* The path of the downloaded file should start with '/Home', '/HomeExt, '/Media' or '/Storagecard/Media'.
	*
	* Refer to @ref PrefixDescription "this page" for more information on the destination path.
	*
	* When the content is downloaded to one of the '/Media' or '/Storagecard/Media' directory, this method internally registers the content in the content database. @n
	* When the download is completed, the application is notified via the IContentTransferListener::OnContentDownloadCompleted() method. @n
	* When the data is being downloaded, the application is notified of the progress via the IContentTransferListener::OnContentTransferInProgress() method.
	*
	* @since                     2.0
	*
	* @privlevel               SYSTEM
	* @privgroup               CONTENT_TRANSFER
	*
	* @return         An error code
	* @param[in]     uri                  The content URL
	* @param[in]     filePath       The destination file path @n
	*                               The allowed path prefixes are '/Home', '/HomeExt', '/Media' and '/Storagecard/Media'.
	* @param[out]    reqId               The request id
	* @param[in]     replace             The replace option of the destination file @n
	*                                         Set to @c true to replace the file, @n
	*											else @c false.
	* @param[in]     timeout            The timeout period in seconds
	* @param[in]     progressInterval The progress period interval as a percentage value
	*
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_IN_PROGRESS			A previous request is in progress.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @remarks    The @c progressInterval is the interval of the progress for each download request. If the value of the @c progressInterval is @c 0, the @c progressInterval uses the value set by the ContentTransfer::SetProgressIntervalByPercent(int). The @c progressInterval is a percentage value between @c 0 and @c 100.
	*                    The @c timeout is the value of the response timeout for each download request. If the value of the @c timeout is @c 0, the value for the timeout uses the value set by the ContentTransfer::SetDefaultTimeout(int).
	* @see  IContentTransferListener::OnContentDownloadCompleted()
	* @see  IContentTransferListener::OnContentTransferInProgress()
	*/
	result Download(const Osp::Base::Utility::Uri& uri, const Osp::Base::String& filePath, RequestId& reqId, bool replace = false, int timeout = 0, int progressInterval = 0);

	/**
	* Downloads a content file to a buffer from the content provider's servers.
	* This method does not register the content. @n
	*
	* When the download is completed, the application is notified via the IContentTransferListener::OnContentDownloadCompleted() method. @n
	* When the data is being downloaded, the application is notified of the progress via the IContentTransferListener::OnContentTransferInProgress() method.
	*
	* @since                     2.0
	*
	* @privlevel                 SYSTEM
	* @privgroup               CONTENT_TRANSFER
	*
	*
	* @return         An error code
	* @param[in]     uri                  The content URL
	* @param[out]   reqId               The request id
	* @param[in]     timeout            The timeout period in seconds
	* @param[in]     progressInterval The progress period interval as a percentage value
	*
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_IN_PROGRESS			A previous request is in progress.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @remarks       The @c progressInterval is the interval of the progress for each download request. If the value of the @c progressInterval is @c 0, the @c progressInterval uses the value set by the ContentTransfer::SetProgressIntervalByPercent(int). The @c progressInterval is a percentage value between @c 0 and @c 100.
	*                The @c timeout is the value of the response timeout for each download request. If the value of the @c timeout is @c 0, the value for the timeout uses the value set by the ContentTransfer::SetDefaultTimeout(int).
	* @see  IContentTransferListener::OnContentDownloadToBufferCompleted()
	* @see  IContentTransferListener::OnContentTransferInProgress()
	*/
	result DownloadToBuffer(const Osp::Base::Utility::Uri& uri, RequestId& reqId, int timeout = 0, int progressInterval = 0);

// Operation
private:

	virtual void OnTimerExpired(Osp::Base::Runtime::Timer& timer);

	RequestId __GetRequestId(void);


	result __AddTransferItem(const Osp::Base::Utility::Uri& uri, const Osp::Base::String& destPath, const Osp::Base::String& sourcePath, int sourceFileSize,
		ContentTransferType type, ContentTransferStatus status, const DownloadDescriptor* pDescriptor, const IContentTransferListener* pListener, int sec, bool isBuffer, RequestId& requestId);

	bool __ContentTransferHandler(void);

	ContentTransferInfo* __GetContentTransferInfoByRequestId(RequestId requestId);

	void __StartTimer(void);

	result __Download(const Osp::Base::Utility::Uri& uri, int fileSize, const Osp::Base::String& destFilePath, bool replace, RequestId& reqId,
		const IContentTransferListener* pListener, int sec, bool isBuffer);

	result __GetEmptySlot(int& slot);

	void __DeleteDownloadObj(void);

	result __checkDestPath(const Osp::Base::String& destPath, bool replace);
	result __checkDownloadStatus(const Osp::Base::Utility::Uri& uri, const Osp::Base::String& destPath);
	result __AddTransferItem2(const Osp::Base::Utility::Uri& uri, const Osp::Base::String& destPath, const Osp::Base::String& sourcePath, ContentTransferType type, ContentTransferStatus status, int timeout, int interval, bool isBuffer, RequestId& requestId);
	result __setDownloadSlotInfo(ContentTransferInfo* pTransferInfo, int& flag);
	result __requestErrorEvent(result requestErrorCode, ContentTransferInfo* pTransferInfo);
	result __removeCompletedTransferInfo(Osp::Base::Collection::ArrayList* pTransferInfoList);

// Attribute
private:
	RequestId __requestID;
	RequestId __restRequestId;

	IContentTransferListener* __pListener;
	IContentTransfer* __pIContentTransfer;
	IContentTransfer* __pIContentTransferDownload[MAX_CONTENT_DOWNLOAD_NUMBER];
	__IContentTransferListenerImpl* __pIContentTransferListenerImpl;
	__IContentTransferListenerImpl* __pIContentTransferListenerImplDownload[MAX_CONTENT_DOWNLOAD_NUMBER];
	Osp::Base::String __destFilePath;
	int __timeout;

	__ContentTransferEvent*	__pTransferEvent;
	__ContentTransferEvent*	__pTransferEventDownload[MAX_CONTENT_DOWNLOAD_NUMBER];

	int	__percent;

	Osp::Base::Collection::ArrayList* __pTransferInfoList;

	Osp::Base::Runtime::Timer*		__pTimer;
	bool	__bTimerStarted;

	Osp::Base::Runtime::Mutex* __pTransferMutex;

	friend class ContentTransferEx;
	class ContentTransferEx* __pContentTransferEx;
};
};};// Osp::Content
#endif // _FCNT_CONTENT_TRANSFER_H_
