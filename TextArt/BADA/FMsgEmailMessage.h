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
 * @file		FMsgEmailMessage.h
 * @brief		This is the header file for the messaging classes.
 *
 * This header file contains the declarations of the %EmailMessage class.
 */

#ifndef _FMSG_EMAILMESSAGE_H_
#define _FMSG_EMAILMESSAGE_H_

// Includes
#include "FMsgIEmailListener.h"

namespace Osp { namespace Messaging {

	// Forward declaration
	class EmailEvent;
	class IMessagePi;

	// Forward declaration for class extension.
	class EmailMessageEx;

	/**
	* @class	EmailMessage
	* @brief	This class provides methods for handling email messages.
	* @since	1.0
	*
	* The %EmailMessage class provides methods for handling email messages.
	* It allows you to set the subject and body text of an email message,
	* and add or remove the files sent as email attachments.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _EXPORT_MSG_ EmailMessage :
		public Osp::Base::Object
	{
		// Lifecycle
	public:

		/**
		* This is the default constructor for this class.
		*
		* @since	1.0
		*/
		EmailMessage(void);

		/**
		* This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~EmailMessage(void);

		/**
		* This is the copy constructor for the %EmailMessage class.
		*
		* @since			1.0
		* @param[in]	value	An instance of %EmailMessage
		*/
		EmailMessage(const EmailMessage& value);


	public:
		/**
		* This assignment operator copies an email message from the specified instance of %EmailMessage to the calling instance of %EmailMessage.
		*
		* @since			1.0
		* @return			The reference of this instance
		* @param[in]	rhs		A reference to the %EmailMessage instance to be copied
		*/
		EmailMessage& operator =(const EmailMessage& rhs);


		// Operation
	public:
		/**
		* Sets the subject of the email.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	subject				The subject of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The subject length of the message exceeds the maximum limit (Maximum 256 characters),
	    *                                   	or the total size of the subject, body, and attachment(s) exceeds the maximum limit (5MB).
		* @see			GetSubject()
		*/
		result SetSubject(const Osp::Base::String& subject);

		/**
		* Sets the body of the message.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	text				The body of the message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The body length of the message exceeds the maximum limit (Maximum 2000 characters), 
		*                                   or the total size of the subject, body, and attachment(s) exceeds the maximum limit (5MB)
		* @see			GetText()
		*/
		result SetText(const Osp::Base::String& text);

		/**
		* Adds a file attachment to the email.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	filePath				The path of the file to attach
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			The length of the specified @c filePath is too long or @c 0.
		* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
		* @exception	E_FILE_ALREADY_EXIST	The file is already attached.
		* @exception	E_MAX_EXCEEDED			The total size of the subject, body, and attachment(s) exceeds the maximum limit (5MB), or
        *                                       the number of attachments exceeds the limit (20 files). @n
        *                                       The total size of attachments must not exceed 5MB, and the total number of attached files must not exceed 20 files.
		* @see			GetAttachmentListN()
		*/
		result AddAttachment(const Osp::Base::String &filePath);

		/**
		* Removes an attachment from an email.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	filePath				The path of the file to be removed
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_FILE_NOT_FOUND		The corresponding format file is not found.
		* @see			AddAttachment(), GetAttachmentListN()
		*/
		result RemoveAttachment(const Osp::Base::String &filePath);

		/**
		* Gets the subject of the message.
		*
		* @since		1.0
		* @return		The subject of the message
		* @see			SetSubject()
		*/
		Osp::Base::String GetSubject(void) const;

		/**
		* Gets the body of the message.
		*
		* @since		1.0
		* @return		The body of the message
		* @see			SetText()
		*/
		Osp::Base::String GetText(void) const;

		/**
		* Gets the list of attachments for the email.
		*
		* @since			1.0
		* @return			The list of the attached files
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.		
		* @remarks		The specific error code can be accessed using the GetLastResult() method.
		* @see			AddAttachment()
		*/
		Osp::Base::Collection::IList* GetAttachmentListN(void) const;


	private:
		/**
		* Gets the list of physical file path of attachments for the email.
		*
		* @since		1.0
		* @return		The list of physical file path of the attached files
		* @see			AddAttachment(), AddPhysicalAttachment()
		*/
		Osp::Base::Collection::IList* GetPhysicalAttachmentListN(void) const;

		/**
		* Adds a file attachment to the email. (Physical file path)
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	physicalFilePath		The path of the file to attach
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_ARG			The length of the specified @c filePath is too long or @c 0.
		* @exception	E_FILE_NOT_FOUND		The specified file cannot be found or accessed.
		* @exception	E_FILE_ALREADY_EXIST	The file is already attached.
		* @exception	E_MAX_EXCEEDED			Attachment is constrained to a maximum of 5MB and 20 files. @n
		*										The total size of the subject, body, and attachment(s) is exceeding the maximum limit (5MB).
		* @see			GetPhysicalAttachmentListN()
		*/
		result AddPhysicalAttachment(const Osp::Base::String &physicalFilePath);

	private:
		Osp::Base::String __subject;
		Osp::Base::String __text;
		Osp::Base::Collection::ArrayList* __attachmentList;
		long __totalFileSize;
		
		Osp::Base::DateTime 	__receivedTime;
		int						__uId;
		bool					__hasAttachment;
		bool					__isRead;
		EmailMessagePriority	__priority;
		int						__accountId;
		Osp::Base::String		__sender;

		// for class extension
	private:
		EmailMessageEx* __pEmailMessageEx;

		// friend class
		friend class __Message;
		friend class EmailMessageEx;
		friend class __EmailParcel;
	};
} // Messaging;
} // Osp;

#endif // _FMSG_EMAILMESSAGE_H_
