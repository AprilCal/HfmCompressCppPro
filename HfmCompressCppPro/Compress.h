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
Description: A Huffman Tree contains method to
construct and get HuffmanCode
**************************************************/

struct Head
{

	int length;
	//int weight[256];
};

class Compress
{
private:
	//change binString into byte
public:
	static char str2Byte(const char *pBinStr);
	static void compress(char *filename, char *filename2, char **code);
};

#endif // !COMPRESS_H