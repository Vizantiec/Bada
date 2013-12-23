#ifndef ITEMLISTFORM_H_
#define ITEMLISTFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

#include "TabsForm.h"

using namespace Osp::Base;
using namespace Osp::Base::Collection;
using namespace Osp::Ui::Controls;
using namespace Osp::Io;

class ItemListForm :
	public TabsForm,
	public Osp::Ui::ICustomItemEventListener {
public:
	ItemListForm();
	virtual ~ItemListForm();
	bool Initialize();

	void HidePopup();

private:

	static const int LIST_ELEMENT_TITLE = 201;
	static const int LIST_ELEMENT_ANCII = 202;

	String title;
	ArrayList formatlist;

	Osp::Ui::Controls::Popup* __pPopup;

	//EditArea *e;

	void ShowPopup(String title, String sms);

protected:
	ArrayList anciilist;
	ArrayList titlelist;
	ArrayList filelist;

	String anciitext;
	String filename;

	static const int BUTTON_SENDSMS = 301;
	static const int BUTTON_COPY = 302;
	static const int BUTTON_SENDEMAIL = 303;
	static const int BUTTON_CANCEL = 304;
	static const int BUTTON_ADDTOFAVOURITES = 305;
	static const int BUTTON_REMOVEFROMFAVOURITES = 306;

	CustomList* CategoryList;
	Label* empty;

	result DrawCustomList();
	result ReadCustomListItems();
	result AddListItem(CustomList& CustomListPtr, String title, String ancii, int id, int linecount);
	result ClearList();
	result RedrawList();
	result SetEmptyText(String text);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);

	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status);
};

#endif
