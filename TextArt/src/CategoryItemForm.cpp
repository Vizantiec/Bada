#include "CategoryItemForm.h"

#include "FormManager.h"
#include "Helper.h"
#include "TextArtRegistry.h"
#include "TextPic.h"

#include <FIoDirectory.h>
#include <FIoRegistry.h>
#include <FIoFile.h>
#include <FGrpFont.h>
#include <FApp.h>

using namespace Osp::Ui::Controls;
using namespace Osp::Base;
using namespace Osp::Base::Utility;
using namespace Osp::Io;

CategoryItemForm::CategoryItemForm() {
}

CategoryItemForm::~CategoryItemForm() {
}

bool
CategoryItemForm::Initialize(String t, String d)
{
	TabsForm::Initialize(FORM_STYLE_INDICATOR | FORM_STYLE_TEXT_TAB | FORM_STYLE_TITLE | FORM_STYLE_FOOTER, TabsForm::CATEGORY_TAB);

	SetTitleText(t);
	dir = d;

	AppResource* pAppResource = Application::GetInstance()->GetAppResource();
	__pFooter = TabsForm::GetFooter();
	__pFooter->SetStyle(FOOTER_STYLE_SEGMENTED_ICON);
	__pFooter->AddActionEventListener(*this);
	__pFooter->SetBackButton();
	SetFormBackEventListener(this);

	ButtonItem buttonItem;
	buttonItem.Construct(BUTTON_ITEM_STYLE_TEXT, SOFTKEY_INFO);
	buttonItem.SetBackgroundBitmap(BUTTON_ITEM_STATUS_NORMAL, pAppResource->GetBitmapN(L"info.png"));
	buttonItem.SetBackgroundBitmap(BUTTON_ITEM_STATUS_PRESSED, pAppResource->GetBitmapN(L"info_p.png"));
	__pFooter->SetButton(BUTTON_POSITION_LEFT, buttonItem);

	/*SetSoftkeyEnabled(SOFTKEY_1,true);
	SetSoftkeyText(SOFTKEY_1, Helper::GetTraslation("IDS_BACK"));
	SetSoftkeyActionId(SOFTKEY_1, SOFTKEY_BACK);
	AddSoftkeyActionListener(SOFTKEY_1, *this);*/

	return true;
}

void
CategoryItemForm::OnFormBackRequested(Osp::Ui::Controls::Form& form)
{
	__pFooter->SetBackButtonEnabled(false);
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
	FormManager *pFormMgr = static_cast<FormManager *>(pFrame->GetControl("FormManager"));
	if (pFormMgr != null) {
		pFormMgr->SendUserEvent(FormManager::REQUEST_CATEGORYLISTBACK, null);
	}
}

result
CategoryItemForm::OnInitializing(void)
{
	ItemListForm::OnInitializing();
	ReadCustomListItems();
	SetEmptyText(Helper::GetTraslation("IDS_EMPTY"));
	return E_SUCCESS;
}

result
CategoryItemForm::OnTerminating(void)
{
	ItemListForm::OnTerminating();
	return E_SUCCESS;
}

result
CategoryItemForm::ReadCustomListItems()
{
	result r = E_SUCCESS;
	String dirName(L"/Home/catalog/"+dir);
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
		if(dirEntry.IsNomalFile()) {
			//AppLog("%S", dirEntry.GetName().GetPointer());
			if(!dirEntry.GetName().Equals("category.info", false)) {

				String fileName(dirName+"/"+dirEntry.GetName());

				String title, desc;
				String iTempStr, iTempStr2;

				File file;
				result r = file.Construct(fileName, L"r");
				if( IsFailed(r) )
				{
						AppLog("File::Consturct() is failed by %s", GetErrorMessage(r));
				}

				FileAttributes fileAttrs;
				file.GetAttributes(fileName, fileAttrs);
				long long size = fileAttrs.GetFileSize();


				ByteBuffer readBuffer;
				readBuffer.Construct((int)size + 1);

				r = file.Read(readBuffer);
				if( IsFailed(r) )
				{
						AppLog("File::Read() is failed by %s", GetErrorMessage(r));
				}

				char* data = new char[readBuffer.GetLimit()+1];
				readBuffer.SetPosition(0);
				readBuffer.GetArray((byte*)data, 0, readBuffer.GetLimit());
				data[readBuffer.GetLimit()] ='\0';
				//String str = String(data);

				String str;
				r = StringUtil::Utf8ToString(data, str);
				delete data;
				if(IsFailed(r)) {
					AppLog("File read error. File : %S", fileName.GetPointer());
					continue;
				}

				file.Seek(FILESEEKPOSITION_BEGIN, 0);
				file.Read(title);

				r = TextPic::GetTranslated(title);
				if (IsFailed(r)) {
					continue;
				}

				int linecount = 0;
				while(file.Read(iTempStr) != E_END_OF_FILE) {
					linecount++;
					iTempStr2.Append(iTempStr);
				}

				anciilist.Add(*(new String(iTempStr2)));
				titlelist.Add(*(new String(title)));
				filelist.Add(*(new String(fileName)));

				ItemListForm::AddListItem(*CategoryList, title, iTempStr2, i++, linecount);
				file.Flush();
			}
		}
	}

	delete pDirEnum;
	delete pDir;

	return r;
}

void
CategoryItemForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	ItemListForm::OnActionPerformed(source, actionId);

	if(actionId == SOFTKEY_BACK) {
		Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
		FormManager *pFormMgr = static_cast<FormManager *>(pFrame->GetControl("FormManager"));
		if (pFormMgr != null) {
			pFormMgr->SendUserEvent(FormManager::REQUEST_CATEGORYLISTBACK, null);
		}
	}

	if(actionId == SOFTKEY_INFO) {
			Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
			FormManager *pFormMgr = static_cast<FormManager *>(pFrame->GetControl("FormManager"));
			if (pFormMgr != null) {
				pFormMgr->SendUserEvent(FormManager::REQUEST_INFO, null);
			}
		}
}
