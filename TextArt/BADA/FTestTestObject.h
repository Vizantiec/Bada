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
 * @file		FTestTestObject.h
 * @brief		This is the header file for the %TestObject class.
 *
 * This header file contains the declarations of the %TestObject class. @n
 * This header file is the default top-level class of a test.
 */
#ifndef _FTEST_TEST_OBJECT_H_
#define _FTEST_TEST_OBJECT_H_

#include <FBase.h>
#include "FTestITestListener.h"

namespace Osp { namespace Test {
class TestResult;

/**
 * @class		TestObject
 * @brief		This class is the base class for all test cases.
 * @since		1.1
 *
 * The %TestObject class is the base class for all test cases in the test framework.
 * To test something, your test case must be a subclass of this class.
 *
 *
 */
class TestObject : public Osp::Base::Object
{
public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.1
	 */
	virtual ~TestObject(void);
	
	/**
	 * Gets the name of the test object. @n
	 * Usually, this method returns the class name if a specific name is not set.
	 *
	 * @since			1.1
	 * @return		The name of the current test object
	 */
	virtual Osp::Base::String GetName(void) const ;

	/**
	 * Adds the test listener.
	 * Using the ITestListener, the running status and the result of the tests are notified.
	 *
	 * @since			1.1
	 * @param[in]	testListener	The test listener
	 */
	void AddTestListener(const ITestListener& testListener);

	/**
	 * Removes the test listener.
	 *
	 * @since			1.1
	 * @param[in]	testListener	The test listener
	 */
	void RemoveTestListener(const ITestListener& testListener);

	/**
	 * Executes the test and gets the result of the test. @n
	 * This method is the executable body of a test.
	 * This method can store the result of the test into @c pTestResult after all the testing is completed.
	 *
	 * @since						1.1
	 * @param [in,out]	pTestResult		An instance of TestResult to store the result of the test
	 * @remarks 					The subclass of TestCase implements this method to start their test.
	 */
	virtual void Execute(TestResult* pTestResult) = 0;

protected:
	/**
	 * Initializes this instance of %TestObject with the specified name. 
	 *
	 * @since			1.1
	 * @param[in]	name			The test object name
	 */
	TestObject(const Osp::Base::String& name);


protected:
    /**
     *@internal
     * This variable is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this variablevariable.
     *
     * @since 1.1 
     */
	Osp::Base::String 		__name;
    /**
     *@internal
     * This variable is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this variablevariable.
     *     * @since 1.1 
     */
	Osp::Base::Collection::ArrayListT<ITestListener*> __testListeners;

	// To make noncopyable class.
private:
	TestObject( const TestObject& );
	TestObject& operator=( const TestObject& );
};
}}
#endif /* _FTEST_TEST_OBJECT_H_ */
