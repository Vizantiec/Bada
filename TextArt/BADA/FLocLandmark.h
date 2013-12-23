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
 * @file		FLocLandmark.h
 * @brief		This is the header file for the Landmark class.
 *
 * This header file contains the declarations of the Landmark class.
 *
 */

#ifndef	_FLOC_LANDMARK_H_
#define _FLOC_LANDMARK_H_

#include "FLocationConfig.h"
#include "FBaseObject.h"
#include "FBaseString.h"
#include "FBaseColIList.h"
#include "FLocQualifiedCoordinates.h"
#include "FLocAddressInfo.h"
#include "FLocGeographicArea.h"

// Forward declaration
struct StringPair;
typedef StringPair MUrlInfo;
struct MLandmark;

namespace Osp { namespace Locations { namespace Services { class __XmlProcessor; }; }; };

namespace Osp { namespace Locations { 

/**
* The Landmark ID
*
* @deprecated	This type is deprecated.
* @since	1.0
*/
typedef long	LandmarkId;
#define INVALID_LANDMARK_ID	-1L

/**
* The lowest value for a landmark priority. @n
* A landmark is considered less important if the priority value is closer to @c 20.
*
* @deprecated	This constant is deprecated.
* @since	1.2
*/
static const int    LOWEST_LANDMARK_PRIORITY = 20;

/**
* The highest value for a landmark priority. @n
* A landmark is considered more important if the priority value is closer to @c 1.
*
* @deprecated	This constant is deprecated.
* @since	1.2
*/
static const int    HIGHEST_LANDMARK_PRIORITY = 1;

/**
* The default value for a landmark priority. @n
* If an application does not set the priority explicitly, a landmark has the lowest priority.
*
* @since	1.2
*/
static const int    DEFAULT_LANDMARK_PRIORITY = LOWEST_LANDMARK_PRIORITY;

/**
* @class	Landmark
* @brief	This class represents a landmark, such as a known location with a name that is known to the end user. 
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %Landmark class represents a landmark, such as a known location with a name that is known to the end user. It also has other parameters, such as textual description, coordinates, address, timestamp of the last modification, area 
* covered, author, additional information, and URLs as additional content. From version 1.2, a new property, Priority, is added to the %Landmark 
* class.
* 
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/landmarks.htm">Landmarks</a>.
*/
class _EXPORT_LOCATION_ Landmark :
public Osp::Base::Object{

// URL information of a landmark
public:
/**
* @class	UrlInfo
* @brief 	This class holds a URL and its description.
* @deprecated	This class is deprecated.
* @since	1.0
*
* The %UrlInfo class represents the URL information of a landmark holding a URL and its description. The URL can be a %Web address or a URL to a local file 
* that contains more content related to the landmark. The description contains additional information about the URL. The description is meant for 
* the user. If a landmark has links to additional information, the application constructs a list of %UrlInfo instances and calls the 
* Landmark.SetUrl() method with the list.
*
*  
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/landmarks.htm">Landmarks</a>.
*/
	class _EXPORT_LOCATION_ UrlInfo :
	public Osp::Base::Object{
	private:
		UrlInfo(void);
	public:
		/**
		* Initializes this instance of %UrlInfo with the specified parameters.
		*
		* @deprecated	This method is deprecated.
		* @since		1.0
		* @param[in]	url			The URL value of this URL information
		* @param[in]	description	The description value of this URL information
		*/
		UrlInfo(const Osp::Base::String& url, const Osp::Base::String& description);
		
		/**
		* This is the copy constructor for the %UrlInfo class.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		*/
		UrlInfo(const UrlInfo& value);
		
		/**
		* This operator assigns the value of the %UrlInfo instance to the current instance.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		*/
		UrlInfo& operator=(const UrlInfo& rhs);

		/**
		* This is the destructor for this class.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		*/
		virtual ~UrlInfo(void);

		/**
		* Gets the URL value. @n
		* The URL can be a %Web address or the URL to a local file that contains more content related to the landmark.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		* @return	The URL of the URL information
		*/
		Osp::Base::String GetUrl(void) const;

		/**
		* Gets the description value.
		* The description contains additional information about the URL.
		*
		* @deprecated	This method is deprecated.
		* @since	1.0
		*
		* @return	description		The description of the URL information
		*/
		Osp::Base::String GetDescription(void) const;

	private:
        /**
         * @internal
         * This method is for internal use only. The bada platform team is not
         * responsible for any behavioral correctness, consistency, and
         * security-related issues that might arise after using this method.
         *
		* @deprecated	This method is deprecated.
         * @since   1.0
         */
		UrlInfo(MUrlInfo* pObject);

	// attribute
	private:
		MUrlInfo*	__pMUrlInfo;
	friend class Landmark;
	friend class _LocationUtil;

    private:
        friend class UrlInfoEx;
        class UrlInfoEx* __pUrlInfoEx;
	};

// Lifecycle
private:
    /**
     * @internal
     * This method is for internal use only. The bada platform team is not
     * responsible for any behavioral correctness, consistency, and
     * security-related issues that might arise after using this method.
     *
	 * @deprecated	This method is deprecated.
     * @since   1.0
     */
	Landmark(MLandmark* pObject);

// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* It constructs an instance of %Landmark with the default name, "landmark".
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	Landmark(void);

	/**
	* Initializes this instance of the %Landmark with the specified parameter.
	*
	* It constructs a %Landmark object with the specified name.
	*	
	 * @deprecated	This method is deprecated.
	* @since			1.0
	*
	* @param[in]	name	The name of the landmark
	*/
	Landmark(const Osp::Base::String& name);

	/**
	* This is the copy constructor for the %Landmark class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	Landmark(const Landmark& value);

	/**
	* This operator assigns the value of the %Landmark object to the current instance.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	Landmark& operator=(const Landmark& rhs);

	/**
	* This is the destructor for this class.
	*
	 * @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual	~Landmark(void);

// Operations - Osp::Base::Object
public:

	/**
	* Compares the equality of values in two %Landmark objects. @n
	* Two %Landmark objects are equal if the landmark fields are equal. The timestamp and landmark store name are not taken into account in the field 
	* comparisons.
	*	
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		@c true if all the fields in the objects are equal, @n
	*				else @c false
	* @param[in]	obj		The object with which the comparison is done
	*/
	virtual bool Equals(const Osp::Base::Object& obj) const;

	/** 
	* Gets the hash value of the current instance by overriding the GetHashCode() method in the Object class.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The hash value of the current instance
	*/
	virtual int GetHashCode(void) const;

// Operations - Osp::Locations::Landmark
public:
	
	/**
	* Gets the address information of the specified landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The address information of the landmark @n
	*				else @c null if it is not available
	* @see			SetAddressInfo()
	*/
	const	AddressInfo*	GetAddressInfo(void) const;

	/**
	* Gets the name of the author who developed the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The name of the author who developed the landmark, @n
	*				else an empty string if the author name is not set
	* @see			SetAuthor()
	*/
	Osp::Base::String	GetAuthor(void) const;

	/**
	* Gets the categories of the landmark according to the time specified on the timestamp of the %Landmark instance cached in the device. The categories are 
	* specific to the landmark store to which the %Landmark instance belongs. If the landmark does not belong to any landmark store or no category is 
	* assigned to it, @c null is returned. While the LandmarkStore.GetCategoriesOfLandmarkN() method gives
	* the up-to-date categories information, the %Landmark instance delivers a snapshot of the information. An application takes advantage of the 
	* quick-and-dirty way of accessing the landmark categories with this method, but it could be outdated.
    *
	 * @deprecated	This method is deprecated.
    * @since	1.2
	*
    * @return	A list of categories of the landmark, @n
    *			else @c null if the landmark does not belong to any landmark store or is not added to any category
    * @see		GetTimestamp(), GetLandmarkStoreName()
    */
  const    Osp::Base::Collection::IList*          GetCategories(void) const;

	/**
	* Gets the description of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The description of the landmark, @n
	*				else an empty string if the description is not available
	* @see			SetDescription()
	*/
	Osp::Base::String GetDescription(void) const;

	/**
	* Gets extra information about the landmark. The returned list consists of the string equivalent of the additional landmark information items set in the 
	* same order as they were set by the application in the constructor or with the SetExtraInfo() method. If @c null or an empty list is used in the 
	* setter, @c null is returned.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		A list of the additional landmark information, @n
	*				else @c null if no extra information has been set
	* @see			SetExtraInfo()
	*/
	const	Osp::Base::Collection::IList*	GetExtraInfo(void) const;

	/**
	* Gets the coverage area of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility 	This method has compatibility issues with different bada API versions. @n
    *                   For more information, see issues in version @ref CompLandmarkGetGeographicAreaPage "1.2" and see 
	*					@ref CompLandmarkGetGeographicArea2Page "2.0".
    *
	* @return			The coverage area of the landmark  @n
	*					else @c null if the coverage area has not been set
	* @see				SetGeographicArea()
	*/
	const	GeographicArea*	GetGeographicArea(void) const;

	/**
	* Gets the ID of the landmark. @n
	* The landmark ID is unique in a landmark store and is available only if the landmark belongs to a landmark store. The name of the landmark store, to 
	* which the specified landmark instance currently belongs, is obtained by the GetLandmarkStoreName() method.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The ID of the landmark in the landmark store, @n
	*				else INVALID_LANDMARK_ID(= -1) if the landmark does not belong to any landmark store	
	* @see			GetLandmarkStoreName()
	*/
	LandmarkId		GetLandmarkId(void) const;

	/**
	* Gets the name of the landmark store to which the specified landmark instance currently belongs. @n 
	* If the landmark belongs to the default landmark store, this method returns the name of the default store, that is, @c null. If this landmark
	* does not belong to a landmark store, an empty @c string is returned.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The name of the landmark store this landmark belongs to, @n
	*				else an empty string if the landmark does not belong to any landmark store	
	* @see			GetLandmarkId()
	*/
	const	Osp::Base::String*	GetLandmarkStoreName(void) const;

	/**
	* Gets the name of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The name of the landmark
	* @see			SetName()
	*/
	Osp::Base::String	GetName(void) const;

  /**
	* Gets the priority of the landmark.
	*
	 * @deprecated	This method is deprecated.
    * @since        1.2
	*
	* @return		The priority of the Landmark @n
    *               DEFAULT_LANDMARK_PRIORITY, if a priority has not been set
	* @see			SetPriority()
	*/
    int     GetPriority(void) const;

	/**
	* Gets the qualified coordinates of the landmark. @n
	* If a coverage area has been set for this landmark but the coordinates have not been set with the SetQualifiedCoordinates() method, this method returns 
	* the center point of the GeographicArea set as the coverage area. In this case, the horizontal and vertical accuracies in the %QualifiedCoordinates  
	* class are set to @c 0.
    *
	 * @deprecated	This method is deprecated.
    * @since			1.0
    * @compatibility    This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
    *                   For more information, see @ref CompLandmarkGetQualifiedCoordinatesPage "here".
	*
	* @return		The qualified coordinates of the landmark, @n
	*				else @c null if the coordinates are not available
	* @see			SetQualifiedCoordinates()
	*/
	const	QualifiedCoordinates*	GetQualifiedCoordinates(void) const;

	/**
	* Gets the timestamp of the landmark. @n
	* The timestamp indicates the time when the landmark information is last modified. The timestamp is updated by the bada API implementation. The 
	* timestamp must be updated when a new %Landmark instance that does not belong to the landmark store is created, or when a landmark field is updated to a 
	* value different from what the Get* method returned. Creating a %Landmark instance that does not belong to any landmark store means that an application 
	* constructs a new %Landmark instance with the constructor. @n
	*
	* When landmarks are added to a landmark store or updated in a landmark store, the timestamp is updated. The time returned is the UTC time in milliseconds.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		The time of the last update on the landmark data
	*/
	long long	GetTimestamp(void) const;

	/**
	* Gets a %UrlInfo list that contains the URLs and their descriptions. @n
	* The URL can be a %Web address or a URL to a local file that contains more content related to the %Landmark instance. The descriptions contain additional
	* information about the URL and may be shown to the user. The returned list contains the URLs and descriptions pairs in the same order as they were set 
	* by the application in the constructor or with the SetUrl() method. If @c null or an empty list is used in the setter or in the constructor, @c null is 
	* returned.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		A list of %UrlInfo, @n
	*				else @c null if no URL information has been set
	* @see			SetUrl()
	*/
	const	Osp::Base::Collection::IList*	GetUrl(void) const;

	/**
	* Sets the address information of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @param[in]	pAddressInfo	The address information of the landmark instance, @n
	*								else @c null if the address information is not available
	* @see				GetAddressInfo()
	*/
	void	SetAddressInfo(const AddressInfo* pAddressInfo);

	/**
	* Sets the author of the landmark data.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @param[in]	author		The author of the %Landmark instance, @n
	*							else an empty string if the author information is not available
	* @see			GetAuthor()
	*/
	void	SetAuthor(const Osp::Base::String& author);

	/**
	* Sets the description of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @param[in]	description		The description of the landmark instance, @n
	*								else an empty string if the description is not available
	* @see				GetDescription()
	*/
	void	SetDescription(const Osp::Base::String& description);

	/**
	* Sets the additional information related to the landmark. @n
	* This information can be the speed of the landmark, the heading of the landmark, and so on. The landmark may have a special meaning when facing a 
	* certain direction. Or the landmark may contain information about the speed limit at that point. The additional information is a string list. Passing 
	* the @c null value indicates no additional information is available.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @return		An error code
	* @param[in]	pExtraInfoList	The additional information for the landmark, @n
	*								else @c null if no additional information is available
	* @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG 	The specified @c pExtraInfoList is empty or does not contain string elements.
	* @see				GetExtraInfo()
	*/
	result	SetExtraInfo(const Osp::Base::Collection::IList* pExtraInfoList);

	/**
	* Sets the coverage area for the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @param[in]	pGeographicArea		The area the landmark covers @n
	*									else @c null if the area information is not available
	* @see			GetGeographicArea()
	*/
	void	SetGeographicArea(const GeographicArea* pGeographicArea);

	/**
	* Sets the name of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @param[in]	name		The name of the landmark
	* @see				GetName()
	*/
	void	SetName(const Osp::Base::String& name);

  /**
	* Sets the priority of the landmark. @n
    * A landmark priority is an integer value that represents the degree of importance. An application sets and utilizes this property to get important or 
	* noticeable landmarks.
	*
	 * @deprecated	This method is deprecated.
    * @since      	1.2
	*
	* @return		An error code
	* @param[in]	priority    	The priority of the landmark
    * @exception	E_SUCCESS		The method is successful.
	* @exception	E_INVALID_ARG 	The specified @c priority is not an integer in the range [#HIGHEST_LANDMARK_PRIORITY, #LOWEST_LANDMARK_PRIORITY].
	* @see				GetPriority()
	*/
	result  SetPriority(int priority);

	/**
	* Sets the qualified coordinates of the landmark.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	*
	* @param[in]	pCoordinates 	The qualified coordinates of the landmark, @n
	*								else @c null if the qualified coordinates are not available
	* @see				GetQualifiedCoordinates()
	*/
	void	SetQualifiedCoordinates(const QualifiedCoordinates* pCoordinates);

	/**
	* Sets the URLs and their descriptions for a landmark. @n
	* The URL can be a %Web address or a URL to a local file that contains more content related to the landmark. The description contains additional 
	* information about the URL, and is meant for the user. The URLs and descriptions are given as a list of %UrlInfo. @n
	*
	* If the URL in the pair is an empty string, E_INVALID_ARG is thrown. If it does not have a description, an empty string must be used. Passing the 
	* @c null value indicates that the URL and the description information are not available.
    *
	 * @deprecated	This method is deprecated.
    * @since			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
    *                   For more information, see @ref CompLandmarkSetUrlPage "here".
	*
	* @return			An error code
	* @param[in]		pUrlList		A list of %UrlInfo for the landmark, @n
    *									else @c null if no %UrlInfo is available
	* @exception		E_SUCCESS		The method is successful.
	* @exception		E_INVALID_ARG 	The specified @c pUrlList has an empty string URL element, or @n
    *									the list is empty or is not made of %UrlInfo.
	* @see				GetUrl()	
	*/
	result	SetUrl(const Osp::Base::Collection::IList* pUrlList);


private:
	AddressInfo*					__pAddressInfo;
	Osp::Base::Collection::IList*	__pExtra;
	GeographicArea*					__pGeographicArea;
	Osp::Base::String*			__pStoreName;
	QualifiedCoordinates*			__pQualifiedCoordinates;
	Osp::Base::Collection::IList*	__pUrl;
	MLandmark*						__pMLandmark;
	
friend class LandmarkStore;
friend class __LandmarkEnumerator;
friend class _LocationUtil;
friend class RemoteLandmarkStore;
friend class __RemoteLandmarkStoreHelper;
friend class Services::__XmlProcessor;

private:
	friend class LandmarkEx;
	class LandmarkEx* __pLandmarkEx;

/**
 * @page    CompLandmarkSetUrlPage	Compatibility for SetUrl()
 *
 * @section CompLandmarkSetUrlPageIssueSection	Issues 
 * Implementation of this method in bada API versions prior to 1.1 has the following issues: @n
 * -# If @c pUrlList contains at least one %UrlInfo item whose URL or description field is an empty string, this method returns without any operation.
 * -# If an empty URL is encountered, it returns E_SUCCESS as the result code.
 *
 * @section	CompLandmarkSetUrlPageSoluctionSection	Resolutions
 * The issues mentioned above are resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n
 *
 * @par 
 * When working with bada API versions prior to 1.1:
 * The application should fill both the URL and description of %UrlInfo with nonempty strings when it constructs a list of UrlInfo. @n
 *
 */

/** 
* @page	CompLandmarkGetGeographicAreaPage	Compatibility for GetGeographicArea()
*
* @section	CompLandmarkGetGeographicAreaIssueSection	Issues 
* Implementation of this method in bada API versions prior to 1.2 has the following issue: @n 
*  If a landmark is retrieved from the landmark store and has a geographic area of rectangle or polygon type, the area returned by this method does not 
* contain the correct information about the geographic area of the landmark. 
* 
* @section	CompLandmarkGetGeographicAreaSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 1.2 and it is recommended to use bada API version 1.2 or above. @n
*
* @par 
* When working with bada API versions prior to 1.2:
* An application should not use a rectangular or polygonal geographic area as the geographic area of the landmark with the aim of keeping it in the landmark 
* store. It should take a circular area to be able to store and retrieve the area information of the landmark.
*/

/** 
* @page	CompLandmarkGetQualifiedCoordinatesPage	Compatibility for GetQualifiedCoordinates()
* @section	CompLandmarkGetQualifiedCoordinatesIssueSection	Issues
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
*  If the coverage areas have been set several times for a landmark but the coordinates have not been set using the SetQualifiedCoordinates() method, the 
* method returns the center point of the first coverage area.
*
* @section	CompLandmarkGetQualifiedCoordinatesSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* If an application uses a coverage area instead of setting the coordinates for specifying the location of a landmark, it should set the center point of the 
* coverage area by calling the SetQualifiedCoordinates() method to get the correct result, when the GetQualifiedCoordinates() method is called.
*/

/** 
* @page	CompLandmarkGetGeographicArea2Page	Compatibility for GetGeographicArea()
* @section	CompLandmarkGetGeographicAreaIssue2Section	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
*  If a landmark is retrieved from the remote landmark store and has a polygonal or rectangular geographic area, the area returned by this method does not 
* contain the correct information. 
* 
* @section	CompLandmarkGetGeographicAreaSolution2Section	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should not use the polygonal or rectangular geographic area of a landmark if they are retrieved from the remote landmark store.
*/

};	// class Landmark

} }	// Osp::Location


#endif	// _FLOC_LANDMARK_H_
