#include "ItemListForm.h"
#include "AnciiListElement.h"
#include "TitleListElement.h"
#include "FormManager.h"

#include "Debug.h"
#include "Retina.h"
#include "Helper.h"
#include "TextArtRegistry.h"

#include <FGrpFont.h>
#include <FApp.h>

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;
using namespace Osp::Graphics;
using namespace Osp::Base::Collection;

ItemListForm::ItemListForm():
	__pPopup(null)
{}

ItemListForm::~ItemListForm() { }

bool
ItemListForm::Initialize()
{
	/*TabsForm::Initialize(FORM_STYLE_INDICATOR | FORM_STYLE_TEXT_TAB | FORM_STYLE_TITLE | FORM_STYLE_SOFTKEY_1, TabsForm::CATEGORY_TAB);

	list.Construct();
	titlelist.Construct();
	formatlist.Construct();

	title = t;
	dir = d;

	SetTitleText(title);

	SetSoftkeyEnabled(SOFTKEY_1,true);
	SetSoftkeyText(SOFTKEY_1, Helper::GetTraslation("IDS_BACK"));
	SetSoftkeyActionId(SOFTKEY_1, SOFTKEY_BACK);
	AddSoftkeyActionListener(SOFTKEY_1, *this);
*/
	return true;
}

result
ItemListForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	TabsForm::OnInitializing();

	formatlist.Construct();
	anciilist.Construct();
	titlelist.Construct();
	filelist.Construct();

	DrawCustomList();
	//ReadCustomListItems();

	return r;
}

result
ItemListForm::DrawCustomList()
{
	Rectangle rect = this->GetClientAreaBounds();

	CategoryList = new CustomList();
	CategoryList->Construct(Rectangle(0, 0, this->GetWidth(), rect.height), CUSTOM_LIST_STYLE_NORMAL);
	CategoryList->AddCustomItemEventListener(*this);
	//CategoryList->SetTextOfEmptyList(Helper::GetTraslation("IDS_EMPTYLIST"));
	CategoryList->SetTextOfEmptyList("");
	CategoryList->SetShowState(false);
	this->AddControl(*CategoryList);

	empty = new Label();
	empty->Construct(Rectangle(0, 0, this->GetWidth(), 100), Helper::GetTraslation("IDS_EMPTYLIST"));
	empty->SetTextColor(Color::COLOR_BLACK);
	empty->SetBackgroundColor(Color(239,239,239));
	empty->SetShowState(true);
	this->AddControl(*empty);


	return E_SUCCESS;
}

result
ItemListForm::AddListItem(CustomList& CustomListPtr, String title, String ancii, int id, int linecount)
{
	CategoryList->SetShowState(true);
	CategoryList->SetBackgroundColor(Color(239,239,239));
	empty->SetShowState(false);
	CustomListItemFormat* pCustomListItemFormat = new CustomListItemFormat();
	pCustomListItemFormat->Construct();

	pCustomListItemFormat->AddElement(LIST_ELEMENT_TITLE, Rectangle(Retina::GetInt(10), Retina::GetInt(5), Retina::GetInt(220), Retina::GetInt(20)));
	pCustomListItemFormat->AddElement(LIST_ELEMENT_ANCII, Rectangle(Retina::GetInt(10), Retina::GetInt(30), Retina::GetInt(230), Retina::GetInt(linecount*16)));

	formatlist.Add(*pCustomListItemFormat);


	CustomListItem * newItem = new CustomListItem();

	AnciiListElement * custom_element = new AnciiListElement(ancii, Retina::GetInt(16));

	TitleListElement * custom_element2 = new TitleListElement(title, Retina::GetInt(20));

	formatlist.Add(*custom_element);
	formatlist.Add(*custom_element2);
	int height = (Retina::GetInt(linecount*16))+(Retina::GetInt(40));
	newItem->Construct(height);
	newItem->SetItemFormat(*pCustomListItemFormat);


	newItem->SetElement(LIST_ELEMENT_TITLE, *(static_cast<ICustomListElement *>(custom_element2)));
	newItem->SetElement(LIST_ELEMENT_ANCII, *(static_cast<ICustomListElement *>(custom_element)));

	CustomListPtr.AddItem(*newItem, id);
	return E_SUCCESS;
}

result
ItemListForm::OnTerminating(void)
{
	result r = E_SUCCESS;

	if(__pPopup != null) {
		delete __pPopup;
	}

	anciilist.RemoveAll(true);
	titlelist.RemoveAll(true);
	filelist.RemoveAll(true);
	formatlist.RemoveAll(true);

	return r;
}

