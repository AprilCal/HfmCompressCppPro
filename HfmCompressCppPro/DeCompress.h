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
	static string int2str(int num)
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
private:
};


#endif // !DECOMPRESS_H


