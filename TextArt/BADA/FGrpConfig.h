/* $Change: 1114438 $ */
#ifndef _FGRPCONFIG_H_
#define _FGRPCONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FGRPAPI_EXPORTS)
#       define _EXPORT_GRP_ __declspec(dllexport)
#	else
#		define _EXPORT_GRP_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_GRP_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_GRP_

#else
#	define _EXPORT_GRP_

#endif

#endif

