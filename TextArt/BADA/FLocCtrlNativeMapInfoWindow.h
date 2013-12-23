/* $Change: 1267243 $ */
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
* @file		FLocCtrlNativeMapInfoWindow.h
* @brief	This is the header file for the %NativeMapInfoWindow class.
*
* This header file contains the declarations of the %NativeMapInfoWindow class.
*/

#ifndef _FLOC_CTRL_MAP_INFOWINDOW_H_
#define _FLOC_CTRL_MAP_INFOWINDOW_H_

#include <FBaseString.h>
#include <FGraphics.h>
#include <FLocCtrlIMapInfoWindow.h>
#include <FLocCtrlMap.h>

namespace Osp { namespace Locations { namespace Controls {
class __INativeMapInfoWindow;

/**
 * @class	NativeMapInfoWindow
 * @brief	This class is an implementation of %NativeMapInfoWindow.
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 *The %NativeMapInfoWindow class is an implementation of %NativeMapInfoWindow. An InfoWindow is a bubble of words that contains additional information about the places or map features, including:
 * 			- Native InfoWindows for adding or changing text and bitmaps.
 * 			- Custom InfoWindows for directly drawing the content onto the canvas.
 *
 * 			This class also provides the methods for getting the coordinates, size, and title text of the InfoWindow control.
 *
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/info_windows.htm">Information Windows</a>.
 */
class _EXPORT_LOCATION_CONTROL NativeMapInfoWindow
	: public Osp::Base::Object, public IMapInfoWindow
{
public:

	/**
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	NativeMapInfoWindow(void);

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	~NativeMapInfoWindow(void);

	/**
	* Initializes this instance of %NativeMapInfoWindow with the specified parameters.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompMapInfoWindowStyle "here".
	*
	* @return		An error code
	* @param[in]	style			The style of InfoWindow
	* @param[in]	width			The width of InfoWindow
	* @param[in]	height			The height of InfoWindow
	* @param[in]	coordinates		The coordinates of InfoWindow
	* @param[in]	offset			The position relative to the coordinates to be drawn (pixel offset)
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The width and height is lower than its minimum size.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @remarks		The minimum size of the InfoWindow is @c 224 x @c 134 on a WVGA screen, @c 170 x @c 100 on a HVGA screen, or @c 112 x @c 67 on a WQVGA screen.
	*/
	result Construct(MapInfoWindowStyle style, int width, int height, const Osp::Locations::Coordinates& coordinates, const Osp::Graphics::Point& offset);

	/**
	* @page       CompMapInfoWindowStyle Compatibility for Construct()
	* @section    CompMapInfoWindowStyleIssues Issues
	* 				Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 				-# The tail of the information window is placed in reverse in the vertical direction. @n
	* 				For example, if MAP_INFOWINDOW_STYPE_RIGHT_UP is chosen, the tail is placed at the bottom right section of the rectangle.
	*
	* @section    CompMapInfoWindowStyleResolutions Resolutions
	* 				-# The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0.
	*/

	/**
	* Sets the text contents of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues in bada API version @b 1.1 @b only.  All other versions are compatible.@n 
	*					For more information, see @ref InfoWindowSetContentPage "here".
	*
	* @return		An error code
	* @param[in]	text			The text string
	* @param[in]	fontSize		The text font size
	* @param[in]	textColor		The text color
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	A specified input parameter is invalid.
	*/
	result SetContent(const Osp::Base::String& text, int fontSize, const Osp::Graphics::Color& textColor);

	/**
	* @page		InfoWindowSetContentPage Compatibility for SetContent()
	*
	* @section	InfoWindowSetContentPageIssueSection Issues
	* 			Implementation of this method in bada API version 1.1 has the following issue. All other versions are compatible: @n
	*			-# The font size is set by default regardless of the value set by this method.
	*/	

	/**
	* Sets the image content of %InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	pImage			The bitmap image
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified input parameter is invalid.
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	*/
	result SetContent(const Osp::Graphics::Bitmap* pImage);

	/**
	* Sets the image content of %InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	imagePath		The local file path of the image content to be set
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified file cannot be found or accessed.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result SetContent(const Osp::Base::String& imagePath);

	/**
	* Sets the title of %InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	text	The text string
	*/
	void SetTitle(const Osp::Base::String& text);

	/**
	* Sets the status of the close button.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable	Set to @c true to enable the close button, @n
	*						else @c false
	*/
	void SetCloseButtonEnabled(bool enable);

	/**
	* Gets the coordinates of %InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The coordinates of %InfoWindow
	*/
	virtual Osp::Locations::Coordinates GetCoordinates(void) const;

	/**
	* Gets the size of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The size (width, height) of %InfoWindow
	*/
	virtual Osp::Graphics::Dimension GetSize(void) const;

	/**
	* Gets the position relative to the coordinates.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The pixel offset
	*/
	virtual Osp::Graphics::Point GetPixelOffset(void) const;

	/**
	* Checks whether the close button is enabled.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	* @return	@c true if the close button on InfoWindow is enabled, @n
	*			else @c false
	*/
	virtual bool IsCloseButtonEnabled(void) const;

	/**
	* Gets the title text of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The title text of InfoWindow
	*/
	virtual Osp::Base::String GetTitle(void) const;

	/**
	* Gets the style of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The InfoWindow style
	*/
	virtual MapInfoWindowStyle GetStyle(void) const;

	/**
	* Sets the position of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	coordinates		The coordinates of the InfoWindow to be drawn
	*/
	void  SetCoordinates(const Osp::Locations::Coordinates &coordinates);

protected:

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Draws the content of %InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	* @param[in]	rect	The rectangle area where the content will be drawn
	*/
	virtual void DrawContent(Osp::Graphics::Canvas& canvas, const Osp::Graphics::Rectangle& rect);

private:

	/*
	* Frees the resources allocated by this control and destroys its native window.
	*
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	*/
	result Dispose(void);

public:

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Sets the implementation of the NativeMapInfoWindow. when opening the information window, the implementation instance is set.
	* when closing it, @c null is set.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @param[in]	pInfoWnd	The instance of the implementation class
	*
	*/
	void SetImplementation(__INativeMapInfoWindow* pInfoWnd) const;

	/**
    * @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Gets the instance of the implementation class. when opening the information window, the implementation instance is set.
	* when closing it, null is set.
	*
	 * @deprecated	This method is deprecated.
	* @since	2.0
	* @return	@c null, if information window does not have an implementation, 
	*			otherwise the instance of the implementation class
	*/	 
	__INativeMapInfoWindow* GetImplementation(void) const;	

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of NativeMapInfoWindow to destination
	*
	 * @deprecated	This method is deprecated.
	* @since 		2.0
	* @return		An error code
	* @param[in]	dest		The destination to be copied.
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method has failed.
	*/
	result CopyData(__INativeMapInfoWindow& dest) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.	
	*
	* Gets image content of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The bitmap image
	* @param[out]	isImage		@c true, if image is set as the content
	*/
	const Osp::Graphics::Bitmap* GetContent(bool& isImage) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Gets text content of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		true, if text is set as the content
	* @param[in]	text			The text string
	* @param[in]	fontSize		The text font size
	* @param[in]	textColor		The text color
	*/
	bool GetContent(Osp::Base::String& text, int& fontSize, Osp::Graphics::Color& textColor) const;

private:

	/*
	* The style of InfoWindow.
	*/
	MapInfoWindowStyle				__style;

	/*
	* The width of InfoWindow.
	*/
	int								__width;

	/*
	* The height of InfoWindow.
	*/
	int								__height;

	/*
	* The coordinate of InfoWindow.
	*/
	Osp::Locations::Coordinates		__coordinates;

	/*
	* The pixel offset.
	*/
	Osp::Graphics::Point			__offset;

	/*
	* The text string.
	*/
	Osp::Base::String				__text;

	/*
	* The bitmap image.
	*/
	Osp::Graphics::Bitmap*			__pImage;

	/*
	* The visibility of InfoWindow.
	*/
	bool							__bVisible;

	/*
	* Determines whether to use the close button or not.
	*/
	bool							__bCloseButton;

	/*
	* The length of text string.
	*/
	int								__textLength;

	/*
	* The font size of text.
	*/
	int								__fontSize;

	/*
	* The color of text.
	*/
	Osp::Graphics::Color			__textColor;

	/*
	* The font style.
	*/
	int								__fontStyle;

	/*
	* The title text string.
	*/
	Osp::Base::String				__titleText;

	/*
	* The content type.
	*/
	int								__nContentStyle;

private:
	friend class Map;

private:
	
	friend class NativeMapInfoWindowEx;
	class NativeMapInfoWindowEx* __pNativeMapInfoWindowEx;

};		// NativeMapInfoWindow

};};};	// Osp::Locations::Controls;

#endif	//_FLOC_CTRL_MAP_INFOWINDOW_H_
