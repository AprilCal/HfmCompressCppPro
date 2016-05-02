#include "stdafx.h"
#include "Huffman.h"
#include "Compress.h"
#include <iostream>

char Compress::str2Byte(const char *pBinStr)
{
	char b = 0x00;
	for (int i = 0;i < 8;i++)
	{
		b = b << 1;
		if (pBinStr[i] == '1')
		{
			b = b | 0x01;
		}
	}
		return b;
}

void Compress::compress(char *filename, char *filename2, char **code)
{
	FILE *in2;
	FILE *out;
	errno_t err3 = fopen_s(&out, filename2, "wb");
	errno_t err2 = fopen_s(&in2, filename, "rb");

	char *pBuffer;
	int pos = 0;
	char cd[256] = { 0 };
	pBuffer = new char[18];
	if (!pBuffer)
	{
		cout << "failed to create field";
	}

	Head head;
	//head.length = 10;
	head.length = _filelength(_fileno(in2));
	int ch2;
	//write file head
	fwrite(&head, 4, 1, out);
	while ((ch2 = getc(in2)) != EOF)
	{
		strcat_s(cd, code[ch2]);
		while (strlen(cd) >= 8)
		{
			pBuffer[pos++] = Compress::str2Byte(cd);
			fwrite(&pBuffer[pos - 1], 1, 1, out);
			//cout << pBuffer[pos - 1];

			for (int i = 0;i < 256 - 8;i++)
			{
				cd[i] = cd[i + 8];
			}
		}
		if (pos >= 16)
		{
			pos = 0;
		}
	}
	if (strlen(cd) > 0)
	{
		pBuffer[pos++] = Compress::str2Byte(cd);
		fwrite(&pBuffer[pos - 1], 1, 1, out);
		cout << pBuffer[pos - 1];
	}

	fclose(in2);
	fclose(out);
	delete[] pBuffer;
}











