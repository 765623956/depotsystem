//第一个C++窗口程序
//2020.10.15
#include<Windows.h>
#include<tchar.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("基本绘图");

//第五步：窗口函数中处理窗口消息
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
		InvalidateRect(hWnd,NULL,TRUE);		//单击鼠标左键的信息
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);
		dispMode = (dispMode + 1) % 6;
		switch (dispMode)
		{
		case 0:
			str = _T("映射方式MM_TEXT:缺省的映射方式");
			SetMapMode(hdc, MM_TEXT);		//设置映射方式为缺省方式
			TextOut(hdc, 0, 0, str, _tcsclen(str));		//输出映射方式及比例
			break;
		case 1:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标为20*20，映射为视口尺寸为10*10，图形缩小一倍");
			SetMapMode(hdc,MM_ISOTROPIC);
			SetWindowExtEx(hdc, 20, 20, NULL);
			SetViewportExtEx(hdc, 10, 10, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 2:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*20，图形放大一倍");
			SetMapMode(hdc, MM_ISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 20, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 3:
			str = _T("映射方式MM_ANISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*10，图形放大一倍，纵向不变");
			SetMapMode(hdc, MM_ANISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 10, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 4:
			str = _T("映射方式MM_ANISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*5，图形放大一倍，纵向缩小一倍");
			SetMapMode(hdc, MM_ANISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 5, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		case 5:
			str = _T("映射方式MM_ISOTROPIC:窗口坐标为10*10，映射为视口尺寸为20*5，图形为了保持原横纵比，系统会调整映射比例");
			SetMapMode(hdc, MM_ISOTROPIC);
			SetWindowExtEx(hdc, 10, 10, NULL);
			SetViewportExtEx(hdc, 20, 5, NULL);
			TextOut(hdc, 0, 0, str, _tcsclen(str));
			break;
		}
		hP = (HPEN)GetStockObject(BLACK_PEN);		//设置画笔为系统预定义的黑色画笔
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

			
		EndPaint(hWnd, &ps);		//释放设备环境句柄
		DeleteObject(hP);		//删除画笔句柄
		DeleteObject(hB);		//删除黑色画刷句柄
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
	//第一步：注册窗口类，指定窗口类的名称与窗口回调函数
	WNDCLASSEX wcex = { 0 };
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = WindowProc;
	wcex.lpszClassName = szWindowClass;

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL, _T("注册窗口类失败"), _T("Tip"), NULL);
		return 1;
	}

	//第二步：创建窗口，指定注册窗口类，窗口标题，窗口的大小
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
		MessageBox(NULL, _T("创建窗口失败！"), _T("Tip"), NULL);
		return 1;
	}

	//第三步：显示窗口
	ShowWindow(hWnd, nCmdShow);

	//第四步：开始消息循环
	MSG msg = { 0 };
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}