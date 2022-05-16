// Task_03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "stdafx.h"

DWORD Funcarama4() {
    // IMPORTANT: Initialize all variables to assume failure.
    HANDLE hFile = INVALID_HANDLE_VALUE;
    PVOID pvBuf = NULL;
    // Assume that the function will not execute successfully.
    BOOL bFunctionOk = FALSE;
    __try {
        DWORD dwNumBytesRead;
        BOOL bOk;
        hFile = CreateFile(TEXT("SOMEDATA.DAT"), GENERIC_READ,
            FILE_SHARE_READ, NULL, OPEN_ALWAYS, 0, NULL);
        if (hFile == INVALID_HANDLE_VALUE) {
            __leave;//replaces return statement
        }
        pvBuf = VirtualAlloc(NULL, 1024, MEM_COMMIT, PAGE_READWRITE);
        if (pvBuf == NULL) {
            __leave;
        }
        bOk = ReadFile(hFile, pvBuf, 1024, &dwNumBytesRead, NULL);
        if (!bOk || (dwNumBytesRead == 0)) {
            __leave;
        }
        // Do some calculation on the data....
        // Indicate that the entire function executed successfully.
        bFunctionOk = TRUE;
    }
    __finally {
        // Clean up all the resources.
        if (pvBuf != NULL)
            VirtualFree(pvBuf, 0, MEM_RELEASE);
        if (hFile != INVALID_HANDLE_VALUE)
            CloseHandle(hFile);

    }
    // Continue processing.
    return(bFunctionOk);
}




int main()
{
    _tprintf(_T("%d"), Funcarama4());
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
