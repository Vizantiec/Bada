/* $Change: 1114438 $ */
#ifndef _FUICONFIG_H_
#define _FUICONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FUIAPI_EXPORTS)
#       define _EXPORT_UI_ __declspec(dllexport)
#	else
#		define _EXPORT_UI_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_UI_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_UI_

#else
#	define _EXPORT_UI_

#endif

#endif

