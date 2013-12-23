/* $Change: 1114438 $ */
#ifndef _FTEXTCONFIG_H_
#define _FTEXTCONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FTEXTAPI_EXPORTS)
#       define _EXPORT_TEXT_ __declspec(dllexport)
#	else
#		define _EXPORT_TEXT_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_TEXT_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_TEXT_

#else
#	define _EXPORT_TEXT_

#endif

#endif

