#include <windows.h>
#include <iostream>

int main() {
    DWORD pid = GetCurrentProcessId();
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION, FALSE, pid);

    if (hProcess) {
        DWORD userObjects = GetGuiResources(hProcess, GR_USEROBJECTS);
        DWORD gdiObjects = GetGuiResources(hProcess, GR_GDIOBJECTS);

        std::cout << "Object Name: User Objects, Count: " << userObjects << std::endl;
        std::cout << "Object Name: GDI Objects, Count: " << gdiObjects << std::endl;

        CloseHandle(hProcess);
    }
    else {
        std::cerr << "Failed to open process." << std::endl;
    }

    return 0;
}
