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
* @file			FCntContentManagerUtil.h 
* @brief		This is the header file for the %ContentManagerUtil class.
*
* This header file contains the declarations of the %ContentManagerUtil class.
*/

#ifndef _FCNT_CONTENT_MANAGER_UTIL_H_
#define _FCNT_CONTENT_MANAGER_UTIL_H_

#include <FCntImageMetadata.h>
#include <FCntAudioMetadata.h>
#include <FCntVideoMetadata.h>

namespace Osp { namespace Content {

class ContentManagerUtilEx;

/**
* @class	ContentManagerUtil
* @brief	This class provides methods for managing the content's utility.
* @since	1.0
*
* The %ContentManagerUtil class provides access to different local content types, such as image, audio, and video, and manages the content metadata.
*
* For more information on managing the content's utility on the device, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_mgmt.htm">Device Content Management</a>.
*
* The following example demonstrates how to use the %ContentManagerUtil class.
*
* @code
* result
* MyClass::TestContentManagerUtil(void)
* {
* 		result r = E_SUCCESS;
*
*		// Image
*		ImageMetadata* pImageMeta = ContentManagerUtil::GetImageMetaN(L"/Media/Images/full_meta.jpg");
*		TryReturn(pImageMeta != null, GetLastResult(), "GetImageMetaN failed.");
*
*		// Audio
*		AudioMetadata* pAudioMeta = ContentManagerUtil::GetAudioMetaN(L"/Media/Sounds/hot.mp3");
*		if(pAudioMeta == null)
*		{
*			delete pImageMeta;
*			return GetLastResult();
*		}
*
*		// Video
*		VideoMetadata* pVideoMeta = ContentManagerUtil::GetVideoMetaN(L"/Media/Videos/video.mp4");
*		if(pVideoMeta == null)
*		{
*			delete pImageMeta;
*			delete pAudioMeta;
*			return GetLastResult();
*		}
*
*		delete pImageMeta;
*		delete pAudioMeta;
*		delete pVideoMeta;
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ ContentManagerUtil : public Osp::Base::Object
{
public :
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	*/
	ContentManagerUtil(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~ContentManagerUtil(void);

	/**
	* Gets the metadata for an image.
	*
	* @since		1.0
	* @return		A pointer to ImageMetadata @n
	* 				@c null, if an exception occurs
	* @param[in]	contentPath			The content path
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The content file path should start with '/Home', '/Media', or '/Storagecard/Media'.
    * 				The supported formats are 'jpg', 'jpeg', 'gif', 'png', 'bmp', 'wbmp', or 'tiff'. @n
    *				The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Content::ImageMetadata* GetImageMetaN(const Osp::Base::String& contentPath);

	/**
	* Gets the metadata for an audio.
	*
	* @since		1.0
	* @return		A pointer to AudioMetadata @n
	* 				@c null, if an exception occurs
	* @param[in]	contentPath			The content path
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The content file path should start with '/Home', '/Media', or '/Storagecard/Media'.
	* 				The supported formats are 'mp3', 'wav', 'aac', 'wma', 'm4a', 'xmf', '3ga', or 'mmf'. @n
	* 				The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Content::AudioMetadata* GetAudioMetaN(const Osp::Base::String& contentPath);

	/**
	* Gets the metadata for a video.
	*
	* @since		1.0
	* @return		A pointer to VideoMetadata @n
	* 				@c null, if an exception occurs
	* @param[in]	contentPath			The content path
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The content file path should start with '/Home', '/Media', or '/Storagecard/Media'.
	* 				The supported formats are 'wmv', 'asf', 'mp4', '3gp', or 'avi'. @n
	* 				The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Content::VideoMetadata* GetVideoMetaN(const Osp::Base::String& contentPath);

	/**
	* Gets the content type from the content path.
    *
	* @deprecated 	This method is deprecated as it may return an improper result. @n
	* 				Instead of using this method, use the CheckContentType(const Osp::Base::String& contentPath) method.
	*
	* @since		1.0
	* @return		The content type
	* @param[in]	contentPath			The content path
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Content::ContentType GetContentType(const Osp::Base::String& contentPath);

	/**
	* Checks the content type from the content path.
	*
	* @since 		1.1
	* @return		The content type
	* @param[in]	contentPath				The content path
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified input parameter is invalid, or
	* 										the length of the specified path is @c 0 or exceeds system limitations.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found.
	* @exception 	E_UNSUPPORTED_FORMAT	The specified format is invalid or not supported.
	* @remarks		The content file path should start with '/Home', '/Media', or '/Storagecard/Media'. @n
	* 				The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Content::ContentType CheckContentType(const Osp::Base::String& contentPath);

	/**
	* Copies an existing file to a new directory.
	*
	* @deprecated 	This method is deprecated because a new method has been added. @n
	* 				Instead of using this method, use CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null) of the ContentManager class.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	srcContentPath			The source content path
	* @param[in]	destContentPath			The destination content path
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	*										- The length of the specified path is equal to @c 0 or exceeds system limitations. @n
	*										- The specified path contains prohibited character(s). @n
	*										- The specified path is invalid.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- File corruption is detected. @n
	*										- The volume or quota is no more available.
	* @remarks		The source file in the system region cannot be copied. @n
	* 				The destination file path should start with '/Media' or '/Storagecard/Media'. @n
	* 				To manage the content, use CreateContent() of the %ContentManager class.
	*/				
	static result CopyToMediaDirectory(const Osp::Base::String& srcContentPath, const Osp::Base::String& destContentPath);

	/**
	* Changes the path to a new directory.
	*
	* @deprecated 	This method is deprecated because a new method has been added. @n
	* 				Instead of using this method, use CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null) of the ContentManager class.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	srcContentPath			The source content path
	* @param[in]	destContentPath			The destination content path
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			Either of the following conditions has occurred: @n
	* 											- The length of the specified path is equal to @c 0 or exceeds system limitations. @n
	* 											- The specified path contains prohibited character(s). @n
	* 											- The specified path is invalid.
	* @exception	E_ILLEGAL_ACCESS		Access is denied due to insufficient permission.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_FILE_ALREADY_EXIST	The specified file already exists.
	* @exception	E_MAX_EXCEEDED			The number of opened files has exceeded the maximum limit.
	* @exception	E_IO					Either of the following conditions has occurred: @n
	*										- An unexpected device failure has occurred as the media ejected suddenly. @n
	*										- File corruption is detected. @n
	*										- The volume or quota is no more available.
	* @remarks		The source file in the system region cannot be copied. @n
	* 				The destination file path should start with '/Media' or '/Storagecard/Media'. @n
	* 				To manage the content, use CreateContent() of the %ContentManager class.
	*/
	static result MoveToMediaDirectory(const Osp::Base::String& srcContentPath, const Osp::Base::String& destContentPath);

	/**
	* @if PRIVCORE
	* Gets the total size of the content files that correspond to a given content type.
	*
	* @since 		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		The total size of the content files in bytes
	* @param[in]	contentType				The content type @n
	* 										The supported types are : @n
	* 											- CONTENT_TYPE_IMAGE @n
	* 											- CONTENT_TYPE_AUDIO @n
	* 											- CONTENT_TYPE_VIDEO
	* @param[in]	dirPath					The directory path @n
	* 										The supported directories are : @n
	* 											- /Media @n
	* 											- /Storagecard/Media
	* @exception	E_SUCCESS				The method was successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	* 										The dirPath exceeds the maximum limit of 256 characters.
	* @exception	E_FILE_NOT_FOUND		The specified directory could not be found.
	* @exception	E_SYSTEM				A system error occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @endif
	*/
	static unsigned long long GetContentFileSize(ContentType contentType, const Osp::Base::String& dirPath);

	/**
	* @if PRIVCORE
	* Registers the directory in the database.
	*
	* @since 		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		An error code
	* @param[in]	dirPath					The directory path
	* @exception	E_SUCCESS				The method was successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	* 										The length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_FILE_ALREADY_EXIST	The specified directory already registered.
	* @exception	E_FILE_NOT_FOUND		The specified directory could not be found.
	* @exception	E_SYSTEM				A system error occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The directory path should start with '/Media' or '/Storagecard/Media'.
	* @endif
	*/
	static result RegisterDirectory(const Osp::Base::String& dirPath);

	/**
	* @if PRIVCORE
	* Deletes content information related with content path.
	*
	* @since 		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		An error code
	* @param[in]	contentPath				The content path
	* @exception	E_SUCCESS				The method was successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	* 										The length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_FILE_NOT_FOUND		The specified file could not be found.
	* @exception	E_SYSTEM				A system error occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The contentPath should start with '/Media' or '/Storagecard/Media'.
	* @endif
	*/
	static result DeleteContentInfo(const Osp::Base::String& contentPath);

	/**
	* @if PRIVCORE
	* Checks whether the content is created or not in the database.
	*
	* @since 		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		@c true if the content is created @n
	* 				@c false, otherwise
	* @param[in]	contentPath				The content path
	* @exception	E_SUCCESS				The method was successful.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid. @n
	* 										The length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_SYSTEM				A system error occurred.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The contentPath should start with '/Media' or '/Storagecard/Media'.
	* @endif
	*/
	static bool IsContentCreated(const Osp::Base::String& contentPath);

	/**
	* @if PRIVCORE
	* Gets the metadata for a system image.
	*
	* @since		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		A pointer to ImageMetadata @n
	* 				@c null, if an exception occurs
	* @param[in]	contentPath			The content path @n
	* 									The supported path are : @n
	* 										- /System/Wallpapers @n
	* 										- /Settings/Wallpaper
	* @exception	E_SUCCESS			The method was successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* 									The length of the input data exceeds the maximum limit of 200 characters.
	* @exception	E_OUT_OF_MEMORY		Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @endif
	*/
	static Osp::Content::ImageMetadata* GetSystemImageMetaN(const Osp::Base::String& contentPath);

	/**
	* @if PRIVCORE
	* Gets the metadata for a system audio.
	*
	* @since		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		A pointer to AudioMetadata @n
	* 				@c null, if an exception occurs
	* @param[in]	contentPath			The content path @n
	* 									The supported path is '/System/Ringtones'.
	* @exception	E_SUCCESS			The method was successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* 									The length of the input data exceeds the maximum limit of 200 characters.
	* @exception	E_OUT_OF_MEMORY		Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @endif
	*/
	static Osp::Content::AudioMetadata* GetSystemAudioMetaN(const Osp::Base::String& contentPath);

	/**
	* @if PRIVCORE
	* Gets the metadata for a system video.
	*
	* @since		2.0
	*
	* @privlevel 	CORE
	* @privgroup 	CONTENT_MANAGER
	*
	* @return		A pointer to VideoMetadata @n
	* 				@c null, if an exception occurs
	* @param[in]	contentPath			The content path @n
	* 									The supported path are : @n
	* 										- /System/Wallpapers @n
	* 										- /Settings/Wallpaper
	* @exception	E_SUCCESS			The method was successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid. @n
	* 									The length of the input data exceeds the maximum limit of 200 characters.
	* @exception	E_OUT_OF_MEMORY		Insufficient memory.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @endif
	*/
	static Osp::Content::VideoMetadata* GetSystemVideoMetaN(const Osp::Base::String& contentPath);

private:
	friend class ContentManagerUtilEx;
	class ContentManagerUtilEx* __pContentManagerUtilEx;

};	// class ContentManagerUtil

};};	// Osp::Content

#endif	// _FCNT_CONTENT_MANAGER_UTIL_H_
