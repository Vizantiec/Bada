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
 * @if PRIVCORE
 * @file		FSclLifelog.h
 * @brief		This is the header file for the %Lifelog class.
 *
 * This header file contains the declarations of the %Lifelog class.
 * @endif
 */
#ifndef _FSCL_LIFE_LOG_H_
#define _FSCL_LIFE_LOG_H_

// Includes
#include "FSclConfig.h"
#include <FSclActivity.h>

struct ILifelog;

namespace Osp { namespace Social {

/**
 * @if PRIVCORE
 * The maximum length of the filter of %Lifelog.
 *
 * @since		2.0
 *
 * @privlevel	CORE
 *
 * @endif
 */
static const int MAX_FILTER_LENGTH = 2048;

/**
 * @if PRIVCORE
 * @class	Lifelog
 * @brief	This class enables the browsing of the activity log data of the user.
 * @since	2.0
 * @privlevel	CORE
 *
 * The %Lifelog class enables the browsing of the activity log data of the user.
 *
 * The following example demonstrates how to use the %Lifelog class.
 * @code
		#include <FSocial.h>

		using namespace Osp::Base;
		using namespace Osp::Social;

		result
		MyCallLog::DisplayLog(String phoneNumber)
		{
			result r; // For error checking.
			IEnumerator*    pEnum = NULL;
			CallDirection	direction;
			DateTime		timestamp;
			int				duration;
			int		    intDirection;
			// Creates a Call Log.
			Lifelog lifeLog;
			lifeLog.Construct(ACTIVITY_CALL);

			// Sets the filter statement in Lifelog.
			String filter(L"CLOG_PHONE_NUMBER = '");
			filter += phoneNumber;
			filter += L"'";
			r = lifeLog.SetFilter(filter);
			if (IsFailed(r))
				goto EXCEPTION;

			r = lifeLog.SetSortOrder(CLOG_PHONE_NUMBER, SORT_ORDER_ASCENDING, CLOG_TIMESTAMP, SORT_ORDER_DESCENDING);
			if (IsFailed(r))
				goto EXCEPTION;

			 // Uses enumerator to access elements in the list.
			pEnum = lifeLog.GetEnumeratorN();
			while (pEnum->MoveNext() == E_SUCCESS)
		    {
	            Activity* pActivity = (Activity *)pEnum->GetCurrent();
		        if (NULL == pActivity)
			    {
				    delete pEnum;
					r = GetLastResult();
	                goto EXCEPTION;
		        }

				timestamp =	pActivity->GetTimestamp();
				pActivity->GetValue(CLOG_DIRECTION, intDirection);
        			direction = (CallDirection)intDirection;
				pActivity->GetValue(CLOG_DURATION, duration);

				// Display on UI.
				this->DisplayLog(direction, phoneNumber, duration, timestamp);

			}

			// Deletes the enumerator.
	        delete pEnum;

		EXCEPTION:
			return r;
		}
 *
 * @endcode
 *
 * @endif
 */
class  _EXPORT_SOCIAL_ Lifelog:
		public Osp::Base::Object
{

public:

	/**
	 * @if PRIVCORE
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @endif
	 */
	Lifelog();

	/**
	* @if PRIVCORE
	* This is the destructor for this class.
	*
	* @since		2.0
	* @privlevel	CORE
	* @endif
	*/
	~Lifelog(void);

	/**
	* @if PRIVCORE
	* Initializes this instance of %Lifelog.
	*
	* @since		2.0
	* @privlevel	CORE
	*
	* @return		An error code
	* @param[in]	activityType		The type of the activity
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @endif
	*/
	result Construct(ActivityType activityType);


	/**
	* @if PRIVCORE
	* Initializes this instance of %Lifelog with the specified activity type, start date/time, and end date/time. @n
	* The start/end time is the UTC time. @n
	* It is not necessary that the start date/time should be earlier than the end date/time.
	*
	* @since		2.0
	* @privlevel	CORE
	*
	* @return		An error code
	* @param[in]	activityType		The type of activity
	* @param[in]	startTime			The start date/time
	* @param[in]	endTime				The end date/time
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has already been constructed.
	* @endif
	*/
	 result Construct(ActivityType activityType, const Osp::Base::DateTime &startTime, const Osp::Base::DateTime &endTime);


private:
	Lifelog(const Lifelog& value);
	Lifelog&	operator =(const Lifelog& value);



public:

	/**
	 * @if PRIVCORE
	 * Gets the activity type.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		The activity type
	 *
	 * @endif
	 */
	ActivityType GetActivityType(void) const;


	/**
	 * @if PRIVCORE
	 * Sets a filter statement to control the output. @n
	 * In general, a filter is used to construct the 'WHERE' clause of an SQL statement based on the content of the fields of the filter. @n
	 * The fields of the filter correspond to the property names in an Activity class.
	 *
	 * @code
	 *
	 *	[propertyName][operator][value]([AND/OR][propertyName][operator][value],...)
	 *
	 *	ex)
	 *		- Comparison operation
	 *			- exact matching: "CLOG_PHONE_NUMBER = '082123456'"
	 *			- comparison matching: "CLOG_DURATION > 10"
	 *			- LIKE operator  "CLOG_PHONE_NUMBER LIKE '%1234%'"
	 *		- Boolean operation (AND, OR)
	 *			- "CLOG_PHONE_NUMBER = '082123456' AND CLOG_DURATION > 10"
	 * @endcode
	 *
	 * This is a sample code.
	 * @code
	 *   result sampleApp::FilterByName(String phoneNumber)
	 *	 {
	 *		result r;
	 *		Lifelog* myLifelog = this->__myLifeLog;
	 *		String filter(L"CLOG_PHONE_NUMBER = '");
	 *		filter += phoneNumber;
	 *		filter += L"'";
	 *		r = myLifelog->SetFilter(filter);
	 *		return r;
	 *	
	 * 	 }
	 *
	 *	 result sampleApp::ResetFilter()
	 *	 {
	 *		result r;
	 *		r = myLifelog->ResetFilter();
	 *		return r;
	 *	 }
	 * @endcode
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @param[in]	filter				A string of the filter statement
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c filter is invalid or not supported, or @n
	 * 							  		the length of the value exceeds the maximum allowable length for the filter (#MAX_FILTER_LENGTH).
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method. 
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
	 *
	 * @endif
	 */
	result	SetFilter(const Osp::Base::String& filter);

	/**
	 * @if PRIVCORE
	 * Resets the filter of %Lifelog.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		 	The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS 	Access is denied due to insufficient permission.
	 * @endif
	 */
	result	ResetFilter(void);

	/**
	 * @if PRIVCORE
	 * Sets the SortOrder property to control the output. @n
	 * Based on the order set, the output data is sorted when it is retrieved by the Get() method. @n
	 * The @c propertyId has a different value for each activity type.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @param[in]	propertyId			The property ID of the value in activity
	 * @param[in]	order				The sort order
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @see			Osp::Social::Activity, Osp::Social::ActivityType
	 *
	 * @endif
	 */
	result SetSortOrder(int propertyId, Osp::Base::SortOrder order);

	/**
	 * @if PRIVCORE
	 * Sets the SortOrder property to control the output. @n
	 * Based on the order set, the output data is sorted when it is retrieved by the Get() method. @n
	 * The @c propertyId has a different value for each activity type.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @param[in]	propertyId1			The first property ID of the value in activity
	 * @param[in]	order1				The sort order
	 * @param[in]	propertyId2			The second property ID of the value in activity
	 * @param[in]	order2				The sort order
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
	 * @endif
	 */
	result SetSortOrder(int propertyId1, Osp::Base::SortOrder order1, int propertyId2, Osp::Base::SortOrder order2);

	/**
	 * @if PRIVCORE
	 * Resets the SortOrder property of the %Lifelog instance. 
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @exception	E_SUCCESS		 	The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 *
	 * @endif
	 */
	result	ResetSortOrder(void);

	/**
	* @if PRIVCORE
	* Gets the number of logs in the %Lifelog instance. @n
	* If the log is filtered by SetFilter(), this method returns the count of the filtered data in the log.
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	PRIVILEGED_LIFELOG
	*
	* @return		An error code
	* @param[out]	value				The count of the log
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	* @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	* @endif
	*/
	result	GetCount(int &value) const;

	/**
	 * @if PRIVCORE
	 * Gets an enumerator (an instance of the IEnumerator-derived class) of Activity of the current instance of %Lifelog. @n
	 *
	 * If the %Lifelog is filtered by SetFilter(), this method returns the filtered data in %Lifelog.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An enumerator of %Activity of the current instance of %Lifelog, @n
	 *				else @c null if an exception occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method. @n
	 * 				Iterating over a list is not a thread-safe operation. Other threads could modify the list. @n
	 *				To obtain an exclusive ownership, the list must be locked during the entire iteration.
	 * @see			Osp::Social::Activity, Osp::Social::ActivityType
	 * @endif
	 */
	Osp::Base::Collection::IEnumerator* GetEnumeratorN(void) const;


	/**
	 * @if PRIVCORE
	 * Gets the summation of the values of the specified property ID. @n
	 * The @c propertyId has a different value for each activity type. @n
	 * The supported property IDs are CLOG_DURATION, MSGLOG_LOCATION_DATA_AGE, APPULOG_DURATION, APPULOG_LOCATION_DATA_AGE, @n
	 * APPILOG_LOCATION_DATA_AGE, MUSICLOG_LENGTH, MUSICLOG_ELAPSEDTIME, MUSICLOG_LOCATION_DATA_AGE, VIDEOLOG_LENGTH, @n
	 * VIDEOLOG_ELAPSEDTIME, VIDEOLOG_LOCATION_DATA_AGE, and LOC_LOG_SPEED.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @param[in]	propertyId			The property ID
	 * @param[out]  value				The sum of the values of the specified property ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	 	The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type, or @n
	 *									an arithmetic operation is not applicable to the specified @c propertyId.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
	 * @endif
	*/
	result GetSum(int propertyId, int &value) const;

	/**
	 * @if PRIVCORE
	 * Gets the average of the values of the specified property ID. @n
	 * The @c propertyId has a different value for each activity type. @n
	 * The supported property IDs are CLOG_DURATION, MSGLOG_LOCATION_DATA_AGE, APPULOG_DURATION, APPULOG_LOCATION_DATA_AGE, @n
	 * APPILOG_LOCATION_DATA_AGE, MUSICLOG_LENGTH, MUSICLOG_ELAPSEDTIME, MUSICLOG_LOCATION_DATA_AGE, VIDEOLOG_LENGTH, @n
	 * VIDEOLOG_ELAPSEDTIME, VIDEOLOG_LOCATION_DATA_AGE, and LOC_LOG_SPEED.
	 *	
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An error code
	 * @param[in]	propertyId			The property ID
	 * @param[out]	value				The average of the values of the specified property ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	 	The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type, or @n
	 *									an arithmetic operation is not applicable to the specified @c propertyId.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
	 * @endif
	*/
	result GetAverage(int propertyId, double &value) const;

	/**
	 * @if PRIVCORE
	 * Gets the activities with the maximum value of the specified property ID. @n
	 * The @c propertyId has a different value for each activity type. @n
	 * The supported property IDs are CLOG_DURATION,  MSGLOG_LOCATION_DATA_AGE, APPULOG_DURATION, APPULOG_LOCATION_DATA_AGE, @n
	 * APPILOG_LOCATION_DATA_AGE, MUSICLOG_LENGTH, MUSICLOG_ELAPSEDTIME, MUSICLOG_LOCATION_DATA_AGE, VIDEOLOG_LENGTH, @n
	 * VIDEOLOG_ELAPSEDTIME, VIDEOLOG_LOCATION_DATA_AGE, and LOC_LOG_SPEED.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An enumerator of activity
	 * @param[in]	propertyId			The property ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	 	The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type, or @n
	 * 									an arithmetic operation is not applicable to the specified property ID.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
 	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
	 * @endif
	 */
	Osp::Base::Collection::IEnumerator*	FindMaxLogsN(int propertyId) const;

	/**
	 * @if PRIVCORE
	 * Gets the activities with the minimum value of the specified property ID. @n
	 * The @c propertyId has a different value for each activity type. @n
	 * The supported property IDs are CLOG_DURATION,  MSGLOG_LOCATION_DATA_AGE, APPULOG_DURATION, APPULOG_LOCATION_DATA_AGE, @n
	 * APPILOG_LOCATION_DATA_AGE, MUSICLOG_LENGTH, MUSICLOG_ELAPSEDTIME, MUSICLOG_LOCATION_DATA_AGE, VIDEOLOG_LENGTH, @n
	 * VIDEOLOG_ELAPSEDTIME, VIDEOLOG_LOCATION_DATA_AGE, and LOC_LOG_SPEED.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
	 * @return		An enumerator of activity
	 * @param[in]	propertyId			The property ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	 	The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type, or @n
	 * 									an arithmetic operation is not applicable to the specified @c propertyId.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
 	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
	 * @endif
  	 */
    Osp::Base::Collection::IEnumerator*	FindMinLogsN(int propertyId) const;

	/**
	 * @if PRIVCORE
	 * Gets the most frequently occurring value of the specified property ID. @n
	 * The @c propertyId has a different value for each activity type.
	 *
	 * This is a sample code.
	 * @code
	 * result sampleApp::DisplayMostCall(int count)
	 * {
	 *	 result r;
     *   IEnumerator*    pEnum = NULL;
	 *
	 *	 Lifelog myLifelog;
	 *	 myLifelog.Construct(ACTIVITY_CALL);
	 *
	 *	 pEnum = myLifelog.GetMostOccurredValuesN(CLOG_PHONE_NUMBER, count);
	 *	 while (pEnum->MoveNext() == E_SUCCESS)
	 *	 {
	 *		Activity* pActivity = null;
	 *		pActivity = (Activity *)pEnum->GetCurrent();
	 *		// This activity instance has only a CLOG_OCCURRED_COUNT and a CLOG_PHONE_NUMBER of requested property.
	 *
	 *		String phoneNumber;
	 *		int	OccurredCount;
	 *		// Gets the phone number of the occurred call.
	 *		pActivity->GetValue(CLOG_PHONE_NUMBER, phoneNumber);
	 *		// Gets the count of the occurred call.
	 *		pActivity->GetValue(CLOG_OCCURRED_COUNT, OccurredCount);
	 *
     *		this->DisplayMostCall(phoneNumber,OccurredCount);
	 *
	 *	 }
	 *	 // Deletes the enumerator.
	 *   delete pEnum;
	 * }
	 * @endcode
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 * @privgroup	PRIVILEGED_LIFELOG
	 *
 	 * @return		An enumerator of value of the specified property ID
	 * @param[in]	propertyId			The property ID
	 * @param[in]	count				The desired maximum number of result items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_MEMORY	 	The memory is insufficient.
	 * @exception	E_INVALID_ARG		The specified @c propertyId is not contained in the current activity type.
	 * @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	 * @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	 * @exception	E_ILLEGAL_ACCESS	Access is denied due to insufficient permission.
	 * @remarks		The specific error code can be accessed using the GetLastResult() method.
	 * @see 		Osp::Social::Activity, Osp::Social::ActivityType
 	 *
	 *
	 * @endif
	*/
	Osp::Base::Collection::IEnumerator*	GetMostOccurredValuesN(int propertyId, int count) const;

private:
	static bool __locationLogPermision;
	static bool __cellInfoLogPermision;
	static bool __callLogPermision;
	static bool __msgLogPermision;
	static bool __appUsageLogPermision;
	static bool __appInstallationLogPermision;
	static bool __musicLogPermision;
	static bool __videoLogPermision;
	static bool __webBrowsingLogPermision;
	static bool __webSearchLogPermision;

public:
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the location activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_LOCATION_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS              The method is successful.
	 * @exception   E_PRIVILEGE_DENIED     The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetLocationLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the cell information.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_CELLINFO_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetCellInfoLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the call activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_CALL_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetCallLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the message activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_MSG_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetMsgLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the application usage activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_APP_USAGE_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetAppUsageLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the application installation activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_APP_INSTALLATION_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetAppInstallationLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the music activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_MUSIC_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetMusicLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the video activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_VIDEO_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetVideoLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the %Web browsing activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_WEB_BROWSING_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetWebBrowsingLogPermission(void);
	
	/**
	 * @if PRIVCORE
	 * Gets the permission to access the %Web search activity.
	 *
	 * @since       2.0
	 * @privlevel   CORE
	 * @privgroup   LIFELOG_WEB_SEARCH_LOG_RETRIEVAL
	 *
	 * @return      An error code
	 * @exception   E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	 * @endif
	*/
	static result GetWebSearchLogPermission(void);

	//variables
private:
	ActivityType __activityType;
	ILifelog* 	 __pILifelog;

private:
	friend class LifelogEx;
	class LifelogEx* __pLifelogEx;
};

};};// Osp::Social

#endif//_FSCL_LIFE_LOG_H_
