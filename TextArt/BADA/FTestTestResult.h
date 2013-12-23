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
 * @file		FTestTestResult.h
 * @brief		This is the header file for the %TestResult class.
 *
 * This header file contains the declarations of the %TestResult class. @n
 * This header file records the test results.
 */
#ifndef _FTEST_TEST_RESULT_H_
#define _FTEST_TEST_RESULT_H_

#include <FBase.h>
#include <FIo.h>
#include "FTestBaseException.h"

namespace Osp { namespace Test {

class ILogWriter;
class __TestResultContainer;

/**
* @enum 		TestReportType
* Defines the report type of a test.
*
* @since		1.0
*/
enum TestReportType
{
	TEST_REPORT_TXT = 0, /**<The report type for a plain text */
	TEST_REPORT_XML,	 /**<The report type for an xml document */
};



/**
* @class		TestResult
* @brief		This class provides the test result.
* @since		1.1
*
* The %TestResult class provides the test result. The TestCase, TestSuite, and TestRunner classes uses this class in their execution to store the test results.
* Currently, you can use the CreateTestResultFile() method to create a test result file.
*
* For more information on the class features, see <a href="../com.osp.documentation.help/html/dev_env/testing_using_test_namespace.htm">Testing Applications Using the Test Namespace</a>.
*
* The following example demonstrates how to use the %TestResult class.
*
* @code
*
* 	pTestResult = new TestResult();
*	Sample1::TestBankAccount* testAccount = new Sample1::TestBankAccount();
*	testAccount->Execute(pTestResult);
*	Sample1::TestBankAccount2* testAccount2 = new Sample1::TestBankAccount2();
*	testAccount2->Execute(pTestResult);
*
*	TestSuite suite("BankAccountTest");
*	suite.AddTestCase(*testAccount);
*	suite.AddTestCase(*testAccount2);
*	suite.Execute(pTestResult);
*	pTestResult->CreateTestResultFile(L"/Home/SampleResult.txt", true, Osp::Test::TEST_REPORT_TXT);
*	pTestResult->CreateTestResultFile(L"/Home/SampleResult.xml", true, Osp::Test::TEST_REPORT_XML);
* @endcode
*
* After running the above example, the following files are created in the Home directory:
*
* - SampleResult.txt
*
* @code
* Sample1::TestBankAccount
*	[O] Sample1::TestBankAccount (0ms)
* Sample1::TestBankAccount2
*	[F] Sample1::TestBankAccount2 - The condition(account.GetBalance() != 100) is false
* BankAccountTest
*	[O] Sample1::TestBankAccount (0ms)
*	[F] Sample1::TestBankAccount2 - The condition(account.GetBalance() != 100) is false
* @endcode
*
* - SampleResult.xml
*
* @code
* <?xml version="1.0" encoding="UTF-8" standalone="no"  ?>
* <test version="1.0">
*     <testrun errors="0" failures="2" successes="2" name="OspTest" mode="run" project="UnknownProject" runs="4/4" time="0" type="simul">
*         <testsuite name="Sample1::TestBankAccount" file="" raisedException="" testcase="" status="success" time="0">
*             <testcase file="C:/bada/1.1.0/IDE/workspace/BankAppTest/BankAccountTest.h" line="" name="Sample1::TestBankAccount" status="success" time="0"></testcase>
*         </testsuite>
*         <testsuite name="Sample1::TestBankAccount2" file="" raisedException="" testcase="" status="fail" time="0">
*             <testcase file="C:/bada/1.1.0/IDE/workspace/BankAppTest/BankAccountTest.h" line="178" name="Sample1::TestBankAccount2" status="fail" time="0">
*                 <fail file="../src/BankAccountTest.cpp" line="42" name="Sample1::TestBankAccount2" status="fail" time="0"><![CDATA[The condition(account.GetBalance() != 100) is false]]></fail>
*             </testcase>
*         </testsuite>
*         <testsuite name="BankAccountTest" file="" raisedException="" testcase="" status="fail" time="0">
*             <testcase file="C:/bada/1.1.0/IDE/workspace/BankAppTest/BankAccountTest.h" line="" name="Sample1::TestBankAccount" status="success" time="0"></testcase>
*             <testcase file="C:/bada/1.1.0/IDE/workspace/BankAppTest/BankAccountTest.h" line="178" name="Sample1::TestBankAccount2" status="fail" time="0">
*                     <fail file="../src/BankAccountTest.cpp" line="42" name="Sample1::TestBankAccount2" status="fail" time="0"><![CDATA[The condition(account.GetBalance() != 100) is false]]></fail>
*             </testcase>
*         </testsuite>
*     </testrun>
* </test>
* @endcode
*/
class TestResult
{
public:
	/**
	* This is the default constructor for this class.
	*
	* @since		1.1
	*/
	TestResult(void);

