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
 * @file		FTestTestFixtureFactory.h
 * @brief		This is the header file for the %TestFixtureFactory class.
 *
 * This header file contains the declarations of the %TestFixtureFactory class. @n
 * It adds a text fixture to the text fixture factory.
 */
#ifndef _FTEST_TEST_FIXTURE_FACTORY_H_
#define _FTEST_TEST_FIXTURE_FACTORY_H_


#include <FBase.h>
#include "FTestTestFixture.h"
#include "FTestTestCase.h"

namespace Osp { namespace Test {

class __TestFixtureContainer;
	
/** @internal
* @class		TestFixtureFactory
* @brief		
* @since		1.1
*
*/
class TestFixtureFactory
{
private:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 */
	TestFixtureFactory();

public:
	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	~TestFixtureFactory();

	/**
	 * Returns an instance of %TestFixtureFactory.
	 *
	 * @since			1.0
	 * @return 		An instance of %TestFixtureFactory
	 */
	static TestFixtureFactory* Instance();

	/**
	 * Returns the registered instance of TestFixture.
	 *
	 * @since			1.0
	 * @param[in]	testFixtureName		The name of the test fixture
	 * @return 		An instance of %TestFixture
	 */
	TestFixture* GetTestFixture(const Osp::Base::String& testFixtureName);

	/**
	 * Registers the TestFixture instance.
	 *
	 * @since			1.0
	 * @param[in]	testFixtureName		The name of the test fixture
	 * @param[in]	testFixture			An instance of %TestFixture
	 * @return 		@c true if adding the test case is successful, @n
	 *						else @c false
	 */
	bool AddTestFixture(const Osp::Base::String& testFixtureName, const TestFixture& testFixture);

	/**
	 * Adds a test case in the TestFixture instance.
	 *
	 * @since			1.0
	 * @param[in]	testFixtureName		The name of the test fixture
	 * @param[in]	testCase			An instance of TestCase
	 * @return		@c true if adding the test case is successful, @n
	 *						else @c false
	 */
	bool AddCaseRef(const Osp::Base::String& testFixtureName, const TestCase& testCase);

	/**
	 * Removes the test case from the TestFixture instance.
	 *
	 * @since			1.0
	 * @param[in]	testFixtureName		The name of the test fixture
	 * @param[in]	testCase			An instance of TestCase
	 * @return		@c true if removing the test case is successful, @n
	 *						else @c false
	 */
	bool RemoveCaseRef(const Osp::Base::String& testFixtureName, const TestCase& testCase);

private:
	Osp::Base::Collection::HashMap 	__testFixtureMap;
	static TestFixtureFactory 		__testFixtureFactory;
	
	TestFixtureFactory& operator=(const TestFixtureFactory& rhs);
    TestFixtureFactory(const TestFixtureFactory& rhs);
};

}}
#endif /* _FTEST_TEST_FIXTURE_FACTORY_H_ */
