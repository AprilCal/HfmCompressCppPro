#pragma once

#pragma once

#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include<iostream>
using namespace std;

class DeCompress
{
public:
	//convert a int num into a bin string
	static string int2str(int num);

	static void decompress(char *filename2, HuffmanTree *ht);
private:
};


#endif // !DECOMPRESS_H


