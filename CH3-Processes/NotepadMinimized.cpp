#include<Windows.h>
#include<stdio.h>

int wmain()
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	//Initialize Startupinfo structure 
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	si.dwFlags = STARTF_USESHOWWINDOW;
	si.wShowWindow = SW_SHOWMINNOACTIVE; //Minimized, no focus
	wchar_t cmdLine[] = L"notepad.exe"; // Writable wide string

	//Initialize PROCESS_INFORMATION structure

	ZeroMemory(&pi, sizeof(pi));

	//Launce Notepad.exe

	if (!CreateProcess(
		NULL,
		cmdLine,
		NULL,
		NULL,
		FALSE,
		0,
		NULL,
		NULL,
		&si,
		&pi
	))
	{
		printf("CreateProcess failed (%lu) .\n", GetLastError());
		return 1;
	}
	printf("Launced Notepad minimized. PID: %lu\n", pi.dwProcessId);

	//Close Hanldes
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
