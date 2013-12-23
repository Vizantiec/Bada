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
 * @file	FUiTouch.h
 * @brief	This is the header file for the %Touch class.
 *
 * This header file contains the declarations of the %Touch class.
 *
 */


#ifndef _FUI_Touch_H_
#define _FUI_Touch_H_
//#define __USING_PI_COM__
// Includes
#include "FSysConfig.h"
#include "FBaseObject.h"
#include "FBaseColIList.h"
#include "FGraphics.h"
#include "FUiConfig.h"


namespace Osp { namespace Base { namespace Runtime { class IEventArg; }; }; };

namespace Osp { namespace Ui {

class Control;
class ITouchPi;
#ifndef __USING_PI_COM__
class __TouchPi;
#endif

/**
 * @enum	TouchStatus
 *
 * Defines the constants used to identify touch status.
 *
 * @since	1.0
 */
enum TouchStatus
{
    TOUCH_PRESSED,          /**< The touch pressed event type */
    TOUCH_LONG_PRESSED,     /**< The touch long pressed event type */
    TOUCH_RELEASED,         /**< The touch released event type */
    TOUCH_MOVED,            /**< The touch moved event type	*/
    TOUCH_DOUBLE_PRESSED,   /**< The touch double pressed event type */
    TOUCH_FOCUS_IN,         /**< The touch focus-in event type */
    TOUCH_FOCUS_OUT,        /**< The touch focus-out event type */
};

/**
 * @class	TouchInfo
 * @brief	This class stores the information of a touch event.
 * @since	1.0
 *
 * The %TouchInfo class provides touch-related information to support multi-point touch.
 *
 */
class _EXPORT_UI_ TouchInfo:
	public Osp::Base::Object
{
public:

	/**
	* The ID of the Touch instance.
	*
	* @since	1.0
	*/
	unsigned long id;

	/**
	* The position of the Touch instance.
	*
	* @since	1.0
	*/
	Osp::Graphics::Point position;


	/**
	* The status of the Touch instance, using only the TOUCH_PRESSED and TOUCH_RELEASED states.
	*
	* @since	1.0
	*/
	TouchStatus status;
};

/**
 * @class		TouchEventInfo
 * @brief		This class stores the information of each touch event.
 * @since		1.0
 *
 * The %TouchEventInfo class provides touch event information, such as the touch position, status, and ID.
 *
 * @see 	ITouchEventListener, ITouchEventListener::OnTouchPressed(), ITouchEventListener::OnTouchLongPressed(), ITouchEventListener::OnTouchReleased(), 
 *			ITouchEventListener::OnTouchMoved(), ITouchEventListener::OnTouchDoublePressed(),  ITouchEventListener::OnTouchFocusIn(), 
 *			ITouchEventListener::OnTouchFocusOut()
 *
 */
class _EXPORT_UI_ TouchEventInfo:
	public Osp::Base::Object
{
public:

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Initializes this instance of TouchEventInfo with the specified parameters.
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in] 	eventArg  		The touch event argument 
	 */
	result Construct(const Osp::Base::Runtime::IEventArg & eventArg);

	/**
	 * Gets the ID of the current touch event.
	 *
	 * @since	1.0
	 * @return	The ID of the current touch event
	 */
	unsigned long GetPointId(void) const;

	/**
	 * Gets the start position of the touch event.
	 *
	 * @since	1.0
	 * @return	The start position of the touch event
	 */
	Osp::Graphics::Point GetStartPosition(void) const;

	/**
	 * Gets the current position of the touch event.
	 *
	 * @since	1.0
	 * @return	The current position of the touch event
	 */
	Osp::Graphics::Point GetCurrentPosition(void)const;

	/**
	 * Gets the touch status.
	 *
	 * @since	1.0
	 * @return  The touch status
	 */
	TouchStatus GetTouchStatus(void)const;

