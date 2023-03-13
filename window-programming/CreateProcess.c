#include <stdio.h>
#include <tchar.h>
#include <windows.h>

#define DIR_LEN MAX_PATH+1

int main(int argc, char const *argv[])
{
	STARTUPINFO si={0,};
	PROCESS_INFORMATION pi;
	
	si.cb = sizeof(si);
	si.dwFlags=STARTF_USEPOSITION;
	si.dwX=100;
	si.dwY=200;
	si.dwXSize=300;
	si.dwYSize=200;
	si.lpTitle=_T("I am a body!");
	TCHAR command[]=_T("AdderProcess.exe 10 20");
	TCHAR cDir[DIR_LEN];
	BOOL state;

	GetCurrentDirectory(DIR_LEN, cDir);
	_fputts(cDir, stdout);
	_fputts(_T("\n"), stdout);

	state = CreateProcess(NULL, command, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if(state!=0) _fputts(_T("Creation OK! \n"), stdout);
	else _fputts(_T("Creation Error! \n"), stdout);

	return 0;
}