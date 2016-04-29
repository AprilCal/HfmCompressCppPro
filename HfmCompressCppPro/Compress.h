#pragma once

#ifndef COMPRESS_H
#define COMPRESS_H

#include<iostream>
using namespace std;

class Compress
{
public:
private:
	//change binString into byte
	char Str2Byte(const char *pBinStr);
	void Encode();
};

#endif // !COMPRESS_H