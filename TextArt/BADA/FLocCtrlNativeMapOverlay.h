/* $Change: 1267243 $ */
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
* @file		FLocCtrlNativeMapOverlay.h
* @brief	This is the header file for the %NativeMapOverlay interface.
*
* This header file contains the declarations of the %INativeMapOverlay interface.
*/
#ifndef _FUI_CTRL_IMAPVIEW_OVERLAY_CONTROL_H_
#define _FUI_CTRL_IMAPVIEW_OVERLAY_CONTROL_H_

#include <FLocCtrlIMapOverlay.h>
#include <FBaseObject.h>

namespace Osp { namespace Locations { namespace Controls { class Map; }; }; };


namespace Osp { namespace Locations { namespace Controls {
class __INativeMapOverlay;

/**
* @class	NativeMapOverlay
* @brief	This class is used to implement a %NativeMapOverlay control.
* @deprecated	This class is deprecated.
* @since	1.0
*
* 			The %NativeMapOverlay class is used to implement a %NativeMapOverlay control by providing the functionalities for creating overlays that are rendered on a map in 
*			addition to the basic functionalities provided by IMapOverlay. All the overlays must inherit this class to work as an overlay on the map.
*
* 
* For more information on the class, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/overlays.htm">Overlays</a>.
*/


class _EXPORT_LOCATION_CONTROL NativeMapOverlay :
	public Osp::Base::Object, public IMapOverlay
{
protected:

	/**
	* This is the default constructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since 1.0
	*/
	NativeMapOverlay(void);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Copy the source data of NativeMapOverlay to destination
	*
	 * @deprecated	This method is deprecated.
	* @since 		2.0
	* @return		An error code
	* @param[in]	dest		The destination to be copied.
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_SYSTEM	The method has failed.
	*/
	result CopyData(__INativeMapOverlay& dest) const;

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Sets the implementation of the NativeMapOverlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		2.0
	* @param[in]	pOverlay		The instance of the implementation class
	*/
	void SetImplementation(__INativeMapOverlay* pOverlay) const;

public:

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual ~NativeMapOverlay(void);

	/**
	* Gets the Z order of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The Z order of the overlay
	*/
	virtual int GetZOrder(void) const;

	/**
	* Gets the priority of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The priority of the overlay
	*/
	virtual int GetPriority(void) const;

	/**
	* Gets the visibility of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The visibility of the overlay
	*/
	virtual bool GetShowState(void) const;

	/**
	* Checks whether shadow is enabled.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if shadow is enabled, @n
	*				else @c false
	*/
	virtual bool IsShadowEnabled(void) const;

	/**
	* Checks whether the overlay is highlighted.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		@c true if the overlay is highlighted, @n
	*				else @c false
	*/
	virtual bool IsHighlighted(void) const;

	/**
	* Gets the ID of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The ID of the overlay
	*/
	virtual int GetId(void) const;

	/**
	* Sets the Z order of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	zOrderNumber	The Z order of the overlay to be set
	*/
	virtual void SetZOrder(int zOrderNumber);

	/**
	* Sets the priority of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	priority	The priority of the overlay to be set
	*/
	virtual void SetPriority(int priority);

	/**
	* Sets the visibility of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable	Set to @c true to enable the visibility of the overlay, @n
	*						else @c false
	*/
	virtual void SetShowState(bool enable);

	/**
	* Sets the status of the shadow of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable	Set to @c true to enable the shadow, @n
	*						else @c false
	*/
	virtual void SetShadowEnabled(bool enable);

	/**
	* Sets the ID of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	id		The ID of the overlay to be set
	*/
	virtual void SetId(int id);

	/**
	* Sets the status of highlighting of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	enable	Set to @c true to highlight the overlay, @n
	 *						else @c false
	*/
	virtual void SetHighlighted(bool enable);

	/**
	* Gets the user information of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The user information of the overlay
	*/
	virtual const Osp::Base::Object* GetExtraInfo(void) const;

	/**
	* Sets the user information of the overlay.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	pExtraInfo	The user information to be set
	*/
	virtual void SetExtraInfo(const Osp::Base::Object* pExtraInfo);

	/**
	* @internal
	* This method is for internal use only.
	* The bada platform team is not responsible for any behavioral correctness, consistency and security-related issues
	* that might arise after using this method.
	*
	* Gets the instance of the implementation class.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @return	@c null, if NativeMapOverlay does not have an implementation, 
	*			otherwise the instance of the implementation class
	*/

	__INativeMapOverlay* GetImplementation(void) const;

protected:

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Z order of overlay.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	int								__zOrder;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Priority of overlay.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	int								__priority;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Determines the status of highlight enable or disable.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	bool							__bHilight;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* User information.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	Osp::Base::Object*				__pUserInfo;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Visibility of overlay.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	bool							__bVisible;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* ID of overlay.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	int								__id;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Determines the status of shadow enable or disable.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	bool							__bShadow;

	/**
	* @internal
	* This value is for internal use only. The bada platform team is not 
	* responsible for any behavioral correctness, consistency, and 
	* security-related issues that might arise after using this value.
	*
	* Map instance.
	*
	 * @deprecated	This variable is deprecated.
	* @since	1.0
	*/
	Osp::Locations::Controls::Map*		__pMap;

private:
	
	friend class Map;
	friend class NativeMapOverlayEx;
	class NativeMapOverlayEx* __pNativeMapOverlayEx;

};			// NativeMapOverlay

};};};		// Osp::Locations::Controls;

#endif		// _FUI_CTRL_IMAPVIEW_OVERLAY_CONTROL_H_
