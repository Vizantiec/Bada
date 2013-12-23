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
 * @file		FTestTestConstants.h
 * @brief		This is the header file to define __Format structure.
 *
 * This header file contains the definitions of the __Format structure.
 */
#ifndef _FTEST_TEST_CONSTANTS_H_
#define _FTEST_TEST_CONSTANTS_H_

#include <FBase.h>
#include <string>

namespace Osp { namespace Test {

struct __Format
{
	static Osp::Base::String ToString(bool value);
	static Osp::Base::String ToString(int value);
	static Osp::Base::String ToString(unsigned int value);
	static Osp::Base::String ToString(short value);
	static Osp::Base::String ToString(unsigned short value);
	static Osp::Base::String ToString(long value);
	static Osp::Base::String ToString(unsigned long value);
	static Osp::Base::String ToString(float value);
	static Osp::Base::String ToString(double value);
	static Osp::Base::String ToString(long double value);
	static Osp::Base::String ToString(char value);
	static Osp::Base::String ToString(const char* value);
	static Osp::Base::String ToString(const mchar* value);
	static Osp::Base::String ToString(std::string &value);
	static Osp::Base::String ToString(const std::string &value);

	static Osp::Base::String ToString(const Osp::Base::Object &value);
	static Osp::Base::String ToString(const Osp::Base::String &value);
	static Osp::Base::String ToString(const Osp::Base::Character &value);
	static Osp::Base::String ToString(const Osp::Base::Boolean &value);
	static Osp::Base::String ToString(const Osp::Base::Number &value);
	static Osp::Base::String ToString(const Osp::Base::DateTime &value);
	static Osp::Base::String ToString(const Osp::Base::TimeSpan &value);
	static Osp::Base::String ToString(const Osp::Base::UuId &value);

	static Osp::Base::String MakeMessage(const Osp::Base::String &user_message, const Osp::Base::String &expected_value, const Osp::Base::String &actual_value);
	static Osp::Base::String MakeMessage(const Osp::Base::String &message1, const Osp::Base::String &message2);

};

}}

/*____________________________________________________________________________________________

                                    CONSTANT - ASSERT
  ____________________________________________________________________________________________*/
#define __MakeString(expected,actual, user_message) 							Osp::Test::__Format::MakeMessage(Osp::Test::__Format::ToString(expected),Osp::Test::__Format::ToString(actual), Osp::Base::String(user_message))

#define __MakeString2(message1, message2)											Osp::Test::__Format::MakeMessage(Osp::Base::String(message1), Osp::Base::String(message2))


#endif /* _FTEST_TEST_CONSTANTS_H_ */
