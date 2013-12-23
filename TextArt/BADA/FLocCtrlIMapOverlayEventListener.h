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
* @file		FLocCtrlIMapOverlayEventListener.h
* @brief	This is the header file for the %IMapOverlayEventListener interface.
*
* This header file contains the declarations of the %IMapOverlayControlEventListener interface.
*/

#ifndef _FLOC_CTRL_IMAP_VIEW_OVERLAY_EVENT_LISTENER_H_
#define	_FLOC_CTRL_IMAP_VIEW_OVERLAY_EVENT_LISTENER_H_

#include <FUiConfig.h>
#include <FBaseRtIEventListener.h>
#include <FBaseTypes.h>
#include <FGraphics.h>
#include <FLocCtrlIMapOverlay.h>

namespace Osp { namespace Locations { namespace Controls {
/**
* @internal
* This method is for internal use only. 
* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues 
* that might arise after using this method.
*
* Defines constants used to identify the map view overlay control status.
*
* @deprecated	This enumerated type is deprecated.
* @since	1.0
*/
enum MapOverlayStatus
{
	MAP_OVERLAY_CLICK = 0,
	MAP_OVERLAY_DRAG,
	MAP_OVERLAY_DROP,
	MAP_OVERLAY_DOUBLE_PRESS
};

/**
 * @interface	IMapOverlayEventListener
 * @brief		This interface is used as the map overlay event listener.
 * @deprecated	This interface is deprecated.
 * @since		1.0
 *
 * The %IMapOverlayEventListener interface provides the event notifications regarding the interaction between overlays and an application.
 * 
 * For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
 * 
 */
 
class _EXPORT_LOCATION_CONTROL IMapOverlayEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~IMapOverlayEventListener(void) {}

	/**
	* Called to notify when the touch and release positions of the released entity are the same. @n
	* This method supports a closed shape and marker.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
	*					For more information, see issue descriptions in versions @ref CompIMapOverlayEventListenerClickPage "1.1" and @ref CompIMapOverlayEventListenerClick2Page "1.2".
	*
	* @param[in]		source	The source of the event
	*/
	virtual void OnMapOverlayControlClicked(const Osp::Locations::Controls::IMapOverlay& source) = 0;

	/**
	* @page		CompIMapOverlayEventListenerClickPage Compatibility for OnMapOverlayControlClicked()
	*
	* @section	CompIMapOverlayEventListenerClickPageIssueSection Issues
	*			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	*			-# Overlay event occurs even if the overlay is not drawn on the map in case the total overlay count exceeds the maximum count of the displayed overlay.
	*
	* @section	CompIMapOverlayEventListenerClickPageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	* @par		When working with bada API versions prior to 1.1:
	*			Set the maximum count of the displayed overlay large enough to include all the overlays by using the SetOverlayDisplayMaxCount().
	*/

	/**
	* @page		CompIMapOverlayEventListenerClick2Page Compatibility for OnMapOverlayControlClicked()
	*
	* @section	CompIMapOverlayEventListenerClick2PageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* 			-# If the coordinates of an overlay are out of the screen and the bounding box of the overlay overlaps the screen partially, an overlay event occurs 
	* 			even if the overlay is not displayed on the map.
	*
	* @section	CompIMapOverlayEventListenerClick2PageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	*/

	/**
	* Called when an entity is dragged. @n
	* This method supports MapOverlayMarker only.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*
	* @compatibility	This method has compatibility issues with different bada API versions. @n
	*					For more information, see issue descriptions in versions @ref CompIMapOverlayEventListenerDragPage "1.1" and @ref CompIMapOverlayEventListenerDrag2Page "1.2".	
	*
	* @param[in] 	source		The source of the event
	* @param[in] 	coordinates	The geographical coordinates
	*/
	virtual void OnMapOverlayControlDragged(const Osp::Locations::Controls::IMapOverlay& source, const Osp::Locations::Coordinates& coordinates) = 0;

	/**
	* @page		CompIMapOverlayEventListenerDragPage Compatibility for OnMapOverlayControlDragged()
	*
	* @section	CompIMapOverlayEventListenerDragPageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	*			-# Overlay event occurs even if the overlay is not drawn on the map in case the total overlay count exceeds the maximum count of the displayed overlay.
	*
	* @section	CompIMapOverlayEventListenerDragPageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	* @par		When working with bada API versions prior to 1.1:
	*			Set the maximum count of the displayed overlay large enough to include all the overlays by using the SetOverlayDisplayMaxCount().
	*/

