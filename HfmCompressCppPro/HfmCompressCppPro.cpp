// HfmCompressCppPro.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include "huffman.h"
using namespace std;

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
	//for (int i = 0;i < 256;i++)
	//{
	//	cout << "Ox" << "%X"<<i << setw(10);
	//	cout << weight[i] << " " << endl;
	//}
	//fclose(in);

	int a[] = { 5,29,7,8,14,23,3,11 };
	HuffmanTree ht=HuffmanTree(a,8);
	ht.showTree();


	cout << "success" << endl;
	//cout << INT16_MAX;
    return 0;
}

