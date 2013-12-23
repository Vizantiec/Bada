/* $Change: 1114438 $ */
#ifndef _FSEC_CONFIG_H_
#define _FSEC_CONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FSECURITYAPI_EXPORTS)
#       define _EXPORT_SECURITY_ __declspec(dllexport)
#	else
#		define _EXPORT_SECURITY_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_SECURITY_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_SECURITY_

#else
#	define _EXPORT_SECURITY_

#endif

#endif	// _FSEC_CONFIG_H_

