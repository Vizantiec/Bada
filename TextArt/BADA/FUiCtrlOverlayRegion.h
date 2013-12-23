// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//

/**
 * @file    FUiCtrlOverlayRegion.h
 * @brief   This is the header file for the %OverlayRegion class.
 *
 * This header file contains the declarations of the %OverlayRegion class.
 */

#ifndef _FUICTRL_OVERLAY_REGION_H_
#define _FUICTRL_OVERLAY_REGION_H_


#include "FBaseObject.h"
#include "FUiCtrlConfig.h"


namespace Osp { namespace Ui { namespace Controls {


/**
 * @enum	OverlayRegionBufferPixelFormat
 *
 * Defines the pixel formats.
 * @since	2.0 
 */
enum OverlayRegionBufferPixelFormat
{
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_MIN = 0,			/**< @internal Specifies the minimum number of enumerated items. This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum. */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_ARGB8888,		/**< The ARGB8888 pixel format */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_RGB565,			/**< The RGB565 pixel format */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_YCbCr420_PLANAR,	/**< The 8-bit Y plane followed by the 8-bit 2x2 subsampled U and V planes */
	OVERLAY_REGION_BUFFER_PIXEL_FORMAT_MAX				/**< @internal Specifies the maximum number of enumerated items. This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum. */
};

/**
 * @enum	OverlayRegionType
 *
 * Defines the type of an overlay region.
 * @since	2.0 
 */
enum OverlayRegionType
{
	OVERLAY_REGION_TYPE_MIN = 0,						/**< @internal Specifies the minimum number of enumerated items. This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum. */
	OVERLAY_REGION_TYPE_PRIMARY_CAMERA,					/**< The primary camera type @n 
															An overlay region displays the auto-rotated primary camera input that comes from Camera. */
	OVERLAY_REGION_TYPE_SECONDARY_CAMERA,				/**< The secondary camera type @n 
															An overlay region displays the auto-rotated and mirrored secondary camera input that comes from Camera. */
	OVERLAY_REGION_TYPE_NORMAL,							/**< The normal type @n 
															An overlay region displays the user input as it is. */
	OVERLAY_REGION_TYPE_MAX								/**< @internal Specifies the maximum number of enumerated items. This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this enum. */
};

/**
 * @enum OverlayRegionEvaluationOption
 *
 * Defines the option for evaluating the bounds of an overlay region.
 * @since	2.0 
 */
enum OverlayRegionEvaluationOption
{
	OVERLAY_REGION_EVALUATION_OPTION_GREATER_THAN,	/**< The option evaluating the overlay region bounds and finding the minimum bounds greater than the input bounds */
	OVERLAY_REGION_EVALUATION_OPTION_LESS_THAN,		/**< The option evaluating the overlay region bounds and finding the maximum bounds smaller than input bounds */
};


/**
 * @class	OverlayRegion
 * @brief	This class is an implementation of an %OverlayRegion.
 * @since	2.0
 *
 * The %OverlayRegion class displays a region of an overlay surface, which is used to play back a video or show the camera preview. 
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_overlay_region.htm">OverlayRegion</a>.
 */
class _EXPORT_CONTROLS_ OverlayRegion :
	public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~OverlayRegion(void);

	/**
	 * Gets the position and size of the overlay region.
	 *
	 * @since		2.0
	 * @return		An instance of Rectangle that represents the position of the top-left corner, the width, and the height of the overlay region
	 *
	 * @remarks	The shape of an overlay region is rectangular, which is defined by the top-left point, and the width or height. The position of the top-left 
	 *			point is relative to the top-left corner of the parent form.
	 *
	 */
	Osp::Graphics::Rectangle GetBounds(void) const;

	/**
	 * Gets the position and size of the overlay region.
     *
	 * @since		2.0
	 * @param[out]	x		The x position of the top-left corner of the overlay region
	 * @param[out]	y		The y position of the top-left corner of the overlay region
     * @param[out]	width	The width of the rectangular region
     * @param[out]	height	The height of the rectangular region
     *
	 * @remarks	The shape of an overlay region is rectangular, which is defined by the top-left point, and the width or height. The position of the top-left 
	 *			point is relative to the top-left corner of the parent form.
	 *
     */
    void GetBounds(int& x, int& y, int& width, int& height) const;

