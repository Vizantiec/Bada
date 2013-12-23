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
 * @file		FLocLandmarkPropertySelector.h
 * @brief		This is the header file for the LandmarkPropertySelector class.
 *
 * This header file contains the declarations of the LandmarkPropertySelector class.
 *
 */

#ifndef	_FLOC_LANDMARK_PROPERTY_SELECTOR_H_
#define _FLOC_LANDMARK_PROPERTY_SELECTOR_H_

#include "FLocationConfig.h"

// forward declaration - SC classes
struct MLandmarkPropertySelector;

namespace Osp { namespace Locations { 

/**
* @class	LandmarkPropertySelector
* @brief	This class selects the properties of the specified landmarks that are to be filled from the landmark store.
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %LandmarkPropertySelector class selects the properties of the specified landmarks that are to be filled from the landmark store.
* An application can select which properties of the specified landmarks to use, such as name, description, coordinates, address,
* author, coverage area, list of extra information, and list of URLs. @n
* From bada API version 1.2, when a landmark is retrieved from the landmark store, its priority property is always filled.
*
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/landmarks.htm">Landmarks</a>.
*/
class _EXPORT_LOCATION_ LandmarkPropertySelector :
	public Osp::Base::Object{
public:
	/**
	* This is the default constructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	LandmarkPropertySelector(void);

	/**
	* This is the copy constructor for the %LandmarkPropertySelector class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	LandmarkPropertySelector(const LandmarkPropertySelector& value);

	/**
	* This operator assigns the value of the specified %LandmarkPropertySelector instance to the current instance.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	LandmarkPropertySelector& operator=(const LandmarkPropertySelector& rhs);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	~LandmarkPropertySelector(void);

   /**
    * Sets the categories selector for the landmarks.
    *
	* @deprecated	This method is deprecated.
    * @since		1.2
    * @param[in]	select	Set to @c true if the categories are required, @n
    *						else @c false
    */
    void SetCategoriesSelector(bool select);

	/**
	* Sets the description selector for the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the description is required, @n
	*						else @c false
	*/
	void SetDescriptionSelector(bool select);

	/**
	* Sets the coordinates selector for the landmarks. @n
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the coordinates are required, @n
	*						else @c false
	*/
	void SetQualifiedCoordinatesSelector(bool select);

	/**
	* Sets the address selector for the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the address is required, @n
	*						else @c false
	*/
	void SetAddressInfoSelector(bool select);

	/**
	* Sets the author selector for the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the author is required, @n
	*						else @c false
	*/
	void SetAuthorSelector(bool select);

	/**
	* Sets the coverage area selector for the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the coverage area is required, @n
	*						else @c false
	*/
	void SetGeographicAreaSelector(bool select);

	/**
	* Sets the extra information selector for the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the extra information is required, @n
	*						else @c false
	*/
	void SetExtraInfoSelector(bool select);

	/**
	* Sets the URL selector for the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	select	Set to @c true if the URL is required, @n
	*						else @c false
	*/
	void SetUrlSelector(bool select);

private:
	MLandmarkPropertySelector*	__pMLandmarkPropertySelector;
friend class LandmarkStore;
friend class RemoteLandmarkStore;
friend class __RemoteLandmarkStoreHelper;

private:
	friend class LandmarkPropertySelectorEx;
	class LandmarkPropertySelectorEx* __pLandmarkPropertySelectorEx;
};

} }	// Osp::Location

#endif	// _FLOC_LANDMARK_PROPERTY_SELECTOR_H_
