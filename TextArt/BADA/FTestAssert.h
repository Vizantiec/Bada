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
 * @file		FTestAssert.h
 * @brief		This is the header file for the Assert structure.
 *
 * This header file contains the declarations of the Assert structure.
 */
#ifndef _FTEST_ASSERT_H_
#define _FTEST_ASSERT_H_

#include <FBase.h>

namespace Osp { namespace Test {

class AssertException;
class TestRegistry;

/**
 * @internal
 * @class		Assert
 * @brief		The Assert class provides a set of static methods to use Assert Macros.
 * @since		1.1
 *
 * In FTestMacroAssert.h, There are many Assert Macros. and They use this Assert's methods to create and throw AssertException.
 * For help your understand, Here is an example using Assert Macro.
 *
 * @code
 * class TestBankAccount: public Osp::Test::TestFixture{
 *	public:
 *		void SetUpBeforeTestSuite() {}
 *		void TearDownAfterTestSuite() {}
 *		void SetUp() {pAccount = new BankAccount();}
 *		void TearDown() {delete pAccount;}
 *
 *		void TestDeposit() {
 *		     pAccount->Deposit(100);
 *		     TestAssertMessage (pAccount->GetBalance() == 100);
 *		}
 * };
 * @endcode
 *
 * In the method TestDeposit, you can use following code instead of TestAssertMessage Macro.
 * so, If you want to create your own MACRO, use this methods to make it.
 * @code
 *
 * if (!( pAccount->GetBalance() == 100 )) Osp::Test::Assert::Fail("the value of Balance is not correct!",  __FILE__, __LINE__);
 *
 * @endcode
 */
struct Assert
{
	/**
	 * Creates and throws AssertException with the file path and the line number of where the failure occurred.
	 *
	 * @since			1.1
	 * @param[in]	message		The message that desribes a failure
	 * @param[in]	filePath	The file's path that makes an assertion
	 * @param[in]	lineNum		The line number in the file that makes an assertion
	 * @param[in]	isCheck		The value is @c false if the Assert Macro calls this method @n
	 * 						The value is @c true if the Check Macro calls this method
	 */
	static void Fail(const Osp::Base::String& message, const Osp::Base::String& filePath, int lineNum, bool isCheck=false);

	/**
	 * Creates and throws AssertException if the value of @c condition is @c false.
	 *
	 * @since			1.1
	 * @param[in]	message		The message that desribes a failure
	 * @param[in]	condition		The condition value
	 * @param[in]	filePath	The file's path that makes an assertion
	 * @param[in]	lineNum		The line number in the file that makes an assertion
	 * @param[in]	isCheck		The value is @c false if the Assert Macro calls this method @n
	 * 						The value is @c true if the Check Macro calls this method
	 */
	static void AssertTrue(const Osp::Base::String& message, bool condition, const Osp::Base::String& filePath, int lineNum, bool isCheck=false);

	/**
	 * Creates and throws AssertException if the value of @c condition is @c true.
	 *
	 * @since			1.1
	 * @param[in]	message		The message that desribes a failure
	 * @param[in]	condition		The condition value
	 * @param[in]	filePath	The file's path that makes an assertion
	 * @param[in]	lineNum		The line number in the file that makes an assertion
	 * @param[in]	isCheck		The value is @c false if the Assert Macro calls this method @n
	 * 						The value is true if the Check Macro calls this method
	 */
	static void AssertFalse(const Osp::Base::String& message, bool condition, const Osp::Base::String& filePath, int lineNum, bool isCheck=false);

	/**
	 * Creates and throws AssertException with an expected exception and an actual exception.
	 *
	 * @since			1.1
	 * @param[in]	message		The message that desribes a failure
	 * @param[in]	expected	The expected value
	 * @param[in]	actual		The actual value
	 * @param[in]	filePath	The file's that makes an assertion
	 * @param[in]	lineNum		The line number in the file that makes an assertion
	 * @param[in]	isCheck		The value is @c false if the Assert Macro calls this method @n
	 * 						The value is @c true if the Check Macro calls this method
	 */
	static void AssertThrow(const Osp::Base::String& message, const Osp::Base::String& expected, const Osp::Base::String& actual, const Osp::Base::String& filePath, int lineNum, bool isCheck=false);

	enum
	{
		SUCCESS = 0,
		FAIL,
		CHECK,
		ERROR
	};

	/** @internal
	 * The Assert class and methods are used internally.
	 *
	 * @since			1.1
	 */
	class AssertInfo : public Osp::Base::Object
	{
	public:
	  /**
	   * @since			1.1
	   */		
		AssertInfo();
	  /**
	   * @since			1.1
	   */		
		AssertInfo(int assertType, const Osp::Base::String& message, const Osp::Base::String& filePath, int lineNum);
	  /**
	   * @since			1.1
	   */		
		AssertInfo(const AssertInfo &baseException) ;
		
	  /**
	   * @since			1.1
	   */		
		const Osp::Base::String& GetMessage(void) const { return __message; }
	  /**
	   * @since			1.1
	   */		
		void SetMessage(const Osp::Base::String& message) { __message = message; }
	  /**
	   * @since			1.1
	   */		
		int GetAssertType(void) const { return __assertType; }
	  /**
	   * @since			1.1
	   */		
		void SetAssertType(int assertType) { __assertType = assertType; }
	  /**
	   * @since			1.1
	   */		
		Osp::Base::String GetFilePath(void) const { return __filePath; }
	  /**
	   * @since			1.1
	   */		
		void SetFilePath(const Osp::Base::String& filePath) { __filePath = filePath; }
	  /**
	   * @since			1.1
	   */		
		int GetLineNum(void) const { return __lineNum; }
	  /**
	   * @since			1.1
	   */		
		void SetLineNum(int lineNum)  { __lineNum= lineNum; }
	private:
		int __assertType;
		Osp::Base::String __message;
		Osp::Base::String __filePath;
		int __lineNum;
	};

  /**
   * @since			1.1
	 */		
	static void InitTestResult(void);
  /**
   * @since			1.1
	 */		
	static void PushTestResult(int assertType, const Osp::Base::String& message, const Osp::Base::String& filePath, int lineNum );
  /**
   * @since			1.1
	 */		
	static bool PopTestResult(AssertInfo& assertInfo);
  /**
   * @since			1.1
	 */		
	static int  GetAssertCount(void);
  /**
   * @since			1.1
	 */		
	static int  GetResultType(void);
  /**
   * @since			1.1
	 */		
	static bool HasFailResult(void);

  /**
   * @since			1.1
	 */		
	static Osp::Base::Collection::ArrayListT<Assert::AssertInfo*> assertRegister;

};
}}
#endif /* _FTEST_ASSERT_H_ */