	/**
	 * Sets the input buffer. @n
	 * Due to the hardware accelerated rendering, there are limitations for an input buffer. The input buffer has the same restriction regarding its size as 
	 * the overlay region and it can be checked by using the GetWidthUnit(), GetHeightUnit() and GetMaxCount(). If the specified condition is not satisfied, 
	 * the E_INVALID_ARG exception is returned. If an input buffer does not fit to the bounds of the overlay region, it will be scaled up or down to the overlay 
	 * region bounds without keeping the ratio of input.
	 *
	 * @since		2.0
   	 * @return		An error code
	 * @param[in]	srcBuffer				The source buffer
	 * @param[in]	srcDim					The source dimension
	 * @param[in]	srcFormat				The pixel format of buffer data
	 *
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception	E_UNSUPPORTED_FORMAT 	The specified pixel format is not supported.
	 * @exception	E_INVALID_OPERATION  	The current state of the instance prohibits the execution of the specified operation.
 	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result SetInputBuffer(const Osp::Base::ByteBuffer& srcBuffer, const Osp::Graphics::Dimension& srcDim, OverlayRegionBufferPixelFormat srcFormat);

	/**
	 * Gets the information related to the background buffer.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @param[out]	info					The information of the input buffer
	 *
	 * @exception	E_SUCCESS				The method is successful.
 	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation.
 	 * @exception	E_SYSTEM				A system error has occurred.
	 *
	 * @remarks This method provides the buffer information, except the pointer of a color buffer. Therefore, info.pPixels is always assigned as @c null.
	 */
	result GetBackgroundBufferInfo(Osp::Graphics::BufferInfo& info) const;

	/**
	 * Shows the overlay region on the screen.
	 * 
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
 	 * @exception	E_INVALID_OPERATION		The current state of the instance prohibits the execution of the specified operation, that is, this control cannot be displayed.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result Show(void);

	/**
	 * Evaluates and returns the valid position and size that are closest to the specified bounds.
	 *
	 * @since		2.0
	 * @return		@c true if the specified @c rectangle is suitable for use, @n
	 *				else @c false
	 * @param[in]		option					The option for evaluating the bounds of the overlay region
	 * @param[in, out]	rect					An instance of %Rectangle that represents the validated bounds of %OverlayRegion @n
	 *											The width and height of the input rectangle should be greater than @c 0.
	 * @param[out]		modified				A boolean flag that indicates whether the specified @c rectangle is modified
	 * @exception		E_SUCCESS				The method is successful.
	 * @exception		E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception		E_UNSUPPORTED_OPTION	A specified input parameter is not supported.
	 * @exception		E_SYSTEM				A system error has occurred.
	 *
	 * @remarks	Due to the hardware accelerated rendering, there are limitations for an overlay region. @n
	 * 			The hardware capability for an overlay region is checked by using the GetWidthUnit(), GetHeightUnit() and GetMaxCount(). @n
	 *			If the application runs on multi-screen resolutions, the specified bounds may not meet the hardware limitations of the overlay region. In 
	 *			such cases, GetOverlayRegionN() will return E_INVALID_ARG. @n
	 * 			To prevent this kind of problem, the application should use the OverlayRegion::EvaluateBounds() method to get a validated bounds that can be 
	 *			used as the input bounds of the GetOverlayRegionN() method.
	 *
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static bool EvaluateBounds(OverlayRegionEvaluationOption option, Osp::Graphics::Rectangle& rect, bool& modified);

	/**
	 * Gets the value of the width. @n 
	 * Only a multiple of this value can be allowed as the width of an overlay region.
	 *
	 * @since		2.0
	 * @return		The value of width
	 *
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetWidthUnit(void);

	/**
	 * Gets the value of the height. @n 
	 * Only a multiple of this value can be allowed as the width of an overlay region.
	 *
	 * @since		2.0
	 * @return		The value of the height
	 *
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks	The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetHeightUnit(void);

	/**
	 * Gets the maximum count of overlay regions that can be used simultaneously per application.
	 *
	 * @since		2.0
	 * @return		The maximum count of overlay regions that can be used simultaneously per application
	 *
	 * @exception	E_SUCCESS	The method is successful.
	 * @exception	E_SYSTEM	A system error has occurred.
	 * @remarks The specific error code can be accessed using the GetLastResult() method.
	 */
	static int GetMaxCount(void);

private:
	OverlayRegion(void);
	OverlayRegion(const OverlayRegion& overlayRegion);
	OverlayRegion& operator =(const OverlayRegion& rhs);

	friend class OverlayRegionEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class OverlayRegionEx*	__pOverlayRegionEx;

}; // OverlayRegion

}; }; }; // Osp::Ui::Controls

#endif// _FUICTRL_OVERLAY_CONTROL_H_
