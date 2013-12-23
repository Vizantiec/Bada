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
 * @file		FTestExceptionTestCase.h
 * @brief		This is the header file for the %ExceptionTestCase class.
 *
 *  This header file contains the declarations of the %ExceptionTestCase class.
 */
#ifndef _FTEST_EXCEPTION_TEST_CASE_H_
#define _FTEST_EXCEPTION_TEST_CASE_H_

#include <FBaseString.h> 
#include "FTestUnknownException.h"
#include "FTestTestCase.h"

namespace Osp { namespace Test {

class TestResult;

/**
 * @class		ExceptionTestCase
 * @brief		This class implements a exception testcase.
 * @since		1.1
 *
 * The %ExceptionTestCase class implements an exception test case. An exception test case is used to check if the specific exception would be thrown when running a test.
 *
 * For more information on the class features, see <a href="../com.osp.documentation.help/html/dev_env/testing_using_test_namespace.htm">Testing Applications Using the Test Namespace</a>.
 * 
 * Note that instead of this class, you can also use the <a href="group__GroupTestHelperMacro.html">helper</a> and <a href="group__GroupTestAssertionMacro.html">assert</a> macros, 
 * such as EXCEPTION_TEST()  and TestAssertThrow().
 *
 * The following example demonstrates how to use the %ExceptionTestCase class
 *
 * @code
 *
 * class TestBankAccount: public Osp::Test::TestFixture{
 *	public:
 *		void SetUpBeforeTestSuite() {}
 *		void TearDownAfterTestSuite() {}
 *		void SetUp() {pAccount = new BankAccount();}
 *		void TearDown() {delete pAccount;}
 *
 *		void TestDepositException() { pAccount->Deposit(-1);}
 * };
 * ...
 * TestCase* testcase = new ExceptionTestCase<InvalidInputException> (new SimpleTestCase<TestBankAccount>("TestDepositException", &TestBankAccount::TestDepositException), "InvalidInputException");
 * testcase->Execute(&testResult);
 * ...
 * @endcode
 *
 * The following example demonstrates how to <a href="../com.osp.documentation.help/html/dev_env/test_macros.htm">use the helper macros</a> instead.
 *
 * The following code snippet illustrates the use of Helper Macro.
 * @code
 * TestCase* testcase = NEW_EXCEPTION_TEST_WITH_FIXTURE(TestBankAccount, TestDeposit, InvalidInputException);
 * testcase->Execute(&testResult);
 * @endcode
 *
 * Also you can use EXCEPTION_TEST Macro in the block which is generated by the bada %Test Case Wizard. @n
 *
 * @code
 *  class TestBankAccount: public Osp::Test::TestFixture{
 *	TESTSUITE_BEGIN(TestBankAccount)
 *	EXCEPTION_TEST(TestDepositException, InvalidInputException)
 *	TESTSUITE_END()
 *    ...
 * @endcode
 */
template<class ExceptionType>
class ExceptionTestCase : public TestCase
{
public:
	/**
	 * Initializes this instance of TestCase with the expected exception.
	 *
	 * @since			1.1
	 * @param[in]	testCase			The test case that throws an exception
	 * @param[in]	exceptionName	The name of the exception to be thrown
	 * @param[in]	filePath			The file path to the file that creates the instance of %TestCase
	 * @param[in]	lineNum			The line number in the file that creates the instance of %TestCase
	 */
	ExceptionTestCase(const TestCase& testCase, const Osp::Base::String& exceptionName, const Osp::Base::String& filePath=__FILE__, int lineNum=__LINE__)
	: TestCase(testCase.GetName(), filePath, lineNum), __pTestCase((TestCase*)&testCase), __exceptionName(exceptionName)
	{

	}

	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.1
	 */
	virtual ~ExceptionTestCase(void)
	{
		if (__pTestCase != null)
		{
			delete __pTestCase;
			__pTestCase = null;
		}
	}

	/** @internal
	 * Gets the TestFixture to be used in this class.
	 *
	 * @since			1.1
	 * @return		the pointer on TestFixture
	 */
	 virtual TestFixture* GetTestFixture(void)
	{
		return __pTestCase->GetTestFixture();
	}


private:
	virtual void Run(void)
    {
    	if (__pTestCase == null)
    	{
    		Assert::PushTestResult(Assert::ERROR, L"Test Case was not found!", this->__filePath, this->__lineNum);
    		throw UnknownException(L"Test Case was not found!", this->__filePath, this->__lineNum);
    	}

        try {
        	__pTestCase->Run();
        }
        catch (ExceptionType &e) {
            if (typeid(e) != typeid(ExceptionType)) {
            	Osp::Base::String message = L"Thrown Exception is not ";
				message.Append(__exceptionName);

				Assert::PushTestResult(Assert::FAIL, L"An unwanted exception is thrown.", this->__filePath, this->__lineNum);
				throw BaseException(message,this->__filePath, this->__lineNum);
            }
            return;
        }
		catch (...)
		{
			Osp::Base::String message = L"Thrown Exception is not ";
			message.Append(__exceptionName);

			Assert::PushTestResult(Assert::FAIL, L"An unwanted exception is thrown.", this->__filePath, this->__lineNum);
			throw BaseException(message,this->__filePath, this->__lineNum);
		}	

		Assert::PushTestResult(Assert::FAIL, L"Exception is not thrown!", this->__filePath, this->__lineNum);
        throw UnknownException(L"Exception is not thrown!", this->__filePath, this->__lineNum);
    }

private:
	TestCase* __pTestCase;	
	Osp::Base::String __exceptionName;
};

}}
#endif /* _FTEST_EXCEPTION_TEST_CASE_H_ */