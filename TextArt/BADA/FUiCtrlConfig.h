/* $Change: 1114438 $ */
#ifndef _FUI_CTRL_CONFIG_H_
#define _FUI_CTRL_CONFIG_H_

#if defined(_WIN32) // MS Compiler
#	if defined(_FUICTRLAPI_EXPORTS)
#       define _EXPORT_CONTROLS_ __declspec(dllexport)
#	else
#		define _EXPORT_CONTROLS_ __declspec(dllimport)
#	endif

#elif defined(__GNUG__)   // GCC
#   define _EXPORT_CONTROLS_ __attribute__((visibility("default")))

#elif defined(__ARMCC_VERSION)  // ARM Compiler (RVCT 3.1)
#	define _EXPORT_CONTROLS_

#else
#	define _EXPORT_CONTROLS_

#endif

#endif // _FUI_CTRL_CONFIG_H_

