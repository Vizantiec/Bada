#ifndef INFOFORM_H_
#define INFOFORM_H_

#include <FBase.h>
#include <FUi.h>
#include <FWeb.h>
#include <FSystem.h>

#include "ItemListForm.h"

class CustomListElement;

class InfoForm:
	public TabsForm,
	public Osp::Ui::ICustomItemEventListener,
	public Osp::Ui::Controls::IFormBackEventListener
	{
public:
	InfoForm();
	virtual ~InfoForm();

	bool Initialize(void);

private:
	static const int SOFTKEY_BACK = 101;
	Osp::Ui::Controls::Footer* __pFooter;

	CustomList* CategoryList;
	CustomListItemFormat* pCustomListItemFormat;
	String* __pProducts[][2];
	int versionAPI;

	static const int LIST_ELEMENT_IMG = 201;
	static const int LIST_ELEMENT_DESC = 202;

	void GetProduct(int index);
	void CreateArray(void);

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, Osp::Ui::ItemStatus status);
    virtual void OnItemStateChanged(const Osp::Ui::Control& source, int index, int itemId, int elementId, Osp::Ui::ItemStatus status);

    virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);
};

#endif
