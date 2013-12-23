#include "RecentForm.h"

#include "Helper.h"
#include "TextArtRegistry.h"
#include "TextPic.h"

#include <FIoFile.h>

using namespace Osp::Base;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

RecentForm::RecentForm() {}

RecentForm::~RecentForm() {}

bool
RecentForm::Initialize()
{
	TabsForm::Initialize(FORM_STYLE_INDICATOR | FORM_STYLE_TEXT_TAB | FORM_STYLE_TITLE, TabsForm::RECENT_TAB);
	SetBackgroundColor(Color(239,239,239));
	SetTitleText(Helper::GetTraslation("IDS_RECENT"));
	return true;
}

result
RecentForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	ItemListForm::OnInitializing();

	return r;
}

result
RecentForm::OnDraw(void)
{
	/*if(count == 0 && TextArtRegistry::updaterecent) {
		ClearList();
	}*/

	ArrayList* data = TextArtRegistry::GetRecent();
	int count = data->GetCount();
	int i;

	if(count == 0 && TextArtRegistry::updaterecent) {
		TextArtRegistry::updaterecent = false;
		ClearList();
	}

	if(count > 0) {
		ClearList();

		for (i = 0; i < count; i++) {
			String fileName = *(static_cast<String*> (data->GetAt(i)));

			File file;
			result r = file.Construct(fileName, L"r+");
			if(r != E_SUCCESS) continue;

			String title, desc;
			String iTempStr, iTempStr2;

			file.Read(title);
			TextPic::GetTranslated(title);

			int linecount = 0;
			while(file.Read(iTempStr) != E_END_OF_FILE) {
				linecount++;
				iTempStr2.Append(iTempStr);
			}

			anciilist.Add(*(new String(iTempStr2)));
			titlelist.Add(*(new String(title)));
			filelist.Add(*(new String(fileName)));

			ItemListForm::AddListItem(*CategoryList, title, iTempStr2, i, linecount);
		}

		data->RemoveAll(true);
	}

	return E_SUCCESS;
}

result
RecentForm::OnTerminating(void)
{
	result r = E_SUCCESS;
	ItemListForm::OnTerminating();
	return r;
}
