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
 * @file		FCntContentManager.h
 * @brief		This is the header file for the %ContentManager class.
 *
 * This header file contains the declarations of the %ContentManager class.
 */

#ifndef _FCNT_CONTENT_MANAGER_H_
#define _FCNT_CONTENT_MANAGER_H_

#include <FCntConstants.h>
#include <FCntContentInfo.h>

struct IContentManager;
struct IContentInfo;

namespace Osp { namespace Content {

class ContentInfo;
class ContentManagerEx;

/**
 * @class	ContentManager
 * @brief	This class provides the methods for local content management.
 * @since	1.0
 *
 * The %ContentManager class manages the information stored locally on the device's content database.
 * It also allows you to create, read, update, and delete specific content information in the database.
 * 
 * For more information on managing content on the device, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_mgmt.htm">Device Content Management</a>.
 *
 * The following example demonstrates how to use the %ContentManager class.
 *
 * @code
 * result
 * MyClass::TestContentManager(void)
 * {
 * 		result r = E_SUCCESS;
 *		ContentId contentId;
 *		ContentManager contentManager;
 *		r = contentManager.Construct();
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		// Creates
 *		Osp::Base::String contentPath(L"/Media/Images/Flower1.jpg");
 *		ImageContentInfo imageContentInfo;
 *		r = imageContentInfo.Construct(&contentPath);
 *		TryReturn(!IsFailed(r), r, "Construct failed.");
 *
 *		contentId = contentManager.CreateContent(imageContentInfo);
 * 		TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed.");
 *
 *		// Gets
 *		ImageContentInfo* pImageContentInfo = null;
 *		pImageContentInfo = (ImageContentInfo*)contentManager.GetContentInfoN(contentId);
 *	 	TryReturn(pImageContentInfo != null, GetLastResult(), "GetContentInfoN failed.");
 *
 *		pImageContentInfo->GetContentPath();
 *
 *		// Updates
 *		r = pImageContentInfo->SetKeyword(L"apple, fruit");
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *		r = pImageContentInfo->SetProvider(L"kw1128");
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *		r = contentManager.UpdateContent(*pImageContentInfo);
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *
 *		// Deletes
 *		r = contentManager.DeleteContent(contentId);
 *		if (IsFailed(r))
 *		{
 *			delete pImageContentInfo;
 *			return r;
 *		}
 *
 *		delete pImageContentInfo;
 *		return r;
 * }
 * @endcode
 */
class _EXPORT_CONTENT_ ContentManager : public Osp::Base::Object
{

public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 * @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	 */
	ContentManager(void);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~ContentManager(void);

	/**
	 * Initializes this instance of %ContentManager.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result Construct(void);

	/**
	* Creates the contents (similar to saving).
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompContentManagerCreateContentPage "here".
	*
	* @privlevel	NORMAL
	* @privgroup	LOCAL_CONTENT
	*
	* @return		The content ID
	* @param[in]	contentInfo			An instance of ContentInfo
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid, or 
	* 									the specified format is invalid or not supported on the device.
	* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_SERVICE_BUSY		The database is busy.
	* @remarks		If the E_UNSUPPORTED_FORMAT exception is received from CheckContentType() of the ContentManagerUtil class,
	* 				the file can be created as a content only using OtherContentInfo class. @n
	* 				The specific error code can be accessed using the GetLastResult() method. @n
	*				For using CreateContent(), check @ref CreateContentUsage "here".
	*/
	ContentId CreateContent(const ContentInfo& contentInfo);

	/**
	* @page		CompContentManagerCreateContentPage Compatibility for CreateContent(const ContentInfo& contentInfo)
	* @section	CompContentManagerCreateContentPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 1.2 has the following issues:
	* 			-# If a physical file corresponding to ContentInfo does not exist, E_INVALID_ARG is returned.
	*			-# If the E_UNSUPPORTED_FORMAT exception is received from CheckContentType() of the ContentManagerUtil class,
	*			   the file cannot be created as content.
	*
	* @section	CompContentManagerCreateContentPageSolutionSection Resolutions
	* 			The issues mentioned above are resolved in bada API version 1.2 as follows:
	* 			-# If a physical file corresponding to %ContentInfo does not exist, E_FILE_NOT_FOUND is returned.
	*			-# If the E_UNSUPPORTED_FORMAT exception is received from %CheckContentType() of the %ContentManagerUtil class,
	*			the file can be created as content using only the OtherContentInfo class.
	*/

