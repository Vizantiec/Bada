#ifndef TABSFORM_H_
#define TABSFORM_H_

#include <FBase.h>
#include <FUi.h>

class TabsForm :
 public Osp::Ui::Controls::Form,
 public Osp::Ui::IActionEventListener
{
public:
 TabsForm();
 virtual ~TabsForm();
 bool Initialize(unsigned long formStyle, const int tab_index);

 const static int CATEGORY_TAB = 0;
 const static int RECENT_TAB = 1;
 const static int FAVOURITES_TAB = 2;
 const static int INFO_TAB = 3;

protected:
 Osp::Ui::Controls::Tab * tab_;
 int tab_index_;

// Callbacks
public:
 virtual result OnInitializing(void);
 result OnTerminating(void);
 void OnActionPerformed(const Osp::Ui::Control& source, int actionId);
};

#endif
