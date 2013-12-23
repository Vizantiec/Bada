#include <FBase.h>
#include <FApp.h>

using namespace Osp::Base;
using namespace Osp::App;

class Helper {
public:
		static String GetTraslation(String id) {
			Application* pApp = Application::GetInstance();
			String value;
			result r = pApp->GetAppResource()->GetString(id, value);
			if(r != E_SUCCESS)
				goto CATCH;
			return value;

			CATCH:
				return id;
		}
};
