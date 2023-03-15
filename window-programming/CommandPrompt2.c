#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>

#define STR_LEN 256
#define CMD_TOKEN_NUM 10
#define DIR_LEN MAX_PATH+1

TCHAR ERROR_CMD[] = _T("'%s'은(는) 실행할 수 있는 프로그램이 아닙니다. \n");
int CmdProcessing(void);
TCHAR * StrLower(TCHAR *);
void ExecuteCommand(TCHAR *);
void GetLastDir(int, TCHAR *);
void cmd_echo(TCHAR *);
void cmd_start(TCHAR *);

int _tmain (int argc, TCHAR * argv[])
{
	DWORD isExit;
	while(1)
	{
		// main 전달인자를 통해서 들어온 경우
		


		isExit = CmdProcessing();
		if(isExit == TRUE)
		{
			_fputts(_T("명령어 처리를 종료합니다. \n"), stdout);
			break;
		}
	}
	return 0;
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");


// 명령어 받아서 해당 기능 수행. exit는 TRUE 반환하여 프로그램 종료
int CmdProcessing(void)
{
	TCHAR lDir[DIR_LEN];
	GetLastDir(DIR_LEN, lDir);

	_tprintf("%s>> ", lDir);
	_getts(cmdString);
	TCHAR * token = _tcstok(cmdString, seps);
	TCHAR optionStr[STR_LEN];
	int tokenNum=0;
	while (token != NULL)
	{
		_tcscpy ( cmdTokenList[tokenNum++], StrLower(token) );
		token = _tcstok(NULL, seps);
	}

	// 처음거는 무조건 명령어, 그 다음은 옵션
	if (tokenNum > 1) // 옵션 있을 시
	{
		_tcscpy(optionStr, cmdTokenList[1]);
		// 옵션 구성
		for(int i = 2; i < tokenNum; i++)
			_stprintf(optionStr, "%s %s", optionStr, cmdTokenList[i]);
	}

	if ( !_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("echo")) )
	{
		cmd_echo(optionStr);
	}
	else if (!_tcscmp(cmdTokenList[0], _T("start")) )
	{
		_stprintf(optionStr, "%s %s", "CommandPrompt2.exe", optionStr);
		cmd_start(optionStr);
	}
	else
	{
		ExecuteCommand(cmdTokenList[0]);
	}
	return 0;
}

void ExecuteCommand(TCHAR * cStr)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	int stat = CreateProcess(NULL, cStr, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
	if(!stat) 
	{
		_tprintf(ERROR_CMD,cStr);
		return;
	}
	CloseHandle(pi.hProcess);
}

void cmd_echo(TCHAR * str)
{
	_tprintf(_T("%s\n"), str);
}

void cmd_start(TCHAR * options)
{
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	int stat = CreateProcess(NULL, options, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	if(!stat) 
	{
		_tprintf(_T("실행하지 못했습니다."));
		return;
	}
	CloseHandle(pi.hProcess);
}

TCHAR * StrLower(TCHAR * pStr)
{
	TCHAR * ret = pStr;

	while(*pStr)
	{
		if(_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}

	return ret;
}

// 230314 디렉터리 마지막만 보여주는 방식으로 변경
void GetLastDir(int len, TCHAR lDir[DIR_LEN])
{
	TCHAR curDir[DIR_LEN];
	GetCurrentDirectory(len, curDir);

	TCHAR * tok = _tcstok(curDir,"\\");
	while (tok != NULL)
	{
		_tcscpy(lDir, tok);
		tok = strtok(NULL, "\\");
	}

}