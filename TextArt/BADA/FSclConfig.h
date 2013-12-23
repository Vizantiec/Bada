/* $Change: 1114438 $ */
#ifndef _FSCL_CONFIG_H_
#define _FSCL_CONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FSOCIALAPI_EXPORTS)
#       define _EXPORT_SOCIAL_ __declspec(dllexport)
#	else
#		define _EXPORT_SOCIAL_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_SOCIAL_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_SOCIAL_

#else
#	define _EXPORT_SOCIAL_

#endif

#endif

