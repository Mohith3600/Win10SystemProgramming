#include <windows.h>
#include <stdio.h>
#include <secext.h>
#include <dsgetdc.h>

int main()
{
	SYSTEM_INFO si;
	::GetNativeSystemInfo(&si);
	printf("Number of processors %d \n", si.dwNumberOfProcessors);

	//To print Computer Name using GetComputerName 
	printf("the computer name will begin from this line \n");

	char computerName[MAX_COMPUTERNAME_LENGTH + 1]; // Buffer to store computer name
	DWORD size = sizeof(computerName) / sizeof(computerName[0]); // Size of the buffer

	// Get the computer name
	if (GetComputerNameA(computerName, &size)) {
		printf("Computer Name: %s\n", computerName);
		printf("the size of the computer %d\n", size);
	}
	else {
		printf("Failed to get computer name. Error: %lu\n", GetLastError());
	}

	//GetWindowsDirectory  Declare the variables 
	printf("--------------------------- \n");
	wchar_t direc[MAX_PATH];
	UINT size1 = MAX_PATH;

	if (GetWindowsDirectoryW(direc, size1))
	{
		printf("get windodws directory %s \n and size of the direcotry %d \n", direc, size1);
	}
	else
	{
		printf("cannot print the working directory", GetLastError());
	}
		
	printf("--------------------------- \n");
	//QueryPerformanceCounter
	printf("\n");
	LARGE_INTEGER queryperfor;
	if (QueryPerformanceCounter(&queryperfor)) {
		printf("perform the query performance %lld \n", queryperfor.QuadPart);
	}
	else
	{
		printf("cannotperform the query counter", GetLastError());
	}

	printf("--------------------------- \n");

	DWORD productType;
	DWORD majorVersion = 10; // Example for Windows 10
	DWORD minorVersion = 0;
	DWORD spMajor = 0;
	DWORD spMinor = 0;

	if (GetProductInfo(majorVersion, minorVersion, spMajor, spMinor, &productType)) {
		printf("Product Type: %u\n", productType);

		// Mapping productType to human-readable values
		switch (productType) {
		case PRODUCT_PROFESSIONAL:
			printf("Windows 10/11 Pro Edition\n");
			break;
		case PRODUCT_ENTERPRISE:
			printf("Windows 10/11 Enterprise Edition\n");
			break;
		case PRODUCT_HOME:
			printf("Windows 10/11 Home Edition\n");
			break;
		default:
			printf("Other Windows Edition: %u\n", productType);
		}
	}
	else {
		printf("Failed to retrieve product info. Error: %d\n", GetLastError());
	}

}

	printf("---------\n GetComputerObject");
	
	DWORD size1 = 0;
	GetComputerName(NameFullyQualifiedDN, NULL, &size1); // Get required size

	if (size == 0) {
		wprintf(L"Failed to retrieve size. Error: %d\n", GetLastError());
		return 1;
	}

	wchar_t* buffer = (wchar_t*)malloc(size * sizeof(wchar_t));
	if (!buffer) {
		wprintf(L"Memory allocation failed.\n");
		return 1;
	}

	if (GetComputerName((NameFullyQualifiedDN, buffer, &size)) {
		wprintf(L"Computer Object Name: %ls\n", buffer);
	}
	else {
		wprintf(L"Failed to retrieve computer object name. Error: %d\n", GetLastError());
	}

	free(buffer);
	return 0;

}
