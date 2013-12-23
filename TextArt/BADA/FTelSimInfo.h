/* $Change: 1198808 $ */
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
 * @file		FTelSimInfo.h 
 * @brief		This is the header file for the %SimInfo class. 
 *
 * This header file contains the declarations of the %SimInfo class.
 */

#ifndef _FTEL_SIM_INFO_H_
#define _FTEL_SIM_INFO_H_

#include "FBase.h"
#include "FTelConfig.h"

namespace Osp { namespace Telephony { class ISimInfoPi; };};

namespace Osp { namespace Telephony {

/**
 * @class	SimInfo 
 * @brief	This class provides information of the currently inserted SIM card. 
 * @since	1.0
 *
 * The %SimInfo class provides methods to get SIM card information, such as MCC, MNC, SPN, ICC ID, operator name, and SIM card availability.
 *
 * The following example demonstrates how to use the %SimInfo class.
 *
 * @code
 *
 *	result
 *	MyClass::GetSimInfo(void)
 *	{
 *		int mnc;
 *		int mcc;
 *		bool isAvailable;
 *		String spn;
 *		String iccId;
 *		String operatorName;
 *		String phoneNumber;
 *
 *		SimInfo *pSimInfo = new SimInfo();
 *
 *		result r = pSimInfo->Construct();
 *		if (IsFailed(r))
 *		{
 *			delete pSimInfo;
 *			return r;
 *		}
 *
 *		mnc = pSimInfo->GetMnc();
 *		mcc = pSimInfo->GetMcc();
 *		spn = pSimInfo->GetSpn();
 *		iccId = pSimInfo->GetIccId();
 *		operatorName = pSimInfo->GetOperatorName();
 *		phoneNumber = pSimInfo->GetPhoneNumber();
 *		isAvailable = pSimInfo->IsAvailable();
 *
 *		delete pSimInfo;
 *		return E_SUCCESS;
 *	}
 *
 * @endcode
 */
class _EXPORT_TEL_ SimInfo
	: public Osp::Base::Object
{
// Life cycle
public:

	/**
	 *	This is the default constructor for this class.	
	 *
	 * @since	1.0
	 */
	SimInfo(void);

	/**
	 *	This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~SimInfo(void);

	/** 
	 * Initializes this instance of %SimInfo.
	 *
	 * @since			1.0
	 * @return		An error code
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_SYSTEM				A system error has occurred.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 */		
	result Construct(void);

// Access
public:	

	/**
	 * Gets the Mobile Network Code (MNC) of the SIM International Mobile Subscriber Identity (IMSI) information.
	 *
	 * @since					1.0
	 * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                  For more information, see @ref SimInfoPage "here".
	 * @privlevel   NORMAL
	 * @privgroup   TELEPHONY		
	 *
	 * @return		The MNC of the SIM card, @n
	 *              else @c -1 if the method fails
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card @b since: @b 1.1.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 *
	 
	 */
	int GetMnc(void) const;

	/**
	 * Gets the Mobile Country Code (MCC) of the SIM IMSI information.
	 *
	 * @since   1.0
	 * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                  For more information, see @ref SimInfoPage "here".
	 * @privlevel   NORMAL
	 * @privgroup   TELEPHONY
	 *
	 * @return		The MCC of the SIM card, @n
	 *              else @c -1 if the method fails
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card @b since: @b 1.1.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 */
	int GetMcc(void) const;

	/**
	 * Gets the Service Provider Name (SPN) string of the SIM card.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                      For more information, see @ref SimInfoPage "here".
	 * @privlevel   NORMAL
	 * @privgroup   TELEPHONY
	 *
	 * @return		The SPN of the SIM card, @n
	 * 				else an empty string if there is no SIM card in the device, or if an SPN is not assigned to the SIM card
     * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card @b since: @b 1.1.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		
	 */
	Osp::Base::String GetSpn(void) const;

	/**
	 * Gets the Integrated Circuit Card Identifier (ICCID) of the SIM card. @n
	 * One useful case to detect the change of SIM cards is to store this value and compare it with the most recent value.
	 * This method provides a unique identification number for the SIM card.
	 *
	 * @since   1.0
	 * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                  For more information, see @ref SimInfoPage "here".
	 * @privlevel   NORMAL
	 * @privgroup   TELEPHONY
	 *
	 * @return		The ICCID of the SIM card, @n
     *              else an empty string if the method fails
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card @b since: @b 1.1.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		
	 */
	Osp::Base::String GetIccId(void) const;

	/**
	 * Gets the operator name of the SIM card.
	 *
	 * @since   1.0
	 * @compatibility   This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                  For more information, see @ref SimInfoPage "here".
	 * @privlevel   NORMAL
	 * @privgroup   TELEPHONY
	 *
	 * @return		The operator name of the SIM card, @n
	 * 				else an empty string if there is no SIM card in the device, or if an OPNS is not assigned to the SIM card
     * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card @b since: @b 1.1.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
     */
	Osp::Base::String GetOperatorName(void) const;

	/**
	 * Gets the phone number of the SIM card.
	 *
	 * @since					2.0
	 * @privlevel	SYSTEM
	 * @privgroup  	TELEPHONY_PHONE_NUMBER
	 *
	 * @return		The phone number of the SIM card, @n
     * 			    else an empty string if there is no SIM card in the device, or if a Mobile Station International Subscriber Directory Number
     * 				(MSISDN) is not assigned to the SIM card
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 * @exception	E_SYSTEM				A system error has occurred.
	 */
	Osp::Base::String GetPhoneNumber (void) const;

	/**
	 * @if PRIVCORE
	 * Gets the International Mobile Subscriber Identity (IMSI) of the SIM card.
	 *
	 * @since					1.0
	 * @compatibility This method has compatibility issues with bada API versions @b prior @b to @b 1.1. @n
	 *                For more information, see @ref SimInfoPage "here".
	 * @privlevel   CORE
	 * @privgroup   USER_IDENTITY
	 *
	 * @return 		The IMSI of the SIM card, @n
     *              else an empty string if the method fails
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception	E_DEVICE_UNAVAILABLE	The operation has failed due to a missing SIM card @b since: @b 1.1.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.		 
	 *
	 * @remarks 	Do not use this method without obtaining prior permissions from the bada platform team.
	 *
	 * @endif
	 */
	Osp::Base::String GetImsi(void) const;


	/**
	 * Checks whether a SIM card is present in the device.
	 *
	 * @since			1.0
	 * @privlevel	NORMAL
	 * @privgroup TELEPHONY
	 *
	 * @return		@c true if the SIM card is present in the device, @n
	 *				else @c false
	 * @exception	E_SUCCESS				The method is successful.
	 * @exception   E_PRIVILEGE_DENIED      The application does not have the privilege to call this method.
	 */
	bool IsAvailable(void) const;

private:
	SimInfo(const SimInfo& value);
	SimInfo& operator =(const SimInfo& value);

private:
	ISimInfoPi* 	__iSimInfoInterface;
	
private:
	friend class SimInfoEx;
	class SimInfoEx* __pSimInfoEx;
};

        /**
         * @page   SimInfoPage Compatibility for SimInfo
         * @section SimInfoIssue Issues
         *                   Implementation of methods in bada API version prior to 1.1 has the following issue: @n
         *
         * -# Return E_SUCCESS when a SIM card is removed after the Construct() method is called.
         * @section SimInfoResolution Resolutions
         *  The issue mentioned above is resolved in bada API version 1.1 as follows. @n
         * -# From version 1.1, return E_DEVICE_UNAVAILABLE when a SIM card is removed after the Construct() method is called. @n
         */




};};
#endif // _FTEL_SIM_INFO_H_
