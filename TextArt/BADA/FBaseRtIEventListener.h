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
 * @file			FBaseRtIEventListener.h
 * @brief			This is the header file for EventListener.
 *
 * This header contains the declarations for the EventListener interface.
 */
#ifndef _FRT_IEVENT_LISTENER_H_
#define _FRT_IEVENT_LISTENER_H_


#include "FBaseResult.h"

namespace Osp { namespace Base { namespace Runtime {

/**
 * @interface IEventListener
 * @brief This is a tagging interface that all event listeners must implement.
 * @since 1.0
 *
 * The %IEventListener interface is a tagging interface that all event listeners must implement.
 * The event listener can listen when the specific event occurs. The event listener
 * has several methods, and each method is called when a specific event occurs.
 *
 */
class _EXPORT_BASE_ IEventListener
{
// Lifecycle
public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since 1.0
	 */
	virtual ~IEventListener(void);

};


} } }// Osp::Runtime


#endif

