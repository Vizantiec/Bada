#include "TabsForm.h"
#include "FormManager.h"
#include "Helper.h"

#include "Retina.h"

#include <FApp.h>

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Ui;

TabsForm::TabsForm():
	tab_(NULL)
{}

TabsForm::~TabsForm() {}

bool
TabsForm::Initialize(unsigned long formStyle, const int tab_index)
{
	Construct(formStyle);

	tab_index_ = tab_index;

	return true;
}

result
TabsForm::OnInitializing(void)
{
	result r = E_SUCCESS;

	tab_ = this->GetTab();
	if(!tab_) goto CATCH;

	tab_->SetCompositeMode(COMPOSITE_MODE_CHROMA_KEY);


	if(Retina::GetInt(1) == 2) {
		tab_->AddItem(Helper::GetTraslation("IDS_CATALOG"), CATEGORY_TAB);
	}
	else {
		String val = Helper::GetTraslation("IDS_CATALOG");
		if(val.GetLength() > 7) {
			val.SubString(0,7,val);
			val.Append("...");
		}

		tab_->AddItem(val, CATEGORY_TAB);
	}
	//
	if(Retina::GetInt(1) == 2) {
		tab_->AddItem(Helper::GetTraslation("IDS_RECENT"), RECENT_TAB);
	}
	else {
		String val = Helper::GetTraslation("IDS_RECENT");
		if(val.GetLength() > 7) {
			val.SubString(0,7,val);
			val.Append("...");
		}

		tab_->AddItem(val, RECENT_TAB);
	}
	//

	if(Retina::GetInt(1) == 2) {
		tab_->AddItem(Helper::GetTraslation("IDS_FAVOURITES"), FAVOURITES_TAB);
	}
	else {
		String val = Helper::GetTraslation("IDS_FAVOURITES");
		if(val.GetLength() > 7) {
			val.SubString(0,7,val);
			val.Append("...");
		}

		tab_->AddItem(val, FAVOURITES_TAB);
	}
	tab_->SetSelectedItem(tab_index_);
	tab_->AddActionEventListener(*this);

	return r;

	CATCH:
		return E_INVALID_STATE;
}

result
TabsForm::OnTerminating(void)
{
	return E_SUCCESS;
}

void
TabsForm::OnActionPerformed(const Osp::Ui::Control& source, int actionId)
{
	tab_->SetSelectedItem(tab_index_);
	if(tab_index_ != actionId) {
		Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();
		FormManager *pFormMgr = static_cast<FormManager *>(pFrame->GetControl("FormManager"));
		if (pFormMgr != null) {
			pFormMgr->SendUserEvent(FormManager::REQUEST_TAB+actionId+1, null);
		}
	}
}
