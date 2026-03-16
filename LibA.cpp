#include <windows.h>

// Указываем линковщику искать функцию в LibB.lib
#pragma comment(lib, "LinB.lib")

// Импортируем из LibB
extern "C" __declspec(dllimport) void __stdcall GetDataFromB(wchar_t* buffer);

extern "C" __declspec(dllexport) int __stdcall CreateTestFile(const wchar_t* filePath) {
    wchar_t dataFromB[256];
    GetDataFromB(dataFromB);

    HANDLE hFile = CreateFileW(filePath, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) return 0;

    DWORD written;
    int len = 0;
    while (dataFromB[len]) len++;

    BOOL res = WriteFile(hFile, dataFromB, len * sizeof(wchar_t), &written, NULL);
    CloseHandle(hFile);
    return res ? 1 : 0;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    return TRUE;
}