﻿// ProjectWinAPI.cpp : 애플리케이션에 대한 진입점을 정의합니다.
//

#include "pch.h"
#include "framework.h"
#include "ProjectWinAPI.h"



// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance, LPCWSTR szWindowClass);
BOOL                InitInstance(HINSTANCE, int, LPCWSTR szWindowClass, LPCWSTR szTitl);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);

// 참조 : tipssoft
// 접두어			추가 접두어  
// g_ : 전역 변수		h_ : 핸들 변수
// m_ : 멤버 변수		p_ : 포인터 변수
// a_ : 매개 변수		r_ : 참조 변수

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	LPCWSTR szWindowClass = L"RWE";
	LPCWSTR szTitle = L"ProjectWinAPI";

	MyRegisterClass(hInstance, szWindowClass);

	// 애플리케이션 초기화를 수행합니다:
	if (!InitInstance(hInstance, nCmdShow, szWindowClass, szTitle))
	{
		return FALSE;
	}

	MSG msg;

	// 기본 메시지 루프입니다:
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance, LPCWSTR szWindowClass)
{
	WNDCLASSEXW wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_PROJECTWINAPI));
	wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_PROJECTWINAPI);
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow, LPCWSTR szWindowClass, LPCWSTR szTitle)
{
	HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

	if (!hWnd)
	{
		return FALSE;
	}

	ShowWindow(hWnd, nCmdShow);
	// Draw
	UpdateWindow(hWnd);

	return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CLOSE:
	{
		if (MessageBox(hWnd, L"Exit?", L"Exit!!!", MB_OKCANCEL) == IDOK)
		{
			return DefWindowProc(hWnd, message, wParam, lParam);
		}

		break;
	}
	case WM_LBUTTONDOWN:
	{
		HDC h_dc = GetDC(hWnd);
		int x = LOWORD(lParam);
		int y = HIWORD(lParam);
		int width = 300;
		int height = 300;
		Rectangle(h_dc, x - width * 0.5f, y - width * 0.5f, x + width * 0.5f, y + width * 0.5f);
		ReleaseDC(hWnd, h_dc);
		break;
	}
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}

	return 0;
}

