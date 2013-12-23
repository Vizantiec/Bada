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
 * @file		FUixWeatherSensor.h
 * @brief		This is the header file for the %WeatherSensor class.
 *
 * This header file contains the declarations of the %WeatherSensor class.
 */
#ifndef _FUIX_WEATHER_SENSOR_H_
#define _FUIX_WEATHER_SENSOR_H_

// Include
#include "FUixConfig.h"
#include "FBase.h"
#include "FUixIWeatherEventListener.h"
#include "FUixWeatherTypes.h"

// Forward declaration - SC layer
struct IMSensorManager;
struct TagBoolExp;
typedef struct TagBoolExp BoolExp;

namespace Osp { namespace Uix {

/**
* @class WeatherSensor
* @brief This class is used to enable receiving the weather data from the server.
* @deprecated This class is deprecated because it is not supported by the platform.
* @since 1.0
*
* The %WeatherSensor class is used to manage a weather service. @n
*
* The %WeatherSensor class can check whether the service is available and request the current weather or a weather forecast.
* An application can receive weather data asynchronously by constructing (registering a listener and providing the location) a
* %WeatherSensor.
*
* @see CurrentWeather, WeatherForecast
*
* The following example demonstrates how to use the %WeatherSensor class.
*
* @code
*  //Sample Code for WeatherSample.h
*  #include <FUix.h>
*
*  using namespace Osp::Uix;
*  class WeatherSample : public IWeatherEventListener
*  {
*  		public:
*  			WeatherSample(void);
*  			virtual ~WeatherSample(void);
*  			bool Initialize_Location(void);
*  			bool Initialize_LonLat(void);
*  			void OnCurrentWeatherReceived(CurrentWeather& currentWeather, result r);
*  			void OnWeatherForecastReceived(Osp::Base::Collection::IList* pWeatherForecastList, result r);
*  		private:
*  			Osp::Uix::WeatherSensor __weatherSensor;
*  };
*
*	//Sample Code for WeatherSample.cpp
*	#include "WeatherSample.h"
*
*	WeatherSample::WeatherSample(void)
*	{
*	}
*	
*	WeatherSample::~WeatherSample(void)
*	{
*	}
*	
*	void WeatherSample::OnCurrentWeatherReceived(CurrentWeather& currentWeather, result r)
*	{
*		// Add your code
*  		// Application methods including the WeatherSensor methods should not be called inside this event handler.
*  		// Override OnCurrentWeatherReceived() for receiving the data and copying it out to the main application context.
*
*  		Osp::Base::String location;
*  		WeatherCondition cond;
*  		float temp = 0.0, tempFL = 0.0, dewP = 0.0, humi = 0.0, press = 0.0, windS = 0.0, windD = 0.0;
*
*  		if (!IsFailed(r))
*  		{
*  			currentWeather.GetLocation(location);
*  			cond = currentWeather.GetCondition();
*  			currentWeather.GetTemperature(temp, tempFL, dewP);
*  			humi = currentWeather.GetHumidity();
*  			press = currentWeather.GetPressure();
*  			currentWeather.GetWind(windS, windD);
*  		}
*   }
*
*   void WeatherSample::OnWeatherForecastReceived(Osp::Base::Collection::IList* pWeatherForecastList, result r)
*   {
*     	Osp::Base::String location;
*  		WeatherCondition cond;
*  		float highT = 0.0, lowT = 0.0;
*  		Osp::Base::DateTime date;
*
*  		if (!IsFailed(r))
*  		{
*  			for(int i = 0; i < pWeatherForecastList->GetCount(); i++)
*  			{
*  				WeatherForecast* pWeatherForecast = (WeatherForecast*)(pWeatherForecastList->GetAt(i));
*  				pWeatherForecast->GetLocation(location);
*  				cond = pWeatherForecast->GetCondition();
*  				pWeatherForecast->GetTemperature(highT, lowT);
*  				pWeatherForecast->GetDate(date);
*  				delete pWeatherForecast;
*  			}
*     	}
*   }
*
*   bool WeatherSample::Initialize_Location(void)
*	{
*    	result r = E_SUCCESS;
*
*  		r = __weatherSensor.Construct(*this);
*
*  		if (IsFailed(r))
*  			return false;
*  		else
*  		{
*  			r = __weatherSensor.RequestCurrentWeather(Osp::Base::String(L"Seoul,South Korea"));
*    			if (IsFailed(r))
*    				return false;
*  		}
*
*    		return true;
*  	}
*
*  	bool WeatherSample::Initialize_LonLat(void)
*  	{
*  		result r = E_SUCCESS;
*  		r = __weatherSensor.Construct(*this);
*  		if (IsFailed(r))
*  			return false;
*  		else
*  		{
*  			r = __weatherSensor.RequestCurrentWeather(37.55, 126.8);
*  			if (IsFailed(r))
*  				return false;
*  		}
   		return true;
*	}
* @endcode
* @n
*/
class _EXPORT_UIX_ WeatherSensor :
	public Osp::Base::Object
{
public:
// Lifecycle

	/**
	* This is the default constructor for this class.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 		1.0
      *
	* @remarks	After creating an instance of this class, you must explicitly call Construct() method to initialize the instance.
	*/
		WeatherSensor(void);

	/**
	* This is the destructor for this class.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 		1.0
	*/
	virtual ~WeatherSensor(void);

	/**
	* Initializes this instance of %WeatherSensor with the specified listener.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 		1.0
      *
	* @return		An error code
	* @param[in]	listener			The weather listener to receive the weather data
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @remarks		The instance should be constructed using this method to appropriately initialize the member variables.
	*/
	result Construct(const IWeatherEventListener& listener);

	/**
	* Gets the current weather data.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 					1.0
	* @compatibility  This method has compatibility issues with different bada API versions. @n
	* 								For more information, see issues in version @ref CompWeatherSensorRequestCurrentWeatherPage "1.1", @ref CompRequestCurrentWeatherMemoryLeakPage "1.2", and @ref CompWeatherSensorUrlSpacePage "2.0".
	*
	* @return		An error code
	* @param[in]	location 			The location for which the weather data is requested @n
	*									The value should be a string such as "Seoul, South Korea", "Austin, Texas".
	*									In USA, the location is composed of city and state.
	*									For other countries, in general, the location is composed of city and country.
	*									To check the validity of the location argument value, please refer to the following list of city names.
	*									<a href="http://weather.weatherbug.com/corporate/products/API/IntlCityCodes.zip
">http://weather.weatherbug.com/corporate/products/API/IntlCityCodes.zip</a>
	*									You can also check the validity by using WeatherBug's API and parsing the XML output.
	*									But in this case, you first need to sign-up and join the weatherbug.com before you use the API. For more details, please see the following page.
	*									<a href="http://weather.weatherbug.com/corporate/products/API/help.aspx
">http://weather.weatherbug.com/corporate/products/API/help.aspx</a>
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_INVALID_STATE 	The method cannot provide the current weather data.
   	*/
	result RequestCurrentWeather(const Osp::Base::String location);

	/**
	* @page   CompWeatherSensorRequestCurrentWeatherPage Compatibility for RequestCurrentWeather()
	* @section CompWeatherSensorRequestCurrentWeatherPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
	*
	* -# This method does not work as expected if the location is greater than 40 characters. @n
	* -# The maximum length can vary up to 40 characters, and it also depends on the memory status. @n
	*
	* @section CompWeatherSensorRequestCurrentWeatherPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	*/

	/**
	* Gets the current weather data.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 					1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 1.2. @n
	* 								For more information, see @ref CompRequestCurrentWeatherMemoryLeakPage "here".
	*
	* @return		An error code
	* @param[in]	longitude 			The value of longitude
	* @param[in]	latitude 			The value of latitude
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE 	The method cannot provide the current weather data.
	*/
	result RequestCurrentWeather(float longitude, float latitude);

	/**
	* @page   CompRequestCurrentWeatherMemoryLeakPage Compatibility for RequestCurrentWeather
	* @section CompRequestCurrentWeatherMemoryLeakPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	*
	* -# Memory leak occurs when the weather data is requested and the result is not received successfully from the server. @n
	* -# A recursive request of weather data may result in memory shortage if receiving the weather data fails every time. @n
	*
	* @section CompRequestCurrentWeatherMemoryLeakPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	*
	*/

	/**
	* @page   CompWeatherSensorUrlSpacePage Compatibility for RequestCurrentWeather()
	* @section CompWeatherSensorUrlSpacePageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
	*
	* When working with bada API versions prior to 2.0:
	* An application should remove the space between two arguments(city and state/country). For example, for a location value "Austin, Texas" , an application should use the location value "Austin,Texas".
	* Note that a space inside city string such as "San Francisco,CA" works correctly.
	*
	* @section CompWeatherSensorUrlSpacePageResolutionSection Resolutions
	* The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
	*/

	/**
	* Gets the weather forecast for 6 or 7 days (including today).
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 					1.0
 	* @compatibility  This method has compatibility issues with different bada API versions. @n
	* 								For more information, see issues in version @ref CompWeatherSensorRequestWeatherForecastPage "1.1", @ref CompWeatherSensorMemoryLeakPage "1.2", and @ref CompWeatherSensorFInfoNumberPage "2.0".
	*
	* @return		An error code
	* @param[in]	location 			The location for which the weather data is requested @n
	*									The value should be a string such as "Seoul, South Korea", "Austin, Texas".
	*									In USA, the location is composed of city and state. @n
	*									For other countries, in general, the location is composed of city and country.
	*									To check the validity of the location argument value, please refer to the following list of city names.
	*									<a href="http://weather.weatherbug.com/corporate/products/API/IntlCityCodes.zip
">http://weather.weatherbug.com/corporate/products/API/IntlCityCodes.zip</a>
	*									You can also check the validity by using WeatherBug's API and parsing the XML output.
	*									But in this case, you first need to sign-up and join the weatherbug.com before you use the API. For more details, please see the following page.
	*									<a href="http://weather.weatherbug.com/corporate/products/API/help.aspx
">http://weather.weatherbug.com/corporate/products/API/help.aspx</a>
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		The specified input parameter is invalid.
	* @exception	E_INVALID_STATE 	The method cannot provide the weather forecast.
	*/
	result RequestWeatherForecast(const Osp::Base::String location);

	/**
	* @page   CompWeatherSensorRequestWeatherForecastPage Compatibility for RequestWeatherForecast()
	* @section CompWeatherSensorRequestWeatherForecastPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
	*
	* -# This method does not work as expected if the location is greater than 40 characters. @n
	* -# The maximum length can vary up to 40 characters, and it also depends on the memory status. @n
	*
	* @section CompWeatherSensorRequestWeatherForecastPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
	*
	*/

	/**
	* Gets the weather forecast for 6 or 7 days (including today).
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 					1.0
	* @compatibility  This method has compatibility issues with different bada API versions. @n
	* 								For more information, see issues in version @ref CompWeatherSensorMemoryLeakPage "1.2" and @ref CompWeatherSensorWrongFWInfoPage "2.0".
	*
	* @return		An error code
	* @param[in]	longitude 			The value of longitude
	* @param[in]	latitude 			The value of latitude
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG		A specified input parameter is invalid.
	* @exception	E_INVALID_STATE 	The method cannot provide the weather forecast.
	*/
	result RequestWeatherForecast(float longitude, float latitude);

	/**
	* @page   CompWeatherSensorMemoryLeakPage Compatibility for WeatherSensorMemoryLeak
	* @section CompWeatherSensorMemoryLeakPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 1.2 has the following issues: @n
	*
	* -# Memory leak occurs when the weather data is requested and the result is not received successfully from the server. @n
	* -# A recursive request of weather data may result in memory shortage if receiving the weather data fails every time. @n
	*
	* -# After requesting weather forecast, GetDate() may return incorrect date information.
    *    If the total length of the date string, which also includes 2 white separators, is greater than 9 characters, the last character is trimmed. @n
	*
	* @section CompWeatherSensorMemoryLeakPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 1.2, and it is recommended to use bada API version 1.2 or above. @n
	*
	*/

	/**
	* @page   CompWeatherSensorWrongFWInfoPage Compatibility for RequestWeatherForecast()
	* @section CompWeatherSensorWrongFWInfoPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	*
	* -# After requesting weather forecast with the longitude and latitude, it may return the weather information of other location. @n
	* -# The weather forecast may consist of 6 or 7 days depending on time and location user requests. However, an error is raised when the weather forecast information for 6 days is received. @n
	*
	* @section CompWeatherSensorWrongFWInfoPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	*
	*/

	/**
	* @page   CompWeatherSensorFInfoNumberPage Compatibility for RequestWeatherForecast()
	* @section CompWeatherSensorFInfoNumberPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	*
	* -# When working with bada API versions prior to 2.0:
	* 	An application should remove the space between two arguments(city and state/country). For example, for a location value "Austin,   Texas" , an application should use the location value "Austin,Texas".
	* 	Note that a space inside city string such as "San Francisco,CA" works correctly. @n
	* -# The weather forecast may consist of 6 or 7 days depending on time and location user requests. However, an error is raised when the weather forecast information for 6 days is received. @n
	*
	* @section CompWeatherSensorFInfoNumberPageResolutionSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above. @n
	*
	*/

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this method.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since   1.0
	*/
	static void HandleCallback(bool enable);

private:
	result __SetWeatherAttributeLocation(const Osp::Base::String& location);
	result __AddWeatherListener(Osp::Uix::WeatherType weatherType);
	result __AddWeatherListener2();
	result __SetWeatherAttributeLocation2(WeatherType type, WeatherAttribute attr, Osp::Base::String& location);
	result __SetWeatherAttributeLonLat2(WeatherType type, WeatherAttribute attr, float longitude, float latitude);
private:
	IWeatherEventListener*				__pListener;
	Osp::Base::Collection::ArrayList*	__pListenerInfoNode;
	IMSensorManager*					__pIWeatherManager;
	BoolExp*							__pWeatherSensingParam;
	bool								__isCurrent;
	WeatherType							__type;
	WeatherAttribute					__attr;
	float								__longitude;
	float								__latitude;
	Osp::Base::String*					__location;
	Osp::Base::Runtime::Mutex* 			__pMutex;
private:
	friend class WeatherSensorEx;
	class WeatherSensorEx* __pWeatherSensorEx;
};

}; };	// Osp::Uix
#endif // _FUIX_WEATHER_SENSOR_H_
