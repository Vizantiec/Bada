/* $Change: 1202329 $ */
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
* @file		FSclSvcSnsImageInfo.h
* @brief	This is the header file for the %SnsImageInfo class.
*
* This header file contains the declarations of the %SnsImageInfo class.
*/
#ifndef _FSCL_SVC_SNS_IMAGE_INFO_H_
#define _FSCL_SVC_SNS_IMAGE_INFO_H_

#include "FBaseObject.h"
#include "FBaseDateTime.h"
#include "FBaseString.h"
#include "FSclConfig.h"

namespace Osp { namespace Social { namespace Services {

	class __SnsUtil;

/**
* @class		SnsImageInfo 
* @brief		This class represents the information of an SNS image information.
* @deprecated	This class is deprecated due to the operation policy of the bada Server.
* @since		1.0 
*
* The %SnsImageInfo class represents the information of an SNS image information.
* The image is a thumbnail or a main image of a photo. It has an image file URL, size, width, and height. The metadata about the image is different for each 
* service provider. Some data may not be available for a specific service provider.
*/
class  _EXPORT_SOCIAL_ SnsImageInfo :
	public Osp::Base::Object
{	
	friend class __SnsUtil;

public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	SnsImageInfo(void);

private:
	/**
	* This is the constructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	SnsImageInfo(const Osp::Base::String& url, int size, int width, int height);

public:
	/**
	* This is the copy constructor for the %SnsImageInfo class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @param[in]	value	An %SnsImageInfo instance to initialize the calling instance
	*/
	SnsImageInfo(const SnsImageInfo& value);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	*/
	virtual ~SnsImageInfo(void);

public:
	/**
	* Gets the image URL.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The URL of the image, for downloading
	*/
	Osp::Base::String GetUrl(void) const;

	/**
	* Gets the image size. @n 
	* When the service provider does not send the size information, this value is set to @c 0.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The size of the image
	*/
	int GetSize(void) const;

	/**
	* Gets the image width. @n
	* When the service provider does not send the width information, this value is set to @c 0.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The width of the image
	*/
	int GetWidth(void) const;

	/**
	* Gets the image height. @n
	* When the service provider does not send the height information, this value is set to @c 0.
	*
	* @deprecated	This method is deprecated due to the operation policy of the bada Server.
	* @since 		1.0
	* @return		The height of the image
	*/
	int GetHeight(void) const;

private:
	Osp::Base::String		__url;
	int						__size;
	int						__width;
	int						__height;

	friend class SnsImageInfoEx;
	class SnsImageInfoEx* __pSnsImageInfoEx;
}; 

};};};// Osp::Social::Services

#endif //_FSCL_SVC_SNS_IMAGE_INFO_H_
