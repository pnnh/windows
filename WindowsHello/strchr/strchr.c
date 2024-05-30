#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <locale.h>

int main()
{
	TCHAR szStr[] = TEXT("WindowsAPI是最为强大的编程语言！");
	LPTSTR lp = _tcschr(szStr, TEXT('最'));

	setlocale(LC_ALL, "chs");

	_tprintf(TEXT("szStr的地址：%p lp的地址：%p \n"), szStr, lp);
	_tprintf(TEXT("szStr = %s lp = %s\n"), szStr, lp);

	return 0;
}