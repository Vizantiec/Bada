/* $Change: 431318 $ */
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
 * @file		FTestMacroAssert.h
 * @brief		This is the header file for the Assertion macro.
 *
 * This header file contains the definitions for the Assertion macro.
 */
#ifndef _FTEST_MACRO_ASSERT_H_
#define _FTEST_MACRO_ASSERT_H_

#include <FBase.h>
#include "FTestAssert.h"
#include "FTestTestConstants.h"

namespace Osp { namespace Test {

/**
 * @defgroup    GroupTestAssertionMacro  Test Assertion Macros
 * @since		1.1
 *
 *
 */

 /**
 * @defgroup    GroupTestCheckMacro  Test Check Macros
 * @since		1.1
 *
 * 
 */

/**
* @internal
* This structure is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this structure.
* @since			1.1
*
* Comparison of all types.
*/
template <class T>
struct __Comparison
{
	static bool Equal(const T& x, const T& y) {
		return x == y;
	}

	static bool IsNull(const T* ptr) {
		return ptr == null;
	}
};

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c T.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c T
* @param[in]	actual		The actual instance of the type @c T
* @param[in]   filePath 	The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by an Assert Macro @n
							The value is @c true if this method is called by Check Macro
* @hideinitializer
*/
template <class T>
void AssertEquals(  	Osp::Base::String message,
						const T& expected,
						const T& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck)
{
	if (!__Comparison<T>::Equal(expected,actual))
		Assert::Fail(message,filePath, lineNum, isCheck);
}



/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::Double.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c Osp::Base::Double
* @param[in]	actual		The actual instance of the type @c Osp::Base::Double
* @param[in]   filePath 	The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
							The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::Double> (
						Osp::Base::String message,
						const Osp::Base::Double& expected,
						const Osp::Base::Double& actual,
						const Osp::Base::String& filePath, 
						int lineNum,
						bool isCheck);


/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type Osp::Base::Float.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c Osp::Base::Float
* @param[in]	actual		The actual instance of the type @c Osp::Base::Float
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
						The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::Float> (
						Osp::Base::String message,
						const Osp::Base::Float& expected,
						const Osp::Base::Float& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);


/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::Integer.
*
* @param[in]	message			The user-defined message
* @param[in]	expected		The expected instance of the type @c Osp::Base::Integer
* @param[in]	actual		The actual instance of the type @c Osp::Base::Integer
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
						The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::Integer> (
						Osp::Base::String message,
						const Osp::Base::Integer& expected,
						const Osp::Base::Integer& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::Int8.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c Osp::Base::Int8
* @param[in]	actual		The actual instance of the type @c Osp::Base::Int8
* @param[in]   filePath 	The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
							The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::Int8> (
						Osp::Base::String message,
						const Osp::Base::Int8& expected,
						const Osp::Base::Int8& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::Long.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c Osp::Base::Long
* @param[in]	actual		The actual instance of the type @c Osp::Base::Long
* @param[in]   filePath 	The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
							The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::Long> (
		Osp::Base::String message,
						const Osp::Base::Long& expected,
						const Osp::Base::Long& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::LongLong.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c Osp::Base::LongLong
* @param[in]	actual		The actual instance of the type @c Osp::Base::LongLong
* @param[in]   filePath 	The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
							The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::LongLong> (
						Osp::Base::String message,
						const Osp::Base::LongLong& expected,
						const Osp::Base::LongLong& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::Short.
*
* @param[in]	message			The user-defined message
* @param[in]	expected	The expected instance of the type @c Osp::Base::Short
* @param[in]	actual		The actual instance of the type @c Osp::Base::Short
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
						The value is @c true if this method is called by Check Macro
*/
template<>
void AssertEquals<Osp::Base::Short> (
						Osp::Base::String message,
						const Osp::Base::Short& expected,
						const Osp::Base::Short& actual,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c char*.
*
* @param[in]	message			The user-defined message
* @param[in]	 expected		The expected instance of the type @c char*
* @param[in]	 actual 	 	The actual instance of the type @c char*
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum			The line number in the file that calls some Macro using this method
* @param[in]   isCheck			The value is @c false if this method is called by Assert Macro @n
								The value is @c true if this method is called by Check Macro
*/
void AssertEquals(Osp::Base::String message,
							const char* expected,
							const char* actual,
							const Osp::Base::String& filePath, int lineNum,
							bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c mchar*.
*
* @param[in]	message			The user-defined message
* @param[in]	 expected		The expected instance of the type @c mchar*
* @param[in]	 actual 	 	The actual instance of the type @c mchar*
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum			The line number in the file that calls some Macro using this method
* @param[in]   isCheck			The value is @c false if this method is called by Assert Macro @n
								The value is @c true if this method is called by Check Macro
*/
void AssertEquals(Osp::Base::String message,
							const mchar* expected,
							const mchar* actual,
							const Osp::Base::String& filePath, int lineNum,
							bool isCheck);

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c Osp::Base::Double&.
*
* @param[in]	 message		 	The user-defined message
* @param[in]	 expected		The expected instance of the type @c Osp::Base::Double
* @param[in]	 actual 	 	The actual instance of the type @c Osp::Base::Double
* @param[in]	 delta			The tolerance
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum			The line number in the file that calls some Macro using this method
* @param[in]   isCheck			The value is @c false if this method is called by Assert Macro @n
								The value is @c true if this method is called by Check Macro
*/
void AssertEqualDelta(
						Osp::Base::String message,
						const Osp::Base::Double& expected,
						const Osp::Base::Double& actual,
						const Osp::Base::Double& delta,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);


/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
* Checks for equivalence between two instances of the type @c double
*
* @param[in]	 message		 	The user-defined message
* @param[in]	 expected	The expected instance of the type @c double
* @param[in]	 actual 	 	The actual instance of the type @c double
* @param[in]	 delta		The tolerance
* @param[in]   filePath 		The file path to the file that calls some Macro using this method
* @param[in]   lineNum		The line number in the file that calls some Macro using this method
* @param[in]   isCheck		The value is @c false if this method is called by Assert Macro @n
							The value is @c true if this method is called by Check Macro
*/
void AssertEqualDelta(  
						Osp::Base::String message,
						double expected,
						double actual,
						double delta,
						const Osp::Base::String& filePath, int lineNum,
						bool isCheck);




/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
 * Checks for null values.
 *
 * @param[in]		message			The user-defined message
 * @param[in]		ptr			The pointer to check
 * @param[in]		filePath	The file path to the file that calls some Macro using this method
 * @param[in]		lineNum 	The line number in the file that calls some Macro using this method
 * @param[in]		isCheck 	The value is @c false if this method is called by Assert Macro @n
								The value is @c true if this method is called by Check Macro
 */
template <class T>
void AssertNull(Osp::Base::String message, const T* ptr, const Osp::Base::String& filePath, int lineNum, bool isCheck)
{
	if (!__Comparison<T>::IsNull(ptr))
		Assert::Fail(message, filePath, lineNum, isCheck);
}

/**
* @internal
* This function is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this function.
* @since			1.1
*
 * Checks for not null values.
 *
 * @param[in]		message			The user-defined message
 * @param[in]		ptr			The pointer to check
 * @param[in]		filePath		 The file path to the file that calls some Macro using this method
 * @param[in]		lineNum 	 The line number in the file that calls some Macro using this method
 * @param[in]		isCheck 	 The value is @c false if this method is called by Assert Macro @n
								The value is @c true if this method is called by Check Macro
 */
template <class T>
void AssertNotNull(Osp::Base::String message, const T* ptr, const Osp::Base::String& filePath, int lineNum, bool isCheck)
{
	if (__Comparison<T>::IsNull(ptr))
		Assert::Fail(message,filePath, lineNum, isCheck);
}

}}

/*____________________________________________________________________________________________

                                    MACRO DEFINE - CHECK
  ____________________________________________________________________________________________*/
  
/**
* @internal
* This macro is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this macro.
* @since			1.1
*/
   
#define __TestCheckMessage(condition, message)									\
	if (!(condition)) Osp::Test::Assert::Fail(message,__FILE__, __LINE__, true)
	
/**	
 *
 * @addtogroup 	GroupTestCheckMacro   
 *
 * @{
 */
		
		
/**
* @def TestCheckMessage(condition, message)
* Checks whether the specified @c condition evaluates to @c false and uses the content of the specified @c message as a failure message.
*
* @since			1.1
* @param[in]	condition	The condition
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestCheckMessage(condition, message)									\
	__TestCheckMessage(condition, __MakeString2(L"The condition("#condition") is false : ",message))


/**
* @def TestCheck(condition)
* Checks whether the specified @c condition evaluates to @c false.
*
* @since			1.1
* @param[in]	condition	The condition
* @hideinitializer
*/
#define TestCheck(condition)												\
	__TestCheckMessage(condition, L"The condition("#condition") is false")

/**
* @def TestCheckEqualMessage(expected,actual, message)
* Checks whether the values of the specified @c expected and @c actual are equal. If @c false, the content of the specified @c message is used as a failure message.
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestCheckEqualMessage(expected,actual, message)              	\
	Osp::Test::AssertEquals(__MakeString(expected,actual,message),expected,actual, __FILE__, __LINE__, true)

/**
* @def TestCheckEqual(expected,actual)
* Checks whether the values of the specified @c expected and @c actual are equal.
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @hideinitializer
*/
#define TestCheckEqual(expected,actual)                          	\
	Osp::Test::AssertEquals(__MakeString(expected,actual,""),expected,actual, __FILE__, __LINE__, true)

/**
* @def TestCheckEqualDoubleWithToleranceMessage(expected,actual, delta, message)
* Checks whether the values of the specified variables are equal within a given tolerance value of @c delta. If the difference between the values of the variables exceeds @c delta, the content of @c message is used as a failure message.
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @param[in]	delta	The tolerance value
* @param[in]	message		The failure message to report
* @remarks 		Use this macro with primitive double type. Do not use this Assertion macro with Osp::Base::Double. 
* @hideinitializer
*/
#define TestCheckEqualDoubleWithToleranceMessage(expected,actual,delta, message)  	\
	Osp::Test::AssertEqualDelta(__MakeString(expected, actual, message),expected,actual,delta, __FILE__, __LINE__, true)

/**
* @def TestCheckEqualDoubleWithTolerance(expected,actual, delta)
* Checks whether the values of the specified variables are equal given a tolerance value of @c delta.
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @param[in]	delta	The tolerance value
* @remarks 		Use this macro with primitive double type. Do not use this Assertion macro with Osp::Base::Double. 
* @hideinitializer
*/
#define TestCheckEqualDoubleWithTolerance(expected,actual,delta)       	\
	Osp::Test::AssertEqualDelta(__MakeString(expected, actual, ""),expected,actual,delta, __FILE__, __LINE__, true)

// bada SDK 1.0 does not support try-catch exception.
//ASSERT THROW
#define __TestCheckThrowFunction(expression,exception_type, message1, message2)		\
	do{                                                           		\
        try {                                                       	\
            expression;                                             	\
        } catch (const exception_type &) {                          	\
            break;														\
        } catch (...) {                                             	\
			Osp::Test::Assert::Fail(message2, __FILE__, __LINE__, true);	\
			break;														\
		}   		                                                	\
		Osp::Test::Assert::Fail(message1, __FILE__, __LINE__, true); \
    }while(false);														\

/**
* @def TestCheckThrowMessage(expression,exception_type, message)
* Checks whether the specified @c expression throws @c exception_type. If @c false, the content of the specified @c message is used as a failure message.
*
* @since			1.1
* @param[in]	expression 		The statement that throws a specific exception
* @param[in]	exception_type	An exception to be thrown
* @param[in]	message				The failure message to report
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestCheckThrowMessage(expression,exception_type, message)		\
	__TestCheckThrowFunction(expression,exception_type, __MakeString2(L"Expected:<"#exception_type"> but was not thrown : ",message), __MakeString2(L"Expected:<"#exception_type"> but an unexpected exception was thrown : ",message))

/**
* @def TestCheckThrow(expression,exception_type)
* Checks whether the specified @c expression throws @c exception_type.
*
* @since			1.1
* @param[in]	expression 		The statement that throws a specific exception
* @param[in]	exception_type	An exception to be thrown
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestCheckThrow(expression,exception_type)                	\
	__TestCheckThrowFunction(expression,exception_type, L"Expected:<"#exception_type"> but was not thrown", L"Expected:<"#exception_type"> but an unexpected exception was thrown")

//CHECK NO THROW
#define __TestCheckNoThrowFunctionMessage(expression, message)          \
		try {														\
			expression; 											\
		} catch (...) {												\
			Osp::Test::Assert::Fail(message, __FILE__, __LINE__, true);	\
		}															\


/**
* @def TestCheckNoThrowMessage(expression,message)
* Checks whether the specified @c expression does not throw an exception. If it throws an exception, the content of the specified @c message is used as a failure message.
*
* @since			1.1
* @param[in]	expression 		The statement that does not throw any exception
* @param[in]	message				The failure message to report
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestCheckNoThrowMessage(expression, message)                	\
	__TestCheckNoThrowFunctionMessage(expression, __MakeString2(L"Unexpected exception caught : ",message))

/**
* @def TestCheckNoThrow(expression)
* Checks whether the specified @c expression does not throw an exception.
*
* @since			1.1
* @param[in]	expression 		The statement that does not throw any exception
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestCheckNoThrow(expression)                            	\
	__TestCheckNoThrowFunctionMessage(expression, L"Unexpected exception caught")


/**
* @def TestCheckNotNullMessage(ptr, message)
* Checks whether the specified @c ptr is not @c null. If it is null, the content of the specified @c message is used as a failure message. 
*
* @since			1.1
* @param[in]	ptr 	The pointer to a variable
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestCheckNotNullMessage(ptr, message)                       	\
	Osp::Test::AssertNotNull(__MakeString2(L"The pointer("#ptr") is null : ",message),(ptr), __FILE__, __LINE__, true)

/**
* @def TestCheckNotNull(ptr)
* Checks whether the specified @c ptr is not @c null.
*
* @since			1.1
* @param[in]	ptr 	The pointer to a variable
* @hideinitializer
*/
#define TestCheckNotNull(ptr)                                   	\
	Osp::Test::AssertNotNull(L"The pointer("#ptr") is null" ,(ptr), __FILE__, __LINE__, true)

/** 
*
@} */
	
/*____________________________________________________________________________________________

                                    MACRO DEFINE - ASSERT
  ____________________________________________________________________________________________*/

/**
* @internal
* This macro is for internal use only. The bada platform team is not
* responsible for any behavioral correctness, consistency, and
* security-related issues that might arise after using this macro.
 * @since			1.1
 */

#define __TestAssertMessage(condition, message)					\
	if (!(condition)) Osp::Test::Assert::Fail(message, __FILE__, __LINE__, false)

/**
 * @addtogroup 	GroupTestAssertionMacro  
 *
 * @{
 */	

/**
* @def TestAssertMessage(condition, message)
* Makes an assertion if the specified @c condition evaluates to @c false and uses the content of the specified @c message for the failure message.
*
* @since			1.1
* @param[in]	condition	The condition
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestAssertMessage(condition, message)                               \
	__TestAssertMessage(condition, __MakeString2(L"The condition("#condition") is false : ", message))

/**
* @def TestAssert(condition)
* Makes an assertion if the specified @c condition evaluates to @c false.
*
* @since			1.1
* @param[in]	condition	The condition
* @hideinitializer
*/
#define TestAssert(condition)                                           \
	__TestAssertMessage(condition, L"The condition("#condition") is false")


/**
* @def TestFailMessage(message)
* Makes an assertion and uses the content of the specified @c message for the failure message.
*
* @since			1.1
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestFailMessage(message)                                      \
	__TestAssertMessage(false, __MakeString2(L"Assertion Failure : ", message))

/**
* @def TestFail()
* Makes an assertion.
* @since			1.1
* @hideinitializer
*/
#define TestFail()                                                 \
	__TestAssertMessage(false, L"Assertion Failure")

/**
* @def TestAssertEqualMessage(expected,actual, message)
* Makes an assertion if the values of the specified @c expected and @c actual are not equal. The content of the specified @c message is used as an assertion message.
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestAssertEqualMessage(expected,actual, message)              \
	Osp::Test::AssertEquals( __MakeString(expected,actual, message),expected,actual, __FILE__, __LINE__, false)

/**
* @def TestAssertEqual(expected,actual)
* Makes an assertion if the values of the specified @c expected and @c actual are not equal. 
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @hideinitializer
*/
#define TestAssertEqual(expected,actual)                          \
	Osp::Test::AssertEquals(__MakeString(expected,actual, ""),expected,actual, __FILE__, __LINE__, false)

/**
* @def TestAssertEqualDoubleWithToleranceMessage(expected,actual,delta,message)
* Makes an assertion if two variables are not equal given a tolerance(@c delta) and uses @c message for the failure message.
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @param[in]	delta	The tolerance value
* @param[in]	message		The failure message to report
* @remarks 		Use this macro with primitive double type. Do not use this Assertion macro with Osp::Base::Double. 
* @hideinitializer
*/
#define TestAssertEqualDoubleWithToleranceMessage(expected,actual,delta,message)  \
	Osp::Test::AssertEqualDelta( __MakeString(expected,actual, message) ,expected,actual,delta, __FILE__, __LINE__, false)

/**
* @def TestAssertEqualDoubleWithTolerance(expected,actual, delta)
* Makes an assertion if two variables are not equal given a tolerance(@c delta).
*
* @since			1.1
* @param[in]	expected The expected value
* @param[in]	actual	The actual value
* @param[in]	delta	The tolerance value
* @remarks 		Use this macro with primitive double type. Do not use this Assertion macro with Osp::Base::Double. 
* @hideinitializer
*/
#define TestAssertEqualDoubleWithTolerance(expected,actual,delta)              \
	Osp::Test::AssertEqualDelta(__MakeString(expected,actual, ""),expected,actual,delta, __FILE__, __LINE__, false)

// bada SDK 1.0 does not support try-catch exception.
#define __TestAssertThrowFunction(expression,exception_type, message, message2)   \
    do {                                                            \
        try {                                                       \
            expression ;                                            \
        } catch (const exception_type &) {                          \
			break;													\
        } catch (...) {                      	                    \
	        Osp::Test::Assert::Fail(message2, __FILE__, __LINE__, false); \
	        break;													\
        }                                                           \
        Osp::Test::Assert::Fail(message, __FILE__, __LINE__, false); \
    }while( false);													\

/**
* @def TestAssertThrowMessage(expression,exception_type, message)
* Makes an assertion if the specified @c expression does not throw @c exception_type. The content of the specified @c message is used as an assertion message.
*
* @since			1.1
* @param[in]	expression 		The statement that throws a specific exception
* @param[in]	exception_type	An exception to be thrown
* @param[in]	message				The failure message to report
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestAssertThrowMessage(expression,exception_type, message)		\
	__TestAssertThrowFunction(expression,exception_type, __MakeString2(L"Expected:<"#exception_type"> but was not thrown : ",message), __MakeString2(L"Expected:<"#exception_type"> but an unexpected exception was thrown : ",message))

/**
* @def TestAssertThrow(expression,exception_type)
* Makes an assertion if the specified @c expression does not throw @c exception_type.
*
* @since			1.1
* @param[in]	expression 		The statement that throws a specific exception
* @param[in]	exception_type	An exception to be thrown
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestAssertThrow(expression,exception_type)                	\
	__TestAssertThrowFunction(expression,exception_type, L"Expected:<"#exception_type"> but was not thrown", L"Expected:<"#exception_type"> but an unexpected exception was thrown")


//ASSERT NO THROW

#define __TestAssertNoThrowFunctionMessage(expression, message)        	\
	try {															\
		expression; 												\
	} catch (...) { 												\
		Osp::Test::Assert::Fail(message, __FILE__, __LINE__, false);	\
	}																\

    
/**
* @def TestAssertNoThrowMessage(expression,message)
* Makes an assertion if the specified @c expression throws an exception. The content of the specified @c message is used as an assertion message.
*
* @since			1.1
* @param[in]	expression 		The statement that does not throw any exception
* @param[in]	message				The failure message to report
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestAssertNoThrowMessage(expression,message)                \
	__TestAssertNoThrowFunctionMessage(expression, __MakeString2(L"Unexpected exception caught : ", message))

/**
* @def TestAssertNoThrow(expression)
* Makes an assertion if the specified @c expression throws an exception.
*
* @since			1.1
* @param[in]	expression 		The statement that does not throw any exception
* @remarks 		Do not use this Assertion macro in SDK v1.0 because the try-catch exception is not supported.
* @hideinitializer
*/
#define TestAssertNoThrow(expression)                           \
	__TestAssertNoThrowFunctionMessage(expression, L"Unexpected exception caught")

/**
* @def TestAssertNotNullMessage(ptr, message)
* Makes an assertion if the specified @c ptr is @c null. The content of the specified @c message is used as an assertion message.
* 
* @since			1.1
* @param[in]	ptr 	The pointer to a variable
* @param[in]	message		The failure message to report
* @hideinitializer
*/
#define TestAssertNotNullMessage(ptr, message)                       \
	Osp::Test::AssertNotNull(__MakeString2(L"The pointer("#ptr") is null :", message),(ptr), __FILE__, __LINE__, false)

/**
* @def TestAssertNotNull(ptr)
* Makes an assertion if the specified @c ptr is @c null.
*
* @since			1.1
* @param[in]	ptr 	The pointer to a variable
* @hideinitializer
*/
#define TestAssertNotNull(ptr)                                   \
	Osp::Test::AssertNotNull(L"The pointer("#ptr") is null",(ptr), __FILE__, __LINE__, false)

#endif /* _FTEST_MACRO_ASSERT_H_ */

/** 
*
@} */
