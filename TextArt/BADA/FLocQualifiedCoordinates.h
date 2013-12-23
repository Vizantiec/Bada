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
* @file		FLocQualifiedCoordinates.h 
* @brief	This is the header file for the %QualifiedCoordinates class.
*
* This header file contains the declarations of %QualifiedCoordinates. @n 
* The class represents coordinates as latitude-longitude-altitude values that are associated with an accuracy value.
*/


#ifndef _FLOCATION_QUALIFIED_COORDINATES_H_
#define _FLOCATION_QUALIFIED_COORDINATES_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FLocCoordinates.h"

struct MQualifiedCoordinates;

namespace Osp { namespace Locations { 

/**
* @class	QualifiedCoordinates
* @brief	This class provides the methods for the qualified coordinates. 
* @deprecated	This class is deprecated.
* @since	1.0   
* 
* 	The %QualifiedCoordinates class provides the methods for the qualified coordinates and specifies the coordinates as latitude-longitude-altitude values that are 
* 			associated with an accuracy value.
*
*/
class _EXPORT_LOCATION_ QualifiedCoordinates :
public Coordinates{	// class inheritance

// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 		1.0
	 * @remarks	 	After creating an instance of this class, one of the Set() methods must be called explicitly to initialize this instance. 
	 * @see	Set()
	 */
	QualifiedCoordinates(void);
	/**
	* This is the copy constructor for the %QualifiedCoordinates class.
	*
	* @deprecated	This method is deprecated.
	* @since 	1.0
	*/
	QualifiedCoordinates(const QualifiedCoordinates& value);
	/**
	* This operator assigns the value of the specified %QualifiedCoordinates instance to the current instance.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		A reference to the current instance
	* @param[in]	rhs		An instance of %QualifiedCoordinates to assign
	*/
	QualifiedCoordinates& operator=(const QualifiedCoordinates& rhs);
	/** 
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since 	1.0
	 */
	~QualifiedCoordinates(void);
	
private:
	QualifiedCoordinates(MQualifiedCoordinates* pMQualifiedCoordinates);

// Operations
public:
 /**
	*
	* Gets the horizontal accuracy of the location in meters (1-sigma standard deviation). @n
	* @c Not-a-Number (NaN) is returned if the horizontal accuracy cannot be determined.
	* 
	* The horizontal accuracy is the RMS (root mean square) of east accuracy (latitudinal error in meters, 1-sigma standard deviation), and
	* north accuracy (longitudinal error in meters, 1-sigma standard deviation).
	*
	 * @deprecated	This method is deprecated.
	* @since 			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref GetHorizontalAccuracyPage "here".
	*
	* @return 		The horizontal accuracy in meters, @n
	*				else @c Not-a-Number (NaN) if the horizontal accuracy is unknown
	*/
	float GetHorizontalAccuracy(void) const;
	/**
	* @page	GetHorizontalAccuracyPage	Compatibility for GetHorizontalAccuracy()
	*
	* @section	GetHorizontalAccuracyPageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* Although the horizontal accuracy is unknown, it returns @c 0 instead of @c Not-a-Number (NaN).
	*
	* @section	GetHorizontalAccuracyPageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows. @n
	* From version 1.2, if the horizontal accuracy is unknown, then @c NaN is returned.
	*/

	/**
	*
	* Gets the accuracy of the location in meters in a vertical direction (orthogonal to an ellipsoidal surface, 1-sigma standard deviation). @n
	* @c Not-a-Number (NaN) is returned if the vertical accuracy cannot be determined.
	*
	 * @deprecated	This method is deprecated.
	* @since 			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref GetVerticalAccuracyPage "here".
	*
	* @return			The vertical accuracy in meters, @n
	*		  			else @c Not-a-Number (NaN) if the vertical accuracy is unknown
	*/
	float GetVerticalAccuracy(void) const;
	/**
	* @page		GetVerticalAccuracyPage		Compatibility for GetVerticalAccuracy()
	* @section	GetVerticalAccuracyPageIssueSection		Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* Although the vertical accuracy is unknown, it returns @c 0 instead of @c Not-a-Number (NaN).
	*
	* @section	GetVerticalAccuracyPageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows. @n
	* From version 1.2, if the vertical accuracy is unknown, then @c NaN is returned.
	*/
	
	/**
	*
	* Sets the horizontal accuracy of the location in meters (1-sigma standard deviation). @n
	* The horizontal accuracy is the RMS (root mean square) of the east 
	* accuracy (latitudinal error in meters, 1-sigma standard deviation), and the north accuracy (longitudinal error in meters, 1-sigma standard deviation).
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
    * @return         An error code
	* @param[in]	horizontalAccuracy  	The horizontal accuracy @n
	*										else Not-a-Number (NaN) if the horizontal accuracy cannot be determined @n
	*										Must be greater than or equal to @c 0.
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_ARG 			The specified input parameter is less than @c 0.
	* @see			GetHorizontalAccuracy()
	*/
	result SetHorizontalAccuracy(float horizontalAccuracy);
	
	/**
	*
	* Sets the accuracy of the location in meters in a vertical direction (orthogonal to ellipsoid surface, 1-sigma standard deviation). @n
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
    * @return         An error code
	* @param[in]	verticalAccuracy  	The vertical accuracy
	*									else Not-a-Number (NaN) if the vertical accuracy cannot be determined @n
	*									Must be greater than or equal to @c 0.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified input parameter is less than @c 0.
	* @see GetVerticalAccuracy()
	*/
	result SetVerticalAccuracy(float verticalAccuracy);
	
	/**
	* Sets the specified latitude, longitude, altitude, horizontal accuracy, and vertical accuracy values.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code
	* @param[in] 	latitude			The latitude of the location in the range [-90.0, 90.0] @n
	*								 	Positive values indicate the northern latitude and negative values, the southern latitude.
	* @param[in] 	longitude			The longitude of the location in the range [-180.0, 180.0] @n
	*								 	Positive values indicate the eastern longitude and negative values, the western longitude.
	* @param[in] 	altitude			The altitude of the location in meters, defined as the height above the WGS 84 ellipsoid @n 
	*								 	@c Not-a-Number (NaN) can be used to indicate that the altitude is not known.
	* @param[in] 	horizontalAccuracy  The horizontal accuracy of the result of this location in meters
	* @param[in] 	verticalAccuracy	The vertical accuracy of the result of this location in meters
	* @exception 	E_SUCCESS			The method is successful.
	* @exception 	E_INVALID_ARG		An input parameter is out of the valid range.
	* @exception 	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	result Set(double latitude, double longitude, float altitude, float horizontalAccuracy, float verticalAccuracy);

// Methods inherited from Coordinates	
	/**
	* Calculates the azimuth value between the two points. @n
	* The azimuth value is relative to true north. The calling %QualifiedCoordinates instance is considered as the origin for calculation and the parameter 
	* is the destination to which the azimuth value is calculated. @n
	* If the origin is the North pole and the destination is not the North pole, this method returns @c 180.0. @n
	* If the origin is the South pole and the destination is not the South pole, this method returns @c 0.0. @n
	* If the origin is equal to the destination, this method returns @c 0.0. 
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		The azimuth value to the destination in degrees in the range [0.0 ,360.0]
	* @param[in] 	to		The coordinates of the destination
    * @remarks      Geographical calculation of the azimuth value is based on the spherical earth and not the WGS 84 Ellipsoid.
	*/
	virtual float GetAzimuthTo(const QualifiedCoordinates& to);

	/**
	* Converts a string representation of the coordinates into a double representation. @n
	*
	* There are two string syntaxes supported: @n
	*
	* <b> 1. Degrees, minutes, seconds, and decimal fractions of seconds. </b> @n
	*
	* This is expressed as a string complying with the following EBNF definition, where the degrees are within the [-179, 179] range 
	* and the minutes and seconds are within the [0, 59] range; or the degree is -180 or 180 and the minutes, seconds, and decimal fractions are 0: @n
	*<pre>	
	*coordinate   	= degrees ":" minutes ":" seconds "." decimalfrac | 
	*		  degrees ":" minutes ":" seconds  | 
	*		  degrees ":" minutes 
	*degrees      	= degreedigits | "-" degreedigits 
	*degreedigits 	= digit | nonzerodigit digit | "1" digit digit  
	*minutes      	= minsecfirstdigit digit 
	*seconds      	= minsecfirstdigit digit 
	*decimalfrac  	= 1*3digit 
	*digit        	= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" |"9" 
	*nonzerodigit 	= "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
	*minsecfirstdigit = "0" | "1" | "2" | "3" | "4" | "5" 
	*</pre>
	*
	* <b> 2. Degrees, minutes, and decimal fractions of minutes. </b>@n
	*
	* This is expressed as a string complying with the following EBNF definition, where the degrees are within the [-179, 179] range  
	* and the minutes are within the [0, 59] range; or the degree is -180 or 180 and the minutes and decimal fractions are 0: @n
	*<pre>	
	*coordinate   	= degrees ":" minutes "." decimalfrac | 
	*		  degrees ":" minutes
	*degrees      	= degreedigits | "-" degreedigits
	*degreedigits 	= digit | nonzerodigit digit | "1" digit digit
	*minutes      	= minsecfirstdigit digit
	*decimalfrac  	= 1*5digit
	*digit        	= "0" | "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" |"9"
	*nonzerodigit 	= "1" | "2" | "3" | "4" | "5" | "6" | "7" | "8" | "9"
	*minsecfirstdigit = "0" | "1" | "2" | "3" | "4" | "5"
	*</pre>
	*
	* For example, for the @c double value of the coordinate 61.51d, the corresponding syntax 1(DD_MM_SS) String is "61:30:36" and 
	* the corresponding syntax 2(DD_MM) String is "61:30.6". @n
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code
	* @param[in]	coordinate			A string in either of the two representations specified above
	* @param[out] 	value				A @c double value with decimal degrees based on the string representation	given as the parameter
	* @exception	E_SUCCESS			The method is successful.
	* @exception  E_INVALID_ARG	The specified @c coordinate does not comply with the defined syntax or is empty.
	* @see			Convert()
	*/
	static result Convert(const Osp::Base::String& coordinate, double& value);
	
    /**
	* Converts a double representation of the coordinates with decimal degrees into a string representation. @n
	* The string syntaxes supported are the same as for the Convert() method. @n
	* For example, for the double value of the coordinate 61.51d, 
	* the corresponding syntax 1(DD_MM_SS) string is "61:30:36" and the corresponding syntax 2(DD_MM) string is "61:30.6". @n
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code
	* @param[in]	coordinate		A @c double representation of a coordinate
	* @param[in]	outputType		A StringCoordinateType enumerator member identifying the type of the string output desired
	* @param[out] 	strCoordinate	The string representation of the coordinates
	* @exception	E_SUCCESS		The method is successful.
	* @exception 	E_INVALID_ARG 	The specified @c outputType is not a valid %StringCoordinateType, or @n
	*								the specified coordinate value is not in the valid range of [-180.0, +180.0] or is not a valid double number.
	* @see			Convert()
	*/
	static result Convert(double coordinate, StringCoordinateType outputType, Osp::Base::String& strCoordinate);

    /**
	*
	* Calculates the geodetic distance between the calling instance and the specified instance, according to the ellipsoid model of WGS 84. @n
	* The altitude is exempted from calculations.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The distance to the destination in meters
	* @param[in]	to		The %QualifiedCoordinates of the destination
	*/
	virtual float Distance(const QualifiedCoordinates& to) const;

	/**
	*
	* Gets the altitude component of this coordinate. @n
	* The altitude is defined as the height above the WGS 84 reference ellipsoid. @c 0.0 means a location at the ellipsoid surface and negative values mean 
	* that the location is below the ellipsoid surface. 
	*
	 * @deprecated	This method is deprecated.
	* @since 			1.0
	* @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	*					For more information, see @ref GetAltitudePage "here".
	*
	* @return			The altitude in meters above the reference ellipsoid, @n
	*					else @c Not-a-Number (NaN) if the altitude is not available
	*/
	virtual float GetAltitude(void) const;
	
	/**
	* 
	* Gets the latitude component of this coordinate. @n
	* Positive values indicate the northern latitude and negative values indicate the southern latitude.
	*
	 * @deprecated	This method is deprecated.
	* @since 	1.0
	* @return	The latitude in degrees
	* @see		SetLatitude()
	*/
	virtual double GetLatitude(void) const;
	
    /**
	*
	* Gets the longitude component of this coordinate. @n
	* Positive values indicate the eastern longitude and negative values indicate the western longitude.
	*
	 * @deprecated	This method is deprecated.
	* @since 	1.0
	* @return	The longitude in degrees
	* @see		SetLongitude()
	*/
	virtual double GetLongitude(void) const;
	
    /**
	*
	* Sets the geodetic altitude for this point.
	* 
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @param[in]	altitude	The altitude of the location in meters, defined as the height above the WGS 84 ellipsoid @n
	*							@c 0.0 means a location at the ellipsoid surface; a negative value means the location is below the ellipsoid surface. 
	* @see 			GetAltitude()
	*/
	virtual void SetAltitude(float altitude);
	
	/**
	*
	* Sets the latitude for this coordinate. @n
	* The latitude is given as @c double type expressing the latitude in degrees according to the WGS 84 datum.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code	
	* @param[in]	latitude		The latitude component of the location in degrees in the range [-90.0, 90.0]	
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG 	The input parameter is out of the valid range.
	* @see 			GetLatitude()
	*/
	virtual result SetLatitude(double latitude);
	
	/**
	*
	* Sets the geodetic longitude for this point. @n
	* The longitude is given as @c double type expressing the longitude in degrees according to the WGS 84 datum.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code
	* @param[in]	longitude		The longitude of the location in degrees in the range [-180.0, 180.0]
	* @exception	E_SUCCESS		The method is successful.
	* @exception  	E_INVALID_ARG 	The input parameter is out of the valid range.
	* @see 			GetLongitude()
	*/
	virtual result SetLongitude(double longitude);

	/**
	*
	* Overrides the equals() method in the Object class to compare the equality of values in two %QualifiedCoordinates objects. @n
	* Since the longitude values @c -180 and @c 180 denote the same longitude, they must be considered equal.
	*
	 * @deprecated	This method is deprecated.
	* @since 			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref QualifiedCoordinatesEqualsPage "here".
	* @return       	@c true if all the fields in the objects are equal, @n
	*					else @c false
	* @param[in] 		obj 	The Object with which the comparison is done 
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;

    /** 
    * @page QualifiedCoordinatesEqualsPage	Compatibility for Equals()
    *
    * @section QualifiedCoordinatesEqualsPage	IssuesSection	Issues 
    * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n 
    * -# If the %QualifiedCoordinates instance contains @c NaN values, 
    *  this method returns @c false even when the values of the corresponding properties of the two %QualifiedCoordinates objects are equal.
    * -# If the longitudes of the two %QualifiedCoordinates objects are @c -180 and @c 180, 
    *  this method returns @c false even when the values of the corresponding properties of the two %QualifiedCoordinates objects are equal.
    *
    * @section QualifiedCoordinatesEqualsPage	ResultionsSection	Resolutions 
    * The issues mentioned above are resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
    *
    * @par 
	* When working with bada API versions prior to 2.0:
    * An application should check each property in the %QualfiedCoordinates instance.
    */

	/**
	* Overrides the GetHashCode() method in the Object class to generate the hash value of the current instance.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;
	

// Attribute
private:
	MQualifiedCoordinates* __pMQualifiedCoordinates;

friend class Landmark;
friend class Location;
friend class Coordinates;

private:
	friend class QualifiedCoordinatesEx;
	class QualifiedCoordinatesEx* __pQualifiedCoordinatesEx;

};		// class QualifiedCoordinates

}; };     // Osp::Locations


#endif // _FLOCATION_QUALIFIED_COORDINATES_H_
