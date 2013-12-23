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
 * @file		FTestTestCase.h
 * @brief		This is the header file for the %TestCase class.
 *
 * This header file contains the declarations of the %TestCase class.
 */
#ifndef _FTEST_TEST_CASE_H_
#define _FTEST_TEST_CASE_H_

#include <FBase.h>
#include "FTestTestObject.h"

namespace Osp { namespace Test {

class TestFixture;
class TestSuite;
class TestResult;

/**
 * @class		TestCase
 * @brief		This class implements a test case.
 * @since		1.1
 *
 * The %TestCase class implements a test case, which is a basic element of test in the testing framework.
 *
 * For more information on the class features, see <a href="../com.osp.documentation.help/html/dev_env/testing_creating_running_test_case.htm">Creating and Running a Test Case</a>.
 *
 * The following example demonstrates how to use the %TestCase class.
 *
 * @code
 * class BankAccount {
 * 	public :
 * 		BankAccount():__balance(0) {}
 * 		void Deposit(int money)	{
 *  		if( money < 0)
 *  			throw std::exception();
 * 			__balance += money;
 * 		}
 *
 * 		int GetBalance() {
 * 			return __balance;
 * 		}
 * 	private :
 * 		int __balance;
 * };
 *
 * class TestBankAccount : public Osp::Test::TestCase{
 * 	public:
 * 		void Run() {
 * 			BankAccount account;
 * 			account.Deposit(100);
 * 			TestAssert (account.GetBalance() == 100);
 * 		}
 * };
 *
 * void Run_TestCase()
 * {
 * 	Osp::Test::TestResult result;
 * 	TestBankAccount testAccount;
 * 	testAccount.Execute(&result);
 * }
 * @endcode
 *
 * @n
 */
class TestCase : public TestObject
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.1
	 */
	virtual ~TestCase(void) {

	}

	/**
	 * Executes this instance of %TestCase and gets the result of the test. @n
	 * This method is the executable body of a test case.
	 * This method can store the execution result of the %TestCase class in @c pTestResult after this method is called.
	 *
	 * @since						1.1
	 * @param [in,out]	pTestResult		An instance of TestResult to store the result of the test @n
	 *									The result of the test.
	 */
	virtual void Execute(TestResult* pTestResult);

	/**
 	 * @internal
 	 *
	 * Executes this test case. @n
	 * This method is usually used by TestFramework. @n
	 * User is not recommended this method because this method will be deprecated.
	 *
	 * @since						1.1
	 * @param [in,out]	pTestResult		An instance of TestResult to be stored the result of test
	 * @param [in]			index			The index of TestCase
	 */
	virtual void Execute(TestResult* pTestResult, int index);

public:
	/** @internal
	 * Returns the test fixture related TestCase.
	 *
	 * @since		1.1
	 * @return	A pointer to the TestFixture instance
	 * @c null, if TestCase does not use TestFixture.
	 */
	virtual TestFixture* GetTestFixture(void) {
	   	return null;
	}

	/**
	 * Returns the path of the file where this test case is created.
	 *
	 * @since			1.1
	 * @return		The path of the file that creates this test case
	 */
	Osp::Base::String  GetFilePath(void) const
	{
		return __filePath;
	}

	/**
	 * Returns the line number in the file where this test case is created.
	 *
	 * @since			1.1
	 * @return		The line number in the file that creates this test case
	 */
	int GetLineNum(void) const
	{
		return __lineNum;
	}


	/**
	 * This method is the executable body of the test case and can be called by the Execute() method. @n
	 * Assert macros can be used to check whether some codes to be tested works correctly in this method.
	 *
	 * @since		1.1
	 */
	virtual void Run(void) = 0;


	/**
	* @internal
	* Returns the time during which TestCase is executing.
	*
	* @since	1.1
	* @return	the time during which TestCase is executing. @n if failure or error occurs, the value is 0 
	*/
	long GetExecutionTime() const;
protected:
	/**
	 * Initializes this instance of %TestCase with the test information. @n
	 * The FileInfo is stored where the instance of %TestCase is created.
	 * It is used to make a test result.
	 *
	 * @since			1.1
	 * @param[in]	caseName		The case name
	 * @param[in]	filePath		The file's path that creates this test case
	 * @param[in]	lineNum			The line number in the file that creates this test case
	 */
	TestCase(const Osp::Base::String& caseName, const Osp::Base::String& filePath=__FILE__, int lineNum=__LINE__);


	/**
	 * This is the default constructor for this class. @n
	 * The FileInfo is stored where the instance of %TestCase is created.
	 * It is used to make a test result.
	 *
	 * @since			1.1
	 * @param[in]	filePath		The file's path that creates this test case
	 * @param[in]	lineNum			The line number in the file that creates this test case
	 */
	TestCase(const Osp::Base::String& filePath=__FILE__, int lineNum=__LINE__);

private:
	void AddTestResult(TestResult* pTestResult, const Osp::Base::String& testCaseName, int assertType, const Osp::Base::String& message, long executionTime, const Osp::Base::String& filePath, int lineNum);
	void SendEventToListener(Osp::Base::Collection::IListT<ITestListener*>* pTestListners, int assertType, TestCase* testCase, int index, const Osp::Base::String& message, long executionTime, const Osp::Base::String& filePath, int lineNum);
		
protected:
    /** 
     *@internal
     * This variable is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this variablevariable.
     *
     * @since 1.1 
     */
	Osp::Base::String __filePath;		
    /** 
     *@internal
     * This variable is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this variablevariable.
     *
     * @since 1.1 
     */
	int __lineNum;
    /** 
     *@internal
     * This variable is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this variablevariable.
     *
     * @since 1.1 
     */
	long __executionTime;

};

}}
#endif /* _FTEST_TEST_CASE_H_ */
