/*  */
#ifndef _FUIANIM_CONFIG_H_
#define _FUIANIM_CONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FUIANIMAPI_EXPORTS)
#       define _EXPORT_ANIMATION_ __declspec(dllexport)
#	else
#		define _EXPORT_ANIMATION_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_ANIMATION_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_ANIMATION_

#else
#	define _EXPORT_ANIMATION_

#endif

#endif // _FUIANIM_CONFIG_H_

