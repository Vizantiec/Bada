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
* @file			FAppAppResource.h 
* @brief			This is the header file for the %AppResource class.
*
* This header file contains the declarations of the %AppResource class.
*/


#ifndef _FAPP_APP_RESOURCE_H_
#define _FAPP_APP_RESOURCE_H_


#include "FBaseObject.h"
#include "FBaseString.h"
#include "FAppConfig.h"
#include "FGrpBitmap.h"

namespace Osp { namespace Locales { class Locale; }; };

namespace Osp { namespace App {


/**
* @class		AppResource
* @brief		This class provides convenient methods to load application resources at run time.
* @since		1.0
*
* The %AppResource class provides convenient methods to load application resources at run time: @n
* - Use AppResource::GetString() to get handle and display localized strings.
* - Use AppResource::GetBitmapN() to obtain a bitmap image that matches the screen density.
* - If the matching image does not exist, the image of the baseline density folder, ScreenDensity-High is used.
*
* The instance of this class can be obtained through Application::GetAppResource().
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/app/localization.htm">Using Localized Strings</a> and <a href="../com.osp.appuiguide.help/html/multiple_screen/autoscale_resource_fallback.htm">Resource Fallback and Prescaling</a>.
* 
* The following example demonstrates how to use the %AppResource class to get strings.
*
* @code
***********************************************************************************************
// Sample code for loading string resources
#include <FApp.h>

using namespace Osp::App;

void
MyClass::StringResourceSample(void)
{
	String hello;
	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	if (pAppResource)
		pAppResource->GetString(L"IDS_HELLO", hello);
}
***********************************************************************************************
* @endcode
*
*
*
* The following example demonstrates how to use the %AppResource class to retrieve bitmaps.
*
* @code
***********************************************************************************************
// Sample code for loading bitmap resources
#include <FApp.h>

using namespace Osp::App;
using namespace Osp::Graphics;

void
MyClass::BitmapResourceSample(void)
{
	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* __pBitmap = null;

	if (pAppResource)
		__pBitmap = pAppResource->GetBitmapN(L"bada.png", BITMAP_PIXEL_FORMAT_ARGB8888);
}
***********************************************************************************************
* @endcode
* 
* 
*/

class _EXPORT_APP_ AppResource :
	public Osp::Base::Object
{
// Lifecycle
private:

	/*
	* This is the default constructor for this class.
	*/
	AppResource(void);

	/*
	* This is the copy constructor for the %AppResource class.
	*/
	AppResource(const AppResource& source);

	/*
	* Initializes this instance.
	*
	*/
	result Construct(void);

	/*
	* Initializes this instance with the specified locale.
	*
	*/
	result Construct(const Osp::Locales::Locale& locale);

public:
	/**
	* This is the destructor for this class.
	*
	* @since		1.0
	*/
	~AppResource(void);


private:
	/**
	 * This is the assignment operator for this class.
	 */
	AppResource& operator=(const AppResource& source);


public:
	/**
	* Gets the string at the specified resource ID.
	*
	* @since		1.0
	* @return		An error code
	* @param[in] 	resourceId		The resource ID of type String that describes the resource
	* @param[out]	loadedString	The string obtained from the loaded application resource
	* @exception	E_SUCCESS				  The method is successful.
	* @exception	E_FAILURE			The argument passed is not found.
	* @exception	E_INVALID_STATE   The state of XML context is invalid.
	* @exception	E_INVALID_ARG			The argument passed to a method contains an invalid resource ID.
	*/
	result GetString(const Osp::Base::String resourceId, Osp::Base::String& loadedString);

	/**
	* Gets the bitmap at the specified path. @n
    * This method interprets the given resource path and reads the best matching image file for the current device resolution. @n
    * To load the bitmap image from a file, give the name of the file as the input parameter and not the file path (Ex: "img.png").
    * Then, the system will first look for the image file in the folder specific to the current device resolution, such as
    * '320x480' and if the file does not exist, it will then search the folder that corresponds to the current screen density, 
    * such as 'ScreenDensity-Middle'. After searching the density folder, all the other density folders are searched in the order high to low.
    * Currently supported image formats are: JPEG, GIF, PNG, BMP, TIFF, and WBMP.
    *
    * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                For more information, see @ref CompGetBitmapN20 "here".
	*
	* @since		1.1
	* @privlevel	NORMAL
	* @privgroup	IMAGE
	*
	* @return		A pointer to the Bitmap instance generated from the specified file
	* @param[in] 	imagePath				The relative path starting from the directory "/Res/ScreenDensity-XXX/", @n
	* 										where A and B represent the screen width and height of the supported device models, respectively.
	* @param[in] 	pixelFormat				The pixel format of the resulting bitmap
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			The instance is in an invalid state to execute the method at the time of invocation.
	* @exception	E_INVALID_ARG			A specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT	The image file format or specified pixel format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found.
	* @exception	E_PRIVILEGE_DENIED 		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM				A system error has occurred.
	*/
	Osp::Graphics::Bitmap* GetBitmapN(const Osp::Base::String& imagePath, Osp::Graphics::BitmapPixelFormat pixelFormat) const;
	
	/**
	* Gets the bitmap at the specified path. @n
    * This method interprets the given resource path and reads the best matching image file for the current device resolution. @n
    * To load the bitmap image from a file, give the name of the file as the input parameter and not the file path (Ex: "img.png").
    * Then, the system will first look for the image file in the folder specific to the current device resolution, such as
    * '320x480' and if the file does not exist, it will then search the folder that corresponds to the current screen density, 
    * such as 'ScreenDensity-Middle'. After searching the density folder, all the other density folders are searched in the order high to low.
    * Currently supported image formats are: JPEG, GIF, PNG, BMP, TIFF, and WBMP.
    * 
    * In this method, the system decides the proper pixel format and whether to use chroma key composition to enable transparency. @n
    * If the input image file has the alpha channel, the pixel format is set to Osp::Graphics::BITMAP_PIXEL_FORMAT_ARGB8888. 
    * Otherwise, the pixel format is set to Osp::Graphics::BITMAP_PIXEL_FORMAT_RGB565 and the masking color of the bitmap is set to magenta, Osp::Graphics::Color(255, 0, 255). @n
    * Typically, a WVGA bada device would support alpha channel, while WQVGA device would support bitmap with masking color, to support transparency. 
    * A 32-bit version and 16-bit version of the resource (image) can be placed in the WQVGA resource folder . To distinguish the pixel format, a postfix '@@16', such as 'image@@16.bmp' can be used for 16-bit version.
        * If no postfix is used, this API loads the correct image and sets the pixel format from the image file that is appropriate for the current device. 
    * Currently supported image formats are: JPEG, GIF, PNG, BMP, TIFF, and WBMP.
    *
    * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                For more information, see @ref CompGetBitmapN20 "here".
	*
	* @since		1.1
	* @privlevel	NORMAL
	* @privgroup	IMAGE
	*
	* @return		A pointer to the Bitmap instance generated from the specified file
	* @param[in] 	imagePath				The relative path starting from the density directory "/Res/ScreenDensity-XXX/", @n
	* 										where A and B represent the width and height of the screen of the supported device models, respectively
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			The instance is in an invalid state to execute the method at the time of invocation.
	* @exception	E_INVALID_ARG			The specified input parameter is invalid.
	* @exception	E_UNSUPPORTED_FORMAT	The image file format is not supported.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_FILE_NOT_FOUND		The specified file cannot be found.
	* @exception	E_PRIVILEGE_DENIED 		The application does not have the privilege to call this method.
	* @exception	E_SYSTEM				A system error has occurred.
	*/
	Osp::Graphics::Bitmap* GetBitmapN(const Osp::Base::String& imagePath) const;

    /**
    * @page CompGetBitmapN20 Compatibility for GetBitmapN()
    * @section CompGetBitmapN20Issues Issues
    *   Implementation of this method in bada API versions prior to 2.0 has the following issues:
    * -# In the bada API version prior to 2.0, the method first attempts to find the image file in the folder that corresponds to the current screen resolution: one of 240x400 and 
    *  480x800. If it fails to find the image file, then, it tries the other folder.
    * -# From bada API version 2.0, the method attempts to find the image file in the following order: the folder that corresponds to the current screen resolution, the folder that
    *  corresponds to the current screen size category and ScreenDensity-High folder.
    *
    * @section CompGetBitmapN20Resolutions Resolutions
    * The issues mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
    */

	/**
	* Gets the %AppResource instance pointer.
	* 
	* @since  2.0
	* @return A pointer to the %AppResource instance, @n
	*		  else @c null if it fails
	*/
	static AppResource* GetInstance(void);

private:
	void *  __pDoc;
	friend class __BaseApplication;

	friend class AppResourceEx;
	class AppResourceEx* __pAppResourceEx;
};

}; }; // Osp::App


#endif
