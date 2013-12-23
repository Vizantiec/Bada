#include <FBase.h>
#include <FSystem.h>

using namespace Osp::System;

class Debug {
public:

	static result GetRuntimeInfomation(void) {
     int value;

     result r = E_SUCCESS;

     String key(L"AvailableMemory");

     r = RuntimeInfo::GetValue(key, value);
     TryCatch(r == E_SUCCESS, , "MyRuntimeInfo: Failed to get value");

     AppLog("MEMORY :%d", value);
    // __availableMemory = value;

     return E_SUCCESS;

    CATCH:
     return r;
}

};
