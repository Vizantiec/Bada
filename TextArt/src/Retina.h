#include <FBase.h>
#include <FUi.h>
#include <FApp.h>

using namespace Osp::Base;
using namespace Osp::Graphics;
using namespace Osp::Ui::Controls;
using namespace Osp::App;

class Retina {
public:
		static void Setup() {
			Frame *pFrame = Application::GetInstance()->GetAppFrame()->GetFrame();

			M = 1.0f;
			switch (pFrame->GetWidth())
			{
				case 320:
					M=1.2f;
					break;
				case 480:
					M=2.0f;
					break;
			}
			/*if(pFrame->GetWidth() > 240) {
				M = 1.2f;
			}*/

		}

		static int GetInt(int value)
		{
			return (int) (M * value);
		}
private:
		static float M;
};
