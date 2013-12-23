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
 * @file		FBaseCol.h 
 * @brief		This is the header file for the %Collection namespace.
 *
 * This header file contains the declarations and descriptions of the %Collection namespace.
 *
 */
#ifndef _FBASE_COL_H_
#define _FBASE_COL_H_


// Object-based collection
#include "FBaseColArrayList.h"
#include "FBaseColLinkedList.h"
#include "FBaseColQueue.h"
#include "FBaseColStack.h"
#include "FBaseColHashMap.h"
#include "FBaseColMapEntry.h"
#include "FBaseColIHashCodeProvider.h"
#include "FBaseColMultiHashMap.h"
#include "FBaseColIBidirectionalEnumerator.h"
#include "FBaseColIBidirectionalEnumeratorT.h"

// Template-based collection
#include "FBaseColIComparerT.h"
#include "FBaseColArrayListT.h"
#include "FBaseColLinkedListT.h"
#include "FBaseColQueueT.h"
#include "FBaseColStackT.h"
#include "FBaseColHashMapT.h"
#include "FBaseColMultiHashMapT.h"
#include "FBaseColMapEntryT.h"


namespace Osp { namespace Base {
/**
 * @namespace	Osp::Base::Collection
 * @brief		This namespace contains classes and interfaces for various collections.
 * @since		1.0
 *
 * @remarks     @b Header @b %file: @b \#include @b <FBase.h> @n
 *				@b Library : @b FOsp
 *
 * 
 * The %Collection namespace contains classes and interfaces for various collections
 * (such as lists, maps, stacks, and queues), which are an aggregation of similar objects.
 *
 *  For more information on the %Base::Collection namespace features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/base/collection_namespace.htm">Collection</a>.
 *
 * The following diagram illustrates the relationships between the classes belonging to the %Collection namespace. 
 *
 * 	@image html base_collection_namespace_obj_based_classdiagram.png 
 *
 *	@image html base_collection_namespace_template_based_classdiagram.png 
 *
 *
 *
 *
 */
namespace Collection
{

}; // Collection
}; }; // Osp::Base
#endif // _FBASE_COL_H_

