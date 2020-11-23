//��һ��C++���ڳ���
//2020.10.15
#include<Windows.h>
#include<tchar.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("������ͼ");

//���岽�����ں����д�������Ϣ
LRESULT CALLBACK WindowProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hB;
	HPEN hP;
	static int dispMode = -1;
	LPCTSTR str;

	switch (uMsg)
	{
	case WM_LBUTTONDOWN:
		InvalidateRect(hWnd,NULL,TRUE);		//��������������Ϣ
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);
		dispMode = (dispMode + 1) % 6;
		switch (dispMode)
		{
		case 0:
			str = _T("ӳ�䷽ʽMM_TEXT:ȱʡ��ӳ�䷽ʽ");
			SetMapMode(hdc, MM_TEXT);		//����ӳ�䷽ʽΪȱʡ��ʽ
			TextOut(hdc, 0, 0, str, _tcsclen(str));		//���ӳ�䷽ʽ������
			break;
		case 1:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������Ϊ20*20��ӳ��Ϊ�ӿڳߴ�Ϊ10*10��ͼ����Сһ��");
			SetMapMode(hdc,MM_ISOTROPIC);
			SetWindowExtEx(hdc, 20, 20, NULL);
			SetViewportExtEx(hdc, 10, 10, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 2:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*20��ͼ�ηŴ�һ��");
			SetMapMode(hdc, MM_ISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 20, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 3:
			str = _T("ӳ�䷽ʽMM_ANISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*10��ͼ�ηŴ�һ�������򲻱�");
			SetMapMode(hdc, MM_ANISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 10, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 4:
			str = _T("ӳ�䷽ʽMM_ANISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*5��ͼ�ηŴ�һ����������Сһ��");
			SetMapMode(hdc, MM_ANISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 5, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 5:
			str = _T("ӳ�䷽ʽMM_ISOTROPIC:��������Ϊ10*10��ӳ��Ϊ�ӿڳߴ�Ϊ20*5��ͼ��Ϊ�˱���ԭ���ݱȣ�ϵͳ�����ӳ�����");
			SetMapMode(hdc, MM_ISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 5, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		}
		hP = (HPEN)GetStockObject(BLACK_PEN);		//���û���ΪϵͳԤ����ĺ�ɫ����
		hB = (HBRUSH)GetStockObject(DKGRAY_BRUSH);
		SelectObject(hdc, hB);
		SelectObject(hdc, hP);
		RoundRect(hdc, 50,120,100,200,15,15);

		hB = (HBRUSH)GetStockObject(LTGRAY_BRUSH);
		SelectObject(hdc, hB);
		Ellipse(hdc, 150, 50, 200, 150);

		hB = (HBRUSH)GetStockObject(HOLLOW_BRUSH);
		SelectObject(hdc, hB);
		Pie(hdc, 250, 50, 300, 100, 250, 50, 300, 50);

			
		EndPaint(hWnd, &ps);		//�ͷ��豸�������
		DeleteObject(hP);		//ɾ�����ʾ��
		DeleteObject(hB);		//ɾ����ɫ��ˢ���
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, uMsg, wParam, lParam);
		break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//��һ����ע�ᴰ���ָ࣬��������������봰�ڻص�����
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = WindowProc;
	wcex.lpszClassName = szWindowClass;

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("ע�ᴰ����ʧ��"), _T("Tip"), NULL);
		return 1;
	}

	//�ڶ������������ڣ�ָ��ע�ᴰ���࣬���ڱ��⣬���ڵĴ�С
	HWND hWnd = CreateWindow
	(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		800, 800,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd) {
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("Tip"), NULL);
		return 1;
	}

	//����������ʾ����
	ShowWindow(hWnd, nCmdShow);

	//���Ĳ�����ʼ��Ϣѭ��
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}