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
 * @file		FUiControls.h
 * @brief		This is the header file for the %Osp::Ui::Controls namespace.
 *
 * This header file contains the declarations and descriptions of the %Osp::Ui::Controls namespace.
 */
#ifndef _FUICTRL_H_
#define _FUICTRL_H_

// Includes
#include "FUiCtrlAlignmentEnum.h"
#include "FUiCtrlAnimation.h"
#include "FUiCtrlAnimationFrame.h"
#include "FUiCtrlBackgroundEnum.h"
#include "FUiCtrlButton.h"
#include "FUiCtrlCheckButton.h"
#include "FUiCtrlColorPicker.h"
#include "FUiCtrlContextMenu.h"
#include "FUiCtrlCustomList.h"
#include "FUiCtrlCustomListEnum.h"
#include "FUiCtrlCustomListItem.h"
#include "FUiCtrlCustomListItemFormat.h"
#include "FUiCtrlDatePicker.h"
#include "FUiCtrlDateTimePicker.h"
#include "FUiCtrlEditArea.h"
#include "FUiCtrlEditDate.h"
#include "FUiCtrlEditEnum.h"
#include "FUiCtrlEditField.h"
#include "FUiCtrlEditTime.h"
#include "FUiCtrlExpandableList.h"
#include "FUiCtrlFlash.h"
#include "FUiCtrlFlashEnum.h"
#include "FUiCtrlForm.h"
#include "FUiCtrlFrame.h"
#include "FUiCtrlFooter.h"
#include "FUiCtrlFooterItem.h"
#include "FUiCtrlForm.h"
#include "FUiCtrlGroupedList.h"
#include "FUiCtrlHeader.h"
#include "FUiCtrlHeaderItem.h"
#include "FUiCtrlIconList.h"
#include "FUiCtrlIconListEnum.h"
#include "FUiCtrlIconListView.h"
#include "FUiCtrlIconListViewEnum.h"
#include "FUiCtrlIconListViewItem.h"
#include "FUiCtrlIIconListViewItemEventListener.h"
#include "FUiCtrlIIconListViewItemProvider.h"
#include "FUiCtrlGallery.h"
#include "FUiCtrlGalleryEnum.h"
#include "FUiCtrlGalleryItem.h"
#include "FUiCtrlIGalleryEventListener.h"
#include "FUiCtrlIGalleryItemProvider.h"
#include "FUiCtrlInputEnum.h"
#include "FUiCtrlIScrollEventListener.h"
#include "FUiCtrlISliderEventListener.h"
#include "FUiCtrlScrollEventEnum.h"
#include "FUiCtrlKeypad.h"
#include "FUiCtrlLabel.h"
#include "FUiCtrlLabelEnum.h"
#include "FUiCtrlList.h"
#include "FUiCtrlListEnum.h"
#include "FUiCtrlListView.h"
#include "FUiCtrlListViewEnum.h"
#include "FUiCtrlMarginEnum.h"
#include "FUiCtrlMessageBox.h"
#include "FUiCtrlOptionMenu.h"
#include "FUiCtrlOverlayPanel.h"
#include "FUiCtrlOverlayRegion.h"
#include "FUiCtrlPanel.h"
#include "FUiCtrlPopup.h"
#include "FUiCtrlPositionEnum.h"
#include "FUiCtrlProgress.h"
#include "FUiCtrlRadioGroup.h"
#include "FUiCtrlScrollPanel.h"
#include "FUiCtrlSlidableList.h"
#include "FUiCtrlSlidableGroupedList.h"
#include "FUiCtrlSlider.h"
#include "FUiCtrlSliderEnum.h"
#include "FUiCtrlTab.h"
#include "FUiCtrlTabBar.h"
#include "FUiCtrlTabBarItem.h"
#include "FUiCtrlTimePicker.h"
#include "FUiCtrlICustomListElement.h"
#include "FUiCtrlIFrameEventListener.h"
#include "FUiCtrlListItemBase.h"
#include "FUiCtrlCustomItem.h"
#include "FUiCtrlSimpleItem.h"
#include "FUiCtrlListContextItem.h"
#include "FUiCtrlIListViewItemEventListener.h"
#include "FUiCtrlIListViewItemProvider.h"
#include "FUiCtrlIFastScrollListener.h"
#include "FUiCtrlICustomElement.h"
#include "FUiCtrlICustomListElement.h"
#include "FUiCtrlListContextItem.h"
#include "FUiCtrlIGroupedListViewItemEventListener.h"
#include "FUiCtrlIGroupedListViewItemProvider.h"
#include "FUiCtrlGroupItem.h"
#include "FUiCtrlGroupedListView.h"
#include "FUiCtrlSearchBar.h"
#include "FUiCtrlISearchBarEventListener.h"
#include "FUiCtrlTextBox.h"
#include "FUiCtrlExpandableEditArea.h"
#include "FUiCtrlIExpandableEditAreaEventListener.h"
#include "FUiCtrlITokenFilter.h"
#include "FUiCtrlIFormBackEventListener.h"

namespace Osp
{
/**
 * @namespace   Osp::Ui::Controls
 * @brief		This namespace contains the classes and interfaces for creating rich user interface components for the applications.
 * @since		1.0
 *
 * @remarks		@b Header @b %file: @b \#include @b <FUi.h> @n
 *				@b Library : @b FOsp
 *
 * The %Ui::Controls namespace contains classes that have graphical representations that can be displayed on the screen as UI elements and with
 * which the user can interact.
 *
 * For more information on the %Ui::Controls namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/controls.htm">UI Controls Guide</a>.
 *
 */

namespace Ui
{

namespace Controls
{

	/**
	* The system color for the text that appears in the indicator and the command area (for example, Header and Footer).
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_TITLE_TEXT;

	/**
	* The system color for the text that appears in controls, has a different background color than that of its parent (for example, Button).
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_BODY_TEXT;

	/**
	* The system default foreground color (for example, Label and CheckButton).
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_FOREGROUND;

	/**
	* The system default background color (for example, Label, Panel, and ScrollPanel).
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_BACKGROUND;

	/**
	* The system default color for the List background.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_LIST_BACKGROUND;

	/**
	* The system default color for the Form background.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_FORM_BACKGROUND;

	/**
	* The system default color for the background of the Form with grouped style child controls.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_FORM_GROUP_BACKGROUND;

	/**
	* The system default color for the Popup background.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_POPUP_BACKGROUND;

	/**
	* The system default color of the group item text.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_GROUP_ITEM_TEXT;

	/**
	* The system default color of the list text.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_LIST_ITEM_TEXT;

	/**
	* The system default color of the list item text, when an item is selected.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_LIST_ITEM_PRESSED_TEXT;

	/**
	* The system default color of the list element text when the item is highlighted.
	*
	* @since 		1.1
	* @remarks    	Different color values can be defined for different device models.
	*/
	/**
	* @htmlonly
	* <!--
	*/
	_EXPORT_CONTROLS_ 
	/**
	* -->
	* @endhtmlonly
	*/
	extern const Osp::Graphics::Color SYSTEM_COLOR_LIST_ITEM_HIGHLIGHTED_TEXT;

};// Osp::Ui::Controls
};// Osp::Ui
};// Osp
#endif// _FUICTRL_H_