	/**
	* @page		CompIMapOverlayEventListenerDrag2Page Compatibility for OnMapOverlayControlDragged()
	*
	* @section	CompIMapOverlayEventListenerDrag2PageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*			-# If the coordinates of an overlay are out of the screen, and the bounding box of the overlay overlaps the screen partially,
	*			overlay events can occur even though the overlay is not displayed on the map.
	*
	* @section	CompIMapOverlayEventListenerDrag2PageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above.
	*/

	/**
	* Called to notify when an entity is dropped. @n
	* This method supports MapOverlayMarker only.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
	*					For more information, see issue descriptions in versions @ref CompIMapOverlayEventListenerDropPage "1.1" and @ref CompIMapOverlayEventListenerDrop2Page "1.2".	
	*
	* @param[in] 	source		The source of the event
	* @param[in] 	coordinates	The geographical coordinates	
	*/
	virtual void OnMapOverlayControlDropped(const Osp::Locations::Controls::IMapOverlay& source, const Osp::Locations::Coordinates& coordinates) = 0;

	/**
	* @page		CompIMapOverlayEventListenerDropPage Compatibility for OnMapOverlayControlDropped()
	*
	* @section	CompIMapOverlayEventListenerDropPageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	*			-# Overlay event occurs even if the overlay is not drawn on the map in case the total overlay count exceeds the maximum count of the displayed overlay.
	*
	* @section	CompIMapOverlayEventListenerDropPageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	* @par		When working with bada API versions prior to 1.1:
	*			Set the maximum count of the displayed overlay large enough to include all the overlays by using the SetOverlayDisplayMaxCount().
	*/

	/**
	* @page		CompIMapOverlayEventListenerDrop2Page Compatibility for OnMapOverlayControlDropped()
	*
	* @section	CompIMapOverlayEventListenerDrop2PageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*			-# If the coordinates of an overlay is out of the screen and the bounding box of the overlay overlaps the screen partially,
	*			overlay events for the overlay can occur even though the overlay is not displayed on a map.
	*
	* @section	CompIMapOverlayEventListenerDrop2PageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	*/

	/**
	* Called to notify when an entity is double-clicked.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with different bada API versions. @n
	*					For more information, see issue description in versions @ref CompIMapOverlayEventListenerDoublePressedPage "1.1" and @ref CompIMapOverlayEventListenerDoublePressed2Page "1.2".
	*
	* @param[in] 		source	The source of the event
	* @remarks			Both OnMapOverlayControlDoublePressed() and OnMapOverlayControlClicked() are called,
	*					when an overlay control is double-clicked.
	*/
	virtual void OnMapOverlayControlDoublePressed(const Osp::Locations::Controls::IMapOverlay& source) = 0;

	/**
	* @page		CompIMapOverlayEventListenerDoublePressedPage Compatibility for OnMapOverlayControlDoublePressed()
	*
	* @section	CompIMapOverlayEventListenerDoublePressedPageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.1 has the following issue: @n
	*			-# Overlay event occurs even if the overlay is not drawn on the map in case the total overlay count exceeds the maximum count of the displayed overlay.
	*
	* @section	CompIMapOverlayEventListenerDoublePressedPageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	* @par		When working with bada API versions prior to 1.1:
	*			Set the maximum count of the displayed overlay large enough to include all the overlays by using the SetOverlayDisplayMaxCount().
	*/

	/**
	* @page		CompIMapOverlayEventListenerDoublePressed2Page Compatibility for OnMapOverlayControlDoublePressed()
	*
	* @section	CompIMapOverlayEventListenerDoublePressed2PageIssueSection Issues
	* 			Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	*			-# If the coordinates of an overlay is out of the screen and the bounding box of the overlay overlaps the screen partially,
	*			overlay events for the overlay can occur even though the overlay is not displayed on a map.
	*
	* @section	CompIMapOverlayEventListenerDoublePressed2PageResolutionsSection Resolutions
	* 			The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use API version 1.2 or above.
	*/

};		// IMapOverlayEventListener

};};};	// Osp::Locations::Controls;

#endif	//_FLOC_CTRL_IMAP_VIEW_OVERLAY_EVENT_LISTENER_H_
