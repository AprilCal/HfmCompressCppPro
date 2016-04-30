// HfmCompressCppPro.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include "huffman.h"
#include "Compress.h"

using namespace std;

//char str2Byte(const char *pBinStr)
//{
//	char b = 0x00;
//	for (int i = 0;i < 8;i++)
//	{
//		b = b << 1;
//		if (pBinStr[i] == '1')
//		{
//			b = b | 0x01;
//		}
//	}
//		return b;
//}

int main()
{
	Head head;
	head.length = 10;

	cout << "Huffman File Compress Pro..." << endl;
	cout << "please input file name:";
	char filename[256];
	char filename2[256];
	cin >> filename;
	cin >> filename2;

	int weight[256] = { 0 };
	FILE *in;
	errno_t err = fopen_s(&in, filename, "rb");

	int ch;
	while ((ch = getc(in)) != EOF)
	{
		weight[ch]++;
	}
	fclose(in);

	HuffmanTree ht = HuffmanTree(weight, 256);

	char** code = ht.getHuffmanCodoArray();
	for (int i = 0;i < 256;i++)
	{
		cout << code[i]<<endl;
	}

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
		//if (strlen(cd) > 0)
		//{
		//	pBuffer[pos++] = str2Byte(cd);
		//	cout << pBuffer[pos - 1];
		//}
	}
	if (strlen(cd) > 0)
	{
		pBuffer[pos++] = Compress::str2Byte(cd);
		fwrite(&pBuffer[pos - 1], 1, 1, out);
		cout << pBuffer[pos - 1];
	}

	fclose(in2);
	fclose(out);
	cout << "success" << endl;
	delete[] pBuffer;
    return 0;


	//Head head;
	//FILE *in;
	//errno_t err2 = fopen_s(&in, "d:\\cloud\\23.txt", "rb");
	//fread(&head, sizeof(head), 1, in);
	//cout << head.length;
	//fclose(in);
	//return 0;
}


//d:\cloud\123.txt
//	//FILE *in;
//	//errno_t err = fopen_s(&in, "d:\\cloud\\23.txt", "wb");
//	//fwrite(&s1, sizeof(s1), 1, in);
//	//fwrite(&s2, sizeof(s2), 1, in);
//
//	//char a = '1';
//	//fwrite(&a,sizeof(a),1,in);
//	//
//
//	//fclose(in);
//
//	//int ch;
//	//FILE *out;
//	//errno_t err2 = fopen_s(&out,"d:\\cloud\\23.txt", "rb");
//
//	//Stu s3,s4;
//	//char a2;
//
//	//fread(&s3, sizeof(s3), 1, out);
//	//fread(&s4, sizeof(s4), 1, out);
//	//fread(&a2, sizeof(a2), 1, out);
//
//	//fclose(out);
//	//cout << s3.a << " " << s3.b << endl;
//	//cout << s4.a << " " << s4.b << endl << a2 << endl;
//
//	return 0;
//}