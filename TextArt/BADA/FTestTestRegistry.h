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
 * @file		FTestTestRegistry.h
 * @brief		This is the header file for the %TestRegistry class.
 *
 * This header file contains the declarations of the %TestRegistry class. @n
 * It adds a test to the test registry.
 */
#ifndef _FTEST_TEST_REGISTRY_H_
#define _FTEST_TEST_REGISTRY_H_

#include <FBase.h>
#include <FBaseObject.h>
#include <FBaseColIListT.h> 

#include "FTestTestSuite.h"
#include "FTestTestCase.h"

namespace Osp { namespace Test {

/**@internal This is not intended for public use.
*
* @since		1.0
*/
class TestSuiteFactoryBase : public Osp::Base::Object
{
public:
  /**
   * @since			1.1
	 */		
	virtual TestSuite* MakeTestSuite(void) = 0;
};

/**@internal This is not intended for public use.
*
* @since		1.0
*/
template<typename TestFixtureType>
class TestSuiteFactory : public TestSuiteFactoryBase
{
public :
  /**
   * @since			1.1
	 */			
	virtual TestSuite* MakeTestSuite(void)
	{
		return TestFixtureType::Suite();
	}
};

/**
 * @class		TestRegistry
 * @brief		This class provides the test suites, which are registered using the REGISTER_TESTSUITE macro.
 * @since		1.1
 *
 * The %TestRegistry class provides the test suites, which are registered using the <a href="group__GroupTestHelperMacro.html">REGISTER_TESTSUITE macro</a>.
 * If the macro is used in a test code, the suite is registered in the singular instance of %TestRegistry.
 * Therefore, you can use this class to get the test suites.
 *
 * Using the macro, the %TestRegistry class can store the type of the class, which has a static member suite() method that creates a TestSuite and returns a pointer to it.
 * Therefore, when the GetTestSuitesN() method is called, the instances of al test suites are created at that time.
 * 
 * For more information on the class features, see <a href="../com.osp.documentation.help/html/dev_env/testing_registering_test_suites.htm">Registering Test Suites</a>.
 */
class TestRegistry
{
private:
	/**
	 * This is the default constructor for this class.
	 * Using this method is prohibited.
	 */
  /**
   * @since			1.1
	 */		
	TestRegistry(void) {

	}

	/**
	 *	This is the copy constructor for the %TestRegistry class.
	 *	Using this method is prohibited.
	 *
	 *	@param[in]	testRegistry	An instance of TestRegistry
	 */
	TestRegistry(const TestRegistry &testRegistry) {

	}

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.1
	 */
	~TestRegistry(void) {

	}

	/** @internal
	 * Adds a TestSuiteFactoryBase having a type of class which has a static method Suite() to create TestSuite.
	 * REGISTER_TESTSUITE uses this method.
	 *
	 * @since			1.1
	 * @param[in]	base				The TestSuiteFactoryBase
	 */
	void AddTestSuiteFactory(TestSuiteFactoryBase* base);

	/**
	 * Creates and returns the test suites that are registered.
	 *
	 * @since			1.1
	 * @return 		The list of the registered test suite
	 */
	Osp::Base::Collection::IListT<TestSuite*>*  GetTestSuitesN(void);
	
	/**
	 * Returns the instance of this class.
	 *
	 * @since			1.1
	 * @return 		An instance of %TestRegistry
	 */
	static TestRegistry* Instance(void);

private:
  /**
   * @since			1.1
	 */		
	Osp::Base::Collection::ArrayList __testSuiteFactoryList;
};

}}
#endif /* _FTEST_TEST_REGISTRY_H_ */
