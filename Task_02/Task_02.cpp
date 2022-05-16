#include "stdafx.h"

DWORD Fun4() {
	DWORD dwTemp;
	HANDLE g_hSem;
	//LPLONG NULL;
	//DWORD INFINITE;
	// 1. Do any processing here. 
	__try {
		// 2. Request permission to access 
		// protected data, and then use it. 
//		WaitForSingleObject(g_hSem, INFINITE);
		DWORD g_dwProtectedData = 5;
		dwTemp = g_dwProtectedData;
		// Return the new value. 
		return(dwTemp);
	}
	__finally {
		// 3. Allow others to use protected data. 
		//ReleaseSemaphore(g_hSem, 1, NULL);
		return(103);
	}
	// Continue processing--this code will never execute. 
	dwTemp = 9;
	return(dwTemp);
}


int main()
{
	_tprintf(_T("%d"), Fun4());
}