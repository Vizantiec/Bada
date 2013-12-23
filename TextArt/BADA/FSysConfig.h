/* $Change: 1114438 $ */
#ifndef _FSYSTEMCONFIG_H_
#define _FSYSTEMCONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FSYSTEMAPI_EXPORTS)
#       define _EXPORT_SYSTEM_ __declspec(dllexport)
#	else
#		define _EXPORT_SYSTEM_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_SYSTEM_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_SYSTEM_

#else
#	define _EXPORT_SYSTEM_

#endif

#endif

