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
 * @internal
 * @file			FSysFeatureList.h 
 * @brief		This is the header file for the %FeatureList class.
 *
 * This header file contains the declarations of the %FeatureList class.
 *
 */

 
#ifndef _FSYS_SYSTEM_FEATURELIST_H_
#define _FSYS_SYSTEM_FEATURELIST_H_

#include "FSysConfig.h"
#include "FBaseObject.h"

namespace Osp { namespace System {

/**
 * @internal
 * This is internal. If used in an application, the application can get rejected during the certification process. 
 * @class		FeatureList
 * @brief		This class retrieves information about a feature that has been installed or not. 
 * @since		1.0
 *
 * Each localized binary can have different features. This class can information about a feature that has been installed or not.
 *
 */
class _EXPORT_SYSTEM_ FeatureList :
	public Osp::Base::Object
{
private:
	/**
	 * This is the default constructor for this class.
	 */
	 FeatureList(void);

	 /**
	  * This is the destructor for this class. @n
	  */
	  virtual ~FeatureList(void);

public:
	/**
   * @internal
   * This is internal. If used in an application, the application can get rejected during the certification process.
	 * Retrieve information about a feature that has been installed or not. 
	 *
	 * @since 		1.0
	 * @return		An error code
	 * @param[in]	featureName	The feature name
	 * @param[out] value	The retrieved result of the feature
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OBJ_NOT_FOUND	The specified @c key is not found.
	 * @exception	E_SYSTEM	A system error occurred.
    */
	static result GetValue(const Osp::Base::String& featureName, bool& value);


private:
	friend class FeatureListEx;
	class FeatureListEx* __pFeatureListEx;
};
};	};
#endif 

