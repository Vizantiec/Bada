#include "CategoryListForm.h"
#include "FormManager.h"

#include "AnciiListElement.h"
#include "Retina.h"
#include "Helper.h"
#include "TabsForm.h"

#include <FIoDirectory.h>
#include <FIoFile.h>
#include <FGrpFont.h>
#include <FApp.h>
#include <TextPic.h>

using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;
using namespace Osp::App;
using namespace Osp::Io;
using namespace Osp::Graphics;
using namespace Osp::App;

CategoryListForm::CategoryListForm(void) {}

CategoryListForm::~CategoryListForm(void) {}

bool
CategoryListForm::Initialize()
{
	TabsForm::Initialize(FORM_STYLE_INDICATOR | FORM_STYLE_TEXT_TAB | FORM_STYLE_TITLE, TabsForm::CATEGORY_TAB);

	SetTitleText(Helper::GetTraslation("IDS_TITLE"));

	list.Construct();
	titlelist.Construct();

	return true;
}

result
CategoryListForm::OnInitializing(void)
{
	Rectangle rect = this->GetClientAreaBounds();

	result r = E_SUCCESS;
	TabsForm::OnInitializing();

	CategoryList = new CustomList();
	CategoryList->Construct(Rectangle(0, 0, this->GetWidth(), rect.height), CUSTOM_LIST_STYLE_NORMAL);
	CategoryList->SetBackgroundColor(Color(239,239,239));
	CategoryList->AddCustomItemEventListener(*this);

	// Category element format
	pCustomListItemFormat = new CustomListItemFormat();
	pCustomListItemFormat->Construct();
	pCustomListItemFormat->AddElement(LIST_ELEMENT_ANCII, Rectangle(Retina::GetInt(5), Retina::GetInt(5), Retina::GetInt(100), Retina::GetInt(65)));
	pCustomListItemFormat->AddElement(LIST_ELEMENT_TITLE, Rectangle(Retina::GetInt(105), Retina::GetInt(5), Retina::GetInt(130), Retina::GetInt(20)),
			Retina::GetInt(20), Color(9,86,126), Osp::Ui::Controls::SYSTEM_COLOR_LIST_ITEM_PRESSED_TEXT);
	pCustomListItemFormat->AddElement(LIST_ELEMENT_DESC, Rectangle(Retina::GetInt(105), Retina::GetInt(30), Retina::GetInt(130), Retina::GetInt(45)),
			Retina::GetInt(12), Color(151,151,151), Osp::Ui::Controls::SYSTEM_COLOR_LIST_ITEM_PRESSED_TEXT);


	String dirName(L"/Home/catalog");
	Directory* pDir;
	DirEnumerator* pDirEnum;

	pDir = new Directory; // allocate Directory instance

	// Open directory
	r = pDir->Construct(dirName);

	// Read all directory entries
	pDirEnum = pDir->ReadN();

	String contentType;
	int i = 0;
	while(pDirEnum->MoveNext() == E_SUCCESS) {
		DirEntry dirEntry = pDirEnum->GetCurrentDirEntry();
		if(dirEntry.IsDirectory()) {
			//AppLog("%S", dirEntry.GetName().GetPointer());
			if(!dirEntry.GetName().Equals(".", false) && !dirEntry.GetName().Equals("..", false)) {

				String fileName(dirName+"/"+dirEntry.GetName()+"/category.info");
				File file;
				file.Construct(fileName, L"r+");

				String title, desc;
				String iTempStr, iTempStr2;
				file.Read(title);
				file.Read(desc);
				result err = TextPic::GetTranslated(title);
				if (IsFailed(err)) {
					continue;
				}
				
				list.Add(*(new String(dirEntry.GetName())));
				
				TextPic::GetTranslated(desc);

				title.Replace("\n", "");
				desc.Replace("\n", "");
				

				titlelist.Add(*(new String(title)));

				while(file.Read(iTempStr) != E_END_OF_FILE) {
					iTempStr2.Append(iTempStr);
				}

				//CategoryList->AddItem(&iTempStr, NULL, NULL, NULL, i++);

				CustomListItem * newItem = new CustomListItem();
				AnciiListElement * custom_element = new AnciiListElement(iTempStr2, Retina::GetInt(13));


				newItem->Construct(Retina::GetInt(75));
				newItem->SetItemFormat(*pCustomListItemFormat);

				newItem->SetElement(LIST_ELEMENT_TITLE, title);
				newItem->SetElement(LIST_ELEMENT_DESC, desc);
				newItem->SetElement(LIST_ELEMENT_ANCII, *(static_cast<ICustomListElement *>(custom_element)));

				CategoryList->AddItem(*newItem, i++);
			}
		}
	}

	this->AddControl(*CategoryList);

	return r;
}

result
CategoryListForm::OnTerminating(void)
{
	result r = E_SUCCESS;
	delete pCustomListItemFormat;
	list.RemoveAll(true);
	titlelist.RemoveAll(true);
	return r;
}

void
CategoryListForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status)
{
	OnItemStateChanged(source, index, itemId, 0, status);
}

void
CategoryListForm::OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status)
{
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormManager *pFormMgr = static_cast<FormManager *>(pFrame->GetControl("FormManager"));
	if (pFormMgr != null) {
		ArrayList* alist = new ArrayList();
		alist->Add(*(static_cast<String*> (titlelist.GetAt(itemId))));
		alist->Add(*(static_cast<String*> (list.GetAt(itemId))));
		pFormMgr->SendUserEvent(FormManager::REQUEST_ITEMLIST, alist);
	}
}
