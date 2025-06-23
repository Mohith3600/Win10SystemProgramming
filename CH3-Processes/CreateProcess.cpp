#include <Windows.h>
#include <stdio.h>
#include <tchar.h>

void _tmain(int argc, TCHAR* argv[])
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));

	if (argc != 2)
	{
		printf("Usage: %s [cmdline]\n", argv[0]);
		return;
	}

	//Start the Child process
	if (!CreateProcess(NULL,
		argv[1],
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
		printf("CreatProcess failed(%d).\n", GetLastError());
		return;
	}

	//Wait until child process exits
	WaitForSingleObject(pi.hProcess, INFINITE);


	//Close process and thread handles
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
