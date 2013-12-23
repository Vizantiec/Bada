/* $Change: 1198808 $ */
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
 * @file	FSclLifelogger.h
 * @brief	This is the header file for the %Lifelogger class.
 *
 * This header file contains the declarations of the %Lifelogger class.
 */
#ifndef _FSCL_LIFELOGGER_H_
#define _FSCL_LIFELOGGER_H_

// Includes
#include "FSclConfig.h"
#include <FSclLifelogTypes.h>
#include <FSclContact.h>


struct ILifelogger;

namespace Osp { namespace Social {


class ILifeloggerPi;

/**
 * @if PRIVCORE
 * @class	Lifelogger
 * @brief	This class provides the methods to log the activity data of the user.
 * @since		2.0
 * @privlevel	CORE
 *
 * The %Lifelogger class provides the methods to log the activity data of the user.
 *
 * @endif
 *
 */
class  _EXPORT_SOCIAL_ Lifelogger:
		public Osp::Base::Object
{

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since		2.0
	 * @privlevel	CORE
	 *
	 */
	Lifelogger(void);

	/**
	* This is the destructor for this class.
	*
	* @since		2.0
	* @privlevel	CORE
	*
	*/
	~Lifelogger(void);

	/**
	* Initializes this instance of %Lifelogger.
	*
	* @since		2.0
	* @privlevel	CORE
	*
	* @return		An error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	* @exception	E_INVALID_STATE	This instance has already been constructed.
	* @exception	E_SYSTEM	 	A system error has occurred.
	*/
	result Construct();

private:
	Lifelogger(const Lifelogger& value);
	Lifelogger&	operator =(const Lifelogger& value);

public:

	/**
	* @if PRIVCORE
	* Writes the information about the music that has been played to the lifelog database. @n
	* If the music logging is disabled, music log does not log. @n
	* The logged data is retrieved using the Osp::Social::Lifelog class.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_MUSIC_LOGGING
	*
	* @return		An error code
	* @param[in]	uri					The URI
	* @param[in]	title				The title
	* @param[in]	length				The length in seconds
	* @param[in]	elapsedTime			The elapsed time in seconds
	* @param[in]	pArtist				The artist
	* @param[in]	pAlbum				The album
	* @param[in]	pGenre				The genre
	* @param[in]	pYear				The year (4-digits numeric number)
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c uri or @c title is an empty string. @n
	*									- The specified @c elapsedTime exceeds the specified @c length. @n
	*									- The specified @c elapsedTime or @c length is negative.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result WriteMusicLog(const Osp::Base::String& uri,  const Osp::Base::String& title,  int length, int elapsedTime,
							const Osp::Base::String *pArtist, const Osp::Base::String *pAlbum,  
							const Osp::Base::String *pGenre, int *pYear);
						
	/**
	* @if PRIVCORE
	* Sets a value that enables or disables location logging. @n
	* 
	* The location logging is executed even though the system enters the sleep mode. @n
	* The logged data is retrieved using the Osp::Social::Lifelog class with Osp::Social::ActivityType::ACTIVITY_LOCATION type.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_LOCATION_LOGGING
	*
	* @return		An error code
	* @param[in]	enable				Set to @c true to enable location logging, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsLocationLoggingEnabled(), SetLocationLoggingInterval()
	*
	* @endif
	*/
	result SetLocationLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the location logging feature is enabled.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_LOCATION_LOGGING
	*
	* @return		@c true if the location logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetLocationLoggingEnabled()
	*
	* @endif
	*/
	bool IsLocationLoggingEnabled(void) const;
							
	/**
	* @if PRIVCORE
	* Sets the interval of location logging. @n
	* 
	* The location logging feature is executed within the specified interval. @n
	* If the location logging feature is enabled, the location data is logged periodically within the specified interval.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_LOCATION_LOGGING
	*
	* @return		An error code
	* @param[in]	interval			The logging interval in seconds should be greater than or equal to @c 300 sec
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_SYSTEM			A system error has occurred.
	* @exception	E_INVALID_ARG 		The specified time interval is smaller than @c 300 sec.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			SetLocationLoggingEnabled(), GetLocationLoggingInterval()
	*
	* @endif
	*/
	result SetLocationLoggingInterval(int interval);
	
	/**
	* @if PRIVCORE
	* Gets the interval of location logging.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_LOCATION_LOGGING
	*
	* @return		The logging interval in seconds, @n
	*				else @c -1 if an error occurs
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_INVALID_STATE		This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetLocationLoggingInterval()
	*
	* @endif
	*/
	int GetLocationLoggingInterval(void) const;

	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the cell information logging (cell ID, LAC, MCC, and MNC).
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_CELLINFO_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable the cell information logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsCellInfoLoggingEnabled()
	*
	* @endif
	*/
	result SetCellInfoLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the cell information logging feature is enabled.
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_CELLINFO_LOGGING
	*
	* @return		@c true if the cell information logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetCellInfoLoggingEnabled()
	*
	* @endif
	*/
	bool IsCellInfoLoggingEnabled(void) const;
	
	/**
	* @if PRIVCORE
	* Sets a value that enables or disables call logging. @n 
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_CALL type.
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_CALL_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable call logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsCallLoggingEnabled()
	*
	* @endif
	*/
	result SetCallLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the call logging feature is enabled.
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_CALL_LOGGING
	*
	* @return		@c true if the call logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetCallLoggingEnabled()
	*
	* @endif
	*/
	bool IsCallLoggingEnabled(void) const;


	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the message logging. @n
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_MESSAGE type.
	*
	* @since 		2.0
	* @privlevel    CORE
	* @privgroup	LIFELOG_MSG_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable message logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsMessageLoggingEnabled()
	*
	* @endif
	*/
	result SetMessageLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the message logging feature is enabled.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup     LIFELOG_MSG_LOGGING
	*
	* @return		@c true if the message logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMessageLoggingEnabled()
	*
	* @endif
	*/
	bool IsMessageLoggingEnabled(void) const;

	
	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the application usage logging. @n
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_ APP_USAGE type.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_APP_USAGE_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable application usage logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsAppUsageLoggingEnabled()
	*
	* @endif
	*/
	result SetAppUsageLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the application usage logging feature is enabled.
	*
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_APP_USAGE_LOGGING
	*
	* @return		@c true if the application usage logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetAppUsageLoggingEnabled()
	*
	* @endif
	*/
	bool IsAppUsageLoggingEnabled(void) const;
	
	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the application installation logging. @n
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_ APP_ INSTALLATION type.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_APP_INSTALLATION_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable application installation logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsAppInstallationLoggingEnabled()
	*
	* @endif
	*/
	result SetAppInstallationLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the application installation logging feature is enabled.
	*
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_APP_INSTALLATION_LOGGING
	*
	* @return		@c true if the application installation logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetAppInstallationLoggingEnabled()
	*
	* @endif
	*/
	bool IsAppInstallationLoggingEnabled(void) const;
	
	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the music logging. @n 
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_ MUSIC type.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_MUSIC_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable music logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsMusicLoggingEnabled()
	*
	* @endif
	*/
	result SetMusicLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the music logging feature is enabled.
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_MUSIC_LOGGING
	*
	* @return		@c true if the music logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetMusicLoggingEnabled()
	*
	* @endif
	*/
	bool IsMusicLoggingEnabled(void) const;

	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the video logging. @n 
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_VIDEO type.
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_VIDEO_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable video logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsVideoLoggingEnabled()
	*
	* @endif
	*/
	result SetVideoLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the video logging feature is enabled.
	*
	*
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_VIDEO_LOGGING
	*
	* @return		@c true if the video logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetVideoLoggingEnabled()
	*
	* @endif
	*/
	bool IsVideoLoggingEnabled(void) const;

	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the logging for %Web browsing. @n 
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_WEB_BROWSING type.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_WEB_BROWSING_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable logging for %Web browsing, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsWebBrowsingLoggingEnabled()
	*
	* @endif
	*/
	result SetWebBrowsingLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the logging feature is enabled for %Web browsing.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_WEB_BROWSING_LOGGING
	*
	* @return		@c true if the logging feature is enabled for %Web browsing, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetWebBrowsingLoggingEnabled()
	*
	* @endif
	*/
	bool IsWebBrowsingLoggingEnabled(void) const;

	/**
	* @if PRIVCORE
	* Sets a value that enables or disables the %Web search logging. @n 
	* The logged data is retrieved using the Osp::Social::Lifelog class with the Osp::Social::ActivityType::ACTIVITY_WEB_SEARCH
	* type.
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_WEB_SEARCH_LOGGING
	*
	* @return		An error code
	* @param[in]	enable					Set to @c true to enable %Web search logging, @n
	*										else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_SYSTEM				A system error has occurred.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	* @see			IsWebSearchLoggingEnabled()
	*
	* @endif
	*/
	result SetWebSearchLoggingEnabled(bool enable);
	
	
	/**
	* @if PRIVCORE
	* Checks whether the %Web search logging feature is enabled.
	*
	*
	* @since 		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_WEB_SEARCH_LOGGING
	*
	* @return		@c true if the %Web search logging feature is enabled, @n
	*				else @c false
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.
	* @exception	E_INVALID_STATE			This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team. @n
	*				The specific error code can be accessed using the GetLastResult() method.
	* @see			SetWebSearchLoggingEnabled()
	*
	* @endif
	*/
	bool IsWebSearchLoggingEnabled(void) const;
	
	/**
	* @if PRIVCORE
	* Deletes all call logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_CALL_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllCallLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all message logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_MSG_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllMsgLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all application usage logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_APP_USAGE_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllAppUsageLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all application installation logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_APP_INSTALLATION_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllAppInstallationLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all music logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_MUSIC_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllMusicLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all video logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_VIDEO_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllVideoLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all %Web browsing logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_WEB_BROWSING_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllWebBrowsingLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all %Web search logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_WEB_SEARCH_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllWebSearchLogs(void);
	
	/**
	* @if PRIVCORE
	* Deletes all location logs.
	* 
	* @since		2.0
	* @privlevel	CORE
	* @privgroup	LIFELOG_LOCATION_LOGGING
	*
	* @return		An error code
	* @exception	E_SUCCESS                The method is successful.
	* @exception	E_OUT_OF_MEMORY          The memory is insufficient.
	* @exception	E_SERVICE_BUSY			 The database is busy. 
	* @exception	E_INVALID_STATE          This instance has not been constructed as yet.
	* @exception	E_PRIVILEGE_DENIED       The application does not have the privilege to call this method.        
	* @remarks		Do not use this method without obtaining prior permission from the bada platform team.
	*
	* @endif
	*/
	result DeleteAllLocationLogs(void);

//variables
private:
	ILifeloggerPi*	__pILifeloggerPi;
	ILifelogger*	__pILifelogger;
private:
	friend class LifeloggerEx;
	class LifeloggerEx* __pLifeloggerEx;
};

};};// Osp::Social

#endif//_FSCL_LIFELOGGER_H_