	/**
	* This is the destructor for this class.
	*
	* @since		1.1
	*/
	virtual ~TestResult(void);

	/** @internal
	* Sets project name.
	* If you create your test result in xml format using CreateTestResultFile, the project name will be a value of 'project' attribute of '/test/testrun/' element.
	*
	* @since			1.1
	* @param[in]	projectName		The project name for a xml report file
	*/
	void SetProjectName(const Osp::Base::String& projectName=L"UNDEFINED_PROJECT_NAME");


	/**@internal
	* Prints out information of test result.
	*
	* @since			1.1
	* @param[in]	writer			The log writer
	*/
	void PrintInfo(ILogWriter& writer);

	/**
	* Creates a file and writes %TestResult into the file.
	* 
	* @since			1.1
	* @privlevel	NORMAL
	* @privgroup	LOCAL_CONTENT	
	*
	* @param[in]   filePath 	 	  The path of the destination file to write
	* @param[in]   overwrite 		  Set to @c true to overwrite the file if it already exists, @n
	*						          else @c false
	* @param[in]   reportType	   	  The test report type
	* @exception   E_SUCCESS		  The method is successful.
	* @exception   E_INVALID_STATE    This method is invalid for the current state of this instance.
	* @exception   E_RESOURCE_UNAVAILABLE  The required file path is unavailable.
	* @exception   E_SYSTEM			  A system error has occurred.
	* @exception   E_FILE_ALREADY_EXIST	The specified file already exists and the value of @c overwrite is not @c true.
	* @exception   E_STORAGE_FULL  	  The storage is full.
	* @exception   E_OUT_OF_MEMORY    The memory is insufficient.
	* @exception   PRIVILEGE_DENIED   The application does not have the privilege to call this method.
	* @remarks The path of the content file should start with '/Home/' or '/Media/Others/'. In the case of '/Media/Others/', the LOCAL_CONTENT privilege is needed.
	* @remarks In the report file as TEST_REPORT_TXT, the prefix string [F] means a failure, [E] means an error, [O] means a success, [X] means a not run.
	*
	*/
	result CreateTestResultFile(const Osp::Base::String& filePath, bool overwrite, TestReportType reportType=TEST_REPORT_TXT);

	/**
	* Gets the number of successes in this %TestResult.
	*
	* @since		1.1
	* @return		The number of successes
	*/
	int GetNumberOfSuccesses(void) const;

	/**
	* Gets the number of failures in this %TestResult.
	*
	* @since		1.1
	* @return		The number of failures
	*/	
	int GetNumberOfFailures(void) const;

	/**
	* Gets the number of errors in this %TestResult.
	*
	* @since		1.1
	* @return		The number of errors
	*/
	int GetNumberOfErrors(void) const;

	/**
	* Gets the number of test cases that are executed in this %TestResult.
	*
	* @since		1.1
	* @return		The number of tests that are executed
	*/
	int GetNumberOfRuns(void) const;


	/**
	* Gets the total number of test cases in this %TestResult.
	*
	* @since		1.1
	* @return		The total number of test cases
	*/
	int GetTotalNumberOfTestCases(void) const;

	/**
	* Gets the failure and error data of the test in this %TestResult.
	*
	* @since	1.1
	* @return	A pointer to ArrayList that contains the string objects for each failure and error @n
	*			The format of the string object consists of the test result and the name of the test suite, the name of test case, and the message of error or failure. @n
	*			For example, if a failure occurs in TestDeposit() method, the value of the string will be L"[F]BankAccountTest::TestDeposit-The balance of the account is not 100." @n
	*			If an error occurs in %TestDeposit() method, the value of string will be L"[E]BankAccountTest::TestDeposit-An unwanted exception is thrown!"
	*/
	Osp::Base::Collection::IList* GetFailureDataN(void) const;

	/**  @internal
	*
	*
	* @since	1.1
	*/
	void AddNumberOfTestCases(int tcCount);

protected:



	/** @internal
	* Sets current test suite name.
	*
	* @since			1.1
	* @param[in]	suiteName		The current suite name
	*/
	void SetCurrentTestSuiteName(const Osp::Base::String& suiteName=L"UnknownSuite");
	
