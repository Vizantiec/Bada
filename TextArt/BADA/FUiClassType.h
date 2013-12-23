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
* @file			FUiClassType.h
* @brief		This is the header file for the %Ui namespace.
*
* This header file contains the declarations and descriptions of the %Ui namespace.
*/

#ifndef __CLASS_TYPE_H__
#define __CLASS_TYPE_H__

#ifndef __cplusplus
#error C++ only(.cpp)
#endif

#pragma once

#include "FBaseTypes.h"
#include "FBaseObject.h"
#include "FUiConfig.h"

namespace Osp { namespace Ui{ }};

/**
* @class	IClassType 
* @brief	This class is the @b runtime class of the bada UI.
* @since	1.0
*
* The %IClassType class can make some class characteristics into a dynamic class.
* 
* Dynamic class : If the 'B' class is declared by %IClassType, the 'A' module can make the
*             instance of 'B' class with the 'B' class name when 'A' module does not  
*             know about the 'B' class type (has no header file). 
*                
* 
*/

class _EXPORT_UI_ IClassType
{
public:
	IClassType(bool bSystem = false );
	virtual ~IClassType(void);
	void Register(bool bReg = true){bRegistered = bReg;}
	bool IsRegistered(void){ return bRegistered; }
	virtual const char * GetClassName(void)=0;
	virtual Osp::Base::Object * Create(void)=0;

public:
	bool bRegistered;
	IClassType * pPrev;	
	IClassType * pNext;	
};

#define DECL_CLASSTYPE(_classname)							\
public:														\
class _classname##_ClassDecl :public IClassType				\
{															\
public:														\
	_classname##_ClassDecl(bool bSystem = false):IClassType(bSystem){}\
	virtual const char * GetClassName(void){return #_classname;};	\
	virtual Osp::Base::Object * Create(void){return new _classname; };	\
};															\
	static _classname##_ClassDecl __classDecl 

/**
* @class	ClassTypeFactory 
* @brief	This class is the @b runtime class of the bada UI.
* @since	1.0
*
* The %ClassTypeFactory class manages the registered runtime class.
* The registered runtime classes are linked with the %IClassType class.
* 
*/

class _EXPORT_UI_ ClassTypeFactory 
{
public :
	IClassType * pBegin; // class factory table
	IClassType * pEnd; // class factory table

	ClassTypeFactory();
	virtual ~ClassTypeFactory();
	IClassType * GetBeginClass(void){return pBegin;}
	IClassType * GetEndClass(void){return pEnd;}
	Osp::Base::Object * CreateObjectInstance(char * szClassName);
	void RegisterRuntimeClass(IClassType* _iclasstype);
	void UnRegisterRuntimeClass(IClassType* _iclasstype);
};

ClassTypeFactory* GetSysClassFactory(); 

#define INIT_CLASSTYPE(_classname)	\
	class _classname::_classname##_ClassDecl ;\
	_classname::_classname##_ClassDecl _classname::__classDecl

#define INIT_SYSCLASSTYPE(_classname)	\
	class _classname::_classname##_ClassDecl ;\
	_classname::_classname##_ClassDecl _classname::__classDecl(true)

//}; }; //Osp::Ui

#endif //__CLASS_TYPE_H__
