
#include <windows.h>
#include <tchar.h>

TCHAR szWindowClass[] = "����ʾ��";					// ��������
TCHAR szTitle[] = "My Windows";					// ���ڱ���

void SetMyWindow(HINSTANCE hInstance, WNDCLASSEX& wcex);			// ���ô�����ĳ�Ա����
bool RegistAndCreateWindow(HINSTANCE hInstance, WNDCLASSEX wcex, HWND& hWnd);		// ע�Ტ��������
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);				// ���ں�����������Ӧ�ó���Խ��ܵ��Ĳ�ͬ��Ϣ����Ӧ

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {	// HINSTANCE ��ǰʵ�����
	WNDCLASSEX wcex;		// ������
	HWND hWnd;				// ���ھ����PVOID�����ݣ���Ӧ�ó���ͨ������ܹ�������Ӧ�Ķ�����Ϣ
	MSG msg;

	SetMyWindow(hInstance, wcex);
	if (!RegistAndCreateWindow(hInstance, wcex, hWnd)) {
		return 1;
	};

	ShowWindow(hWnd, nCmdShow);				// ��ʾ����
	UpdateWindow(hWnd);						// ���´���

	while (GetMessage(&msg, NULL, 0, 0)) {	// ��Ϣѭ��
		TranslateMessage(&msg);			// ����Ϣ�������ת��Ϊ�ַ���Ϣ
		DispatchMessage(&msg);			// ����Ϣ���͵�ָ���Ĵ��ں���
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {	// ���ں���
	switch (message) {					// ������Ϣ���Ͳ�������Ӧ
	case WM_DESTROY:					// ��������
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);		// ϵͳ��ϢĬ�ϴ�����
		break;
	}

	return 0;
}


void SetMyWindow(HINSTANCE hInstance, WNDCLASSEX& wcex) {
	wcex.cbSize = sizeof(WNDCLASSEX);			// ������Ĵ�С
	wcex.style = 0;								// ������ķ��
	wcex.lpfnWndProc = WndProc;					// ָ�򴰿ں�����ָ��
	wcex.cbClsExtra = 0;						// �����ڴ�����ṹ����ֽ��������������չ���ݲ���⣩
	wcex.cbWndExtra = 0;						// �����ڴ���ʵ������ֽ���,����ʵ����չ���ݲ���⣩
	wcex.hInstance = hInstance;					// ���崰�����Ӧ�ó���ʵ�����
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));			// ����ͼ��
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);									// ��ͷ���
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);					// ������ɫ
	wcex.lpszMenuName = NULL;					// �����۵Ĳ˵���Դ��
	wcex.lpszClassName = szWindowClass;			// ��������
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));	// �������Сͼ��
}

bool RegistAndCreateWindow(HINSTANCE hInstance, WNDCLASSEX wcex, HWND& hWnd) {
	if (!RegisterClassEx(&wcex)) {				// ע�ᴰ��
		MessageBox(NULL, _T("Register Window Failed!"), _T("REG Failed"), NULL);
		return 0;
	}

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);		// ��������
	if (!hWnd) {
		MessageBox(NULL, "Create Window Failed", _T("Creat Window"), NULL);
		return 0;
	}

	return 1;
}