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
* @file		FUixIWeatherEventListener.h
* @brief	This is the header file for the %IWeatherEventListener interface.
*
* This header file contains the declarations of the %IWeatherEventListener interface.
*
*/

#ifndef _FUIX_IWEATHER_EVENTLISTENER_H_
#define _FUIX_IWEATHER_EVENTLISTENER_H_

// Includes
#include "FUixConfig.h"
#include "FBase.h"

namespace Osp { namespace Uix {

/**
* @interface IWeatherEventListener
* @brief This interface implements an event listener used to receive weather data asynchronously.
* @deprecated This interface is deprecated because it is not supported by the platform.
* @since 1.0
*
* The %IWeatherEventListener interface provides methods that are invoked when the weather data is received from the server.
*
* The following example demonstrates how to use the %IWeatherEventListener class.
*
* @code
*
*  //Sample Code for WeatherSample.h
*  #include <FUix.h>
*  #include <FUi.h>
*
*  using namespace Osp::Uix;
*
*  class WeatherSample :
*	public Osp::Ui::Controls::Form,
*	public Osp::Uix::IWeatherEventListener
*  {
*  	public:
*		void OnCurrentWeatherReceived(CurrentWeather& currentWeather, result r);
*		void OnWeatherForecastReceived(Osp::Base::Collection::IList* pWeatherForecastList, result r);
*  }
*
*  //Sample Code for WeatherSample.cpp
*  #include "WeatherSample.h"
*
*  using namespace Osp::Uix;
*
*  void
*  WeatherSample::OnCurrentWeatherReceived(CurrentWeather& currentWeather, result r)
*  {
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
*  }
*
*   void
*   WeatherSample::OnWeatherForecastReceived(Osp::Base::Collection::IList* pWeatherForecastList, result r)
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
* @endcode


*/

class CurrentWeather;

class _EXPORT_UIX_ IWeatherEventListener
{
// Lifecycle
//public:
//	virtual ~IWeatherEventListener(void);

// Operation
public:

	/**
	* Called when the current weather data is received.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 		1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	* 					For more information, see @ref CompDiffLocPage "here".
	*
	* @param[in]	currentWeather	A reference to the CurrentWeather instance to store the current weather data
	* @param[out]	r				The error code
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_DATA	The data is invalid. @n
	*                               For example, the return value from the server is invalid, the network connection has failed,
	*                               or the specified longitude or latitude value is not registered as a service location in the weather server.
	*
	*/
	virtual void OnCurrentWeatherReceived(CurrentWeather& currentWeather, result r) = 0;

	/**
    * @page   CompDiffLocPage Compatibility for OnCurrentWeatherReceived()
    * @section CompDiffLocPageIssueSection Issues
    *                   Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
    *
    * -# After requesting the weather information, it may return an incorrect location value even though the weather data is correct.
    *
    * @section CompDiffLocPageResolutionSection Resolutions
    * The issue mentioned above is resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
    *
    */

	/**
	* Called when the weather forecast for 6 or 7 days (including today) is received.
	*
	* @deprecated This method is deprecated because it is not supported by the platform.
	* @since 		1.0
	* @compatibility  This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	* 					For more information, see @ref CompWeatherSensorWrongExceptionPage "here".
	*
	* @param[in]	pWeatherForecastList	A pointer to a list of the WeatherForecast instances to store the weather forecast for 6 or 7 future days (including today)
	* @param[out]	r						The error code
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_DATA			The data is invalid. @n
	*                               For example, the server is invalid, the network connection has failed,
	*                               or the specified longitude or latitude value is not registered as a service location in the weather server.
	* @remarks		The number of weather forecast days can be accessed using the Osp::Base::Collection::GetCount() method.
	*
	*/
	virtual void OnWeatherForecastReceived(Osp::Base::Collection::IList* pWeatherForecastList, result r) = 0;

	/**
	* @page   CompWeatherSensorWrongExceptionPage Compatibility for OnWeatherForecastReceived()
	* @section CompWeatherSensorWrongExceptionPageIssueSection Issues
	*                   Implementation of this method in bada API versions prior to 2.0 has the following issues: @n
	*
	* -# If the network connection fails or the weather forecast is requested with an invalid location value, 
	* 									the input argument of the event handler, result r, will have E_SUCCESS, and not E_INVALID_DATA. @n
	* -# After requesting the weather information, it may return an incorrect location value even though the weather data is correct. @n
	* -# The weather forecast may consist of 6 or 7 days depending on the time and location the user requests. However, an error is raised when the weather forecast information for 6 days is received.
	*
	* @section CompWeatherSensorWrongExceptionPageResolutionsSection Resolutions
	* The issues mentioned above are resolved in bada API version 2.0, and it is recommended to use bada API version 2.0 or above.
	*
	*/

private:
	friend class IWeatherEventListenerEx;
	class IWeatherEventListenerEx* __pIWeatherEventListenerEx;

};	// class IWeatherEventListener

}; };	// Osp::Uix

#endif // _FUIX_IWEATHER_EVENTLISTENER_H_
