#pragma once

#pragma once

#ifndef DECOMPRESS_H
#define DECOMPRESS_H

#include<iostream>
using namespace std;

/*************************************************
Copyright: AprilCal
Author: AprilCal
Date: 2016-05-02
Description: XD
**************************************************/

class DeCompress
{
public:
	//convert a int num into a bin string
	static string int2str(int num);

	static void decompress(char *filename2, HuffmanTree *ht);
private:
};


#endif // !DECOMPRESS_H


