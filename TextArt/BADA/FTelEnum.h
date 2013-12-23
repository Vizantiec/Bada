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
 * @file		FTelEnum.h 
 * @brief		This header file contains the enumerations used by the Telephony namespace.
 *
 * This header file contains the declarations of the enumerations of the Telephony namespace.
 */

#ifndef _FTEL_ENUM_H_
#define _FTEL_ENUM_H_


namespace Osp { namespace Telephony {

// Enumeration

/**
 * @enum CallType
 * Defines the type of the current call.
 *
 * @since 1.0
 */
enum CallType
{
	TYPE_UNDEFINED_CALL = -1,		/**< No defined type */
	TYPE_VOICE_CALL = 0, 			/**< The voice call type */
	TYPE_VIDEO_CALL					/**< The video call type */
};

/**
 * @enum CallStatus
 * Defines the current status of the calls.
 *
 * @since 1.0
 */
enum CallStatus
{
	CALL_STATUS_UNDEFINED = -1,										/**< No defined type */
	CALL_STATUS_IDLE = 0,											/**< No call is in progress */
	CALL_STATUS_ACTIVE,												/**< @deprecated This enum value is deprecated because an active status is divided into three, that is, communicating, ringing, and dialing */
	CALL_STATUS_COMMUNICATING,										/**< Voice or video calls are in progress @b since: @b 2.0 */
	CALL_STATUS_RINGING,											/**< An incoming voice or video call @b since: @b 2.0 */
	CALL_STATUS_DIALING												/**< An outgoing voice or video call @b since: @b 2.0 */
}; 


};};

#endif // _FTEL_ENUM_H_
