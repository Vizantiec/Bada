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
 * @file		FBaseRtLibrary.h 
 * @brief		This is the header file for the Dynamic Linking Library (DLL) %Library class.
 *
 * This header file contains the declarations of the %Library (DLL) class.
 */

#ifndef _FRT_LIBRARY_H_
#define _FRT_LIBRARY_H_

#include "FBaseResult.h"
#include "FBaseString.h"


namespace Osp { namespace Base { namespace Runtime {



/**
 * @class Library
 * @brief This is the class for shared library.
 * @since 1.0
 *
 * The %Library class loads the shared library with the given file path.
 * It loads the library in current process' memory space, and application can use this library explicitly.
 */
class _EXPORT_BASE_ Library
{
public:
	/**
	 *	This is the default constructor for this class.
	 *
	 *  @since 1.0
	 */
	Library(void);


	/**
	 *	This is the destructor for this class.
	 *
	 *  @since 1.0
	 */
	~Library(void);


	/**
	 * @if PRIVCORE
	 *
	 * Initializes this instance of %Library with the specified DLL path. @n
	 * It loads the library in the memory space of the current process.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup RUNTIME
	 *
	 * @param[in]	dllPath				The path of the DLL file
	 * @return		An error code
	 *
	 * @exception	E_SUCCESS			 The method is successful.
	 * @exception	E_LIBRARY_NOT_FOUND	 The library cannot be found.
     *
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
     *
	 * @endif
	 */
	result Construct(const Osp::Base::String& dllPath);




	/**
	 * @if PRIVCORE
   *
	 * Gets the address of the specified symbol from the specified dynamic
	 * linking library.
	 *
	 * @since 		1.0
	 * @privlevel	CORE
	 * @privgroup RUNTIME
	 *
	 * @return		The address of the specified symbol
	 * @param[in]	symbol		The symbol of the address to get
     *
	 * @exception	E_SUCCESS				 The method is successful.
	 * @exception	E_SYMBOL_NOT_FOUND		 The symbol cannot be found in the symbol table of the dynamic linking library.
	 *
	 * @exception   E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
   *
	 * @endif
	 */
	void* GetProcAddress(const Osp::Base::String& symbol);

private:


	/**
	 *	Dll handle
	 */
	void* __pHandle;

private:
	friend class LibraryEx;
	class LibraryEx* __pLibraryEx;
};


} } }// Osp::Runtime


#endif

