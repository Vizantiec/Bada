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
 * @file		FSclActivity.h
 * @brief		This is the header file for the %Activity class.
 *
 * This header file contains the declarations of the %Activity class.
 * @endif
 */
#ifndef _FSCL_ACTIVITY_LOG_H_
#define _FSCL_ACTIVITY_LOG_H_

// Includes
#include "FSclConfig.h"
#include <FBase.h>
#include <FLocCoordinates.h>

namespace Osp { namespace Social {

class __LifelogUtil;

/**
 * @if PRIVCORE
 * @enum	ActivityType
 * Defines the type of activity.
 *
 * @since	2.0
 * @endif
 */
enum ActivityType
{
	ACTIVITY_NONE		= -1,	/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method. */
	ACTIVITY_CALL,				/**< @if PRIVCORE The call activity (Osp::Social::CalllogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetCallLogPermission() method. @endif */
	ACTIVITY_MESSAGE,			/**< @if PRIVCORE The message activity (Osp::Social::MessagelogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetMsgLogPermission() method. @endif */
	ACTIVITY_MUSIC,				/**< @if PRIVCORE The music activity (Osp::Social::MusiclogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetMusicLogPermission() method. @endif */
	ACTIVITY_APP_USAGE,			/**< @if PRIVCORE The application usage activity (Osp::Social::AppUsagelogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetAppUsageLogPermission() method. @endif */
	ACTIVITY_APP_INSTALLATION,	/**< @if PRIVCORE The application installation activity (Osp::Social::AppInstalllogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetAppInstallationLogPermission() method. @endif */
	ACTIVITY_VIDEO,				/**< @if PRIVCORE The video activity (Osp::Social::VideologPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetVideoLogPermission() method. @endif */
	ACTIVITY_LOCATION,			/**< @if PRIVCORE The location activity (Osp::Social::LocationlogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetLocationlogPermission() method. @endif */
	ACTIVITY_WEB_BROWSING,		/**< @if PRIVCORE The %Web browsing activity (Osp::Social::WebBrowsinglogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetWebBrowsingLogPermission() method. @endif */
	ACTIVITY_WEB_SEARCH			/**< @if PRIVCORE The %Web search activity (Osp::Social::WebSearchlogPropertyId) @n To make use of this activity, invoke the Osp::Social::Lifelog::GetWebSearchLogPermission() method. @endif */
};

/**
* @if PRIVCORE
* @enum		CallDirection
* Defines the direction of the call.
*
* @since	2.0
* @endif
*/
enum CallDirection
{
	CLOGTYPE_INCOMING,	/**< @if PRIVCORE An incoming call @endif */
	CLOGTYPE_OUTGOING,	/**< @if PRIVCORE An outgoing call @endif */
	CLOGTYPE_MISSED		/**< @if PRIVCORE A missed call  @endif */
};

/**
* @if PRIVCORE
* @enum		CalllogPropertyId
* Defines the properties of a call activity. @n
*
* To make use of this activity, invoke the Osp::Social::Lifelog::GetLocationLogPermission() method. @n
* To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
* The Activity::GetValue() throws E_DATA_NOT_FOUND, if @c CLOG_PHONE_NUMBER is unknown. @n
* If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1.
*
* @since	2.0
* @endif
*/
enum CalllogPropertyId
{
	CLOG_NONE	= -1,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	CLOG_DIRECTION,			/**< @if PRIVCORE The call direction (Osp::Social::CallDirection) @endif */
	CLOG_DURATION,			/**< @if PRIVCORE The call duration (int (sec)) @endif */
	CLOG_TYPE,				/**< @if PRIVCORE The call type (Osp::Telephony::CallType) @endif */
	CLOG_PHONE_NUMBER,  	/**< @if PRIVCORE The phone number (String) @endif */
	CLOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	CLOG_LAC,				/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	CLOG_MCC,				/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	CLOG_MNC,				/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	CLOG_TIMESTAMP,			/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	CLOG_OCCURRED_COUNT,	/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
	CLOG_LOCATION 			/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.The last known location using WPS or GPS (String: "latitude, longitude")*/
};

/**
* @if PRIVCORE
* @enum		MessageDirection
* Defines the direction of the message.
*
* @since	2.0
* @endif
*/
enum MessageDirection
{
	MSGLOGTYPE_RECEIVED,	/**< @if PRIVCORE The received message @endif */
	MSGLOGTYPE_SENT			/**< @if PRIVCORE The sent message @endif */
};

/**
 * @if PRIVCORE
 * @enum	MessageType
 * Defines the types of messages.
 *
 * @since	2.0
 * @endif
 */
enum MessageType
{
	MSG_SMS = 0, 	 		/**< @if PRIVCORE An SMS message @endif */
	MSG_MMS, 				/**< @if PRIVCORE An MMS message @endif */
};

/**
 * @if PRIVCORE
 * @enum	MessagelogPropertyId
 * Defines the properties of a message activity.
 *
 * To make use of this activity, invoke the Osp::Social::Lifelog::GetMsgLogPermission() method. @n
 * To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
 * The Activity::GetValue() returns E_DATA_NOT_FOUND, if @c MSGLOG_SUMMARY or @c MSGLOG_PHONE_NUMBER is unknown. @n
 * If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1. 
 *
 * @since	2.0
 * @endif
 */
enum MessagelogPropertyId
{
	MSGLOG_NONE = -1,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	MSGLOG_DIRECTION,		/**< @if PRIVCORE The message direction (Osp::Social::MessageDirection) @endif */
	MSGLOG_SUMMARY,			/**< @if PRIVCORE The message summary (String) @endif */
	MSGLOG_TYPE,			/**< @if PRIVCORE The message type (Osp::Social::MessageType) @endif */
	MSGLOG_PHONE_NUMBER,	/**< @if PRIVCORE The phone number (String) @endif */
	MSGLOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	MSGLOG_LAC,				/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	MSGLOG_MCC,				/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	MSGLOG_MNC,				/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	MSGLOG_TIMESTAMP,		/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	MSGLOG_OCCURRED_COUNT,	/**< @if PRIVCORE The count of most frequently occurring values @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
	MSGLOG_LOCATION			/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.The last known location using WPS or GPS (String: "latitude, longitude")*/
};

/**
 * @if PRIVCORE
 * @enum	AppUsagelogPropertyId
 * Defines the properties of the application usage activity. @n
 *
 * To make use of this activity, invoke the Osp::Social::Lifelog::GetAppUsageLogPermission() method. @n
 * To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
 * If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1. 
 * 
 * @since	2.0
 * @endif
 */
enum AppUsagelogPropertyId
{
	APPULOG_NONE = -1,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	APPULOG_APP_ID,			/**< @if PRIVCORE The application ID (String) @endif */
	APPULOG_APP_NAME,		/**< @if PRIVCORE The application name (String) @endif */
	APPULOG_START_TIME,		/**< @if PRIVCORE The application launch time (DateTime) @endif */
	APPULOG_END_TIME,		/**< @if PRIVCORE The application end time (DateTime) @endif */
	APPULOG_DURATION,		/**< @if PRIVCORE The application duration (int (sec)) @endif */
	APPULOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	APPULOG_LAC,			/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	APPULOG_MCC,			/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	APPULOG_MNC,			/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	APPULOG_LOCATION,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.The last known location using WPS or GPS (String: "latitude, longitude")*/
	APPULOG_TIMESTAMP,		/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	APPULOG_OCCURRED_COUNT	/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
};

/**
 * @if PRIVCORE
 * @enum	AppInstallationType
 * Defines the application installation types.
 *
 * @since	2.0
 * @endif
 */
enum AppInstallationType
{
	APP_INSTALL, 	/**<  @if PRIVCORE The application installation @endif   */
	APP_UNINSTALL, 	/**<  @if PRIVCORE The application uninstallation @endif */
};

/**
 * @if PRIVCORE
 * @enum	AppInstalllogPropertyId
 * Defines the properties for the application installation activity. @n
 *
 * To make use of this activity, invoke the Osp::Social::Lifelog::GetAppInstallationLogPermission() method. @n
 * To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
 * The Activity::GetValue() returns E_DATA_NOT_FOUND, if @c APPILOG_APP_NAME is unknown. @n
 * If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1.
 *
 * @since	2.0
 * @endif
 */
enum AppInstalllogPropertyId
{
	APPILOG_NONE = -1,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	APPILOG_APP_ID,			/**< @if PRIVCORE The application ID (Osp::App::AppId) @endif */
	APPILOG_APP_NAME,		/**< @if PRIVCORE The application name (String) @endif */
	APPILOG_TYPE,			/**< @if PRIVCORE The application installation type (Osp::Social::AppInstallationType) @endif */
	APPILOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	APPILOG_LAC,			/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	APPILOG_MCC,			/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif*/
	APPILOG_MNC,			/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	APPILOG_LOCATION,       /**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.The last known location using WPS or GPS (String: "latitude, longitude") */
	APPILOG_TIMESTAMP,		/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	APPILOG_OCCURRED_COUNT	/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
};


/**
* @if PRIVCORE
* @enum		MusiclogPropertyId
* Defines the properties for the music activity. @n
*
* To make use of this activity, invoke the Osp::Social::Lifelog::GetMusicLogPermission() method. @n
* To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
* The Activity::GetValue() returns E_DATA_NOT_FOUND, if @c MUSICLOG_TITLE, @c MUSICLOG_ARTIST, @c MUSICLOG_ALBUM, @c MUSICLOG_YEAR, or @c MUSICLOG_GENRE is 
* unknown. @n
* If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1.
*
* @since	2.0
* @endif
*/
enum MusiclogPropertyId
{
	MUSICLOG_NONE = -1,			/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	MUSICLOG_TITLE,				/**< @if PRIVCORE The title (String) @endif */
	MUSICLOG_URI,				/**< @if PRIVCORE The URI (String) @endif */
	MUSICLOG_ARTIST,			/**< @if PRIVCORE The artist name (String) @endif */
	MUSICLOG_ALBUM,				/**< @if PRIVCORE The album (String) @endif */
	MUSICLOG_YEAR,				/**< @if PRIVCORE The year (4-digit String)  @endif */
	MUSICLOG_GENRE,				/**< @if PRIVCORE The genre (String) @endif */
	MUSICLOG_LENGTH,			/**< @if PRIVCORE The length (int (sec)) @endif */
	MUSICLOG_ELAPSEDTIME,		/**< @if PRIVCORE The elapsed time (int (sec)) @endif */
	MUSICLOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	MUSICLOG_LAC,				/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	MUSICLOG_MCC,				/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	MUSICLOG_MNC,				/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	MUSICLOG_TIMESTAMP,			/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	MUSICLOG_OCCURRED_COUNT		/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
};

/**
* @if PRIVCORE
* @enum VideologPropertyId
* Defines the properties for the video activity.
*
* To make use of this activity, invoke the Osp::Social::Lifelog::GetVideoLogPermission() method. @n
* To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
* The Activity::GetValue() returns E_DATA_NOT_FOUND if @c VIDEOLOG_TITLE, @c VIDEOLOG_ARTIST, @c VIDEOLOG_ALBUM, @c VIDEOLOG_YEAR, or @c VIDEOLOG_GENRE is 
* unknown. @n
* If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1.
*
* @since 2.0
* @endif
*/
enum VideologPropertyId
{
	VIDEOLOG_NONE = -1,			/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	VIDEOLOG_TITLE,				/**< @if PRIVCORE The title (String) @endif */
	VIDEOLOG_URI,				/**< @if PRIVCORE The URI (String) @endif */
	VIDEOLOG_ARTIST,			/**< @if PRIVCORE The artist name (String) @endif */
	VIDEOLOG_ALBUM,				/**< @if PRIVCORE The album (String) @endif */
	VIDEOLOG_YEAR,				/**< @if PRIVCORE The year (4-digit String) @endif */
	VIDEOLOG_GENRE,				/**< @if PRIVCORE The genre (String) @endif */
	VIDEOLOG_LENGTH,			/**< @if PRIVCORE The length (int (sec)) @endif */
	VIDEOLOG_ELAPSEDTIME,		/**< @if PRIVCORE The elapsed time (int (sec)) @endif */
	VIDEOLOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	VIDEOLOG_LAC,				/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	VIDEOLOG_MCC,				/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	VIDEOLOG_MNC,				/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	VIDEOLOG_TIMESTAMP,			/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	VIDEOLOG_OCCURRED_COUNT		/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
};

/**
* @if PRIVCORE
* @enum		LocationlogPropertyId
* Defines the properties for the location activity. @n
*
* To make use of this activity, invoke the Osp::Social::Lifelog::GetLocationLogPermission() method. @n
* To make use of the cell ID, LAC, MCC, and MNC, invoke the Osp::Social::Lifelog::GetCellInfoLogPermission() method. @n
* The Activity::GetValue() returns E_DATA_NOT_FOUND if @c LOCLOG_ALTITUDE, @c LOCLOG_HORIZACCURACY, @c LOCLOG_VERTACCURACY, @c LOCLOG_SPEED, or @c 
* LOCLOG_COURSE is unknown. @n
* If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1. 
*
* @since 	2.0
* @endif
*/
enum LocationlogPropertyId
{
	LOC_LOG_NONE   = -1,	/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	LOC_LOG_LATITUDE,		/**< @if PRIVCORE The latitude (double in [-90.0,90.0]) @endif */
	LOC_LOG_LONGITUDE,		/**< @if PRIVCORE The longitude (double in [-180.0,180.0]) @endif */
	LOC_LOG_ALTITUDE,		/**< @if PRIVCORE The altitude (double in meters) @endif */
	LOC_LOG_METHOD,			/**< @if PRIVCORE The location method (@c LOC_METHOD_GPS or @c LOC_METHOD_WPS in Osp::Locations::LocationMethod) @endif */
	LOC_LOG_HORIZACCURACY,	/**< @if PRIVCORE The horizontal accuracy (double in meters) @endif */
	LOC_LOG_VERTACCURACY,	/**< @if PRIVCORE The vertical accuracy (double in meters) @endif */
	LOC_LOG_SPEED,			/**< @if PRIVCORE The speed (double in km/h) @endif */
	LOC_LOG_COURSE,			/**< @if PRIVCORE The course (double in [0.0, 360.0]) @endif */
	LOC_LOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	LOC_LOG_LAC,			/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	LOC_LOG_MCC,			/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	LOC_LOG_MNC,			/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	LOC_LOG_TIMESTAMP,		/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	LOC_LOG_OCCURRED_COUNT	/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
};


/**
* @if PRIVCORE
* @enum		WebBrowsinglogPropertyId
* Defines the properties for the %Web browsing activity.
*
* If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1.
* @since	2.0
* @endif
*/
enum WebBrowsinglogPropertyId
{
	WEB_BROWSING_LOG_NONE=-1,			/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	WEB_BROWSING_LOG_TITLE,				/**< @if PRIVCORE The %Web page title (String) @endif */
	WEB_BROWSING_LOG_URL,				/**< @if PRIVCORE The URL (String) @endif */
	WEB_BROWSING_LOG_CELLID,			/**< @if PRIVCORE The cell ID (int) @endif */
	WEB_BROWSING_LOG_LAC,				/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	WEB_BROWSING_LOG_MCC,				/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	WEB_BROWSING_LOG_MNC,				/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	WEB_BROWSING_LOG_TIMESTAMP,			/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	WEB_BROWSING_LOG_OCCURRED_COUNT		/**< @if PRIVCORE The count of values that occur most frequently @n This is used as the result for Lifelog::GetMostOccurredValuesN(). @endif */
};

/**
* @if PRIVCORE
* @enum		WebSearchlogPropertyId
* Defines the properties for the %Web search activity. @n
*
* If the data is invalid, the value of the cell ID, LAC, MCC, and MNC fields is @c -1.
* @since	2.0
* @endif
*/
enum WebSearchlogPropertyId
{
	WEB_SEARCH_LOG_NONE = -1,			/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.*/
	WEB_SEARCH_LOG_KEYWORD,				/**< @if PRIVCORE The search keyword (String) @endif */
	WEB_SEARCH_LOG_CELLID,				/**< @if PRIVCORE The cell ID (int) @endif */
	WEB_SEARCH_LOG_LAC,					/**< @if PRIVCORE The LAC (Location Area Code: int) @endif */
	WEB_SEARCH_LOG_MCC,					/**< @if PRIVCORE The MCC (Mobile Country Code: int) @endif */
	WEB_SEARCH_LOG_MNC,					/**< @if PRIVCORE The MNC (Mobile Network Code: int) @endif */
	WEB_SEARCH_LOG_TIMESTAMP,			/**< @if PRIVCORE The timestamp @n This is used as a parameter in Lifelog::SetSortOrder(). The time format is UTC time. @endif */
	WEB_SEARCH_LOG_OCCURRED_COUNT		/**< @if PRIVCORE The count of values that occur most frequently @n This is used as a result of Lifelog::GetMostOccurredValuesN(). @endif */
};


// Enumerator
/**
* @internal This enum is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
* @enum ActivityValueType
* Defines the activity value type.
*
* @since 2.0
*/
enum ActivityValueType
{
	ACTIVITY_VALUE_NONE = -1,	/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.Invalid type  */
	ACTIVITY_VALUE_INTEGER,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.Integer type  */
	ACTIVITY_VALUE_INTEGER64,	/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.Integer type  */
	ACTIVITY_VALUE_DOUBLE,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.Double type   */
	ACTIVITY_VALUE_STRING,		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.String type   */
	ACTIVITY_VALUE_DATETIME		/**< @internal This enum value is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.DateTime type */
};

/**
 * @if PRIVCORE
 * @class		Activity
 * @brief		This class provides the methods for the various lifelog activities.
 * @since		2.0
 * @privlevel	CORE
 *
 * The %Activity class has common properties, such as the time (when), location (where), value (what), and peer (with whom) for presenting a lifelog.
 *
 * @endif
 */
class  _EXPORT_SOCIAL_ Activity:
		public Osp::Base::Object
{

protected:
	/**
	 * @if PRIVCORE
	 * Initializes this instance of %Activity with the specified @c type.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @param[in] 	type	The type of the activity
	 * @endif
	*/
	Activity(ActivityType type);
	/**
	 * @if PRIVCORE
	 * Initializes this instance of %Activity with the specified @c type and @c timestamp.
	 * The timestamp is the UTC time.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @param[in]	type		The type of the activity
	 * @param[in]	timestamp	The timestamp of the activity
	 * @endif
	*/
	Activity(ActivityType type, Osp::Base::DateTime& timestamp);

public:
	/**
	* @if PRIVCORE
	* This is the destructor for this class.
	*
	* @since		2.0
	* @privlevel	CORE
	*
	* @endif
	*/
	~Activity(void);

// Two phase construction idiom.
private:
	Activity(const Activity& value);
	Activity&	operator =(const Activity& value);

public:

	/**
	 * @if PRIVCORE
	 * Gets the activity type of the current instance of %Activity.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		The activity type
	 * @endif
	 */
	ActivityType GetActivityType(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the timestamp of the current instance of %Activity. @n
	 * The timestamp is the UTC time.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		The timestamp
	 * @endif
	 */
	Osp::Base::DateTime GetTimestamp(void) const;

	/**
	 * @if PRIVCORE
	 * Gets the value of the activity.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		An error code
	 * @param[in]	propertyId			A property ID
	 * @param[out]	value				An integer value of the activity that has the specified @c propertyId
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The activity does not have the specified @c propertyId.
	 * @exception	E_DATA_NOT_FOUND	The specified property does not have a value.
	 * @see 		Osp::Social::CalllogPropertyId, Osp::Social::MessagelogPropertyId, Osp::Social::AppUsagelogPropertyId, 
	 *				Osp::Social::AppInstalllogPropertyId, Osp::Social::MusiclogPropertyId, Osp::Social::VideologPropertyId, Osp::Social::LocationlogPropertyId 
	 * @endif
	 */
	result GetValue(int propertyId, int& value) const;

	/**
	 * @if PRIVCORE
	 * Gets the value of the activity.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		An error code
	 * @param[in]	propertyId			A property ID
	 * @param[out]	value				A @c long long value of the activity of the specified @c propertyId
	 * @exception	E_SUCCESS			The method is successful.
 	 * @exception	E_INVALID_ARG		The activity does not have the specified @c propertyId.
	 * @exception	E_DATA_NOT_FOUND	The specified property does not have a value.
	 * @endif
	 */
	result GetValue(int propertyId, long long& value) const;

	/**
	 * @if PRIVCORE
	 * Gets the value of the activity.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		An error code
	 * @param[in]	propertyId			A property ID
	 * @param[out]	value				A @c double value of the activity of the specified @c propertyId
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The activity does not have the specified @c propertyId.
	 * @exception	E_DATA_NOT_FOUND	The specified property does not have a value.
	 * @see Osp::Social::LocationlogPropertyId
	 * @endif
	 */
	result GetValue(int propertyId, double& value) const;

	/**
	 * @if PRIVCORE
	 * Gets the value of the activity.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 * @return		An error code
	 * @param[in]	propertyId			A property ID
	 * @param[out]	value				A @c String value of the activity of the specified @c propertyId
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The activity does not have the specified @c propertyId.
	 * @exception	E_DATA_NOT_FOUND	The specified property does not have a value.
	 * @see Osp::Social::CalllogPropertyId, Osp::Social::MessagelogPropertyId, Osp::Social::AppUsagelogPropertyId, Osp::Social::AppInstalllogPropertyId, 
	 *		Osp::Social::MusiclogPropertyId, Osp::Social::VideologPropertyId, Osp::Social::LocationlogPropertyId
	 * @endif
	 */
	result GetValue(int propertyId, Osp::Base::String& value) const;

	/**
	 * @if PRIVCORE
	 * Gets the value of the activity.
	 *
	 * @since 		2.0
	 * @privlevel	CORE
	 *
	 * @return		An error code
	 * @param[in]	propertyId			A property ID
	 * @param[out]	value				A @c DateTime value of the activity of the specified @c propertyId
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The activity does not have the specified @c propertyId.
	 * @exception	E_DATA_NOT_FOUND	The specified property does not have a value.
	 * @see	Osp::Social::AppUsagelogPropertyId
	 * @endif
	 */
	result GetValue(int propertyId, Osp::Base::DateTime& value) const;

private:
	/**
	* @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	* Sets the value of the Activity	@n
	*
	* @return		An error code
	* @param[in]	propertyId			A property ID of the Activity
	* @param[in]	value				The value of Activity of the specified property ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The activity does not have the specified property ID.
	* @exception	E_OBJ_ALREADY_EXIST	The specified @c propertyId already exists.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @see Osp::Social::CalllogPropertyId, Osp::Social::MessagelogPropertyId
	*/
	result AddValue(int propertyId, Osp::Base::Object *pValue);

	/**
	 * @internal This method is for internal use only. The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues that might arise after using this method.
	 * Gets the value type of the property of the Activity	@n
	 *
	 * @return		The value type of the property
	 * @param[in]	propertyId			A property ID
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG		The activity does not have the specified property ID.
	 */
	ActivityValueType GetValueType(int propertyId);

private:

	ActivityType					__activityType;
	Osp::Base::Collection::HashMap	__activityValueMap;
	Osp::Base::DateTime				__timestamp;

friend class __LifelogUtil;

private:
	friend class ActivityEx;
	class ActivityEx* __pActivityEx;

};

};};// Osp::Social

#endif//_FSCL_ACTIVITY_LOG_H_

