#ifndef CATEGORYITEMFORM_H_
#define CATEGORYITEMFORM_H_

#include "ItemListForm.h"

#include <FBase.h>

using namespace Osp::Base;

class CategoryItemForm:
	public ItemListForm,
	public Osp::Ui::Controls::IFormBackEventListener
	 {
public:
	CategoryItemForm();
	virtual ~CategoryItemForm();

	bool Initialize(String t, String d);

private:
	static const int SOFTKEY_BACK = 101;
	static const int SOFTKEY_INFO = 102;

	String dir;
	Osp::Ui::Controls::Footer* __pFooter;

	result ReadCustomListItems();

public:
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);

	virtual void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
	virtual void OnFormBackRequested(Osp::Ui::Controls::Form& source);
};

#endif
