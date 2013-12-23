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
 * @file		FTestILogWriter.h
 * @brief		This is the header file for the %ILogWriter interface.
 * 
 * This header file contains the declarations of the %ILogWriter interface. @n
 * The %ILogWriter interface is used to write a log on test progress and result.
 */
#ifndef _FTEST_ILOG_WRITER_H_
#define _FTEST_ILOG_WRITER_H_

#include <FBaseString.h> 

namespace Osp { namespace Test {

/** @internal
 * @interface		ILogWriter
 * @brief		This is a listener interface to print test results and information.
 * @since		1.1
 *
 * This is a listener interface to print the information in this framework.
 * This framework calls the Write() method first and then the Flush() method is called continuosly.
 *
 */
class ILogWriter
{
	public :
		/**
		 * Writes a log message into an internal buffer.
		 *
		 * @since			1.1
		 * @param[in]	log			A message
		 */
		virtual void Write(const Osp::Base::String& log) = 0;

		/**
		 * Moves some information from an internal buffer to its destination.
		 *
		 * @since			1.1
		 */
		virtual void Flush(void) = 0;
};
}}

#endif /* _FTEST_ILOG_WRITER_H_ */
