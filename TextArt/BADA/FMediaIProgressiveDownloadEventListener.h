/* $Change: 405501 $ */
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
 * @if PRIVCORE
 *
 * @file		FMediaIProgressiveDownloadEventListener.h 
 * @brief		This is the header file for the %IProgressiveDownloadEventListener interface.
 *
 * This header file contains the declarations of the %IProgressiveDownloadEventListener interface.
 *
 * @endif
 */
 
#ifndef _FMEDIA_PROGRESSIVE_DOWNLOAD_EVENTLISTENER_H_
#define _FMEDIA_PROGRESSIVE_DOWNLOAD_EVENTLISTENER_H_

// Include
#include <FBase.h>
#include "FMediaConfig.h"
#include "FMediaProgressivePlayerCommon.h"


namespace Osp{ namespace Media{

class ProgressivePlayer;

/**
 *	@if PRIVCORE
 *
 * @interface	IProgressiveDownloadEventListener
 * @brief			This interface provides a listener for the events of ProgressivePlayer::OpenProgressiveUrl().
 * @since			1.2
 *
 * The %IProgressiveDownloadEventListener interface provides the methods used to notify the download status of the content from the ProgressivePlayer.
 *
 * @endif
 */
class _EXPORT_MEDIA_ IProgressiveDownloadEventListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	*	@if PRIVCORE
	*
	*	Called when the progressive download has started.
	*
	* @since			1.2
	* @param[in]	src				The instance of the ProgressivePlayer that sends this event
	*	@endif
	*/
	virtual void OnProgressiveDownloadStarted(Osp::Media::ProgressivePlayer &src) = 0;


	/**
	 *	@if PRIVCORE
	 *
	*	Called to notify the percentage of the downloaded content.
	*
	* @since			1.2
	* @param[in]	src				The instance of the ProgressivePlayer that sends this event
	*	@param[in]	percent			The percentage of the downloaded content
	*
	* @endif
	*/
	virtual void OnProgressiveDownloadInProgress(Osp::Media::ProgressivePlayer &src, int percent) = 0; 


	/**
	 *	@if PRIVCORE
	 *
	*	Called when the progressive download has ended.
	*
	* @since			1.2
	* @param[in]	src						The instance of the ProgressivePlayer that sends this event
	*	@param[in]	r						The result of progressive download
	*
	*	@exception	E_SUCCESS				The method is successful.
	*	@exception	E_CONNECTION_FAILED		The connection to a server has failed.
	*	@exception	E_INVALID_DATA			The content has invalid data.
	*	@exception	E_STORAGE_FULL			The storage is full.
	*	@exception	E_SYSTEM				A system error has occurred.
	*
	*	@endif
	*/
	virtual void OnProgressiveDownloadCompleted(Osp::Media::ProgressivePlayer &src, result r) = 0; 

};

};};// Osp::Media

#endif