result
ItemListForm::ClearList()
{
	CategoryList->RemoveAllItems();

	CategoryList->SetShowState(false);
	empty->SetShowState(true);

	anciilist.RemoveAll(true);
	titlelist.RemoveAll(true);
	filelist.RemoveAll(true);
	formatlist.RemoveAll(true);
	return E_SUCCESS;
}

result
ItemListForm::RedrawList()
{
	CategoryList->RequestRedraw(true);
	return E_SUCCESS;
}

result
ItemListForm::SetEmptyText(String text)
{
	//CategoryList->SetTextOfEmptyList(text);
	empty->SetText(text);
	return E_SUCCESS;
}

void
ItemListForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	TabsForm::OnActionPerformed(source, actionId);

	switch (actionId) {
				case BUTTON_SENDSMS:
				{

					 ArrayList* pDataList = new ArrayList();
					 String* pData = new String(L"type:SMS");
					 String* pData2 = new String("text:"+anciitext);
					 //String* pData4 = new String(L"text:LAbas");
					 String* pData3 = new String(L"to:");

					 pDataList->Construct();
					 pDataList->Add(*pData);
					 pDataList->Add(*pData2);
					 //pDataList->Add(*pData4);
					 pDataList->Add(*pData3);

					 AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_MESSAGE, OPERATION_EDIT);
					 if(pAc) {
						 pAc->Start(pDataList, null);
						  delete pAc;
					  }

					  pDataList->RemoveAll(true);
					  delete pDataList;

					  HidePopup();
				}
					break;
				case BUTTON_COPY:
				{
					ClipboardItem item;
					item.Construct(CLIPBOARD_DATA_TYPE_TEXT, anciitext);

					Clipboard* pClipboard = Clipboard::GetInstance();
					pClipboard->CopyItem(item);

					HidePopup();
					//RequestRedraw(true);
					//delete e;
				}
						break;
				case BUTTON_SENDEMAIL:
				{
					ArrayList* pDataList = new ArrayList();
					String* pData2 = new String(L"text:"+anciitext);

					pDataList->Construct();
					pDataList->Add(*pData2);

					AppControl* pAc = AppManager::FindAppControlN(APPCONTROL_EMAIL, OPERATION_EDIT);
					if(pAc)
					{
						pAc->Start(pDataList, null);
					    delete pAc;
					}

					pDataList->RemoveAll(true);
					delete pDataList;
					HidePopup();
				}
				break;
				case BUTTON_CANCEL:
					{ HidePopup(); }
				break;

				case BUTTON_ADDTOFAVOURITES:
				{
					TextArtRegistry::AddFavourite(filename);
					HidePopup();
				}
				break;
				case BUTTON_REMOVEFROMFAVOURITES:
				{
					TextArtRegistry::RemoveFavourite(filename);
					HidePopup();
				}
				break;
				default:
					break;
			}

	if(actionId == ItemListForm::BUTTON_SENDSMS || actionId == ItemListForm::BUTTON_SENDEMAIL || actionId == ItemListForm::BUTTON_COPY) {
			TextArtRegistry::AddRecent(filename);
	}
}

void
ItemListForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status)
{
	OnItemStateChanged(source, index, itemId, 0, status);
}

void
ItemListForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status)
{
	String ancii = *(static_cast<String*> (anciilist.GetAt(itemId)));
	String title = *(static_cast<String*> (titlelist.GetAt(itemId)));
	String file = *(static_cast<String*> (filelist.GetAt(itemId)));

	anciitext = ancii;
	filename = file;

	ShowPopup(title, ancii);
}

void
ItemListForm::HidePopup() {
	__pPopup->SetShowState(false);
	//__pPopup->Draw();

	//Draw();
	//Show();
	__pPopup->RemoveAllControls();
	delete __pPopup;
	__pPopup = null;
}

