#pragma once

#ifndef COMPRESS_H
#define COMPRESS_H

#include "Huffman.h"
#include <iostream>
#include <io.h>
using namespace std;

/*************************************************
Copyright: AprilCal
Author: AprilCal
Date: 2016-05-02
Description: XD
**************************************************/

struct Head
{

	int length;
	HTNode tree[512];
	//int weight[256];
};

class Compress
{
private:
	//change binString into byte
public:
	static char str2Byte(const char *pBinStr);
	static void compress(char *filename, char *filename2, char **code, HuffmanTree *ht);
};

#endif // !COMPRESS_H