#include <windows.h>
#include <iostream>

int main() {
    PWSTR env = ::GetEnvironmentStrings();
    if (!env) {
        std::wcerr << L"Failed to retrieve environment strings.\n";
        return 1;
    }

    WCHAR text[8192] = { 0 };
    auto p = env;

    while (*p) {
        auto equals = wcschr(p, L'=');
        if (equals != p) { // eliminate empty names/values
            wcsncat_s(text, p, equals - p);
            wcscat_s(text, L": ");
            wcscat_s(text, equals + 1);
            wcscat_s(text, L"\n");
        }
        p += wcslen(p) + 1;
    }

    ::FreeEnvironmentStrings(env);

    // Output the result
    std::wcout << text;

    return 0;
}
