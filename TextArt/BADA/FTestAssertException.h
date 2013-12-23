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
 * @file		FTestAssertException.h
 * @brief		This is the header file of the %AssertException class.
 *
 * This header file contains the declarations of the %AssertException class.
 */
#ifndef _FTEST_ASSERT_EXCEPTION_H_
#define _FTEST_ASSERT_EXCEPTION_H_

#include "FTestBaseException.h"

namespace Osp { namespace Test {

/**
 * @internal
 * @class		AssertException
 * @brief		The AssertException is thrown when codes of a test case makes an Assertion.
 * @since		1.0
 *
 * The AssertException is thrown when the code of a test case makes an Assertion.
 * It means the result of the test case is failure.
 * This exception is used internally.
 *
 */
class AssertException: public BaseException
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	AssertException(void);

	/**
	 * Initializes this instance of AssertException with @c message.
	 *
	 * @since			1.0
	 * @param[in]	message		The user-defined message that desribes a failure
	 */
	AssertException(const Osp::Base::String& message);

	/**
	 * Initializes the message with the test-file information.
	 *
	 * @since			1.0
	 * @param[in]	message		The user-defined message that desribes a failure
	 * @param[in]	filePath	The file's path that throws AssertException
	 * @param[in]	lineNum		The line number in the file that throws AssertException
	 */
	AssertException(const Osp::Base::String& message, const Osp::Base::String& filePath, int lineNum);

	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~AssertException() throw();
};

}}
#endif /* _FTEST_ASSERT_EXCEPTION_H_ */
