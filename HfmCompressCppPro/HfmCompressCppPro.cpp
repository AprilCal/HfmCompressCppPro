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
#include "DeCompress.h"
using namespace std;




int main()
{
	cout << "Huffman File Compress Pro..." << endl;
	cout << "please input file path & file name:";
	char filename[256];
	char filename2[256] = {0};
	cin >> filename;
	strcat_s(filename2, filename);
	strcat_s(filename2, ".huf");

	//census weight for each byte 
	int weight[256] = { 0 };
	FILE *in;
	errno_t err = fopen_s(&in, filename, "rb");

	int ch;
	while ((ch = getc(in)) != EOF)
	{
		weight[ch]++;
	}
	fclose(in);

	//construct a huffman tree by the above array
	HuffmanTree ht = HuffmanTree(weight, 256);
	//get huffman code from class HuffmanTree
	char** code = ht.getHuffmanCodoArray();
	Compress::compress(filename, filename2,code);
	DeCompress::decompress(filename2, &ht);

    return 0;
}
//d:\cloud\123.txt
//d:\cloud\123.jpeg
//d:\cloud\123.jpeg.huf
//d:\cloud\123.png
//d:\cloud\1234.png.huf