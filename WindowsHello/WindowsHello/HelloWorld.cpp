#include <Windows.h>

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow) {
	int nRet = MessageBox(NULL, TEXT("Hello World!"), TEXT("Caption"), MB_OKCANCEL | MB_ICONINFORMATION | MB_DEFBUTTON2);
	switch (nRet) {
	case IDOK:
		MessageBox(NULL, TEXT("�û�������ȷ����ť"), TEXT("Caption"), MB_OK);
		break;
	case IDCANCEL:
		MessageBox(NULL, TEXT("�û�������ȡ����ť"), TEXT("Caption"), MB_OK);
		break;
	}
	return 0;
}