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
 * @file	FSclIRecordClearResultListener.h
 * @brief	This is the header file for the %IRecordClearResultListener interface.
 *
 * This header file contains the declarations of the %IRecordClearResultListener interface.
 */
#ifndef _FSCL_IRECORD_CLEAR_RESULT_LISTENER_H_
#define _FSCL_IRECORD_CLEAR_RESULT_LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FSclRecord.h"

namespace Osp { namespace Social { 


/**
 * @if PRIVCORE
 * @interface	IRecordClearResultListener
 * @brief		This interface represents a listener that receives events associated with the clear methods (type : Record::RemoveAllRecords).
 * @since		1.0
 *
 * @remarks		Addressbook::RemoveAllCategories, Addressbook::RemoveAllContacts, Calendarbook::RemoveAllEvents, Calendarbook::RemoveAllTodos
*
* The %IRecordClearResultListener interface represents a listener that receives events associated with the clear methods (type : Record::RemoveAllRecords).
 * @endif
 */
class  _EXPORT_SOCIAL_ IRecordClearResultListener:
	public Osp::Base::Runtime::IEventListener
{
// Operations
public:
	/**
     * Called to notify when all the records are cleared.
     *
     * @since			1.0
     * @param[in]		recordType		The @c #RecordType of the records cleared
     * @param[in]		r				The result of the request 
     * @exception		E_SUCCESS		The method is successful. 
	 * @exception		E_SYSTEM		A system error has occurred.
	 * @see				Addressbook::RemoveAllContacts(), Addressbook::RemoveAllCategories(), Calendarbook::RemoveAllEvents(), Calendarbook::RemoveAllTodos()
     */
	virtual void	OnAllRecordsCleared(RecordType recordType, result r) = 0;
};

};};// Osp::Social

#endif//_FSCL_IRECORD_CLEAR_RESULT_LISTENER_H_

