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
 * @file		FMsgMmsMessage.h
 * @brief		This is the header file for the messaging classes.
 *
 * This header file contains the declarations of the %MmsMessage class.
 */

#ifndef _FMSG_MMSMESSAGE_H_
#define _FMSG_MMSMESSAGE_H_

// Includes
#include "FMsgIMmsListener.h"

namespace Osp { namespace Messaging {

	/**
	* @enum MmsAttachmentFormat
	* Defines all the MMS attachment types.
	*
	* @since	1.0
	*/
	enum MmsAttachmentFormat
	{
		MMS_IMAGE = 0,		/**< The image type */
		MMS_AUDIO,			/**< The audio type */
		MMS_VIDEO,			/**< The video type */
		MMS_VCARD,			/**< The vCard type @b since: @b 2.0*/
		MMS_VCALENDAR		/**< The vCalendar type @b since: @b 2.0*/
	};

	// Forward declaration.
	class MmsEvent;
	class IMessagePi;

	// Forward declaration for class extension.
	class MmsMessageEx;

	/**
	* @class	MmsMessage
	* @brief	This class provides the methods for handling an MMS message.
	* @since	1.0
	*
	* The %MmsMessage class provides methods for handling MMS messages. It allows you to set
	* the subject and body text of an MMS message, and add or remove the files sent as MMS attachments.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.
	*/
	class _EXPORT_MSG_ MmsMessage :
		public Osp::Base::Object
	{
		// Lifecycle
	public:

		/**
		*	This is the default constructor for this class.
		*
		* @since	1.0
		*/
		MmsMessage(void);

		/**
		*	This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~MmsMessage(void);

		/**
		* This is the copy constructor for the %MmsMessage class.
		*
		* @since			1.0
		* @param[in]	value	An instance of %MmsMessage
		*/
		MmsMessage(const MmsMessage& value);

		/**
		* This assignment operator copies an MMS message from the specified instance of %MmsMessage to the calling instance of %MmsMessage.
		*
		* @since	1.0
		* @return		A reference to the %MmsMessage instance
		* @param[in]	rhs		A reference to the %MmsMessage instance to be copied
		*/
		MmsMessage& operator =(const MmsMessage& rhs);

		// Operation

	public:

		/**
		* Sets the subject of the MMS message.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	subject				The subject of the MMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The subject length of the message exceeds the maximum limit (Maximum 40 characters). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetSubject()
		*/
		result SetSubject(const Osp::Base::String& subject);

		/**
		* Sets the body of the MMS message.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	text				The body of the MMS message
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_MAX_EXCEEDED		The body length of the message exceeds the maximum limit (Maximum 1000 characters). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetText()
		*/
		result SetText(const Osp::Base::String& text);

		/**
		* Adds the attachment of the specific type.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	format				The format of the attachment
		* @param[in]	filePath			The path of the file to attach
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
		* @exception	E_INVALID_ARG		Either of the following conditions has occurred: @n
		*									- The length of the specified @c filePath is too long or @c 0. @n
		* 									- The specified file format is already attached. @n
		* 									- The specified @c format is invalid. @n
		* 									- The specified file contains invalid or the media is not supported. @n
		* 									- The specified file format cannot be attached.@n
		* 									(An MMS attachment may contain either an image, audio, video, vCard, or a vCalendar file or a combination of an image, audio, vCard, and vCalendar file. @n
		* 									MMS attachments cannot contain a video file in combination with an image or audio file.)
		* @exception	E_MAX_EXCEEDED		The size of the file exceeds the maximum limit (Maximum 295KB). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetAttachment()
		*/
		result AddAttachment(MmsAttachmentFormat format, const Osp::Base::String &filePath);

		/**
		* Gets the subject of the MMS message.
		*
		* @since		1.0
		* @return		The subject of the MMS message
		* @see			SetSubject()
		*/
		Osp::Base::String GetSubject(void) const;

		/**
		* Gets the body of the MMS message.
		*
		* @since	1.0
		* @return		The body of the MMS message
		* @see			SetText()
		*/
		Osp::Base::String GetText(void) const;

		/**
		* Gets the attachment file of the specific type.
		*
		* @since			1.0
		* @return			The path of the attached file
		* @param[in]	format					The format of the attachment
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_CONDITION		The file is not attached.
		* @exception	E_INVALID_ARG			The specified @c format is invalid.
		* @remarks  	The specific error code can be accessed using the GetLastResult() method.
		* @see			AddAttachment()
		*/
		Osp::Base::String GetAttachment(MmsAttachmentFormat format) const;

		/**
		* Removes the attachment of the specific type.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	format					The format of the attachment to remove
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_FILE_NOT_FOUND		The corresponding format file is not found.
		* @exception	E_INVALID_ARG			The specified @c format is invalid.
		* @see			AddAttachment(), GetAttachment()
		*/
		result RemoveAttachment(MmsAttachmentFormat format);

	private:

		/**
		* Checks the existence of the previous attachment file according to the file format.
		*
		* @return		An error code
		* @param[in]	format				The format of the attachment
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		A specified input parameter is invalid.
		*/
		result CheckPreviousAttachment(MmsAttachmentFormat  format);


		/**
		* Sets the file path to the attachment file path according to the format.
		*
		* @return		An error code
		* @param[in]	format				The format of the attachment
		* @param[in]	filePath			The Input file path
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		A specified input parameter is invalid.
		*/
		result SetAttachmentPath(const MmsAttachmentFormat  format, const Osp::Base::String& filePath);

		/**
		* Gets the physical attachment file path of the specific type.
		*
		* @return		The path of the attached file
		* @param[in]	format					The format of the attachment
		* @exception	E_SUCCESS				The method is successful.
		* @exception	E_INVALID_CONDITION		No file is attached.
		* @exception	E_INVALID_ARG			There is no file of the specified @c format.
		* @remarks  	The specific error code can be accessed using the GetLastResult() method.
		* @see			AddAttachment()
		*/
		Osp::Base::String GetPhysicalAttachment(MmsAttachmentFormat format) const;

		/**
		* Adds the attachment of the specific type. (Physical file path)
		*
		* @return			An error code
		* @param[in]	format				The format of the attachment
		* @param[in]	physicalFilePath	The physical path of the file to attach
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_FILE_NOT_FOUND	The specified file cannot be found or accessed.
		* @exception	E_INVALID_ARG		The length of the specified @c physicalFilePath is too long or @c 0. @n
		* 									The specified file format is already attached. @n
		* 									The specified @c format is invalid. @n
		* 									The specified file contains invalid or unsupported media. @n
		* 									The specified file format cannot be attached. @n
		* 									(An MMS attachment may contain either an image, audio, video, vCard, or a vCalendar file or a combination of an image, audio, vCard, and vCalendar file. @n
		* 									MMS attachments cannot contain a video file in combination with an image or audio file.)
		* @exception	E_MAX_EXCEEDED		The size of the file exceeds the maximum limit (Maximum 295KB). @n
		* 									The total size of the subject, body, and attachment(s) exceeds the maximum limit (295KB).
		* @see			GetPhysicalAttachment()
		*/
		result AddPhysicalAttachment(MmsAttachmentFormat format, const Osp::Base::String &physicalFilePath);


	private:
		Osp::Base::String __subject;
		Osp::Base::String __text;
		Osp::Base::String __imageFilePath;
		Osp::Base::String __audioFilePath;
		Osp::Base::String __videoFilePath;
		Osp::Base::String __imagePhysicalFilePath;
		Osp::Base::String __audioPhysicalFilePath;
		Osp::Base::String __videoPhysicalFilePath;
		int __remainMsgSize;

		// for class extension
	private:
		MmsMessageEx* __pMmsMessageEx;

		// friend class
		friend class __Message;
		friend class MmsMessageEx;
		friend class __MmsParcel;
	};
};};

#endif // _FMSG_MMSMESSAGE_H_
