#include "pch.h"
#include "BitmapManager.h"

void BitmapManager::DrawRect(HBITMAP ah_bitmap, int a_sx, int a_sy, int a_ex, int a_ey)
{
	unsigned int* p = new unsigned int[BMP_WIDTH * BMP_HEIGHT];

	GetBitmapBits(ah_bitmap, BMP_WIDTH * BMP_HEIGHT * 4, p);

	int i = 0;
	unsigned int* p_pos = p + (size_t)a_sy * BMP_WIDTH + a_sx;
	for (i = 0; i < a_ex - a_sx; ++i)
	{
		*p_pos = 0X00FFFF00;
		p_pos++;
	}

	p_pos = p + ((size_t)a_ey - 1) * BMP_WIDTH + a_sx;
	for (i = 0; i < a_ex - a_sx; ++i)
	{
		*p_pos = 0x00FFFF00;
		p_pos++;
	}

	p_pos = p + (size_t)a_sy * BMP_WIDTH + a_sx;
	for (i = 0; i < a_ey - a_sy; ++i) 
	{
		*p_pos = 0x00FFFF00;
		p_pos += BMP_WIDTH;
	}

	p_pos = p + (size_t)a_sy * BMP_WIDTH + a_ex - 1;
	for (i = 0; i < a_ey - a_sy; ++i)
	{
		*p_pos = 0x00FFFF00;
		p_pos += BMP_WIDTH;
	}

	SetBitmapBits(ah_bitmap, BMP_WIDTH * BMP_HEIGHT * 4, p);

	delete[] p;
}
