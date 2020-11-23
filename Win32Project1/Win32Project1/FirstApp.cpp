//��һ��C++���ڳ���
//2020.10.15
#include<Windows.h>
#include<tchar.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("������ͼ");

//���岽�����ں����д�������Ϣ
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hB;
	HPEN hP;
	//TCHAR greeting[] = _T("������һ������ʾ�ڳ����У�");
	
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);		//����豸�������
		SetMapMode(hdc, MM_TEXT);		//����ӳ��ģʽ
		//TextOut(hdc,5,5,greeting,_tcslen(greeting));
		Rectangle(hdc,130,60,270,200);		//ʹ�õ�ǰ���ʻ��ƾ��β����
		hB = CreateHatchBrush(HS_CROSS,RGB(255,0,0));		//�Զ���һ����ɫ����״��ˢ
		SelectObject(hdc, hB);		//���»�ˢλ�Զ��廭ˢ
		Ellipse(hdc,130,70,270,190);		//��ֵ��Բ�����
		hP = CreatePen(PS_DASHDOT,1,RGB(0,255,0));		//������Ϊ1����ɫ���ʣ����㻭��
		SelectObject(hdc,hP);		//���»���Ϊ�Զ��廭��

		MoveToEx(hdc, 100, 130, NULL);		//ʹ�õ�ǰ���ʻ�������
		LineTo(hdc,300,130);
		MoveToEx(hdc,200,30,NULL);
		LineTo(hdc,200,230);

		EndPaint(hWnd, &ps);		//�ͷ��豸�������
		DeleteObject(hP);		//ɾ�����ʾ��
		DeleteObject(hB);		//ɾ����ɫ��ˢ���
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd,uMsg,wParam,lParam);
		break;
	}
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow) 
{
	//��һ����ע�ᴰ���ָ࣬��������������봰�ڻص�����
	WNDCLASSEX wcex = {0};
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = WindowProc;
	wcex.lpszClassName = szWindowClass;

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,_T("ע�ᴰ����ʧ��"),_T("Tip"),NULL);
		return 1;
	}

	//�ڶ������������ڣ�ָ��ע�ᴰ���࣬���ڱ��⣬���ڵĴ�С
	HWND hWnd = CreateWindow
	(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,CW_USEDEFAULT,
		500,300,
		NULL,
		NULL,
		hInstance,
		NULL
	);

	if (!hWnd) {
		MessageBox(NULL,_T("��������ʧ�ܣ�"),_T("Tip"),NULL);
		return 1;
	}

	//����������ʾ����
	ShowWindow(hWnd,nCmdShow);

	//���Ĳ�����ʼ��Ϣѭ��
	MSG msg = {0};
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}