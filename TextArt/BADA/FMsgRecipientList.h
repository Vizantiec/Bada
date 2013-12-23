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
 * @file		FMsgRecipientList.h
 * @brief		This is the header file for the messaging classes.
 *
 * This header file contains the declarations of the %RecipientList class.
 */

#ifndef _FMSG_RECIPIENTLIST_H_
#define _FMSG_RECIPIENTLIST_H_

// Includes
#include "FBase.h"
#include "FMsgCommon.h"


namespace Osp { namespace Messaging {

	// Forward declaration
	class SmsManager;
	class MmsManager;
	class EmailManager;

	// Forward declaration for class extension.
	class RecipientListEx;

	/**
	* @class	RecipientList
	* @brief	This class provides the abstract data type and methods for handling recipients.
	* @since	1.0
	*
	* The %RecipientList class provides methods for handling message recipients. It allows you to add, remove, set,
	* and get the list of recipients. A recipient is an email address for an email message and a telephone number
                   * for an SMS or MMS message.
	*
	* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/messaging/messaging.htm">Messaging Guide</a>.

	*/
	class _EXPORT_MSG_ RecipientList :
		public Osp::Base::Object
	{
		// Lifecycle
	public:
		/**
		* This is the default constructor for this class.
		*
		* @since	1.0
		*/
		RecipientList(void);

		/**
		* This is the copy constructor for the %RecipientList class.
		*
		* @since			1.0
		* @param[in]	value	An instance of %RecipientList
		*/
		RecipientList(const RecipientList& value);

		/**
		*	This is the destructor for this class.
		*
		* @since	1.0
		*/
		virtual ~RecipientList(void);

	// Operator
	public:
		/**
		* This is the assignment operator for this class. @n
		* Copies the recipient list from the specified instance of %RecipientList to the calling instance of %RecipientList.
		*
		* @since			1.0
		* @param[in]	rhs		A reference to this %RecipientList instance
		*/
		RecipientList& operator =(const RecipientList& rhs);

		/**
		* This operator compares the two recipient lists.
		*
		* @since		1.0
		* @return		@c true if both instances are equal, @n
		*				else @c false
		* @param[in]	rhs		A reference to the %RecipientList instance on the right-hand side of the operator
		*/
		bool operator ==(const RecipientList& rhs) const;

		/**
		*	Gets the hash value of the current instance.
		*
		* @since		1.0
		*	@return		The hash value of the current instance
		*	@remarks 	Two equal instances should return the same hash value. For better performance,
		*				the used hash function must generate a random distribution for all inputs.
		*/
		virtual int GetHashCode(void) const;

	// Operation
	public:
		/**
		* Compares the specified instance with the calling instance.
		*
		* @since		1.0
		* @return		@c true if both instances are equal, @n
		*				else @c false
		* @param[in]	value		An instance of %RecipientList
		*/
		virtual bool Equals(const Osp::Base::Object& value) const;
		/**
		* Adds a recipient string.
		*
		* @since	1.0
		* @return		An error code
		* @param[in]	type				The type of recipient
		* @param[in]	recipient			The recipient string
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_OBJ_ALREADY_EXIST	The specified @c recipient is already added.
		* @exception	E_INVALID_ARG		The specified @c recipient string length is too short (< 3) or too long (> 320), or
		* 									the specified @c type is invalid.
		* @remarks		The limit of the number of recipients is not checked in this method. This is done in the Send() method of each manager class (SmsManager, MmsManager, and EmailManager).
		* 				The minimum length of a recipient is @c 3 for a phone number and @c 5 for an email address.
		* 				The maximum length of a recipient is @c 41 for a phone number and @c 320 for an email address.
		* @see			Set(), GetListN(), SmsManager::Send(), MmsManager::Send(), EmailManager::Send()
		*/
		result Add(RecipientType type, const Osp::Base::String& recipient);

		/**
		* Removes the recipient.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	type			The type of recipient
		* @param[in]	recipient		The recipient string
		* @exception	E_SUCCESS		The method is successful.
		* @exception	E_INVALID_ARG	The specified @c recipient string length is too short (< 3) or too long (> 320), or
		* 								the specified @c type is invalid.
		* @exception	E_OBJ_NOT_FOUND	The specified @c recipient does not exist.
		* @see			Add()
		*/
		result Remove(RecipientType type, const Osp::Base::String& recipient);


		/**
		* Sets a recipient list.
		*
		* @since			1.0
		* @return			An error code
		* @param[in]	type				The type of recipient
		* @param[in]	list				A list of recipient strings
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_INVALID_ARG		The length of one of the recipients in the list is too short (< 3) or too long (> 320), or
		* 									the specified @c type is invalid.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_OBJ_ALREADY_EXIST	A duplicate recipient in the recipient list already exists.
		* @remarks		The limit of recipients is not checked in this method.
		*				This is done in the Send() method of each manager class (SmsManager, MmsManager, and EmailManager).
		* @see			Add(), GetListN()
		*/
		result Set(RecipientType type, const Osp::Base::Collection::IList& list);

		/**
		* Gets the recipient list of the specific recipient type.
		*
		* @since			1.0
		* @return			A pointer to the list of recipient type
		* @param[in]	type				The type of recipient
		* @exception	E_SUCCESS			The method is successful.
		* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
		* @exception	E_INVALID_ARG		The specified @c type is invalid.
		* @remarks		The recipient is an email address for an email message or a telephone number for an SMS or MMS message. The specified @c type contains RECIPIENT_TYPE_TO, RECIPIENT_TYPE_CC, RECIPIENT_TYPE_BCC.
		* 				The specific error code can be accessed using the GetLastResult() method.
		* @see			Add(), Set()
		*/
		Osp::Base::Collection::IList* GetListN(RecipientType type);

		// Operation
	private:

		/**
		* Returns the number of recipients ( To + Cc + Bcc ).
		*
		* @return		The number of total recipient count
		*/
		int GetTotalRecipientCount(void) const;

		/**
		* Clear all recipients ( To + Cc + Bcc ).
		*
		*/
		void ClearAllRecipients(RecipientType type);

	private:
		Osp::Base::Collection::ArrayList*	__pRecipientList;
		Osp::Base::Collection::ArrayList*	__pRecipientCcList;
		Osp::Base::Collection::ArrayList*	__pRecipientBccList;

		// for class extension
	private:
		RecipientListEx* __pRecipientListEx;

		// friend class
		friend class SmsManager;
		friend class MmsManager;
		friend class EmailManager;
		friend class RecipientListEx;
	};

};
};

#endif // _FMSG_RECIPIENTLIST_H_
