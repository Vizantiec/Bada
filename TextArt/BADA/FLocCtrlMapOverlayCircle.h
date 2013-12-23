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
* @file		FLocCtrlMapOverlayCircle.h
* @brief	This is the header file for the %MapOverlayCircle class.
*
* This header file contains the declarations of the %MapOverlayCircle class.
*/
#ifndef _FLOC_CTRL_MAPVIEW_CIRCLE_H_
#define _FLOC_CTRL_MAPVIEW_CIRCLE_H_

#include <FLocCtrlMapOverlayShape.h>
#include <FLocCircleGeographicArea.h>
#include <FLocCoordinates.h>

namespace Osp { namespace Graphics { class Canvas; }; };
namespace Osp { namespace Graphics { class Point; }; };

namespace Osp { namespace Locations { namespace Controls {

class __IMapOverlayCircle;

/**
 * @class	MapOverlayCircle
 * @brief	This class defines the common behaviors for a circle.
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * The %MapOverlayCircle class displays a circle overlay. This class also provides the methods that help getting the rectangle bounds of a circle and the circular 
 * geographical area on the WGS 84 Ellipsoid.
 * The Map control renders the circle overlay on the map and not on the Earth's surface.
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
 */
class _EXPORT_LOCATION_CONTROL MapOverlayCircle :
	public Osp::Locations::Controls::MapOverlayShape
{
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	area	The area of this control
	 */
	MapOverlayCircle(const Osp::Locations::CircleGeographicArea& area);

	/**
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~MapOverlayCircle(void);

protected:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the circle.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	*/
	virtual void DrawOverlay(Osp::Graphics::Canvas& canvas);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the shadow of the circle.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	canvas	The graphic canvas of this control
	*/
	virtual void DrawOverlayShadow(Osp::Graphics::Canvas& canvas);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Checks whether the circle is hit.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The hit status of the circle
	* @param[in]	anchor	The pixel value transformed from the center coordinates of the circle
	* @param[in]	pt		The hit point
	*/
	virtual bool Contains(const Osp::Graphics::Point& anchor, const Osp::Graphics::Point& pt) const;

public:
	/**
	* Gets the rectangle bound of the circle.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The rectangle bound of the circle
	*/
	virtual const Osp::Locations::RectangleGeographicArea* GetBounds(void) const;

	/**
	* Gets the instance of a circular geographical area on the WGS 84 Ellipsoid.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The %CircleGeographicArea of the circle
	*/
	Osp::Locations::CircleGeographicArea GetGeographicArea(void) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of MapOverlayCircle to destination
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dest			The destination to be copied.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result CopyData(__IMapOverlayCircle& dest) const;

private:

	/*
	* CircleGeographicArea instance.
	*/
	Osp::Locations::CircleGeographicArea	__bound;

private:

	friend class MapOverlayCircleEx;
	class MapOverlayCircleEx* __pMapOverlayCircleEx;

};		// MapOverlayCircle

};};};	// Osp::Ui::Controls

#endif	// _FLOC_CTRL_MAPVIEW_CIRCLE_H_
