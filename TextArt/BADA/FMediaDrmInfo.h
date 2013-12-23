/* $Change: 1241928 $ */
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
* @file			FMediaDrmInfo.h
* @brief		This is the header file for the %DrmInfo class.
*
* This header file contains the declarations of the %DrmInfo class.
*/
#ifndef _FMEDIA_DRM_INFO_H_
#define _FMEDIA_DRM_INFO_H_

// includes
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaDrmConstants.h"
#include "FMediaDrmConstraintInfo.h"



namespace Osp { namespace Media {

class IDrmManagerPi;
class DrmInfoEx;
/**
 * @class	DrmInfo
 * @brief	This class provides information on the DRM content.
 * @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
 * @since	1.0
 *
 *
 * The %DrmInfo class provides information on the DRM content that includes:
 * - DRM file information: MIME type, title, description, author, copyright, and so on.
 * - DRM information: DRM type, method, and so on.
 * - The status of a DRM right object.
 * - The Constraints of a DRM right object.
 *
 * The currently supported DRM types are OMA-DRM (v1.0, v2.0, and v2.1), WMDRM, and PlayReady DRM. @n
 * PlayReady DRM is supported @b since: @b 2.0.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/digital_rights_management.htm">Digital Rights Management</a>.
 *
 * The following example demonstrates how to use the %DrmInfo class to create a DrmManager instance and get a DRM type.
 *
 * @code
 void
 SampleApp::GetDrmType(void)
 {
	DrmInfo drmInfo;
	DrmType	drmType;
	result r = drmInfo.Construct(L"/Home/jpg.dcf");

	if (IsFailed(r)) {
		return;
	}

	drmType = drmInfo.GetDrmType();
 }

 * @endcode
 *
 * The following example demonstrates how to use the %DrmInfo class to get a DrmConstraintInfo.
 *
 * @code
 void
 SampleApp::GetDrmConstraintInfo(void)
 {
 	DrmInfo drmInfo;
	DrmConstraintInfo constraintInfo;
	result r = drmInfo.Construct(L"/Home/jpg.dcf");

	if (IsFailed(r)) {
		return;
	}

	r = drmInfo.GetDrmConstraintInfo(DRM_PERMISSION_TYPE_DISPLAY, constraintInfo);

	if (IsFailed(r)) {
		return;
	}
 }

 * @endcode
 */
class _EXPORT_MEDIA_ DrmInfo :
		public Osp::Base::Object
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	* @remarks	After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize this instance.
	*/
	DrmInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~DrmInfo(void);

	/**
	* Initializes this instance with the specified file path. @n
	* This method should be called after an instance is constructed.
	*
	* @since	1.0
	*
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	* 					For more information, see @ref CompMediaDrmInfoConstruct20 "here".
	*
	* @return		An error code
	* @param[in]	filePath				The DRM file path
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY 		The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
	* @exception	E_INVALID_STATE			This instance has already been constructed.
	* @exception	E_UNSUPPORTED_FORMAT	The DRM format is not supported.
	* @exception	E_INVALID_FORMAT		The content header in the DRM is not found.
	*/
	result Construct(const Osp::Base::String& filePath);

	/**
	* @page		CompMediaDrmInfoConstruct20 Compatibility for Construct()
	* @section 	CompMediaDrmInfoConstructPageIssueSection Issues
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*
	* -# The PlayReady DRM is not supported, but the Construct() method returns E_SUCCESS and the GetDrmType() method returns DRM_UNDEFINED.
	*
	* @section CompMediaDrmInfoConstructPageResolutionSection Resolutions @n
	* The issue mentioned above is resolved in bada API version 2.0 as follows: @n
	*
	* -# The PlayReady DRM is supported, and the GetDrmType() method returns DRM_PLAYREADY.
	*/


// Operation
public:
	/**
	* Gets the DRM Type.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The DRM Type
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	DrmType GetDrmType(void) const;

	/**
	* Gets the DRM Method Type.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The DRM Method Type
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	DrmMethodType GetDrmMethodType(void) const;

	/**
	* Checks whether a file is a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			@c true if the file is a supported DRM file, @n
	*					else @c false
  * @exception		E_SUCCESS		The method was successful.	
  *	@exception		E_INVALID_STATE			This instance has not been constructed yet.					
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.		
	*		
	*/
	bool IsDrmFile(void) const;

