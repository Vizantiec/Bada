#ifndef _CATEGORYLISTFORM_H_
#define _CATEGORYLISTFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

#include "TabsForm.h"

using namespace Osp::Ui::Controls;
using namespace Osp::Base::Collection;

class CategoryListForm :
	public TabsForm,
	public Osp::Ui::ICustomItemEventListener
{

public:
	CategoryListForm(void);
	virtual ~CategoryListForm(void);
	bool Initialize(void);

private:
	ArrayList list;
	ArrayList titlelist;

	CustomList* CategoryList;
	CustomListItemFormat* pCustomListItemFormat;

	static const int LIST_ELEMENT_TITLE = 201;
	static const int LIST_ELEMENT_ANCII = 202;
	static const int LIST_ELEMENT_DESC = 203;

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status);
};

#endif
