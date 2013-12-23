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
* @file			FCntOtherContentInfo.h
* @brief		This is the header file for the %OtherContentInfo class.
*
* This header file contains the declarations of %OtherContentInfo class.
*/

#ifndef _FCNT_OTHER_CONTENT_INFO_H_
#define _FCNT_OTHER_CONTENT_INFO_H_

#include <FCntConstants.h>
#include <FCntContentInfo.h>

namespace Osp { namespace Content {

class OtherContentInfoEx;

/**
* @class	OtherContentInfo
* @brief	This class provides the methods to access the other content information.
* @since	1.0
*
* The %OtherContentInfo class provides the methods to access other content information. 
* Before retrieving other content information, the ContentManager class must be used to create the content.  
* If the E_UNSUPPORTED_FORMAT exception is received from CheckContentType() method of the ContentManagerUtil class, the file can only be created as %OtherContentInfo. 
*
* For more information about the different types of content information, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/content/device_content_mgmt.htm">Device Content Management</a>.
*
* The following example demonstrates how to use the %OtherContentInfo class.
*
* @code
* result
* MyClass::TestOtherContentInfo(void)
* {
*		result r = E_SUCCESS;
*
*		ContentId contentId;
*		ContentManager contentManager;
*		r = contentManager.Construct();
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		Osp::Base::String inputPath(L"/Media/Others/document.doc");
*		OtherContentInfo otherContentInfo;
*		r = otherContentInfo.Construct(&inputPath);
*		TryReturn(!IsFailed(r), r, "Construct failed.");
*
*		contentId = contentManager.CreateContent(otherContentInfo);
*		TryReturn(Osp::Base::UuId::INVALID_UUID != contentId, GetLastResult(), "CreateContent failed.");
*
*		// contents information
*		Osp::Base::String contentPath = otherContentInfo.GetContentPath();
*
*		return r;
* }
* @endcode
*/
class _EXPORT_CONTENT_ OtherContentInfo
	: public Osp::Content::ContentInfo
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.0
	* @remarks		After creating an instance of this class, the Construct() method must be called explicitly to initialize this instance.
	*/
	OtherContentInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	virtual ~OtherContentInfo(void);

	/**
	* Initializes this instance of %OtherContentInfo with the specified parameters.
	*
	* @deprecated   This method is deprecated as there is a problem in managing the user-defined thumbnail and device coordinates. @n
	* 				Instead of using this method, use Construct(const Osp::Base::String* pContentPath). @n
	* 				To set the coordinates in the %ContentInfo instance, use SetCoordinates(const Osp::Locations::Coordinates& coordinates) of the ContentInfo class.
	*
	* @since		1.0
	* @return		An error code
	* @param[in]	contentPath				The content path
	* @param[in]	thumbnailPath			The thumbnail path
	* @param[in]	setGps					Set to @c true to save the device's last known coordinates in the %ContentInfo instance, @n
    *										else @c false @n
	*										The coordinate information may be incorrect if it is outdated or has never been updated. @n
	* 										To update the coordinate information or to get the exact value,
	* 										use RequestLocationUpdates() of the Osp::Locations::LocationProvider class, before calling this method.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid or
	* 										the length of the input data exceeds the maximum limit of 256 characters.
	* @exception	E_LOCATION				The location provider is currently out of service.
	* @remarks		The content path should start with '/Media' or '/Storagecard/Media'.
	* 				The thumbnail path should start with '/Home', '/Media', or '/Storagecard/Media'.
	* 				The permitted format for a thumbnail image is bitmap (bmp).
	*/
	result Construct(const Osp::Base::String& contentPath, const Osp::Base::String& thumbnailPath = L"", bool setGps = false);

	/**
	* Initializes this instance of %OtherContentInfo with the specified parameter.
	*
	* @since		2.0
	* @return		An error code
	* @param[in]	pContentPath			The content path
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_INVALID_ARG			The specified content path is invalid or its length exceeds the maximum limit of 256 bytes.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_IO					An I/O error has occurred.
	* @exception	E_SYSTEM				An internal error has occurred.
	* @remarks		The content path should start with '/Media' or '/Storagecard/Media'. 
	*				If @c pContentPath is @c null, use CreateContent(const Osp::Base::ByteBuffer& byteBuffer, const Osp::Base::String& destinationPath, const ContentInfo* pContentInfo = null)
    *				or CreateContent(const Osp::Base::String& sourcePath, const Osp::Base::String& destinationPath, bool deleteSource, const ContentInfo* pContentInfo = null) of the ContentManager class. @n
	*/
	result Construct(const Osp::Base::String* pContentPath);

private:
	IContentInfo* __pIContentInfo;

	result SetContentInfo(const IContentInfo* pIContentInfo);

	friend class ContentManager;
	friend class ContentSearch;

	friend class OtherContentInfoEx;
	class OtherContentInfoEx* __pOtherContentInfoEx;

};	// class OtherContentInfo

}; };	// Osp::Content

#endif	// _FCNT_OTHER_CONTENT_INFO_H_
