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
 * @file	FSclIRecordListener.h
 * @brief	This is the header file for the %IRecordListener interface.
 *
 * This header file contains the declarations of the %IRecordListener interface.
 */
#ifndef _FSCL_IRECORD__LISTENER_H_
#define _FSCL_IRECORD__LISTENER_H_

// Includes
#include "FBaseRtIEventListener.h"
#include "FBaseDataType.h"

namespace Osp { namespace Social { 

/**
 * @interface	IRecordListener
 * @brief		This interface represents a listener to asynchronously retrieve the records from the Calendarbook or Addressbook.
 * @since		1.0
 *
 * The %IRecordListener interface represents a listener to asynchronously retrieve the records from the Calendarbook or Addressbook.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/social/social_records.htm">Social Records</a>. 
 */
class  _EXPORT_SOCIAL_ IRecordListener:
	public Osp::Base::Runtime::IEventListener
{
// Operations
public:
	/**
	 * Called when the requested records are retrieved.
	 *
	 * @since		1.0
	 * @param[in]	reqId				The request ID
	 * @param[in]	pRecords			The result of a specific asynchronous method @n
	 * 									A list containing all of the retrieved #Record instances, @n
	 *									else an empty list if there are no retrieved records, or @c null if an exception occurs @n
	 * @param[in]	r					The result of the request
	 *										
	 * @exception	E_SUCCESS			The request is successful.
	 * @exception	E_OUT_OF_MEMORY 	The memory is insufficient.
	 * @exception	E_SYSTEM			An error has occurred on the local storage side.
	 * @remarks		After using @c pRecords, the application must delete it.
	 * @see			Calendarbook::GetEventInstances()
	 */
	virtual void    OnRecordsReceivedN(RequestId  reqId, Osp::Base::Collection::IList* pRecords, result r) = 0;
};

};};// Osp::Social

#endif//_FSCL_IRECORD__LISTENER_H_

