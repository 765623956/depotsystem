//����Windows����
//2020.10.13
#include<windows.h>
#include<tchar.h>
//���ں���˵��
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//��ں�������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow) {
	WNDCLASSEX wcex;
	HWND hWnd;
	MSG msg;
	
	TCHAR szWindowClass[] = _T("����ʾ��");		//��������
	TCHAR szTitle[] = _T("My Windows");			//���ڱ�����

	//��ʼ��������
	wcex.cbSize = sizeof(WNDCLASSEX);		//������Ĵ�С
	wcex.style = 0;		//������ΪĬ����ʽ
	wcex.lpfnWndProc = WndProc;		//���崰����Ϣ����������
	wcex.cbWndExtra = 0;		//����ʾ������չ
	wcex.hInstance = hInstance;			//��ǰʵ�����
	wcex.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_APPLICATION));		//���ڵ�ͼ��ΪĬ��ͼ��
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);		//���ڲ��ü�ͷ���
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);		//���ڱ���Ϊ��ɫ
	wcex.lpszMenuName = NULL;		//�������޲˵�
	wcex.lpszClassName = szWindowClass;		//��������Ϊ������ʾ����
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));			//���ڵ�Сͼ��ΪĬ��ͼ��

	//ע�ᴰ����
	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("����ע��ʧ�ܣ�"), _T("����ע��"), NULL);
		return 1;
	}

	//��������
	hWnd = CreateWindow(
				szWindowClass,		//��������
				szTitle,		//����ʵ���ı�����
				WS_OVERLAPPEDWINDOW,			//���ڵķ��
				CW_USEDEFAULT, CW_USEDEFAULT,		//�������Ͻ�����ΪĬ��ֵ
				CW_USEDEFAULT,CW_USEDEFAULT,		//���ڵĸߺͿ�ΪĬ��ֵ
				NULL,		//�˴����޸�����
				NULL,		//�˴��������˵�
				hInstance,			//����Ӧ�ó���ĵ�ǰ���
				NULL		//��ʹ�ø�ֵ
	);	
	if (!hWnd) {			//����������ʧ�����;���
		MessageBox(NULL, _T("��������ʧ�ܣ�"), _T("��������"), NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);		//��ʾ����
	UpdateWindow(hWnd);		//�����û���
	while (GetMessage(&msg,NULL,0,0)) {			//��Ϣѭ��
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;		//������ֹʱ����Ϣ����ϵͳ
}

//���ں����Ĵ���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);		//Ĭ��ʱ����ϵͳ��ϢĬ�ϴ�����
		break;
	}
	return 0;
}

