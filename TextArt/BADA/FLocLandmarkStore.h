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
 * @file	FLocLandmarkStore.h 
 * @brief	This is the header file for the %LandmarkStore interface.
 *
 * This header file contains the declarations of the %LandmarkStore interface.
 */

#ifndef	_FLOC_LANDMARK_STORE_H_
#define _FLOC_LANDMARK_STORE_H_

#include "FLocationConfig.h"
#include "FBaseColIList.h"
#include "FBaseColIEnumerator.h"
#include "FBaseTypes.h"
#include "FLocILandmarkSearchListener.h"
#include "FLocLandmark.h"
#include "FLocLandmarkPropertySelector.h"
#include "FLocLandmarkFilter.h"

// Forward declaration
struct _ILandmarkStore;

namespace Osp { namespace Locations { 

// Forward declaration	
class Coordinates;
class AddressInfo;
class GeographicArea;
class Landmark;

// Enums and Constants
/**
 * @enum	SortBy
 * Defines the sorting criteria for the landmark search results.
 *
 * @deprecated	This enumerated type is deprecated.
 * @since	1.0
 */
typedef enum {
	SORT_BY_NAME = 1,	/**< The constant for sorting the landmark search results by name of the landmark */
	SORT_BY_DESCRIPTION = 2,/**< The constant for sorting the landmark search results by description of the landmark */
	SORT_BY_DISTANCE = 4,	/**< The constant for sorting the landmark search results by distance of the coordinates given as a parameter in the method */
	SORT_BY_PRIORITY = 8,	/**< The constant for sorting the landmark search results by priority of the landmark @b Since: @b 1.2 */
} SortBy;

/** The constant for the global landmark category 'accommodation'. This category may contain hotels or camping sites.  
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	ACCOMMODATION			= L"gc_accommodation";

/** The constant for the global landmark category 'business'. This category may contain banks, factories, or offices. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	BUSINESS				= L"gc_business";

/** The constant for the global landmark category 'communication'. This category may contain Internet access points, public telephones, or wireless LAN hot 
*	spots.
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	COMMUNICATION			= L"gc_communication";

/** The constant for the global landmark category 'educational institutes'. This category may contain schools or colleges. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	EDUCATIONAL_INSTITUTE	= L"gc_educational_institute";

/** The constant for the global landmark category 'entertainment'. This category may contain cinemas, concert halls, or night clubs. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	ENTERTAINMENT			= L"gc_entertainment";

/** The constant for the global landmark category 'food and beverage'. This category may contain restaurants, bars, or cafes.  
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	FOOD_AND_BEVERAGE		= L"gc_food_and_beverage";

/** The constant for the global landmark category 'geographical areas'. This category may contain cities, towns, or city centers. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	GEOGRAPHICAL_AREA		= L"gc_geographical_area";

/** The constant for the global landmark category 'outdoor activities'. This category may contain camping sites or playgrounds. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	OUTDOOR_ACTIVITIES		= L"gc_outdoor_activities";

/** The constant for the global landmark category 'people'. This category may contain a parent's or a friend's house. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	PEOPLE					= L"gc_people";

/** The constant for the global landmark category 'public service'. This category may contain hospitals or libraries. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	PUBLIC_SERVICE			= L"gc_public_service";

/** The constant for the global landmark category 'religious places'. This category may contain churches or mosques. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	RELIGIOUS_PLACES		= L"gc_religious_places";

/** The constant for the global landmark category 'shopping'. This category may contain market places or shopping centers. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	SHOPPING				= L"gc_shopping";

/** The constant for the global landmark category 'sightseeing'. This category may contain museums or monuments. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	SIGHTSEEING				= L"gc_sightseeing";

/** The constant for the global landmark category 'sports'. This category may contain a golf course or an ice hockey hall. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	SPORTS					= L"gc_sports";

/** The constant for the global landmark category 'transport'. This category may contain bus stops or railway stations. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	TRANSPORT				= L"gc_transport";

/** The constant for the global landmark category user location. This category is used to indicate the location of the user. 
*
* @deprecated	This constant is deprecated.
* @since	1.0
*/
static const Osp::Base::String	USER_LOCATION			= L"gc_user_location";

/**
* @class	LandmarkStore
* @brief	This class provides the methods to store, delete, and retrieve landmarks from a persistent landmark store.
* @deprecated	This class is deprecated.
* @since	1.0
*
* @remarks  The %LandmarkStore class supports Unicode characters for the store name and textual fields of landmarks @b since: @b 2.0.
*           In the bada API versions prior to 2.0, some Unicode characters are not supported. @n
*           See the compatibility of the CreateLandmarkStore() and AddLandmark() methods for more details.
*
* This class provides the methods to store, delete, and retrieve landmarks from a persistent landmark store.
* The landmark store supports Unicode characters for the store name and textual fields of the landmarks @b since: @b 2.0.
*           In the bada API versions prior to 2.0, some Unicode characters are not supported.
*           See the compatibility of the CreateLandmarkStore() and AddLandmark() methods for more details.
* 			The landmark store can be a public one visible to all applications, or a private one visible to the creator application only. You can create and 
*			delete landmark stores using the CreateLandmarkStore() and DeleteLandmarkStore() methods.
* 
* 
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/landmarks.htm">Landmarks</a>.
* 
* The following example demonstrates how to use the %LandmarkStore class.
*
* @code
*
*   #include <FBase.h>
*   #include <FLocations.h>
*   
*   using namespace Osp::Base;
*   using namespace Osp::Locations;
*   
*   void
*   MyClass::LandmarkStoreExample(void)
*   {
*   	result                  r = E_SUCCESS;
*   	String                  storeName(L"MyStore");
*   	QualifiedCoordinates    location;
*   	Landmark                museum(L"Museum of Art");
*   	LandmarkStore           myStore;
*
*   	// 1. Creates a public landmark store of the name "MyStore".
*   	// Note that a named landmark store is unique for a target device. 
*   	// The application must use a unique name to avoid conflicts arising from duplicate names. 
*   	// Creating a landmark store fails if the name is already in use. 
*   	// To ensure uniqueness, an appropriate postfix can be added to the name.
*   	r = LandmarkStore::CreateLandmarkStore(storeName, true);
*   	if (IsFailed(r)) {
*   		AppLog("Failed to CreateLandmarkStore - %s.", GetErrorMessage(r));
*   		return;
*   	}
*
*   	// 2. Constructs the instance of the landmark store.
*   	r = myStore.Construct(&storeName);
*   	if (IsFailed(r)) {
*   		AppLog("Failed to Construct - %s.", GetErrorMessage(r));
*   		return;
*   	}
*
*   	// 3. Adds a landmark to the landmark store associating it with the global category SIGHTSEEING.
*   	location.Set(37.335084, 126.582571, 0.0, 0.0, 0.0);
*   	museum.SetQualifiedCoordinates(&location);
*   	r = myStore.AddLandmark(museum, &SIGHTSEEING);
*   	if (IsFailed(r)) {
*   		AppLog("Failed to AddLandmark - %s.", GetErrorMessage(r));
*   		return;
*   	}
*
*   	// 4. Updates the landmark.
*   	museum.SetDescription(L"My favorite museum");
*   	r = myStore.UpdateLandmark(museum);
*   	if (IsFailed(r)) {
*   		AppLog("Failed to UpdateLandmark - %s.", GetErrorMessage(r));
*   		return;
*   	}
*    
*   	// ...
*       
*   	// 5. Deletes the landmark.
*   	r = myStore.DeleteLandmark(museum);
*   	if (IsFailed(r)) {
*   		AppLog("Failed to DeleteLandmark - %s.", GetErrorMessage(r));
*   		return;
*   	}
*    
*   	// 6. Deletes the landmark store.
*   	r = LandmarkStore::DeleteLandmarkStore(storeName);
*   	if (IsFailed(r)) {
*   		AppLog("Failed to DeleteLandmarkStore - %s.", GetErrorMessage(r));
*   		return;
*   	}
*   }
*
* @endcode
* @{
*/
class _EXPORT_LOCATION_ LandmarkStore :
	public Osp::Base::Object{

// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	* 
	* The instance of %LandmarkStore should be initialized using the Construct() method in this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	* @see 		Construct()
	*/
	LandmarkStore(void);

	/**
	* Initializes this instance of %LandmarkStore with the specified name for storing, deleting, and retrieving landmarks.
    *
	* There is one default landmark store. However, there might be other landmark stores that can be accessed by their name.
	* Passing the @c null value for the store name constructs an instance of the default landmark store.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		An error code
	* @param[in]	pStoreName			The name of the landmark store to be opened, @n
	*									else @c null to construct the default landmark store 
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OBJ_NOT_FOUND 	The landmark store with the specified name is not found.
    * @exception	E_ILLEGAL_ACCESS 	The application does not have the permission to access the landmark stores.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_IO 				An I/O error has occurred.
	*/
	result Construct(const Osp::Base::String* pStoreName);

	/**
	* This is the destructor for this class.
	*
	* @deprecated	This method is deprecated.
	* @since	1.0
	*/
	virtual	~LandmarkStore(void);

private:
	// no implementation. force to private
	LandmarkStore(const LandmarkStore& value);
	LandmarkStore& operator=(const LandmarkStore& rhs);

// Operations - Osp::Locations::LandmarkStore
public:

	/**
	* Creates a new landmark store of the specified name with access restrictions. @n
	*
	* The application creating the landmark store decides whether it is a public or private store. @n
	* A public landmark store is visible to all applications, but only the creator can modify the store. @n
	* A private landmark store is only visible to the creator of the store. @n
  *
	* If the provided name is longer than 64 Unicode characters, this method returns the error code E_INVALID_ARG. @n
  *
  * If a landmark store of the specified name already exists, this method returns an E_INVALID_ARG exception. @n
  * The specified name might be already in use for a private landmark store of another application. In this case, 
  * the named landmark store is not visible to the application. @n
	* It is recommended that the application uses a unique name to avoid a name conflict by adding a postfix to the name.
	*
	* A newly created landmark store does not contain any landmarks. @n
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *					For more information, see @ref CompLandmarkStoreCreateLandmarkStorePage "here".
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	storeName			The name of the landmark store to be created
	* @param[in]	publicity			Set to @c true if the store is a public landmark store, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The length of the specified @c storeName is longer than @c 62, or @n
	*									or a landmark store with the specified @c storeName already exists.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks		A landmark store created by this method is stored on the predefined storage location on the device.
	*/
	static	result	CreateLandmarkStore(const Osp::Base::String& storeName, bool publicity);

	/**
    * Deletes a landmark store of the specified name. @n
	* All the landmarks and categories defined in the specified landmark store are permanently removed. @n
	*
	* This method does not return any errors, even if the specified landmark store does not exist. @n
	*
	* The name of the landmark store must be one of the names returned by GetAllLandmarkStoreNamesN(). The search is case sensitive.
    * 
	* @deprecated	This method is deprecated.
    * @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
    * @param[in]	storeName			The name of the landmark store to be deleted
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
    * @exception	E_IO 				An I/O error has occurred.
	* @exception	E_ILLEGAL_ACCESS 	The application does not have the permissions to delete the store.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	static	result	DeleteLandmarkStore(const Osp::Base::String& storeName);

	/**
	* Lists the names of all the landmark stores that the calling application has access to. @n
	* The list contains both public landmark stores and private landmark stores that have been created by the calling application. @n
	* 
	* The default landmark store is obtained from the Construct() method by passing @c null as the parameter. The @c null name for the default landmark store 
	* is not included in the list returned by this method. If there are no named landmark stores other than the default landmark store, this method returns 
	* @c null. @n
	*
	* The store names are returned in a form that is directly usable as input to Construct() and DeleteLandmarkStore() methods.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		A list of string that indicates landmark store names, @n
	*				else @c null if there are no named landmark stores other than the default landmark store
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_SERVICE_BUSY			The system is too busy to handle the request.
	* @exception	E_IO					An I/O error has occurred when accessing the landmark store.
	* @exception	E_OUT_OF_MEMORY			The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED		The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The application must delete the returned list.
	*/
	static	Osp::Base::Collection::IList*	GetAllLandmarkStoreNamesN(void);

	/**
	* Adds a category to this landmark store. @n
	* 
	* If an application tries to add a category that is the same as the name of the global landmark category (defined in the constants in this class), 
	* E_INVALID_ARG is returned. If the provided name is longer than 32 Unicode characters, it is added as a truncated string of 32 Unicode characters. @n
	*
	* As many as @c 100 categories can be stored in a store. If the number of categories in the store exceeds the limit, this method returns the error code 
	* E_MAX_EXCEEDED. There are some cases when this method returns E_IO, for example, when an I/O error occurs while accessing the landmark store.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                   For more information, see @ref CompLandmarkStoreAddCategoryPage "here".
    * 
    *
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	category			The category name to be added
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c category is an empty string, or a category with the same name already exists.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_MAX_EXCEEDED 		The number of categories in the landmark store has reached the maximum limit.
	* @exception	E_IO 				An I/O error has occurred while accessing the landmark store.
	* @exception	E_ILLEGAL_ACCESS 	The application does not have the permission to manage categories.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	AddCategory(const Osp::Base::String& category);

	/**
	* Adds a landmark to the specified category in the landmark store. @n
	*
	* If some textual field inside the landmark object (such as description or all the fields in the AddressInfo) is set to a value that is too long to be 
	* stored, the landmark store truncates the fields that are too long. Currently, the maximum length of the string that the landmark store supports is 100 
	* Unicode characters for the description and the URL, and 32 Unicode characters for other fields. However, the name and author fields of the landmark  
	* must not be truncated. Only those name and author fields that are 32 Unicode characters or shorter can be added to the landmark store. If an 
	* application tries to add a landmark with a name or author field longer than the 32 characters allotted to it, this method returns the error code 
	* E_INVALID_ARG. @n
	*
	* Currently, the landmark store supports 5 items for each URL and extra info lists. @n
	*
	* If the %Landmark instance (passed as a parameter) is an instance that belongs to this landmark store, the same %Landmark instance is added to the 
	* specified category, in addition to the categories to which it already belongs. If the landmark already belongs to the specified category, this method 
	* returns with no effect. If the landmark is deleted after it is obtained from the landmark store, it can be added again when this method is called. @n
	* 
	* If the %Landmark instance (passed as a parameter) is an instance initially constructed by the application using the constructor, or an 
	* instance that belongs to a different landmark store, a new landmark is created in this landmark store. It belongs initially to only the category 
	* specified in the category parameter. After this method is called, the %Landmark instance (passed as a parameter) belongs to this landmark store. @n
	*
	* If a landmark has to be added to more than one category, the additions must be done one by one with this method. Adding a landmark to any of the global 
	* landmark categories must be done using the constant global category names defined in this class. @n
	*
	* Calling this method updates the timestamp of the landmark. @n
	*
	* As many as 5000 landmarks can be stored in a landmark store. If the number of landmarks in the store exceeds the limit, this method returns the error 
	* code E_MAX_EXCEEDED. There are some cases when this method returns E_IO. For example, when an I/O error occurs while accessing the landmark store.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                   For more information, see @ref CompLandmarkStoreAddLandmarkPage "here".
	* @privlevel		NORMAL
	* @privgroup		LANDMARK
	*
	* @return			An error code
	* @param[in,out]	landmark			The instance of the %Landmark to be added
	* @param[in]		pCategory			The category where the %Landmark is added
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_INVALID_ARG 		The length of the name or author field of the specified @c landmark is longer than @c 32 characters, or @n
	*										the specified @c pCategory is not a category defined in this landmark store. 
	* @exception		E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	    E_MAX_EXCEEDED 		The number of landmarks in the landmark store has reached the maximum limit.
	* @exception		E_IO 				An I/O error has occurred while accessing the landmark store, or @n
	*										there are no resources available to store this landmark.
	* @exception		E_ILLEGAL_ACCESS 	The application does not have the permission to add landmarks.
	* @exception		E_INVALID_STATE 	This instance is in an invalid state.
	* @exception		E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception		E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	AddLandmark(Landmark& landmark, const Osp::Base::String* pCategory);

	/**
	* Changes the authorization mode of a private landmark store to public. @n
	* 
	* After calling the method, all the applications have access to the specified landmark store. If the given landmark store is already public, this method 
	* does not take any action. @n
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return			An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred while accessing the landmark store.
	* @exception	E_ILLEGAL_ACCESS 	The application does not have the permission to change the authorization mode of the store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	ChangeToPublic(void);

	/**
	* Removes a specified category from the specified landmark store. @n
	*
	* Global landmark categories cannot be removed. All the landmarks belonging to the removed category will no longer belong to the category after this 
	* method is called. This method does not remove any of the landmarks. This method does not return an error even if the specified category does not exist 
	* in the landmark store.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *					For more information, see @ref CompLandmarkStoreDeleteCategoryPage "here".
    *
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return			An error code
	* @param[in]	category	 		The name of the category to be removed
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c category is an empty string, or @n
	*									the specified @c category is one of the global landmark categories defined in the class.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred.
	* @exception	E_ILLEGAL_ACCESS 	The application does not have the permission to manage categories.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	DeleteCategory(const Osp::Base::String& category);

	/**
	* Deletes a specified landmark from the specified landmark store. @n
	*
	* Removes the specified landmark from all the categories and deletes the information from the landmark store. @n
	*
	* The Landmark instance (passed as a parameter) must be an instance that belongs to this landmark store. If the Landmark belongs to this landmark store 
	* but has already been deleted from this landmark store, then the request is ignored and the method call returns with no error. @n
	*
	* If the landmark instance does not belong to the specified landmark store, then E_LANDMARK is returned. "Not belonging" to the landmark store is 
	* different from "not being stored currently" in the landmark store. @n
	*
	* Calling this method updates the timestamp of the landmark. @n
	*
	* In some cases, the landmark store may be read-only, so no changes are allowed to it. In this case, this method returns E_IO.
	* 
	* @deprecated	This method is deprecated.
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		LANDMARK
	*
	* @return			An error code
	* @param[in,out]	landmark			The instance of the Landmark
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_LANDMARK 			The landmark does not belong to this landmark store.
	* @exception		E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception		E_IO 				An I/O error has occurred while accessing the landmark store.
	* @exception		E_ILLEGAL_ACCESS 	The application does not have the permission to delete the landmark.
	* @exception		E_INVALID_STATE 	This instance is in an invalid state.
	* @exception		E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception		E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	DeleteLandmark(Landmark& landmark);

	/**
	* Gets the category names that are defined in this landmark store. @n
	*
	* The returned list at least contains the global landmark categories as constants defined in this class. The global categories must be in the beginning 
	* of the list and in the same order as defined in the description of this package. 
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		A list of string objects representing the category names @n
	*				At least the global categories in the specified order are returned.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred while accessing the landmark store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The application must delete the returned list.
	*/
	Osp::Base::Collection::IList*	GetAllCategoriesN() const;

	/**
	* Gets the landmark categories for the specified landmark. @n
	* 
	* If the specified landmark does not belong to any landmark category, @c null is returned. If the specified landmark does not belong to this landmark 
	* store, E_LANDMARK is reported. If the landmark belongs to global categories, the names of those categories are returned as constants defined in this 
	* class. @n
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		A list of string objects that specify the categories of the landmark, @n
	*				else @c null if the landmark does not belong to any category
	* @param[in]	landmark			The landmark whose categories are queried
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred while accessing the landmark store.
	* @exception	E_LANDMARK 			The landmark does not belong to this landmark store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The application must delete the returned list.
	*/
	Osp::Base::Collection::IList*	GetCategoriesOfLandmarkN(const Landmark& landmark) const;

	/**
	* Gets a list of all the landmarks stored in the specified landmark store. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An enumerator of %Landmark instances that enumerates all the landmarks stored in the specified landmark store, @n
	*				else @c null if there are no landmarks in the landmark store
	* @param[in]	pSelector			The landmark property selector @n
	*									It may be @c null.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred while accessing the landmark store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The application must delete the returned enumerator.
	*/
	Osp::Base::Collection::IEnumerator*	GetAllLandmarksN(const LandmarkPropertySelector* pSelector) const;

	/**
	* Gets the landmark for the specified ID. @n
	*
	* The landmarkId is the unique key that the application needs to access the landmark. If the landmark store does not have such landmark corresponding to 
	* the specified ID, this method returns @c null. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks.
    *
	* @deprecated	This method is deprecated.
    * @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		The requested landmark, @n 
	*				else @c null if the landmark cannot be found
	* @param[in]	landmarkId			The ID of the landmark that is unique in the landmark store
	* @param[in]	pSelector			The landmark property selector @n
	*									It may be @c null
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_ARG 		The specified @c landmarkId is equal to or less than INVALID_LANDMARK_ID (=-1).
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	* @remarks		The specific error code can be accessed using the GetLastResult() method.
	* @remarks		The application must delete the returned landmark.
	*/
	Landmark*	GetLandmarkN(LandmarkId landmarkId, const LandmarkPropertySelector* pSelector) const;

	/**
	* Searches the landmarks in the storage, where the category and name match the specified parameters. @n
	*
    * The category and name are handled in a case-sensitive manner and are matched exactly with the corresponding fields of the landmark.
    * 
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks. @n
	*
	* This method operates asynchronously, that is, it ends immediately without the search results. The application is notified when the searching 
	* is done, so the results are available via the ILandmarkSearchListener::OnLandmarkSearchResultReceivedN() method if this method returns E_SUCCESS. 
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *					For more information, see @ref CompLandmarkStoreSearchLandmarks2Page "here".
    *
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	pCategory			The category of the landmark @n
	*									@c null or an empty string implies a wildcard that matches all categories.
	* @param[in]	pName				The name of the desired landmark @n
	*									@c null or an empty string implies a wildcard that matches all the names within the category indicated by the 
	*									category parameter.
	* @param[in]	pSelector			The landmark property selector @n
	*									It may be @c null.
	* @param[in]	listener			The event listener
	* @param[out]	searchId			The ID of the search
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY		The system is too busy to handle the request.
	* @exception	E_IO				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_STATE		This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* The following example demonstrates how to search the landmarks.
	*
	* @code
	*
    *   #include <FBase.h>
    *   #include <FLocations.h>
    *   
    *   using namespace Osp::Base;
    *   using namespace Osp::Base::Collection;
    *   using namespace Osp::Locations;
    *
    *   class MyClass: public ILandmarkSearchListener
    *   {
    *   public:
    *   	MyClass(void);
    *   	~MyClass(void);
    *   	void LandmarkStoreExample(void);
    *   	void SearchLandmarksExample(void);
    *   	
    *   // ILandmarkSearchListener
    *   public:
    *       void OnLandmarkSearchResultReceivedN(SearchId searchId, IEnumerator* pResults, result r) {
    *       	if (IsFailed(r)){
    *       		AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
    *       	}
    *
    *           if (pResults) {
    *           	while(!IsFailed(pResults->MoveNext())) {
    *           	    const Landmark* item = static_cast<const Landmark*>(pResults->GetCurrent());
    *           		String name = item->GetName();
    *           		AppLog("Landmark Retrieved(%S).", name.GetPointer());
    *           	}
    *           	
    *           	delete pResults;
    *           }
    *       }
    *   };
    *
    *   void 
    *   MyClass::SearchLandmarksExample(void) {
    *   	result					r = E_SUCCESS;
    *   	SearchId				searchId;
    *   	String                  storeName(L"MyStore");
    *   	LandmarkStore			myStore;
    *
    *   	// 1. Constructs the instance of the landmark store.
    *   	r = myStore.Construct(&storeName);
    *   	if (IsFailed(r)) {
    *   		AppLog("Failed to Construct - %s.", GetErrorMessage(r));
    *   		return;
    *   	}
    *
    *   	// 2. Searches the landmarks categorized by the global category 'SIGHTSEEING'.
    *   	r = myStore.SearchLandmarks(&SIGHTSEEING, null, null, *this, searchId);
    *   	if (IsFailed(r)) {
    *   	    AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
    *   	} else {
    *   		AppLog("SearchLandmarks(%d) is started.", searchId);
    *   	}
    *   }
	*
	* @endcode
	*/
	result	SearchLandmarks(const Osp::Base::String* pCategory, const Osp::Base::String* pName, const LandmarkPropertySelector* pSelector, const ILandmarkSearchListener& listener, SearchId& searchId) const ;

	/**
	* Searches all the landmarks that are within an area defined by the specified minimum and maximum latitude and longitude and also belonging to the defined 
	* category, if it is specified. @n
    *
    * The category is handled in a case-sensitive manner and matches exactly with the corresponding field of the landmark. @n
	*
	* The outer limits are considered to belong to the area. If minLongitude <= maxLongitude, this area covers the longitude 
	* range [minLongitude, maxLongitude]. If minLongitude > maxLongitude, this area covers the longitude range
	* [-180.0, maxLongitude] and [minLongitude, 180.0]. For latitude, the area covers the latitude range [minLatitude, maxLatitude]. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks. @n
	*
	* This method operates asynchronously, that is, it ends immediately without the search results. The applications are notified while searching, 
	* so that the results are available via the ILandmarkSearchListener::OnLandmarkSearchResultReceivedN() method if this method returns E_SUCCESS.
	*
	* @deprecated	This method is deprecated.
	* @since			 1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                   For more information, see @ref CompLandmarkStoreSearchLandmarks2Page "here".
	*
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	pCategory			The category of the landmark @n
	*									@c null or an empty string implies a wildcard that matches all categories
	* @param[in]	minLatitude			The minimum latitude of the area within the range [-90.0, 90.0]
	* @param[in]	maxLatitude			The maximum latitude of the area within the range [minLatitude, 90.0]
	* @param[in]	minLongitude		The minimum longitude of the area within the range [-180.0, 180.0]
	* @param[in]	maxLongitude		The maximum longitude of the area within the range [-180.0, 180.0]
	* @param[in]	pSelector			The landmark property selector @n
	*									It may be @c null.
	* @param[in]	listener			The event listener
	* @param[out]	searchId			The ID of the search
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c minLongitude or @c maxLongitude is out of range. The valid range is [-180.0, 180.0]. @n
	*									- The specified @c minLatitude or @c maxLatitude is out of range. The valid range is [-90.0, 90.0]. @n
	*									- The specified @c minLatitude is greater than the @c maxLatitude.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*
	* The following example demonstrates how to search for the landmarks.
	*
	* @code
	*
    *   #include <FBase.h>
    *   #include <FLocations.h>
    *   
    *   using namespace Osp::Base;
    *   using namespace Osp::Base::Collection;
    *   using namespace Osp::Locations;
    *
    *   class MyClass: public ILandmarkSearchListener
    *   {
    *   public:
    *   	MyClass(void);
    *   	~MyClass(void);
    *   	void LandmarkStoreExample(void);
    *   	void SearchLandmarksExample(void);
    *   	
    *   // ILandmarkSearchListener
    *   public:
    *       void OnLandmarkSearchResultReceivedN(SearchId searchId, IEnumerator* pResults, result r) {
    *       	if (IsFailed(r)){
    *       		AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
    *       	}
    *
    *           if (pResults) {
    *           	while(!IsFailed(pResults->MoveNext())) {
    *           	    const Landmark* item = static_cast<const Landmark*>(pResults->GetCurrent());
    *           		String name = item->GetName();
    *           		AppLog("Landmark Retrieved(%S).", name.GetPointer());
    *           	}
    *           	
    *           	delete pResults;
    *           }
    *       }
    *   };
    *
    *   void 
    *   MyClass::SearchLandmarksExample(void) {
    *   	result					r = E_SUCCESS;
    *   	SearchId				searchId;
    *   	String                  storeName(L"MyStore");
    *   	LandmarkStore			myStore;
    *
    *   	// 1. Constructs the instance of the landmark store.
    *   	r = myStore.Construct(&storeName);
    *   	if (IsFailed(r)) {
    *   		AppLog("Failed to Construct - %s.", GetErrorMessage(r));
    *   		return;
    *   	}
    *
    *   	// 2. Searches the landmarks categorized by the global category 'SIGHTSEEING' and located in the bounds of (36.6, 125.0) and (37.0, 126.0).
	*		r = myStore.SearchLandmarks(&SIGHTSEEING, 36.0, 37.0, 125.0, 126.0, null, *this, searchId);
    *   	if (IsFailed(r)) {
    *   	    AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
    *   	} else {
    *   		AppLog("SearchLandmarks(%d) is started.", searchId);
    *   	}
    *   }
	*
	* @endcode
	*/
	result	SearchLandmarks(const Osp::Base::String* pCategory, double minLatitude, double maxLatitude, double minLongitude, double maxLongitude, const LandmarkPropertySelector* pSelector, const ILandmarkSearchListener& listener, SearchId& searchId) const;
	
	/**
	* Searches the landmarks in the store using a landmark filter. @n
	* 
	* A landmark filter contains several filters that are used in the matching process. Filters that are not set by the application are ignored. Passing the 
	* @c null value as a landmark filter lists all the landmarks in this store. @n
    *
	* Note that only the @ref ADDRESS_FIELD_CITY, @ref ADDRESS_FIELD_POSTAL_CODE, and @ref ADDRESS_FIELD_STREET_NAME fields in an address filter work 
	* currently. @n
    * If an application wants to perform a query with an address, it may first geocode the address to coordinates using 
    * @ref Osp::Locations::Services::IGeocodingServiceProvider, and then perform a proximity query for landmarks around the coordinates. For example, using a 
	* circular geographic area filter with the coordinates as the center. @n
	*
	* A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all the properties of the landmarks. @n
	*
	* The @c sortBy parameter indicates the field in the %Landmark instance that is used to sort the result set. In addition to that, sorting may be done 
	* based on the distance of the landmark from the coordinates given as a parameter. Since the only mandatory field for a landmark is the name, the result 
	* set may contain landmarks that do not have the specified sorting fields. @n
	*
	* This method operates asynchronously, that is, it ends immediately without the search results. Applications are notified when searching is done, so the 
	* results are available via the ILandmarkSearchListener::OnLandmarkSearchResultReceivedN() method if this method returns E_SUCCESS.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility    This method has compatibility issues with different bada API versions. @n
    *                   For more information, see issues in version @ref CompLandmarkStoreSearchLandmarksPage "1.1" and @ref CompLandmarkStoreSearchLandmarks2Page "2.0".
    *
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	pFilter				The landmark filter @n
	*									It may be @c null.
	* @param[in]	pSelector			The landmark property selector @n
	*									It may be @c null.
	* @param[in]	pDistFrom			The coordinates from which the distance is calculated if sorting is done based on the distance @n
	*									It may be @c null.
	* @param[in]	maxResults			The maximum number of results this query can return, @n
	*									else @c -1 if an application has no restriction
	* @param[in]	sortOrder			The order in which the sorting is done
	* @param[in]	sortBy				The field used to sort the result set
	* @param[in]	listener			The event listener
	* @param[out]	searchId			The ID of the search
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c maxResults is equal to @c 0 or less than @c -1. @n
	*									- The specified @c sortBy is SORT_BY_DISTANCE when the @c distFrom is @c null. @n
    *									- The specified @c sortOrder or @c sortBy is invalid.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
    *
	* The following example demonstrates how to search for the landmarks.
	*
	* @code
	*
  *   #include <FBase.h>
  *   #include <FLocations.h>
  *   
  *   using namespace Osp::Base;
  *   using namespace Osp::Base::Collection;
  *   using namespace Osp::Locations;
  *
  *   class MyClass: public ILandmarkSearchListener
  *   {
  *   public:
  *   	MyClass(void);
  *   	~MyClass(void);
  *   	void LandmarkStoreExample(void);
  *   	void SearchLandmarksExample(void);
  *   	
  *   // ILandmarkSearchListener
  *   public:
  *       void OnLandmarkSearchResultReceivedN(SearchId searchId, IEnumerator* pResults, result r) {
  *       	if (IsFailed(r)){
  *       		AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
  *       	}
  *
  *           if (pResults) {
  *           	while(!IsFailed(pResults->MoveNext())) {
  *           	    const Landmark* item = static_cast<const Landmark*>(pResults->GetCurrent());
  *           		String name = item->GetName();
  *           		AppLog("Landmark Retrieved(%S).", name.GetPointer());
  *           	}
  *           	
  *           	delete pResults;
  *           }
  *       }
  *   };
  *
  *   void 
  *   MyClass::SearchLandmarksExample(void) {
  *       result					r = E_SUCCESS;
  *       SearchId				searchId;
  *       Coordinates				center;
  *       center.Set(37.335084, 126.582571, 0.0);
  *       CircleGeographicArea	area;
  *       LandmarkFilter			filter;
  *       String                  storeName(L"MyStore");
  *       LandmarkStore			myStore;
  *
  *       // 1. Constructs the instance of the landmark store.
  *       r = myStore.Construct(&storeName);
  *       if (IsFailed(r)) {
  *           AppLog("Failed to Construct - %s.", GetErrorMessage(r));
  *           return;
  *       }
  *
  *       // 2. Makes up a filter for an advanced search. Sets the filter for the category and geographic area.
  *       filter.SetCategoryFilter(&SIGHTSEEING);
  *       area.Set(center, 100);
  *       filter.SetGeographicAreaFilter(&area);
  *
  *       // 3. Searches landmarks with the filter, sorting them by distance from the center of the area.
  *       r = myStore.SearchLandmarks(&filter, null, &center, 10, SORT_ORDER_ASCENDING, SORT_BY_DISTANCE, *this, searchId);
  *       if (IsFailed(r)) {
  *          AppLog("Failed to SearchLandmarks - %s.", GetErrorMessage(r));
  *       } else {
  *      		AppLog("SearchLandmarks(%d) is started.", searchId);
  *      	}
  *   }
  *       
	* @endcode
	*/
	result	SearchLandmarks(const LandmarkFilter* pFilter, const LandmarkPropertySelector* pSelector, const Coordinates* pDistFrom, int maxResults, Osp::Base::SortOrder sortOrder, SortBy sortBy, const ILandmarkSearchListener& listener, SearchId& searchId) const;


    /**
    * Searches landmarks in the store using a landmark filter. @n
    * 
    * A landmark filter contains several filters that are used in the matching process. Filters that are not set by the application are ignored. The 
	* @c null value is passed to the landmark filter to list all the landmarks present in this store. @n
    *
    * Note that only the @ref ADDRESS_FIELD_CITY, @ref ADDRESS_FIELD_POSTAL_CODE, and @ref ADDRESS_FIELD_STREET_NAME fields in an address filter work 
	* currently. @n
    * If an application wants to perform a query with an address, it may first geocode the address to coordinates using 
    * @ref Osp::Locations::Services::IGeocodingServiceProvider, and then perform a proximity query for landmarks around the coordinates. For example, using 
	* a circular geographic area filter with the coordinates as the center.
    *
    * A landmark property selector takes only those properties of the landmark that it is interested in. Only the selected properties are filled in the 
	* result landmarks. Passing the @c null value as a selector gives all properties of landmarks. @n
    *
    * The @c sortBy parameter indicates the field in the %Landmark instance that is used to sort the result set. In addition to that,
    * sorting may be done based on the distance of the landmark from the coordinates specified in the parameter. Since the only mandatory field for a 
	* landmark is name, the result set may contain landmarks that do not have the specified sorting fields.
    *
    * The @c timeout parameter controls the maximum response time of searching. When the search time exceeds the @c timeout value, it tries to abort the 
	* search process immediately and then notifies the search listener. The search time loosely meets the timeout. The partial result might be retrieved (if 
	* it exists) via the search listener. Passing @c -1 as the timeout value means no limitations on the searching time.
    *
    * This method operates asynchronously, that is, it ends immediately without the search results. Applications are notified when searching 
    * is done, so the results are available via the ILandmarkSearchListener::OnLandmarkSearchResultReceivedN() method if this method returns E_SUCCESS.
    *
	* @deprecated	This method is deprecated.
    * @since		2.0
    *
    * @privlevel	NORMAL
    * @privgroup	LANDMARK
    * @return		An error code
	* @param[in]	pFilter				The landmark filter @n
	*									It may be @c null.
	* @param[in]	pSelector			The landmark property selector @n
	*									It may be @c null.
	* @param[in]	pDistFrom			The coordinates from which the distance is calculated if sorting is done based on the distance @n
	*									It may be @c null.
	* @param[in]	maxResults			The maximum number of results this query can return, @n
	*									else @c -1 if an application has no restriction
	* @param[in]	sortOrder			The order in which the sorting is done
	* @param[in]	sortBy				The field used to sort the result set
    * @param[in]    timeout     		The search timeout in seconds
	*									@c -1 denotes no limitation on the searching time.
	* @param[in]	listener			The event listener
	* @param[out]	searchId			The search ID
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c maxResults is equal to @c 0 or less than @c -1. @n
    * 									- The specified @c sortBy is SORT_BY_DISTANCE when the @c distFrom is @c null. @n
    * 									- The specified @c sortOrder or @c sortBy is invalid. @n
    * 									- The specified @c timeout is equal to @c 0 or less than @c -1.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.

    */
    result SearchLandmarks(const LandmarkFilter* pFilter, const LandmarkPropertySelector* pSelector, const Coordinates* pDistFrom, int maxResults, Osp::Base::SortOrder sortOrder, SortBy sortBy, int timeout, const ILandmarkSearchListener& listener, SearchId& searchId) const;
    

	/**
	* Gets the authorization mode of this landmark store.
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return			An error code
	* @param[out]	isPublic			Set to @c true if the authorization mode of this landmark store is public, @n
	*									else @c false
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	IsPublic(bool& isPublic) const;

	/**
	* Gets the name of the specified landmark store. @n
	*
	* @deprecated	This method is deprecated.
	* @since		1.0
	* @return		The name of the landmark store, @n
	*				else @c null in case of the default landmark store
	*/
	const	Osp::Base::String*	GetName(void) const;

	/**
	* Gets the number of landmarks in the specified category. @n 
	*
	* If the category is null, the method returns the number of landmarks in the landmark store. @n
	* If the specified category is not found from the landmark store, E_INVALID_ARG is reported.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                   For more information, see @ref CompLandmarkStoreGetNumberOfLandmarksPage "here".
    *
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	pCategory			The landmark category from which the landmark number is requested, @n
	*									else @c null if the total number of landmarks in the landmark store is requested
	* @param[out]	numberOfLandmarks	The number of landmarks in the given category or in the landmark store
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception	E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception	E_INVALID_ARG 		The specified @c pCategory does not exist in the landmark store.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	GetNumberOfLandmarks(const Osp::Base::String* pCategory, int& numberOfLandmarks) const;

	/**
	* Removes the specified landmark from all the categories with which it is associated. @n
	*
	* The %Landmark instance (passed as a parameter) must be an instance that belongs to this landmark store. If the landmark parameter does not belong to 
	* any category or to the landmark store at all, the request is ignored and the method call returns no error. @n
	*
	* Calling this method updates the timestamp of the landmark. @n
	* 
	* In some cases, the landmark store may be read-only, so no changes are allowed to it. In this case, this method returns E_IO. @n
	*
	* Even if the landmark is removed from the categories, the landmark still belongs to the store. The landmark can still be
	* obtained from the store by passing @c null as the category to search methods.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
	* @privlevel		NORMAL
	* @privgroup		LANDMARK
	*
	* @return			An error code
	* @param[in,out]	landmark			The landmark to be removed from all categories
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception		E_IO 				An I/O error has occurred when accessing the landmark store.
	* @exception		E_ILLEGAL_ACCESS 	The application does not have the permission to modify the landmark.
	* @exception		E_INVALID_STATE 	This instance is in an invalid state.
	* @exception		E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception		E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	RemoveLandmarkFromAllCategories(Landmark& landmark);

	/**
	* Removes the specified landmark from the specified category. @n
	*
	* To remove the specified landmark from a global landmark category, the constant defined for that global landmark category must be used. @n
	*
	* The landmark (passed as a parameter) must be an instance that belongs to this landmark store. @n
	* If the landmark parameter does not belong to the specified category or to the landmark store at all, the request is ignored and the method call 
	* returns no error. The request is also ignored if the specified category does not exist in this landmark store. @n
	*
	* Calling this method updates the timestamp of the landmark. @n
	*
	* In some cases, the landmark store may be read-only, so no changes are allowed to it. In this case, this method returns E_IO. @n
	*
	* The landmark is only removed from the specified category but the landmark information is retained in the landmark store. If the landmark no longer 
	* belongs to any category, it can still be obtained from the store by passing @c null as the category to search methods.
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility  	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *					For more information, see @ref CompLandmarkStoreRemoveLandmarkFromCategoryPage "here".
	*
	* @privlevel		NORMAL
	* @privgroup		LANDMARK
	*
	* @return			An error code
	* @param[in,out]	landmark			The landmark to be removed
	* @param[in]		category			The category from which it is removed
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_SERVICE_BUSY		The system is too busy to handle the request.
	* @exception		E_IO				An I/O error has occurred when accessing the landmark store.
	* @exception		E_ILLEGAL_ACCESS	The application does not have the permission to modify the landmark.
	* @exception		E_INVALID_STATE		This instance is in an invalid state.
	* @exception		E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result	RemoveLandmarkFromCategory(Landmark& landmark, const Osp::Base::String& category);

	/**
	* Renames a landmark category. @n
	*
	* This method cannot be used to rename the global landmark categories. Renaming affects all the landmarks belonging to the specified category. If a 
	* category with the specified category name does not exist in this landmark store, this method returns with no error. @n
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *					For more information, see @ref CompLandmarkStoreRenameCategoryPage "here".
    *
	* @privlevel	NORMAL
	* @privgroup	LANDMARK
	*
	* @return		An error code
	* @param[in]	oldCategory			The current name of the landmark category
	* @param[in]	newCategory			The new name for the landmark category
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_SERVICE_BUSY		The system is too busy to handle the request.
	* @exception	E_IO				An I/O error has occurred.
	* @exception	E_INVALID_ARG 		Either of the following conditions has occurred: @n
	*									- The specified @c oldCategoryName is one of the global landmark categories defined in the class. @n
	*									- The specified @c newCategoryName is one of the global category constants defined in this class. @n 
	*									- One of these specified input parameters is an empty string.
	* @exception	E_ILLEGAL_ACCESS 	The application does not have the permission to manage categories.
	* @exception	E_INVALID_STATE 	This instance is in an invalid state.
	* @exception	E_OUT_OF_MEMORY  	The memory is insufficient.  
	* @exception	E_PRIVILEGE_DENIED  The application does not have the privilege to call this method.
	*/
	result	RenameCategory(const Osp::Base::String& oldCategory, const Osp::Base::String& newCategory);

	/**
	* Updates the information about a landmark. @n
	*
	* This method only updates the information about a landmark and does not modify the categories that the landmark belongs to. @n
	*
	* The %Landmark instance (passed as a parameter) must be an instance that belongs to this landmark store. This method cannot be used to add a new 
	* landmark to the store. @n
	*
	* Calling this method updates the timestamp of the landmark. In some cases, the landmark store may be read-only, so no changes are allowed to it. In 
	* this case, this method returns an E_IO. @n
	*
	* @deprecated	This method is deprecated.
	* @since			1.0
    * @compatibility 	This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n 
    *                   For more information, see @ref CompLandmarkStoreUpdateLandmarkPage "here".
	*
	* @privlevel		NORMAL
	* @privgroup		LANDMARK
	*
	* @return			An error code
	* @param[in,out]	landmark			The landmark to be updated
	* @exception		E_SUCCESS			The method is successful.
	* @exception		E_SERVICE_BUSY 		The system is too busy to handle the request.
	* @exception		E_IO	 			An I/O error has occurred when accessing the landmark store.
	* @exception		E_INVALID_ARG 		The landmark has a longer name field than the implementation can support.
	* @exception		E_LANDMARK 			The landmark does not belong to this landmark store or it does not exist in the store anymore.
	* @exception		E_ILLEGAL_ACCESS 	The application does not have the permission to update the landmark.
	* @exception		E_INVALID_STATE 	This instance is in an invalid state.
	* @exception		E_OUT_OF_MEMORY		The memory is insufficient.  
	* @exception		E_PRIVILEGE_DENIED	The application does not have the privilege to call this method.
	*/
	result	UpdateLandmark(Landmark& landmark);

// Attribute
private:
	Osp::Base::String*	__pName;
	_ILandmarkStore*		__pMILandmarkStore;

private:
	friend class LandmarkStoreEx;
	class LandmarkStoreEx* __pLandmarkStoreEx;

/**
 * @page	CompLandmarkStoreSearchLandmarksPage	Compatibility for SearchLandmarks() 
 * @section	CompLandmarkStoreSearchLandmarksPageIssueSection	Issues
 * Implementation of this method in bada API versions prior to 1.1 has the following issue: @n 
 * If the bounding box of an area filter in @c pFilter crosses 180 degree longitude, and @c pFilter 
 * has filters such as name, address, author, category, and priority, the search result is not as expected. @n
 * Expected result: Landmarks of the area covered by the longitudinal range of [-180.0, maxLongitude]
 * or [minLongitude, 180.0], matching with other filters in @c pFilter. @n
 * Actual result (Prior to version 1.1) : Landmarks of the area covered by the longitudinal range of 
 * [minLongitude, 180.0], matching with the category filter, if provided.
 *
 * @section	CompLandmarkStoreSearchLandmarksPageSolutionSection		Resolutions
 * The issue mentioned above is resolved in bada API version 1.1, and it is recommended to use bada API version 1.1 or above. @n 
 *
 * @par 
 * When working with bada API versions prior to 1.1: 
 * 1. For the area that crosses the 180 degrees longitude, divide the area into 2, cutting at 180 degrees longitude. 
 * The areas then have a longitudinal range of [-180.0, maxLongitude] and [minLongitude, 180.0]. @n
 * 2.  Call the SearchLandmarks() method with each of the divided areas as an area filter in @c pFilter. @n
 * This workaround is applicable only for a rectangular area. @n
 * To search landmarks for areas circular or polygonal in shape: @n
 * 1. Retrieve the bounding box of the area using the GeographicArea.GetBoundingBox() method and search for landmarks. @n
 * 2. Refine the search results by discarding false answers using the GeographicArea.ContainsCoordinates() method. @n
 * 
 */

/** 
* @page CompLandmarkStoreCreateLandmarkStorePage Compatibility for CreateLandmarkStore()
* @section CompLandmarkStoreCreateLandmarkStoreIssueSection Issues 
*            Implementation of this method in API versions prior to 2.0 has the following issue: @n 
* 
* If @c storeName contains characters other than letters, digits, and underscore("_"), or begins with a digit, 
* the method fails to create a landmark store as per the specified name.
* 
* @section CompLandmarkStoreCreateLandmarkStoreSolutionSection Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use API version 2.0 or above. @n
*
* @par When working with API versions prior to 2.0:
* An application should use only letters, digits, and underscore("_") for the store name and it should not begin with a digit.
*/

/** 
* @page	CompLandmarkStoreAddCategoryPage	Compatibility for AddCategory()
* @section	CompLandmarkStoreAddCategoryIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
* If the category name contains single quotation(') marks, the method fails to add the category.
* 
* @section CompLandmarkStoreAddCategorySolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a category name with two single quotation marks.
* For example, for a category name such as "Sam's friends", an application should use the category name as "Sam''s friends".
*/

/** 
* @page CompLandmarkStoreRenameCategoryPage Compatibility for RenameCategory()
* @section CompLandmarkStoreRenameCategoryIssueSection Issues 
*            Implementation of this method in API versions prior to 2.0 has the following issue: @n 
* 
* If the category contains single quotation(') marks, the method fails to rename the category name.
* 
* @section CompLandmarkStoreRenameCategorySolutionSection Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use API version 2.0 or above. @n
*
* @par When working with API versions prior to 2.0:
* An application should replace a single quotation mark in a category name with two single quotation marks.
* For example, for a category name such as "Sam's friends", an application should use the category name as "Sam''s friends".
*/

/** 
* @page	CompLandmarkStoreDeleteCategoryPage		Compatibility for DeleteCategory()
* @section CompLandmarkStoreDeleteCategoryIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
* 
* If the category contains single quotation(') marks, the method fails to delete the category.
* 
* @section CompLandmarkStoreDeleteCategorySolutionSection 	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a category name with two single quotation marks.
* For example, for a category name such as "Sam's friends", an application should use the category name as "Sam''s friends".
*/

/** 
* @page CompLandmarkStoreRemoveLandmarkFromCategoryPage	Compatibility for RemoveLandmarkFromCategory()
*
* @section CompLandmarkStoreRemoveLandmarkFromCategoryIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
* 
* If the category contains single quotation(') marks, the method fails to remove the landmark from the category.
* 
* @section CompLandmarkStoreRemoveLandmarkFromCategorySolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a category name with two single quotation marks.
* For example, for a category name such as "Sam's friends", an application should use the category name as "Sam''s friends".
*/

/** 
* @page CompLandmarkStoreGetNumberOfLandmarksPage	Compatibility for GetNumberOfLandmarks()
*
* @section CompLandmarkStoreGetNumberOfLandmarksIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
* 
* If the category contains single quotation(') marks, the method fails to get the number of landmarks present in the category.
* 
* @section CompLandmarkStoreGetNumberOfLandmarksSolutionSection		Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a category name with two single quotation marks.
* For example, for a category name such as "Sam's friends", an application should use the category name as "Sam''s friends".
*/

/** 
* @page CompLandmarkStoreAddLandmarkPage	Compatibility for AddLandmark()
*
* @section CompLandmarkStoreAddLandmarkIssueSection		Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
* If a textual field in the landmark contains single quotation(') marks, the method fails to add the landmark.
* 
* @section CompLandmarkStoreAddLandmarkSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a string with two single quotation marks.
* For example, for a string such as "Sam's friends", an application should use the string as "Sam''s friends".
*/

/** 
* @page CompLandmarkStoreUpdateLandmarkPage		Compatibility for UpdateLandmark()
*
* @section CompLandmarkStoreUpdateLandmarkIssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n
* If a textual field in the landmark contains single quotation(') marks, the method fails to update the landmark.
* 
* @section CompLandmarkStoreUpdateLandmarkSolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a string with two single quotation marks.
* For example, for a string such as "Sam's friends", an application should use the string as "Sam''s friends".
*/

/** 
* @page CompLandmarkStoreSearchLandmarks2Page	Compatibility for SearchLandmarks()
* @section CompLandmarkStoreSearchLandmarks2IssueSection	Issues 
* Implementation of this method in bada API versions prior to 2.0 has the following issue: @n 
* 
* If a text field of the filter (for example category, name, or author) contains single quotation(') marks, the method fails to search landmarks.
* 
* @section CompLandmarkStoreSearchLandmarks2SolutionSection	Resolutions 
* The issue mentioned above is resolved in bada API version 2.0 and it is recommended to use bada API version 2.0 or above. @n
*
* @par 
* When working with bada API versions prior to 2.0:
* An application should replace a single quotation mark in a string with two single quotation marks.
* For example, for a string such as "Sam's friends", an application should use the string as "Sam''s friends".
*/

};	// class LandmarkStore
/**
 * @}
 */

} }	// Osp::Location

#endif	// _FLOC_LANDMARK_STORE_H_