	/**
	 * Checks whether the touch status is flick.
	 *
	 * @since	1.0
	 * @return 	@c true if the touch status is flick, @n
     *  			else @c false
	 */
	bool IsFlicked(void) const;

private:
	unsigned long __PointId;
	TouchStatus __touchStatus;
	Osp::Graphics::Point __startPosition;
	Osp::Graphics::Point __currentPosition;
	bool	__isFlicked;
};

/**
 * @class	Touch
 * @brief	This class supports multi-point touch for %Touch devices.
 * @since	1.0
 *
 * The %Touch class supports multi-point touch, and provides information about touch events.
 *
 * The following example demonstrates how to use the %Touch class.
 * @code

// Sample Code for TouchSample.h
#include <FUi.h>

class TouchSample :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::ITouchEventListener
{
public:
    TouchSample(void) {};
    virtual ~TouchSample(void) {};

protected:
    void DisplayMultipointTouchInfo(const Osp::Ui::Control &source);

public:
    virtual result OnInitializing(void);
    virtual void OnTouchDoublePressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
    virtual void OnTouchFocusIn(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
    virtual void OnTouchFocusOut(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
    virtual void OnTouchLongPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
    virtual void OnTouchMoved(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
    virtual void OnTouchPressed(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
    virtual void OnTouchReleased(const Osp::Ui::Control &source, const Osp::Graphics::Point &currentPosition, const Osp::Ui::TouchEventInfo &touchInfo);
};

// Sample Code for TouchSample.cpp
#include "TouchSample.h"

using namespace Osp::Base::Collection;
using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

// How to enable touch event and multi-point.
result
TouchSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    AddTouchEventListener(*this);
    Touch touch;
    touch.SetMultipointEnabled(*this, true);

    return r;
}

void
TouchSample::DisplayMultipointTouchInfo(const Control &source)
{
    Touch touch;
    IList *pList = null;
    pList = touch.GetTouchInfoListN(source);
    if (pList)
    {
        for(int i=0; i<pList->GetCount(); i++ )
        {
            TouchInfo *pTouchInfo = static_cast<TouchInfo *>(pList->GetAt(i));
            AppLog("OnTouchMoved : [%d]%d,%d - %d", pTouchInfo->id, pTouchInfo->position.x ,pTouchInfo->position.y,pTouchInfo->status);
        }
        pList->RemoveAll(true);
        delete pList;
    }
}

// How to implement ITouchEventListener
void
TouchSample::OnTouchDoublePressed(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchDoublePressed is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchFocusIn(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchFocusIn is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchFocusOut(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchFocusOut is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchLongPressed(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchLongPressed is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchMoved(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchMoved is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchPressed(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchPressed is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

void
TouchSample::OnTouchReleased(const Control &source, const Point &currentPosition, const TouchEventInfo &touchInfo)
{
    AppLog("OnTouchReleased is called. [%d]%d,%d", touchInfo.GetPointId(), currentPosition.x, currentPosition.y);
    DisplayMultipointTouchInfo(source);
}

 * @endcode
 *
 */
class _EXPORT_UI_ Touch :
	public Osp::Base::Object
{
public:
	/**
	 * @internal
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Invalid cursor ID
	 *
	 * @since     1.0
	*/
	static const unsigned long INVALID_CURSOR_ID = 0xffffffff;

	/**
	 * The default constructor for this class.
	 *
	 * @since		1.0
	 */
	Touch(void);

	/**
	 * The destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Touch(void);

public:
	/**
	 * Enables or disables the multi-point touch of the Control. 
	 *
	 * @since		1.0
	 * @return		An error code
	 * @param[in]	control				The control
	 * @param[in]	enable				A Boolean flag indicating whether to enable to the multi-point touch
	 * @exception	E_SUCCESS           The method is successful.
	 * @exception	E_INVALID_OPERATION	The current state of the instance prohibits the execution of the specified operation. @n
	 *									The specified @c control is not constructed.
 	 * @see			IsMultipointEnabled()
	 *
	 */
	result SetMultipointEnabled(const Osp::Ui::Control& control,bool enable);

	/**
	 * Checks whether the multi-point touch is enabled.
	 *
	 * @since		1.0
	 * @return		@c true if the multi-point touch is enabled, @n
	 *				else @c false
	 * @see			IsMultipointEnabled()
	 */
	bool IsMultipointEnabled(const Osp::Ui::Control& control) const;


	/**
	 * Gets the touch position.
	 * If there is only a single touch, that is returned. If there are multi-point touches, then the position of the last touch is returned.
	 *
	 * @since			1.0
 	 * @return			The coordinates of the touch
	 */
	Osp::Graphics::Point GetPosition(void);

	/**
	 * Gets the touch position by ID.
	 *
	 * @since			1.0
	 * @return			The coordinates of the touch
	 * @param[in]		id		The ID of the touch
	 */
	Osp::Graphics::Point GetPosition(unsigned long id);

	/**
	 * Gets the touch position relative to the specified control.
	 *
	 * @since			1.0
	 * @return			The coordinates of the touch
	 * @param[in]		control		The source control
	 */
	Osp::Graphics::Point GetPosition(const Osp::Ui::Control& control);

	/**
	 * Gets the touch position relative to the specified control by ID.
	 *
	 * @since		1.0
	 * @return		The coordinates of the touch
	 * @param[in]	control		The source conotrol
	 * @param[in]	id			The ID of the touch
	 *
	 */
	Osp::Graphics::Point GetPosition(const Osp::Ui::Control& control, unsigned long id);

	/**
	* Gets the status of the touch by ID.
	*
	* @since		1.0
	* @param[in]	id		The ID of the touch
	* @return		The touch status
	*
	*/
	TouchStatus GetTouchStatus(unsigned long id);

	/**
	 * Gets the list of the multi-point touches, each represented by %TouchInfo.
	 *
	 * @since		1.0
	 * @return		List of the TouchInfo
	 * @see			Osp::Ui::TouchInfo
	 *
	 */
	Osp::Base::Collection::IList* GetTouchInfoListN(void) ;


	/**
	 * Gets the list of the multi-point touch positions relative to the specified control, each represented by %TouchInfo.
	 *
	 * @since		1.0
	 * @return		A list of the TouchInfo instances
	 * @param[in]	control 	The source object for calculating the coordinates
	 * @see			Osp::Ui::TouchInfo
	 *
	 */
	Osp::Base::Collection::IList* GetTouchInfoListN(const Osp::Ui::Control& control);

	/**
	* Gets the count of the multi-point touches.
	*
	* @since		1.0
	* @return		The number of the multi-point touches
	*/
	int GetPointCount(void);

	/**
	 * Gets the point ID at the given index.
	 *
	 * @since		1.0
	 * @return		The touch point ID
	 * @param[in]	index	The index of the touch
	 */
	 unsigned long GetPointId(int index);

private:
#ifdef __USING_PI_COM__
	ITouchPi* __pITouchPi;
#else
	__TouchPi * __pITouchPi;
#endif

};
};};


#endif
