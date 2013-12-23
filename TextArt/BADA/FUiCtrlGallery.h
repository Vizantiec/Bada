// Copyright (c) 2011 Samsung Electronics Co., Ltd.
// All rights reserved.
 
// This software contains confidential and proprietary information 
// of Samsung Electronics Co., Ltd.
// The user of this software agrees not to disclose, disseminate or copy such 
// Confidential Information and shall use the software only in accordance with 
// the terms of the license agreement the user entered into with Samsung.
//
/**
 * @file	FUiCtrlGallery.h
 * @brief	This is the header file for the %Gallery class.
 *
 * This header file contains the declarations of the %Gallery class and its helper classes.
 */

#ifndef _FUICTRL_GALLERY_H_
#define _FUICTRL_GALLERY_H_

//Includes
#include "FBaseObject.h"
#include "FBaseTypes.h"
#include "FBaseString.h"
#include "FGrpRectangle.h"
#include "FGrpDimension.h"
#include "FGrpBitmap.h"
#include "FUiControl.h"
#include "FUiContainer.h"
#include "FUiCtrlConfig.h"
#include "FUiCtrlListViewEnum.h"
#include "FUiCtrlGalleryItem.h"
#include "FUiCtrlGalleryEnum.h"
#include "FUiCtrlIGalleryItemProvider.h"
#include "FUiCtrlIGalleryEventListener.h"

