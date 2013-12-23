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
 * @file		FBaseResource.h 
 * @brief		This is the header file for __Resource class.
 *
 * This header file contains the declaration of __Resource class.
 */
#ifndef _FBASE_RESOURCE_H_
#define _FBASE_RESOURCE_H_

// includes
#include "FBaseErrors.h"

namespace Osp { namespace Base {
/**
 *  @internal
 *  This is internal. If used in an application, the application can get rejected during the certification process.
 *	@class	__Resource 
 *	@brief	This class is the base class of all resource types in the framework.
 *	@since	1.0
 *
 *	The Resource class is the base class of all resource classes in the framework. 
 *	This class only defines only one method - Dispose(void) which is called by the resource tracker
 *  to free the system resource allocated by an instance of Resource (or any of its derived). @n
 *
 *	A derived of this class must override Dispose(void) method and provide specific de-
 *	allocation routine. Also it must ensure that calling destruct method multiple 
 *	times does not generate any runtime error. 
 *
 */

// forward declaration
class __ResourceTracker;

class _EXPORT_BASE_ __Resource
{
// Lifecycle
public:

	/** 
	 *  This is the default constructor for this class. @n
	 *	Initializes the current instance of Resource and stores
	 *	the name of file and the line number where the this Resource is created. 
	 *
	 *	@since	1.0
	 */
	__Resource(void);


	/** 
	 *	This is the destructor for this class.
	 *
	 *	@since	1.0
	 */
	virtual ~__Resource(void);


	// Operation
protected:
	/** 
     * @internal
     * This method is for internal use only. The bada platform team is not 
     * responsible for any behavioral correctness, consistency, and 
     * security-related issues that might arise after using this method.
     * 
	 * Frees the resources allocated by this instance.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_SYSTEM			The method is unable to free the resource currently possessed by this instance.
	 * @remarks		The implementer of the derived class of Resource class must override
	 *				this method and provide specific resource deallocation routine.
	 */
	virtual result Dispose(void);


// Attribute
protected:
	/** 
     * @internal
     * This variable is for internal use only. The bada platform team is not 
     * responsible for any behavioral correctness, consistency, and 
     * security-related issues that might arise after using this method.
     * 
     * @since 1.0
     */
	String* __pAppId;

// Friend
private:
	friend class Osp::Base::__ResourceTracker;

};
}; };// Osp::Base
#endif//_FBASE_RESOURCE_H_
