#include <windows.h>

extern "C" __declspec(dllexport) void __stdcall GetDataFromB(wchar_t* buffer) {
    const wchar_t* msg = L"Data from LibB (Thread Safe)";
    lstrcpyW(buffer, msg);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    return TRUE;
}
