/* $Change: 1114438 $ */
#ifndef _FAPP_CONFIG_H_
#define _FAPP_CONFIG_H_

#if defined(_WIN32)             // MS Compiler & MinGW GCC
#	if defined(_FAPPAPI_EXPORTS)
#       define _EXPORT_APP_ __declspec(dllexport)
#	else
#		define _EXPORT_APP_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_APP_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_APP_

#else
#	define _EXPORT_APP_

#endif

#endif // _FAPP_CONFIG_H_

