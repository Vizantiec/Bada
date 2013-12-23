#ifndef FAVOURITESFORM_H_
#define FAVOURITESFORM_H_

#include <FBase.h>
#include <FUi.h>

#include "ItemListForm.h"

class FavouritesForm:
	public ItemListForm {
public:
	FavouritesForm();
	virtual ~FavouritesForm();

	bool Initialize(void);

public:
	result OnDraw(void);
	virtual result OnInitializing(void);
};

#endif
