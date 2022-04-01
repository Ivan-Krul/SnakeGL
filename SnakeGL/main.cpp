#include <windows.h>
#include <gl/GL.h>
#include <chrono>
#include "UIPainter.h"
#include "defines.h"

#pragma comment(lib, "opengl32.lib")
#pragma comment(lib, "winmm.lib")

LRESULT CALLBACK WindowProc(HWND, UINT, WPARAM, LPARAM);
void EnableOpenGL(HWND hwnd, HDC*, HGLRC*);
void DisableOpenGL(HWND, HDC, HGLRC);

int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	WNDCLASSEX wcex;
	HWND hwnd;
	HDC hDC;
	HGLRC hRC;
	MSG msg;
	BOOL bQuit = FALSE;
	float theta = 0.0f;

	//жжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжж
	srand(time(NULL));
	bool is_pause = false;
	UIPainter ux;
	ux.setup();
	//жжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжжж

	/* register window class */
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_OWNDC;
	wcex.lpfnWndProc = WindowProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = L"GLSample";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);;


	if (!RegisterClassEx(&wcex))
		return 0;

	/* create main window */
	hwnd = CreateWindowEx(0,
		L"GLSample",
		L"SnakeGL",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		WindowX,
		WindowY,
		NULL,
		NULL,
		hInstance,
		NULL);

	ShowWindow(hwnd, nCmdShow);

	/* enable OpenGL for the window */
	EnableOpenGL(hwnd, &hDC, &hRC);

	//PlaySoundW(L"D:\\Chrome Downloads\\sound\\YinYang_WhenImByYou.wav", NULL, SND_ASYNC);

	std::chrono::system_clock::time_point beg, end;

	/* program main loop */
	while (!bQuit)
	{

		/* check for messages */
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
		{
			/* handle or dispatch messages */
			if (msg.message == WM_QUIT)
			{
				bQuit = TRUE;
			}
			else
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
		}
		else
		{
			beg = std::chrono::system_clock::now();
			if (GetAsyncKeyState(' ')) { is_pause = !is_pause; Sleep(100); }

			if (!is_pause) {
				/* OpenGL animation code goes here */
				glClearColor(0.5, 0.5, 0.5, 0.0f);
				glClear(GL_COLOR_BUFFER_BIT);

				glLoadIdentity();
				glTranslated(-1, -1, 0);
				glScaled(2, 2, 0);

				ux.logic();
				ux.paint();

				//glSupport::glRectangled(0, 0, PixelX, PixelY, 0, 0, 0);
				//glSupport::glRectangled(PixelX, 0, PixelX * 2.0, PixelY, 0, 0, 1);
				//glSupport::glRectangled(PixelX * 2.0, 0, PixelX * 3.0, PixelY, 0, 1, 0);
				//glSupport::glRectangled(PixelX * 3.0, 0, PixelX * 4.0, PixelY, 0, 1, 1);
				//glSupport::glRectangled(PixelX * 4.0, 0, PixelX * 5.0, PixelY, 1, 0, 0);
				//glSupport::glRectangled(PixelX * 5.0, 0, PixelX * 6.0, PixelY, 1, 0, 1);
				//glSupport::glRectangled(PixelX * 6.0, 0, PixelX * 7.0, PixelY, 1, 1, 0);
				//glSupport::glRectangled(PixelX * 7.0, 0, PixelX * 8.0, PixelY, 1, 1, 1);
				//glSupport::glRectangled(0, PixelY, PixelX, PixelY * 2.0, 0, 0, 1);
				//glSupport::glRectangled(0, PixelY * 2.0, PixelX, PixelY * 3.0, 0, 1, 0);
				//glSupport::glRectangled(0, PixelY * 3.0, PixelX, PixelY * 4.0, 0, 1, 1);
				//glSupport::glRectangled(0, PixelY * 4.0, PixelX, PixelY * 5.0, 1, 0, 0);
				//glSupport::glRectangled(0, PixelY * 5.0, PixelX, PixelY * 6.0, 1, 0, 1);
				//glSupport::glRectangled(0, PixelY * 6.0, PixelX, PixelY * 7.0, 1, 1, 0);
				//glSupport::glRectangled(0, PixelY * 7.0, PixelX, PixelY * 8.0, 1, 1, 1);

				SwapBuffers(hDC);
				theta += 1.0f;
			}

			end = std::chrono::system_clock::now();
			int time = std::chrono::duration_cast<std::chrono::nanoseconds>(end-beg).count();
			time /= 100;
			Sleep(90.0/(double(time)/1000.0));
		}
	}

	/* shutdown OpenGL */
	DisableOpenGL(hwnd, hDC, hRC);

	/* destroy the window explicitly */
	DestroyWindow(hwnd);

	return msg.wParam;
}

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CLOSE:
		PostQuitMessage(0);
		break;

	case WM_DESTROY:
		return 0;

	case WM_KEYDOWN:
	{
		switch (wParam)
		{
		case VK_ESCAPE:
			PostQuitMessage(0);
			break;
		}
	}
	break;

	default:
		return DefWindowProc(hwnd, uMsg, wParam, lParam);
	}

	return 0;
}

void EnableOpenGL(HWND hwnd, HDC* hDC, HGLRC* hRC)
{
	PIXELFORMATDESCRIPTOR pfd;

	int iFormat;

	/* get the device context (DC) */
	*hDC = GetDC(hwnd);

	/* set the pixel format for the DC */
	ZeroMemory(&pfd, sizeof(pfd));

	pfd.nSize = sizeof(pfd);
	pfd.nVersion = 1;
	pfd.dwFlags = PFD_DRAW_TO_WINDOW |
		PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
	pfd.iPixelType = PFD_TYPE_RGBA;
	pfd.cColorBits = 24;
	pfd.cDepthBits = 16;
	pfd.iLayerType = PFD_MAIN_PLANE;

	iFormat = ChoosePixelFormat(*hDC, &pfd);

	SetPixelFormat(*hDC, iFormat, &pfd);

	/* create and enable the render context (RC) */
	*hRC = wglCreateContext(*hDC);

	wglMakeCurrent(*hDC, *hRC);
}

void DisableOpenGL(HWND hwnd, HDC hDC, HGLRC hRC)
{
	wglMakeCurrent(NULL, NULL);
	wglDeleteContext(hRC);
	ReleaseDC(hwnd, hDC);
}

