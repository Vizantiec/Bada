#include <FBase.h>
#include <FUi.h>

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Ui::Controls;

class AnciiListElement: public Osp::Ui::Controls::ICustomListElement {

private:
	String pic;
	int fontsize;
	Font* __pFont;
public:
	AnciiListElement(String& picture, int fs) {
		pic = picture;
		fontsize = fs;
		__pFont = new Font();
		__pFont->Construct(FONT_STYLE_PLAIN, fontsize);
	}
	~AnciiListElement() {
		delete __pFont;
	}

	result DrawElement(const Osp::Graphics::Canvas& canvas, const Osp::Graphics::Rectangle& rect, CustomListItemStatus itemStatus) {
		result r = E_SUCCESS;
		Canvas* pCanvas = const_cast<Canvas*> (&canvas);

		EnrichedText titleText;
		titleText.Construct(Dimension(rect.width, rect.height));
		titleText.SetTextWrapStyle(TEXT_WRAP_WORD_WRAP);

		TextElement titleTextElement;
		titleTextElement.Construct(pic);

		if (itemStatus == CUSTOM_LIST_ITEM_STATUS_SELECTED) {
			titleTextElement.SetTextColor(Osp::Ui::Controls::SYSTEM_COLOR_LIST_ITEM_PRESSED_TEXT);
		} else {
			titleTextElement.SetTextColor(/*Osp::Ui::Controls::SYSTEM_COLOR_LIST_ITEM_TEXT*/Color::COLOR_BLACK);
		}
		titleTextElement.SetFont(*__pFont);

		titleText.Add(titleTextElement);
		pCanvas->DrawText(Point(0, 0), titleText);
		return r;
	}

};
