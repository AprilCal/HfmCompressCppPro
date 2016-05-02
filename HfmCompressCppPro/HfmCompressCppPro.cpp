// HfmCompressCppPro.cpp : 定义控制台应用程序的入口点。

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#include <string>
#include <tchar.h>
#include <io.h>
#include "huffman.h"
#include "Compress.h"
using namespace std;

//convert a int num into a bin string
string int2str(int num)
{
	string s;
	while (true)
	{
		s = ((num % 2) ? "1" : "0") + s;
		num = num / 2;
		if (num == 0)
		{
			break;
		}
	}
	while ((int)s.size() < 8)
	{
		s = "0" + s;
	}
	return s;
}

int main()
{

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

	Head head;
	head.length = 10;
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
	cout << "success" << endl;


	delete[] pBuffer;
	cout << endl;


	//read file head
	Head _head;
	FILE *_in;
	errno_t _err = fopen_s(&_in, filename2, "rb");
	char decode[256];
	fread(&_head, sizeof(_head), 1, _in);


	FILE *_out;
	errno_t _err2 = fopen_s(&_out,"d:\\cloud\\56.txt", "wb");
	char end = EOF;
	



	//if (_in)
	//{
	//	int size = _filelength(_fileno(_in));
	//	cout<< "size:" <<size<< endl;
	//}

	int _ch;
	string s;
	while ((_ch = getc(_in)) != EOF)
	{
		s =s + int2str(_ch);
		//while ((int)s.size() > 10)
		//{
		//	int i;
		//	for (i = 511;ht.tree[i].lchild != 0;)
		//	{
		//		if (s[0] == '0')
		//		{
		//			i = ht.tree[i].lchild;
		//		}
		//		else if (s[0] == '1')
		//		{
		//			i = ht.tree[i].rchild;
		//		}
		//		else
		//		{
		//			goto
		//		}
		//		s.erase(0, 1);
		//	}
		//	char a = i-1;
		//	cout << endl << a;
		//}
	}
	int length=0;
	while ((int)s.size() > 0)
	{
		int i;
		for (i = 511;ht.tree[i].lchild != 0&&(int)s.size()>0;)
		{
			if (s[0] == '0')
			{
				i = ht.tree[i].lchild;
			}
			else if (s[0] == '1')
			{
				i = ht.tree[i].rchild;
			}
			s.erase(0, 1);
		}
		if (length>=14)
		{
			break;
		}
		if (ht.tree[i].lchild == 0)
		{
			char a = i-1;
			fwrite(&a, 1, 1, _out);
			length++;
			cout << endl << a;
		}
	}

	//fseek(_out, 10, SEEK_SET);   /*将文件位置指针移动到文件末尾,-1是为了给后面要写入的“结束标志”留空间*/
	//fwrite(&end, 1, 1, _out);

	fclose(_in);
	fclose(_out);
    return 0;
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