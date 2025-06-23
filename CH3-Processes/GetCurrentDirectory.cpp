#include<Windows.h>
#include <stdio.h>
#include <conio.h>

int main()
{
	TCHAR buffer[MAX_PATH];
	DWORD ret = GetCurrentDirectory(MAX_PATH, buffer);

	if (ret == 0) {
		printf("GetCurrentDirectory failed with error % lu\n", GetLastError());
	}
	else {
		printf("Current Directory is : %s\n", buffer);
	}
	
}
