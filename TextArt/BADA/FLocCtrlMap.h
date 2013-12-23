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
* @file		FLocCtrlMap.h
* @brief	This is the header file for the %Map class.
*
* This header file contains the declarations of the %Map class.
*/

#ifndef _FLOC_CTRL_MAP_H_
#define _FLOC_CTRL_MAP_H_

#include <FLocationControlConfig.h>
#include <FUiControl.h>
#include <FLocCoordinates.h>
#include <FLocRectangleGeographicArea.h>

namespace Osp { namespace Locations { namespace Services { class IMapServiceProvider; }; }; };
namespace Osp { namespace Locations { namespace Services { class IMaps; }; }; };
namespace Osp { namespace Locations { namespace Services { class MapServicePreferences; }; }; };
namespace Osp { namespace Locations { class LocationProvider; }; };

namespace Osp { namespace Locations { namespace Controls {

class IMapEventListener;
class IMapOverlayEventListener;
class IMapInfoWindowEventListener;
class IMapOverlay;
class IMapInfoWindow;
class IMapControlSpi;

/**
* @class	Map
* @brief	This class displays a dynamic map.
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %Map class displays a dynamic map. An instance of this class helps in customizing maps to provide additional information and
* map interactivity. After getting a %Map instance, an application can modify the viewport of a map. It can pan, zoom, or move
* the viewport as needed. After performing any of these operations, the results are made visible by calling the Draw() method.
*
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/map_controls.htm">Map Controls</a>.
*/
class _EXPORT_LOCATION_CONTROL Map :
	public Osp::Ui::Control
{
	DECL_CLASSTYPE(Map);
	
public:

	/**
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	Map(void);

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~Map(void);

	/**
	* Draws the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SYSTEM			The method has failed.
	* @exception	E_INVALID_STATE		This instance of canvas has not been constructed as yet.
	*/
	virtual result Draw(void);

protected:

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Frees the resources allocated by this control and destroys its native window.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result Dispose(void);
	
	/** 
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* This method is called by the framework to perform user-specific initialization codes.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_FAILURE	The method has failed.
	* @remarks		OnInitializing() is called when the control is successfully added to a container.
	*/
	result OnInitializing(void);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Override this method to provide user-specific termination code.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_FAILURE	The method has failed.
	* @remarks		OnTerminating() is called right before the control is successfully removed from the container.
	* @see			OnInitializing()
 	*/
 	result OnTerminating(void);

public:
	
	/**
	* Initializes this instance of %Map with the specified parameters.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompControlConstruct20 "here".
	*
	* @return		An error code
	* @param[in]	rect				The rectangle of this control
	* @param[in]	mapServiceProvider	The MapServiceProvider instance from a map service provider
	* @exception	E_SUCCESS 			The method is successful.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			The method has failed.
	* @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	*/
	result Construct(const Osp::Graphics::Rectangle& rect, Osp::Locations::Services::IMapServiceProvider& mapServiceProvider);

	/**
	* Initializes this instance of %Map with the specified parameters.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	rect				The rectangle of this control
	* @param[in]	mapServiceProvider	The %MapServiceProvider instance from a map service provider
	* @param[in]	enableRotation		Set to @c true to enable the rotation functionality of the map, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			The method has failed.
	* @remarks		Memory usage is increased if @c enableRotation is set to @c true.
	* @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	*/
	result Construct(const Osp::Graphics::Rectangle& rect, Osp::Locations::Services::IMapServiceProvider& mapServiceProvider, bool enableRotation);

	/**
	* Sets the center of the map according to the specified coordinates.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
	*					For more information, see issues in version @ref MapSetCenter1_v12Page "1.2" and @ref MapSetCenter1_v20Page "2.0" .
	*
	* @return			An error code
	* @param[in]		centerCoordinates	The new center coordinates of the map
	* @param[in]		effectEnabled		Set to @c true to enable the animation effect, @n
	*                             			else @c false
	* @exception		E_SUCCESS 			The method is successful.
	* @exception		E_INVALID_ARG 		The specified center contains invalid coordinates, or @n
	*										the specified center is not within the area supported by the map service provider. @n
	*										Some service providers might not support all valid coordinates, such as (-90,90) and (-180,180).
	*/
	result SetCenter(const Osp::Locations::Coordinates& centerCoordinates, bool effectEnabled);

	/**
	 * @page		MapSetCenter1_v12Page 	Compatibility for SetCenter()
	 *
	 * @section		MapSetCenter1_v12PageIssueSection 	Issues
	 * 				Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * 				-# If the animation effect is set to @c true, the center of the map is set incorrectly.
	 *
	 * @section		MapSetCenter1_v12PageResolutionSection 	Resolutions
	 * 				The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	 *
	 * @par			
	 * When working with bada API versions prior to 1.2: @n
	 * Call the SetCenter() method once more without using the animation effect.
	 */

	/**
	* @page			MapSetCenter1_v20Page Compatibility for SetCenter()
	*
	* @section		MapSetCenter1_v20PageIssueSection	Issues
	*				Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*				-# E_SUCCESS is returned even if the specified center is not within the area supported by the map service provider.
	*
	* @section		MapSetCenter1_v20PageResolutionSection Resolutions
	* 				-# E_INVALID_ARG is returned if the specified center is not within the area supported by the map service provider.
	*/

	/**
	* Sets the center of the map according to the specified coordinates.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
	*					For more information, see issues in version @ref MapSetCenter2_v12Page "1.2"  and @ref MapSetCenter2_v20Page "2.0".
	*
	* @return		An error code
	* @param[in]	latitude		The latitude of the new center point of the map
	* @param[in]	longitude		The longitude of the new center point of the map
	* @param[in]	effectEnabled	Set to @c true to enable the animation effect, @n
	*								else @c false
	* @exception	E_SUCCESS 	  	The method is successful.
	* @exception	E_INVALID_ARG	The specified center contains invalid coordinates, or @n
	*								the specified center is not within the area supported by the map service provider. @n
	*								Some service providers might not support all valid coordinates, such as (-90,90) and (-180,180).
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	*/
	result SetCenter(double latitude, double longitude, bool effectEnabled);

	/**
	* @page			MapSetCenter2_v12Page Compatibility for SetCenter()
	*
	* @section		MapSetCenter2_v12PageIssueSection Issues
	*				Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*				-# If the animation effect is set to @c true, the center of the map is set incorrectly.
	*
	* @section		MapSetCenter2_v12PageResolutionSection Resolutions
	* 				The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*
	* @par			
	* When working with bada API versions prior to 1.2: @n
	*				Call the SetCenter() method once more without using the animation effect.
	*/
	
	/**
	* @page			MapSetCenter2_v20Page Compatibility for SetCenter()
	*
	* @section		MapSetCenter1_V20PageIssueSection Issues
	*				Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 				-# E_SYSTEM is returned even if the specified center coordinates are not valid.
	*
	* @section		MapSetCenter1_V20PageResolutionSection Resolutions
	* 				-# E_INVALID_ARG is returned if the specified center coordinates are not valid.
	* 				-# E_OUT_OF_MEMORY is returned if system is not able to allocate memory for converting @c latitude and @c longitude to coordinates.
	*/
	
	/**
	* Gets the center coordinates of the map.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The center point coordinates of the area
	* @remarks	If the latitude or longitude of the center point of a map is not within the range of the map, this method
	*			returns the nearest boundary value as the center. @n
	* 			The values returned by this method may be slightly different from the value set by @ref SetCenter().
	*
	*/	 
	Osp::Locations::Coordinates GetCenterCoordinates(void) const;

	/**
	* Sets the bounds (viewport) of the map. @n
	* This method sets the viewport in the direction to true north. If an application needs a rotated viewport, it must call the Rotate() method, after 
	* executing this method. Setting the viewport may fail if the viewport is outside the supported area.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	area			The new viewport of the map
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result SetViewport(const Osp::Locations::RectangleGeographicArea& area);

	/**
	* Gets a RectangleGeographicArea instance that defines the current viewport of the map. @n
	* If the map is rotated, this method returns the minimum %RectangleGeographicArea that contains the rotated viewport area. In this case,
	* the returned area may be greater than the rotated viewport.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The viewport of the map as a rectangular geographic area
	*/
	Osp::Locations::RectangleGeographicArea GetViewport(void) const;

	/**
	* Sets the size of the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	width			The width of the area where the map is rendered in pixels
	* @param[in]	height			The height of the area where the map is rendered in pixels
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c width or @c height is less than or equal to @c 0.
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result SetSize(int width, int height);

	/**
	* Sets the size of the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	dim 			The area where the map is rendered, in pixels
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c dim.width or @c dim.height is less than or equal to @c 0.
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result SetSize( const Osp::Graphics::Dimension &  dim);

	/**
	* Sets the position and size of the map. @n
	* The width is set to the value specified in @c width, and the height is set to the value specified in @c height from the position (x,y).
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompMapSetBounds "here".
	*
	* @return			An error code
	* @param[in]		x					The X position of the map where the map is rendered in pixels
	* @param[in]		y					The Y position of the map where the map is rendered in pixels
	* @param[in]		width				The width of the area where the map is rendered in pixels
	* @param[in]		height				The height of the area where the map is rendered in pixels
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG		A specified input parameter is invalid, or the specified @c width or @c height is less than or equal to @c 0.
	* @exception		E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception		E_SYSTEM			The method has failed.
	* @see				SetSize()
	* @see				@ref Osp::Ui::Control::SetBounds()
	* @see				@ref Osp::Ui::Control::SetPosition()
	*/
	result SetBounds ( int x, int y, int width, int height );

	/**
	* Sets the position and size of a map. @n
	* The position is set to (rect.x, rect.y), the width becomes the value specified in @c rect.width,
	* and the height becomes the value specified in @c rect.height.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref CompMapSetBounds "here".
	*
	* @return			An error code
	* @param[in]		rect			The bounds where the map is rendered in pixels
	* @exception		E_SUCCESS		The method is successful.
	* @exception		E_INVALID_ARG	The specified input parameter is invalid, or either @c rect.width or @c rect.height is @c 0 or has a negative value.
	* @exception		E_SYSTEM		The method has failed.
	* @see				SetSize()
	* @see				@ref Osp::Ui::Control::SetBounds()
	* @see				@ref Osp::Ui::Control::SetPosition()
	*/
	result SetBounds(const Osp::Graphics::Rectangle& rect);

	/**
	* @page		CompMapSetBounds Compatibility for SetBounds()
	*
	* @section		CompMapSetBoundsIssues Issues
	*				Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*				-# If an application calls the @ref SetBounds() method of a Map instance, @ref Osp::Ui::Control::SetBounds() is called. 
	*				In this case, the map related methods (for example, SetCenter(), TransformPixelsToCoordinates()) do not work
	*				as expected, even if the position and size of a map are changed.
	*
	* @section		CompMapSetBoundsResolutions Resolutions
	*				The issue mentioned above is resolved in bada API version 2.0 by overriding the SetBounds() method present in
	*				the Locations::Controls::Map class, and it is recommended to use bada API version 2.0 or above. @n
	*
	* @par
	* When working with bada API versions prior to 2.0: @n
	* Call @ref Osp::Ui::Control::SetPosition() and @ref SetSize() methods instead of calling @ref SetBounds().
	*/

	/**
	* Sets the zoom level. @n
	* The value must be within the range of [1.0, maximum zoom level]. The maximum zoom level can 
	* be retrieved with the @ref GetMaxZoomLevel() method. If the new zoom level is less than
	* the current zoom level, the map is zoomed out. If the new zoom level is greater than 
	* the current zoom level, the map is zoomed in. @n
	* The support for continuous zoom can be checked with the Osp::Locations::Services::ProviderCapabilities::GetPropertyValue() method using 
	* @ref Osp::Locations::Services::ProviderCapabilities::MAP_SUPPORTS_CONTINUOUS_ZOOM as the property key. This key 
	* is supported from bada API version 2.0.
	* In case continuous zoom is not supported, only integer values are available for the 
	* zoom level and if the zoom level is not an integer value, the nearest integer value is set 
	* instead of the specified zoom level.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                  For more information, see issues in version @ref CompMapSetZoomLevelPage "1.1" and @ref CompMapSetZoomLevel2Page "2.0".
 	*
	* @return			An error code
	* @param[in]		level			The new zoom level for a map @n
	*									This parameter can be set to @c float type. 
	*									If discrete value (for example, level 3, 4) needs to be set for the zoom level, it can be set as @c 3.0, @c 4.0.
	* @param[in]		effectEnabled	Set to @c true to enable the animation effect, @n
	*									else @c false
	* @exception		E_SUCCESS		The method is successful, or SetZoomEnabled() has set the zoom status to @c false.
	* @exception		E_INVALID_ARG	The specified @c level is out of range. @n
	*									The valid range is [1.0, number of zoom levels]. 
	* @remarks		The map images from the map are always displayed as non-scaled bitmap images.
	* 				This means that the applications can display a different region of the map on a different screen 
	* 				resolution even when using the same zoom level. 
	*  				To guarantee that a map shows a certain region regardless of the resolution, use 
	*  				the SetViewport() method instead of the SetZoomLevel() method.
	*/
	result SetZoomLevel(float level, bool effectEnabled);

	/**
	* @page			CompMapSetZoomLevelPage		Compatibility for SetZoomLevel()
	*
	* @section		CompMapSetZoomLevelPageIssueSection		Issues
	* 				Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	* 				-# Returns E_SUCCESS, even if the input value is out of range when the value of @c effectEnabled is set to @c true.
	*
	* @section		CompMapSetZoomLevelPageResolutionsSection Resolutions 
	* 				The issue mentioned above is resolved in bada API version 1.1 and 2.0 as follows. @n
	* 				-# Returns E_INVALID_ARG in bada API versions 1.1 or above, if the input value is out of range when the value of
	*				@c effectEnabled is set to @c true.
	*/

	/**
	* @page        CompMapSetZoomLevel2Page Compatibility for SetZoomLevel()
	*
	* @section     CompMapSetZoomLevel2PageIssueSection Issues
	* 				Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	* 				-# Applications cannot set the zoom level by calling this method, if the SetZoomEnabled() method is set to @c false.
	*              -# This method works improperly if animation effect is set to @true and the difference between the current zoom level and the new zoom level is greater than @c 1.0.
	*
	* @section     CompMapSetZoomLevel2PageResolutionsSection Resolutions
	* 				The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*/
	
	/**
	* Gets the zoom level. @n
	* The returned value is within the range [1.0, maximum zoom level].
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The current zoom level of the map
	* @remarks		The maximum zoom level is retrieved by the @ref GetMaxZoomLevel() method.
	*/
	float GetZoomLevel(void) const;

	/**
	* Gets the maximum zoom level supported by the map. @n
	* The minimum zoom level of the map instances is always @c 1.0.
	* The zoom level supported by the map instance ranges from @c 1.0 to the number returned from this method.
	* If, for example, the method returns @c 4.0, the supported zoom levels are [1.0, 4.0].
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The @c float value that indicates the maximum zoom level
	*/
	float GetMaxZoomLevel(void) const;

	/**
	* Gets the current azimuth of the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		A floating value indicating the azimuth of the map, @n
	*				else @c 0 if the value has not been set before
	* @remarks		This value is set by the @ref Rotate() method.
	*/
	float GetAzimuth(void) const;

	/**
	* Rotates the map according to the specified azimuth value. @n
	* An azimuth is specified as the degrees from the true north. The support for rotation can be
	* checked with the Osp::Locations::Services::ProviderCapabilities::GetPropertyValue() method using @ref 
	* Osp::Locations::Services::ProviderCapabilities::MAP_SUPPORTS_MAP_ROTATION as the property
	* key. If the service provider that constructed this object does not support the rotation and
	* the azimuth value is not 0.0, this method returns @c Not-a-Number (NaN).
	* If rotation is supported, but the map cannot be rotated to the specified azimuth,
	* the map is rotated to the closest possible azimuth. If the requested azimuth is in the middle 
	* of two supported azimuths, the map is rotated to the smaller supported azimuth. The realized
	* rotation azimuth is returned. If the rotation fails, @c Not-a-Number (NaN) is returned. @n
	*
	* When the map is rotated, the geographical area displayed on the map changes. The center point of
	* the geographical area remains the same. The new viewport is the area around the center point that fits into the current graphics context. The
	* zoom level must not be changed. The geographical area can be retrieved with the @ref GetViewport() method.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The azimuth value to which the map is rotated, @n
	*				else @c Not-a-Number (NaN) if the rotation fails
	* @param[in]	azimuth			The rotation angle from true north in the clockwise direction
	* @param[in]	effectEnabled	Set to @c true to enable the animation effect, @n
	*								else @c false
	* @remarks		This method fails if the specified @c azimuth is less than @c 0.0 or greater than or equal to @c 360.0. @n
	*				It can also fail if the map service provider does not support the rotation when the azimuth is other than @c 0.0.	
	*/
	float Rotate(float azimuth, bool effectEnabled);

	/**
	* Pans the map to the specified direction. @n
	* If an effect is used, this method returns after the effect has ended. @n
	* The map can be panned upwards, downwards, left, or right. The upward movement and the movement to the left are
	* indicated by negative values for the number of pixels. The downward movement and the movement to the right are indicated
	* by positive values for the number of pixels. @n
	* This method returns the number of pixels that are panned.
	* 
	* The value of @c wholeAmount helps an application to decide whether the panning is completely or partially allowed. 
	* If this parameter is @c true and the requested amount of pixels cannot be panned, the method
	* returns without any action and the returned point contains two @c 0 values.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		A value of type Point, where Point.x contains the number of pixels moved in the horizontal
	*				direction and Point.y contains the number of pixels moved in the vertical direction
	* @param[in]	point			The number of pixels to be panned in each direction
	* @param[in]	wholeAmount		Set to @c true if panning is done only if the requested amount of pixels can be panned, @n
	*								else @c false if partial panning is accepted by the application
	* @param[in]	effectEnabled	Set to @c true to enable the animation effect, @n
	*								else @c false
	*/
	Osp::Graphics::Point Pan(const Osp::Graphics::Point& point, bool wholeAmount, bool effectEnabled);

	/**
	* Adds map layers to the map. @n
	* These layers include streets, highways, public transportation lines, water areas, parks, buildings, sidewalks, or administrative areas. @n
	* The names of the map layers that are supported by the map service provider can be retrieved with the 
	* @ref Osp::Locations::Services::ProviderCapabilities::GetPropertyValue() method 
	* using the @ref Osp::Locations::Services::ProviderCapabilities::MAP_SUPPORTED_LAYERS property key.
	* An application does not consider whether the layers are set in the right order. The service provider defines the
	* order in which the layers are to be placed on top of the map base when the map is being rendered.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	name			The name of the layer to be added
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c name of layer is not supported by the service provider, or
	*								contains elements that are not String objects.
	* @exception	E_SYSTEM		The method has failed.
	* @see			RemoveLayer()
	*/
	result  AddLayer(const Osp::Base::String& name);

	/**
	* Removes the map layers from the map. @n
	* These layers include streets, highways, public transportation
	* lines, water areas, parks, buildings, sidewalks, or administrative areas.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	name			The name of the layer to be removed
	* @exception	E_SUCCESS 		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c name of layer is invalid.
	* @exception	E_SYSTEM		The method has failed.
	* @see			AddLayer()
	*/
	result RemoveLayer(const Osp::Base::String& name);

	/**
	* Sets the preferences for the map base in the map contribute. @n
	* The base of a map can include a regular map,
	* a satellite image, an aerial image, a terrain map, or latitude and longitude grid only. The
	* map bases supported by the map service provider can be retrieved with the @ref Osp::Locations::Services::ProviderCapabilities::GetPropertyValue() method
	* using the @ref Osp::Locations::Services::ProviderCapabilities::MAP_SUPPORTED_MAP_BASES property key.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	mapMode			The map base preference to be set
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	*/
	result SetMapMode(const Osp::Base::String& mapMode);

	/**
	* Gets the preference for the map base to be used in the service request. @n
	* The base of a map can include a regular map, a satellite
	* image, an aerial image, a terrain map, or latitude and longitude grid only. The map bases supported by the map
	* service provider can be retrieved with the @ref Osp::Locations::Services::ProviderCapabilities::GetPropertyValue() method using the 
	* @ref Osp::Locations::Services::ProviderCapabilities::MAP_SUPPORTED_MAP_BASES property key. The method returns the default value set by
	* the service provider or a value set with the @ref SetMapMode() method.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The map base preference for service requests
	*/
	Osp::Base::String GetMapMode(void) const;

	/**
	* Sets the status of panning.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable		Set to @c true to enable panning, @n
	*							else @c false
	* @remarks		If the status of panning is set to @c false, panning is not possible by user interaction. @n
	*				The Pan() method works normally even if the status of panning is set to @c false.
	*/
	void SetPanEnabled(bool enable);

	/**
	* Gets the status of panning.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if panning is enabled, @n
	*				else @c false
	*/
	bool IsPanEnabled(void) const;

	/**
	* Sets the status of zooming.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable		Set to @c true to enable zooming, @n
	*							else @c false
	* @remarks		If the status of zooming is set to @c false, zooming is not possible either by user
	*				interaction or method call.
	*/
	void SetZoomEnabled(bool enable);

	/**
	* Gets the status of zooming.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if zooming is enabled, @n
	*				else @c false
	*/
	bool IsZoomEnabled(void) const;

	/**
	* Adds the IMapEventListener instance to the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be added
	*/
	void AddMapEventListener(const IMapEventListener& listener);

	/**
	* Removes the IMapEventListener instance of the map. @n
	* If the specified listener is not registered, this method does not perform any operation.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be removed
	*/
	void RemoveMapEventListener(const IMapEventListener& listener);

	/**
	* Adds the IMapOverlayEventListener instance to a map overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be added
	*/
	void AddMapOverlayEventListener(const IMapOverlayEventListener& listener);

	/**
	* Removes the IMapOverlayEventListener instance of a map overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be removed
	*/
	void RemoveMapOverlayEventListener(const IMapOverlayEventListener& listener);

	/**
	* Adds the IMapInfoWindowEventListener instance to a map InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be added
	*/
	void AddMapInfoWindowEventListener(const IMapInfoWindowEventListener& listener);

	/**
	* Removes the IMapInfoWindowEventListener instance of a map InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	listener	The event listener to be removed
	*/
	void RemoveMapInfoWindowEventListener(const IMapInfoWindowEventListener& listener);

	/**
	* Converts the coordinates in the WGS 84 projection system to the point of area, where a map is rendered. @n
	* The returned Point.x contains the point on the x-axis and Point.y is the point on 
	* the y-axis of the rendering area.
	* The origin point is the top left corner of the current viewport. The values on the 
	* x-axis grow towards the right and those on the y-axis,
	* grow downwards. If the specified coordinates are not within the viewport, 
	* the rendering area coordinates are returned in relation to the origin point.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the method is successful, @n
	*				else @c false
	* @param[in]	coordinates		The coordinates to be converted
	* @param[out]	convertedPoint	The converted point
	*/
	bool TransformCoordinatesToPixels(const Coordinates &  coordinates, Osp::Graphics::Point &  convertedPoint) const;

	/**
	* Converts the point on the area, where a map is rendered into WGS 84 coordinates. @n
	* The x and y coordinates are presented in the coordinates system of the rendering area. 
	* The origin point is the top-left corner of the area. The values on the x-axis grow towards 
	* the right and those on the y-axis, grow downwards. 
	* The pixels outside the current rendered area can be specified.
	* The returned @ref Coordinates object does not include any information about the altitude. 
	* This value is set to @c Not-a-Number (NaN) in the object.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the method is successful, @n
	*				else @c false
	* @param[in]	point					The position of the point to be converted
	* @param[out]	convertedCoordinates	The converted coordinates
	*/
	bool TransformPixelsToCoordinates(const Osp::Graphics::Point &  point, Coordinates &  convertedCoordinates) const;

	/**
	* Adds the IMapOverlay instance to a map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	overlay				The %IMapOverlay instance to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		This method performs a shallow copy. It adds just the pointer, not the element itself. @n
	*				If the same overlay is added to many different maps, the overlay may not work as
	*				expected.
	* @see			RemoveMapOverlay()
	*/
	result AddMapOverlay(const Osp::Locations::Controls::IMapOverlay& overlay);

	/**
	* Removes the %IMapOverlay instance of a map.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	overlay			The IMapOverlay instance to be removed
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The map does not contain this overlay.
	* @exception	E_FAILURE		The method has failed.
	* @see			AddMapOverlay()
	*/
	result RemoveMapOverlay(const Osp::Locations::Controls::IMapOverlay& overlay);

	/**
	* Sets the activity status of all the overlay instances.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable	Set to @c true to set the activity status of the overlay as @c "show", @n
	*						else @c false
	*/
	void SetShowOverlayEnabled (bool enable);

	/**
	* Gets the activity status of all the overlay instances.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the state of the overlay is "show" (all overlays may be visible), @n
	*				else @c false
	*/
	bool IsShowOverlayEnabled (void) const;

	/**
	* Sets the maximum count of the drawable overlay instances at once.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	count		The new maximum count of the drawable overlay instances
	*/
	void SetOverlayDisplayMaxCount(int count);

	/**
	* Gets the maximum count of the drawable overlay instances at once.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The maximum count of the drawable overlay instances at once
	*/
	int GetOverlayDisplayMaxCount (void) const;

	/**
	* Gets a list of overlays.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The list of overlays
	*/
	const Osp::Base::Collection::LinkedListT<IMapOverlay*>* GetOverlayList(void) const;

	/**
	* Sets the activity status of the location information to be updated. @n
	* To stop the location information updates, set the value of @c enable to @c false.
	* It is recommended that the location information updates be stopped in order to conserve power. 
	* For example, Osp::App::Application::OnBackground() is called, when an application moves to the background.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                For more information, @ref SetMyLocationEnabledPage "here".
	*
	* @privlevel   NORMAL
	* @privgroup   LOCATION
	*
	* @param[in]	enable				The new activity status of the location information to be updated
	* @exception   E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This instance is in an invalid state.
	* @exception   E_LOCATION			The %Location information updates are currently out of service, or the platform does not have the resources to update 
	*									the location information.
	* @exception   E_OUT_OF_MEMORY     The memory is insufficient.
	* @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method, or the user has blocked the application from using 
	*									the location information.
	* @exception   E_SYSTEM            A system error has occurred.
	*              
	* @remarks     The specific error code can be accessed using the GetLastResult() method.
	* @see			GetMyLocationEnabled()
	*/

	void SetMyLocationEnabled(bool enable);

	/**
	* @page         SetMyLocationEnabledPage Compatibility for SetMyLocationEnabled()
	*
	* @section      SetMyLocationEnabledPageIssueSection Issues
	*               Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	* 				-# This method does not have the privilege level and group in bada API versions prior to 2.0. @n@n
	* 				-# This method does not have any exceptions in bada API versions prior to 2.0.
	* 				For bada API version prior to 2.0, the result can be checked by invoking the GetMyLocationEnabled() method, after SetMyLocationEnabled() is called. @n
	* 				If GetMyLocationEnabled() returns @c false, the location services may be disabled.
	*
	* @section      SetMyLocationEnabledPageResolutionsSection Resolutions
	*               The issues mentioned above are resolved in bada API version 2.0 as follows: @n
	*
	*               -# The privilege level and group in bada API version 2.0 or above are mentioned below: @n
	*               @b Privilege @b level: @b NORMAL @n
	* 				@b Privilege @b group: @b LOCATION @n
	*
	*               -# For bada API version 2.0 or above, the method may throw E_SUCCESS, E_INVALID_STATE, E_LOCATION, E_OUT_OF_MEMORY, E_PRIVILEGE_DENIED, or E_SYSTEM exceptions.
	*               The specific error code can be accessed using the GetLastResult() method.
	*/


	/**
	* Gets the activity status of the location information to be updated.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The activity status of the location information to be updated
	* @see		SetMyLocationEnabled()
	*/
	bool GetMyLocationEnabled(void) const;

	/**
	* Sets the InfoWindow to a map and opens the InfoWindow.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	infoWindow		The IMapInfoWindow instance
	* @param[in]	effectEnabled	Set to @c true to enable the animation effect, @n
	*								else @c false @n
	*								The auto panning effect is applied only once when InfoWindow is first drawn on the canvas.
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	* @remarks		This method opens only one InfoWindow.
	*				If another InfoWindow is already open, it must be closed, and a new InfoWindow opened.
	* @see			CloseInfoWindow()
	*/
	result OpenInfoWindow(const Osp::Locations::Controls::IMapInfoWindow &infoWindow, bool effectEnabled);

	/**
	* Closes the InfoWindow.
	* 
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	infoWindow		The InfoWindow to be closed
	* @see			OpenInfoWindow()
	*/
	void CloseInfoWindow(const Osp::Locations::Controls::IMapInfoWindow &infoWindow);

	/**
	* Sets the property value of the map service preferences for the specified key. @n
	* Passing @c null as the property value resets the property to the default value.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	key 		The key identifier of the property
	* @param[in]	pValue		The value of the property @n
	* 							The parameter is set to @c null to reset the property value. 
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c key is not supported.
	* @see			@ref Osp::Locations::Services::ServicePreferences::SetPropertyValue()
	*/
	result SetPreferencePropertyValue(const Osp::Base::String &key, const Osp::Base::String *pValue);

	/**
	* Gets the value of the requested additional property as a string.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The value of the property, @n
	*				else @c null if the key is not defined
	* @param[in]	key 	The identifier of the property
	* @see			@ref Osp::Locations::Services::ServicePreferences::GetPropertyValue()
	*/
	const Osp::Base::String * GetPreferencePropertyValue (const Osp::Base::String &key) const;

	/**
	* Moves the center of a map to the current location.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.1
	*
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	* @exception	E_SYSTEM		The current location information is temporarily unavailable or has failed to
	*								set the center coordinates according to the current location of the user.
	* @remarks		This method works as expected only if GetMyLocationEnabled() returns @c true. @n
	*				It takes up to three seconds to retrieve the location information after this method is called. @n
	*				If E_SYSTEM is returned, the center of the map can be moved to the current location by
	*         		explicitly calling this method.
	* @see			SetMyLocationEnabled(), GetMyLocationEnabled()
	*/
	result MoveToMyLocation(void);

	/**
	* Sets the offset margin for the pre-fetched map. @n
	* If offset margin is set to @c width and @c height, the actual size of canvas for the pre-fetched map is 
	* [@c 2 (left and right) x @c width  + @c control.width] by [@c 2 (top and bottom) x @c height  + @c control.height].
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code 
	* @param[in]	width				The @c width of the pre-fetched margin in pixels
	* @param[in]	height				The @c height of the pre-fetched margin in pixels
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The @c width or @c height is less than or equal to @c 0.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			The method has failed.
	* @remarks		The pre-fetched margin may not be set as requested.
	*				It is recommended to check the result by using the @ref GetPrefetchMargin() method, after @ref SetPrefetchMargin() is called.
	* @see			GetPrefetchMargin(), TransformCoordinatesToPixelsOnCanvas(), TransformPixelsOnCanvasToCoordinates()
	*/
	result SetPrefetchMargin (int width, int height);

	/**
	* Gets the offset margin for the pre-fetched map.
	*
	 * @deprecated	This method is deprecated.
	* @since        2.0
	* @param[out]   width		The width of the pre-fetched offset margin
	* @param[out]   height		The height of the pre-fetched offset margin
	* @see          SetPrefetchMargin(), TransformCoordinatesToPixelsOnCanvas(), TransformPixelsOnCanvasToCoordinates()
	*/
	void GetPrefetchMargin (int &width, int &height) const;

	/**
	* Sets the offset margin for the pre-fetched map tiles. @n
	* If the offset margin is set to @c dim, the actual size of the canvas for the pre-fetched map is 
	* [@c 2 (left and right) x @c dim.width  + @c control.width] by [@c 2 (top and bottom) x @c dim.height  + @c control.height].
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		An error code
	* @param[in]	dim					The dimension of the pre-fetched margin in pixels
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The @c dim.width or @c dim.height is less than or equal to @c 0.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			The method has failed.
	* @remarks		The pre-fetched margin may not be set as requested.
	*				It is recommended to check the result by using the @ref GetPrefetchMargin() method, after @ref SetPrefetchMargin() is called.
	* @see			GetPrefetchMargin(), TransformCoordinatesToPixelsOnCanvas(), TransformPixelsOnCanvasToCoordinates()
	*/
	result SetPrefetchMargin (Osp::Graphics::Dimension& dim);

	/**
	* Gets the offset margin for the pre-fetched map.
	*
	 * @deprecated	This method is deprecated.
	* @since	2.0
	* @return	The size of the pre-fetched offset margin
	* @see		SetPrefetchMargin(), TransformCoordinatesToPixelsOnCanvas(), TransformPixelsOnCanvasToCoordinates()
	*/
	Osp::Graphics::Dimension GetPrefetchMargin(void) const;

	/**
	* Converts the coordinates in the WGS 84 projection system into the point of the area, where the map is rendered.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		@c true if the method is successful, @n
	*				else @c false
	* @param[in]	canvas			The canvas for rendering the map
	* @param[in]	coordinates		The coordinates to be converted
	* @param[out]	convertedPoint	The converted point
	* @see			TransformPixelsOnCanvasToCoordinates()
	*/
	bool TransformCoordinatesToPixelsOnCanvas(const Osp::Graphics::Canvas & canvas, const Coordinates & coordinates, Osp::Graphics::Point & convertedPoint) const;

	/**
	* Converts a point on the area, where the map is rendered into WGS 84 coordinates.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		@c true if the method is successful @n
	*				else @c false
	* @param[in]	canvas					The canvas for rendering the map
	* @param[in]	point					The position of the point to be converted
	* @param[out]	convertedCoordinates	The converted coordinates
	* @see			TransformCoordinatesToPixelsOnCanvas()
	*/
	bool TransformPixelsOnCanvasToCoordinates(const Osp::Graphics::Canvas & canvas, const Osp::Graphics::Point & point, Coordinates & convertedCoordinates) const;

	/**
	* Get the width of the world map in pixels. @n
	* A provider may draw the map repeatedly along the x-axis at a low zoom level. @n
	* This method returns the width of the world map in the current zoom level.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The width of the world map in pixels, @n
	*				The width is greater than @c 0
	*/
	int GetGlobalMapWidthInPixels(void);
	
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Gets the service provider.
	*
	 * @deprecated	This method is deprecated.
	 * @since		2.0
	 * @return		An instance of the service provider
	 */
	IMapControlSpi* GetServiceProvider(void) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Gets the peer handle of the map.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @return		The handle of the map
	*/
	Handle	GetPeerHandlePublic(void) const;

private:
	
	/*
	* Draws the control.
	*
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_SYSTEM		The method has failed.
	* @exception	E_INVALID_STATE	This instance is in an invalid state.
	*/
	virtual result __Draw(void);

private:

	/*
	* The IMaps interface.
	*/
	Osp::Locations::Services::IMaps* __pMap;

	/*
	* Specifies the relative-position and size of this instance.
	*/
	Osp::Graphics::Rectangle __curRect;

	/*
	* The Overlay manager instance.
	*/
	void*	__pOverlayManager;

	/*
	* The position where the action starts.
	*/
	Osp::Graphics::Point	__startPosition;

	/*
	* The previous position.
	*/
	Osp::Graphics::Point	__prevPosition;

	/*
	* The current position.
	*/
	Osp::Graphics::Point	__currentPosition;

	/*
	* The coordinate where the action starts.
	*/
	Osp::Locations::Coordinates	__startCoord;

	/*
	* The previous coordinate.
	*/
	Osp::Locations::Coordinates	__prevCoord;

	/*
	* The current coordinate.
	*/
	Osp::Locations::Coordinates	__currentCoord;

	/*
	* Determines the status of panning as enable or disable.
	*/
	bool __enablePan;

	/*
	* Determines the status of zooming as enable or disable.
	*/
	bool __enableZoom;

	/*
	* Determines the activity status of location information update.
	*/
	bool __enableMyLocation;

	/*
	* Determines the touch flick flag enable or disable.
	*/
	bool __isFlicked;

	/*
	* The Zoom bar instance.
	*/
	void*	__pZoomControl;

	/*
	* The Bitmap instance.
	*/
	Osp::Graphics::Bitmap* __pBitmapSource;

	/*
	* The Map Event.
	*/
	class __MapEvent*	__pMapEvent;

	/*
	* The Map Overlay Event.
	*/
	Osp::Base::Runtime::IEvent*	__pMapOverlayEvent;

	/*
	* The Map InfoWindow Event.
	*/
	Osp::Base::Runtime::IEvent*	__pMapInfoWindowEvent;

	/*
	* The Map Event Adaptor.
	*/
	void* __pMapEventAdaptor;

	/*
	* The MyLocation listener.
	*/
	void* __pRemoteListener;

	/*
	* The Location provider instance.
	*/
	Osp::Locations::LocationProvider* __pLocProvider;

	/*
	* The Map InfoWindow.
	*/
	void* __pInfoWindow;

	/*
	* Determines the panning effect enable or disable.
	*/
	bool __bInfoWindowEffect;

	/*
	* Specifies the relative-position and size of the close button image.
	*/
	Osp::Graphics::Rectangle __closeButtonBound;

	/*
	* Specifies the relative-position and size of the InfoWindow bound.
	*/
	Osp::Graphics::Rectangle __infoWindowBound;

	/*
	* True, if all images for the info window is loaded.
	*/
	bool __bInfoImgLoaded;

	/*
	* The Bitmap of the marker's default image.
	*/
	Osp::Graphics::Bitmap*	__pDefMarkerImage;
	Osp::Graphics::Bitmap*	__pDefShadowImage;
	Osp::Graphics::Bitmap*	__pDefHilightedImage;

	/*
	* The Bitmap of my location's image.
	*/
	Osp::Graphics::Bitmap * __pMyLocation;
	Osp::Graphics::Bitmap * __pMyLocationShadow;
	Osp::Graphics::Bitmap * __pMyLocationFail;	

	/*
	* The Bitmap of the InfoWindow's image.
	*/
	Osp::Graphics::Bitmap * __pInfoTail;
	Osp::Graphics::Bitmap * __pInfoCloseBtn;
	Osp::Graphics::Bitmap * __pInfoPressedCloseBtn;
	Osp::Graphics::Bitmap * __pInfoTLEdge;
	Osp::Graphics::Bitmap * __pInfoBLEdge;
	Osp::Graphics::Bitmap * __pInfoTREdge;
	Osp::Graphics::Bitmap * __pInfoBREdge;
	Osp::Graphics::Bitmap * __pInfoTCBar;
	Osp::Graphics::Bitmap * __pInfoBCBar;
	Osp::Graphics::Bitmap * __pInfoRCBar;
	Osp::Graphics::Bitmap * __pInfoLCBar;
	Osp::Graphics::Bitmap * __pInfoBox;

	/*
	* True, if the current zoom status is zoom-in, otherwise false.
	*/
	bool __isZoomIn;

	/*
	* True, if InfoWindow is visible, otherwise false.
	*/
	bool __isInfoVisible;

	void * __pMapServiceListener;
	void * __pListener;
	Osp::Graphics::Bitmap * __pBitmapCache;
		
	Osp::Locations::Services::MapServicePreferences * __pPreferences;

private:

	friend class NativeMapInfoWindow;
	friend class MapOverlayMarker;
	friend class __MapEventAdaptor;
	friend class __MapMapServiceListener;
	friend class MapOverlayPolyline;
	friend class MapOverlayPolygon;
	friend class MapOverlayRectangle;

private:
	
	friend class MapEx;
	class MapEx* __pMapEx;

protected:

	friend class MapImpl;
	
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues that might arise after using this method.
	*
	* Gets the implementation instance of this control.
	*
	 * @deprecated	This method is deprecated.
	* @since          2.0
	* @return         An implementation instance of this control.
	*/
	class MapImpl* GetImpl(void) const;

};

};};};	// Osp::Locations::Controls

#endif	// _FLOC_CTRL_MAP_H_
