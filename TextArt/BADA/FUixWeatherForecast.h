/* $Change: 1248480 $ */
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
 * @file		FUixWeatherForecast.h
 * @brief		This is the header file for the %WeatherForecast class.
 *
 * This header file contains the declarations of the %WeatherForecast class.
 */
#ifndef _FUIX_WEATHER_FORECAST_H_
#define _FUIX_WEATHER_FORECAST_H_

// Include
#include "FUixWeatherTypes.h"
#include "FUixWeatherSensor.h"

namespace Osp { namespace Uix {

/**
* @class WeatherForecast
* @brief This class encapsulates one day's weather forecast.
* @deprecated This class is deprecated because it is not supported by the platform.
* @since 1.0
*
* The %WeatherForecast class includes a weather forecast for one future day, containing information about the temperature and weather conditions.
*/
class _EXPORT_UIX_ WeatherForecast :
	public Osp::Base::Object
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 1.0
	*/
	WeatherForecast(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 1.0
	*/
    virtual ~WeatherForecast(void);

public:
	/**
	* Gets where the weather is sensed. @n
	* Location includes city, state and county.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
      *
	* @return			An error code
	* @param[out]	location 			The location for which weather is sensed
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND 	The data does not exist.
	*/
	result GetLocation(Osp::Base::String& location);

	/**
	* Gets the date of the weather forecast.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
      *
	* @return			An error code
	* @param[out]	date 				The date of the forecast
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_DATA_NOT_FOUND 	The data does not exist.
	*/
	result GetDate(Osp::Base::DateTime& date);

	/**
	* Gets the weather condition.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
      *
	* @return			The weather condition
	* @see 				WeatherCondition
	*/
	WeatherCondition GetCondition(void);

	/**
	* Gets the highest / lowest temperature.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
      *
	* @param[out]	highTemperature			The high temperature (unit : Degree Celsius)
	* @param[out]	lowTemperature			The low temperature (unit : Degree Celsius)
	*/
	void GetTemperature(float& highTemperature, float& lowTemperature);

private:
    Osp::Base::String __location;
	Osp::Base::DateTime __date;
	WeatherCondition __condition;
	float __highTemperature;
	float __lowTemperature;

public:
	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets where the weather is sensed. Location includes city, state and county.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
	*/
	result SetLocation(Osp::Base::String& location);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the date of the weather forecast.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
	*/
	result SetDate(Osp::Base::DateTime &date);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the weather condition.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
	*/
	void SetCondition(WeatherCondition condition);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* Sets the highest / lowest temperature.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 			1.0
	*/
	void SetTemperature(float highTemperature, float lowTemperature);

private:
	friend class WeatherForecastEx;
	class WeatherForecastEx* __pWeatherForecastEx;
};

}; };	// Osp::Uix
#endif // _FUIX_WEATHER_FORECAST_H_
