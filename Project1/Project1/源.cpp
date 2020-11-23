
#include <windows.h>
#include <tchar.h>

TCHAR szWindowClass[] = "窗口示例";					// 窗口类名
TCHAR szTitle[] = "My Windows";					// 窗口标题

void SetMyWindow(HINSTANCE hInstance, WNDCLASSEX& wcex);			// 设置窗口类的成员变量
bool RegistAndCreateWindow(HINSTANCE hInstance, WNDCLASSEX wcex, HWND& hWnd);		// 注册并创建窗口
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);				// 窗口函数，定义了应用程序对接受到的不同消息的响应

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {	// HINSTANCE 当前实例句柄
	WNDCLASSEX wcex;		// 窗口类
	HWND hWnd;				// 窗口句柄（PVOID型数据），应用程序通过句柄能够访问相应的对象信息
	MSG msg;

	SetMyWindow(hInstance, wcex);
	if (!RegistAndCreateWindow(hInstance, wcex, hWnd)) {
		return 1;
	};

	ShowWindow(hWnd, nCmdShow);				// 显示窗口
	UpdateWindow(hWnd);						// 更新窗口

	while (GetMessage(&msg, NULL, 0, 0)) {	// 消息循环
		TranslateMessage(&msg);			// 将消息的虚拟键转换为字符信息
		DispatchMessage(&msg);			// 将消息传送的指定的窗口函数
	}

	return 0;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {	// 窗口函数
	switch (message) {					// 区分消息类型并作出响应
	case WM_DESTROY:					// 窗口销毁
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);		// 系统消息默认处理函数
		break;
	}

	return 0;
}


void SetMyWindow(HINSTANCE hInstance, WNDCLASSEX& wcex) {
	wcex.cbSize = sizeof(WNDCLASSEX);			// 窗口类的大小
	wcex.style = 0;								// 窗口类的风格
	wcex.lpfnWndProc = WndProc;					// 指向窗口函数的指针
	wcex.cbClsExtra = 0;						// 分配在窗口类结构后的字节数，窗口类的拓展（暂不理解）
	wcex.cbWndExtra = 0;						// 分配在窗口实例后的字节数,窗口实例拓展（暂不理解）
	wcex.hInstance = hInstance;					// 定义窗口类的应用程序实例句柄
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));			// 窗口图标
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);									// 箭头光标
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);					// 背景颜色
	wcex.lpszMenuName = NULL;					// 窗口累的菜单资源名
	wcex.lpszClassName = szWindowClass;			// 窗口类名
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));	// 窗口类的小图标
}

bool RegistAndCreateWindow(HINSTANCE hInstance, WNDCLASSEX wcex, HWND& hWnd) {
	if (!RegisterClassEx(&wcex)) {				// 注册窗口
		MessageBox(NULL, _T("Register Window Failed!"), _T("REG Failed"), NULL);
		return 0;
	}

	hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, NULL, NULL, hInstance, NULL);		// 创建窗口
	if (!hWnd) {
		MessageBox(NULL, "Create Window Failed", _T("Creat Window"), NULL);
		return 0;
	}

	return 1;
}