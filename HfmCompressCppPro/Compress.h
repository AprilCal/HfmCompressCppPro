#pragma once

#ifndef COMPRESS_H
#define COMPRESS_H

#include "Huffman.h"
#include <iostream>
using namespace std;

struct Head
{

	int length;
	int weight[256];
};

class Compress
{
private:
	//change binString into byte
	char str2Byte(const char *pBinStr);
	void Encode();
};

#endif // !COMPRESS_H