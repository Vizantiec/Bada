/* $Change: 995676 $ */
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
 * @file	FUiCtrlAnimation.h
 * @brief	This header file contains the declarations of the %Animation class.
 *
 * This header file contains the declarations of the %Animation class and its helper classes.
 */

#ifndef _FUICTRL_ANIMATION_H_
#define _FUICTRL_ANIMATION_H_

// Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseColArrayList.h"
#include "FGrpBitmap.h"
#include "FGrpColor.h"
#include "FGrpPoint.h"
#include "FGrpRectangle.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlAnimationFrame.h"
#include "FUiIAnimationEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

/**
 * @enum	AnimationStatus
 * Defines the animation status.
 *
 * @since		1.0
 */
typedef enum {
		ANIMATION_STOPPED,				/**< The Animation is in 'stopped' state */
		ANIMATION_PAUSED,				/**< The Animation is in 'paused' state */
		ANIMATION_PLAYING				/**< The Animation is in 'playing' state */
} AnimationStatus;


/**
 * @class	Animation
 * @brief This class defines the common behavior of an %Animation control.
 * @since	1.0
 * 
 * The %Animation class displays a series of frames one by one which are represented by the AnimationFrame instances.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_animation.htm">Animation</a>.
 *
 *
 * The following example demonstrates how to use the %Animation class.
 *
 *
 * @code

// Sample Code for AnimationSample.h
#include <FUi.h>

class AnimationSample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::IAnimationEventListener
{
protected:
    Osp::Graphics::Bitmap* GetBitmapN(void);
    Osp::Base::Collection::ArrayList __animationFrameList;

public:
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
    virtual void OnAnimationStopped(const Osp::Ui::Control& source);
};


// Sample Code for AnimationSample.cpp
#include "AnimationSample.h"

using namespace Osp::Graphics;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Base::Collection;

result
AnimationSample::OnInitializing(void)
{
    result r = E_SUCCESS;

    // Create Bitmaps
    Bitmap* pBitmap1 = GetBitmapN();
    Bitmap* pBitmap2 = GetBitmapN();
    Bitmap* pBitmap3 = GetBitmapN();
    Bitmap* pBitmap4 = GetBitmapN();

    // Create AnimationFrames
    AnimationFrame* pAniFrame1 = new AnimationFrame(*pBitmap1, 1000) ;
    AnimationFrame* pAniFrame2 = new AnimationFrame(*pBitmap2, 1000) ;
    AnimationFrame* pAniFrame3 = new AnimationFrame(*pBitmap3, 1000) ;
    AnimationFrame* pAniFrame4 = new AnimationFrame(*pBitmap4, 1000) ;

    __animationFrameList.Construct();
    __animationFrameList.Add(*pAniFrame1);
    __animationFrameList.Add(*pAniFrame2);
    __animationFrameList.Add(*pAniFrame3);
    __animationFrameList.Add(*pAniFrame4);

    // Create an Animation
    Animation* pAnimation = new Animation();
    pAnimation->Construct(Rectangle(0, 50, 128, 128), __animationFrameList);
    pAnimation->SetRepeatCount(100);
    pAnimation->AddAnimationEventListener(*this);

    // Add an Animation to the Form
    AddControl(*pAnimation);

    // Display the Form
    Draw();
    Show();

    // Play an Animation
    pAnimation->Play();

    return r;
}

result
AnimationSample::OnTerminating(void)
{
    result r = E_SUCCESS;

    // Deallocate bitmaps
    __animationFrameList.RemoveAll(true);
    return r;
}

Bitmap*
AnimationSample::GetBitmapN(void)
{
    return null; // You should implement GetBitmapN
}

void
AnimationSample::OnAnimationStopped(const Osp::Ui::Control& source)
{
    // Todo:
}

 * @endcode
 *
 */
