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
 * @file		FUiAnimations.h
 * @brief		This is the header file for the %Animations namespace.
 *
 * This header file contains the declarations and descriptions of the %Animations namespace.
 */
 
#ifndef _FUIANIMATIONS_H_
#define _FUIANIMATIONS_H_

#include "FUiAnimAnimationBase.h"
#include "FUiAnimAnimationGroup.h"
#include "FUiAnimParallelAnimationGroup.h"
#include "FUiAnimSequentialAnimationGroup.h"
#include "FUiAnimDimensionAnimation.h"
#include "FUiAnimFloatAnimation.h"
#include "FUiAnimIntegerAnimation.h"
#include "FUiAnimPointAnimation.h"
#include "FUiAnimRectangleAnimation.h"
#include "FUiAnimRotateAnimation.h"
#include "FUiAnimControlAnimator.h"
#include "FUiAnimFrameAnimator.h"
#include "FUiAnimAnimationTransaction.h"
#include "FUiAnimIAnimationTransactionEventListener.h"
#include "FUiAnimIControlAnimatorDetailedEventListener.h"
#include "FUiAnimIControlAnimatorEventListener.h"
#include "FUiAnimIFrameAnimatorEventListener.h"

namespace Osp
{
namespace Ui
{
/**
 * @namespace Osp::Ui::Animations
 * @brief	This namespace contains the classes for the animation-related functionalities.
 * @since	2.0
 *
 * @remarks	@b Header @b %file: @b \#include @b <FUiAnimations.h> @n
 *			@b Library : @b FOsp
 *
 * 
 *
 * The %Animations namespace provides animation capabilities for the UI controls.
 * 
 * For more information on the %Animations namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/animation.htm">Animations Guide</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Animations namespace.
 * @image html animation_namespace_class_relationship.png
 *
 * The following example demonstrates how to use the %Animations namespace.
 * 
 *	@code
// Sample code for Control Animation using ControlAnimator

#include <FUi.h>
#include <FUiAnimations.h>

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Ui::Animations;
using namespace Osp::Graphics;

class AnimationSample :
	public Osp::Ui::Controls::Form,
	public Osp::Ui::IActionEventListener
{
public:
	virtual result OnInitializing(void);
	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

protected:
	static const int ID_BUTTON = 101;
	Osp::Ui::Controls::Button *__pButton;
};

result
AnimationSample::OnInitializing(void)
{
	result r = E_SUCCESS;

	// Creates a button
	__pButton = new Button();
	__pButton->Construct(Rectangle(10, 200, 460, 100));
	__pButton->SetText(L"Start animation");
	__pButton->SetActionId(ID_BUTTON);
	__pButton->AddActionEventListener(*this);
	AddControl(*__pButton);

	return r;
}

void
AnimationSample::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_BUTTON:
		{
			// Starts an animation
			result r = E_SUCCESS;

			ControlAnimator* pButtonAnimator = __pButton->GetControlAnimator();
			Point startPos = __pButton->GetPosition();
			Point endPos(startPos.x, startPos.y + 200);
			PointAnimation pointAnimation(startPos,
										  endPos,
										  2000,
										  ANIMATION_INTERPOLATOR_LINEAR);

	        pointAnimation.SetAutoReverseEnabled(true);

			r = pButtonAnimator->StartUserAnimation(ANIMATION_TARGET_POSITION, pointAnimation);
			if (IsFailed(r))
	        {
				AppLog("Start Animation on Button Failed.\n");
				return;
			}
		}
		break;
	}
}
 *	@endcode
 * 
 *	@code
// Sample code for Form Transition Animation using FrameAnimator
 
#include <FUi.h>
#include <FUiAnimations.h>

using namespace Osp::App;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Ui::Animations;

bool
FrameAnimatorSample::OnAppInitializing(AppRegistry& appRegistry)
{
	// Create a form
	Form1 *pForm1 = new Form1();
	pForm1->Initialize();

	Form2* pForm2 = new Form2();
	pForm2->Initialize();

	// Add the form to the frame
	Frame *pFrame = GetAppFrame()->GetFrame();
	pFrame->AddControl(*pForm1);
	pFrame->AddControl(*pForm2);

	// Set the current form
	pFrame->SetCurrentForm(*pForm1);

	// Draw and Show the form
	pForm1->Draw();
	pForm1->Show();

	return true;
}

// Transition from Form1 to Form2
void
Form1::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_TRANSIT:
		{
			result r = E_SUCCESS;

			Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
			FrameAnimator *pFrameAnimator = pFrame->GetFrameAnimator();

			Form *nextFrom = static_cast<Form*>(pFrame->GetControl(L"Form2"));

			if(pFrameAnimator->GetStatus() == ANIMATOR_STATUS_STOPPED)
			{
				pFrameAnimator->SetFormTransitionAnimation (FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_LEFT,
									                        1000,
									                        ANIMATION_INTERPOLATOR_LINEAR );
				r = pFrameAnimator->SetCurrentForm (*nextFrom);
				if (IsFailed(r))
				{
					AppLog("SetCurrentForm on the Form2 Failed.\n");
					return;
				}
			}
		}
		break;
	default:
		break;
	}
}

// Transition from Form2 to Form1
void
Form2::OnActionPerformed(const Control& source, int actionId)
{
	switch(actionId)
	{
	case ID_FOOTER_BUTTON_TRANSIT:
		{
			result r = E_SUCCESS;

			Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
			FrameAnimator *pFrameAnimator = pFrame->GetFrameAnimator();

			Form *nextFrom = static_cast<Form*>(pFrame->GetControl(L"Form1"));
			if(pFrameAnimator->GetStatus() == ANIMATOR_STATUS_STOPPED)
			{
				pFrameAnimator->SetFormTransitionAnimation(FRAME_ANIMATOR_FORM_TRANSITION_ANIMATION_TRANSLATE_RIGHT,
									                       1000,
									                       ANIMATION_INTERPOLATOR_LINEAR );
				r = pFrameAnimator->SetCurrentForm (*nextFrom);
				if (IsFailed(r))
				{
					AppLog("SetCurrentForm on the Form1 Failed.\n");
					return;
				}
			}
		}
		break;
	default:
		break;
	}
}
 *	@endcode
 * 
 * 
 *
 */

namespace Animations
{
};

}; };

#endif /* _FUIANIMATIONS_H_ */
