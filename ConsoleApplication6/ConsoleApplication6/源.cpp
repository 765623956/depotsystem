#include "windows.h"
#include "tchar.h"
//���ں���˵��
LRESULT CALLBACK Wndproc(HWND, UINT, WPARAM, LPARAM);
//��ں�������
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hWnd;
	MSG msg;
	TCHAR szWindowClass[] = L"����ʾ��";					//��������
	TCHAR szTitle[] = _T("My Windows");							//���ڱ�����

																//���³�ʼ��������
	wcex.cbSize = sizeof(WNDCLASSEX);						//������Ĵ�С
	wcex.style = 0;														//������ʽΪĬ����ʽ
	wcex.lpfnWndProc = Wndproc;								//���崰����Ϣ����������
	wcex.cbClsExtra = 0;												//����������չ
	wcex.cbWndExtra = 0;											//����ʵ������չ
	wcex.hInstance = hInstance;									//��ǰʵ�����
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	//���ڵ�ͼ��ΪĬ��ͼ��
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);		//���ڲ��ü�ͷ���
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	//���ڱ���Ϊ��ɫ
	wcex.lpszMenuName = NULL;
	//�������޲˵�
	wcex.lpszClassName = szWindowClass;					//��������Ϊ������ʾ����
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	//���ڵ�Сͼ��ΪĬ��ͼ��

	//���½��д������ע��
	if (!RegisterClassEx(&wcex))									//���ע��ʧ���򷢳�����
	{
		MessageBox(NULL, _T("WINDOWS FALES"), _T("REGISTER WINSOWS"), NULL);
		return 1;
	}

	//���½��д�������
	hWnd = CreateWindow(
		szWindowClass,													//��������
		szTitle,																//����ʵ���ı�����
		WS_OVERLAPPEDWINDOW,									//���ڵķ��
		CW_USEDEFAULT, CW_USEDEFAULT,					//�������Ͻ�����ΪĬ��ֵ
		CW_USEDEFAULT, CW_USEDEFAULT,					//���ڵĸߺͿ�ΪĬ��ֵ
		NULL,																//�˴����޸�����
		NULL,																//�˴��������˵�
		hInstance,															//����Ӧ�ó���ĵ�ǰ���
		NULL																	//��ʹ�ø�ֵ
	);
	if (!hWnd)
	{
		MessageBox(NULL, _T("CREATE FALSE"), _T("CREATE WINDOWS"), NULL);
		return 1;
	}
	ShowWindow(hWnd, nCmdShow);							//��ʾ����
	UpdateWindow(hWnd);											//�����û���
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;												//������ֹʱ����Ϣ����ϵͳ

}

//�����Ǵ��ں����Ĵ���
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		//Ĭ��ʱ����ϵͳ��ϢĬ�ϴ�����
		break;

	}

	return 0;
}