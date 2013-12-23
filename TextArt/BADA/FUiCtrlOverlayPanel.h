/* $Change: 995579 $ */
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
* @file		FUiCtrlOverlayPanel.h
* @brief	This is the header file for the %OverlayPanel class.
*
* This header file contains the declarations of the %OverlayPanel class.
*/
#ifndef _FUICTRL_OVERLAY_CONTROL_H_
#define _FUICTRL_OVERLAY_CONTROL_H_

// Includes
#include "FUiCtrlConfig.h"
#include "FBaseTypes.h"
#include "FUiCtrlPanel.h"
#include "FGrpCanvas.h"

namespace Osp { namespace Ui { namespace Controls { class Panel; };};};

namespace Osp { namespace Ui { namespace Controls {


/**
 * @class		OverlayPanel
 * @brief		This class is an implementation of %OverlayPanel.
 * @deprecated 	This class is deprecated. Instead of using this class, use the OverlayRegion class, that supports video playback and camera preview.
 * @since		1.0
 *
 * @remarks	The %OverlayPanel control can only be attached to a %Form control by using Osp::Ui::Container::AddControl method, because of its native 
 *			characteristics. Since %OverlayPanel inherits a Panel control, it can be used as a container if needed.
 *
 * The %OverlayPanel class is an implementation of the %OverlayPanel control.
 * The %OverlayPanel is a special type of panel which is used to specify a region where the developer
 * can playback video or camera preview. It is called an overlay because it is possible to overlay
 * other graphics and controls on top of the panel.
 * The %OverlayPanel consists of two layers, the foreground panel and background buffer which supports
 * H/W accelerated rendering. Due to the hardware accelerated nature, there is a limitation with an
 * %OverlayPanel. The Form that houses an %OverlayPanel can only have a black, opaque background.
 * The overlay panel can manipulate the rotation, the aspect ratio and the size of input buffer.
 *
 * Example: Please refer to the camera preview example of Osp::Media::Camera
 *
 *
 */
class _EXPORT_CONTROLS_ OverlayPanel :
	public Osp::Ui::Controls::Panel
{
	DECL_CLASSTYPE(OverlayPanel);
	// Lifecycle
public:
	/**
	* @enum   Rotation
	* Defines the various rotation options.
	*
	* @deprecated	This enumerator is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera 
	*				preview.
	*
	* @since	1.0
	*/
	typedef enum {
		ROTATION_NONE,		/**< No rotation */
		ROTATION_90,		/**< The 90 degree rotation */
		ROTATION_180,		/**< The 180 degree rotation */
		ROTATION_270,		/**< The 270 degree rotation */
		ROTATION_NONE_LR,	/**< The horizontal mirroring */
		ROTATION_NONE_UD,	/**< The vertical mirroring */
		ROTATION_90_LR,		/**< The 90 degree rotation with horizontal mirroring */
		ROTATION_90_UD,		/**< The 90 degree rotation with vertical mirroring */
		ROTATION_180_LR,	/**< The 180 degree rotation with horizontal mirroring */
		ROTATION_180_UD,	/**< The 180 degree rotation with vertical mirroring */
		ROTATION_270_LR,	/**< The 270 degree rotation with horizontal mirroring */
		ROTATION_270_UD,	/**< The 270 degree rotation with vertical mirroring */
		ROTATION_MAX
	}Rotation;

	/**
	 * @enum	BufferPixelFormat
	 * Defines the pixel formats.
	 *
	 * @deprecated	This enumerator is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since	1.0
	 */
	enum BufferPixelFormat
	{
		/**
		 * The ARGB8888 pixel format
		 *
		 */
		BUFFER_PIXEL_FORMAT_ARGB8888,
		/**
		 * The RGB565 pixel format
		 *
		 */
		BUFFER_PIXEL_FORMAT_RGB565,

		/**
		 * The 8 bit Y plane followed by 8 bit 2 X 2 subsampled U and V planes
		 *
		 */
		BUFFER_PIXEL_FORMAT_YCbCr420_PLANAR
	};

	/**
	 *	This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since	1.0
	 */
	OverlayPanel(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since	1.0
	 */
	virtual ~OverlayPanel(void);

	/**
	 * Initializes this instance of %OverlayPanel at the specified rectangle.
	 *
     * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompControlConstruct20 "here".
	 * @return		An error code
	 * @param[in]	rect				The location and size of the %OverlayPanel control @n
	 *									The maximum size is 480 x 800 on a WVGA screen, or 240 x 400 on a WQVGA screen. @n
	 *									The minimum size of this control is 32 x 32 on a WVGA screen.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE		This instance has already been constructed.
	 * @exception 	E_INVALID_ARG		A specified input parameter is invalid.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0. @n
	 *				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
	 * @remarks		Do not use %OverlayPanel in combination with %OverlayRegion. If used, %OverlayPanel may not work as expected.
	 * @see			Osp::Ui::Container
	 */
	result Construct(const Osp::Graphics::Rectangle& rect);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since		1.0
	 * @param[in]	rect	 A rectangle of the background buffer
	 */
	void SetInputRectangle(Osp::Graphics::Rectangle & rect);

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * @since			1.0
	 * @return			An error code
	 * @param[in]		rect		The rectangle of the background buffer
	 * @exception		E_SUCCESS	The method is successful.
	 * @exception		E_OPERATION_FAILED	The operation has failed.
	 * @exception		E_INIT_FAILED OverlayPanel is not initialized.
	 *
	 */
	result GetInputRectangle(Osp::Graphics::Rectangle & rect);

	/**
	* Sets the rotation of the input buffer. @n
	* All the rotations are clock-wise.
	*
	* @deprecated  This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	*
	* @since		1.0
	*
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0 @n
	*		  					For more information, see @ref CompOverlayPanelSetInputBuffer2 "here".
	* @param[in]	rotation	The rotation
	*
	*/
	void SetRendererRotation(OverlayPanel::Rotation rotation);

	/**
	 * Changes the size of the displayed renderer.
	 *
	 * @deprecated  This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since		1.0
	 *
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0 @n
	 *		  					For more information, see @ref CompOverlayPanelSetInputBuffer2 "here".
	 * @param[in]	dim		The dimension of the window to draw
	 *
	 */
	void SetRendererSize(Osp::Graphics::Dimension& dim);

	/**
	* Sets the aspect ratio of the renderer.
	*
	* @deprecated This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	*
	* @since		1.0
	*
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0 @n
	*		  					For more information, see @ref CompOverlayPanelSetInputBuffer2 "here".
	*
	* @param[in]	fix		Set to @c true if the renderer will display the aspect ratio of the input buffer even if the renderer and input data have 
	*						different aspect ratios, @n
	*						else @c false
	*/
	void SetRendererAspectRatio(bool fix);
	
	/**
	 * Sets the input buffer.
	 *
	 * @deprecated This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since		1.0
	 *
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	 *		  			For more information, see @ref CompOverlayPanelSetInputBuffer "here".
	 *
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0 @n
	 *		  					For more information, see @ref CompOverlayPanelSetInputBuffer2 "here".
	 *
	 * @param[in]  	destDim				  	The dimension of the window to be drawn
	 * @param[in]  	srcBuffer              	The source buffer
	 * @param[in]  	srcDim                 	The source dimension
	 * @param[in]  	srcFormat              	The pixel format of buffer data
	 * @exception  	E_SUCCESS				The method is successful.
	 * @exception  	E_INVALID_ARG			A specified input parameter is invalid.
	 * @exception  	E_SYSTEM				A system error has occurred.
	 * @exception  	E_UNSUPPORTED_FORMAT   	The specified pixel format is not supported.
	 * @exception  	E_INVALID_STATE			This instance has not been constructed as yet.
	 *
	 * @remarks	BUFFER_PIXEL_FORMAT_ARGB8888, and BUFFER_PIXEL_FORMAT_RGB565 are not supported. @n
	 *			Form::Draw() and Form::Show() methods should be called to properly display the input buffer.
	 *
	 */
	result SetInputBuffer(const Osp::Graphics::Dimension& destDim, const Osp::Base::ByteBuffer& srcBuffer, const Osp::Graphics::Dimension& srcDim, BufferPixelFormat srcFormat);
	
	/**
	 * @page	CompOverlayPanelSetInputBuffer	Compatibility for SetInputBuffer()
	 * @section	CompOverlayPanelSetInputBufferIssues	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -# If an application deallocates or modifies the buffer passed to SetInputBuffer() before %OverlayPanel stops using the buffer, 
	 *	  it causes the application to terminate abnormally.
	 *
	 * @section	CompOverlayPanelSetInputBufferResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */
	
	/**
	 * @page   CompOverlayPanelSetInputBuffer2 Compatibility for SetInputBuffer() / SetRendererAspectRatio() / SetRendererSize() / SetRendererRotation() / GetBackgroundBufferInfo()
	 * @section CompOverlayPanelSetInputBuffer2Issues Issues
	 *			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 *
	 * -# The rendering result of %OverlayPanel is not guaranteed for the below-mentioned options. For more information, please refer to the compatibility chart below (S-Success, F-Fail).
	 *
	 * @section CompOverlayPanelSetInputBuffer2Resolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0. However, as %OverlayPanel is deprecated it is recommended to use %OverlayRegion
	 * instead of %OverlayPanel.
	 *
     * @image	html	OverlayPanel_ARGB8888.png @n
     * @n
     * @image	html	OverlayPanel_RGB565.png @n 
     * @n
     * @image	html	OverlayPanel_YUV420.png
	 */
	
	/**
	 * Gets the information of the background buffer.
	 *
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since		1.0
	 *
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0 @n
	 *		  					For more information, see @ref CompOverlayPanelSetInputBuffer2 "here".
	 *
	 * @return		An error code
	 * @param[out]	info				The information of the background buffer
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OPERATION_FAILED	The operation has failed.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 *
	 * @remarks		Currently, this function provides buffer information except the pointer of the RGB color buffer. @n
	 *				Therefore, info.pPixels is always assigned @c null. 
	 */
	result GetBackgroundBufferInfo(Osp::Graphics::BufferInfo& info) const;

	/**
	 * Gets the masking color of this control.
	 *
	 * @deprecated	This method is deprecated. Instead of using this class, use the %OverlayRegion class, that supports video playback and camera preview.
	 *
	 * @since		1.0
	 * @return		The pixel color format
	 */
	Osp::Graphics::Color GetMaskingColor(void) const;

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)Gets the background color of this control.
	 *
	 * @since			 1.0
	 */
	virtual Osp::Graphics::Color GetBackgroundColor(void) const;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * (Blocked)Sets the foreground color of this control.
	 *
	 * @since			 1.0
	 */
	virtual void SetBackgroundColor(const Osp::Graphics::Color& color);

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
	 * @since		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS 	The method is successful.
	 * @exception	E_SYSTEM 	A system error occurred. Failed to free the resource possessed by this instance.
	 */
	 result Dispose(void);


private:
	Osp::Graphics::Canvas* __pOverlayCanvas;

	Osp::Graphics::Rectangle __inputRect;
	OverlayPanel::Rotation __rotation;

	bool __resize;
	Osp::Graphics::Dimension __resizeDim;

	bool __aspectRatio;

	// for YUV drawing
	class __TBufferCache
	{
	public:
		Osp::Graphics::PixelFormat pixelFormat;
		Osp::Graphics::Rectangle   rect;
		byte*                      pBuffer;
		int                        bufferSize;

		__TBufferCache();
		~__TBufferCache();
		void Reset(void);
	};

	__TBufferCache __bufferCache;


private:
	friend class OverlayPanelEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         1.0
     */	
	class OverlayPanelEx*	__pOverlayPanelEx;

protected:
	friend class OverlayPanelImpl;
 	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of this control
     *
     * @since         2.0
     */	
	class OverlayPanelImpl* GetImpl(void) const;

}; // OverlayPanel

}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_OVERLAY_CONTROL_H_
