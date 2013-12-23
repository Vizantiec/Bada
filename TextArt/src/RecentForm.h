#ifndef RECENTFORM_H_
#define RECENTFORM_H_

#include <FBase.h>
#include <FUi.h>

#include "ItemListForm.h"

class RecentForm:
	public ItemListForm {
public:
	RecentForm();
	virtual ~RecentForm();

	bool Initialize(void);


public:
	virtual result OnDraw(void);
	virtual result OnInitializing(void);
	virtual result OnTerminating(void);
};

#endif
