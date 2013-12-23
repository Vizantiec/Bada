/* $Change: 1241928 $ */
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
* @file			FMediaDrmConstraintInfo.h 
* @brief		This is the header file for the %DrmConstraintInfo class.
*
* This header file contains the declarations of the %DrmConstraintInfo class.
*/
#ifndef _FMEDIA_DRM_CONSTRAINT_INFO_H_
#define _FMEDIA_DRM_CONSTRAINT_INFO_H_

// includes
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaDrmConstants.h"

namespace Osp { namespace Media {
class __DrmManager;
class __DrmManagerPiReceiver;
class DrmConstraintInfoEx;

/**
* @class	DrmConstraintInfo
* @brief	This class specifies the constraints of the DRM.
* @deprecated  This enumeration is deprecated due to the operation policy of DRM service.
* @since	1.0
*
* The %DrmConstraintInfo class contains the Digital Rights Management (DRM) constraint information, including: @n
* - Count: The number of times a permission may be granted over an asset
* - Timed-count: The count constraint with the addition of an optional timer attribute
* - Datetime: The time range and time limit for permissions for the DRM content.
* - Interval: A period of time during which the permissions can be exercised over the DRM content.
* - Accumulated: The maximum period of metered usage time during which the rights can be exercised over the DRM content.
*
* For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/media/digital_rights_management.htm">Digital Rights Management</a>.
*/
class _EXPORT_MEDIA_ DrmConstraintInfo :
	public Osp::Base::Object
{
// Lifecycle
public:
	/**
	* This is the default constructor for this class.
	*
	* @since	1.0
	*/
	DrmConstraintInfo(void);

	/**
	* This is the destructor for this class.
	*
	* @since	1.0
	*/
	virtual ~DrmConstraintInfo(void);

// Access
public:
	/**
	* Gets the original counter.
	*
	* @since			1.0
	*	@privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	*	@return			The original counter
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetOriginalCounter(void) const;

	/**
	* Gets the total number of remaining counters.
	*
	* @since			1.0
	*	@privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	*	@return			The number of counters remaining
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetLeftCounter(void) const;

	/**
	* Gets the start time.
	*
	* @since			1.0
	*	@privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	*	@return			The start time
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::DateTime GetStartTime(void) const;

	/**
	* Gets the end time.
	*
	* @since			1.0
	*	@privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	*	@return			The end time
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::DateTime GetEndTime(void) const;

	/**
	* Gets the time interval. 
	*
	* @since			1.0
	*	@privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	* @return		The time interval
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	Osp::Base::DateTime GetInterval(void) const;

	/**
	* Gets the accumulated time.
	*
	* @since		1.0
	* @privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	* @return		The accumulated time
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/
	int GetAccumulatedTime(void) const;

	/**
	* Gets the timed count.
	*
	* @since			1.0
	*	@privlevel	NORMAL
	* @privgroup	DRM_CONTENT
	*	@return			An error code
	* @param[out]	timer			The timer in seconds
	* @param[out]	counter			The counter
	* @exception	E_SUCCESS		The method was successful.
	* @exception	E_PRIVILEGE_DENIED				The application does not have the privilege to call this method.
	*	@remarks		The specific error code can be accessed using the GetLastResult() method.
	*/	
	void GetTimedCount(int& timer, int& counter) const;

// Access
private:
	/**
	* Gets the DRM constraints type list.
	*
	* @return		A list of the DRM constraints type
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/		
	Osp::Base::Collection::IList* GetConstraintsTypeList(void) const;

// Operation
private:
	/**
	* Sets the specified value for the original counter.
	*
	* @param[in]	counter				The value to be set for the original counter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	void SetOriginalCounter(int counter);

	/**
	* Sets the specified value for the left counter.
	*
	* @param[in]	counter				The value to be set for the left counter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	void SetLeftCounter(int counter);

	/**
	* Sets the start time.
	*
	* @param[in]	dateTime			The start time
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	void SetStartTime(const Osp::Base::DateTime& dateTime);

	/**
	* Sets the end time.
	*
	* @param[in]	dateTime			The end time
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	void SetEndTime(const Osp::Base::DateTime& dateTime);

	/**
	* Sets the time interval.
	*
	* @param[in]	interval			The time interval
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	void SetInterval(const Osp::Base::DateTime& interval);

	/**
	* Sets the accumulated time.
	*
	* @param[in]	accumulatedTime		The accumulated time
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/
	void SetAccumulatedTime(int accumulatedTime);

	/**
	* Sets the timed count.
	*
	* @param[in]	timer				The timer in seconds
	* @param[in]	counter				The counter
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	*/	
	void SetTimedCount(int timer, int counter);	

// Lifecycle
private:

// Attributes
private:
	int	__originalCounter;
	int __leftCounter;
	Osp::Base::DateTime __startTime;
	Osp::Base::DateTime __endTime;
	Osp::Base::DateTime __interval;
	int __accumulateTime;
	int __timedTimer;
	int __timedCounter;

	friend class __DrmManager;
	friend class __DrmManagerPiReceiver;
	friend class DrmConstraintInfoEx;
	class DrmConstraintInfoEx* __pDrmConstraintInfoEx;
};

};};// Osp::Media
#endif // _FMEDIA_DRM_CONSTRAINT_INFO_H_
