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
 * @file			FUixMotion.h 
 * @brief			This is the header file for the %Motion class.
 *
 * This header file contains the declarations of the %Motion class.
 */

#ifndef _FUIX_MOTION_H_
#define _FUIX_MOTION_H_

// include
#include "FBaseObject.h"
#include "FUixConfig.h"
#include "FUixMotionCommon.h"
#include "FUixIMotionEventListener.h"

namespace Osp{ namespace Uix{ class IMotionPi; } }

namespace Osp{ namespace Uix{ 

/**
* @class	Motion
* @brief	This class is used to probe or to receive an event about conceptual states of the device's movement.
* @since	1.0
* 
* The %Motion class allows an application to know about the movement of the device. The information is given in 2 ways:
* the application probes the state or the application registers a listener and receives an event when a movement is observed.
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/device_motions.htm">Device Motions</a>.
*
* The following example demonstrates how to use the %Motion class to register a motion event listener and receive motion events.
* 
* @code
* class MotionExample : public Osp::Uix::IMotionEventListener
* {
* public:
* 	result Initialize();
* 
* 	// MotionEventListener
* 	void OnDoubleTapDetected(void);
* 	void OnShakeDetected(Osp::Uix::MotionState motionState);
* 	void OnSnapDetected(Osp::Uix::MotionSnapType snapType);
* 
* private:
* 	Osp::Uix::Motion* pMotion;
* };
* 
* result MotionExample::Initialize(void)
* {
* 	pMotion = new Motion();
* 	pMotion->Construct(*this);
* 	pMotion->SetEnabled(MOTION_TYPE_DOUBLETAP | MOTION_TYPE_SHAKE);
*
* 	return E_SUCCESS;
* }
* 
* void
* MotionExample::OnDoubleTapDetected(void)
* {
* 	// Do something...
* }
* 
* void
* MotionExample::OnShakeDetected(MotionState motionState)
* {
* 	// Do something...
* }
* 
* void
* MotionExample::OnSnapDetected(MotionSnapType snapType)
* {
* 	// In this example, since Snap is not enabled, this listener will not be called
* }
* @endcode
*/

class _EXPORT_UIX_ Motion:
	public Osp::Base::Object
{
// Lifecycle
public:

	/**
	* This is the default constructor for this class.
	* 
	* @since	1.0
	*/
	Motion(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~Motion(void);

//Operation
public:
	/**
	 * Initializes this instance of %Motion with the specified listener.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	listener					An instance of IMotionEventListener
	 * @exception	E_SUCCESS					The method is successful.
	 * @exception	E_OUT_OF_MEMORY				The memory is insufficient.
	 * @exception	E_INVALID_STATE				This instance is in an invalid state.
	 * @exception	E_MAX_EXCEEDED				The application has reached the maximum number of motion instances.
	 * @exception	E_UNSUPPORTED_OPERATION		The motion detection is not supported.
	 */
	result Construct( const IMotionEventListener& listener);

	/**
	 * Sets the motion event type.   
	 * By default, if this method is not called, all the motion event types will be captured by the listener.
     * If the motion events are not be captured, this method can be called with @c type set to MOTION_TYPE_NONE.
	 *
	 * @since			1.0
	 *
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompMotionSetEnabledPage "here".
	 *
	 *
	 * @param[in]	type				The type of motions to be captured by a listener @n
     *                                  Multiple motion types of type Osp::Uix::MotionType can be combined using the logical OR operator.
	 * @exception	E_SUCCESS			The method is successful.	
	 * @exception   E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_INVALID_ARG		A specified input parameter is invalid  @b since: @b 2.0
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.  
	 * @see			Osp::Uix::MotionType
	 */
    void SetEnabled(unsigned long type);

	/**
     * @page		CompMotionSetEnabledPage Compatibility for SetEnabled()
     *
     * @section		CompMotionSetEnabledPageIssueSection Issues
     *				Implementation of this method in bada API versions prior to 2.0 has following issue: @n
     *				GetLastResult() throws E_SUCCESS instead of E_INVALID_ARG, even if the specified @c type is not a combination of Osp::Uix::MotionType. @n
     *
     * @section		CompMotionSetEnabledPageSolutionSection Resolutions
     *              The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
     */


	/**
	 * Checks whether the specified @c MotionType is supported. 
	 * MOTION_TYPE_NONE and MOTION_TYPE_ALL are invalid, and @c false will be returned for these types.
	 *
	 * @since		1.0
	 * @return		@c true if the specified motion type is supported, @n
	 *				else @c false
	 * @param[in]	type	The type of the motion to query
	 * @see			Osp::Uix::MotionType
	 */
	bool IsSupported(MotionType type) const;


private:
	Motion(const Motion& value);
	Motion& operator =(const Motion& value);
	IMotionPi* __pIMotionPi;

	friend class MotionEx;
	class MotionEx* __pMotionEx;
};

} } //Osp::Uix

#endif
