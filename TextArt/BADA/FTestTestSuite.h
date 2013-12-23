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
 * @file		FTestTestSuite.h
 * @brief		This is the header file for the %TestSuite class.
 *
 * This header file contains the declarations of the %TestSuite class.
 * This header file runs a collection of test cases.
 */
#ifndef _FTEST_TEST_SUITE_H_
#define _FTEST_TEST_SUITE_H_

#include <FBase.h> 
#include "FTestTestObject.h"

namespace Osp { namespace Test {

class TestFixture;
class TestCase;
class ITestListener;
class TestResult;
class ILogWriter;
class __TestContainer;


/**
 * @class		TestSuite
 * @brief		This class provides a test suite, which is a collection of test cases.
 * @since		1.1
 *
 *  The %TestSuite class provides a test suite, which is a collection of test cases.
 *
 * For more information on the class features, see <a href="../com.osp.documentation.help/html/dev_env/testing_using_test_namespace.htm">Testing Applications Using the Test Namespace</a>.
 *
 * TIP: You can also create a text suite using the <a href="../com.osp.documentation.help/html/dev_env/testing_using_wizard.htm">Test Case Wizard</a> in the bada IDE. 
 * The wizard can generate the following code, which contains a static Osp::Test::TestSuite* suite() method that you can use to create the text suite.
 *
 * @code
 * class TestBankAccount: public Osp::Test::TestFixture{
 * 	TESTSUITE_BEGIN(TestBankAccount)
 *	SIMPLE_TEST(TestDeposit)
 *	SIMPLE_TEST(TestGetBalance)
 *	TESTSUITE_END()
 *  ...
 * };
 * ...
 * TestSuite* suite = TestBankAccount::suite();
 * suite->Execute(null);
 * ...
 * @endcode
 *
 * The following example demonstrates how to use the %TestSuite class.
 *
 * @code
 *
 *	TestSuite* suite = new TestSuite("TestSuiteSample");
 *
 *	suite->AddTestCase(*NEW_SIMPLE_TEST_WITH_FIXTURE(TestBankAccount, TestDeposit));
 *	suite->AddTestCase(*NEW_STRESS_TEST_WITH_FIXTURE(TestBankAccount, TestStressDeposit, 10));
 *	suite->AddTestCase(*NEW_EXCEPTION_TEST_WITH_FIXTURE(TestBankAccount, TestExceptionDeposit, std::exception));
 *
 *	suite->Execute(&result);
 *
 * @endcode
 *
 */
class TestSuite : public TestObject {

public:
	/**
	 * Initializes this instance of %TestSuite with the specified parameter.
	 *
	 * @since				1.1
	 * @param [in]	suiteName		The name of %TestSuite
	 */
	TestSuite(const Osp::Base::String& suiteName);

	/**
	 * This is the destructor for this class. @n
	 * The instances of TestCase in this suite are destroyed together.
	 *
	 * @since				1.1
	 */
	virtual ~TestSuite(void);

public:
	/**
	 * Adds a test case to this test suite.
	 *
	 * @since				1.1
	 * @param [in]	testCase		A test case to add
	 * @remarks			Do not use an instance of TestCase as a local variable.
	 *         		  The instance of the added %TestCase will be destroyed by this %TestSuite.
	 */
	void AddTestCase(const TestCase& testCase);

	/**
	 * Gets the count of test cases.
	 *
	 * @since				1.1
	 * @return			The count of test cases
	 */
	int GetTestCaseCount(void) const;

	/**
	 *@internal
	 * Prints out information of this test suite that includes testcase's information which are added.
	 *
	 * @since				1.1
	 * @param [in]	writer			The log writer
	 */
	void PrintTestInfo(ILogWriter& writer);

	/**
	 * Executes an instance of %TestSuite and gets the result of the test. @n
	 * This method is the executable body of a test suite.
	 * This method can store the execution result of the %TestSuite into @c pTestResult after this method is called.
	 *
	 * @since						1.1
	 * @param [in,out]	pTestResult		An instance of TestResult to store the result of the test
	 */
	virtual void Execute(TestResult* pTestResult);


	
	/**
	* @internal
	* Returns the time during which TestCase is executing.
	*
	* @since	1.1
	* @return	the time during which TestCase is executing. @n if failure or error occurs, the value is 0
	*/
	long GetExecutionTime() const;

private:
  /**
   * @since			1.1
	 */			
	void InitiateTestInfo(void);
  /**
   * @since			1.1
	 */		
	void OnTestStarted(TestResult* pTestResult, Osp::Base::Collection::IListT<ITestListener*>& testListeners);
  /**
   * @since			1.1
	 */		
	void OnTestStopped(Osp::Base::Collection::IListT<ITestListener*>& testListeners);
  /**
   * @since			1.1
	 */		
	bool RunNextTestCase(TestResult* pTestResult, Osp::Base::Collection::IListT<ITestListener*>& testListeners);
  /**
   * @since			1.1
	 */		
	bool IsFinished(void);
  /**
   * @since			1.1
	 */		
	bool Filterring(void);
	
private:
	int				  														 __testCaseCount;
	bool																	 __isFinished;
	Osp::Base::Collection::HashMapT<TestFixture*, __TestContainer*>  		__testContainers;
	Osp::Base::Collection::IMapEnumeratorT<TestFixture*, __TestContainer*>*  __pTestContainerIndex;
	__TestContainer*														 __pCurrentContainer;
	long																	 __executionTime;

	friend class TestRunner;

};
}}
#endif /* _FTEST_TEST_SUITE_H_ */
