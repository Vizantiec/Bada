#include "StartAPI.h"
#include <FNet.h>

using namespace Osp::Base::Utility;
using namespace Osp::Net::Wifi;
using namespace Osp::Security::Crypto;
using namespace Osp::Text;
using namespace Osp::App;

StartAPI::StartAPI()
{
	__isLastData = false;
	body[0][0] = "\"udid\":";
	body[1][0] = "\"app\":";
	body[2][0] = "\"app_version\":";
	body[3][0] = "\"action\":";
	body[4][0] = "\"os\":";
	body[5][0] = "\"os_version\":";
	body[6][0] = "\"device\":";
	body[7][0] = "\"token\":";
}

StartAPI::~StartAPI()
{
}

void
StartAPI::CreateBody(void)
{
	 WifiManager* _pWifiManager = new WifiManager();
	 _pWifiManager->Construct(*this);
	 String macAddress = _pWifiManager->GetMacAddress();
	 for(int i=0; i<5; i++)
	 {
		 int k;
		 macAddress.IndexOf('-', 0, k);
		 macAddress.Remove(k, 1);
	 }
	 body[0][1] = macAddress;
	 AppLog("udid: %ls", body[0][1].GetPointer());
	 body[1][1] = Application::GetInstance()->GetAppName();
	 AppLog("app: %ls", body[1][1].GetPointer());
	 body[2][1] = Application::GetInstance()->GetAppVersion();
	 AppLog("app_version: %ls", body[2][1].GetPointer());
	 body[3][1] = "start";
	 body[4][1] = "Bada";
	 String key(L"PlatformVersion");
	 SystemInfo::GetValue(key, body[5][1]);
	 //SystemInfo::GetImei(body[6][1]);
	 for(int i=0; i<8; i++)
	 {
		 if(body[i][1]!="")
		 {
			 _Body.Append(body[i][0]+"\""+body[i][1]+"\",");
		 }
	 }
	 _Body.Insert('{',0);
	 _Body.SetCharAt('}', _Body.GetLength()-1);
	 AppLog("%ls", _Body.GetPointer());
	 POST();
	 //MD5(macAddress);
}

void
StartAPI::POST(void)
{
	String* pProxyAddr = null;
	String hostAddr = L"api.mobigear.ru";
	String uri = L"api.mobigear.ru/stats";
	HttpHeader* pHeader = null;
	HttpTransaction* pHttpTransaction = null;

	// Create HTTP Session
	__pHttpSession = new HttpSession();
	__pHttpSession->Construct(NET_HTTP_SESSION_MODE_NORMAL, pProxyAddr, hostAddr, null);

	// Open a new Http Transaction within the HttpSession
	pHttpTransaction = __pHttpSession->OpenTransactionN();

	// Add Listener
	// OnTransactionCompleted() will be called when response is arrived
	pHttpTransaction->AddHttpTransactionListener(*this);

	// Get Http Request
	HttpRequest* pHttpRequest = pHttpTransaction->GetRequest();

	// Set HTTP Method
	pHttpRequest->SetMethod(NET_HTTP_METHOD_POST);

	// Set Uri
	pHttpRequest->SetUri(uri);

	//Set a Body to Request.
	ByteBuffer reqBody;

	const char* pBodyArray = null;
	ByteBuffer* _pByteBuffer = null;
	_pByteBuffer = StringUtil::StringToUtf8N(_Body);
	pBodyArray= (const char*) _pByteBuffer ->GetPointer();
	int len = strlen(pBodyArray);
	reqBody.Construct(len);
	reqBody.SetArray((byte*)pBodyArray, 0, len);
	reqBody.Flip();
	String lengthAsString;
	lengthAsString.Append(len);

	// Fill HTTP Header
	pHeader = pHttpRequest->GetHeader();
	pHeader->AddField(L"Content-Type", L"application/json");
	pHeader->AddField(L"Accept", L"application/json");
	pHeader->AddField(L"Cache-Control", L"no-cache");
	pHeader->AddField(L"Content-Length", lengthAsString);

	//Enable OnTransactionReadyToWrite()
	pHttpTransaction->EnableTransactionReadyToWrite();

	pHttpRequest->WriteBody(reqBody);
	// Submit a request
	pHttpTransaction->Submit();
}

void
StartAPI::OnTransactionReadyToRead(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
{
	ByteBuffer *pBody = null;
	HttpResponse* pHttpResponse = null;
	HttpHeader* pHttpHeader = null;

	// Get Response
	pHttpResponse = httpTransaction.GetResponse();

	// Check the Status Code
	if (pHttpResponse->GetHttpStatusCode() == HTTP_STATUS_OK)
	{
		// Get Http Header
		pHttpHeader = pHttpResponse->GetHeader();

		// Read the body from the HttpResponse
		pBody = pHttpResponse->ReadBodyN();
		AppLog("HTTP_STATUS_OK");

		delete pBody;
	}
	AppLog("HTTP_STATUS_FALSE");
}

void
StartAPI::OnTransactionReadyToWrite(HttpSession& httpSession, HttpTransaction& httpTransaction, int recommendedChunkSize)
{
	HttpTransaction* pTransaction = &httpTransaction;
	HttpRequest* pRequest = pTransaction->GetRequest();
	ByteBuffer body;
	result r = E_SUCCESS;
	AppLog("__isLastData = %d", __isLastData);
	if(__isLastData)
	{
		//Set a last chunked flag.
		body.Construct(0);
		body.Flip();
		r =pRequest->WriteBody(body);
	} else
	{
		//Set a chunked data.
		const char* pBodyArray = "{\"udid\":\"test123\",\"app\":\"test\",\"app_version\":\"1.0\",\"action\":\"start\"}";
		body.Construct(strlen(pBodyArray));
		r = body.SetArray((byte*)pBodyArray,0,strlen(pBodyArray));
		body.Flip();
		r =pRequest->WriteBody(body);
		__isLastData = true;
	}
}

void
StartAPI::OnTransactionCompleted(HttpSession& httpSession, HttpTransaction& httpTransaction)
{
	delete &httpTransaction;
	AppLog("OnTransactionCompleted");
}

void
StartAPI::MD5(String mac)
{
	// to bytebuffer
	ByteBuffer* pOutput = StringUtil::StringToUtf8N(mac);
	pOutput->SetLimit(pOutput->GetCapacity()-1);
	// Md5Hash
	Md5Hash test;
	ByteBuffer* out1 = test.GetHashN(*pOutput);
	byte tmp;
	out1->GetByte(tmp);
	String str;
	str.Append((String)tmp);
	AppLog("str: %ls", str.GetPointer());
	// print string
	Utf8Encoding utf8;
	String strUtf8;
	utf8.GetString(*pOutput, strUtf8);
	const byte* pActualOutput = static_cast<const byte*>(out1->GetPointer());
	for (int i = 0; i < 16; i++)
	{
		AppLog("pActualOutput[] %x", pActualOutput[i]);
	}
	AppLog("strUtf8: %ls", strUtf8.GetPointer());
}

void
StartAPI::OnWifiActivated(result r)
{

}

void
StartAPI::OnWifiDeactivated(result r)
{

}

void
StartAPI::OnWifiConnected(const Osp::Base::String& ssid, result r)
{

}

void
StartAPI::OnWifiDisconnected(void)
{

}

void
StartAPI::OnWifiRssiChanged(long rssi)
{

}

void
StartAPI::OnWifiScanCompletedN(const Osp::Base::Collection::IList* pWifiBssInfoList, result r)
{

}
