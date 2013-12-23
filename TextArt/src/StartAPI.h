#ifndef STARTAPI_H_
#define STARTAPI_H_

#include <FApp.h>
#include <FBase.h>
#include <FSystem.h>
#include <FNet.h>
#include <FSecurity.h>
#include <FText.h>
#include <FUi.h>

using namespace Osp::Base;
using namespace Osp::System;
using namespace Osp::Net::Http;

class StartAPI :
	public Osp::Net::Http::IHttpTransactionEventListener,
	public Osp::Net::Wifi::IWifiManagerEventListener
{
public:
	enum PlatformOS
	{
		Bada = 0,
		Tizen = 1,
		Android = 2,
		iOS = 3,
		WP8 = 4
	};
	StartAPI();
	~StartAPI();
public:
	String body[8][2];
	String _Body;

	void CreateBody(void);
	void MD5(Osp::Base::String mac);
	void POST(void);

private:
	void OnWifiActivated(result r);
	void OnWifiDeactivated(result r);
	void OnWifiConnected(const Osp::Base::String& ssid, result r);
	void OnWifiDisconnected(void);
	void OnWifiRssiChanged(long rssi);
	void OnWifiScanCompletedN(const Osp::Base::Collection::IList* pWifiBssInfoList, result r);
	void OnTransactionReadyToRead(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, int availableBodyLen);
	void OnTransactionAborted(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, result r) {}
	void OnTransactionReadyToWrite(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, int recommendedChunkSize);
	void OnTransactionHeaderCompleted(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, int headerLen, bool bAuthRequired) {}
	void OnTransactionCompleted(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction);
	void OnTransactionCertVerificationRequiredN(Osp::Net::Http::HttpSession& httpSession, Osp::Net::Http::HttpTransaction& httpTransaction, Osp::Base::String* pCert) {}

private:
	Osp::Net::Http::HttpSession* 	__pHttpSession;
	bool		 					__isLastData;
};
#endif


