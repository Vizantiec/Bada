/* $Change: 1142016 $ */
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
 * @file		FUiIOrientationEventListener.h 
 * @brief		This is the header file for the %IOrientationEventListener interface.
 *
 * This header file contains the declarations of the %IOrientationEventListener interface. @n
 * If an orientation event is generated, a method of this class is called. @n
 * So, if an application performs tasks related to the orientation event, use the methods of this class.
 *
 */
#ifndef _FUI_IORIENTATION_EVENT_LISTENER_H_
#define _FUI_IORIENTATION_EVENT_LISTENER_H_

// Includes
#include "FUiConfig.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Ui { class Control;    } }

namespace Osp {namespace Ui {
	/**
	* @enum	Orientation
	* Defines the constants used to identify the orientations that a control supports.
	*
	* @since	1.0
	*/
	enum Orientation
	{
		ORIENTATION_NONE,							/**< The control has no orientation style */
		ORIENTATION_PORTRAIT,						/**< The control has vertical orientation style */
		ORIENTATION_LANDSCAPE,						/**< The control has horizontal orientation style */
		ORIENTATION_PORTRAIT_REVERSE,				/**< The control has vertical upside-down orientation style */
		ORIENTATION_LANDSCAPE_REVERSE,				/**< The control has horizontal reverse orientation style */
		ORIENTATION_AUTOMATIC = 6,					/**< The control has vertical, horizontal, and horizontal reverse orientation styles*/
		ORIENTATION_AUTOMATIC_FOUR_DIRECTION = 8,	/**< The control has four-directional orientation style */
	};

	/**
	* @enum	OrientationStatus
	* Defines the constants used to identify the current orientation of a control.
	*
	* @since	1.0
	*/
	enum OrientationStatus
	{
		ORIENTATION_STATUS_NONE = 0,											/**< The control orientation status is not determined @b since: @b 2.0 */
		ORIENTATION_STATUS_PORTRAIT = ORIENTATION_PORTRAIT,						/**< The control is set to vertical orientation */
		ORIENTATION_STATUS_LANDSCAPE = ORIENTATION_LANDSCAPE,					/**< The control is set to horizontal orientation */
		ORIENTATION_STATUS_PORTRAIT_REVERSE = ORIENTATION_PORTRAIT_REVERSE,		/**< The control is set to vertical upside-down orientation */
		ORIENTATION_STATUS_LANDSCAPE_REVERSE = ORIENTATION_LANDSCAPE_REVERSE,	/**< The control is set to horizontal reverse orientation */
	};


/**
 * @interface	IOrientationEventListener 
 * @brief		This interface implements the listener for orientation events.
 * @since		1.0
 *
 * The %IOrientationEventListener interface is the listener interface for receiving orientation events. 
 * The class that processes an orientation event implements this interface, and the instance created with that class is registered
 * with a UI control, using the control's AddOrientationEventListener() method. When the orientation event occurs, the
 * OnOrientationChanged() method of that instance is invoked.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_form.htm">Form</a>.

 */
class _EXPORT_UI_ IOrientationEventListener :
	public Osp::Base::Runtime::IEventListener
{
// Operation
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IOrientationEventListener(void) {}

	/**
	 * Called when an orientation event occurs.
	 *
	 * @since		1.0
	 * @compatibility	This method has compatibility issues with different bada API versions. @n
	 *					For more information, see issues in version @ref CompOnOrientationChanged "1.2" and @ref CompOnOrientationChanged20 "2.0".
	 * @param[in] 	source					The source of the event
	 * @param[in] 	orientationStatus		The information about the orientation event
	 * @remarks		The orientation changed event is fired on %Control for which orientation mode change has been enabled by calling SetOrientation().
	 * @see		Osp::Ui::Controls::Frame
	 * @see		Osp::Ui::Controls::Form
	 */
	virtual void OnOrientationChanged(const Osp::Ui::Control& source, Osp::Ui::OrientationStatus orientationStatus) = 0;

	/**
	 * @page	CompOnOrientationChanged	Compatibility for OnOrientationChanged()
	 *
	 * @section	CompOnOrientationChanged	Issues
	 * Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	 * -#  When a %Frame only application is executed, the OnOrientationChanged() event does not occur until %Frame is shown again.
	 *
	 * @section	CompOnOrientationChangedResolutions	Resolutions
	 * The issue mentioned above is resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	 */
	 
	 /**
	 * @page	CompOnOrientationChanged20	Compatibility for OnOrientationChanged()
	 *
	 * @section	CompOnOrientationChanged20Issues	Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# The OnOrientationChanged() event does not occur after a %Form control starts with portrait orientation.
	 *
	 * @section	CompOnOrientationChanged20Resolutions	Resolutions
	 * -# The OnOrientationChanged() event always occurs after a %Form control is initialized.
	 */
};

}; /* Osp::Ui*/ }; /* Osp */

#endif // _FUI_IORIENTATION_EVENT_LISTENER_H_

