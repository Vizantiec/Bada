/*
 * Summary: al module
 * Description: Interfaces, constants and types related to the al
 *
 */

#ifndef AL_AL_H
#define AL_AL_H

#if defined(__cplusplus)
extern "C" {
#endif


/**
 * @defgroup libopenal libopenal
 * @brief	The list of libopenal functions
 * @since	2.0 
 */
 
/**
 * @addtogroup libopenal
 * 
 * @{
 */

#if defined(_WIN32) && !defined(_XBOX)
 /* _OPENAL32LIB is deprecated */
 #if defined(AL_BUILD_LIBRARY) || defined (_OPENAL32LIB)
  #define AL_API __declspec(dllexport)
 #else
  #define AL_API __declspec(dllimport)
 #endif
#else
 #if defined(AL_BUILD_LIBRARY) && defined(HAVE_GCC_VISIBILITY)
  #define AL_API __attribute__((visibility("default")))
 #elif defined(AL_BUILD_LIBRARY)
	#define AL_API __declspec(dllexport)
 #else
	#define AL_API extern
 #endif
#endif

#if defined(_WIN32)
 #define AL_APIENTRY __cdecl
#else
 #define AL_APIENTRY
#endif

#if defined(TARGET_OS_MAC) && TARGET_OS_MAC
 #pragma export on
#endif

/*
 * The OPENAL, ALAPI, ALAPIENTRY, AL_INVALID, AL_ILLEGAL_ENUM, and
 * AL_ILLEGAL_COMMAND macros are deprecated, but are included for
 * applications porting code from AL 1.0
 */
#define OPENAL
#define ALAPI AL_API
#define ALAPIENTRY AL_APIENTRY
#define AL_INVALID                                (-1)
#define AL_ILLEGAL_ENUM                           AL_INVALID_ENUM
#define AL_ILLEGAL_COMMAND                        AL_INVALID_OPERATION

#define AL_VERSION_1_0
#define AL_VERSION_1_1


/** 8-bit boolean 
*
* @since	2.0
*/
typedef char ALboolean;

/** character 
*
* @since	2.0
*/
typedef char ALchar;

/** signed 8-bit 2's complement integer 
*
* @since	2.0
*/
typedef char ALbyte;

/** unsigned 8-bit integer 
*
* @since	2.0
*/
typedef unsigned char ALubyte;

/** signed 16-bit 2's complement integer 
*
* @since	2.0
*/
typedef short ALshort;

/** unsigned 16-bit integer 
*
* @since	2.0
*/
typedef unsigned short ALushort;

/** signed 32-bit 2's complement integer 
*
* @since	2.0
*/
typedef int ALint;

/** unsigned 32-bit integer 
*
* @since	2.0
*/
typedef unsigned int ALuint;

/** non-negative 32-bit binary integer size 
*
* @since	2.0
*/
typedef int ALsizei;

/** enumerated 32-bit value 
*
* @since	2.0
*/
typedef int ALenum;

/** 32-bit IEEE754 floating-point 
*
* @since	2.0
*/
typedef float ALfloat;

/** 64-bit IEEE754 floating-point 
*
* @since	2.0
*/
typedef double ALdouble;

/** void type (for opaque pointers only) 
*
* @since	2.0
*/
typedef void ALvoid;


/* Enumerant values begin at column 50. No tabs. */

/** "no distance model" or "no buffer" 
*
* @since	2.0
*/
#define AL_NONE                                   0

/** Boolean False. 
*
* @since	2.0
*/
#define AL_FALSE                                  0

/** Boolean True. 
*
* @since	2.0
*/
#define AL_TRUE                                   1

/** Indicate Source has relative coordinates. 
*
* @since	2.0
*/
#define AL_SOURCE_RELATIVE                        0x202



/**
 * Directional source, inner cone angle, in degrees.
 * Range:    [0-360] 
 * Default:  360
 *
 * @since	2.0
 */
#define AL_CONE_INNER_ANGLE                       0x1001

/**
 * Directional source, outer cone angle, in degrees.
 * Range:    [0-360] 
 * Default:  360
 *
 * @since	2.0
 */
#define AL_CONE_OUTER_ANGLE                       0x1002

/**
 * Specify the pitch to be applied at source.
 * Range:   [0.5-2.0]
 * Default: 1.0
 *
 * @since	2.0
 */
#define AL_PITCH                                  0x1003
  
/** 
 * Specify the current location in three dimensional space.
 * OpenAL, like OpenGL, uses a right handed coordinate system,
 *  where in a frontal default view X (thumb) points right, 
 *  Y points up (index finger), and Z points towards the
 *  viewer/camera (middle finger). 
 * To switch from a left handed coordinate system, flip the
 *  sign on the Z coordinate.
 * Listener position is always in the world coordinate system.
 *
 * @since	2.0
 */ 
#define AL_POSITION                               0x1004
  
/** Specify the current direction. 
*
* @since	2.0
*/
#define AL_DIRECTION                              0x1005
  
/** Specify the current velocity in three dimensional space. 
*
* @since	2.0
*/
#define AL_VELOCITY                               0x1006

/**
 * Indicate whether source is looping.
 * Type: ALboolean?
 * Range:   [AL_TRUE, AL_FALSE]
 * Default: FALSE.
 *
 * @since	2.0
 */
#define AL_LOOPING                                0x1007

/**
 * Indicate the buffer to provide sound samples. 
 * Type: ALuint.
 * Range: any valid Buffer id.
 *
 * @since	2.0
 */
#define AL_BUFFER                                 0x1009
  
/**
 * Indicate the gain (volume amplification) applied. 
 * Type:   ALfloat.
 * Range:  ]0.0-  ]
 * A value of 1.0 means un-attenuated/unchanged.
 * Each division by 2 equals an attenuation of -6dB.
 * Each multiplicaton with 2 equals an amplification of +6dB.
 * A value of 0.0 is meaningless with respect to a logarithmic
 *  scale; it is interpreted as zero volume - the channel
 *  is effectively disabled.
 *
 * @since	2.0
 */
#define AL_GAIN                                   0x100A

/**
 * Indicate minimum source attenuation
 * Type: ALfloat
 * Range:  [0.0 - 1.0]
 *
 * Logarthmic
 *
 * @since	2.0
 */
#define AL_MIN_GAIN                               0x100D

/**
 * Indicate maximum source attenuation
 * Type: ALfloat
 * Range:  [0.0 - 1.0]
 *
 * Logarthmic
 *
 * @since	2.0
 */
#define AL_MAX_GAIN                               0x100E

/**
 * Indicate listener orientation.
 *
 * at/up 
 *
 * @since	2.0
 */
#define AL_ORIENTATION                            0x100F

/**
 * Source state information.
 *
 * @since	2.0
 */
#define AL_SOURCE_STATE                           0x1010

/**
 * Source state information.
 *
 * @since	2.0
 */
#define AL_INITIAL                                0x1011

/**
 * Source state information.
 *
 * @since	2.0
 */
#define AL_PLAYING                                0x1012

/**
 * Source state information.
 *
 * @since	2.0
 */
#define AL_PAUSED                                 0x1013

/**
 * Source state information.
 *
 * @since	2.0
 */
#define AL_STOPPED                                0x1014

/**
 * Buffer Queue params
 *
 * @since	2.0
 */
#define AL_BUFFERS_QUEUED                         0x1015

/**
 * Buffer Queue params
 *
 * @since	2.0
 */
#define AL_BUFFERS_PROCESSED                      0x1016

/**
 * Source buffer position information
 *
 * @since	2.0
 */
#define AL_SEC_OFFSET                             0x1024

/**
 * Source buffer position information
 *
 * @since	2.0
 */
#define AL_SAMPLE_OFFSET                          0x1025

/**
 * Source buffer position information
 *
 * @since	2.0
 */
#define AL_BYTE_OFFSET                            0x1026

/**
 * Source type (Static, Streaming or undetermined)
 * Source is Static if a Buffer has been attached using AL_BUFFER
 * Source is Streaming if one or more Buffers have been attached using alSourceQueueBuffers
 * Source is undetermined when it has the NULL buffer attached
 *
 * @since	2.0
 */
#define AL_SOURCE_TYPE                            0x1027

/**
 * Source type (Static, Streaming or undetermined)
 * Source is Static if a Buffer has been attached using AL_BUFFER
 * Source is Streaming if one or more Buffers have been attached using alSourceQueueBuffers
 * Source is undetermined when it has the NULL buffer attached
 *
 * @since	2.0
 */
#define AL_STATIC                                 0x1028

/**
 * Source type (Static, Streaming or undetermined)
 * Source is Static if a Buffer has been attached using AL_BUFFER
 * Source is Streaming if one or more Buffers have been attached using alSourceQueueBuffers
 * Source is undetermined when it has the NULL buffer attached
 *
 * @since	2.0
 */
#define AL_STREAMING                              0x1029

/**
 * Source type (Static, Streaming or undetermined)
 * Source is Static if a Buffer has been attached using AL_BUFFER
 * Source is Streaming if one or more Buffers have been attached using alSourceQueueBuffers
 * Source is undetermined when it has the NULL buffer attached
 *
 * @since	2.0
 */
#define AL_UNDETERMINED                           0x1030

/** Sound samples: format specifier. 
*
* @since	2.0
*/
#define AL_FORMAT_MONO8                           0x1100

/** Sound samples: format specifier. 
*
* @since	2.0
*/
#define AL_FORMAT_MONO16                          0x1101

/** Sound samples: format specifier. 
*
* @since	2.0
*/
#define AL_FORMAT_STEREO8                         0x1102

/** Sound samples: format specifier. 
*
* @since	2.0
*/
#define AL_FORMAT_STEREO16                        0x1103

/**
 * source specific reference distance
 * Type: ALfloat
 * Range:  0.0 - +inf
 *
 * At 0.0, no distance attenuation occurs.  Default is
 * 1.0.
 *
 * @since	2.0
 */
#define AL_REFERENCE_DISTANCE                     0x1020

/**
 * source specific rolloff factor
 * Type: ALfloat
 * Range:  0.0 - +inf
 *
 * @since	2.0
 */
#define AL_ROLLOFF_FACTOR                         0x1021

/**
 * Directional source, outer cone gain.
 *
 * Default:  0.0
 * Range:    [0.0 - 1.0]
 * Logarithmic
 *
 * @since	2.0
 */
#define AL_CONE_OUTER_GAIN                        0x1022

/**
 * Indicate distance above which sources are not
 * attenuated using the inverse clamped distance model.
 *
 * Default: +inf
 * Type: ALfloat
 * Range:  0.0 - +inf
 *
 * @since	2.0
 */
#define AL_MAX_DISTANCE                           0x1023

/** 
 * Sound samples: frequency, in units of Hertz [Hz].
 * This is the number of samples per second. Half of the
 *  sample frequency marks the maximum significant
 *  frequency component.
 *
 * @since	2.0
 */
#define AL_FREQUENCY                              0x2001

/** 
 * Sound samples: frequency, in units of Hertz [Hz].
 * This is the number of samples per second. Half of the
 *  sample frequency marks the maximum significant
 *  frequency component.
 *
 * @since	2.0
 */
#define AL_BITS                                   0x2002

/** 
 * Sound samples: frequency, in units of Hertz [Hz].
 * This is the number of samples per second. Half of the
 *  sample frequency marks the maximum significant
 *  frequency component.
 *
 * @since	2.0
 */
#define AL_CHANNELS                               0x2003

/** 
 * Sound samples: frequency, in units of Hertz [Hz].
 * This is the number of samples per second. Half of the
 *  sample frequency marks the maximum significant
 *  frequency component.
 *
 * @since	2.0
 */
#define AL_SIZE                                   0x2004

/**
 * Buffer state.
 *
 * Not supported for public use (yet).
 *
 * @since	2.0
 */
#define AL_UNUSED                                 0x2010

/**
 * Buffer state.
 *
 * Not supported for public use (yet).
 *
 * @since	2.0
 */
#define AL_PENDING                                0x2011

/**
 * Buffer state.
 *
 * Not supported for public use (yet).
 *
 * @since	2.0
 */
#define AL_PROCESSED                              0x2012


/** Errors: No Error. 
*
* @since	2.0
*/
#define AL_NO_ERROR                               AL_FALSE

/** 
 * Invalid Name paramater passed to AL call.
 *
 * @since	2.0
 */
#define AL_INVALID_NAME                           0xA001

/** 
 * Invalid parameter passed to AL call.
 *
 * @since	2.0
 */
#define AL_INVALID_ENUM                           0xA002

/** 
 * Invalid enum parameter value.
 *
 * @since	2.0
 */
#define AL_INVALID_VALUE                          0xA003

/** 
 * Illegal call.
 *
 * @since	2.0
 */
#define AL_INVALID_OPERATION                      0xA004

  
/**
 * No mojo.
 *
 * @since	2.0
 */
#define AL_OUT_OF_MEMORY                          0xA005


/** Context strings: Vendor Name. 
*
* @since	2.0
*/
#define AL_VENDOR                                 0xB001

/** Context strings: Vendor Name. 
*
* @since	2.0
*/
#define AL_VERSION                                0xB002

/** Context strings: Vendor Name. 
*
* @since	2.0
*/
#define AL_RENDERER                               0xB003

/** Context strings: Vendor Name. 
*
* @since	2.0
*/
#define AL_EXTENSIONS                             0xB004


/**
 * Doppler scale.  Default 1.0
 *
 * @since	2.0
 */
#define AL_DOPPLER_FACTOR                         0xC000

/**
 * Tweaks speed of propagation.
 *
 * @since	2.0
 */
#define AL_DOPPLER_VELOCITY                       0xC001

/**
 * Speed of Sound in units per second
 *
 * @since	2.0
 */
#define AL_SPEED_OF_SOUND                         0xC003

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_DISTANCE_MODEL                         0xD000

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_INVERSE_DISTANCE                       0xD001

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_INVERSE_DISTANCE_CLAMPED               0xD002

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_LINEAR_DISTANCE                        0xD003

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_LINEAR_DISTANCE_CLAMPED                0xD004

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_EXPONENT_DISTANCE                      0xD005

/**
 * Distance models
 *
 * used in conjunction with DistanceModel
 *
 * implicit: NONE, which disances distance attenuation.
 *
 * @since	2.0
 */
#define AL_EXPONENT_DISTANCE_CLAMPED              0xD006

/*
 * Renderer State management
 */
 
 /**
 * For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
 *
 * @since	2.0
 */
AL_API void AL_APIENTRY alEnable( ALenum capability );

/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alDisable( ALenum capability ); 
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALboolean AL_APIENTRY alIsEnabled( ALenum capability ); 


/*
 * State retrieval
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API const ALchar* AL_APIENTRY alGetString( ALenum param );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBooleanv( ALenum param, ALboolean* data );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetIntegerv( ALenum param, ALint* data );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetFloatv( ALenum param, ALfloat* data );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetDoublev( ALenum param, ALdouble* data );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALboolean AL_APIENTRY alGetBoolean( ALenum param );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALint AL_APIENTRY alGetInteger( ALenum param );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALfloat AL_APIENTRY alGetFloat( ALenum param );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALdouble AL_APIENTRY alGetDouble( ALenum param );

/*
 * Error support.
 * Obtain the most recent error generated in the AL state machine.
 */

/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALenum AL_APIENTRY alGetError( void );


/* 
 * Extension support.
 * Query for the presence of an extension, and obtain any appropriate
 * function pointers and enum values.
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/ 
AL_API ALboolean AL_APIENTRY alIsExtensionPresent( const ALchar* extname );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void* AL_APIENTRY alGetProcAddress( const ALchar* fname );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALenum AL_APIENTRY alGetEnumValue( const ALchar* ename );


/*
 * LISTENER
 * Listener represents the location and orientation of the
 * 'user' in 3D-space.
 *
 * Properties include: -
 *
 * Gain         AL_GAIN         ALfloat
 * Position     AL_POSITION     ALfloat[3]
 * Velocity     AL_VELOCITY     ALfloat[3]
 * Orientation  AL_ORIENTATION  ALfloat[6] (Forward then Up vectors)
*/

/*
 * Set Listener parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/ 
AL_API void AL_APIENTRY alListenerf( ALenum param, ALfloat value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alListener3f( ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alListenerfv( ALenum param, const ALfloat* values ); 
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alListeneri( ALenum param, ALint value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alListener3i( ALenum param, ALint value1, ALint value2, ALint value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alListeneriv( ALenum param, const ALint* values );

/*
 * Get Listener parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetListenerf( ALenum param, ALfloat* value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetListener3f( ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetListenerfv( ALenum param, ALfloat* values );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetListeneri( ALenum param, ALint* value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetListener3i( ALenum param, ALint *value1, ALint *value2, ALint *value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetListeneriv( ALenum param, ALint* values );


/*
 * SOURCE
 * Sources represent individual sound objects in 3D-space.
 * Sources take the PCM data provided in the specified Buffer,
 * apply Source-specific modifications, and then
 * submit them to be mixed according to spatial arrangement etc.
 * 
 * Properties include: -
 *
 * Gain                              AL_GAIN                 ALfloat
 * Min Gain                          AL_MIN_GAIN             ALfloat
 * Max Gain                          AL_MAX_GAIN             ALfloat
 * Position                          AL_POSITION             ALfloat[3]
 * Velocity                          AL_VELOCITY             ALfloat[3]
 * Direction                         AL_DIRECTION            ALfloat[3]
 * Head Relative Mode                AL_SOURCE_RELATIVE      ALint (AL_TRUE or AL_FALSE)
 * Reference Distance                AL_REFERENCE_DISTANCE   ALfloat
 * Max Distance                      AL_MAX_DISTANCE         ALfloat
 * RollOff Factor                    AL_ROLLOFF_FACTOR       ALfloat
 * Inner Angle                       AL_CONE_INNER_ANGLE     ALint or ALfloat
 * Outer Angle                       AL_CONE_OUTER_ANGLE     ALint or ALfloat
 * Cone Outer Gain                   AL_CONE_OUTER_GAIN      ALint or ALfloat
 * Pitch                             AL_PITCH                ALfloat
 * Looping                           AL_LOOPING              ALint (AL_TRUE or AL_FALSE)
 * MS Offset                         AL_MSEC_OFFSET          ALint or ALfloat
 * Byte Offset                       AL_BYTE_OFFSET          ALint or ALfloat
 * Sample Offset                     AL_SAMPLE_OFFSET        ALint or ALfloat
 * Attached Buffer                   AL_BUFFER               ALint
 * State (Query only)                AL_SOURCE_STATE         ALint
 * Buffers Queued (Query only)       AL_BUFFERS_QUEUED       ALint
 * Buffers Processed (Query only)    AL_BUFFERS_PROCESSED    ALint
 */

/* Create Source objects */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGenSources( ALsizei n, ALuint* sources ); 

/* Delete Source objects */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alDeleteSources( ALsizei n, const ALuint* sources );

/* Verify a handle is a valid Source */ 
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALboolean AL_APIENTRY alIsSource( ALuint sid ); 

/*
 * Set Source parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcef( ALuint sid, ALenum param, ALfloat value ); 
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSource3f( ALuint sid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcefv( ALuint sid, ALenum param, const ALfloat* values ); 
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcei( ALuint sid, ALenum param, ALint value ); 
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSource3i( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourceiv( ALuint sid, ALenum param, const ALint* values );

/*
 * Get Source parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetSourcef( ALuint sid, ALenum param, ALfloat* value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetSource3f( ALuint sid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetSourcefv( ALuint sid, ALenum param, ALfloat* values );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetSourcei( ALuint sid,  ALenum param, ALint* value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetSource3i( ALuint sid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetSourceiv( ALuint sid,  ALenum param, ALint* values );


/*
 * Source vector based playback calls
 */

/* Play, replay, or resume (if paused) a list of Sources */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcePlayv( ALsizei ns, const ALuint *sids );

/* Stop a list of Sources */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourceStopv( ALsizei ns, const ALuint *sids );

/* Rewind a list of Sources */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourceRewindv( ALsizei ns, const ALuint *sids );

/* Pause a list of Sources */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcePausev( ALsizei ns, const ALuint *sids );

/*
 * Source based playback calls
 */

/* Play, replay, or resume a Source */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcePlay( ALuint sid );

/* Stop a Source */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourceStop( ALuint sid );

/* Rewind a Source (set playback postiton to beginning) */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourceRewind( ALuint sid );

/* Pause a Source */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourcePause( ALuint sid );

/*
 * Source Queuing 
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/ 
AL_API void AL_APIENTRY alSourceQueueBuffers( ALuint sid, ALsizei numEntries, const ALuint *bids );

/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSourceUnqueueBuffers( ALuint sid, ALsizei numEntries, ALuint *bids );


/*
 * BUFFER
 * Buffer objects are storage space for sample data.
 * Buffers are referred to by Sources. One Buffer can be used
 * by multiple Sources.
 *
 * Properties include: -
 *
 * Frequency (Query only)    AL_FREQUENCY      ALint
 * Size (Query only)         AL_SIZE           ALint
 * Bits (Query only)         AL_BITS           ALint
 * Channels (Query only)     AL_CHANNELS       ALint
 */

/* Create Buffer objects */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGenBuffers( ALsizei n, ALuint* buffers );

/* Delete Buffer objects */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alDeleteBuffers( ALsizei n, const ALuint* buffers );

/* Verify a handle is a valid Buffer */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API ALboolean AL_APIENTRY alIsBuffer( ALuint bid );

/* Specify the data to be copied into a buffer */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBufferData( ALuint bid, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq );

/*
 * Set Buffer parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBufferf( ALuint bid, ALenum param, ALfloat value );

/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBuffer3f( ALuint bid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBufferfv( ALuint bid, ALenum param, const ALfloat* values );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBufferi( ALuint bid, ALenum param, ALint value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBuffer3i( ALuint bid, ALenum param, ALint value1, ALint value2, ALint value3 );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alBufferiv( ALuint bid, ALenum param, const ALint* values );

/*
 * Get Buffer parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBufferf( ALuint bid, ALenum param, ALfloat* value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBuffer3f( ALuint bid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBufferfv( ALuint bid, ALenum param, ALfloat* values );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBufferi( ALuint bid, ALenum param, ALint* value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBuffer3i( ALuint bid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alGetBufferiv( ALuint bid, ALenum param, ALint* values );


/*
 * Global Parameters
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alDopplerFactor( ALfloat value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alDopplerVelocity( ALfloat value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alSpeedOfSound( ALfloat value );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
AL_API void AL_APIENTRY alDistanceModel( ALenum distanceModel );

/*
 * Pointer-to-function types, useful for dynamically getting AL entry points.
 */
typedef void           (AL_APIENTRY *LPALENABLE)( ALenum capability );
typedef void           (AL_APIENTRY *LPALDISABLE)( ALenum capability ); 
typedef ALboolean      (AL_APIENTRY *LPALISENABLED)( ALenum capability ); 
typedef const ALchar*  (AL_APIENTRY *LPALGETSTRING)( ALenum param );
typedef void           (AL_APIENTRY *LPALGETBOOLEANV)( ALenum param, ALboolean* data );
typedef void           (AL_APIENTRY *LPALGETINTEGERV)( ALenum param, ALint* data );
typedef void           (AL_APIENTRY *LPALGETFLOATV)( ALenum param, ALfloat* data );
typedef void           (AL_APIENTRY *LPALGETDOUBLEV)( ALenum param, ALdouble* data );
typedef ALboolean      (AL_APIENTRY *LPALGETBOOLEAN)( ALenum param );
typedef ALint          (AL_APIENTRY *LPALGETINTEGER)( ALenum param );
typedef ALfloat        (AL_APIENTRY *LPALGETFLOAT)( ALenum param );
typedef ALdouble       (AL_APIENTRY *LPALGETDOUBLE)( ALenum param );
typedef ALenum         (AL_APIENTRY *LPALGETERROR)( void );
typedef ALboolean      (AL_APIENTRY *LPALISEXTENSIONPRESENT)(const ALchar* extname );
typedef void*          (AL_APIENTRY *LPALGETPROCADDRESS)( const ALchar* fname );
typedef ALenum         (AL_APIENTRY *LPALGETENUMVALUE)( const ALchar* ename );
typedef void           (AL_APIENTRY *LPALLISTENERF)( ALenum param, ALfloat value );
typedef void           (AL_APIENTRY *LPALLISTENER3F)( ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
typedef void           (AL_APIENTRY *LPALLISTENERFV)( ALenum param, const ALfloat* values );
typedef void           (AL_APIENTRY *LPALLISTENERI)( ALenum param, ALint value );
typedef void           (AL_APIENTRY *LPALLISTENER3I)( ALenum param, ALint value1, ALint value2, ALint value3 );
typedef void           (AL_APIENTRY *LPALLISTENERIV)( ALenum param, const ALint* values );
typedef void           (AL_APIENTRY *LPALGETLISTENERF)( ALenum param, ALfloat* value );
typedef void           (AL_APIENTRY *LPALGETLISTENER3F)( ALenum param, ALfloat *value1, ALfloat *value2, ALfloat *value3 );
typedef void           (AL_APIENTRY *LPALGETLISTENERFV)( ALenum param, ALfloat* values );
typedef void           (AL_APIENTRY *LPALGETLISTENERI)( ALenum param, ALint* value );
typedef void           (AL_APIENTRY *LPALGETLISTENER3I)( ALenum param, ALint *value1, ALint *value2, ALint *value3 );
typedef void           (AL_APIENTRY *LPALGETLISTENERIV)( ALenum param, ALint* values );
typedef void           (AL_APIENTRY *LPALGENSOURCES)( ALsizei n, ALuint* sources ); 
typedef void           (AL_APIENTRY *LPALDELETESOURCES)( ALsizei n, const ALuint* sources );
typedef ALboolean      (AL_APIENTRY *LPALISSOURCE)( ALuint sid ); 
typedef void           (AL_APIENTRY *LPALSOURCEF)( ALuint sid, ALenum param, ALfloat value); 
typedef void           (AL_APIENTRY *LPALSOURCE3F)( ALuint sid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
typedef void           (AL_APIENTRY *LPALSOURCEFV)( ALuint sid, ALenum param, const ALfloat* values );
typedef void           (AL_APIENTRY *LPALSOURCEI)( ALuint sid, ALenum param, ALint value); 
typedef void           (AL_APIENTRY *LPALSOURCE3I)( ALuint sid, ALenum param, ALint value1, ALint value2, ALint value3 );
typedef void           (AL_APIENTRY *LPALSOURCEIV)( ALuint sid, ALenum param, const ALint* values );
typedef void           (AL_APIENTRY *LPALGETSOURCEF)( ALuint sid, ALenum param, ALfloat* value );
typedef void           (AL_APIENTRY *LPALGETSOURCE3F)( ALuint sid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
typedef void           (AL_APIENTRY *LPALGETSOURCEFV)( ALuint sid, ALenum param, ALfloat* values );
typedef void           (AL_APIENTRY *LPALGETSOURCEI)( ALuint sid, ALenum param, ALint* value );
typedef void           (AL_APIENTRY *LPALGETSOURCE3I)( ALuint sid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
typedef void           (AL_APIENTRY *LPALGETSOURCEIV)( ALuint sid, ALenum param, ALint* values );
typedef void           (AL_APIENTRY *LPALSOURCEPLAYV)( ALsizei ns, const ALuint *sids );
typedef void           (AL_APIENTRY *LPALSOURCESTOPV)( ALsizei ns, const ALuint *sids );
typedef void           (AL_APIENTRY *LPALSOURCEREWINDV)( ALsizei ns, const ALuint *sids );
typedef void           (AL_APIENTRY *LPALSOURCEPAUSEV)( ALsizei ns, const ALuint *sids );
typedef void           (AL_APIENTRY *LPALSOURCEPLAY)( ALuint sid );
typedef void           (AL_APIENTRY *LPALSOURCESTOP)( ALuint sid );
typedef void           (AL_APIENTRY *LPALSOURCEREWIND)( ALuint sid );
typedef void           (AL_APIENTRY *LPALSOURCEPAUSE)( ALuint sid );
typedef void           (AL_APIENTRY *LPALSOURCEQUEUEBUFFERS)(ALuint sid, ALsizei numEntries, const ALuint *bids );
typedef void           (AL_APIENTRY *LPALSOURCEUNQUEUEBUFFERS)(ALuint sid, ALsizei numEntries, ALuint *bids );
typedef void           (AL_APIENTRY *LPALGENBUFFERS)( ALsizei n, ALuint* buffers );
typedef void           (AL_APIENTRY *LPALDELETEBUFFERS)( ALsizei n, const ALuint* buffers );
typedef ALboolean      (AL_APIENTRY *LPALISBUFFER)( ALuint bid );
typedef void           (AL_APIENTRY *LPALBUFFERDATA)( ALuint bid, ALenum format, const ALvoid* data, ALsizei size, ALsizei freq );
typedef void           (AL_APIENTRY *LPALBUFFERF)( ALuint bid, ALenum param, ALfloat value);
typedef void           (AL_APIENTRY *LPALBUFFER3F)( ALuint bid, ALenum param, ALfloat value1, ALfloat value2, ALfloat value3 );
typedef void           (AL_APIENTRY *LPALBUFFERFV)( ALuint bid, ALenum param, const ALfloat* values );
typedef void           (AL_APIENTRY *LPALBUFFERI)( ALuint bid, ALenum param, ALint value);
typedef void           (AL_APIENTRY *LPALBUFFER3I)( ALuint bid, ALenum param, ALint value1, ALint value2, ALint value3 );
typedef void           (AL_APIENTRY *LPALBUFFERIV)( ALuint bid, ALenum param, const ALint* values );
typedef void           (AL_APIENTRY *LPALGETBUFFERF)( ALuint bid, ALenum param, ALfloat* value );
typedef void           (AL_APIENTRY *LPALGETBUFFER3F)( ALuint bid, ALenum param, ALfloat* value1, ALfloat* value2, ALfloat* value3);
typedef void           (AL_APIENTRY *LPALGETBUFFERFV)( ALuint bid, ALenum param, ALfloat* values );
typedef void           (AL_APIENTRY *LPALGETBUFFERI)( ALuint bid, ALenum param, ALint* value );
typedef void           (AL_APIENTRY *LPALGETBUFFER3I)( ALuint bid, ALenum param, ALint* value1, ALint* value2, ALint* value3);
typedef void           (AL_APIENTRY *LPALGETBUFFERIV)( ALuint bid, ALenum param, ALint* values );
typedef void           (AL_APIENTRY *LPALDOPPLERFACTOR)( ALfloat value );
typedef void           (AL_APIENTRY *LPALDOPPLERVELOCITY)( ALfloat value );
typedef void           (AL_APIENTRY *LPALSPEEDOFSOUND)( ALfloat value );
typedef void           (AL_APIENTRY *LPALDISTANCEMODEL)( ALenum distanceModel );

#if defined(TARGET_OS_MAC) && TARGET_OS_MAC
 #pragma export off
#endif

/**
 * @}
 */


#if defined(__cplusplus)
}  /* extern "C" */
#endif

#endif /* AL_AL_H */
