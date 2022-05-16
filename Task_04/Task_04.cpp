// Task_04.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "stdafx.h"

int RobustHowManyToken(const char* str) {
    int nHowManyTokens = -1; // -1 indicates failure 
    char* strTemp = NULL; // Assume failure 
    __try {
        // Allocate a temporary buffer 
        strTemp = (char*)malloc(strlen(str) + 1);
        // Copy the original string to the temporary buffer 
        strcpy(strTemp, str);
        // Get the first token 
        char* pszToken = strtok(strTemp, " ");
        // Iterate through all the tokens 
        for (; pszToken != NULL; pszToken = strtok(NULL, " "))
            nHowManyTokens++;
        nHowManyTokens++; // Add 1 since we started at -1 
    }
    __except (EXCEPTION_EXECUTE_HANDLER) {
        // Nothing to do here 
    }
    // Free the temporary buffer (guaranteed) 
    free(strTemp);
    return(nHowManyTokens);
}

int main()
{
    _tprintf(_T("%d"), RobustHowManyToken("tgi gth yht"));

}

