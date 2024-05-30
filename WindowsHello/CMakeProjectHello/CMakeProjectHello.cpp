// CMakeProjectHello.cpp : Defines the entry point for the application.
//

#include "CMakeProjectHello.h"
#include <Windows.h>
#include <tchar.h>		// _tcslen函数需要该头文件

#pragma comment(lib, "Winmm.lib")


using namespace std;


// 函数声明，窗口过程
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wndclass;
	TCHAR szClassName[] = TEXT("CMakeProjectWindow");
	TCHAR szAppName[] = TEXT("CMakeProjectHello");

	HWND hwnd;		// CreateWindowEx函数创建的窗口的句柄
	MSG msg;

	wndclass.cbSize = sizeof(WNDCLASSEX);		// 结构体大小
	wndclass.style = CS_HREDRAW | CS_VREDRAW;		// 窗口样式
	wndclass.lpfnWndProc = WindowProc;		// 窗口过程
	wndclass.cbClsExtra = 0;		// 窗口类的附加内存，一般设为0
	wndclass.cbWndExtra = 0;		// 窗口的附加内存，一般设为0
	wndclass.hInstance = hInstance;		// 程序实例句柄
	wndclass.hIcon = LoadIcon(NULL, IDI_APPLICATION);		// 程序图标，使用默认图标
	wndclass.hCursor = LoadCursor(NULL, IDC_ARROW);		// 鼠标光标，使用默认光标
	wndclass.hbrBackground = (HBRUSH)GetStockObject(GRAY_BRUSH);		// 背景色，使用白色背景
	wndclass.lpszMenuName = NULL;		// 菜单名，没有菜单，设为NULL
	wndclass.lpszClassName = szClassName;		// 窗口类名
	wndclass.hIconSm = NULL;		// 小图标，使用默认图标
	RegisterClassEx(&wndclass);		// 注册窗口类

	hwnd = CreateWindowEx(0, 	// 扩展窗口风格
				szClassName,		// 窗口类名
				szAppName,		// 窗口标题
				WS_OVERLAPPEDWINDOW,		// 窗口风格
				CW_USEDEFAULT,		// 窗口左上角横坐标
				CW_USEDEFAULT,		// 窗口左上角纵坐标
				CW_USEDEFAULT,		// 窗口宽度
				CW_USEDEFAULT,		// 窗口高度
				NULL,		// 父窗口句柄
				NULL,		// 菜单句柄
				hInstance,		// 应用程序实例句柄
				NULL		// 其他创建参数
		);

	ShowWindow(hwnd, nCmdShow);		// 显示窗口
	UpdateWindow(hwnd);		// 更新窗口

	while(GetMessage(&msg, NULL, 0, 0)) {		// 消息循环
		TranslateMessage(&msg);		// 键盘消息转换
		DispatchMessage(&msg);		// 分发消息
	}

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	TCHAR szStr[] = TEXT("Hello World!");

	switch(uMsg)
	{
		case WM_CREATE:
			PlaySound(TEXT("hellowin.wav"), NULL, SND_FILENAME | SND_ASYNC);
			return 0;
		case WM_PAINT:
			hdc = BeginPaint(hwnd, &ps);
			TextOut(hdc, 100, 100, szStr, _tcslen(szStr));
			EndPaint(hwnd, &ps);
			return 0;
		case WM_LBUTTONDBLCLK:
			MessageBox(hwnd, TEXT("你双击了鼠标左键！"), TEXT("提示"), MB_OK);
			return 0;
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

//int main()
//{
//	cout << "Hello CMake." << endl;
//	return 0;
//}
