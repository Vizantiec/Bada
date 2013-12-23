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
 * @file			FBaseRtMemoryManager.h 
 * @brief		    This is the header file for the %MemoryManager class.
 *
 * This header file contains the declarations of the %MemoryManager class.
 *
 */

 
#ifndef _FBASE_MEMORY_MANAGER_H_
#define _FBASE_MEMORY_MANAGER_H_

#include "FBase.h"
#include "FBaseObject.h"

namespace Osp { namespace Base { namespace Runtime {

/**
 *  @class 	MemoryManager
 *	@brief	This class represents a memory manager for runtime. 
 *	@since	2.0
 *
 *  The %MemoryManager class represents a memory manager for runtime. 
 *
 *  The following example demonstrates how to use the %MemoryManager class.
 *
 *	@code
 *	#include <stdlib.h>
 *	#include <FBaseRt.h>
 *
 *	using namespace Osp::Base::Runtime;
 *
 *  result
 *	MyApp::Execute(void)
 *	{
 *      result r = E_SUCCESS;
 *		int size = 1024;
 *
 *		void *pTest = (void*)malloc(size);
 *      ...
 *
 *      // Prepare for execution
 *		r = MemoryManager::PrepareForExecution(pTest, size);
 *      if (IsFailed(r))
 *	    {
 *			//Failed to prepare for execution
 *		}
 *
 *      // Execute code in the memory
 *      ...	    
 *
 *	}
 *
 *	@endcode
 *
 */
class _EXPORT_BASE_ MemoryManager :
	public Osp::Base::Object
{
// Lifecycle
private:
	/**
	 * This is the default constructor for this class.
	 */
	 MemoryManager(void);

	 /**
	  * This is the destructor for this class. 
	  */
	  virtual ~MemoryManager(void);

// Operation
public:
	
	/**
	 * Prepares for executing an application. @n
     * This method should be recalled when the address and size of the memory are changed for executing an application.
	 *
	 * @since	    2.0
	 * @privlevel	SYSTEM
	 * @privgroup	EXECUTION_ON_HEAP
     *
     * @param[in]   pAddress        A pointer to the starting memory address
     * @param[in]   size            The size of memory in bytes
	 *	 
	 * @return		An error code
	 * @exception	E_SUCCESS	    	The method is successful.	 
	 * @exception	E_SYSTEM    	    A system error has occurred due to an invalid address.
	 * @exception	E_INVALID_ARG       A specified input parameter is invalid. 
 	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.	 
     */
	static result PrepareForExecution(void* pAddress, int size);
		
private:	
	friend class MemoryManagerEx;
	class DeviceManagerEx* __pMemoryManagerEx;
};
} /* Runtime */ } /* Base */ } /* Osp */
#endif 
