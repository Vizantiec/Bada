/* $Change: 1232335 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/*
* @file		FUixWeatherTypes.h
* @brief	This is the header file for the ISensorEventListener interface.
*
* This header file contains the declarations of the common weather sensor related data types and constants.
*
*/

#ifndef _FUIX_WEATHER_TYPES_H_
#define _FUIX_WEATHER_TYPES_H_

// Includes
#include "FBase.h"

namespace Osp { namespace Uix {

/**
* @enum	WeatherType
* Defines the types of the weather data.
* @deprecated This enum is deprecated because it is not supported by the platform.
* @since 		1.0
*/
typedef enum{
	WEATHER_TYPE_CURRENT_WEATHER = 0,	/**< The current weather type */
	WEATHER_TYPE_WEATHER_FORECAST,	/**< The weather forecast type */
}WeatherType;

/**
* @internal
* This enum is for internal use only.
* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
* that might arise after using this enum.
* @deprecated This enum is deprecated because it is not supported by the platform.
* @since   1.0
*/
typedef enum
{
	WEATHER_ATTRIBUTE_LOCATION = 0,
	WEATHER_ATTRIBUTE_LONLAT,
	WEATHER_ATTRIBUTE_MAX
} WeatherAttribute;

/**
* @enum WeatherCondition
* Defines the values for different weather conditions.
* @deprecated This enum is deprecated because it is not supported by the platform.
* @since 		1.0
*/
typedef enum {
	WEATHER_CONDITION_CLOUDY = 0,	/**< The weather condition is cloudy  */
	WEATHER_CONDITION_FOG,	/**< The weather condition is fog */
	WEATHER_CONDITION_FRIGID,	/**< The weather condition is frigid */
	WEATHER_CONDITION_HAIL,	/**< The weather condition is hail */
	WEATHER_CONDITION_LIGHTENING,	/**< The weather condition is lightening */
	WEATHER_CONDITION_RAIN,	/**< The weather condition is rain */
	WEATHER_CONDITION_SMOKE,	/**< The weather condition is smoke */
	WEATHER_CONDITION_SNOW,	/**< The weather condition is snow */
	WEATHER_CONDITION_SUNNY,	/**< The weather condition is sunny */
	WEATHER_CONDITION_THUNDERSTORMS,	/**<The weather condition is thunderstorms */
	WEATHER_CONDITION_WINDY,	/**< The weather condition is windy */
	WEATHER_CONDITION_CLOUDY_AND_SUNNY	/**< The weather condition is cloudy and sunny */
} WeatherCondition;

/**
* @enum	CurrentWeatherKey
* Defines the list of current weather data parameters.
* @deprecated This enum is deprecated because it is not supported by the platform.
* @since 		1.0
*/
typedef enum{
	CURRENT_WEATHER_KEY_LOCATION = 0,	/**< The key for location where the weather information is received */
	CURRENT_WEATHER_KEY_CONDITION,	/**< The key for current weather condition */
	CURRENT_WEATHER_KEY_TEMPERATURE,	/**< The key for current temperature (unit: Degrees Celsius) */
	CURRENT_WEATHER_KEY_TEMPERATURE_FEELLIKE,	/**< The key for current wind chill temperature (unit: Degrees Celsius) */
	CURRENT_WEATHER_KEY_DEWPOINT,	/**< The key for current dew point (unit: Degrees Celsius) */
	CURRENT_WEATHER_KEY_HUMIDITY,	/**< The key for current humidity (unit: Percent RH(%)) */
	CURRENT_WEATHER_KEY_PRESSURE,	/**< The key for current pressure (unit: Millibar(mb)) */
	CURRENT_WEATHER_KEY_WIND_SPEED,	/**< The key for current wind speed (unit: Km/h) */
	CURRENT_WEATHER_KEY_WIND_DIRECTION,	/**< The key for current wind direction (unit: Degree) */
}CurrentWeatherKey;

/**
* @enum	WeatherForecastKey
* Defines the list of the weather forecast data.
* @deprecated This enum is deprecated because it is not supported by the platform.
* @since 		1.0
*/
typedef enum{
	WEATHER_FORECAST_KEY_LOCATION = 0,	/**< The key for location where the weather information is received */
	WEATHER_FORECAST_KEY_DATE,	/**< The key for weather forecast date */
	WEATHER_FORECAST_KEY_CONDITION,	/**< The key for weather condition */
	WEATHER_FORECAST_KEY_HIGH_TEMPERATURE,	/**< The key for the highest temperature */
	WEATHER_FORECAST_KEY_LOW_TEMPERATURE,	/**< The key for the lowest temperature */
}WeatherForecastKey;

}; }; // Osp::Uix

#endif // _FUIX_WEATHER_TYPES_H_
