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
 * @file		FLocILandmarkSearchListener.h
 * @brief		This is the header file for the ILandmarkSearchListener interface.
 *
 * This header file contains the declarations of the ILandmarkSearchListener interface.
 *
 */
 
#ifndef _FLOC_ILANDMARK_SEARCH_LISTENER_H_
#define _FLOC_ILANDMARK_SEARCH_LISTENER_H_

#include "FLocationConfig.h"
#include "FBaseColIEnumerator.h"
#include "FBaseColIList.h"
#include "FBaseRtIEventListener.h"

namespace Osp { namespace Locations { 

// SearchId
typedef long	SearchId;
#define INVALID_SEARCH_ID	-1

/**
* @interface	ILandmarkSearchListener
* @brief		This interface represents a listener that receives the events generated while searching for landmarks in the landmark store.
* @deprecated	This interface is deprecated.
* @since		1.0
*
* The %ILandmarkSearchListener interface represents a listener that receives the events generated while searching for landmarks in the landmark store.
* Applications implement this interface and pass it to the LandmarkStore::SearchLandmarks() methods to be notified when the search is done and 
*				the results are available.
*
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/locations/landmarks.htm">Landmarks</a>.
*/
class	_EXPORT_LOCATION_	ILandmarkSearchListener: 
	public Osp::Base::Runtime::IEventListener{

// Lifecycle
public:
    /**
     * This is the destructor for this class.
     *
	 * @deprecated	This method is deprecated.
     * @since   1.0
     */
    virtual ~ILandmarkSearchListener(void);


public:
	/**
	* Called to notify when one of the LandmarkStore::SearchLandmarks() methods is completed.
	*
	 * @deprecated	This method is deprecated.
	* @since		1.0
	* @param[in]	searchId	The ID of the search
	* @param[in]	pResults	The enumerator of Landmark instances matching with the specified criteria from LandmarkStore::SearchLandmarks(), @n
	*							else @c null if there are no matching landmarks
	* @param[in]	r			The error code
	* @exception	E_SUCCESS	The method is successful.
	* @exception	E_IO		An I/O error has occurred when accessing the landmark store.
    * @exception    E_TIMEOUT	The search time exceeds the limitation that is set by the LandmarkStore::SearchLandmarks() method. @n
	*							The @c pResults parameter may contain a partial result @b since: @b 2.0.
	* @remark		The result enumerator must be deleted by the application.
	* @see			LandmarkStore::SearchLandmarks()
	*/	
	virtual void	OnLandmarkSearchResultReceivedN(SearchId searchId, Osp::Base::Collection::IEnumerator* pResults, result r) = 0;
};	// class ILandmarkSearchListener

} }	// Osp::Location

#endif// _FLOC_ILANDMARK_SEARCH_LISTENER_H_
