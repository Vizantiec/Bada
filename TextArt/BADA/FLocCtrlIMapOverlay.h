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
* @file		FLocCtrlIMapOverlay.h
* @brief	This is the header file for the %IMapOverlay interface.
*
* This header file contains the declarations for the %IMapOverlay interface.
*/

#ifndef _FLOC_CTRL_IMAPOVERLAY_H_
#define _FLOC_CTRL_IMAPOVERLAY_H_

#include <FLocationControlConfig.h>
#include <FLocCoordinates.h>
#include <FLocRectangleGeographicArea.h>

namespace Osp { namespace Graphics { class Canvas; }; };
namespace Osp { namespace Graphics { class Point; }; };

namespace Osp { namespace Locations { namespace Controls {

/**
* @interface	IMapOverlay
* @brief		This interface is used as the most prime interface of the map overlay.
* @deprecated	This interface is deprecated.
* @since		1.0
*
* The %IMapOverlay interface is used as the most prime interface of the map overlay. 
* All overlays must implement the %IMapOverlay interface.
* 
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
*/

class _EXPORT_LOCATION_CONTROL IMapOverlay
{

public:
	
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	IMapOverlay(void){};

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~IMapOverlay(void){};

	/**
	* Gets the coordinates of an overlay. @n
	* OverlayRectangle and OverlayCircle return their center coordinates. But OverlayPolygon returns the center coordinates of its circumscribed rectangle 
	* boundary. If the map calls a custom MapOverlay, it returns the designated value.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The coordinates of an overlay
	*/
	virtual Osp::Locations::Coordinates GetCoordinates(void) const = 0;

	/**
	* Gets the Z order of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The Z order of the overlay
	*/
	virtual int GetZOrder(void) const = 0;

	/**
	* Gets the priority of the overlay. @n
	* The priority is used for selecting the overlays to be drawn when the number of overlays is greater than the overlay display maximum count set by 
	* calling Map::SetOverlayDisplayMaxCount(). The overlays with the higher priority are selected first.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The priority of the overlay
	* @see			Map::SetOverlayDisplayMaxCount()
	*/
	virtual int GetPriority(void) const = 0;

	/**
	* Gets the visibility of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The visibility of the overlay
	*/
	virtual bool GetShowState(void) const = 0;

	/**
	* Checks whether shadow is enabled.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the shadow is enabled, @n
	*				else @c false
	*/
	virtual bool IsShadowEnabled(void) const = 0;

	/**
	* Gets the ID of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The ID of the Overlay
	*/
	virtual int GetId(void) const = 0;

	/**
	* Gets the rectangle bound of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The rectangle bound of the overlay
	*/
	virtual const Osp::Locations::RectangleGeographicArea* GetBounds(void) const = 0;
	
protected:
	
	/**
	* Checks whether the overlay is hit.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The hit status of the marker
	* @param[in]	anchor		The pixel value transformed from the center coordinates of the %IMapOverlay
	* @param[in]	pt			The hit point
	*/
	virtual bool Contains(const Osp::Graphics::Point& anchor, const Osp::Graphics::Point& pt) const = 0;

	/**
	* Draws the overlay. @n
	* The method can be overridden in a child class.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	*/
	virtual void DrawOverlay(Osp::Graphics::Canvas& canvas) = 0;

	/**
	* Draws the shadow of the overlay. @n
	* This method can be overridden in a child class.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	*/
	virtual void DrawOverlayShadow(Osp::Graphics::Canvas& canvas) = 0;

private:
	
	friend class __Util;

};	// IMapOverlay

};};};	// Osp::Locations::Controls;

#endif	// _FLOC_CTRL_IMAPOVERLAY_H_
