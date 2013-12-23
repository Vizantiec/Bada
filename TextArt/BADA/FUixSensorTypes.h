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
/*
* @file		FUixSensorTypes.h
* @brief	This is the header file for the common data types used by the sensor data and the sensor manager.
*
* This header file contains the declarations of the common data types and constants used by the sensor data and the sensor manager.
*/

#ifndef _FUIX_SENSOR_TYPES_H_
#define _FUIX_SENSOR_TYPES_H_

// Includes

#define MAX_TILT_AZIMUTH (360)
#define MIN_TILT_AZIMUTH (0)
#define MAX_TILT_PITCH (180)
#define MIN_TILT_PITCH (-180)
#define MAX_TILT_ROLL (90)
#define MIN_TILT_ROLL (-90)
#define MAX_GPS_LATITUDE (90)
#define MIN_GPS_LATITUDE (-90)
#define MAX_GPS_LONGITUDE (180)
#define MIN_GPS_LONGITUDE (-180)


namespace Osp { namespace Uix {

/**
* @enum	 SensorType
* Defines the sensor type.
*
* @since 1.0
*/
typedef enum {
	SENSOR_TYPE_ACCELERATION = 0,	/**< The acceleration sensor type */
	/**
	* @internal
	* This enum is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
	* that might arise after using this enum.
	*
	* GPS sensor type
	* @remarks  SENSOR_TYPE_GPS field is deprecated in favor of applications using an explicit and separate API for obtaining the updated location information. Instead, use Osp::Locations::LocationProvider::RequestLocationUpdates(), which provides more functionality to the application.
	*/
	SENSOR_TYPE_GPS,
	SENSOR_TYPE_MAGNETIC,	/**< The magnetic sensor type */
	SENSOR_TYPE_PROXIMITY,	/**< The proximity sensor type */
	SENSOR_TYPE_TILT	/**< The tilt sensor type */
} SensorType;

/**
* @enum	SensorDataKey
* Defines the default key types for the SensorData.
*
* @since 		1.0
* @remarks		Use actual key type, such as Osp::Uix::AccelerationDataKey, Osp::Uix::MagneticDataKey, Osp::Uix::ProximityDataKey, or Osp::Uix::TiltDataKey with type casting. For example, use Osp::Uix::SensorData::GetValue((SensorDataKey)ACCELERATION_DATA_KEY_X, value) to get the acceleration value in x axis.
*/
typedef enum{

	SENSOR_DATA_KEY_0 = 0,
	SENSOR_DATA_KEY_1,
	SENSOR_DATA_KEY_2,
	SENSOR_DATA_KEY_3,
	SENSOR_DATA_KEY_4
}SensorDataKey;

/**
* @enum AccelerationDataKey
* Defines the keys to access the acceleration sensor data.
*
* @since 		1.0
*/
typedef enum {
	ACCELERATION_DATA_KEY_TIMESTAMP = 0,	/**< The key to the timestamp of the acceleration sensor data */
	ACCELERATION_DATA_KEY_X,	/**< The key to the x-axis of the acceleration sensor data */
	ACCELERATION_DATA_KEY_Y,	/**< The key to the y-axis of the acceleration sensor data */
	ACCELERATION_DATA_KEY_Z,	/**< The key to the z-axis of the acceleration sensor data */
	ACCELERATION_DATA_KEY_COUNT	/**< The number of indices for the acceleration sensor data */
} AccelerationDataKey;

/**
* @internal 
* This enum is for internal use only.
* The bada platform team is not responsible for any behavioral correctness, consistency, and security-related issues
* that might arise after using this enum.
*
* @enum GpsDataKey
* Defines keys to access GPS sensor data.
*
* @since 		1.0
* @remarks  GpsDataKey enumeration is deprecated in favor of applications 
*		  		  using an explicit and separate API, for obtaining the updated location
*		   			information. Use Osp::Locations::LocationProvider::RequestLocationUpdates() instead,
*           which provides more functionality to the application.
*/
typedef enum {
	/* The key to the timestamp of the GPS sensor data */
	GPS_DATA_KEY_TIMESTAMP = 0,
	/* The key to the latitude of the GPS sensor data */
	GPS_DATA_KEY_LATITUDE,
	/* The key to the longitude of the GPS sensor data */
	GPS_DATA_KEY_LONGITUDE,
	/* The key to the altitude of the GPS sensor data */
	GPS_DATA_KEY_ALTITUDE,
	/* The number of indices to access the GPS sensor data */
	GPS_DATA_KEY_COUNT
} GpsDataKey;

/**
* @enum MagneticDataKey
* Defines the keys to access the magnetic sensor data.
*
* @since 		1.0
*/
typedef enum {
	MAGNETIC_DATA_KEY_TIMESTAMP = 0,	/**< The key to the timestamp of the magnetic sensor data */
	MAGNETIC_DATA_KEY_X,	/**< The key to the x-axis of the magnetic sensor data */
	MAGNETIC_DATA_KEY_Y,	/**< The key to the y-axis of the magnetic sensor data  */
	MAGNETIC_DATA_KEY_Z,	/**< The key to the z-axis of the magnetic sensor data  */
	MAGNETIC_DATA_KEY_COUNT	/**< The number of indices to access magnetic sensor data */
} MagneticDataKey;

/**
* @enum ProximityDataKey
* Defines the keys to access the proximity sensor data.
*
* @since 		1.0
*/
typedef enum {
	PROXIMITY_DATA_KEY_TIMESTAMP = 0,	/** The key to the timestamp of the proximity sensor data */
	PROXIMITY_DATA_KEY_ONOFF,	/** The key to on/off the proximity sensor data */
	PROXIMITY_DATA_KEY_COUNT	/** The number of indices to access the proximity sensor data */
} ProximityDataKey;

/**
* @enum TiltDataKey
* Defines the keys to access the tilt sensor data.
*
* @since 		1.0
*/
typedef enum {
	TILT_DATA_KEY_TIMESTAMP = 0,	/** The key to the timestamp of the tilt sensor data */
	TILT_DATA_KEY_AZIMUTH,	/** The key to the azimuth of the tilt sensor data  */
	TILT_DATA_KEY_PITCH,	/** The key to the pitch of the tilt sensor data */
	TILT_DATA_KEY_ROLL,	/** The key to the roll of the tilt sensor data */
	TILT_DATA_KEY_COUNT	/** The number of indices to access the tilt sensor data */
} TiltDataKey;

}; }; // Osp::Uix

#endif // _FUIX_SENSOR_TYPES_H_
