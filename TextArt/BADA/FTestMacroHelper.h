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
 * @file		FTestMacroHelper.h
 * @brief		This is the header file for the Helper macro.
 *
 * This header file contains the definitions for the Helper macro.
 */
#ifndef _FTEST_MACRO_HELPER__H_
#define _FTEST_MACRO_HELPER__H_

#include "FTestTestRegistry.h"
#include "FTestSimpleTestCase.h"
#include "FTestStressTestCase.h"
#include "FTestExceptionTestCase.h"

/**
 * @defgroup GroupTestHelperMacro  Test Helper Macros
 * @since	1.1
 *
 */

/*____________________________________________________________________________________________

                                    MACRO DEFINE - TESTAUTOREGISTRY
  ____________________________________________________________________________________________*/

/**
 * @addtogroup 	GroupTestHelperMacro  
 *
 * @{
 */
 
/**
* @def NEW_SIMPLE_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName)
* Creates an instance of SimpleTestCase.
*
* @since			1.1
* @param[in]	TestFixtureClassName The test fixture type
* @param[in]	TestCaseName	The method name of %TestFixture that is called for testing
* @hideinitializer
*/
#define NEW_SIMPLE_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName)								\
					new Osp::Test::SimpleTestCase<TestFixtureClassName>(#TestCaseName, &TestFixtureClassName::TestCaseName,  __FILE__, __LINE__)

/**
* @def NEW_STRESS_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName, RepeatedCount)
* Creates an instance of StressTestCase.
*
* @since			1.1
* @param[in]	TestFixtureClassName The test fixture type
* @param[in]	TestCaseName	The name of test case and the method name of %TestFixture that is called for testing
* @param[in]	RepeatedCount	The count to be repeated to invoke the method whose name is TestCaseName
* @hideinitializer
*/
#define NEW_STRESS_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName, RepeatedCount)						\
					new Osp::Test::StressTestCase(*NEW_SIMPLE_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName), RepeatedCount,  __FILE__, __LINE__)

/**
* @def NEW_EXCEPTION_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName, ExceptionType)
* Creates an instance of ExceptionTestCase.
*
* @since			1.1
* @param[in]	TestFixtureClassName The test fixture type
* @param[in]	TestCaseName	The name of test case and the method name of %TestFixture that is called for testing
* @param[in]	ExceptionType	The exception type
* @hideinitializer
*/
#define NEW_EXCEPTION_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName, ExceptionType)				\
					new Osp::Test::ExceptionTestCase<ExceptionType>(*NEW_SIMPLE_TEST_WITH_FIXTURE(TestFixtureClassName, TestCaseName), #ExceptionType,   __FILE__, __LINE__)


#define __DEFINE_TESTSUITE(TestSuiteClassName)														\
class __AutoTestRegistry_##TestSuiteClassName															\
{																										\
public:																									\
    __AutoTestRegistry_##TestSuiteClassName()															\
    {																									\
		Osp::Test::TestRegistry::Instance()->AddTestSuiteFactory(new Osp::Test::TestSuiteFactory<TestSuiteClassName>());	\
    }																									\
};																										\

/**
* @def REGISTER_TESTSUITE(TestSuiteClassName)
* Registers the test suite into TestRegistry.
*
* @since			1.1
* @param[in]	TestSuiteClassName The name of test suite @n
*							The name is usually equal to the name of test fixture.
* @hideinitializer
*/
#define REGISTER_TESTSUITE(TestSuiteClassName)														\
    __DEFINE_TESTSUITE(TestSuiteClassName);														\
    static __AutoTestRegistry_##TestSuiteClassName _autoregister_##TestSuiteClassName;



#define NEW_SIMPLE_TEST(TestCaseName)                                                     			\
			new Osp::Test::SimpleTestCase<TestSuiteType>(#TestCaseName, &TestSuiteType::TestCaseName,  __FILE__, __LINE__)



#define NEW_STRESS_TEST(TestCaseName, RepeatedCount)                                          			\
            new Osp::Test::StressTestCase(*NEW_SIMPLE_TEST(TestCaseName), RepeatedCount,  __FILE__, __LINE__)

#define NEW_EXCEPTION_TEST(TestCaseName, ExceptionType)                                  			\
            new Osp::Test::ExceptionTestCase<ExceptionType>(*NEW_SIMPLE_TEST(TestCaseName), #ExceptionType,  __FILE__, __LINE__)


/**
* @def TESTSUITE_BEGIN(TestSuiteClassName)
* Declares the start of defining a test suite. The name of test suite should be the name of test fixture.
*
* @since			1.1
* @param[in]	TestSuiteClassName The name of test suite @n
*							The name of test fixture and test suite must be equal.
* @hideinitializer
*/
#define TESTSUITE_BEGIN(TestSuiteClassName)                                                    		\
    public:                                                                                         	\
       typedef TestSuiteClassName TestSuiteType;                                                     	\
																										\
       virtual Osp::Base::String GetClassName(void) const {													\
           static Osp::Base::String testFixtureName(#TestSuiteClassName);								\
           return testFixtureName;																		\
       }																								\
																										\
       static Osp::Test::TestSuite* Suite() {                                                        		\
    	   Osp::Test::TestSuite *testSuite = new Osp::Test::TestSuite(#TestSuiteClassName);					\

/**
* @def SIMPLE_TEST(TestCaseName)
* Creates and registers an instance of SimpleTestCase into the specified TestSuite.
*
* @since			1.1
* @param[in]	TestCaseName The name of test case @n
*							The name is one of the methods in TestFixture.
* @hideinitializer
*/
#define SIMPLE_TEST(TestCaseName)                                                      		\
            testSuite->AddTestCase(*NEW_SIMPLE_TEST(TestCaseName));

/**
* @def STRESS_TEST(TestCaseName, RepeatedCount)
* Creates and registers an instance of StressTestCase into the specified TestSuite.
*
* @since			1.1
* @param[in]	TestCaseName	The name of test case @n
*							The name is one of the methods in TestFixture.
* @param[in]	RepeatedCount	The count to be repeated to invoke the method whose name is TestCaseName
* @hideinitializer
*/
#define STRESS_TEST(TestCaseName, RepeatedCount)                                            		\
            testSuite->AddTestCase(*NEW_STRESS_TEST(TestCaseName, RepeatedCount));

/**
* @def EXCEPTION_TEST(TestCaseName, ExceptionType)
* Creates and registers an instance of ExceptionTestCase into the specified TestSuite.
*
* @since			1.1
* @param[in]	TestCaseName	The name of test case @n
*							The name is one of the methods in TestFixture.
* @param[in]	ExceptionType	The exception type
* @hideinitializer
*/
#define EXCEPTION_TEST(TestCaseName, ExceptionType)                                     		\
            testSuite->AddTestCase(*NEW_EXCEPTION_TEST(TestCaseName, ExceptionType));

/**
* @def TESTSUITE_END()
* Declares the end of defining a test suite.
*
* @since			1.1
* @hideinitializer
*/
#define TESTSUITE_END()                                                                       		\
            return testSuite;                                                                      		\
        }


#endif /* _FTEST_MACRO_HELPER__H_ */

/** 
*
@} */
