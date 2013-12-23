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
 * @file			FMediaTone.h
 * @brief			This is the header file for the %Tone class.
 *
 * This header file contains the declarations of the %Tone class.
 */

#ifndef _FMEDIA_TONE_H_
#define _FMEDIA_TONE_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaToneCommon.h"

namespace Osp{ namespace Media{

/**
 * @class		Tone
 * @brief		This class generates a tone.
 * @since		2.0
 *
 * @remarks
 * The instance of the %Tone class can be played using ::TonePlayer.
 *
 * The %Tone class generates a tone and provides methods for:
 * - Generating a single tone.
 * - Generating dual tones with two different values of frequencies.
 * - Generating a silent tone for a specified period of interval.
 *
 *
 * The following example demonstrates how to use the %Tone class.
 *
 * @code 
 * #include <FMediaToneCommon.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::Media;
 *
 * result TestDTMFPresetTone()
 * {
 * 	   result r = E_SUCCESS;
 * 	   Tone* pDTMFPresetTone = null;
 *     int firstFrequency, secondFrequency;
 * 	   long duration;
 * 
 * 	   pDTMFPresetTone = new Tone();
 * 
 * 	   // Construct Tone of DTMF_PRESET_0 with duration 1000 milliseconds.
 * 	   r = pDTMFPresetTone->Construct(DTMF_PRESET_0,1000);
 * 	   if (IsFailed(r)) goto CATCH;
 *   
 * 	   r = pDTMFPresetTone->GetFrequency(firstFrequency,secondFrequency);
 * 	   if (IsFailed(r)) goto CATCH;
 *    
 * 	   duration = pDTMFPresetTone->GetDuration();
 *    
 * 	   CATCH:
 * 	   delete pDTMFPresetTone;
 *    
 * 	   return r;
 * }
 *    
 * result UserDefinedTones()
 * {
 * 	   result r = E_SUCCESS;
 *    
 * 	   Tone* pTone = null;
 * 	   Tone* pSilenetTone = null;
 *    
 * 	   int firstFrequency,secondFrequency;
 * 	   long duration;
 *    
 * 	   // Construct tone with 4000Hz and 5000Hz frequency and duration 2000 milliseconds.
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(4000,5000,2000);
 *     if (IsFailed(r)) goto CATCH;
 *    
 * 	   r = pTone->GetFrequency(firstFrequency,secondFrequency);
 * 	   if (IsFailed(r)) goto CATCH;
 *    
 * 	   duration = pTone->GetDuration();
 *    
 * 	   // Construct a silent tone(Both the frequencies will be zero) for duration 300 milliseconds.
 * 	   pSilenetTone = new Tone();
 * 	   r = pSilenetTone->Construct(0,0,300);
 * 	   if (IsFailed(r)) goto CATCH;
 *    
 * 	   r = pSilenetTone->GetFrequency(firstFrequency,secondFrequency);
 * 	   if (IsFailed(r)) goto CATCH;
 *    
 * 	   duration = pSilenetTone->GetDuration();
 *    
 * 	   CATCH:
 * 	   delete pTone;
 * 	   delete pSilenetTone;
 *    
 * 	   return r;
 * }
 * 
 * @endcode
 */
class _EXPORT_MEDIA_ Tone :
		public Osp::Base::Object
{

// Lifecycle

public:
	/**
	 *	This is the default constructor for this class.
	*
	*   @since 2.0
	*	@remarks	After creating an instance of this class, one of the Construct() methods must be called explicitly to initialize this instance.
	*	@see		Construct()
	*/
	Tone(void);

	/**
	*	This is the destructor for this class. @n
	*	The resources are deallocated by this method.
	*	This method must be called in the same thread as the Construct() method.
	*
	*   @since 2.0
	*	@see		Construct()
	*/
	virtual ~Tone(void);

// Operation
public:

	/**
	 *	Initializes this instance of the %Tone class with the values of the specified tone.
	*
	*   @since 2.0
	*	@return		An error code
	*	@param[in]	firstFrequency					The first frequency of the dual tone in Hertz @n
													The range of this parameter is @c 0 Hz ~ @c 15000 Hz.
	*	@param[in]	secondFrequency					The second frequency of the dual tone in Hertz @n
													The range of this parameter is @c 0 Hz ~ @c 15000 Hz.
	*	@param[in]	duration						The duration of the tone in milliseconds @n
													The value of this parameter must be greater than @c 0.
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OUT_OF_RANGE					A specified input parameter is out of range.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*
	*	@remarks If both the input frequencies are @c 0 Hz, the tone is set as a silent tone.
	*/
	result Construct(int firstFrequency, int secondFrequency, long duration);


	/**
	*	Initializes this instance of the %Tone class with the values of the specified DTMF preset tone.
	*
	*   @since 2.0
	*	@return		An error code
	*	@param[in]	preset							The preset of the DTMF tone
	*	@param[in]	duration						The duration of the tone in milliseconds @n
													The value of this parameter must be greater than @c 0.
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_OUT_OF_RANGE					A specified input parameter is out of range.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*/
	result Construct(DtmfPreset preset, long duration);


	/**
	*	Gets the current frequency.
	*
	*   @since 2.0
	*	@return		An error code
	*	@param[out]	firstFrequency					The first frequency of the dual tone in Hertz
	*	@param[out]	secondFrequency					The second frequency of the dual tone in Hertz
	*	@exception	E_SUCCESS						The method is successful.
	*	@exception	E_INVALID_STATE					This method is invalid for the current state of this instance.
	*
	*	@remarks The specified input parameters of this method are @c -1 when an exception occurs.
	*/
	result GetFrequency(int& firstFrequency, int& secondFrequency) const;

	/**
	*	Gets the current duration.
	*
	*   @since 2.0
	*	@return		The duration of the tone
	*
	*	@remarks This method returns @c 0 before the Construct() method is called.
	*/
	long GetDuration(void) const;

private:
	Tone(const Tone& tone);
	Tone& operator =(const Tone& tone);

	friend class ToneEx;
	class ToneEx* __pToneEx;

	int __firstFrequency;
	int __secondFrequency;
	long __duration;
	bool __IsConstructed;
};

};}; // Osp::Media

#endif