void
ItemListForm::ShowPopup(String title, String sms)
{
	__pPopup = new Popup();
	Dimension dim(Retina::GetInt(222), Retina::GetInt(222));
	__pPopup->Construct(true, dim);
	__pPopup->SetTitleText(title);

	AppResource *pAppResource = Application::GetInstance()->GetAppResource();

	if(anciitext.GetLength() > 80) {
		//pApp->GetAppResource()->GetString("IDS_TOOLONG", toolong);

		Label* lbl = new Label();
		lbl->Construct(Rectangle(0, Retina::GetInt(4), Retina::GetInt(190), Retina::GetInt(42)), Helper::GetTraslation("IDS_TOOLONG"));
		lbl->SetTextConfig(Retina::GetInt(12), LABEL_TEXT_STYLE_NORMAL);
		lbl->SetBackgroundColor(Osp::Ui::Controls::SYSTEM_COLOR_POPUP_BACKGROUND);
		__pPopup->AddControl(*lbl);
	}
	else {
		Button* bnt1 = new Button();
		bnt1->Construct(Rectangle(Retina::GetInt(40), Retina::GetInt(5), Retina::GetInt(65), Retina::GetInt(65)));
		bnt1->SetActionId(BUTTON_SENDSMS);
		bnt1->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"sms.png"));
		bnt1->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"sms_p.png"));
		bnt1->AddActionEventListener(*this);
		__pPopup->AddControl(*bnt1);
	}

		/*e = new EditArea();
		e->Construct(Rectangle(Retina::GetInt(5), Retina::GetInt(51), Retina::GetInt(50), Retina::GetInt(40)));
		e->SetText(sms);
		e->SetShowState(false);
		__pPopup->AddControl(*e);*/

		Button* bnt2 = new Button();
		bnt2->Construct(Rectangle(Retina::GetInt(40), Retina::GetInt(75), Retina::GetInt(65), Retina::GetInt(65)));
		bnt2->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"copy.png"));
		bnt2->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"copy_p.png"));
		bnt2->SetActionId(BUTTON_COPY);
		bnt2->AddActionEventListener(*this);
		if(anciitext.GetLength() > 80)
			{
			bnt2->SetBounds(Rectangle(Retina::GetInt(75), Retina::GetInt(50), Retina::GetInt(65), Retina::GetInt(65)));
			}
		__pPopup->AddControl(*bnt2);

		Button* bnt3 = new Button();
		bnt3->Construct(Rectangle(Retina::GetInt(110), Retina::GetInt(5), Retina::GetInt(65), Retina::GetInt(65)));
		bnt3->SetActionId(BUTTON_SENDEMAIL);
		bnt3->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"mail.png"));
		bnt3->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"mail_p.png"));
		bnt3->AddActionEventListener(*this);
		if(anciitext.GetLength() > 80)
			{
			bnt3->SetBounds(Rectangle(Retina::GetInt(5), Retina::GetInt(50), Retina::GetInt(65), Retina::GetInt(65)));
			}
		__pPopup->AddControl(*bnt3);

		Button* bnt4 = new Button();
		bnt4->Construct(Rectangle(Retina::GetInt(110), Retina::GetInt(75), Retina::GetInt(65), Retina::GetInt(65)));
		if(tab_index_ == TabsForm::FAVOURITES_TAB) {
			//bnt4->SetText(Helper::GetTraslation("IDS_REMOVEFROMFAVOURITES"));
			bnt4->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"favorite_active.png"));
			bnt4->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"favorite_active_p.png"));
			bnt4->SetActionId(BUTTON_REMOVEFROMFAVOURITES);
			bnt4->AddActionEventListener(*this);
		}
		else {
			//bnt4->SetText(Helper::GetTraslation("IDS_ADDTOFAVOURITES"));
			bnt4->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"favorite.png"));
			bnt4->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"favorite_p.png"));
			bnt4->SetActionId(BUTTON_ADDTOFAVOURITES);
			bnt4->AddActionEventListener(*this);
		}
		if(anciitext.GetLength() > 80)
			{
			bnt4->SetBounds(Rectangle(Retina::GetInt(145), Retina::GetInt(50), Retina::GetInt(65), Retina::GetInt(65)));
			}
		__pPopup->AddControl(*bnt4);

		Button* bnt5 = new Button();
		bnt5->Construct(Rectangle(Retina::GetInt(180), Retina::GetInt(145), Retina::GetInt(28), Retina::GetInt(28)));
		bnt5->SetNormalBackgroundBitmap(*pAppResource->GetBitmapN(L"cancel.png"));
		bnt5->SetPressedBackgroundBitmap(*pAppResource->GetBitmapN(L"cancel_p.png"));
		bnt5->SetActionId(BUTTON_CANCEL);
		bnt5->AddActionEventListener(*this);
		__pPopup->AddControl(*bnt5);

	__pPopup->SetShowState(true);
	__pPopup->Show();
}
