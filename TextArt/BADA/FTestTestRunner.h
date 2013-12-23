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
 * @file		FTestTestRunner.h
 * @brief		This is the header file for the %TestRunner class.
 *
 * This header file contains the declarations of the %TestRunner class. 
 */
#ifndef _FTEST_TEST_RUNNER_H_
#define _FTEST_TEST_RUNNER_H_

#include <FBaseRtThreadThread.h>
#include "FTestTestObject.h"
#include "FTestTestResult.h"
#include "FTestITestListener.h"
#include "FTestILogWriter.h"


namespace Osp { namespace Test {

class TestCase;
class TestSuite;
class ILogWriter;

/**
* @enum TestRunnerType
* Defines the type of %TestRunner.
*
* @since			1.0
*/
enum TestRunnerType
{
	RUNNER_DEFAULT = 0 , /**<The normal type recommended to use manually*/
	RUNNER_IDE_WIZARD,   /**<The type usually used in IDE Wizard @n Use only single instance in your test project.*/
};


/**
 * @class		TestRunner
 * @brief		This class is the base class to run TestSuites in this TestFramework.
 * @since		1.1
 *
 * The %TestRunner class is the base class to run test suites in the test framework. 
 * You can run the TestSuite and TestCase instances using the Execute() method. If you want to run all the TestSuites which you have defined, use this class.
 *
 * For more information on the class features, see <a href="../com.osp.documentation.help/html/dev_env/creating_running_testsuite_testrunner.htm">Creating and Running Test Suites with a Test Runner</a>.
 *
 *
 * 
 *
 */
class TestRunner : public Osp::Base::Runtime::Thread
{
public:
	/**
	 * Initializes this instance of %TestRunner with the specified parameters.
	 *
	 * @since			1.1
	 * @param[in]	runnerName		The runner name
	 * @param[in]	runnerType		The test runner type
	 * @remarks 		Use RUNNER_DEFAULT type if you create an instance of %TestRunner manually.
	 */
	TestRunner(const Osp::Base::String& runnerName, TestRunnerType runnerType = RUNNER_DEFAULT);

	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.1
	 */
	virtual ~TestRunner(void);

	/**
	 * Adds an instance of ITestListener.
	 *
	 * @since			1.1
	 * @param[in]	testListener	An instance of %ITestListener
   * @remarks		An instance of %ITestListener must not be a local variable, because %TestRunner runs as an event-driven thread.
	 */
	void AddTestListener(const ITestListener& testListener);

	/**
	 * Removes an added instance of ITestListener.
	 *
	 * @since			1.1
	 * @param[in]	testListener	An instance of %ITestListener
	 */
	void RemoveTestListener(const ITestListener& testListener);

	/**
	 * Adds an instance of TestSuite to this %TestRunner.
	 *
	 * @since			1.1
	 * @param[in]	testSuite		An instance of %TestSuite
	 * @remarks    Do not use an instance of %TestSuite that is a local variable.
	 *            The instance of the added %TestSuite will be destroyed by this %TestRunner.
	 */
	void AddTestSuite(const TestSuite& testSuite);


	/**
	 * Adds a test list that has the instances of TestSuite.
	 *
	 * @since			1.1
	 * @param[in]	testSuiteList	The list of instances of %TestSuite
	 * @remarks    Do not use @c testSuiteList that are local variables. @n
	 *            The instances of %TestSuite that are added into @c testSuiteList will be destroyed by this %TestRunner.
	 */
	void AddTestSuites(const Osp::Base::Collection::IListT<TestSuite*>& testSuiteList) ;

	/**
	 * @internal
	 * Adds an instance of TestCase to this TestRunner.
	 *
	 * @since			1.1
	 * @remarks    Do not use a instance of TestCase that is local variable. @n
	 * 						The instance of added TestCase will be destroyed by This TestRunner.
	 *
	 * @param[in]	testCase		An instance of TestCase
	 */
	void AddTest(const TestCase& testCase);

	/**
	 * @internal
	 * Prints out information of test suites in this TestRunner.
	 *
	 * @since			1.1
	 * @param[in]	writer			The log writer
	 */
	 void PrintTestInfo(ILogWriter& writer);

	/**
	 * Returns the name of this %TestRunner.
	 *
	 * @since			1.1
	 * @return		The name of this %TestRunner
	 */
	virtual Osp::Base::String GetName(void) const;

	/**
	 * Returns a pointer to TestResult that %TestRunner used to test.
	 *
	 * @since			1.1
	 * @return		A pointer to the %TestResult instance
	 */
	virtual TestResult* GetTestResult(void) const;

	/**
	 * Starts a thread for %TestRunner and executes the test suites which this %TestRunner has. @n
	 * Currently, %TestRunner does not support Pause() and Resume() methods.
	 * Therefore, you can only use Start() and Stop() methods for testing.
	 *
	 * @since						1.1
	 * @param [in,out]	pTestResult		An instance of TestResult to store the result of test
	 * @return					An error code
	 * @exception				E_SUCCESS 			The method is successful.
	 * @exception				E_INVALID_STATE	 	The thread of test runner is in an invalid state, or the test runner has already started.
	 * @remarks					An instance of %TestResult must not be a local variable because %TestRunner is running as an event-driven thread after calling this method.
	 */
	virtual result Start(TestResult* pTestResult);

	/**
	 * Forces the thread and the testing to stop executing.
	 *
	 * @since			1.1
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_INVALID_STATE			The thread is in an invalid state.
	 * @exception	E_SYSTEM			    A system error has occurred.
	 */
	virtual result	Stop(void);

	/**
	* @internal
	* This method is called when Start method is called and Thread is started.
	*
	* @since			1.1
	*/
	bool OnStart(void);
	/**
	* @internal
	* This method is called when Stop method is called and Thread is stopped.
	* @since			1.1
	*/
	void OnStop(void);	

	/**
	* @internal
	* Notifies when the user event is sent by calling SendUserEvent(). @n
	* TestRunner is event-driven Thread which uses this method to run TestCases.
	*
	* @since			1.1
	*/
	void OnUserEventReceivedN (RequestId requestId, Osp::Base::Collection::IList *pArgs);


private:
	/**
	 * @internal
	 * runs a next TestCase. if there is no more TestCase to run, returns false.
	 */
	bool RunNextTestObject(void);

	/**
	 * @internal
	 * User can select some TestCases and TestSuites wanted to run in his test project.
	 * This method removes TestCases and TestSuites except that.
	 */
	void Filtering(void);

	/**
	 * @internal
	 * Start the thread to run TestCases
	 */
	result Start (void);

private:
	Osp::Base::String			__runnerName;
	TestSuite*					__pUnknownSuite;
	bool 						__inTesting;
	bool 						__threadStarted;
	bool 						__stopThread;
	bool 						__eventProccessed;
	TestResult*					__pTestResult;
	TestRunnerType				__runnerType;
	ITestListener*				__pInternalListener;
	long						__executionTime;
	
	Osp::Base::Collection::ArrayListT<ITestListener*> 	__testListeners;
	Osp::Base::Collection::ArrayListT<TestSuite*>  	__testSuites;
	Osp::Base::Collection::IEnumeratorT<TestSuite*>*	__pSuiteIndex;
	
	//disable copy and assign
	TestRunner& operator=(const TestRunner& rhs);  
	TestRunner(const TestRunner& rhs); 
};
}}

#endif /* _FTEST_TEST_RUNNER_H_ */
