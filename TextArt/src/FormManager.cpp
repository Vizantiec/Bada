#include "FormManager.h"
#include "CategoryListForm.h"
#include "ItemListForm.h"

#include "Debug.h"

using namespace Osp::App;
using namespace Osp::Base;
using namespace Osp::Ui;
using namespace Osp::Ui::Controls;

FormManager::FormManager(void):
	__itemlistForm(null),
	__categoryForm(null),
	activeItemList(false),
	__recentForm(null),
	__favouritesForm(null)
{
}

FormManager::~FormManager(void)
{
}

bool FormManager::Initialize()
{
	result r = E_SUCCESS;
	r = Form::Construct(FORM_STYLE_NORMAL);
	SetName(L"FormManager");
	return true;
}

bool FormManager::SetStarterForm(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{

	SwitchToForm(REQUEST_CATEGORYLIST, null);
	return true;
}

void FormManager::OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	SwitchToForm(requestId, pArgs);
}

void FormManager::SwitchToForm(RequestId requestId, Osp::Base::Collection::IList* pArgs)
{
	Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();

	if(requestId == REQUEST_CATEGORYLISTBACK) {
		activeItemList = false;
		requestId = REQUEST_CATEGORYLIST;
	}

	if(activeItemList && requestId == REQUEST_CATEGORYLIST) {
		requestId = REQUEST_ITEMLIST;
	}

	switch(requestId) {
		case REQUEST_CATEGORYLIST: {
			activeItemList = false;
			if(__categoryForm == null) {
				__categoryForm = new CategoryListForm();
				__categoryForm->Initialize();
				pFrame->AddControl(*__categoryForm);
			}

			pFrame->SetCurrentForm(*__categoryForm);
			__categoryForm->Draw();
			__categoryForm->Show();

			if (__itemlistForm != null) {
				pFrame->RemoveControl(*__itemlistForm);
				__itemlistForm = null;
			}
		}
		break;
		case REQUEST_ITEMLIST: {
			activeItemList = true;

			if(__itemlistForm == null) {
				String title = *(static_cast<String*> (pArgs->GetAt(0)));
				String dir = *(static_cast<String*> (pArgs->GetAt(1)));

				__itemlistForm = new CategoryItemForm();
				__itemlistForm->Initialize(title, dir);

				pFrame->AddControl(*__itemlistForm);
			}
			pFrame->SetCurrentForm(*__itemlistForm);

			__itemlistForm->Draw();
			__itemlistForm->Show();

		}
		break;
		case REQUEST_RECENT: {
			if(__recentForm == null) {
				__recentForm = new RecentForm();
				__recentForm->Initialize();
				pFrame->AddControl(*__recentForm);
			}

			pFrame->SetCurrentForm(*__recentForm);
			__recentForm->Draw();
			__recentForm->Show();
		}
		break;
		case REQUEST_FAVOURITES: {
			if(__favouritesForm == null) {
				__favouritesForm = new FavouritesForm();
				__favouritesForm->Initialize();
				pFrame->AddControl(*__favouritesForm);
			}

			pFrame->SetCurrentForm(*__favouritesForm);
			__favouritesForm->Draw();
			__favouritesForm->Show();
		}
		break;
		case REQUEST_INFO: {
			if(__infoForm == null) {
				__infoForm = new InfoForm();
				__infoForm->Initialize();
				pFrame->AddControl(*__infoForm);
			}

			pFrame->SetCurrentForm(*__infoForm);
			__infoForm->Draw();
			__infoForm->Show();
		}
		default:
		break;
	}

	/*if(pArgs != null) {
		pArgs->RemoveAll(true);
		delete pArgs;
	}*/
}