	/**
	* Writes the content in the byte buffer to the destination path and creates the content.
	*
	* @since		2.0
	*
	* @privlevel	NORMAL
	* @privgroup	LOCAL_CONTENT
	*
	* @return		The content ID
	* @param[in]	byteBuffer				The byteBuffer of the content to be created
	* @param[in]	destinationPath			The destination file path formed by the byteBuffer
	* @param[in]	pContentInfo			A pointer to the ContentInfo instance @n
	* 										If the content path exists in %ContentInfo, it gets ignored.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	* 										The @c destinationPath length exceeds the maximum limit of 256 characters. @n
	* 										There is a mismatch between the type specified in %ContentInfo and the type specified in the actual content.
	* @exception	E_STORAGE_FULL			The storage is full.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_SERVICE_BUSY			The database is busy.
	* @remarks		The destination path should start with '/Media' or '/Storagecard/Media'. @n
	*				For using CreateContent(), check @ref CreateContentUsage "here".
	*/
	ContentId CreateContent(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Base::String& destinationPath, const ContentInfo* pContentInfo = null);

	/**
	* Copies or moves the actual content to the destination path and creates the content.
	*
	* @since		2.0
	*
	* @privlevel	NORMAL
	* @privgroup	LOCAL_CONTENT
	*
	* @return		The content ID
	* @param[in]	sourcePath				The source file path
	* @param[in]	destinationPath			The destination file path
	* @param[in]	deleteSource			Set to @c true in order to delete the source file, @n
    *										else @c false
	* @param[in]	pContentInfo			A pointer to the ContentInfo instance @n
	* 										If the content path exists in %ContentInfo, it gets ignored.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	* 										The specified @c sourcePath length exceeds the maximum limit of 200 characters. @n
	* 										The @c destinationPath length exceeds the maximum limit of 256 characters. @n
	* 										There is a mismatch between the type of the source path and destination path. @n
	*										There is a mismatch between the type specified in %ContentInfo and the type specified in the actual content.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_STORAGE_FULL			The storage is full.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @exception	E_SERVICE_BUSY			The database is busy.
	* @remarks		The source path should start with '/Home' or '/HomeExt' and destination path should start with '/Media' or '/Storagecard/Media'. @n
	*				If the E_UNSUPPORTED_FORMAT exception is received from CheckContentType() of the ContentManagerUtil class,
	* 				the file can be created as a content using only the OtherContentInfo class. @n
	*				For using CreateContent(), check @ref CreateContentUsage "here".
	*/
	ContentId CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null);

	/**
	* @page		CreateContentUsage How To Use CreateContent
	* @section  CreateContentUsageFirst 1. CreateContent(const ContentInfo& contentInfo)
	*
	*			result r = E_SUCCESS; @n
	*			ImageContentInfo imageContentInfo; @n
	*
	*			Osp::Base::String contentPath("/Media/Images/Flower1.jpg"); @n
	*			r = imageContentInfo.Construct(&contentPath); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			r = imageContentInfo.SetKeyword("apple, fruit"); @n
	*			TryReturn(!IsFailed(r), r, "SetKeyword failed."); @n
	*
	*			r = imageContentInfo.SetProvider("kw1128"); @n
	*			TryReturn(!IsFailed(r), r, "SetProvider failed."); @n
	*
	*			ContentId contentId; @n
	*			ContentManager contentManager; @n
	*			r = contentManager.Construct(); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			contentId = contentManager.CreateContent(imageContentInfo); @n
	* 			TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed."); @n
	*
	* @section  CreateContentUsageSecond 2. CreateContent(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Base::String& destinationPath, const ContentInfo* pContentInfo = null)
	*
	*			<b> // The first usage </b> @n
	*			result r = E_SUCCESS; @n
	*			ByteBuffer byteBuffer; @n
	*			byteBuffer.Construct(1024); @n
	*
	*			// Set the data to byteBuffer @n
	*
	*			ContentId contentId; @n
	*			ContentManager contentManager; @n
	*			r = contentManager.Construct(); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			contentId = contentManager.CreateContent(byteBuffer, "/Media/Images/dest.jpg"); @n
	*			TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed."); @n
	*
	* 			@n <b> // The second usage </b> @n
	*			result r = E_SUCCESS; @n
	*			ByteBuffer byteBuffer; @n
	*			byteBuffer.Construct(1024); @n
	*
	*			// Set the data to byteBuffer @n
	*
	*			ContentId contentId; @n
	*			ContentManager contentManager; @n
	*			r = contentManager.Construct(); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			ImageContentInfo imageContentInfo; @n
	*			r = imageContentInfo.Construct(null); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			r = imageContentInfo.SetKeyword("apple, fruit"); @n
	*			TryReturn(!IsFailed(r), r, "SetKeyword failed."); @n
	*
	*			r = imageContentInfo.SetProvider("kw1128"); @n
	*			TryReturn(!IsFailed(r), r, "SetProvider failed."); @n
	*
	*			contentId = contentManager.CreateContent(byteBuffer, "/Media/Images/dest.jpg", &imageContentInfo); @n
	*			TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed."); @n
	*
	* @section  CreateContentUsageThird 3. CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null);
	*
	*			<b> // The first usage </b> @n
	*			result r = E_SUCCESS; @n
	*			ContentId contentId; @n
	*			ContentManager contentManager; @n
	*			r = contentManager.Construct(); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			contentId = contentManager.CreateContent("/Home/source.jpg", "/Media/Images/dest.jpg", false); @n
	*			TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed."); @n
	*
	* 			@n <b> // The second usage </b> @n
	*			result r = E_SUCCESS; @n
	*			ContentId contentId; @n
	*			ContentManager contentManager; @n
	*			r = contentManager.Construct(); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			ImageContentInfo imageContentInfo; @n
	*			r = imageContentInfo.Construct(null); @n
	*			TryReturn(!IsFailed(r), r, "Construct failed."); @n
	*
	*			r = imageContentInfo.SetKeyword("apple, fruit"); @n
	*			TryReturn(!IsFailed(r), r, "SetKeyword failed."); @n
	*
	*			r = imageContentInfo.SetProvider("kw1128"); @n
	*			TryReturn(!IsFailed(r), r, "SetProvider failed."); @n
	*
	*			contentId = contentManager.CreateContent("/Home/source.jpg", "/Media/Images/dest.jpg", false, &imageContentInfo); @n
	*			TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed."); @n
	*/

