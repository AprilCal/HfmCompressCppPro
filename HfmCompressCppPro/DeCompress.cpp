#include "stdafx.h"
#include "Huffman.h"
#include "Compress.h"
#include "DeCompress.h"

/*************************************************
Copyright: AprilCal
Author: AprilCal
Date: 2016-05-02
Description: XD
**************************************************/

string DeCompress::int2str(int num)
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

void DeCompress::decompress(char *filename2, HuffmanTree *ht)
{
	//read file head
	Head _head;
	FILE *_in;
	errno_t _err = fopen_s(&_in, filename2, "rb");
	char decode[256];
	fread(&_head, sizeof(_head), 1, _in);

	FILE *_out;
	errno_t _err2 = fopen_s(&_out, "d:\\cloud\\56.png", "wb");
	char end = EOF;

	int _ch;
	string s;
	while ((_ch = getc(_in)) != EOF)
	{
		s = s + DeCompress::int2str(_ch);
	}

	//write code into new file
	int length = 0;
	while ((int)s.size() > 0)
	{
		int i;
		for (i = 511;ht->tree[i].lchild != 0 && (int)s.size()>0;)
		{
			if (s[0] == '0')
			{
				i = ht->tree[i].lchild;
			}
			else if (s[0] == '1')
			{
				i = ht->tree[i].rchild;
			}
			s.erase(0, 1);
		}
		if (length >= _head.length)
		{
			break;
		}
		if (ht->tree[i].lchild == 0)
		{
			char a = i - 1;
			fwrite(&a, 1, 1, _out);
			length++;
		}
	}
	//fseek(_out, 10, SEEK_SET);   /*将文件位置指针移动到文件末尾,-1是为了给后面要写入的“结束标志”留空间*/
	//fwrite(&end, 1, 1, _out);
	fclose(_in);
	fclose(_out);
}