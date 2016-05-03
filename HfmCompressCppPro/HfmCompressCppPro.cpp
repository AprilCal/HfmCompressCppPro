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



/*************************************************
Copyright: AprilCal
Author: AprilCal
Date: 2016-05-02
Description: Program entry
**************************************************/
int main()
{
	cout << "Huffman File Compress Pro..." << endl;
	cout << "input 1 to compress a file" << endl;
	cout << "input 2 to decompress a file" << endl;
	cout << "input 3 to exit" << endl;
	

	HuffmanTree *ht;

	int i;
	while (cin >> i)
	{
		if (i == 1)
		{
			cout << "please input the path of file you want to compress:" << endl;
			char filename[256] = { 0 };
			char filename2[256] = { 0 };
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
			ht=new HuffmanTree(weight, 256);
			//get huffman code from class HuffmanTree
			char** code = ht->getHuffmanCodoArray();
			Compress::compress(filename, filename2, code, ht);
		}		
		else if (i == 2)
		{
			cout << "please input the path of file you want to decompress:" << endl;
			char filename[256] = { 0 };
			cin >> filename;
			DeCompress::decompress(filename);
		}
		else if (i == 3)
		{
			break;
		}
		else
		{
			cout << "please input a number between 1 & 3" << endl;
		}
		cout << "input 1 to compress a file" << endl;
		cout << "input 2 to decompress a file" << endl;
		cout << "input 3 to exit" << endl;
	}
	cout << "exit..." << endl;
	delete ht;
    return 0;
}
//d:\cloud\123.txt
//d:\cloud\123.jpeg
//d:\cloud\123.jpeg.huf
//d:\cloud\12345.png
//d:\cloud\12345.png.huf