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
* @file		FLocCtrlMapOverlayMarker.h
* @brief	This is the header file for the %MapOverlayMarker class.
*
* This header file contains the declarations of the %MapOverlayMarker class.
*/
#ifndef _FLOC_CTRL_MAP_OVERLAY_MARKER_H
#define _FLOC_CTRL_MAP_OVERLAY_MARKER_H

#include <FLocCtrlNativeMapOverlay.h>
#include <FGrpPoint.h>

namespace Osp { namespace Graphics { class Bitmap; }; };

namespace Osp { namespace Locations { namespace Controls {

class __IMapOverlayMarker;

/**
 * @class	MapOverlayMarker
 * @brief	This class defines the common behavior of an overlay marker.
 * @deprecated	This class is deprecated.
 * @since	1.0
 *
 * The %MapOverlayMarker class defines the common behavior of an overlay marker. The overlay marker is interactive and provides event handlers. With these event handlers, applications can add interactivity, such as opening a 
 * 			website for a restaurant on a map, exchanging data and interacting with an application, or drawing on a map. The markers are used in almost the 
 *			same way as colored pins are used on physical maps. This class also provides the methods that help in retrieving the rectangle bounds and centre coordinates of a marker.
 * 
 * 
 *
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
 */
class _EXPORT_LOCATION_CONTROL MapOverlayMarker :
	public Osp::Locations::Controls::NativeMapOverlay
{
public:
	/**
	* Initializes this instance of %MapOverlayMarker with the specified coordinates.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	coordinates		The coordinates of the marker to be drawn
	*/
	MapOverlayMarker(const Osp::Locations::Coordinates& coordinates);

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~MapOverlayMarker(void);

	/**
	* Gets the position of the marker.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The center coordinates of a marker
	*/
	virtual Osp::Locations::Coordinates GetCoordinates(void) const;

protected:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Draws the marker.
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
	* Draws the shadow of the marker.
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
	* Checks whether the marker is hit.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The hit status of the marker
	* @param[in]	anchor	The pixel value transformed from the center coordinates of the marker
	* @param[in]	pt		The hit point
	*/
	virtual bool Contains(const Osp::Graphics::Point& anchor, const Osp::Graphics::Point& pt) const;

public:
	/**
	* Sets the drag and drop status of the marker.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref MarkerDragDropPage "here".
	*
	* @param[in]		enable	Set to @c true to enable drag and drop for the marker, @n
	*						else @c false
	*/
	void SetDragDropEnabled(bool enable);

	/**
	* @page			MarkerDragDropPage Compatibility for SetDragDropEnabled()
	*
	* @section		MarkerDragDropIssueSection Issues
	*				Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 				-# If the top-left corner of the map is not positioned at the top-left corner of the screen,
	*				when dragging a marker, the map is not drawn accurately.
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/

	/**
	* Checks whether the marker can be dragged and dropped.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the marker can be dragged and dropped, @n
	*				else @c false
	*/
	bool IsDragDropEnabled(void) const;

	/**
	* Sets a bitmap image as a marker.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref MarkerSetImagePage "here".
	*
	* @return		An error code
	* @param[in]	pMarkerImage	The bitmap image of the marker @n
	*								If this parameter has @c null value, the default image is used.
	* @param[in]	hotSpot			The pixel position of the image corresponding to the coordinates of the marker  @n
	*								If @c pMarkerImage has @c null value, this input parameter is ignored and the default value is used.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	* @remarks		If the hotspot is set again by SetHighlightedImage(), the value of the hotspot is overwritten.
	* @see			SetHighlightedImage()
	*/
	result SetImage(const Osp::Graphics::Bitmap* pMarkerImage, const Osp::Graphics::Point& hotSpot);

	/**
	* Sets the image at the specified image path as a marker.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	markerImagePath	The local file path of the image file to set as a marker @n
	*                           	If this parameter is an empty string value, the default image is used.
	* @param[in]	hotSpot			The pixel position of the image corresponding to the coordinates of marker @n
	*                            	If @c markerImagePath has an empty string value, this input parameter is ignored and the default value is used.
	* @exception	E_SUCCESS       The method is successful.
	* @exception	E_INVALID_ARG   The specified file cannot be found or accessed.
	* @exception	E_SYSTEM        The method has failed.
	* @remarks		If the hotspot is set again by SetHighlightedImage(), the value of the hotspot is overwritten.
	* @see			SetHighlightedImage()
	*/
	result SetImage(const Osp::Base::String& markerImagePath, const Osp::Graphics::Point& hotSpot);

	/**
	 * @page		MarkerSetImagePage Compatibility for SetImage( )
	 *
	 * @section		MarkerSetImagePageIssueSection Issues
	 * 				Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * 				-# The marker image set by this method is displayed at the wrong coordinates when the applications written for WVGA run on a WQVGA device.
	 *
	 * @section		MarkerSetImagePageResolutionSection Resolutions
	 * 				The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above.
	 */

	/**
	* Sets a bitmap image as a shadow of a marker.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref MarkerSetShadowImagePage "here".
	*
	* @return		An error code
	* @param[in]	pShadowImage	The bitmap image to be set as the shadow of the marker @n
 	*								If this parameter has @c null value, the default image will be used.
	* @param[in]	hotSpot			The pixel position of the image corresponding to the coordinates of marker  @n
	*								If @c pShadowImage has @c null value, this input parameter is ignored and the
	*								default value is used.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result SetShadowImage(const Osp::Graphics::Bitmap* pShadowImage, const Osp::Graphics::Point& hotSpot);
	
	/**
	* Sets the image at the specified image path as a shadow of a marker.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	shadowImagePath	The local file path of the image file to be set as the shadow of the marker @n
	*								If this parameter is an empty string value, the default image is used.
	* @param[in]	hotSpot			The pixel position of the image corresponding to the coordinates of marker @n
	*								If @c shadowImagePath has an empty string value, this input parameter is ignored
	*								and the default value is used.
	* @exception	E_SUCCESS       The method is successful.
	* @exception	E_INVALID_ARG   The specified file cannot be found or accessed.
	* @exception	E_SYSTEM        The method has failed.
	*/
	 result SetShadowImage(const Osp::Base::String& shadowImagePath, const Osp::Graphics::Point& hotSpot);

	/**
	* @page			MarkerSetShadowImagePage Compatibility for SetShadowImage( )
	*
	* @section		MarkerSetShadowImagePageIssueSection Issues
	* 				Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 				-# The shadow image of a marker set by this method is displayed at the wrong coordinates, when the applications written for WVGA run on a WQVGA device.
	*
	* @section		MarkerSetShadowImagePageResolutionSection Resolutions
	* 				The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above. @n
	*/

	/**
	* Sets the specified bitmap image as a highlighted marker.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref MarkerSetHighlightedImagePage "here".
	*
	* @return		An error code
	* @param[in]	pHighlightedImage	The bitmap image of the highlighted marker @n
	*									If this parameter has @c null value, the default image is used.
	* @param[in]	hotSpot				The pixel position of the image corresponding to the coordinates of marker @n
	*									If @c pHighlightedImage has @c null value, this input parameter is ignored
	*									and the default value is used.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method has failed.
	* @remarks		This method works in pair with SetImage(), if SetHighlighted() is set to @c true. @n
	*				The highlighted marker image will be visible only when SetImage() is called. @n
	*				The size and hotspot of the highlighted marker should be equal to that of the marker set by
	*				SetImage(), because the bounds of the highlighted image is decided by the bounds of the marker set by SetImage().
	* @see			SetImage(), SetHighlighted()
	*/
	result SetHighlightedImage(const Osp::Graphics::Bitmap* pHighlightedImage, const Osp::Graphics::Point& hotSpot);

	/**
	* Sets the image at the specified image path as a highlighted marker.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @retur		An error code
	* @param[in]	highlightedImagePath	The local file path of the image file to set as a highlighted marker @n
	*										If this parameter is an empty string value, the default image is used.
	* @param[in]	hotSpot					The pixel position of the image corresponding to the coordinates of the marker @n
	*										If @c highlightedImagePath has an empty string value, this input parameter is
	*										ignored and the default value is used.
	* @exception 	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG			The specified file cannot be found or accessed.
	* @exception	E_SYSTEM				The method has failed.
	* @remarks		If SetHighlighted() is set to @true, this API works in pair with SetImage(). @n
	*				The highlighted marker image will be visible only when SetImage() is called. @n
	*				The size and hotspot of the highlighted marker should be equal to that of the marker set by
	*				SetImage(), because the bounds of the highlighted image is decided by the bounds of the marker bounds set by SetImage().
	* @see			SetImage(), SetHighlighted()
	*/
	result SetHighlightedImage(const Osp::Base::String& highlightedImagePath, const Osp::Graphics::Point& hotSpot);


	/**
	* @page			MarkerSetHighlightedImagePage Compatibility for SetHighlightedImage( )
	*
	* @section		MarkerSetHighlightedImagePageIssueSection Issues
	* 				Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*				-# The highlighted image of a marker set by this method is displayed at the wrong coordinates
	*				when applications written for WVGA run on a WQVGA device.
	*
	* @section		MarkerSetHighlightedImagePageResolutionSection Resolutions
	* 				The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above.
	*/

	/**
	* Gets the rectangular bounds of the marker containing a transparent background.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The rectangular bounds of the marker
	*/
	virtual const Osp::Locations::RectangleGeographicArea* GetBounds(void) const;

	/**
	* Sets the position of the marker.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	coordinates		The coordinates of the marker to be drawn
	*/
	void  SetCoordinates(const Osp::Locations::Coordinates &coordinates);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of MapOverlayMarker to destination
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dest			The destination to be copied.
	* @exception	E_SUCCESS   	The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result CopyData(__IMapOverlayMarker& dest) const;

protected:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* This is not supported.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual result Dispose(void);

private:

	/*
	* Bitmap instance of marker.
	*/
	Osp::Graphics::Bitmap*		__pMarkerImage;

	/*
	* Bitmap instance of marker's shadow.
	*/
	Osp::Graphics::Bitmap*		__pShadowImage;

	/*
	* Bitmap instance of highlighted marker.
	*/
	Osp::Graphics::Bitmap*		__pHilightedImage;

	/*
	* Position of hotspot.
	*/
	Osp::Graphics::Point		__MarkerHotSpot;

	/*
	* Position of hotspot's shadow.
	*/
	Osp::Graphics::Point		__ShadowHotspot;

	/*
	* Dragging ability of a marker.
	*/
	bool						__bMarkerDraggable;

	/*
	* Opacity of a marker.
	*/
	int							__opacity;

	/*
	* Canvas instance.
	*/
	Osp::Graphics::Canvas*		__pCanvas;

	/*
	* Coordinate of a marker.
	*/
	Osp::Locations::Coordinates				__coordinates;

	/*
	* Geographic area of a marker.
	*/
	Osp::Locations::RectangleGeographicArea	__Markderbound;

	/*
	* Geographic area of a marker's shadow.
	*/
	Osp::Locations::RectangleGeographicArea	__Shadowbound;

	/*
	* Flag used to indicate the usage of default image.
	*/
	bool	__bUsedDefault;
	bool	__bUsedDefaultShadow;

	friend class __MapOverlayControlManager;

private:

	friend class MapOverlayMarkerEx;
	class MapOverlayMarkerEx* __pMapOverlayMarkerEx;

};	// MapOverlayMarker

};};};	// Osp::Locations::Controls;

#endif	//_FLOC_CTRL_MAP_OVERLAY_MARKER_H


