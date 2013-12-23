#ifndef AL_ALC_H
#define AL_ALC_H

#if defined(__cplusplus)
extern "C" {
#endif

/**
 * @addtogroup libopenal
 * 
 * @{
 */
 
#if defined(_WIN32) && !defined(_XBOX)
 /* _OPENAL32LIB is deprecated */
 #if defined(AL_BUILD_LIBRARY) || defined (_OPENAL32LIB)
  #define ALC_API __declspec(dllexport)
 #else
  #define ALC_API __declspec(dllimport)
 #endif
#else
 #if defined(AL_BUILD_LIBRARY) && defined(HAVE_GCC_VISIBILITY)
  #define ALC_API __attribute__((visibility("default")))
 #elif defined(AL_BUILD_LIBRARY)
	#define ALC_API __declspec(dllexport)
 #else
	#define ALC_API extern
 #endif
#endif

#if defined(_WIN32)
 #define ALC_APIENTRY __cdecl
#else
 #define ALC_APIENTRY
#endif

#if defined(TARGET_OS_MAC) && TARGET_OS_MAC
 #pragma export on
#endif

/**
 * The ALCAPI, ALCAPIENTRY, and ALC_INVALID macros are deprecated, but are
 * included for applications porting code from AL 1.0
 *
 * @since	2.0
 */
#define ALCAPI ALC_API

/**
 * The ALCAPI, ALCAPIENTRY, and ALC_INVALID macros are deprecated, but are
 * included for applications porting code from AL 1.0
 *
 * @since	2.0
 */
#define ALCAPIENTRY ALC_APIENTRY

/**
 * The ALCAPI, ALCAPIENTRY, and ALC_INVALID macros are deprecated, but are
 * included for applications porting code from AL 1.0
 *
 * @since	2.0
 */
#define ALC_INVALID 0


#define ALC_VERSION_0_1         1

typedef struct ALCdevice_struct ALCdevice;
typedef struct ALCcontext_struct ALCcontext;


/** 8-bit boolean
 *
 * @since	2.0
 */
typedef char ALCboolean;

/** character 
 *
 * @since	2.0
 */
typedef char ALCchar;

/** signed 8-bit 2's complement integer 
 *
 * @since	2.0
 */
typedef char ALCbyte;

/** unsigned 8-bit integer 
 *
 * @since	2.0
 */
typedef unsigned char ALCubyte;

/** signed 16-bit 2's complement integer 
 *
 * @since	2.0
 */
typedef short ALCshort;

/** unsigned 16-bit integer 
 *
 * @since	2.0
 */
typedef unsigned short ALCushort;

/** signed 32-bit 2's complement integer 
 *
 * @since	2.0
 */
typedef int ALCint;

/** unsigned 32-bit integer 
 *
 * @since	2.0
 */
typedef unsigned int ALCuint;

/** non-negative 32-bit binary integer size 
 *
 * @since	2.0
 */
typedef int ALCsizei;

/** enumerated 32-bit value 
 *
 * @since	2.0
 */
typedef int ALCenum;

/** 32-bit IEEE754 floating-point 
 *
 * @since	2.0
 */
typedef float ALCfloat;

/** 64-bit IEEE754 floating-point 
 *
 * @since	2.0
 */
typedef double ALCdouble;

/** void type (for opaque pointers only) 
 *
 * @since	2.0
 */
typedef void ALCvoid;


/* Enumerant values begin at column 50. No tabs. */

/** Boolean False. 
 *
 * @since	2.0
 */
#define ALC_FALSE                                0

/** Boolean True. 
 *
 * @since	2.0
 */
#define ALC_TRUE                                 1

/**
 * followed by <int> Hz
 *
 * @since	2.0
 */
#define ALC_FREQUENCY                            0x1007

/**
 * followed by <int> Hz
 *
 * @since	2.0
 */
#define ALC_REFRESH                              0x1008

/**
 * followed by AL_TRUE, AL_FALSE
 *
 * @since	2.0
 */
#define ALC_SYNC                                 0x1009

/**
 * followed by <int> Num of requested Mono (3D) Sources
 *
 * @since	2.0
 */
#define ALC_MONO_SOURCES                         0x1010

/**
 * followed by <int> Num of requested Stereo Sources
 *
 * @since	2.0
 */
#define ALC_STEREO_SOURCES                       0x1011

/**
 * No error
 *
 * @since	2.0
 */
#define ALC_NO_ERROR                             ALC_FALSE

/**
 * No device
 *
 * @since	2.0
 */
#define ALC_INVALID_DEVICE                       0xA001

/**
 * invalid context ID
 *
 * @since	2.0
 */
#define ALC_INVALID_CONTEXT                      0xA002

/**
 * bad enum
 *
 * @since	2.0
 */
#define ALC_INVALID_ENUM                         0xA003

/**
 * bad value
 *
 * @since	2.0
 */
#define ALC_INVALID_VALUE                        0xA004

/**
 * Out of memory.
 *
 * @since	2.0
 */
#define ALC_OUT_OF_MEMORY                        0xA005


/**
 * The Specifier string for default device
 *
 * @since	2.0
 */
#define ALC_DEFAULT_DEVICE_SPECIFIER             0x1004

/**
 * The Specifier string for default device
 *
 * @since	2.0
 */
#define ALC_DEVICE_SPECIFIER                     0x1005

/**
 * The Specifier string for default device
 *
 * @since	2.0
 */
#define ALC_EXTENSIONS                           0x1006

/**
 * ALC major version
 *
 * @since	2.0
 */
#define ALC_MAJOR_VERSION                        0x1000

/**
 * ALC minor version
 *
 * @since	2.0
 */
#define ALC_MINOR_VERSION                        0x1001

/**
 * Arrtibutes size
 *
 * @since	2.0
 */
#define ALC_ATTRIBUTES_SIZE                      0x1002

/**
 * All attributes
 *
 * @since	2.0
 */
#define ALC_ALL_ATTRIBUTES                       0x1003


/**
 * Capture extension
 *
 * @since	2.0
 */
#define ALC_CAPTURE_DEVICE_SPECIFIER             0x310

/**
 * Capture extension
 *
 * @since	2.0
 */
#define ALC_CAPTURE_DEFAULT_DEVICE_SPECIFIER     0x311

/**
 * Capture extension
 *
 * @since	2.0
 */
#define ALC_CAPTURE_SAMPLES                      0x312


/*
 * Context Management
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCcontext *    ALC_APIENTRY alcCreateContext( ALCdevice *device, const ALCint* attrlist );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCboolean      ALC_APIENTRY alcMakeContextCurrent( ALCcontext *context );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcProcessContext( ALCcontext *context );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcSuspendContext( ALCcontext *context );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcDestroyContext( ALCcontext *context );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCcontext *    ALC_APIENTRY alcGetCurrentContext( void );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCdevice*      ALC_APIENTRY alcGetContextsDevice( ALCcontext *context );


/*
 * Device Management
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCdevice *     ALC_APIENTRY alcOpenDevice( const ALCchar *devicename );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCboolean      ALC_APIENTRY alcCloseDevice( ALCdevice *device );


/*
 * Error support.
 * Obtain the most recent Context error
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCenum         ALC_APIENTRY alcGetError( ALCdevice *device );


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
ALC_API ALCboolean      ALC_APIENTRY alcIsExtensionPresent( ALCdevice *device, const ALCchar *extname );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void  *         ALC_APIENTRY alcGetProcAddress( ALCdevice *device, const ALCchar *funcname );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCenum         ALC_APIENTRY alcGetEnumValue( ALCdevice *device, const ALCchar *enumname );


/*
 * Query functions
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API const ALCchar * ALC_APIENTRY alcGetString( ALCdevice *device, ALCenum param );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcGetIntegerv( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *data );


/*
 * Capture functions
 */
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCdevice*      ALC_APIENTRY alcCaptureOpenDevice( const ALCchar *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API ALCboolean      ALC_APIENTRY alcCaptureCloseDevice( ALCdevice *device );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcCaptureStart( ALCdevice *device );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcCaptureStop( ALCdevice *device );
/**
* For more information about using Libopenal, go to <a href="http://connect.creativelabs.com/openal/default.aspx" target=_blank> http://connect.creativelabs.com/openal/default.aspx </a>
*
* @since	2.0
*/
ALC_API void            ALC_APIENTRY alcCaptureSamples( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );

/*
 * Pointer-to-function types, useful for dynamically getting ALC entry points.
 */
typedef ALCcontext *   (ALC_APIENTRY *LPALCCREATECONTEXT) (ALCdevice *device, const ALCint *attrlist);
typedef ALCboolean     (ALC_APIENTRY *LPALCMAKECONTEXTCURRENT)( ALCcontext *context );
typedef void           (ALC_APIENTRY *LPALCPROCESSCONTEXT)( ALCcontext *context );
typedef void           (ALC_APIENTRY *LPALCSUSPENDCONTEXT)( ALCcontext *context );
typedef void           (ALC_APIENTRY *LPALCDESTROYCONTEXT)( ALCcontext *context );
typedef ALCcontext *   (ALC_APIENTRY *LPALCGETCURRENTCONTEXT)( void );
typedef ALCdevice *    (ALC_APIENTRY *LPALCGETCONTEXTSDEVICE)( ALCcontext *context );
typedef ALCdevice *    (ALC_APIENTRY *LPALCOPENDEVICE)( const ALCchar *devicename );
typedef ALCboolean     (ALC_APIENTRY *LPALCCLOSEDEVICE)( ALCdevice *device );
typedef ALCenum        (ALC_APIENTRY *LPALCGETERROR)( ALCdevice *device );
typedef ALCboolean     (ALC_APIENTRY *LPALCISEXTENSIONPRESENT)( ALCdevice *device, const ALCchar *extname );
typedef void *         (ALC_APIENTRY *LPALCGETPROCADDRESS)(ALCdevice *device, const ALCchar *funcname );
typedef ALCenum        (ALC_APIENTRY *LPALCGETENUMVALUE)(ALCdevice *device, const ALCchar *enumname );
typedef const ALCchar* (ALC_APIENTRY *LPALCGETSTRING)( ALCdevice *device, ALCenum param );
typedef void           (ALC_APIENTRY *LPALCGETINTEGERV)( ALCdevice *device, ALCenum param, ALCsizei size, ALCint *dest );
typedef ALCdevice *    (ALC_APIENTRY *LPALCCAPTUREOPENDEVICE)( const ALCchar *devicename, ALCuint frequency, ALCenum format, ALCsizei buffersize );
typedef ALCboolean     (ALC_APIENTRY *LPALCCAPTURECLOSEDEVICE)( ALCdevice *device );
typedef void           (ALC_APIENTRY *LPALCCAPTURESTART)( ALCdevice *device );
typedef void           (ALC_APIENTRY *LPALCCAPTURESTOP)( ALCdevice *device );
typedef void           (ALC_APIENTRY *LPALCCAPTURESAMPLES)( ALCdevice *device, ALCvoid *buffer, ALCsizei samples );

#if defined(TARGET_OS_MAC) && TARGET_OS_MAC
 #pragma export off
#endif

/**
 * @}
 */


#if defined(__cplusplus)
}
#endif

#endif /* AL_ALC_H */
