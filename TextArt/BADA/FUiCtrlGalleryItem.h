// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlGalleryItem.h
 * @brief	This is the header file for the %GalleryItem class.
 *
 * This header file contains the declarations of the %GalleryItem class and its helper classes.
 */
 
#ifndef _FUICTRL_GALLERY_ITEM_H_
#define _FUICTRL_GALLERY_ITEM_H_

//Includes
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FGrpBitmap.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlGalleryEnum.h"

namespace Osp { namespace Ui { namespace Controls {

class GalleryItemEx;

/**
 * @class	GalleryItem
 * @brief This class defines the common behavior for a %GalleryItem control.
 * @since		2.0
 *
 * The %GalleryItem class represents an item of the Gallery control. An instance of the %GalleryItem class
 * comprises of a bitmap image and its image rotation. @n @n
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_gallery.htm">Gallery</a>.
 */
class _EXPORT_CONTROLS_ GalleryItem
	: public Osp::Base::Object
{
public:
	/** 
	 * This is the default constructor for this class. 
	 *
	 * @since 2.0 
	 */	
	GalleryItem(void);
	
	/** 
	 * This is the destructor for this class. 
	 * @since 2.0 
	 */	
	virtual ~GalleryItem(void);
	
private:
	/*
	 * This is the copy constructor for the %GalleryItem class.
	 *
	 * @since 2.0 
	 */
	GalleryItem(const GalleryItem& galleryItem);
	
	/*
	 * This is the substitution operator for this class.
	 *
	 * @since 2.0 
	 */
	GalleryItem& operator=(const GalleryItem& galleryItem);
	
public:
	/** 
	 * Initializes this instance of %GalleryItem with the specified parameters.
	 *
	 * @since 2.0 
	 * @return		An error code
	 * @param[in]	bitmap			The default bitmap image
	 * @param[in]	rotation		The rotation of the bitmap image
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_MEMORY	The memory is insufficient.
	 * @exception E_INVALID_STATE   This instance has already been constructed.
	 * @exception E_SYSTEM          A system error has occurred.
	 */
	result Construct(const Osp::Graphics::Bitmap& bitmap, GalleryImageRotation rotation = GALLERY_IMAGE_ROTATION_0);

	/**
	* Initializes this instance of %GalleryItem with the specified parameters.
	*
	* @since 2.0 
	* @return            	 			 An error code
	* @param[in]  bitmap                 The default bitmap image
	* @param[in]  filePath               The bitmap file path
	* @param[in]  rotation               The rotation of the bitmap image
	* @exception  	E_SUCCESS				The method is successful.
	* @exception  E_INVALID_STATE        This instance has already been constructed.
	* @exception  	E_OVERFLOW				The image specified by @c filePath has caused an overflow.
	* @exception  	E_UNSUPPORTED_FORMAT   	The image specified by @c filePath is not supported.
	* @exception  	E_OUT_OF_MEMORY        	The memory is insufficient.
	* @exception  E_FILE_NOT_FOUND       The specified file cannot be found or accessed.
	* @exception  E_INTERRUPTED   		 The requested operation cannot be performed due to an interruption from another thread. @n
	* @exception  E_ILLEGAL_ACCESS       The image specified by @c filePath parameter, is protected with DRM.
	* @exception  E_SYSTEM           	 A system error has occurred.
	* @remarks  The specified file path is used to decode the original bitmap to show a more higher quality image when the corresponding item is zoomed.
	*/
	result Construct(const Osp::Graphics::Bitmap& bitmap, const Osp::Base::String& filePath, GalleryImageRotation rotation=GALLERY_IMAGE_ROTATION_0);

private:
	friend class Gallery;
	friend class __GalleryEventAdaptor;
	friend class GalleryItemEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */	
	class GalleryItemEx* __pGalleryItemEx;
};

}; }; }; 

#endif // _FUICTRL_GALLERY_ITEM_H_

