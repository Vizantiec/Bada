/* $Change: 1142016 $ */
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
 * @file		FWebCtrlIWebDownloadListener.h
 * @brief		This is the header file for the %IWebDownloadListener interface.
 *
 * This header file contains the declarations of the %IWebDownloadListener interface.
 */


#ifndef _FWEB_IWEBDOWNLOADLISTENER_H_
#define _FWEB_IWEBDOWNLOADLISTENER_H_

#include "FBase.h"
#include "FWebConfig.h"

namespace Osp { namespace Web { namespace Controls {


/**
 * @interface	IWebDownloadListener
 * @brief		This interface downloads data from the internet.
 * @since	1.0
 *
 * The %IWebDownloadListener interface downloads data from the internet.
 * An application receives content from a network incrementally 
 * when it decides to download the content after checking the Multipurpose Internet Mail Extensions (MIME).
 * This is useful when the content is not supported by the framework itself and the application wants to handle it.
 *
 * For more information on the class features, see <a href="../com.osp.cppappprogramming.help/html/dev_guide/web/controls_namespace.htm">Web Controls Guide</a>.
 *
 * The following examples demonstrate how to use the %IWebDownloadListener interface.
 *	@code
 *
 *	#include <FWeb.h>
 *	#include <FUiControls.h>
 *
 *	using namespace Osp::Web;
 *	using namespace Osp::Ui::Controls;
 *	
 *
 *	// Adds Web control to parent container
 *	result
 *	WebSample::CreateControl(Form* pParentForm)
 *	{
 *		result r = E_SUCCESS;
 *
 *		pWeb = new Web();
 *		r = pWeb->Construct( pParentForm->GetClientAreaBounds());
 *		r = pParentForm->AddControl(*pWeb);
 *		
 *	 	//Sets ILoadingListener and IWebDownloadListener
 *		pWeb->SetDownloadListener(pMyDownloadListener);
 *		pWeb->SetLoadingListener(pMyLoadingListener);
 *	
 *		return r;
 *	}
 *	
 *	@endcode
 *	
 *
 *	As soon as the first chunk of data is received, OnWebDataReceived() is fired with the MIME type.
 *	If you want to download the data, return WEB_DECISION_DOWNLOAD.
 * 
 *	@code
 *	DecisionPolicy 
 *	MyLoadingListener::OnWebDataReceived(const Osp::Base::String& mime, const Osp::Net::Http::HttpHeader& header)
 *	{
 *		return WEB_DECISION_DOWNLOAD;
 *	}
 *	
 *	@endcode
 *	
 * 	Then, the data is routed to OnWebChunkedDataReceived().
 *
 *	@code
 *	void 
 *	MyDownloadListener::OnWebChunkedDataReceived(Osp::Base::ByteBuffer& chunk)
 *	{
 *		//Application handles the data.
 *	}
 *	
 *	@endcode
 */


class _EXPORT_WEB_ IWebDownloadListener :
	public Osp::Base::Runtime::IEventListener
{

public:

	/**
	 * This is the destructor for this class.
	 *
	 * @since	1.0
	 */
	virtual ~IWebDownloadListener(void) {}

	/**	 
   * Called when the HyperText Transfer Protocol (HTTP) protocol receives the next chunked data.
	 *
	 * @since				1.0 	 
	 * @param[in]		chunk		The chunked data 
	 * @remarks     The received data size is less than the capacity of the specified %ByteBuffer by 1. 
   	 */	
	virtual void OnWebChunkedDataReceived(const Osp::Base::ByteBuffer& chunk) = 0;

	/**	 
	  * Called when the downloading of the content is completed.
	  *
	  * @since	1.0
	  */	
	virtual void OnWebDataDownloadCompleted(void) = 0;

	/**
	* Called when an error has occurred while downloading content.
	*
	* @since                  1.0
	* @compatibility     This method has compatibility issues with bada API versions @b prior @b to @b 2.0. @n
	*                                 For more information, see @ref CompLoadingErrorType "here".
	* @param[in]          error                           The type of error that occurred while downloading data
	*/              
	virtual void OnWebDownloadFailed(LoadingErrorType error) = 0;

};

}; };};
#endif

