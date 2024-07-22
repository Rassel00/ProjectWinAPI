#pragma once
class BitmapManager
{
public:
	void DrawBitmap(HWND hWnd);
	void DrawRect(HBITMAP ah_bitmap, int a_sx, int a_sy, int a_ex, int a_ey);
};

