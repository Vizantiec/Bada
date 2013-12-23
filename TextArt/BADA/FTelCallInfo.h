/* $Change: 1142016 $ */
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
 * @file		FTelCallInfo.h
 * @brief		This is the header file for the %CallInfo class.
 *
 * This header file contains the declarations of the %CallInfo class.
 */

#ifndef _FTEL_CALL_INFO_H_
#define _FTEL_CALL_INFO_H_

// Includes
#include "FBase.h"
#include "FTelConfig.h"
#include "FTelEnum.h"

namespace Osp { namespace Telephony {
//forward declaration
class __CallInfoImpl;

/**
 * @class	CallInfo
 * @brief	This class provides methods to obtain detailed information about a call.
 * @since	2.0
 *
 * The %CallInfo class provides methods to obtain detailed call information, such as the call type and number.
 *
 *
 */
class _EXPORT_TEL_ CallInfo
	: public Osp::Base::Object
{
// Life cycle
public:

	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since	2.0
	 */
	CallInfo(void);

	/**
	 *	This is the copy constructor for the %CallInfo class.
	 *
	 * @since				2.0
	 *
	 * @param[in]		callInfo	The call information
	 */
	CallInfo(const CallInfo& callInfo);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since	2.0
	 */
	virtual ~CallInfo(void);

// Operation
public:

	/**
	 * Gets the call type of a call.
	 *
	 * @since			2.0
	 *
	 * @return		The current call type
	 * @see			Osp::Telephony::CallType
	 */
	CallType GetCallType(void) const;

	/**
	 * Gets the correspondent's phone number.
	 *
	 * @since			2.0
	 * @return		The phone number
	 *
	 * @remarks This information is valid only for an incoming event.
	 */
	Osp::Base::String GetNumber(void) const;

private:

	CallInfo(CallType type, const Osp::Base::String& number);
	CallInfo& operator =(const CallInfo& value);

private:
	friend class __CallInfoImpl;
	class __CallInfoImpl* __pCallInfoImpl;
};

};};
#endif // _FTEL_CALL_INFO_H_
