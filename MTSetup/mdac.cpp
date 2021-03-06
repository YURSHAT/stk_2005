// mdac.cpp

#include "stdafx.h"
#include <windows.h>
#include "MTSetup.h"


extern DWORD g_dwOSVerFlags;
extern CRITICAL_SECTION	g_cs;
extern DWORD	g_dwInitRebootReason;

BOOL InstallMDAC()
{
	BOOL bRetVal = FALSE;
	TCHAR szFileName[MAX_PATH];
	TCHAR szCurrentDir[MAX_PATH];
	DWORD dwExitCode = 0;
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	BOOL bCreateProc = FALSE;
	//BOOL bProcessExitCode;

	GetCurrentDirectory(sizeof(szCurrentDir), szCurrentDir);

	if(NULL == szCurrentDir[3])
	//if(szCurrentDir[2] == TEXT('\\'))
	{
		// at root directory
		wsprintf(szFileName, TEXT("%sMDAC_TYP.EXE /Q /r"), szCurrentDir);
	}
	else
		wsprintf(szFileName, TEXT("\"%s\\%s\" /Q /R"), szCurrentDir, TEXT("MDAC_TYP.EXE"));
#ifdef _DEBUG
	MessageBox(NULL, szFileName, TEXT("MDAC Filename"), MB_OK);
#endif


	// old way of spawing MDAC didn't accound for paths w/ whitespace. or the root dir.
	//wsprintf(szFileName, TEXT("%s\\%s /Q /R"), szCurrentDir, TEXT("MDAC_TYP.EXE"));


	// try writing Win95 registry here.
	if((g_dwOSVerFlags & dwWin95) == dwWin95)
		if(!SetRunOnceKey(dwMDAC))
			MessageBox(NULL, TEXT("MDAC RunOnce Key not set for Win95"), TEXT("Error"), MB_ICONERROR);
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	bCreateProc = CreateProcess(NULL,
		szFileName,
		NULL,
		NULL,
		FALSE,
		0,   
		NULL,
		NULL,
		&si,
		&pi);

	if(bCreateProc)
	{
		// MDAC Installation has started
		CloseHandle(pi.hThread);
		EnterCriticalSection(&g_cs);
		g_dwInitRebootReason = dwMDAC;
		LeaveCriticalSection(&g_cs);
		WaitForSingleObject(pi.hProcess, INFINITE);
		CloseHandle(pi.hProcess);
		return TRUE;
	}
	else
	{
		DWORD dwErrCode = 0;
		char szErr[25];
		dwErrCode = GetLastError();
		wsprintf(szErr, TEXT("MDAC Installation failed. Error Code:%u"), dwErrCode);
		MessageBox(NULL, szErr, TEXT("MDAC Failed"), MB_OK);
		return FALSE;
	}
}

BOOL IsMDACPresent()
{
	BOOL bRetVal = FALSE;
	TCHAR szMDACRegKey[] = TEXT("Software\\Microsoft\\DataAccess");
	TCHAR szValue[MAX_PATH];
	DWORD dwValue = 0;
	HKEY hKLM = NULL;
	LONG lReg = 0;
	LONG ldwReg = 0;
	LONG lszReg = 0;
	DWORD dwKeySize = 0;

	if((g_dwOSVerFlags & dwWin2K) == dwWin2K)
	{
		return TRUE;
	}

	lReg = RegOpenKeyEx(HKEY_LOCAL_MACHINE,
				szMDACRegKey,
				0,
				KEY_READ,
				&hKLM);

	if(ERROR_SUCCESS == lReg)
	{
		dwKeySize = sizeof(szValue)/sizeof(TCHAR);
		lszReg = RegQueryValueEx(hKLM, TEXT("FullInstallVer"), NULL, NULL, (BYTE*) szValue, &dwKeySize);
		ldwReg = RegQueryValueEx(hKLM, TEXT("Full21Install"), NULL, NULL, (BYTE*) dwValue, &dwKeySize);
		if((ERROR_SUCCESS == lszReg) || (ERROR_SUCCESS == ldwReg))
		{
			RegCloseKey(hKLM);
			return TRUE;
		}
		else
		{
			RegCloseKey(hKLM);
			return FALSE;
		}
	}
	else
	{
		return FALSE;
	}
}
