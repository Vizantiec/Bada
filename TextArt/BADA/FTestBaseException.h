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
 * @file		FTestBaseException.h
 * @brief		This is the header file of the %BaseException class.
 *
 * This header file contains the declarations of the %BaseException class.
 */
#ifndef _FTEST_BASE_EXCEPTION_H_
#define _FTEST_BASE_EXCEPTION_H_

#include <FBaseString.h>

namespace Osp { namespace Test {

/**
 * @internal
 * @class		BaseException
 * @brief		This is the base class of Exception in TestFramework.
 * @since		1.0
 *
 * The BaseException class is used to be thrown when the result of a test case is a failure or an error in this TestFramework.
 * You can only use this exception in your ITestListener and TestResult to get an error reason.
 *
 */
class BaseException
{
public:
	/**
	 * This is the default constructor for this class.
	 *
	 * @since		1.0
	 */
	BaseException();

	/**
	 * Initializes this instance of BaseException with the @c message.
	 *
	 * @since			1.0
	 * @param[in]	message		The user-defined message that desribes a failure
	 */
	BaseException(const Osp::Base::String& message);

	/**
	 * This constructor initializes the message with the test-file information.
	 *
	 * @since			1.0
	 * @param[in]	message		The user-defined message that desribes a failure
	 * @param[in]	filePath		The file path to file that throws this Exception
	 * @param[in]	lineNum		The line number in the file  that throws this Exception
	 */
	BaseException(const Osp::Base::String& message, const Osp::Base::String& filePath, int lineNum);

	/**
	 * This is the copy constructor for this class.
	 *
	 * @since			1.0
	 * @param[in]	baseException	A BaseException instance to be copied
	 */
	BaseException(const BaseException &baseException);

	/**
	 * This is the destructor for this class.
	 *
	 * @since			1.0
	 */
	virtual ~BaseException() throw();

	/**
	 * Gets the general cause of the current error.
	 *
	 * @since			1.0
	 * @return		The general cause of the current error
	 */
	virtual Osp::Base::String what(void) const throw();

	/**
	 * Sets the general cause of the current error.
	 *
	 * @since			1.0
	 * @param[in] message	The user-defined message that desribes a failure
	 */
	virtual void SetMessage(const Osp::Base::String& message);

	/**
	 * Gets the path to the file.
	 *
	 * @since			1.0
	 * @return		A path to the file to test
	 */
	Osp::Base::String  GetFilePath(void) const;
	
	/**
	 * Gets the source line.
	 *
	 * @since			1.0
	 * @return		A line-number of the source
	 */
	int GetLineNum(void) const;

	/**
	 * Sets the information of test-file.
	 *
	 * @since			1.0
	 * @param[in]	filePath		The file's path that throws this exception
	 * @param[in]	lineNum			The line number in the file that throws this exception
	 */
	virtual void SetFileInfo(const Osp::Base::String& filePath, int lineNum);

protected:
	Osp::Base::String __message;
	Osp::Base::String __filePath;		
	int __lineNum;
};
}}
#endif /* _FTEST_BASE_EXCEPTION_H_ */
