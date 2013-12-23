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
 * @file		FUiCtrlFlashEnum.h
 * @brief		This is the header file for the %Flash enumerations.
 *
 * This header file contains the declarations of the %Flash enumerations.
 *
 * These enumerations define the various properties of the %Flash control.
 */
#ifndef _FUICTRL_FLASHENUM_H_
#define _FUICTRL_FLASHENUM_H_

namespace Osp { namespace Ui { namespace Controls {

/*
 * @define Flash Volume Level
 */
#define MIN_FLASH_VOLUME		0
#define MAX_FLASH_VOLUME		100
#define DEFAULT_FLASH_VOLUME	50

  /**
   * @enum 	FlashQuality
   *
   * Defines the quality of the flash.
   *
   * @since	1.0
   */
  typedef enum
  {
      FLASH_QUALITY_LOW,							/**< The playback quality is low */
      FLASH_QUALITY_MEDIUM,							/**< The playback quality is medium  */
      FLASH_QUALITY_HIGH							/**< The playback quality is high  */
  } FlashQuality;

  /**
   * @enum 	FlashRepeatMode
   * Defines the repeat modes of the flash.
   *
   * @since	1.0
   */
  typedef enum
  {
		FLASH_REPEAT_NONE,							/**< The Flash is played once without repeating */
		FLASH_REPEAT_LOOP							/**< The Flash is in loop mode*/
  } FlashRepeatMode;

	/**
   * @enum	FlashStatus
   * Defines the status of the flash.
   *
   * @since	1.0
   */
  typedef enum
  {
		FLASH_STOPPED,									/**< The Flash is in 'stopped' state */
		FLASH_PAUSED,									/**< The Flash is in 'paused' state */
		FLASH_PLAYING									/**< The Flash is in 'playing' state */
  } FlashStatus;

	/**
   * @enum 	FlashStyle
   * Defines the style of the flash.
   *
   * @since	1.0
   */
	typedef enum
	{
		FLASH_STYLE_NORMAL,								/**< The Flash control must have focus to play */
		FLASH_STYLE_PLAY_WITHOUT_FOCUS					/**< The Flash can play even when the control does not have focus */
	} FlashStyle;

}; }; }; // Osp::Ui::Controls

#endif
