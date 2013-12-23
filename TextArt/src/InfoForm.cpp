#include "InfoForm.h"

#include "FormManager.h"
#include "Helper.h"
#include "TextArtRegistry.h"
#include "TextPic.h"
#include "Retina.h"

#include <FIoFile.h>
#include <FNet.h>

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

using namespace Osp::Locales;
using namespace Osp::System;
using namespace Osp::App;
using namespace Osp::Web::Controls;

InfoForm::InfoForm() {}

InfoForm::~InfoForm() {}

bool
InfoForm::Initialize()
{
	TabsForm::Initialize(FORM_STYLE_INDICATOR | FORM_STYLE_TITLE | FORM_STYLE_FOOTER, TabsForm::INFO_TAB);
	SetTitleText(Helper::GetTraslation("IDS_INFO"));

	__pFooter = TabsForm::GetFooter();
	__pFooter->SetStyle(FOOTER_STYLE_SEGMENTED_ICON);
	__pFooter->AddActionEventListener(*this);
	__pFooter->SetBackButton();
	SetFormBackEventListener(this);

	return true;
}

result
InfoForm::OnInitializing(void)
{
	Rectangle rect = this->GetClientAreaBounds();

	result r = E_SUCCESS;
	TabsForm::OnInitializing();

	AppResource *pAppResource = Application::GetInstance()->GetAppResource();
	Bitmap* _bitmap;

	CategoryList = new CustomList();
	CategoryList->Construct(Rectangle(0, 0, this->GetWidth(), rect.height), CUSTOM_LIST_STYLE_NORMAL);
	CategoryList->SetBackgroundColor(Color(239,239,239));
	CategoryList->AddCustomItemEventListener(*this);

	// Category element format
	pCustomListItemFormat = new CustomListItemFormat();
	pCustomListItemFormat->Construct();
	pCustomListItemFormat->AddElement(LIST_ELEMENT_IMG, Rectangle(Retina::GetInt(5), Retina::GetInt(5), Retina::GetInt(65), Retina::GetInt(65)));
	pCustomListItemFormat->AddElement(LIST_ELEMENT_DESC, Rectangle(Retina::GetInt(75), Retina::GetInt(5), Retina::GetInt(180), Retina::GetInt(120)),
		Retina::GetInt(12), Color(151,151,151), Osp::Ui::Controls::SYSTEM_COLOR_LIST_ITEM_PRESSED_TEXT);

	CreateArray();

	int i=0;
	// Adds an item to the CustomList
	while(__pProducts[i][0]->GetLength() == 12)
	{
		CustomListItem * newItem = new CustomListItem();

		newItem->Construct(Retina::GetInt(75));
		newItem->SetItemFormat(*pCustomListItemFormat);
		int k=0;
		Integer::Parse(*__pProducts[i][1], k);

		switch (k)
		{
			case 451549:
			case 451431:
				newItem->SetElement(LIST_ELEMENT_DESC, Helper::GetTraslation("IDS_SPACESHUFFLE"));
				_bitmap = pAppResource->GetBitmapN(L"Ikonka_512.png");
				break;
			case 53471:
				newItem->SetElement(LIST_ELEMENT_DESC, Helper::GetTraslation("IDS_UCONVERTOR"));
				_bitmap = pAppResource->GetBitmapN(L"uc_icon2.png");
				break;
			case 287131:
			case 287177:
			case 232222:
			case 279563:
				newItem->SetElement(LIST_ELEMENT_DESC, Helper::GetTraslation("IDS_sCalc"));
				_bitmap = pAppResource->GetBitmapN(L"scalc_icon.png");
				break;
		}
		newItem->SetElement(LIST_ELEMENT_IMG, *_bitmap, _bitmap);
		CategoryList->AddItem(*newItem, i);
		i++;
	}

	this->AddControl(*CategoryList);

	return r;
}

void
InfoForm::OnFormBackRequested(Osp::Ui::Controls::Form& form)
{
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormManager *pFormMgr = static_cast<FormManager *>(pFrame->GetControl("FormManager"));
	if (pFormMgr != null) {
		pFormMgr->SendUserEvent(FormManager::REQUEST_ITEMLIST, null);
	}
}

void
InfoForm::OnItemStateChanged(const Control& source, int index, int itemId, ItemStatus status)
{
    OnItemStateChanged(source, index, itemId, 0, status);
}

void
InfoForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status)
{
	GetProduct(index);
}

result
InfoForm::OnTerminating(void)
{
	result r = E_SUCCESS;
	delete pCustomListItemFormat;
	return r;
}

void
InfoForm::GetProduct(int index)
{
	result r = E_SUCCESS;
	String samsungapps;
	// get appId of Samsung Apps
	r = SystemInfo::GetValue("SamsungAppsAppId", samsungapps);
	AppLog("SamsungAppsAppId %s", r);

	ArrayList *pArrayList = new ArrayList();
	pArrayList->Construct();
	String *uri= new String();
	uri->Append(L"samsungapps://ProductDetail/"+*__pProducts[index][0]);
	pArrayList->Add(*uri);

	AppManager *pAppManager = AppManager::GetInstance();
	// Launch Samsung Apps with uri
	pAppManager->LaunchApplication(samsungapps, pArrayList, AppManager::LAUNCH_OPTION_DEFAULT);
}

void
InfoForm::CreateArray(void)
{
	versionAPI = 2;
	String key(L"APIVersion");
	String platformVersion = String("fail");
	SystemInfo::GetValue(key, platformVersion);
	float f;
	Float::Parse(platformVersion, f);
	versionAPI = (int) f;

	switch (this->GetWidth())
	{
		case 240:
			__pProducts[0][0]= new String("000000232222");
			__pProducts[0][1]= new String("232222");
			break;
		case 320:
			__pProducts[0][0]= new String(L"000000451549");
			__pProducts[0][1]= new String(L"451549");
			__pProducts[1][0]= new String(L"000000287131");
			__pProducts[1][1]= new String(L"287131");
			break;
		case 480:
			__pProducts[0][0]= new String(L"000000451431");
			__pProducts[0][1]= new String(L"451431");
			if(versionAPI == 2)
			{
				__pProducts[1][0]= new String(L"000000287177");
				__pProducts[1][1]= new String(L"287177");
			}
			else
			{
				__pProducts[1][0]= new String(L"000000279563");
				__pProducts[1][1]= new String(L"279563");
			}
			__pProducts[2][0]= new String(L"000000053471");
			__pProducts[2][1]= new String(L"53471");
			break;
	}
}
