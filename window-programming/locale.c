#include <stdio.h>
#include <tchar.h>
#include <locale.h>
#include <windows.h>

int _tmain (int argc, TCHAR * argv[])
{
	setlocale(LC_ALL, _T(""));
	_tprintf(_T("한글"));

	return 0;
}