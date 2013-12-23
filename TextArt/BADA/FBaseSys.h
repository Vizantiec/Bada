/* $Change: 1142016 $ */
//
// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.

// This software contains confidential and proprietary information
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such
// Confidential Information and shall use the software only in accordance with
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file		FBaseSys.h
 * @brief		This header file defines the diagnostic types.
 *
 * This header file contains the definitions of the diagnostic types.
 */
#ifndef _FBASE_SYS_H_
#define _FBASE_SYS_H_

#include "FBaseConfig.h"


#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

/**
 * @defgroup GroupMacros Debugging Macros
 *
 * This page describes bada debugging macros.
 *
 * @since	1.0
 */

#ifdef _DEBUG
// AppLog Macro
#if defined(_MSC_VER)
#define AppLog(...)						__App_info(__FUNCTION__ , __LINE__, __VA_ARGS__)
#define AppLogDebug(...)				__App_debug(__FUNCTION__ , __LINE__, __VA_ARGS__)
#define AppLogException(...)			__App_exception(__FUNCTION__ , __LINE__, __VA_ARGS__)
#else
#define AppLog(...)						__App_info(__PRETTY_FUNCTION__ , __LINE__, __VA_ARGS__)
#define AppLogDebug(...)				__App_debug(__PRETTY_FUNCTION__ , __LINE__, __VA_ARGS__)
#define AppLogException(...)			__App_exception(__PRETTY_FUNCTION__ , __LINE__, __VA_ARGS__)
#endif


#define AppLogIf(condition, ...) \
if (condition) { \
		__App_info(__PRETTY_FUNCTION__ , __LINE__, __VA_ARGS__); \
	} else {;}

#define AppLogDebugIf(condition, ...) \
if (condition) { \
	__App_debug(__PRETTY_FUNCTION__ , __LINE__, __VA_ARGS__); \
	} else {;} 

#define AppLogExceptionIf(condition, ...) \
if (condition) { \
	__App_exception(__PRETTY_FUNCTION__ , __LINE__, __VA_ARGS__); \
	} else {;} 


#define AppAssert(condition) \
	if (!(condition)) { \
		__App_assert(__FILE__, __LINE__); \
	} else {;}
