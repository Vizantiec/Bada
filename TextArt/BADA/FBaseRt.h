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
 * @file			FBaseRt.h 
 * @brief			This is the header file for the %Runtime namespace.
 *
 * This header file contains the declarations of the %Runtime namespace. 
 * 
 */

#ifndef _FRT_H_
#define _FRT_H_


// Types for Runtime Namespace
#include "FBaseRtTypes.h"

// Semantic Event Model
#include "FBaseRtIEventListener.h"

// Timer Event
#include "FBaseRtTimer.h"
#include "FBaseRtITimerEventListener.h"

#include "FBaseRtThread.h"

#include "FBaseRtLibrary.h"
// Memory Manager
#include "FBaseRtMemoryManager.h"


/**
 * @namespace	Osp::Base::Runtime
 * @brief		This namespace contains classes for running applications.
 * @since		1.0
 * @remarks     @b Header @b %file: @b \#include @b <FBase.h> @n
 *				@b Library : @b FOsp
 *
 *
 * The %Runtime namespace contains classes for running applications.
 * The runtime environment includes threading, synchronization objects,   
 * and timer.
 *
 * For more information on the %Base::Runtime namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/runtime_namespace.htm">Runtime</a>.
 * 
 *	The following diagram illustrates the relationships between the classes belonging to the %Runtime namespace.
 *	@image html base_runtime_namespace_classdiagram.png 
 *	
 * 
 *
 */


namespace Osp { namespace Base { namespace Runtime {


} } }// Osp::Runtime

#endif


