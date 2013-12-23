#ifndef _FORMMANAGER_H_
#define _FORMMANAGER_H_

#include <FApp.h>
#include <FBase.h>
#include <FUi.h>

#include "CategoryListForm.h"
#include "CategoryItemForm.h"
#include "RecentForm.h"
#include "FavouritesForm.h"
#include "InfoForm.h"

class FormManager :
	public Osp::Ui::Controls::Form
{
public:
	FormManager(void);
	virtual ~FormManager(void);

public:
	bool Initialize();
	bool SetStarterForm(RequestId requestId, Osp::Base::Collection::IList* pArgs);

	static const RequestId REQUEST_TAB = 100;
	static const RequestId REQUEST_CATEGORYLIST = 101;
	static const RequestId REQUEST_CATEGORYLISTBACK = 301;
	static const RequestId REQUEST_RECENT = 102;
	static const RequestId REQUEST_FAVOURITES = 103;
	static const RequestId REQUEST_INFO = 104;

	static const RequestId REQUEST_ITEMLIST = 201;

private:
	CategoryListForm* __categoryForm;
	CategoryItemForm* __itemlistForm;
	RecentForm* __recentForm;
	FavouritesForm* __favouritesForm;
	InfoForm* __infoForm;

	bool activeItemList;

protected:
	void SwitchToForm(RequestId requestId, Osp::Base::Collection::IList* pArgs);

public:
	virtual void OnUserEventReceivedN(RequestId requestId, Osp::Base::Collection::IList* pArgs);
};

#endif
