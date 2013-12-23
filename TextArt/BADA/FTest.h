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
 * @file		FTest.h
 * @brief		This is the header file for the %Test namespace.
 *
 * This header file contains the declarations of the %Test namespace.
 */
#ifndef _FTEST_H_
#define _FTEST_H_

#include "FTestMacro.h"
#include "FTestTestFixture.h"
#include "FTestTestSuite.h"
#include "FTestTestResult.h"
#include "FTestTestRunner.h"
#include "FTestSimpleTestCase.h"
#include "FTestTestRegistry.h"

// Utility
#include "FTestUtil.h"

/**
 * @namespace	Osp::Test
 * @brief			This namespace contains classes to perform unit test for bada C++ applications.
 * @since			1.1
 *
 * @remarks		@b Header @b %file: @b \#include @b <FTest.h> @n
 *						@b Library : @b FTest.a
 *
 *
 * The %Test namespace is a testing framework; a part of the bada Testing Tool, which allows you to develop and run different
 * types of test cases for unit testing. The testing framework has an
 * xUnit-based architecture. 
 *
 * For more information on the %Test namespace features, see <a href="../com.osp.documentation.help/html/dev_env/testing_using_test_namespace.htm">Testing Applications Using the Test Namespace</a> and 
 <a href="../com.osp.documentation.help/html/dev_env/test_macros.htm">Test Macros</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Test namespace.
 * @image html test_namespace_classdiagram.png
 *
 *
 *
 *
 */
namespace Osp { namespace Test  {
}}
#endif /* _FTEST_H_ */
