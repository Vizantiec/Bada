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
 * @file			FMediaIImageEventListener.h
 * @brief			This is the header file for the %IImageDecodeUrlEventListener interface.
 *
 * This header file contains the declarations of the %IImageDecodeUrlEventListener interface.
 */

#ifndef _FMEDIA_IIMAGE_EVENTLISTENER_H_
#define _FMEDIA_IIMAGE_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include <FGraphics.h>
#include "FMediaConfig.h"
#include "FMediaImageCommon.h"

namespace Osp{ namespace Media{

/**
 * @interface	IImageDecodeUrlEventListener
 * @brief			This interface provides a listener that receives events associated with the Image::DecodeUrl().
 * @since			1.0
 *
 * The %IImageDecodeUrlEventListener interface provides a listener that receives events associated with the %Image::DecodeUrl() method, including specifying the methods used to get the decoded bitmap data from the remote URL.
 * The %Image::DecodeUrl() method works asynchronously. Therefore, it is important to implement this listener to ensure that the decoding flows correctly.
 * When an operation of each method is completed, an event is generated and a method of this interface is called.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/viewing_processing_still_images.htm">Viewing and Processing Still Images</a>.
 */
class _EXPORT_MEDIA_ IImageDecodeUrlEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	Called when a Image::DecodeUrl() operation is completed.
	*
	* @since			1.0
	*	@param[in]  reqId		The requested ID
	*	@param[in]	pBitmap		The downloaded bitmap data
	* @param[in]	r			The result of the upload
	* @param[in]	errorCode	The error code
	* @param[in]	errorMessage	The error message
	*	@remarks	The %Image object should not be deleted in this event listener.
	*	@see		Image::DecodeUrl()
	*/
	virtual void OnImageDecodeUrlReceived( RequestId reqId, Osp::Graphics::Bitmap* pBitmap, result r, const Osp::Base::String errorCode, const Osp::Base::String errorMessage) = 0;

};

};}; // Osp::Media

#endif

