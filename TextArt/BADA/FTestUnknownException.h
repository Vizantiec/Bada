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
 * @file		FTestUnknownException.h
 * @brief		This is the header file for the %UnknownException class.
 *
 * This header file contains the declarations of the %UnknownException class.
 */
#ifndef _FTEST_UN_KNOWN_EXCEPTION_H_
#define _FTEST_UN_KNOWN_EXCEPTION_H_

#include <FBaseString.h> 
#include "FTestBaseException.h"

namespace Osp { namespace Test {

/**
 * @internal
 * @class		UnknownException
 * @brief		The UnknownException class is thrown when it is impossible to run a test case because of some reason.
 * @since		1.1
 *
 * In this test framework, The UnknownException class is thrown when it is impossible to run a test case because of some reason.
 * It means the result of the test case is an error.
 * This exception is used internally.
 *
 */
class UnknownException : public BaseException
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.1
	 */
	UnknownException(void);

	/**
	 * Initializes this instance of %UnknownException with the specified message.
	 *
	 * @since			1.1
	 * @param[in]	message		The user-defined message that describes a failure
	 */
	UnknownException(const Osp::Base::String& message);

	/**
	 * Initializes this instance of %UnknownException with the test-file information.
	 *
	 * @since			1.1
	 * @param[in]	message		The user-defined message that describes a failure
	 * @param[in]	filePath	The file's path that throws this exception
	 * @param[in]	lineNum		The line number in the file that throws this exception
	 */
	UnknownException(const Osp::Base::String& message, const Osp::Base::String& filePath, int lineNum);

	/**
	 * This is the destructor for this class.
	 *
	 * @since		1.1
	 */
	virtual ~UnknownException(void) throw();
};

}}
#endif /* _FTEST_UN_KNOWN_EXCEPTION_H_ */
