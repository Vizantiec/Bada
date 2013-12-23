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
* @file		FLocCoordinates.h 
* @brief	This is the header file for the %Coordinates class.
*
* This header file contains the declarations of the %Coordinates class. @n 
* The class specifies the coordinates as latitude-longitude-altitude values.
*/

#ifndef _FLOC_COORDINATES_H_
#define _FLOC_COORDINATES_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"

struct MCoordinates;

namespace Osp { namespace Locations { 

/**
* @enum     StringCoordinateType
* Defines the different representations of the coordinates.
*
* @deprecated	This enumerated type is deprecated.
* @since 1.0
*/
typedef enum  
{
	/**
	*An identifier for a string coordinate representing degrees, minutes, and decimal fractions of a minute
	*/
	DD_MM = 1,
	/** 
	*An identifier for a string coordinate representing degrees, minutes, seconds, and decimal fractions of a second
	*/
	DD_MM_SS = 2
}StringCoordinateType;

/**
* @class	Coordinates
* @brief	This class provides the methods to manipulate the coordinates.    
* @deprecated	This class is deprecated.
* @since	1.0
* 
* The %Coordinates class provides the methods to manipulate the coordinates, that is, the latitude-longitude-altitude values: @n
*			- The latitude and longitude values are expressed in degrees using floating point numbers.
*			- The degrees are in decimal values instead of minutes/seconds.
*			- The coordinates are given using the WGS 84 datum. @n
*
* 			This class also provides the methods for converting a String coordinate representation into a double coordinate representation and vice versa.
*
*/
class _EXPORT_LOCATION_ Coordinates :
public Osp::Base::Object{
// Lifecycle
public:
	/** 
	 * This is the default constructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 * @remarks 	After creating an instance of this class, the Set() method must be called explicitly to initialize this instance.
	 *
	 * @see			Set()
	 */
	Coordinates(void);
	
	/**
	* This is the copy constructor for the %Coordinates class.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref CoordinatesCoordinatesPage "here".
    * 
	*/
	Coordinates(const Coordinates& value);

    /** 
    * @page	CoordinatesCoordinatesPage	Compatibility for Coordinates()
    *
    * @section	CoordinatesCoordinatesPageIssuesSection		Issues 
    * Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
    * If the source object of the %Coordinates copy constructor is of type QualifiedCoordinates, 
    * the properties of the coordinates are reset to zero.
    *
    * @section	CoordinatesCoordinatesPageResultionsSection		Resolutions 
    * The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
    *
    * @par When working with bada API versions prior to 2.0:
    * An application should copy each property in the %Coordinates instance if it uses the %QualifiedCoordinates object for copying the source object.
    */
    
	
	/**
	* This operator copies the value of the specified instance to the current instance.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		A reference to the current instance
	* @param[in]	rhs		An instance of %Coordinates to be assigned
	*/
	Coordinates& operator=(const Coordinates& rhs);
	
	/** 
	 * This is the destructor for this class.
	 *
	 * @deprecated	This method is deprecated.
	 * @since		1.0
	 */
	virtual ~Coordinates(void);
	
private:
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
	 * @deprecated	This method is deprecated.
     * @since   1.0
	 */
	Coordinates(MCoordinates* pMCoordinates);

// Operations
public:
	/**
	* Calculates the azimuth value between the two points. @n
	* The azimuth value is relative to true north. The calling %Coordinates instance is considered as the origin for calculation and the parameter is the 
	* destination to which the azimuth value is calculated. @n 
	* - If the origin is the North pole and the destination is not the North pole, this method returns @c 180.0. 
	* - If the origin is the South pole and the destination is not the South pole, this method returns @c 0.0. 
	* - If the origin is equal to the destination, this method returns @c 0.0. 
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		The azimuth value of the destination in degrees within the range [0.0 ,360.0]
	*
	* @param[in] 	to		The coordinates of the destination
    * @remarks      Geographical calculation of the azimuth value is based on the spherical earth and not the WGS 84 Ellipsoid.
	*/
	virtual float GetAzimuthTo(const Coordinates& to);

	/**
	* Converts a double representation of the coordinates with decimal degrees into a string representation. @n
	* The string syntaxes supported are the same as for the Convert() method. @n
	* For example, for the double value of the coordinate 61.51d, the corresponding syntax 1(DD_MM_SS) string is "61:30:36" and the corresponding syntax 
	* 2(DD_MM) string is "61:30.6".
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code
	* @param[in]	coordinate		An @c double representation of a coordinate
	* @param[in]	outputType		A StringCoordinateType enum member identifying the type of the string output desired
	* @param[out]	strCoordinate	The string representation of the coordinates
	* @exception	E_SUCCESS		The method is successful.
	* @exception 	E_INVALID_ARG 	Either of the following conditions has occurred: @n
	*								- The specified @c outputType is not a valid StringCoordinateType. @n 
	*								- The specified coordinate value is not in the valid range of [-180.0, +180.0]. @n
	*								- The specified coordinate value is not a valid double number.
	* @see			Convert()
	*/
	static result Convert(double coordinate, StringCoordinateType outputType, Osp::Base::String& strCoordinate); 
	
	/**
	* Converts a string representation of the coordinates into a double representation. @n
	*
	* There are two string syntaxes supported: @n
	*
	* <b> 1. Degrees, minutes, seconds, and decimal fractions of seconds. </b> @n
	*
	* This is expressed as a string complying with the following Extended Backus-Naur Form (EBNF) definition, where the degrees are within the [-179, 179] 
	* range and the minutes and seconds are within the [0, 59] range; or the degree is -180 or 180 and the minutes, seconds, and decimal fractions are 0: @n
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
	* @since		1.0
	* @return		An error code
	* @param[in]	coordinate		A string in either of the two representations specified above
	* @param[out] 	value			The @c double value with decimal degrees based on the string representation given as the parameter
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG	The specified @c coordinate does not comply with the defined syntax or is empty.
	* @see			Convert()
	*/
	static result Convert(const Osp::Base::String& coordinate, double& value);

	/**
	*
	* Calculates the geodetic distance between the calling instance and the specified instance, according to the ellipsoid model of WGS 84. @n
	* The altitude is exempted from calculations.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The distance to the destination in meters
	* @param[in]	to		The coordinates of the destination
	*/
	virtual float Distance(const Coordinates& to) const;

	/**
	*
	* Gets the altitude component of this coordinate. @n
	* The altitude is defined as the height above the WGS 84 reference ellipsoid. @n
	* The @c 0.0 value means a location on the ellipsoid surface. However, a negative value means that the location is below the ellipsoid surface. 
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
	* @page			GetAltitudePage		Compatibility for GetAltitude()
	* @section		GetAltitudePageIssueSection	Issues
	* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n
	* When the altitude is unknown, this method returns @c 0 instead of @c Not-a-Number (NaN).
	*
	* @section		GetAltitudePageResolutionSection	Resolutions
	* The issue mentioned above is resolved in bada API version 1.2 as follows: @n
	* From version 1.2, if the altitude is unknown, @c Not-a-Number (NaN) is returned.
	*/

	/**
	* 
	* Gets the latitude component of this coordinate. @n
	* The positive values indicate the northern latitude and the negative values indicate the southern latitude.
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
	* The positive values indicate the eastern longitude and the negative values indicate the western longitude.
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
	* The latitude is specified in degrees using the @c double type format according to the WGS 84 datum.
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
	* The longitude is specified in degrees using the @c double type format according to the WGS 84 datum.
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
	* Sets the specified latitude, longitude, and altitude for the calling instance.
	*
	 * @deprecated	This method is deprecated.
	* @since 		1.0
	* @return		An error code
	* @param[in]	latitude		The latitude of the location @n
	*								Valid range: [-90.0, 90.0]. Positive values indicate the northern latitude and negative values the southern latitude.
	* @param[in]	longitude		The longitude of the location @n
	*								Valid range: [-180.0, 180.0]. Positive values indicate the eastern longitude and negative values the western longitude.
	* @param[in]	altitude		The altitude of the location in meters, defined as the height above the WGS 84 ellipsoid @n 
	*								@c Not-a-Number (NaN) can be used to indicate that the altitude is not known 
	*
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_OUT_OF_MEMORY The memory is insufficient.
	* @exception	E_INVALID_ARG	An input parameter is out of the valid range.
	*/
	result Set(double latitude, double longitude, float altitude);
	
	/**
	*
	* Compares the calling instance with the specified instance for equality. @n
	* Since the longitude values @c -180 and @c 180 denote the same longitude, they are considered to be equal.
	*
	 * @deprecated	This method is deprecated.
	* @since 			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, @ref CoordinatesEqualsPage "here".
    * 
	* @return			@c true if all the fields in the objects are equal, @n
	*					else @c false
	* @param[in] 		obj 	The object to be compared
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;
    
    /** 
    * @page	CoordinatesEqualsPage	Compatibility for Equals()
    *
    * @section	CoordinatesEqualsPage	IssuesSection	Issues 
    * Implementation of this method in bada API versions prior to 2.0 has the following issues: @n 
    * -# If the %Coordinates object contains @c NaN values, this method returns @c false even when the values of the corresponding properties of the two 
	* %Coordinates objects are equal.
    * -# If longitudes of two Coordinates objects are @c -180 and @c 180, 
    *  this method returns @c false even when the values of the corresponding properties of two Coordinates objects are equal.
    *
    * @section	CoordinatesEqualsPage	ResultionsSection	Resolutions 
    * The issues mentioned above are resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
    *
    * @par When working with bada API versions prior to 2.0:
    * An application should check each property in the %Coordinates object.
    */
    
	
   /** 
	* Generates the hash value of the calling instance.
	*
	 * @deprecated	This method is deprecated.
	* @since 	1.0
	* @return	The hash value of the calling instance
	*/
	virtual int GetHashCode(void) const;

// Attributes
private:
       MCoordinates* __pMCoordinates; 

	   friend class GeographicArea;
       friend class CircleGeographicArea;
       friend class RectangleGeographicArea;
       friend class PolygonGeographicArea;
	   friend class LandmarkStore;
	   friend class RemoteLandmarkStore;

private:
	friend class CoordinatesEx;
	class CoordinatesEx* __pCoordinatesEx;

};      // class Coordinates

}; };    // Osp::Locations


#endif // _FLOC_COORDINATES_H_
