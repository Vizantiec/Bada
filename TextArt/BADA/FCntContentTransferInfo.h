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
* @file			FCntContentTransferInfo.h 
* @brief		This is the header file for the %ContentTransferInfo class.
*
* This header file contains the declarations of the %ContentTransferInfo class. 
*/
#ifndef _FCNT_CONTENT_TRANSFER_INFO_H_
#define _FCNT_CONTENT_TRANSFER_INFO_H_

#include "FCntConstants.h"
#include "FCntDownloadDescriptor.h"
#include "FCntIContentTransferListener.h"

namespace Osp { namespace Content { 
class ContentTransferInfoEx;

/**
* @class	ContentTransferInfo
* @brief	This class contains the methods that provide information about the content transfer.
* @since	1.0
*
* The %ContentTransferInfo class provides information about the transfer of content between the device and servers.
*/

/**
* @enum ContentTransferType
* Defines the content transfer type.
*
* @deprecated	This enum is deprecated due to the operation policy of the bada Server.
* @since	1.0
*/
enum  ContentTransferType
{
	CONTENT_TRANSFER_TYPE_NONE, /**<  None */
	CONTENT_TRANSFER_TYPE_UPLOAD, /**< The Upload type*/
	CONTENT_TRANSFER_TYPE_DOWNLOAD, /**< The Download type*/
	CONTENT_TRANSFER_TYPE_OMADOWNLOAD /**<  The OMA Download type*/ 
};

/**
* @enum ContentTransferStatus
* Defines the content transfer status.
*
* @since	1.0
*/
enum  ContentTransferStatus
{
	CONTENT_TRANSFER_STATUS_NONE, /**<  None */
	CONTENT_TRANSFER_STATUS_UPLOADING, /**< The Uploading status */ /**< @deprecated  This enumeration field is deprecated due to the operation policy of the bada Server. */
	CONTENT_TRANSFER_STATUS_DOWNLOADING, /**< The Downloading status */
	CONTENT_TRANSFER_STATUS_UPLOAD_COMPLETED, /**< The Upload completed status */ /**< @deprecated  This enumeration field is deprecated due to the operation policy of the bada Server. */
	CONTENT_TRANSFER_STATUS_DOWNLOAD_COMPLETED, /**<  The Download completed status */
	CONTENT_TRANSFER_STATUS_UPLOAD_READY, /**<  The Upload ready status */ /**< @deprecated  This enumeration field is deprecated due to the operation policy of the bada Server. */
	CONTENT_TRANSFER_STATUS_DOWNLOAD_READY /**<  The Download ready status */
};


class _EXPORT_CONTENT_ ContentTransferInfo : 	
		public Osp::Base::Object
{
// Lifecycle
public:
	/**
	* This is the constructor for this class.
	*
	* @since		1.0
	* @remarks	After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	ContentTransferInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual~ContentTransferInfo(void);
// Operation
public:
	/** 
	* Gets the requested Uniform Resource Identifier (URI). 
	*
	* @since	1.0
	* @return	The request URI
	*
	*/
	Osp::Base::Utility::Uri GetUri(void);

	/** 
	* Gets the request ID. 
	*
	* @since	1.0
	* @return	The request ID
	*
	*/
	RequestId GetRequestId(void);

	/** 
	* Gets the destination file path. 
	*
	* @since	1.0
	* @return	The destination file path
	*
	*/
	Osp::Base::String GetDestPath(void);

	/** 
	* Gets the source file path. 
	*
	* @deprecated This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future.
	* @since	 1.0
	* @return	 The source file path
	*
	*/
	Osp::Base::String GetSourcePath(void);

	/** 
	* Gets the content transfer's type. 
	*
	* @deprecated This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future.
	* @since	1.0
	* @return	The content transfer's type
	*
	*/
	ContentTransferType GetContentTransferType(void);

	/** 
	* Gets the content transfer's status.
	*
	* @since	1.0
	* @return	The content transfer's status
	*
	*/
	ContentTransferStatus GetContentTransferStatus(void);

	/** 
	* Sets the content transfer's status.
	*
	* @deprecated This method is deprecated due to the operation policy of the bada Server. An alternate method will be introduced in the near future.
	* @since			1.0
	* @param[in]	status	The status to set
	*/
	void SetContentTransferStatus(ContentTransferStatus status);

	/** 
	* Gets the download descriptor.
	*
	* @deprecated	This method is deprecated as OMA download is currently not supported.
	* @since	1.0
	* @return	The download descriptor
	*
	*/
	DownloadDescriptor GetDownloadDescriptor(void);


// Operation
private:
	void SetUri(const Osp::Base::Utility::Uri& uri);

	void SetRequestId(RequestId reqId);

	void SetRestRequestId(RequestId reqId);

	void SetDestPath(const Osp::Base::String& destPath);

	void SetSourcePath(const Osp::Base::String& sourcePath, int sourceFileSize);

	void SetContentTransferType(ContentTransferType type);

	void SetAllInfo(RequestId reqId, const Osp::Base::Utility::Uri& uri, const Osp::Base::String& destPath, const Osp::Base::String& sourcePath, int sourceFileSize, 
		ContentTransferType type, ContentTransferStatus status);

	void SetDownloadDescriptor(const DownloadDescriptor& descriptor);

	RequestId GetRestRequestId(void);

	int GetDownloadId(void);

	void SetDownloadId(int id);

	int GetSourceFileSize(void);

	void SetSlotId(int slot);

	int GetSlotId(void);

	void SetTimeout(int sec);

	int GetTimeout(void);

	void SetListener(const IContentTransferListener* pListener);

	IContentTransferListener* GetListener(void);

	ContentTransferInfo* CopyN(void);

	void SetIsBuffer(bool isBuffer);

	bool GetIsBuffer(void);

	void SetPrgoressInterval(int intervalValue);

	int GetPrgoressInterval(void);

	void SetDownloadType(int type);

	int GetDownloadType(void);

// Attribute
private:
	Osp::Base::Utility::Uri __uri;
	RequestId				__requestId;
	RequestId				__restRequestId;
	Osp::Base::String		__destPath;
	Osp::Base::String		__sourcePath;
	ContentTransferType		__type;
	ContentTransferStatus	__status;
	int						__sourceFileSize;
	int						__downloadId;
	int						__slotId;
	DownloadDescriptor		__descriptor;

	IContentTransferListener* __pListener;
	int						__timeout;

	bool					__isBuffer;
	

	// TODO : download description

	friend class ContentTransfer;
	friend class ContentTransferInfoEx;
	class ContentTransferInfoEx* __pContentTransferInfoEx;
};
};};// Osp::Content
#endif //  _FCNT_CONTENT_TRANSFER_INFO_H_

