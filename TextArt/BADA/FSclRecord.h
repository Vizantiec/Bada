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
 * @file	FSclRecord.h
 * @brief	This is the header file for the %Record class.
 *
 * This header file contains the declarations of the %Record class.
 */
#ifndef _FSCL_RECORD_H_
#define _FSCL_RECORD_H_

// Includes
#include "FBaseColIList.h"
#include "FSclConfig.h"

namespace Osp { namespace Social {
	
// To make friendship.
class Addressbook;
class __AddressbookPi;
class Calendarbook;
class __CalendarbookPi;

/**
 * A unique ID. This ID is unique within a local storage only. @n
 * @c RecordId is assigned by the local storage (for example, Addressbook and Calendarbook) when a record is saved to the storage. @n
 * A newly constructed record instance has @c INVALID_RECORD_ID.
 *
 * @since	1.0
 */
typedef	long long RecordId;

// Enums & constants
/**
 * An invalid record ID. @n 
 * The record has not been properly recorded to Addressbook.
 *
 * @since	1.0
 */
const RecordId INVALID_RECORD_ID = -1;

/**
 * @enum RecordType
 * Defines the possible types of a record.
 *
 * @since	1.0
 */
enum RecordType {
	RECORD_TYPE_CONTACT = 0x01,		/**< The contact type */
	RECORD_TYPE_CATEGORY = 0x02,	/**< The category type */
	RECORD_TYPE_EVENT = 0x04,		/**< The event type */
	RECORD_TYPE_TODO = 0x08			/**< The to-do type */
};

/**
 * @class	Record
 * @brief	This class defines the general behavior of records used in the Social namespace. Users cannot create an instance directly from this
 * 			class. Instead, instantiate the classes derived from %Record.
 * @since	1.0
 * 
 * The %Record class defines the general behavior of records used in the Social namespace. Users cannot create an instance directly from this
 * 	class. Instead, instantiate the classes derived from %Record.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/social_records.htm">Social Records</a>.
 */
class  _EXPORT_SOCIAL_ Record:
	public Osp::Base::Object
{
	friend class Osp::Social::Addressbook;
	friend class Osp::Social::__AddressbookPi;
	friend class Osp::Social::Calendarbook;
	friend class Osp::Social::__CalendarbookPi;

// Construct Operations
protected:
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Initializes this instance of %Record with the specified type.
	 *
	 * @since	1.0
	 *
	 * @param[in]	type			The type of this record
	 */
	Record(RecordType type);

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~Record(void);

// Two phase construction idiom
protected:
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * This copy constructor does not work.
	 *
	 * @since	1.0
	 *
	 * @param[in]	type			The source instance of Record
	 */
	Record(const Record& value);
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * This assignment operator does not work.
	 *
	 * @since			1.0
	 *
	 * @param[in]	value		The source instance of Record
	 */
	Record&	operator =(const Record& value);

// Operations
public:
	/**
	 * Gets the type of the record.
	 *
	 * @since		1.0
	 * @return		The type of the record
	 */
	RecordType	GetRecordType(void) const;

	/**
	 * Gets the local-wide unique ID of the current instance of %Record. @n
	 * The @c RecordId is assigned by an address book when a record is added to it. @n
	 * A newly constructed record instance has @c INVALID_RECORD_ID.
	 *
	 * @since		1.0
	 * @return		The ID of the record
	 */
	RecordId	GetRecordId(void) const;

protected:
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Type of this record
	 *
	 * @since			1.0
	 */
	RecordType		__recordType;
	
	/**
	 * @internal This data member is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * ID of this record
	 *
	 * @since			1.0
	 */	
	RecordId		__id;

protected:
	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Sets the Id of this record
	 *
	 * @since			1.0
	 * @param[in]	recordID					The ID of this record
	 */
	void	SetRecordId(RecordId recordID);
	
private:
	friend class RecordEx;
	class RecordEx* __pRecordEx;

};

};};// Osp::Social

#endif//_FSCL_RECORD_H_

