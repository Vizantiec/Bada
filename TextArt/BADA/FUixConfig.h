#ifndef _FUIXCONFIG_H_
#define _FUIXCONFIG_H_


#if	defined(_MSC_VER)
#	if defined(_FUIXAPI_EXPORTS)
#		define _EXPORT_UIX_	__declspec(dllexport)
#	else
#		define _EXPORT_UIX_	__declspec(dllimport)
#	endif
#else
#	define _EXPORT_UIX_
#endif
#endif