/* $Change: 1267885 $ */
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
 * @file		FUixCurrentWeather.h
 * @brief		This is the header file for the %CurrentWeather class.
 *
 * This header file contains the declarations of the %CurrentWeather class.
 */
#ifndef _FUIX_CURRENT_WEATHER_H_
#define _FUIX_CURRENT_WEATHER_H_

// Includes
#include "FUixWeatherTypes.h"
#include "FUixWeatherSensor.h"

namespace Osp { namespace Uix {

/**
* @class CurrentWeather
* @brief This class stores the current weather data.
* @deprecated This class is deprecated because it is not supported by the platform.
* @since 1.0
*
* The %CurrentWeather class includes the current weather data, such as temperature, pressure, or wind.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/uix/weather_sensor.htm">Weather Sensor</a>.

*/
class _EXPORT_UIX_ CurrentWeather :
	public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 1.0
	*/
	CurrentWeather(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 1.0
	*/
    virtual ~CurrentWeather(void);

public:
	/**
	* Gets the location where the weather is sensed. @n
	* The location includes city, state and country.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since			1.0
      *
	* @return			An error code
	* @param[out]	location 			The location for which the weather is sensed
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND 	The data does not exist.
	*/
	result GetLocation(Osp::Base::String& location);

	/**
	* Gets the current weather condition.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	* @return		The current weather condition
	*
	* @see 			WeatherCondition
	*/
	WeatherCondition GetCondition(void);

	/**
	* Gets the current temperatures including the actual temperature, wind chill temperature, and dew point.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since			1.0
      *
	* @param[out]	temperature			The current temperature in degree Celsius 
	* @param[out]	temperatureFeellike	The current wind chill temperature in degree Celsius
	* @param[out]	dewPoint			The current dew point in degree Celsius
	*/
	void GetTemperature(float& temperature, float& temperatureFeellike, float& dewPoint);

	/**
	* Gets the current humidity.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
      *
	* @return		The current humidity(RH) in percentage
	*/
	float GetHumidity(void);

	/**
	* Gets the current pressure.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
      *
	* @return		The current pressure in millibars (mb) 
	*/
	float GetPressure(void);

	/**
	* Gets the current wind speed and direction.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since			1.0
      *
	* @param[out]	windSpeed			The current wind speed in kilometer per hour (km/h)
	* @param[out]	windDirection		The current wind direction in degrees with a range between @c 0 to @c 360
	*/
	void GetWind(float& windSpeed, float& windDirection);

private:
    Osp::Base::String __location;
	WeatherCondition __condition;
    float 	__temperature;
    float 	__temperatureFeelLike;
    float 	__dewPoint;
	float 	__humidity;
	float 	__pressure;
	float 	__windSpeed;
	float	__windDirection;

public:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets location where the weather is sensed. Location includes city, state and country.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	*/
	result SetLocation(Osp::Base::String& location);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the current weather condition.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	*/
	void SetCondition(WeatherCondition condition);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the current temperatures including actual temperature, wind chill temperature, and dew point.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	*/
	void SetTemperature(float temperature, float temperatureFeellike, float dewPoint);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the current humidity.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	*/
	void SetHumidity(float humidity);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the current pressure.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	*/
	void SetPressure(float pressure);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the current wind speed and direction.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since		1.0
	*/
	void SetWind(float windSpeed, float windDirection);

private:
	friend class CurrentWeatherEx;
	class CurrentWeatherEx* __pCurrentWeatherEx;
};

}; };	// Osp::Uix
#endif // _FUIX_CURRENT_WEATHER_H_