	/**
	* Gets the DRM constraint information.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			An error code
	* @param[in]		type					The DRM permission type
	* @param[out]		constraintInfo			The constraint information
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_OBJ_NOT_FOUND			The specified instance is not found.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	*	@exception	E_INVALID_ARG  			The specified input parameter is invalid.  
	* @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception		E_PRIVILEGE_DENIED		An application does not have the privilege to call this method.
	*/
	result GetDrmConstraintInfo(DrmPermissionType type, DrmConstraintInfo& constraintInfo);

	/**
	* Gets the DRM right status.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			An error code
	* @param[in]		type					The DRM permission type
	* @param[out]		rightStatus				The right status
	* @exception		E_SUCCESS				The method is successful.
	* @exception		E_OBJ_NOT_FOUND			The specified instance is not found.
	* @exception		E_INVALID_STATE			This instance has not been constructed as yet.
	*	@exception	E_INVALID_ARG  			The specified input parameter is invalid. 
	* @exception		E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	*/
	result  GetDrmRightStatus(DrmPermissionType type, DrmRightStatus& rightStatus);

	/**
	* Gets the type of the content in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The content type
	* @exception		E_SUCCESS		The method was successful.
	*	@exception	E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetContentType(void) const;

	/**
	* Gets the title of the content in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The content title
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetContentTitle(void) const;

	/**
	* Gets the description of the content in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The description of the content 
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String  GetContentDescription(void) const;

	/**
	* Gets the copyright of the content in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The copyright of the content
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetContentCopyright(void) const;

	/**
	* Gets the author of the content in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The author of the content
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetContentAuthor(void) const;

	/**
	* Gets the URL of the content icon in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The URL of the content icon
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetContentIconUri(void) const;

	/**
	* Gets the URL of the content information in a DRM file.
	*
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		DRM_CONTENT
	* @return			The URL of the content information
	* @exception		E_SUCCESS		The method was successful.
	*	@exception		E_INVALID_STATE			This instance has not been constructed yet.
	* @exception		E_PRIVILEGE_DENIED			The application does not have the privilege to call this method.
	* @remarks			The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::String GetContentInfoUrl(void) const;

   /**
    * @if PRIVCORE
    * Gets the current secure time.
    *
    * @since			1.0
    * @privlevel    	CORE
    * @privgroup    	DRM_SERVICE
    * @return       	An error code
    * @param[out]   	currentTime             The current secure time in UTC
    * @exception    	E_SUCCESS               The method is successful.
    * @exception    	E_PRIVILEGE_DENIED	    The application does not have the privilege to call this method.
    * @exception    	E_SYSTEM                A system error has occurred.
    * @endif
    */
   static result GetSecureTime(Osp::Base::DateTime& currentTime);

//Lifecycle
private:
	result	__IntializePi(void);


// Attributes
private:
	IDrmManagerPi* __pIDrmManagerPi;
	bool	__drmFileCheck;
	DrmType	__drmType;
	DrmMethodType __drmMethodType;
	Osp::Base::String __filePath;
	Osp::Base::String __contentType;
	Osp::Base::String __contentTitle;
	Osp::Base::String __contentDescription;
	Osp::Base::String __contentCopyright;
	Osp::Base::String __contentAuthor;
	Osp::Base::String __contentIconUri;
	Osp::Base::String __contentInfoUrl;

	friend class DrmInfoEx;
	class DrmInfoEx* __pDrmInfoEx;
};
};};// Osp::Media
#endif // _FMEDIA_DRM_INFO_H_
