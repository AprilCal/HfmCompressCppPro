#include "stdafx.h"
#include "Huffman.h"
#include <iostream>

using namespace std;

/*************************************************
Copyright: AprilCal
Author: AprilCal
Date: 2016-04-28
Description: A Huffman Tree contains method to 
construct and get HuffmanCode
**************************************************/
int HuffmanTree::selectMin(HTNode *p, int n, int &s1)
{
	s1 = INT32_MAX;
	
	int num;
	for (int i = 1;i <=size;i++)
	{
		if (p[i].parent == 0 && p[i].weight < s1)
		{
			s1 = p[i].weight;
			num = i;
		}
	}
	
	p[num].parent = n;
	return num;
}

void HuffmanTree::createHuffmanCode()
{
	char cd[256] = {'\0'};
	int cdlen = 0;//note length

	for (int i = 1;i <=size;i++)
	{
		//flag
		tree[i].weight = 0;
	}

	int p = size;//root

	while (p != 0)
	{
		if (tree[p].weight == 0)//trun left
		{
			tree[p].weight = 1;
			if (tree[p].lchild != 0)
			{
				p = tree[p].lchild;
				cd[cdlen++] = '0';
			}
			else if (tree[p].rchild == 0)
			{
				huffmanCode[p-1] = new char[256];
				cd[cdlen] = '\0';
				strcpy_s(huffmanCode[p-1],256, cd);
			}
		}
		
		else if (tree[p].weight == 1)
		{
			tree[p].weight = 2;
			if (tree[p].rchild != 0)
			{
				p = tree[p].rchild;
				cd[cdlen++] = '1';
			}
		}

		else
		{
			tree[p].weight = 0;
			p = tree[p].parent;
			--cdlen;
		}
	}//while
}

void HuffmanTree::showTree()
{
	for (int i = 1;i <=size;i++)
	{
		cout << i << " " << tree[i].weight << " " << tree[i].parent << " " << tree[i].lchild << " " << tree[i].rchild << endl;
	}
}

HuffmanTree::HuffmanTree(int *p, int n)
{
	tree = new HTNode[2 * n];
	leafSize = n;
	size = 2 * n-1;

	for (int i = 1;i <= leafSize;i++)
	{
		tree[i].weight = p[i-1];
		tree[i].parent = 0;
		tree[i].lchild = 0;
		tree[i].rchild = 0;
	}

	for (int i = leafSize + 1;i <=size ;i++)
	{
		tree[i].weight = INT32_MAX;
		tree[i].parent = 0;
		tree[i].lchild = 0;
		tree[i].rchild = 0;
	}

	for (int i = leafSize + 1;i <= size;i++)
	{
		int s1=0;
		int s2=0;
		int a = selectMin(tree, i, s1);
		int b = selectMin(tree, i, s2);
		//cout << s1 << " " << s2 << " " << a << " " << b << endl;
		tree[i].weight = s1 + s2;
		tree[i].lchild = a;
		tree[i].rchild = b;
	}
	createHuffmanCode();
}

char** HuffmanTree::getHuffmanCodoArray()
{
	return huffmanCode;
}

HuffmanTree::~HuffmanTree()
{
	delete[] tree;
}