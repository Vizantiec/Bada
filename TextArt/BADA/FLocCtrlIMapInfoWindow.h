/* $Change: 1267878 $ */
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
* @file		FLocCtrlIMapInfoWindow.h 
* @brief	This is the header file for the %IMapInfoWindow interface.
*
* This header file contains the declarations of the %IMapInfoWindow interface.
*/
#ifndef _FLOC_CTRL_CTRL_IMAP_INFO_WINDOW_H_
#define _FLOC_CTRL_CTRL_IMAP_INFO_WINDOW_H_

#include <FLocationControlConfig.h>
#include <FLocCoordinates.h>
#include <FGrpDimension.h>
#include <FGrpPoint.h>

namespace Osp { namespace Graphics { class Canvas; }; };
namespace Osp { namespace Graphics { class Rectangle; }; };

namespace Osp { namespace Locations { namespace Controls {

/**
* @enum MapInfoWindowStyle
* Defines the InfoWindow style.
*
* @deprecated	This enumerated type is deprecated.
* @since	1.0
*/
enum MapInfoWindowStyle
{
	MAP_INFOWINDOW_STYLE_RIGHT_UP		= 0x00,		/**< The tail of InfoWindow is located in upper-right */
	MAP_INFOWINDOW_STYLE_RIGHT_DOWN		= 0x01,		/**< The tail of InfoWindow is located in lower-right */
	MAP_INFOWINDOW_STYLE_LEFT_UP		= 0x02,		/**< The tail of InfoWindow is located in upper-left */
	MAP_INFOWINDOW_STYLE_LEFT_DOWN		= 0x03		/**< The tail of InfoWindow is located in lower-left */
};

/**
* @interface	IMapInfoWindow
* @brief		This interface is used as the most prime interface of the MapInfoWindow class.
 * @deprecated	This interface is deprecated.
* @since		1.0
*
* The %IMapInfoWindow interface provides the means to render an InfoWindow on top of a map, and retrieve its details. This interface is implemented in order 
* to use custom %InfoWindows.
*
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/info_windows.htm">Information Windows</a>.
*
*/

class _EXPORT_LOCATION_CONTROL IMapInfoWindow 
{

public :
	
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	IMapInfoWindow(void){};

	/** 
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*/
	virtual ~IMapInfoWindow(void){};

	/**
	* Gets the coordinates of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The coordinates of InfoWindow
	*/
	virtual Osp::Locations::Coordinates GetCoordinates(void) const = 0;

	/**
	* Gets the size of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The size of InfoWindow
	*/
	virtual Osp::Graphics::Dimension GetSize(void) const = 0;                     

	/**
	* Gets the relative position of the coordinates.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The pixel offset
	*/
	virtual Osp::Graphics::Point GetPixelOffset(void) const = 0;                   

	/**
	* Checks whether the close button is enabled.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the close button on InfoWindow is enabled, @n
	*				else @c false
	*/
	virtual bool IsCloseButtonEnabled(void) const = 0;

	/**
	* Gets the title text of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The title text of InfoWindow
	*/
	virtual Osp::Base::String GetTitle(void) const = 0;

	/**
	* Gets the style of InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The style of InfoWindow
	*/
	virtual MapInfoWindowStyle GetStyle(void) const = 0;
	
protected:		

	/**
	* Draws the content of InfoWindow. @n
	* This method can be overridden in a child class.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas		The graphic canvas of this control
	* @param[in]	rect		The rectangle area where the content will be drawn
	*/
	virtual void DrawContent(Osp::Graphics::Canvas& canvas, const Osp::Graphics::Rectangle& rect) = 0;    

private:
	
	friend class __Util;

};

};};};

#endif //_FLOC_CTRL_CTRL_INATIVE_MAP_INFO_WINDOW_H_
