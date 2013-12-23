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
 * @file		FCntContentSearchResult.h 
 * @brief		This is the header file for the %ContentSearchResult class.
 *
 * This header file contains the declarations of the %ContentSearchResult class.
 */

#ifndef _FCNT_CONTENT_SEARCH_RESULT_H_
#define _FCNT_CONTENT_SEARCH_RESULT_H_

#include <FCntConstants.h>

namespace Osp { namespace Content {

class ContentInfo;
class ContentSearchResultEx;

/**
 * @class	ContentSearchResult
 * @brief	This class represents the content search result. 
 * @since	1.0
 *
 * The %ContentSearchResult class gets a pointer to the ContentInfo class and retrieves the content type. 
 *
 * The search result list comprises of this class, and each node can have a different type of %ContentInfo (ImageContentInfo, AudioContentInfo, VideoContentInfo, or OtherContentInfo). 
 * You must cast the %ContentInfo class into the appropriate content type to use the %ContentSearchResult class.
 */

class _EXPORT_CONTENT_ ContentSearchResult :
	public Osp::Base::Object
{

public:
// Lifecycle
	/**
	 * This is the default constructor for this class.
	 *
	 * @since			1.0
	 * @remarks		After creating an instance of this class, one of the Construct() methods must be called explicitly 
	 *				to initialize this instance.
	 * @see			Construct()
	 */
	
	ContentSearchResult(void);
	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~ContentSearchResult(void);

//Operator
public:
	/**
	 * Gets the content type of the ContentInfo class.
	 *
	 * @since			1.0
	 * @return		The content type
	 *				
	 */
	ContentType GetContentType(void) const;

	/**
	 * Gets the content information of the ContentInfo class.
	 *
	 * @since			1.0
	 * @return		A pointer to the %ContentInfo class
	 *				
	 */
	ContentInfo* GetContentInfo(void) const;

private:
	void __SetContentType(ContentType contentType);

	void __SetContentInfo(ContentInfo* pContentInfo);

	ContentType __contentType; 
	ContentInfo* __pContentInfo;

	friend class ContentSearch;
	friend class ContentSearchResultEx;
	class ContentSearchResultEx* __pContentSearchResultEx;

};


}; }; // Osp::Content

#endif// _FCNT_CONTENT_SEARCH_RESULT_H_

