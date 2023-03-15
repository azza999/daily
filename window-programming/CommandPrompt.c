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

int _tmain (int argc, TCHAR * argv[])
{
	DWORD isExit;
	while(1)
	{
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
	TCHAR curDir[DIR_LEN];
	GetCurrentDirectory(DIR_LEN, curDir);
	_tprintf("%s> ", curDir);
	_getts(cmdString);
	TCHAR * token = _tcstok(cmdString, seps);
	int tokenNum=0;
	while (token != NULL)
	{
		_tcscpy ( cmdTokenList[tokenNum++], StrLower(token) );
		token = _tcstok(NULL, seps);
	}

	if ( !_tcscmp(cmdTokenList[0], _T("exit")))
	{
		return TRUE;
	}
	else if (!_tcscmp(cmdTokenList[0], _T("명령어")) )
	{
		/* code */
	}
	else
	{
		_tprintf(ERROR_CMD, cmdTokenList[0]);
	}
	return 0;
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