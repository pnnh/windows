#include <Windows.h>
#include <tchar.h>
#include <stdio.h>
#include <locale.h>

int compare(const void* arg1, const void* arg2);

int main()
{
	setlocale(LC_ALL, "chs");

	LPCTSTR arrStr[] = {
		TEXT("架构风格之资源管理.AVI"),
		TEXT("模块化之合理内聚.AVI"),
		TEXT("总结.AVI"),
		TEXT("模块化之管理依赖.AVI"),
		TEXT("系统架构设计概述.AVI"),
		TEXT("架构风格之分布式.AVI"),
		TEXT("4、原理——开发风格之资源管理.AVI"),
		TEXT("11、总结"),
		TEXT("8、架构风格之"),
		TEXT("6、适配与扩展"),
		TEXT("1、设计概述"),
		TEXT("7、重用与内聚"),
		TEXT("10、确保扩展"),
		TEXT("3、原理架构风格之分布式"),
		TEXT("9、模块化之保持可用"),
		TEXT("5、事件驱动"),
		TEXT("4、架构风格之资源管理"),
	};
	qsort(arrStr, _countof(arrStr), sizeof(LPTSTR), compare);

	for (int i = 0; i < _countof(arrStr); i++) {
		_tprintf(TEXT("%s\n"), arrStr[i]);
	}
	return 0;
}

int compare(const void* arg1, const void* arg2) {
	//return _tcscoll(*(LPTSTR*)arg1, *(LPTSTR*)arg2);
	LPTSTR p1 = NULL;
	LPTSTR p2 = NULL;
	double d1 = _tcstod(*(LPTSTR*)arg1, &p1);
	double d2 = _tcstod(*(LPTSTR*)arg2, &p2);

	if (d1 != d2) {
		if (d1 > d2) {
			return 1;
		}
		else {
			return -1;
		}
	}
	else {
		return _tcscoll(p1, p2);
	}
}