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
 * @file			FMediaTonePlayer.h
 * @brief			This is the header file for the %TonePlayer class. 
 *
 * This header file contains the declarations of the %TonePlayer class.
 */

#ifndef _FMEDIA_TONEPLAYER_H_
#define _FMEDIA_TONEPLAYER_H_

// Include
#include <FBase.h>
#include <FMediaAudioOut.h>
#include "FMediaConfig.h"
#include "FMediaTone.h"
#include "FMediaITonePlayerEventListener.h"

namespace Osp{ namespace Media{
class __TonePlayerImp;
class ITonePlayerEventListener;

/**
 * @class		TonePlayer
 * @brief		This class plays the tone(s).
 * @since		2.0
 *
 * @remarks
 * The maximum number of the %TonePlayer instance is @c 64. This number is a system wide count so that the application should not be able to construct instances more than the maximum number.
 *
 * The %TonePlayer class provides the methods for:
 * - Playing the tone(s) 
 * - Controlling a tone player instance
 *
 * The following example demonstrates how to use the %TonePlayer class for playing a single tone and a list of tones.
 *
 * @code
 * #include <FMediaToneCommon.h>
 * #include <FMediaTone.h>
 * #include <FMediaITonePlayerEventListener.h>
 *
 * using namespace Osp::Base;
 * using namespace Osp::Media;
 *
 * class MyTonePlayerEventListener:
 *	 public ITonePlayerEventListener
 * {
 *     virtual void OnTonePlayerEndOfTone(Osp::Media::TonePlayer& src);
 *	   virtual void OnTonePlayerInterrupted(Osp::Media::TonePlayer& src);
 *	   virtual void OnTonePlayerReleased(Osp::Media::TonePlayer& src);
 *	   virtual void OnTonePlayerErrorOccurred(Osp::Media::TonePlayer& src, result r);
 * };
 *
 *
 * static MyTonePlayerEventListener* pListener = null;
 *
 * void
 * MyTonePlayerEventListener::OnTonePlayerEndOfTone(Osp::Media::TonePlayer& src)
 * {
 *	  // Insert your code to operate after the end of tone is reached.
 * }
 * 
 * void
 * MyTonePlayerEventListener::OnTonePlayerInterrupted(Osp::Media::TonePlayer& src)
 * {
 * 	   // Insert your code to operate after TonePlayer is interrupted.
 * }
 * 
 * void
 * MyTonePlayerEventListener::OnTonePlayerReleased(Osp::Media::TonePlayer& src)
 * {
 * 	   // Insert your code to operate after TonePlayer is released.
 * }
 * 
 * void
 * MyTonePlayerEventListener::OnTonePlayerErrorOccurred(Osp::Media::TonePlayer& src, result r)
 * {
 * 	   // Insert your code to operate after an error occurs.
 * }
 * 
 * result testSingleTonePlay()
 * {
 * 	   result r = E_SUCCESS;
 * 
 * 	   Tone	*pTone = null;
 *     TonePlayer	*pTonePlayer = null;
 * 
 *     // Construct Tone.
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(DTMF_PRESET_S,2000);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   pListener	= new MyTonePlayerEventListener();
 * 	   pTonePlayer = new TonePlayer();
 * 
 * 	   // Construct TonePlayer.
 * 	   r = pTonePlayer->Construct(*pListener);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   // Open TonePlayer with single tone as argument.
 * 	   r = pTonePlayer->Open(*pTone,5);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Play();
 * 	   if (IsFailed(r)) goto CATCH; 
 * 
 * 	   r = pTonePlayer->Pause();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Play();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Stop();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Close();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   CATCH:
 * 	   if (pTonePlayer)
 * 		   delete pTonePlayer;
 * 	   if (pTone)
 * 		   delete pTone;
 * 	   if (pListener)
 * 	   delete pListener;
 * 
 * 	   return r;
 * }
 *
 *
 * result testListTonePlay()
 * {
 * 	   result r = E_SUCCESS;
 * 
 * 	   Osp::Base::Collection::ArrayList *pToneList = null;
 * 	   Tone	*pTone = null;
 * 	   TonePlayer	*pTonePlayer = null;
 * 
 * 	   // Create a list to hold five Tone instances.
 * 	   pToneList = new Osp::Base::Collection::ArrayList();
 * 	   r = pToneList->Construct(5);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   // Construct and Add Tones to ToneList.
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(DTMF_PRESET_1,2000);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pToneList->Add(*pTone);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(2000,5000,3000);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pToneList->Add(*pTone);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(DTMF_PRESET_8,500);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pToneList->Add(*pTone);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   // Constructing silent tone.
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(0,0,1500);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pToneList->Add(*pTone);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   pTone = new Tone();
 * 	   r = pTone->Construct(10000,14000,2500);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pToneList->Add(*pTone);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   pListener	= new MyTonePlayerEventListener();
 * 	   pTonePlayer = new TonePlayer();
 * 
 * 	   r = pTonePlayer->Construct(*pListener);
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   // Open TonePlayer with Tone list argument.
 * 	   r = pTonePlayer->Open(*pToneList,2);
 * 	   if(IsFailed(r)) goto CATCH;
 *  
 * 	   r = pTonePlayer->Play();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Pause();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Play();
 * 	   if (IsFailed(r)) goto CATCH;
 *   
 *     r = pTonePlayer->Stop();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   r = pTonePlayer->Close();
 * 	   if (IsFailed(r)) goto CATCH;
 * 
 * 	   CATCH:
 * 	   if (pTonePlayer)
 * 		   delete pTonePlayer;
 * 	   if (pToneList)
 * 	   {
 * 		   pToneList->RemoveAll(true);
 * 		   delete pToneList;
 * 	   }
 * 	   if (pListener)
 * 		   delete pListener;
 * 
 * 	   return r;
 * }
 *
 * @endcode
 */

class _EXPORT_MEDIA_ TonePlayer :
	public Osp::Base::Object
{

// Lifecycle

public:

	/**
	 * This is the default constructor for this class.
	 *
	 * @since 		2.0
     * @remarks		After creating an instance of this class, the Construct() method must be 
	 *				called explicitly to initialize this instance
	 * @see			Construct()
	 */
	TonePlayer(void);

	/**
	 * This is the destructor for this class. @n
	 * All the allocated resources are released by this method. @n
	 * This method should be called in the same thread as the Construct() method.
	 *
	 * @since		2.0
	 * @see			Construct()
	 */
	virtual ~TonePlayer(void);

	/**
	* Initializes this instance of the %TonePlayer with the specified listener.
	*
	* @since 		2.0
	* @return		An error code
	* @param[in]	listener				An ITonePlayerEventListener instance
	* @exception	E_SUCCESS				The method is successful.
	* @exception	E_INVALID_STATE			This method is invalid for the current state of this instance.
	* @exception	E_RESOURCE_UNAVAILABLE	The tone player's resources are unavailable.
	* @exception	E_SYSTEM				A system error has occurred.
	*/
	result Construct( const Osp::Media::ITonePlayerEventListener& listener);

	/**
	* Opens the specified list of tones.
	*
	* @since 		2.0
	* @return		An error code
	* @param[in]	toneList			A list of Tone instances
	* @param[in]	repeatCount			The number of times the list of tones should be played @n
	*									This number is greater than or equal to @c 1.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OBJ_NOT_FOUND		The specified tone instance cannot be found in the list.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE		The count is out of range.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The item(s) of the specified @c toneList should be an instance(s) of ::Tone.
	* @see			Close()
	*/
	result Open(const Osp::Base::Collection::IList& toneList,  int repeatCount=1);

	/**
	* Opens the specified tone.
	*
	* @since 		2.0
	* @return		An error code
	* @param[in]	tone				The tone instance
	* @param[in]	repeatCount			The number of times a tone should be played @n
	*									This number is greater than or equal to @c 1.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_OUT_OF_MEMORY		The memory is insufficient.
	* @exception	E_OUT_OF_RANGE		The count is out of range.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Close()
	*/
	result Open(const Osp::Media::Tone& tone, int repeatCount=1);

	/**
	* Starts the playback or resumes the playback if Pause() has been called. @n
	* In case of the ::TONEPLAYER_STATE_ENDOFTONE state, the tone(s) can be played again.
	*
	* @since 		2.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_DEVICE_BUSY		The device is busy for other operations.
	* @exception	E_SYSTEM			A system error has occurred.
	* @remarks		The playback starts from the current position. If playback is paused, playback restarts from 
	*				the last position.
	* @see			Stop(), Pause()
	*/
	result Play(void);

	/**
	* Stops the playback.
	*
	* @since 		2.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Play(), Pause()
	*/
	result Stop(void);

	/**
	* Pauses the playback. @n
	* To resume the paused playback, call Play().
	*
	* @since 		2.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Play(), Stop()
	*/
	result Pause(void);


	/**
	* Sets the volume level.
	*
	* @since 		2.0
	* @return		An error code
	* @param[in]	volume				The new value for volume @n
	*						            The range of this parameter is @c 0 to @c 100 and it is proportional to the current media sound volume level in setting.
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_OUT_OF_RANGE		The specified @c volume parameter is out of range.
	* @exception	E_INVALID_STATE		This method is invalid for the current state of this instance.
	* @see			GetVolume()
	*/
	result SetVolume(int volume);

	/**
	* Gets the current volume level
	*
	* @since 		2.0
	* @return		The current volume level @n
	*				The range of this return value is @c 0 to @c 100.
	* @remarks		If the @c volume is not set, the default volume @c 50 is returned.
	* @see			SetVolume()
	*/
	int GetVolume(void) const;	

	/**
	* Closes the tone player.
	*
	* @since 		2.0
	* @return		An error code
	* @exception	E_SUCCESS			The method is successful.
	* @exception	E_INVALID_STATE     This method is invalid for the current state of this instance.
	* @exception	E_SYSTEM			A system error has occurred.
	* @see			Open()
	*/
	result Close(void);

	/**
	* Gets the current state of the tone player instance.
	*
	* @since 		2.0
	* @return		The current state of the tone player
	*/
	TonePlayerState GetState(void) const;

private:
	TonePlayer(const TonePlayer& tonePlayer);
	TonePlayer& operator =(const TonePlayer& tonePlayer);

	friend class TonePlayerEx;
	class TonePlayerEx* __pTonePlayerEx;
	__TonePlayerImp *__pTonePlayerImp;
};

};}; // Osp::Media

#endif

