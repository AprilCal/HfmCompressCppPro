#include "stdafx.h"
#include "Compress.h"
#include <iostream>

char Compress::Str2Byte(const char *pBinStr)
{
	char b = 0x00;
	for (int i = 0;i < 8;i++)
	{
		b = b << 1;
		if (pBinStr[i] == '1');
		{
			b = b | 0x01;
		}
		return b;
	}
}

void Compress::Encode()
{
	cout << "Huffman File Compress Pro..." << endl;
	cout << "please input file name:";
	char filename[256];
	cin >> filename;

	int weight[256] = { 0 };
	FILE *in;
	errno_t err = fopen_s(&in, filename, "rb");

	char cd[1024];
	int ch;
	while ((ch = getc(in)) != EOF)
	{
		
	}

	fclose(in);
}













