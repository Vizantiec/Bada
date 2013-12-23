/* $Change: 576488 $ */
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
 * @file			FMediaCapability.h
 * @brief			This is the header file for the %MediaCapability class.
 *
 * This header file contains the declarations of the %MediaCapability class.
 */

#ifndef _FMEDIA_CAPABILITY_H_
#define _FMEDIA_CAPABILITY_H_

#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaCapabilityCommon.h"

namespace Osp{ namespace Media {


class ICameraCapabilityPi;
class MediaCapabilityImpl;


/**
 * @class	MediaCapability
 * @brief	This class provides capability information of the various classes in the Media namespace.
 * @since	1.1
 *
 * @remarks
 * - If the type of a key is 'List, type', use GetValueN(). @n
 *    For example, 'List, String', 'List, Integer'.
 *
 * The %MediaCapability class provides capability information of the various classes in the %Media namespace.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm">Media Capabilities</a>.
 *
 * The following example demonstrates how to use the %MediaCapability class.
 * @code
 * 
 * #include <FBase.h>
 * #include <FMedia.h>
 * 
 * using namespace Osp::Base;
 * using namespace Osp::Media;
 * 
 * result GetMediaCapability()
 * {
 * 	result r;
 * 	Osp::Base::Collection::IList *pList;
 * 
 * 	pList = MediaCapability::GetValueN(CAMERA_PRIMARY_CAPTURE_FORMAT);
 * 	TryCatch(pList != null, , "mediaCap.GetValue(CAPTURE_FORMAT) failed : %s", GetErrorMessage(GetLastResult()));
 * 
 * 	for (int i=0; i<pList->GetCount(); i++) {
 * 		Osp::Graphics::PixelFormat captureFormat;
 * 		Osp::Base::Integer *pValue = (Osp::Base::Integer*)pList->GetAt(i);
 * 		captureFormat = (Osp::Graphics::PixelFormat)pValue->ToInt();
 * 		AppLog("CaptureFormat %d = %d", i, captureFormat);
 * 	}
 * 	pList->RemoveAll(true);
 * 	delete pList;
 * 
 * 	pList = MediaCapability::GetValueN(CAMERA_PRIMARY_PREVIEW_RESOLUTION);
 * 	TryCatch(pList != null, , "mediaCap.GetValue(PREVIEW_RESOLUTION) failed : %s", GetErrorMessage(GetLastResult()));
 * 
 * 	for (int i=0; i<pList->GetCount(); i++) {
 * 		Osp::Graphics::Dimension *pValue = (Osp::Graphics::Dimension*)pList->GetAt(i);
 * 		AppLog("PreviewResolution %d = %d x %d", i, pValue->width, pValue->height);
 * 	}
 * 	pList->RemoveAll(true);
 * 	delete pList;
 * 
 * 	return E_SUCCESS;
 * 
 * CATCH:
 * 	return r;
 * }
 *
 * @endcode
 *
 *
 *
 */

class _EXPORT_MEDIA_ MediaCapability
{

// Operations
public:

	/**
	*	Gets the capability value.
	*
	* @since		1.1
	*	@return		An error code on failure, @n
	*				else E_SUCCESS
	*
	*	@param[in]	key								The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability
	*	@param[out]	value							The retrieved capability information
	*
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_OBJ_NOT_FOUND 				The specified @c key is not found.
	*	@exception	E_INVALID_ARG	 				A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Osp::Base::String &key, bool &value);


	/**
	*	Gets the capability value.
	*
	* @since		1.1
	*	@return		An error code on failure, @n
	*				else E_SUCCESS
	*
	*	@param[in]	key								The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability			
	*	@param[out]	value							The retrieved capability information
	*
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_OBJ_NOT_FOUND 				The specified @c key is not found.
	*	@exception	E_INVALID_ARG	 				A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Osp::Base::String &key, int &value);

	/**
	*	Gets the capability value.
	*
	* @since		1.1
	*	@return		An error code on failure, @n
	*				else E_SUCCESS
	*		
	*	@param[in]	key								The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability			
	*	@param[out]	value							The retrieved capability information
	*
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_OBJ_NOT_FOUND 				The specified @c key is not found.
	*	@exception	E_INVALID_ARG	 				A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Osp::Base::String &key, long long &value);

	/**
	*	Gets the capability value.
	*
	* @since			1.1
	*	@return			An error code on failure, @n
	*					else E_SUCCESS
	*
	*	@param[in]	key								The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability			
	*	@param[out]	value							The retrieved capability information
	*
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_OBJ_NOT_FOUND 				The specified @c key is not found.
	*	@exception	E_INVALID_ARG	 				A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Osp::Base::String &key, double &value);

	/**
	*	Gets the capability value.
	*
	* @since			1.1
	*	@return			An error code on failure, @n
	*					else E_SUCCESS
	*
	*	@param[in]	key								The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability			
	*	@param[out]	value							The retrieved capability information
	*
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_OBJ_NOT_FOUND 				The specified @c key is not found.
	*	@exception	E_INVALID_ARG	 				A specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*/
	static result GetValue(const Osp::Base::String &key, Osp::Base::String &value);

	/**
	*	Gets the capability value.
	*
	* @since			1.1
	*	@return		A pointer to %IList on success, @n
	*				else @c null
	*
	*	@param[in]	key								The <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/media_capabilities.htm#media_capabilities">key name</a> of the media capability			
	*
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*	@exception	E_OBJ_NOT_FOUND 				The specified @c key is not found.
	*	@exception	E_INVALID_ARG	 				The specified input parameter is invalid.
	*	@exception	E_SYSTEM						A system error has occurred.
	*
	*	@remarks The specific error code can be accessed using the GetLastResult() method.
	*/
	static Osp::Base::Collection::IList* GetValueN(const Osp::Base::String &key);


private:
	MediaCapability();
	~MediaCapability();
	MediaCapability(const MediaCapability &src);
	MediaCapability& operator =(const MediaCapability& src);
	
};


};};// Osp::Media

#endif

