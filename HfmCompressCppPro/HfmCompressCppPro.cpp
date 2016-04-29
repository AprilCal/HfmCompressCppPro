// HfmCompressCppPro.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include "huffman.h"

using namespace std;

char str2Byte(const char *pBinStr)
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

int main()
{
	//cout << "Huffman File Compress Pro..." << endl;
	//cout << "please input file name:";
	//char filename[256];
	//cin >> filename;

	//int weight[256] = { 0 };
	//FILE *in;
	//errno_t err = fopen_s(&in, filename, "rb");


	//int ch;
	//while ((ch = getc(in)) != EOF)
	//{
	//	weight[ch]++;
	//}
	//cout << "Byte " << "Weight" << endl;
	////for (int i = 0;i < 256;i++)
	////{
	////	cout << "Ox" << "%X"<<i << setw(10);
	////	cout << weight[i] << " " << endl;
	////}
	//fclose(in);



	//HuffmanTree ht = HuffmanTree(weight, 256);

	//char** code = ht.getHuffmanCodoArray();
	//for (int i = 0;i < 256;i++)
	//{
	//	cout << code[i]<<endl;
	//}


	//FILE *in2;
	//errno_t err2 = fopen_s(&in2, filename, "rb");
	//char *pBuffer;
	//int pos = 0;

	//char cd[30] = { 0 };

	//pBuffer = new char[10];
	//if (!pBuffer)
	//{
	//	cout << "failed to create field";
	//}

	//int ch2;
	//while ((ch2 = getc(in2)) != EOF)
	//{
	//	strcat_s(cd, code[ch2]);
	//	while (strlen(cd) >= 8)
	//	{
	//		pBuffer[pos++] = str2Byte(cd);
	//		cout << pBuffer[pos - 1];
	//		for (int i = 0;i < 30 - 8;i++)
	//		{
	//			cd[i] = cd[i + 8];
	//		}
	//	}

	//	//if (strlen(cd) > 0)
	//	//{
	//	//	pBuffer[pos++] = str2Byte(cd);
	//	//}
	//}

	//fclose(in2);
	//cout << "success" << endl;

	struct Stu
	{
		int a;
		int b;
	};
	Stu s1;
	s1.a = 1;
	s1.b = 2;
	Stu s2;
	s2.a = 3;
	s2.b = 4;
	FILE *in;
	errno_t err = fopen_s(&in, "d:\\cloud\\23.txt", "wb");
	fwrite(&s1, sizeof(s1), 1, in);
	fwrite(&s2, sizeof(s2), 1, in);

	char a = '1';
	fwrite(&a,sizeof(a),1,in);
	

	fclose(in);

	int ch;
	FILE *out;
	errno_t err2 = fopen_s(&out,"d:\\cloud\\23.txt", "rb");

	Stu s3,s4;
	char a2;

	fread(&s3, sizeof(s3), 1, out);
	fread(&s4, sizeof(s4), 1, out);
	fread(&a2, sizeof(a2), 1, out);

	fclose(out);
	cout << s3.a << " " << s3.b << endl;
	cout << s4.a << " " << s4.b << endl<<a2;

    return 0;
}

