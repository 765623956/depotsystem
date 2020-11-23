//第一个C++窗口程序
//2020.10.15
#include<Windows.h>
#include<tchar.h>

static TCHAR szWindowClass[] = _T("WindowClass");
static TCHAR szTitle[] = _T("基本绘图");

//第五步：窗口函数中处理窗口消息
LRESULT CALLBACK WindowProc(HWND hWnd,UINT uMsg,WPARAM wParam,LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	HBRUSH hB;
	HPEN hP;
	//TCHAR greeting[] = _T("绘制了一行字显示在程序中！");
	
	switch (uMsg)
	{
	case WM_PAINT:
		hdc = BeginPaint(hWnd,&ps);		//获得设备环境句柄
		SetMapMode(hdc, MM_TEXT);		//设置映射模式
		//TextOut(hdc,5,5,greeting,_tcslen(greeting));
		Rectangle(hdc,130,60,270,200);		//使用当前画笔绘制矩形并填充
		hB = CreateHatchBrush(HS_CROSS,RGB(255,0,0));		//自定义一个红色网格状画刷
		SelectObject(hdc, hB);		//更新画刷位自定义画刷
		Ellipse(hdc,130,70,270,190);		//回值椭圆并填充
		hP = CreatePen(PS_DASHDOT,1,RGB(0,255,0));		//定义宽度为1的绿色画笔，画点画线
		SelectObject(hdc,hP);		//更新画笔为自定义画笔

		MoveToEx(hdc, 100, 130, NULL);		//使用当前画笔绘制轴线
		LineTo(hdc,300,130);
		MoveToEx(hdc,200,30,NULL);
		LineTo(hdc,200,230);

		EndPaint(hWnd, &ps);		//释放设备环境句柄
		DeleteObject(hP);		//删除画笔句柄
		DeleteObject(hB);		//删除黑色画刷句柄
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
	//第一步：注册窗口类，指定窗口类的名称与窗口回调函数
	WNDCLASSEX wcex = {0};
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.lpfnWndProc = WindowProc;
	wcex.lpszClassName = szWindowClass;

	if (!RegisterClassEx(&wcex)) {
		MessageBox(NULL,_T("注册窗口类失败"),_T("Tip"),NULL);
		return 1;
	}

	//第二步：创建窗口，指定注册窗口类，窗口标题，窗口的大小
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
		MessageBox(NULL,_T("创建窗口失败！"),_T("Tip"),NULL);
		return 1;
	}

	//第三步：显示窗口
	ShowWindow(hWnd,nCmdShow);

	//第四步：开始消息循环
	MSG msg = {0};
	while (GetMessage(&msg,NULL,0,0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}