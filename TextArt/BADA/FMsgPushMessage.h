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
 * @file		FMsgPushMessage.h 
 * @brief		This is the header file for the %PushMessage class.
 *
 * This header file contains the declarations of the %PushMessage class.
 */

#ifndef _FMSG_PUSHMESSAGE_H_
#define _FMSG_PUSHMESSAGE_H_

// Includes
#include "FBase.h"
#include "FMsgConfig.h"

namespace Osp { namespace Messaging {
	// Forward declaration
	class __MsgUtil;

	// Forward declaration for class extension.
	class PushMessageEx;

	/**
	* @class	PushMessage
	* @brief	This class provides the methods for handling a push message.
	* @since	2.0
	*
	* The %PushMessage class provides methods for handling a push messages. It allows you to get the body text and
	* received time of a push message.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _EXPORT_MSG_ PushMessage :
		public Osp::Base::Object
	{
		// Lifecycle
	private:
		/*
		* This is the default constructor for this class.
		*/
		PushMessage(void);

		/*
		* This is the default constructor for this class.
		*
		* @param[in]	dateTime	The date and time (UTC time) when the message is received
		* @param[in]	text		The message body text
		*/
		PushMessage(Osp::Base::DateTime& dateTime, Osp::Base::String& text);

	public:
		/**
		* This is the destructor for this class.
		*
		* @since		2.0
		*/
		virtual ~PushMessage(void);

	private:
		PushMessage(const PushMessage& value);
		PushMessage& operator =(const PushMessage& value);

		// Operation
	public:
		/**
		* Gets the date and time (UTC time) of the message when it is received.
		*
		* @since		2.0
		* @return		The date and time (UTC time) when the message is received
		*/
		Osp::Base::DateTime GetReceivedTime(void) const;

		/**
		* Gets the body of the message.
		*
		* @since		2.0
		* @return		The body of the message
		*/
		Osp::Base::String GetText(void) const;

		// Attributes
	private:
		Osp::Base::DateTime	__dateTime;
		Osp::Base::String	__text;

		// for class extension
	private:
		class PushMessageEx* __pPushMessageEx;

		// friend class
		friend class __MsgUtil;
		friend class PushMessageEx;
	};
};
};

#endif // _FMSG_PUSHMESSAGE_H_
