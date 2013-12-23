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
 * @file		FSclIRecordEventListener.h
 * @brief		This is the header file for the %IRecordEventListener interface.
 *
 * This header file contains the declarations of the %IRecordEventListener interface.
 */
#ifndef _FSCL_IRECORD_EVENT_LISTENER_H_
#define _FSCL_IRECORD_EVENT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FSclRecord.h"

namespace Osp { namespace Social { 

// Enums
/**
 * @enum RecordEventType 
 * Defines the record event types.
 *
 * @since 1.0
 */
enum RecordEventType {
	RECORD_ADDED,				/**< The adding of a new record */
	RECORD_UPDATED,				/**< The updating of a record */
	RECORD_REMOVED,				/**< The removal of a record */
	ALL_RECORDS_REMOVED,		/**< The removal of all records */
	MULTI_RECORDS_ADDED,		/**< The adding of multiple records  @b since: @b 1.1 */
	MULTI_RECORDS_UPDATED,		/**< The adding, updating, and/or removal of multiple records  @b since: @b 1.1 */
	MULTI_RECORDS_REMOVED		/**< The removal of multiple records  @b since: @b 1.1 */
};


/**
 * @interface	IRecordEventListener
 * @brief		This interface provides a listener that receives the events associated with the record.
 * @since		1.0 
 *
 * The %IRecordEventListener interface provides a listener that receives the events associated with the record.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/social_records.htm">Social Records</a>.
 */
class  _EXPORT_SOCIAL_ IRecordEventListener:
	public Osp::Base::Runtime::IEventListener
{
// Operations
public:
	/**
	 * Called to notify when a record in the data storage is changed externally.
	 *
	 * @since 		1.0
	 * @param[in]	eventType       		The operation type                  
	 * @param[in]	recordType      		The record type of the changed record
	 * @param[in]	record					The Record instance that has changed @n
	 *                                  	If the eventType is #RECORD_REMOVED, the %Record instance only has @c recordId and @c recordType but no data. @n
	 *                                  	When multiple records have changed (#MULTI_RECORDS_ADDED, #MULTI_RECORDS_UPDATED, #MULTI_RECORDS_REMOVED),
	 *                                  	the %Record instance is an invalid record instance with @c INVALID_RECORD_ID.
	 * @param[in]	pUpdatedProperties      The list of updated properties @n
	 *										For example, #ContactPropertyId, #CalEventPropertyId, and #CalTodoPropertyId. @n
	 *										It is available only if the specified @c eventType is #RECORD_UPDATED. @n
	 *										If not, the value is @c null. @n
	 *										The list consists of %LongLong class instances that have a property ID. @n
	 *										Currently, this parameter is not supported, do not use it.
	 * @param[in]	pUpdatedMultiProperties The list of updated properties @n
	 *										For example, #ContactMultiPropertyId. @n
	 *										It is available only if the specified @c eventType is #RECORD_UPDATED. @n
	 *										If not, the value is @c null. @n
	 *										The list consists of %LongLong class instances that have a property ID. @n
	 *										Currently, this parameter is not supported, do not use it.
	 * @remarks		If an application "A" changes a record, all the applications except "A" receive the change notification.
	 * @remarks		After using the @c pUpdatedProperties and @c pUpdatedMultiProperties, they must be deleted.
	 */
	virtual void    OnRecordChangedN(RecordEventType eventType, RecordType recordType, Record& record, Osp::Base::Collection::IList* pUpdatedProperties, Osp::Base::Collection::IList* pUpdatedMultiProperties) = 0;
};

};};// Osp::Social

#endif//_FSCL_IRECORD_EVENT_LISTENER_H_