namespace Osp { namespace Ui { namespace Controls {

class GalleryEx;

/**
 * @class	Gallery
 * @brief	This class defines the common behavior of a %Gallery control.
 * @since	2.0
 *
 * The %Gallery class displays an image viewer that contains a collection of images (1 
 * image at a time) in a horizontally scrolling list. It also supports a slide 
 * show, which automatically displays all the images consecutively.
 * 
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/implementing_gallery.htm">Gallery</a>.
 * 
 * The following example demonstrates how to use the %Gallery class.
 * 
 * @code
// Sample code for GallerySample.h
#include <FGraphics.h>
#include <FUi.h>
#include <FUiControl.h>
#include <FBase.h>
#include <FMedia.h>

class GallerySample :
    public Osp::Ui::Controls::Form,
    public Osp::Ui::Controls::IGalleryEventListener,
    public Osp::Ui::Controls::IGalleryItemProvider
{
protected:
    Osp::Ui::Controls::Gallery*   __pGallery;
   	Osp::Graphics::Bitmap* __pImageTemp ;

public:
    GallerySample(void);
    virtual ~GallerySample(void);
    virtual result OnInitializing(void);
    virtual result OnTerminating(void);
	void GetBitmap(void);

    // IGalleryEventListener
    virtual void OnGalleryCurrentItemChanged(Osp::Ui::Controls::Gallery &gallery, int index);
    virtual void OnGalleryItemClicked(Osp::Ui::Controls::Gallery &gallery, int index);
	virtual void OnGallerySlideShowStarted(Osp::Ui::Controls::Gallery& gallery);
	virtual void OnGallerySlideShowStopped(Osp::Ui::Controls::Gallery& gallery);
	
    //IGalleryItemProvider
    virtual Osp::Ui::Controls::GalleryItem* CreateItem (int index);
    virtual bool DeleteItem (int index, Osp::Ui::Controls::GalleryItem *pItem);
    virtual int GetItemCount(void);
};

// Sample Code for GallerySample.cpp

#include "GallerySample.h"

using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;
using namespace Osp::Base;
using namespace Osp::Media;

result
GallerySample::OnInitializing(void)
{
    result r = E_SUCCESS;

    GetBitmap();
	Rectangle rt = GetBounds();

	__pGallery = new Gallery();
	__pGallery->Construct(rt);
    __pGallery->SetItemProvider(*this);
	__pGallery->AddGalleryEventListener(*this);

    AddControl(*__pGallery);

    return r;
}

result
GallerySample::OnTerminating(void)
{
    result r = E_SUCCESS;
    // TODO: Add your termination code here
    return r;
}

// IGalleryEventListener
 void
 GallerySample::OnGalleryCurrentItemChanged(Osp::Ui::Controls::Gallery &gallery, int index)
 {
     // TODO
 }
 
 void
 GallerySample::OnGalleryItemClicked(Osp::Ui::Controls::Gallery &gallery, int index)
 {
     // TODO
 }

void 
GallerySample::OnGallerySlideShowStarted(Osp::Ui::Controls::Gallery& gallery)
{
	// TODO
}

void 
GallerySample::OnGallerySlideShowStopped(Osp::Ui::Controls::Gallery& gallery)
{
	// TODO
}

void
GallerySample::GetBitmap(void)
{
  // The GetBitmap() method should be implemented.
	Image* pImage = new Image();
	pImage->Construct();
	__pImageTemp = pImage->DecodeN(L"/Res/ScreenDensity-High/image1.jpg", BITMAP_PIXEL_FORMAT_ARGB8888);
	delete pImage;
}

//IGalleryItemProvider
 Osp::Ui::Controls::GalleryItem* GallerySample::CreateItem (int index)
 {
	GalleryItem* pGallery = new GalleryItem();
	pGallery->Construct(*__pImageTemp, L"/Res/ScreenDensity-High/image1.jpg");
	return pGallery;
 }
 
 bool
 GallerySample::DeleteItem (int index, Osp::Ui::Controls::GalleryItem *pItem)
 {
    delete pItem;
	return true;
}

int
GallerySample::GetItemCount(void)
{
 return 1;
}
 * @endcode
 */
class _EXPORT_CONTROLS_	Gallery :
	public Osp::Ui::Control
{
public:
	/** 
	 * This is the default constructor for this class. 
	 *
	 * @since 2.0
	 */	
	Gallery(void);

	/** 
	 * This is the destructor for this class. 
	 *
	 * @since 2.0
	 */	
	virtual ~Gallery(void);
	
private:
	/*
	 * This is the copy constructor for this class.
	 * @since 2.0
	 */
	Gallery(const Gallery& gallery);
	
	/*
	 * This is the substitution operator for this class.
	 * @since 2.0
	 */
	Gallery& operator=(const Gallery& gallery);

public:
	/**
	 * Initializes this instance of %Gallery with the specified parameter.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	rect	        An instance of the Graphics::Rectangle class @n
	 *						        	This instance represents the X and Y coordinates of the top-left corner of the created Gallery control along with the 
	 *									width and height.
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_ARG	The specified input parameter is invalid.
	 * @exception	E_INVALID_STATE	This instance has already been constructed.
	 * @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		For the minimum size of the control, refer to <a href="../com.osp.cppappprogramming.help/html/dev_guide/ui/control_size.htm">here</a>.	 	 
	 */
	result Construct(const Osp::Graphics::Rectangle& rect);
	
	/**
	 * Sets the item provider that creates and deletes the items from the %Gallery control.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	provider		The item provider to create and delete items
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @remark		If an item provider is not set for the %Gallery control, the method does not work. @n
	 *              The item provider should be allocated on a heap memory.
	 */
	result SetItemProvider(const IGalleryItemProvider &provider);

	/**
	 * Adds an IGalleryEventListener instance. @n
	 * The added listener can listen to the item events when they are fired.
	 *
	 * @since 		2.0
	 * @param[in]	listener 		The listener to be added
	 */
	void AddGalleryEventListener(const IGalleryEventListener &listener);

	/**
	 * Removes an IGalleryEventListener instance. @n
	 * The removed listener cannot listen to events when they are fired.
	 *
	 * @since 		2.0
	 * @param[in]	listener 		The listener to be removed
	 */
	void RemoveGalleryEventListener(const IGalleryEventListener &listener);

	/**
	 * Gets the index of the current item.
	 *
	 * @since 		2.0
	 * @return		The current item index of the %Gallery control
     * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetCurrentItemIndex(void) const;

	/**
	 * Sets the index of the current item. 
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	index			The index of the item
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 *
	 */
	result SetCurrentItemIndex(int index);

	/**
	 * Gets the total number of items.
	 *
	 * @since	2.0
	 * @return	The total number of items, @n
	 *			else @c -1 if an error occurs
	 */
	int GetItemCount(void) const;
	
	/**
	 * Refreshes the item at the specified index.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]	itemIndex    			The index of the item to be refreshed
	 * @param[in]	type			The type of change for an item
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_OUT_OF_RANGE	The specified @c index is out of range.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_INVALID_OPERATION The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	result RefreshGallery(int itemIndex, GalleryRefreshType type);

	/**
	 * Updates all the items of a list.
	 *
	 * @since 	  2.0
	 * @return    An error code
	 *
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception E_INVALID_STATE      This instance is in an invalid state.
	 * @exception E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception E_SYSTEM             A system error has occurred.
	 * @remarks   This method clears items in the list and reinvokes methods of the item provider to fill the list.
	 */
	result UpdateGallery(void);

	/**
	 * Sets the text of the empty %Gallery control.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]   text    			The text of the empty %Gallery control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 */
	result SetTextOfEmptyGallery(const Osp::Base::String &text);

	/**
	 * Get the text of the empty %Gallery control.
	 *
	 * @since 		2.0
	 * @return		The text of the empty %Gallery control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Base::String GetTextOfEmptyGallery(void) const;

	/**
	 * Sets the background bitmap of the %Gallery control.
	 *
	 * @since 		2.0
	 * @param[in] 	pBitmap				The bitmap of the empty %Gallery control
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		When @c pBitmap is @c null, the %Gallery control does not have a background bitmap. The default value for the background bitmap is @c null.
	 * @remarks		The background bitmap has a priority over the background color. When both the background bitmap and the background color are specified, 
	 *				only the bitmap is displayed.
	 */
	result SetBitmapOfEmptyGallery(const Osp::Graphics::Bitmap* pBitmap);

	/**
	 * Sets the slide show transition animation type.
	 *
	 * @since 		2.0
	 * @param[in] animation                The animation type of the %Gallery control
	 * @exception E_SUCCESS                The method is successful.
	 * @exception E_INVALID_STATE          This instance is in an invalid state.
	 * @exception E_UNSUPPORTED_OPERATION  This operation is not supported.
	 * @exception E_SYSTEM                 A system error has occurred.
	 *
	 * @remarks   The method is not supported in 16-bit devices.
	 */
	result SetSlideShowAnimation(GalleryAnimation animation);

	/**
	 * Gets the transition animation type of the slide show.
	 *
	 * @since 		2.0
	 * @return    The animation type of a %Gallery control
	 * @exception E_SUCCESS                The method is successful.
	 * @exception E_INVALID_STATE          This instance is in an invalid state.
	 * @exception E_UNSUPPORTED_OPERATION  This operation is not supported.
	 * @exception E_SYSTEM                 A system error has occurred.
	 *
	 * @remarks   The specific error code can be accessed using the GetLastResult() method.
	 * @remarks   The method is not supported in 16-bit devices.
	 */
	GalleryAnimation GetSlideShowAnimation(void) const;

	/**
	 * Sets the duration of the slide show transition animation.
	 *
	 * @since 		2.0
	 * @param[in] 	duration	The animation duration
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE		The specified @c duration is out of the possible duration range. @n
	 * 				The specified duration should be greater than or equal to 300 or less than or equals to 20000.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The unit of the duration is in milliseconds.@n 
	 * 				The default animation duration is different for each slide show animation type.
	 */
	result SetSlideShowAnimationDuration(int duration);

	/**
	 * Gets the transition animation duration of the %Gallery control.
	 *
	 * @since 		2.0
	 * @return     	The animation duration, @n
	 *     	        else @c -1 if an error occurs
	 * @exception	E_SUCCESS		The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM		A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	int GetSlideShowAnimationDuration(void) const;

	/**
	 * Sets the duration of the slide-show item view.
	 *
	 * @since		2.0
	 * @param[in]	duration		The item view duration
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_OUT_OF_RANGE  The specified @c duration is out of possible duration range. @n
	 *								- The specified @c duration should be greater than 10. 
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The unit of the duration is in milliseconds.@n 
	 * 				The default animation duration is different for each slide show animation type.
	 */
	result SetSlideShowViewDuration(int duration);

	/**
	 * Gets the duration of the slide-show item view.
	 *
	 * @since		2.0
	 * @return		The item view duration, @n
	 *				else @c -1 if an error occurs
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks		The specific error code can be accessed using @c GetLastResult() method.
	 */
	int GetSlideShowViewDuration(void) const;

	/**
	 * Starts the slide show.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]   repeat			     The repeat status
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	     This instance is in an invalid state.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM		     A system error has occurred.
	 */
	result StartSlideShow(bool repeat = false);
	
	/**
	 * Stops the slide show.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	     This instance is in an invalid state.
	 * @exception   E_INVALID_OPERATION  The current state of the instance prohibits the execution of the specified operation.
	 * @exception	E_SYSTEM		     A system error has occurred.
	 */
	result StopSlideShow(void) const;

	/**
	 * Checks whether the slide show has started.
	 *
	 * @since		2.0
	 * @return		@c true if the slide show is running, @n
	 * 				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsSlideShowStarted(void) const;
	
	 /**
	 * Enables or disables the image zooming.
	 *
	 * @since 		2.0
	 * @return		An error code
	 * @param[in]   enable	   			Set to @c true to enable zooming, @n
	 *									else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remark		When enabled, the user can enter the zoom mode by double-clicking or pinching the current image.
	 */
	result SetZoomingEnabled(bool enable);
	
	/**
	 * Checks whether zooming is enabled.
	 *
	 * @since 		2.0
	 * @return		@c true if zooming is enabled, @n
	 * 				else @c false
	 * @exception	E_SUCCESS			The method is successful.
	 * @exception	E_INVALID_STATE	This instance is in an invalid state.
	 * @exception	E_SYSTEM			A system error has occurred.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	bool IsZoomingEnabled(void) const;

	/**
	 * Sets the background color of the %Gallery control.
	 *
	 * @since       2.0
	 * @return      An error code
	 * @param[in]   color   The background color
	 * @exception   E_SUCCESS              	The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @exception   E_SYSTEM              	A system error has occurred.
	 * @remarks     The method ignores the alpha value of the @c color parameter and sets the alpha value to 255.
	 */
	result SetBackgroundColor(const Osp::Graphics::Color& color);

	/**
	 * Gets the background color of the %Gallery control
	 *
	 * @since       2.0
	 * @return      The background color, @n
	 *              else RGBA(0, 0, 0, 0) if an error occurs
	 * @exception   E_SUCCESS			The method is successful.
	 * @exception   E_INVALID_STATE	This instance is in an invalid state.
	 * @remarks     The specific error code can be accessed using the GetLastResult() method.
	 */
	Osp::Graphics::Color GetBackgroundColor(void) const;

protected:
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
	 * Frees the resources allocated by the Frame.
	 *
         * @since         1.0
	 * @return		An error code
	 * @exception	E_SUCCESS The method is successful.
	 * @exception	E_SYSTEM Failed to free the resource possessed by this instance.
	 */
	virtual result Dispose(void);

protected:	
	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void Gallery_Reserved1 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void Gallery_Reserved2 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void Gallery_Reserved3 (void) {}

	/**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void Gallery_Reserved4 (void) {}

    /**
	 * @internal
	 * This method is for internal use only. The bada platform team is not
	 * responsible for any behavioral correctness, consistency, and
	 * security-related issues that might arise after using this method.
	 *
	 * The following method is reserved, and their names can be changed
	 * at any time without prior notice.
	 *
	 * @since      2.0
	 */
    virtual void Gallery_Reserved5 (void) {}
	
private:
	friend class GalleryEx;
	/**
     * @internal    
     * This value is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this value.
	 *
	 * The internal data structure.
     * @since         2.0
     */		
	class GalleryEx* __pGalleryEx;

protected:
	friend class GalleryImpl;
	/**
     * @internal    
     * This method is for internal use only. The bada platform team is not 
	 * responsible for any behavioral correctness, consistency, and 
	 * security-related issues that might arise after using this method.
	 *
     * Gets the implementation instance of the Gallery
     *
     * @since         2.0
     */
	class GalleryImpl* GetImpl(void) const;
};

}; }; }; // Osp::Ui::Controls
#endif // _FUICTRL_GALLERY_H_