	/**
	 * Gets the content information.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompContentManagerGetContentInfoNPage "here".
	 *
 	 * @privlevel	NORMAL
	 * @privgroup	LOCAL_CONTENT
	 *
 	 * @return		A pointer to ContentInfo
 	 * @param[in]	contentId			The content ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
 	 * @exception	E_SYSTEM			A system error has occurred.
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY		The database is busy.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 */
	ContentInfo* GetContentInfoN(ContentId contentId) const;

	/**
	* @page		CompContentManagerGetContentInfoNPage Compatibility for GetContentInfoN(ContentId contentId)
	* @section	CompContentManagerGetContentInfoNPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 1.2 has the following issue:
	* 			-# If a physical file corresponding to the ContentId does not exist, E_SUCCESS is returned.
	*
	* @section	CompContentManagerGetContentInfoNPageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2 as follows:
	* 			-# If a physical file corresponding to the %ContentId does not exist, E_FILE_NOT_FOUND is returned.
	*/

	/**
	* Updates the %ContentManager with the specified instance of ContentInfo.
	*
	* @since		1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref CompContentManagerUpdateContentPage "here".
	*
	* @privlevel	NORMAL
	* @privgroup	LOCAL_CONTENT
	*
	* @return		An error code
	* @param[in]	contentInfo			An instance of %ContentInfo
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_SERVICE_BUSY		The database is busy.
	*/
	result UpdateContent(const ContentInfo& contentInfo);

	/**
	* @page		CompContentManagerUpdateContentPage Compatibility for UpdateContent(const ContentInfo& contentInfo)
	* @section	CompContentManagerUpdateContentPageIssueSection Issues
	*           Implementation of this method in bada API versions prior to 1.2 has the following issue:
	* 			-# If a physical file corresponding to the ContentInfo does not exist, E_SUCCESS is returned.
	*
	* @section	CompContentManagerUpdateContentPageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2 as follows:
	* 			-# If a physical file corresponding to the %ContentInfo does not exist, E_FILE_NOT_FOUND is returned.
	*/

	/**
	 * Deletes the content of the %ContentManager with the specified content Id.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *					For more information, see @ref CompContentManagerDeleteContentPage "here".
	 *
 	 * @privlevel	NORMAL
	 * @privgroup	LOCAL_CONTENT
	 *
 	 * @return		An error code
 	 * @param[in]	contentId			The content ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		The specified input parameter is invalid.
	 * @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred. @n
	 * 									(The content is a read-only file or Internal DB operation error.)
	 * @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	 * @exception	E_SERVICE_BUSY		The database is busy.
	 * @remarks		The file is deleted.
	 */
	result DeleteContent(ContentId contentId);

	/**
	* @page		CompContentManagerDeleteContentPage Compatibility for DeleteContent(ContentId contentId)
	* @section	CompContentManagerDeleteContentPageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.2 has the following issue:
	* 			-# If a physical file corresponding to the ContentId does not exist, E_SUCCESS is returned.
	*
	* @section	CompContentManagerDeleteContentPageSolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2 as follows:
	* 			-# If a physical file corresponding to the %ContentId does not exist, E_FILE_NOT_FOUND is returned.
	*/

private:
	IContentManager* __pIContentManager;
	mutable ContentInfo* __pContentInfo;

	IContentInfo* RevertContentInfo(ContentInfo* pIContentInfo);

	friend class ContentSearch;
	friend class ContentUtil;

	friend class ContentManagerEx;
	class ContentManagerEx* __pContentManagerEx;

};	// class ContentManager

}; };	// Osp::Content

#endif	// _FCNT_CONTENT_MANAGER_H_