#define AppAssertf(condition, ...) \
	if (!(condition)) { \
		__App_assertf(#condition, __FILE__, __LINE__, __VA_ARGS__); \
	} else {;} 
#else // _DEBUG

/**
 * @addtogroup 	GroupMacros  
 *
 * @{
 */
 /**
 * This macro allows display of arbitrary messages for future examination. 
 *
 * @since			1.0
 * @param[in]	    ... 		The message to be displayed 
 *
 *  The following example demonstrates how to use the AppLog macros.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLog("Initialization successful.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLog(...) ((void) 0)

/**
 * This macro needs to be added in your program wherever you need Info messages to be displayed in your output. 
 *
 * @since			1.0
 * @param[in]	    ...			The message to be displayed
 *
 *  @image html debugging_applog_output.png 
 *
 *  The following example demonstrates how to use the AppLogDebug macros.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebug("Invoked with value: %d", value);
 *
 *	   //...
 *
 *	   AppLogDebug("Exit.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogDebug(...) ((void) 0)

/**
 * This macro needs to be added in your program wherever you need Info messages to be displayed in your output.
 *
 * @since			1.0
 * @param[in]	    ...				The message to be displayed
 *
 *  The following example demonstrates how to use the AppLogException macros.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebug("Invoked with value: %d", value);
 *	   //...
 *	   if (something_wrong)   // The Try family macros can be used instead.
 *	   {
 *	      AppLogException("An unexpected error occurred.");
 *
 *	      return false;
 *	   }
 *
 *	   AppLog("Initialization successful.");
 *	   AppLogDebug("Exit.");
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogException(...) ((void) 0)

/**
 * This macro is used to check logical errors in a program. 
 * If the assertion fails, the current process is killed.
 *
 * @since			1.0
 * @param[in]	    condition  The condition to succeed
 * @hideinitializer
 */
#define AppAssert(condition) ((void) 0)

/**
 * This macro is used to check logical errors in a program. 
 * If the assertion fails, a message is printed on the console and the current process is killed.
 *
 * @since			1.0
 * @param[in]	    condition				The condition to succeed
 * @param[in]	    ...						The message to be displayed, if the assertion fails
 *
 * @image html debugging_appassert.png 
 *
 * The following example demonstrates how to use the Assert macro.
 *
 * @code
 *	result
 *	MyClass::DoSomething(void)
 *	{
 *	   result r = E_SUCCESS;
 *	   r = mutex.Acquire();
 *	   // do something
 *	   r = mutex.Release();
 *
 *	   // If false, console prints "Mutex Release Failed."
 *	   // and the process is killed.
 *	   AppAssertf(r == E_SUCCESS, "Mutex Release Failed.");
 *
 *	   return r;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppAssertf(condition, ...) ((void) 0)

/**
 * This macro is added in a program to display a message when the condition is true.
 *
 * @since         1.0
 * @return        void
 * @param[in]     condition                     The condition to succeed 
 * @param[in]     ...                           The message to be displayed
 *
 *  The following example demonstrates how to use the AppLogIf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogIf(value !=0, "Invoked with value: %d", value);
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogIf(condition, ...) ((void) 0)

/**
 * This macro is added in a program to display a debug message when the condition is true.
 *
 * @since         1.0
 * @return        void
 * @param[in]     condition                     The condition to succeed
 * @param[in]     ...                           The message to be displayed
 *
 *  The following example demonstrates how to use the AppLogDebugIf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   AppLogDebugIf(value !=0, "Invoked with value: %d", value);
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogDebugIf(condition, ...) ((void) 0)

/**
 * This macro is added in a program to display an exception message when the condition is true.
 *
 * @since 		  1.0
 * @return        void
 * @param[in]     condition                    The condition to succeed
 * @param[in]     ...                          The message to be displayed
 *
 *  The following example demonstrates how to use the AppLogExceptionIf macro.
 *
 * @code
 *	Bool
 *	MyEngine::Init(int value)
 *	{
 *	   int status;
 *
 *	   AppLogExceptionIf(status != 0, "status : %d.", status);
 *	   //...
 *
 *	   return true;
 *	}
 * @endcode
 * @hideinitializer
 */
#define AppLogExceptionIf(condition, ...) ((void) 0)
/** @} */    



#endif // _DEBUG
	
// Try Macros
/**
 * @addtogroup 	GroupMacros  
 *
 * @{
 */
/**
 * Tests the condition. If the condition is false, it prints a message, executes statements, 
 * and goes to <tt>CATCH</tt>.
 *
 * @since		1.0
 * @param[in]	condition				The condition to succeed
 * @param[in]	statements				The statements to set
 * @param[in]	...						The message to be displayed
 *
 *  The following example demonstrates how to use the Try macro.
 *
 * @code
 *	const  A*
 *	MyClass::DoSomething(const mchar* pValue)
 *	{
 *	   result r = E_SUCCESS;
 *
 *	   // Do something...
 *
 *	   // If pValue is null, print "pValue == null" to the
 *	   // console and return E_INVALID_ARG.
 *	   TryCatch(pValue != null, r = E_INVALID_ARG, "pValue == null");
 *
 *	   SetLastResult(E_SUCCESS);
 *
 *	   return _pValue;
 *
 *	   CATCH:
 *	      SetLastResult(r);
 *
 *	      return null;
 *	}
 * @endcode
 * @hideinitializer
 */


#define TryCatch(condition, statements, ...) \
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
		statements; \
		goto CATCH; \
	} else {;}
/**
 * If the condition is false, the message is printed and a value is returned.
 *
 * @since		1.0
 * @param[in]	condition			The condition to succeed
 * @param[in]	returnValue         The return value when the condition is false
 * @param[in]   ...					The message to be displayed
 * @hideinitializer
 */
#define TryReturn(condition, returnValue, ...) \
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
		return returnValue; \
	} else {;}
/**
 * If the condition is false, the message is printed and no value is returned.
 *
 * @since		1.0
 * @param[in]	condition			The condition to succeed
 * @param[in]   ...					The message to be displayed
 * @hideinitializer
 */
#define TryReturnVoid(condition, ...) \
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
		return; \
	} else {;}
/**
 * If the condition is false, the message is printed.
 *
 * @since		1.0
 * @param[in]	condition	The condition to succeed
 * @param[in]   ...		    The message to be displayed
 * @hideinitializer
 */
#define TryLog(condition, ...) \
	if (!(condition)) { \
		AppLogException(__VA_ARGS__); \
	} else {;}
/** 
*
@} */



_EXPORT_BASE_	void __App_info(const char* pFunction, int lineNumber, const char* pFormat, ...);
_EXPORT_BASE_	void __App_debug(const char* pFunction, int lineNumber, const char* pFormat, ...);
_EXPORT_BASE_	void __App_exception(const char* pFunction, int lineNumber, const char* pFormat, ...);
_EXPORT_BASE_	void __App_assert(const char* pFileName, int lineNumber);
_EXPORT_BASE_	void __App_assertf(const char *expr, const char* pFileName, int lineNumber, const char* pFormat, ...);


#ifdef __cplusplus
}
#endif // __cplusplus


#endif// _FBASE_SYS_H_
