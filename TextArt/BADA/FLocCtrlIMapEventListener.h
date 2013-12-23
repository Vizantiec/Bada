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
* @file		FLocCtrlIMapEventListener.h 
* @brief	This is the header file for the %IMapEventListener interface.
*
* This header file contains the declarations of the %IMapEventListener interface.
*/

#ifndef _FLOC_CTRL_IMAP_EVENT_LISTENER_H_
#define _FLOC_CTRL_IMAP_EVENT_LISTENER_H_

#include <FUiConfig.h>
#include <FBaseRtIEventListener.h>
#include <FBaseTypes.h>
#include <FGraphics.h>
#include <FLocCtrlMap.h>
#include <FLocCoordinates.h>

namespace Osp { namespace Locations { namespace Controls { class Map; } } }
namespace Osp { namespace Locations { namespace Controls {

/**
* @internal
* This method is for internal use only. The bada platform team is not responsible for any 
* behavioral correctness, consistency, and security-related issues that might arise after 
* using this method.
*
* Defines constants used to identify map view status.
*
* @deprecated	This enumerated type is deprecated.
* @since	1.0
*/
enum MapStatus
{
	MAP_CLICK = 0,
	MAP_MOVE_START,	
	MAP_MOVE_END,	
	MAP_ZOOMING_START,
	MAP_ZOOMING_END,		
	MAP_DRAW_COMPLETED,
	MAP_DRAW_ERROR
};

/**
* @interface	IMapEventListener
* @brief		This interface is used as the map event listener.
* @deprecated	This interface is deprecated.
* @since		1.0
* 
* The %IMapEventListener interface acts as the map event listener by providing the event notification methods that support the interaction between a map and an 
* application. For example, an application needs to know whether a map has been clicked, moved, or zoomed. To do so, an application can inherit 
* %IMapEventListener and override the event notification methods that can be customized later.
*
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/map_controls.htm">Map Controls</a>.
*/
class _EXPORT_LOCATION_CONTROL IMapEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~IMapEventListener(void){}

	/**
	* Called to notify when an entity is released if the touched and released position are the same.  
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in] 	source		The source of the event
	* @param[in] 	point		The display position
	* @param[in] 	coordinates	The geographical coordinates
	*/
	virtual void OnMapClicked(const Osp::Locations::Controls::Map& source, const Osp::Graphics::Point& point, const Osp::Locations::Coordinates& coordinates) = 0;

	/**
	* Called to notify when an entity is flicked. 
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in] 	source	The source of the event
	* @remarks		This listener method is called only if the map panning is started by user interaction.
	*/
	virtual void OnMapMovingStarted(const Osp::Locations::Controls::Map& source) = 0;

	/**
	* Called to notify the application when the movement of a map ends. 
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	source		The source of the event
	* @remarks		This listener method is called only if the map panning is started by user interaction.
	*/
	virtual void OnMapMovingEnded(const Osp::Locations::Controls::Map& source) = 0;
	
	/**
	 * Called to notify when a map starts zooming. 
	 *
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref OnMapZoomingStartedPage "here".
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @param[in]	source		The source of the event
	 * @param[in]	isZoomedIn	Set to @c true for the Zoom-In mode, @n
	 *							else @c false for the Zoom-Out mode
	 * @remarks	This listener method is called only if the map zooming is started by user interaction.
	 */
	virtual void OnMapZoomingStarted(const Osp::Locations::Controls::Map& source, bool isZoomedIn) = 0;

	/**
	* @page		OnMapZoomingStartedPage Compatibility for OnMapZoomingStarted()
	*
	* @section	OnMapZoomingStartedPageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	* 			-# This listener method is called when the map zooming is started by user interaction and method call.
	*			-# The second parameter @c zoomIn is set to @true even though the map is in the Zoom-Out mode.
	*
	* @section	OnMapZoomingStartedPageResolutionSection Resolutions
	*			The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
	*/

	/**
	* Called to notify when a map ends zooming. 
	*
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref OnMapZoomingEndedPage "here".
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	source		The source of the event
	* @param[in]	isZoomedIn	Set to @c true for the Zoom-In mode @n
	*							else @c false for the Zoom-Out mode
	* @remarks	This listener method is called only if the map zooming is ended by user interaction.
	*/
	virtual void OnMapZoomingEnded(const Osp::Locations::Controls::Map& source, bool isZoomedIn) = 0;

	/**
	* @page		OnMapZoomingEndedPage Compatibility for OnMapZoomingEnded()
	*
	* @section	OnMapZoomingEndedPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*			-# This listener method is called when the map zooming is ended by user interaction and method call.
	*			-# The second parameter @c zoomIn is set to @true even though the map is in the Zoom-Out mode.
	*
	* @section	OnMapZoomingEndedPageResolutionSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
	*/

	/**
	* Called to notify the application once the drawing of all the map tiles to the graphic canvas is completed.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*					For more information, see @ref OnMapDrawCompletedPage "here".
	*
	* @param[in] 		source	The source of the event
	*/
	virtual void OnMapDrawCompleted(const Osp::Locations::Controls::Map& source) = 0;

	/**
	* @page	OnMapDrawCompletedPage Compatibility for OnMapDrawCompleted()
	*
	* @section	OnMapDrawCompletedIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*			-# This listener method is called before the drawing of a map is completed.
	*			-# This listener method may be called multiple times while panning with animation, 
	*			only when the map panning occurs using the @ref Osp::Locations::Controls::Map::Pan() method.
	*
	* @section	OnMapDrawCompletedSolutionSection Resolutions 
	* 			The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
	*
	* @par		When working with bada API versions prior to 2.0 for issue 1: @n
	*			An application utilizes this user event when the drawing of a map is completed. @n
	*			An application sends a user event using the SendUserEvent() method inside the OnMapDrawCompleted() method. @n
	* 			When the OnUserEventReceivedN() method is called, the map is completely drawn. @n 
	*/ 

	/**
	* Called to notify the application if an error occurs when drawing the map tiles to the graphic canvas.
	* The error could result from a loss of network connection or a problem in the map service provider.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	source				The source of the event
	* @param[in]	r					The result of the operation
	* @param[in]	errorCode			The error code from the server
	* @param[in]	errorMsg			The error message from the server
	* @exception	E_LOCATION_SERVICE	An error has prevented the service provider from servicing the request.
	* @exception	E_SERVER			An error has occurred on the server side.
	* @remarks		An error may occur when a higher priority task, such as an incoming call or a message, interrupts the map service.
	*/
	virtual void OnMapDrawErrorOccured(const Osp::Locations::Controls::Map& source, result r, const Osp::Base::String& errorCode, const Osp::Base::String& errorMsg) {}

};

};};};	// Osp::Locations::Controls;

#endif	// _FLOC_CTRL_IMAP_EVENT_LISTENER_H_
