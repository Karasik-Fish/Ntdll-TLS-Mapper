#include <windows.h>

#pragma comment(lib, "LinB.lib")

extern "C" __declspec(dllimport) void __stdcall GetDataFromB(wchar_t* buffer);

// Структура для передачи данных в поток
struct ThreadData {
    wchar_t path[MAX_PATH];
};

// Функция потока
DWORD WINAPI ThreadProc(LPVOID lpParam) {
    ThreadData* data = (ThreadData*)lpParam;
    wchar_t buffer[256];

    // Вызов функции из зависимой DLL внутри потока
    GetDataFromB(buffer);

    // Выведем сообщение (для теста) или запишем лог
    MessageBoxW(NULL, buffer, L"Thread from LibC", MB_OK);

    delete data;
    return 0;
}

// Экспортируемая функция для запуска теста
extern "C" __declspec(dllexport) void __stdcall RunThreadTest() {
    ThreadData* data = new ThreadData();
    CreateThread(NULL, 0, ThreadProc, data, 0, NULL);
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    return TRUE;
}