class _EXPORT_CONTROLS_ Animation 
	: public Osp::Ui::Control
{

	DECL_CLASSTYPE(Animation);
// Lifecycle	
public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	Animation(void);


	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.0
	 */
	virtual ~Animation(void);


	/**
	 * Initializes this instance of %Animation with the specified parameters. @n
	 * The input list of the AnimationFrame instances (@c aniFrames) should be deleted explicitly after use.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
     *                  For more information, see @ref CompControlConstruct20 "here".
	 * @return		An error code
	 * @param[in]	rect			An instance of the Rectangle class @n
	 *								This instance represents the x and y coordinates of the top-left corner of the created window along with 
	 *								its width and height.
	 * @param[in]	aniFrames		An IList of %AnimationFrames used in the animation
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception   E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks		A control is fully usable only after it has been added to a container, therefore some methods may fail if used earlier. @n
	 *				In the bada API versions prior to 2.0, the width and the height of the control must be greater than @c 0. @n
     * 				From bada API version 2.0, the size of the control must be within the range defined by the minimum size and the maximum size.
     * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.
	 * @see 		AnimationFrame
	 */
	result Construct(const Osp::Graphics::Rectangle& rect, const Osp::Base::Collection::IList& aniFrames);


// Operation
public:
	/**
	* Adds a listener instance to the current instance of %Animation. @n
	* The added listener can listen to the events on the given event dispatcher's context when they are fired. @n
	 * When an animation stops, a state change event with the state name "ANIMATION_NOTIFY_CLOSE" is fired.
	 *
	 * @since		1.0
	* @param[in]	listener	The listener to be added
	 */
	void AddAnimationEventListener(const Osp::Ui::IAnimationEventListener& listener);

	/**
	* Removes a listener instance from the current instance of %Animation. @n
	* The removed listener cannot listen to the events when they are fired.
	 *
	 * @since		1.0
	* @param[in]	listener	The listener to be removed
	 */
	void RemoveAnimationEventListener(const Osp::Ui::IAnimationEventListener& listener);

	/**
	 * Sets the repeat count of the animation. @n
	 * If this value is not set, the default value is @c 1.
	 *
	 * @since			1.0
	 * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	 *					For more information, see @ref CompAnimationSetRepeatCount "here".
	 * @param[in] 		count		The repeat count
	 */
	void SetRepeatCount(int count);

	/**
	 * @page   CompAnimationSetRepeatCount	Compatibility for SetRepeatCount()
	 * @section CompAnimationSetRepeatCountIssues Issues
	 * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	 * -# If the repeat count of the animation is set on playing, the animation is sometimes repeated infinitely.
	 *
	 * @section CompAnimationSetRepeatCountResolutions Resolutions
	 * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	 */

	/**
	 * Gets the total repeat count of the animation.
	 *
	 * @since		1.0
	 * @return		The total repeat count, @n
	 *          	else @c -1 if the %Animation instance is not constructed
	 */
	int GetRepeatCount(void) const;

	/**
	 * Gets the current repeated count of the animation.
	 *
	 * @since		1.0
	 * @return		The current repeated count, @n
	 *          	else @c -1 if the %Animation instance is not constructed 
	 */
	int GetCurrentRepeatedCount(void) const;

	/**
	 * Gets the total image count of the animation.
	 *
	 * @since		1.0
	 * @return		The total image count, @n
	 *				else @c -1 if the %Animation instance is not constructed
	 */
	int GetImageCount(void) const;

	/**
	 * Plays the animation.
	 *
	 * @since		1.0
	 */
	void Play(void);

	/**
	* Stops the animation.
	 *
	 * @since		1.0
	 */
	void Stop(void);

	/**
	* Pauses the animation.
	 *
	 * @since		1.0
	 */
	void Pause(void);


	/**
	 * Gets the status of the animation.
	 *
	 * @since	1.0
	 * @return	The status of animation, @n
	*			else ANIMATION_STOPPED if the %Animation control is not constructed
	 */
	AnimationStatus GetStatus(void) const;

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by this control and destroys its native window if it is present).
	 *
	 * @since		1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	result Dispose(void);


private:
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * State Change Event
     * @since         1.0
	 */
	Osp::Base::Runtime::IEvent* __pAnimationEvent;

	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * State Change Event Adaptor
     * @since         1.0
	 */
	void* __pAnimationEventAdaptor;

// Attribute
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * Animation Frames
     * @since         1.0
	 */
	void* __pAnimationFrames;
	
private:
	friend class AnimationEx;
	class AnimationEx* __pAnimationEx;

protected:
	friend class AnimationImpl;

	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Gets the implementation instance of this control
	 *
	 * @since         2.0
	 */
	class AnimationImpl* GetImpl(void) const;

};
}; }; }; // Osp::Ui::Controls

#endif // _FUICTRL_ANIMATION_H_