	/** @internal
	* Sets current test suite name.
	*
	* @since			1.1
	* @param[in]	testCaseId		The unique id of TestCase
	* @param[in]	testCaseName	The case name
	* @param[in]	filePath		The file path to the file that creates TestCase
	* @param[in]	lineNum			The line number in the file that creates TestCase
	*/
	void SetCurrrentTestCase(int testCaseId, const Osp::Base::String& testCaseName, const Osp::Base::String& filePath, int lineNum);
	
	/** @internal
	* Called to add a test success to this class
	*
	* @since			1.1
	* @param[in]	testCaseId		The unique id of TestCase
	* @param[in]	testCaseName	The case name
	* @param[in]	executionTime	The time spent in testing
	* @param[in]	filePath		The file path to the file that creates TestCase
	* @param[in]	lineNum			The line number in the file that creates TestCase
	*/
	void AddSuccess(int testCaseId, const Osp::Base::String& testCaseName, long executionTime, const Osp::Base::String& filePath, int lineNum);

	/** @internal
	* Called to add a test failure to this class
	*
	* @since			1.1
	* @param[in]	testCaseId		The unique id of TestCase
	* @param[in]	testCaseName	The case name
	* @param[in]	executionTime	The time spent in testing
	* @param[in]	message			The message of an assertion
	* @param[in]	filePath		The file path to the file makes an assertion
	* @param[in]	lineNum			The line number in the file that makes an assertion
	*/
	void AddFailure(int testCaseId, const Osp::Base::String&  testCaseName, long executionTime, const Osp::Base::String&  message, const Osp::Base::String& filePath, int lineNum);

	/** @internal
	* Called to add a test error to this class
	*
	* @since			1.1
	* @param[in]	testCaseId		The unique id of TestCase
	* @param[in]	testCaseName	The case name
	* @param[in]	executionTime	The time spent in testing
	* @param[in]	message			The message of an assertion
	* @param[in]	filePath		The file path to the file that makes an error
	* @param[in]	lineNum			The line number in the file that makes an error
	*/
	void AddError(int testCaseId, const Osp::Base::String&  testCaseName, long executionTime, const Osp::Base::String&  message, const Osp::Base::String& filePath, int lineNum);

	/** @internal
	* Called to add a test error to this class
	*
	* @since			1.1
	* @param[in]	testCaseId		The unique id of TestCase
	* @param[in]	testCaseName	The case name
	* @param[in]	message			The message of an assertion
	* @param[in]	filePath		The file path to the file that makes an error
	* @param[in]	lineNum			The line number in the file that makes an error
	*/
	void AddNotRun(int testCaseId, const Osp::Base::String&  testCaseName, const Osp::Base::String&  message, const Osp::Base::String& filePath, int lineNum);

	/** @internal
	* Called to add a testfixture error to this class
	* if an error occurred in SetUpBeforeTestSuite or TearDownAfterTestSuite of TestFixture, this method is called. 
	*
	* @since			1.1
	* @param[in]	testfixtureId		The unique id of TestFixture
	* @param[in]	testFixtureName		The case name
	* @param[in]	executionTime		The time spent in testing
	* @param[in]	message				The message of an assertion
	* @param[in]	filePath			The path to the file that makes an error
	* @param[in]	lineNum				The line number in the file that makes an error
	*/
	void AddTestFixtureError(int testCaseId, const Osp::Base::String&  testFixtureName, long executionTime, const Osp::Base::String&  message, const Osp::Base::String& filePath, int lineNum);

private:
	result WriteTextDataIntoFile(Osp::Io::File& file);
	result WriteXMLDataIntoFile(Osp::Io::File& file);

private:

	Osp::Base::String		__projectName;
	Osp::Base::String		__currentTestSuiteName;
	int						__currentTestCaseId;
	int						__runCount;
	int						__totalCount;
	int						__failCount;
	long 					__executionTimes;
	Osp::Base::Collection::ArrayListT<__TestResultContainer*> 		__testCaseIndex;
	Osp::Base::Collection::ArrayListT<__TestResultContainer*> 		__testCaseSuccess;
	Osp::Base::Collection::ArrayListT<__TestResultContainer*> 		__testCaseFail;
	Osp::Base::Collection::ArrayListT<__TestResultContainer*> 		__testCaseError;
	__TestResultContainer*	__pCurrentTestCaseResult;
	friend class TestCase;
	friend class TestSuite;
	friend class __TestContainer;
};
}}
#endif /* _FTEST_TEST_RESULT_H_ */
