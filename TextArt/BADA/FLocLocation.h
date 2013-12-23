/* $Change: 1267243 $ */
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
 * @file	FLocLocation.h 
 * @brief	This is the header file for the %Location class.
 *
 * This header file contains the declarations of the %Location, %SatelliteInfo, and %SatelliteDisplayInfo classes. @n 
 * These classes represent a standard set of methods that help in obtaining the basic information about the current location.
 */


#ifndef _FLOC_LOCATION_H_
#define _FLOC_LOCATION_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseColIListT.h"
#include "FBaseColIList.h"
#include "FBaseString.h"

struct MLocation;
struct MSatelliteInfo;
struct MSatelliteDisplayInfo;

namespace Osp { namespace Locations { 

/**
 * @enum	LocationMethod
 * Defines the location technology.
 *
 * @deprecated	This enumerated type is deprecated.
 * @since	1.0
 */
enum LocationMethod{
	/**
	* The %Location method using Global Positioning %System (GPS).
	*/
	LOC_METHOD_GPS = 1,
	/**
	* The %Location method using Wi-Fi Positioning %System (WPS) including cell ID information.
	*/
	LOC_METHOD_WPS = 2,
	/**
	* The %Location method using the consolidated WPS and GPS.
	*/
	LOC_METHOD_HYBRID = 3
};

/**
* @class	SatelliteInfo
* @brief	This class provides the methods to access the satellite information.    
* @deprecated	This class is deprecated.
* @since	1.0
* 
* 	The %SatelliteInfo class provides the following data: @n
* 			@li The overall satellites being used at the current location
* 			@li The total number of satellites available
* 			@li A list of satellites with their data
*
*/
class _EXPORT_LOCATION_ SatelliteInfo :
public Osp::Base::Object
{
public:
/** Maximum number of satellites in use. */
#define MAX_SATELLITE_NUM_IN_USE 12
/** Maximum number of satellites. */
#define MAX_SATELLITE_NUM_IN_VIEW 32

	/**
	* @class	SatelliteDisplayInfo
	* @brief	This class is used for the satellite display information.   
	 * @deprecated	This class is deprecated.
	* @since	1.0
	* 
	* 	The %SatelliteDisplayInfo class provides a detailed information about the individual satellite.
	*/
	class _EXPORT_LOCATION_ SatelliteDisplayInfo:
	public Osp::Base::Object
	{
	public:
		/** 
		* This is the destructor for this class.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		*/
		virtual ~SatelliteDisplayInfo(void);
		/**
		* Gets the identification of the satellite.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		* @return	The PRN (pseudo-random noise) code of the satellite used for its identification
		*/
		int GetSatelliteId(void) const;
		/**
		* Gets the elevation in degrees between the earth (mean sea level) and the satellite.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		* @return	The elevation in degrees
		*/
		int GetElevation(void) const;
		/**
		* Gets the azimuth value between a fixed point and the satellite.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		* @return	The azimuth value in degrees
		*/
		int GetAzimuth(void) const;
		/**
		* Gets the signal to noise ratio (SNR) in dBHZ (0 ~ 99).
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		* @return	The SNR value
		*/
		int GetSNR(void) const;
		/**
		*
		* Overrides the equals() method in the Object class to compare the equality of values in two %SatelliteDisplayInfo objects. 
		*
		* @deprecated	This method is deprecated.
		* @since		1.0
		* @return       @c true if all the fields in the objects are equal, @n
		*				else @c false
		* @param[in] 	obj 	The Object with which the comparison is done 
		*/
		virtual bool Equals(const Osp::Base::Object& obj) const;

		/**
		* Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
		*
		* @deprecated	This method is deprecated.
		* @since		1.0
		* @return		The hash value of the current instance
		*/
		virtual int GetHashCode(void) const;
	
	private:
		SatelliteDisplayInfo(void);
		SatelliteDisplayInfo(const SatelliteDisplayInfo& value);
		SatelliteDisplayInfo& operator=(const SatelliteDisplayInfo& rhs);	
		SatelliteDisplayInfo(MSatelliteDisplayInfo* pMSatelliteDisplayInfo);
		
	private:
		int __satelliteId;
		int __elevation;
		int __azimuth;
		int __snr;

	friend class _LocationUtil;

private:
	friend class SatelliteDisplayInfoEx;
	class SatelliteDisplayInfoEx* __pSatelliteDisplayInfoEx;

	};

public:
	/**
	* This is the copy constructor for the %SatelliteInfo class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	SatelliteInfo(const SatelliteInfo& value);	
	/**
	* This operator assigns the value of the indicated %SatelliteInfo object to the current instance.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		A reference to the current instance
	* @param[in]	rhs		An instance of %SatelliteInfo to be assigned
	*/
	SatelliteInfo& operator=(const SatelliteInfo& rhs);	
	/** 
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~SatelliteInfo(void);
private:
	SatelliteInfo(void);
	SatelliteInfo(MSatelliteInfo* pMSatelliteInfo);
public:
	/**
	* Gets the number of satellites that are being used to determine the current position.  
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	* @return 	The number of satellites in use to determine the current position
	*/
	int GetNumOfSatelliteInUse(void) const;
	/**
	* Gets the number of satellites that are available for position determination.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The number of satellites that are available
	*/
	int GetNumOfSatelliteInView(void) const;
	/**
	* Gets the list of PRN (pseudo-random noise) identification codes of the satellites that are being used to determine the position. @n
	* The maximum count of the list is @c 12.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	* @return	A list of PRN (pseudo-random noise) identification codes of the satellites that are being used
	*/
	Osp::Base::Collection::IListT<int>& GetSatelliteInUse(void) const;
	/**
	* Gets the list of the %SatelliteDisplayInfo objects.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	* @return	A list of the satellite display information
	*/
	Osp::Base::Collection::IList& GetSatelliteInView(void) const;
	/**
	*
	* Overrides the equals() method in the Object class to compare the equality of values in two SatelliteInfo objects. 
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return       @c true if all the fields in the objects are equal, @n
	*				else @c false
	* @param[in] 	obj 	The Object with which the comparison is done 
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/**
	* Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;
	
private:
	MSatelliteInfo* __pMSatelliteInfo;
	Osp::Base::Collection::IListT<int>* __pSatelliteInUse;
	Osp::Base::Collection::IList* __pSatelliteInView;

friend class Location;
friend class _LocationUtil;

private:
	friend class SatelliteInfoEx;
	class SatelliteInfoEx* __pSatelliteInfoEx;

};
/*
* @}
*/

class QualifiedCoordinates;
/**
* @class	Location
* @brief	This class defines the standard set of basic location information.
* @deprecated	This class is deprecated.
* @since  	1.0
*
* The %Location class includes the timestamped coordinates, accuracy, speed, course, the positioning method used for the location, and the satellite 
*			information.
*
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/location_provider.htm">Location Provider</a>.
*
*/
class _EXPORT_LOCATION_ Location :
public Osp::Base::Object
{
// Lifecycle
protected:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	Location(void);							
	/**
	* This is the copy constructor for the %Location class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	Location(const Location& value);				
	/**
	* Assigns the value of the specified %Location instance to the current instance.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		A reference to the current instance 
	* @param[in]	rhs 	An instance of %Location to be assigned
	*/
	Location& operator=(const Location& rhs);	
public:
	/** 
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since	1.0
	 */
	virtual ~Location(void);
private:
	Location(MLocation* pMLocation);
	const MLocation* GetMLocation(void) const;
//Operations
public:
	/**
	*
	* Gets the course of the terminal in degrees relative to true north.
	* The value is always in the [0.0, 360.0] degrees range.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref GetCoursePage "here".
	*
	* @return       	A @c float value representing the course of the terminal relative to @c true north in degrees, @n
	* 					else Not-a-Number (NaN) if the course is unknown
	*/
	float GetCourse(void) const;
	/**
	* @page		GetCoursePage	Compatibility for GetCourse()
	*
	* @section	GetCoursePageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* If the course is unknown, it returns @c 0 instead of Not-a-Number (NaN).
	*
	* @section		GetCoursePageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows: @n
	* If the course is unknown, Not-a-Number (NaN) is returned.
	*/
	
	/**
	*
	* Gets the information about the location method used. 
	* 
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return 	The location method used
	*/

	LocationMethod GetLocationMethod(void) const;

	/**
	*
	* Gets the coordinates of the specified location and their accuracy.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	* 					For more information, see @ref GetQualifiedCoordinatesPage "here".
	*
	* @return		A %QualifiedCoordinates instance representing the coordinates of the specified location, @n
	*				else @c null if the coordinates are unknown
	*/
	const QualifiedCoordinates* GetQualifiedCoordinates(void) const;
	/**
	* @page		GetQualifiedCoordinatesPage		Compatibility for GetQualifiedCoordinates()
	*
	* @section	GetQualifiedCoordinatesPageIssueSection		Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* If the value of the latitude and longitude is @c 0, it returns @c null instead of the valid qualified coordinates.
	*
	* @section	GetQualifiedCoordinatesPageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows: @n
	* If the value of the latitude and longitude is @c 0, it returns the valid qualified coordinates.
	*/

	/**
	*
	* Gets the current ground speed of the terminal in kilometers per hour (km/h) at the time of measurement. @n
	* The speed is always a non-negative value. Note that unlike the coordinates, the speed does not have an associated accuracy because the methods used to 
	* determine the speed typically, are not able to indicate the accuracy.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref GetSpeedPage "here".
	*
	* @return			A @c float value indicating the current ground speed in km/h, @n
	*		  			else @c Not-a-Number (NaN) if the speed is unknown
	*/
	float GetSpeed(void) const;
	/**
	* @page		GetSpeedPage	Compatibility for GetSpeed()
	*
	* @section	GetSpeedPageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* If the speed is unknown, it returns @c 0 instead of Not-a-Number (NaN).
	*
	* @section		GetSpeedPageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows: @n
	* If the speed is unknown, @c Not-a-Number (NaN) is returned.
	*/
	
	/**
	
	* Gets the timestamp at which the data is collected. @n
    * This timestamp shows the time when the measurements are made. The time returned is the time in milliseconds of UTC time. The timestamp of the location 
	* using GPS is the UTC time fixed from the satellite. 
    *
    * @deprecated   This method is deprecated because a new method has been introduced. @n
	*				The timestamp of the WPS location data is wrongly shifted by UTC minus its local time. @n
	*				Instead of using this method, use the GetTimestampInUtc() method. 
	* 
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The timestamp indicating the time
	* @remarks   	If the location is invalid, the timestamp may be invalid. 
	*/
	long long GetTimestamp(void) const;

	/**
	*
	* Gets the timestamp at which the data is collected. @n
    * This timestamp shows the time when the measurements are made. The time returned is the time in milliseconds of UTC time. The timestamp of the location 
	* using GPS is the UTC time fixed from the satellite. 
	* 
	 * @deprecated	This method is deprecated.
	* @since  2.0
	*
	* @return		The timestamp indicating the time
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_INVALID_DATA 		The timestamp is @c 0.
	* @remarks 		The specific error code can be accessed using the GetLastResult() method.
	* @remarks   	If the location is invalid, the timestamp may be invalid or @c 0. 
	*/
	long long GetTimestampInUtc(void) const;
	
	/**
	*
	* Checks whether the specified %Location instance represents a valid location with coordinates or an invalid one where all the data, 
	* especially the latitude and longitude coordinates, may not be present. @n
	* 
	* If the %Location instance contains invalid coordinates, the GetErrorCode() method returns the related error code.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	@c true if the location is valid, @n
	*			else @c false
	* @see 		GetErrorCode()
	*/
	bool IsValid(void) const;

	/**
	*
	* Gets the error code if the location information is not valid. @n 
	* The returned error code may indicate the reason for the invalid location information.
	*
	* The following are the possible error codes for the location retrieved from LocationProvider:
	* @li 101: Valid location information cannot be determined.
	* @li 102: The location service is disabled by the user in system setting.
    *
    * The following are the possible error codes for the location retrieved from RemoteLocationProvider:
	* @li 103: User level access is not permitted.
	* @li 104: Application level access is not permitted due to unauthorized accesses 
	*           from applications which is not installed or disabled in system setting.
	* @li 105: The location is out of the search boundary.
	* 
	* If the location is valid, @c 0 is returned.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                   For more information, @ref LocationGetErrorCodePage "here".
	* @return 	@c 0 if the location is valid, @n 
	*			else an error code
	*/
	int GetErrorCode(void) const;

	/** 
	* @page LocationGetErrorCodePage Compatibility for GetErrorCode()
	*
	* @section LocationGetErrorCodePageIssuesSection Issues 
	* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
	* The error codes 101 and 102 are not supported. Therefore, the GetErrorCode() method may return @c 0 or @c 101 in case of error code 101, and may return @c 101 in case of error code 102.
	*
	* @section LocationGetErrorCodePageResultionsSection Resolutions 
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	*
	* @par When working with API versions prior to 2.0:
	* For an invalid location that is received from LocationProvider, an application can distinguish between error codes 101 and 102 using the @ref Osp::System::SettingInfo::GetValue (const Osp::Base::String &key, bool &value) method with @c GPSEnabled and @c WPSEnabled keys.
	*
	* If the corresponding location setting is disabled, invalid location is returned because of error code 102. Else, error code 101 is returned. 
	*/
	
	/**
	*
	* Gets the satellite information. @n
	* The satellite information is the external location information. If the location data does not have the satellite information, this method returns 
	* @c null.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return 		A pointer to the satellite information, @n
	*				else @c null if the satellite information is unknown
	*/
	const SatelliteInfo* GetSatelliteInfo(void) const;

	/**
	*
	* Overrides the equals() method in the Object class to compare the equality of values in two %Location objects. 
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref LocationEqualsPage "here".
	* @return       	@c true if all the fields in the objects are equal @n
	*					else @c false
	* @param[in] obj 	The Object with which the comparison is done 
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;

    /** 
    * @page	LocationEqualsPage	Compatibility for Equals()
    *
    * @section	LocationEqualsPageIssuesSection		Issues 
    * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n 
    * -# An application can be terminated when it compares the locations that do not have the coordinates or satellite information.
    * -# If a location contains @c NaN values, this method returns @c false even when the values of the corresponding properties 
    * of the two %Location objects are equal.
    *
    * @section	LocationEqualsPageResultionsSection		Resolutions 
    * The issues mentioned above are resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
    *
    * @par When working with bada API versions prior to 2.0:
    * An application should check each property in the %Location object.
    */

	/**
	* Overrides the GetHashCode() method in the %Object class to generate the hash value of the current instance.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	* @return	The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

protected:
    /**
	 * @internal
	 * This variable is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this variable.
	 *
	 * @deprecated	This variable is deprecated.
	 * @since 1.0
	 */
    MLocation* _pMLocation;
private:
	QualifiedCoordinates*	__pQualifiedCoordinates;
	SatelliteInfo* __pSatelliteInfo;

friend class LocationProvider; 
friend class RemoteLocationProvider;
friend class _LocationUtil;
friend class _RemoteUtil;
friend class __RemoteLocationMessage;

private:
	friend class LocationEx;
	class LocationEx* __pLocationEx;

};      // class Location

}; };     // Osp::Locations

#endif // _FLOC_LOCATION_H_
