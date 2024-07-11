#include "pch.h"
#include "BitmapGenerator.h"

#define BMP_WIDTH 300
#define BMP_HEIGHT 200

void BitmapGenerator::DrawRect(HBITMAP ah_bitmap, int a_sx, int a_sy, int a_ex, int a_ey)
{
	unsigned int* p = new unsigned int[BMP_WIDTH * BMP_HEIGHT];

	GetBitmapBits(ah_bitmap, BMP_WIDTH * BMP_HEIGHT * 4, p);

	int i = 0;
	unsigned int* p_pos = p + a_sy * BMP_WIDTH + a_sx;

	delete[] p;
}
