/* $Change: 1114438 $ */
#ifndef _FWEBCONFIG_H_
#define _FWEBCONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FWEBAPI_EXPORTS)
#       define _EXPORT_WEB_ __declspec(dllexport)
#	else
#		define _EXPORT_WEB_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_WEB_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_WEB_

#else
#	define _EXPORT_WEB_

#endif

#endif

