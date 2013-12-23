#include "FavouritesForm.h"

#include "Helper.h"
#include "TextArtRegistry.h"
#include "TextPic.h"

#include <FIoFile.h>

using namespace Osp::Base;
using namespace Osp::Ui::Controls;
using namespace Osp::Graphics;

FavouritesForm::FavouritesForm() {}

FavouritesForm::~FavouritesForm() {}

bool
FavouritesForm::Initialize()
{
	// Construct an XML form
	TabsForm::Initialize(FORM_STYLE_INDICATOR | FORM_STYLE_TEXT_TAB | FORM_STYLE_TITLE, TabsForm::FAVOURITES_TAB);

	SetTitleText(Helper::GetTraslation("IDS_FAVOURITES"));
	SetBackgroundColor(Color(239,239,239));

	return true;
}

result
FavouritesForm::OnInitializing(void)
{
	result r = E_SUCCESS;
	ItemListForm::OnInitializing();
	return r;
}

result
FavouritesForm::OnDraw(void)
{
	ArrayList* data = TextArtRegistry::GetFavourites();
	int count = data->GetCount();

	if(count == 0 && TextArtRegistry::updatefavourites) {
		TextArtRegistry::updatefavourites = false;
		ClearList();
	}

	int i;
	if(count > 0) {
		ClearList();
		for (i = 0; i < count; i++) {
			String fileName = *(static_cast<String*> (data->GetAt(i)));

			File file;
			file.Construct(fileName, L"r+");

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
