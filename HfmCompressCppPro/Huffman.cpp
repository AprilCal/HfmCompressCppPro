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
	s1 = INT16_MAX;
	
	int num;
	for (int i = 0;i <= size;i++)
	{
		if (p[i].parent == 0 && p[i].weight < s1)
		{
			s1 = p[i].weight;
			num = i;
		}
	}
	
	p[num].parent = n;
	return num;
	//int i = 0;
	//for (;i < size;i++)
	//{
	//	if (p[i].parent == 0)
	//		//temp = p[i].weight;
	//		s1 = p[i].weight;
	//}
	//int num = i;
	//for (int i = 0;i < size;i++)
	//{
	//	if (p[i].weight <s1 && p[i].parent == 0)
	//	{
	//		//temp = p[i].weight;
	//		s1 = p[i].weight;
	//		num = i;
	//	}
	//}

	//p[num].parent = n;
	////s1 = temp;
	//return num;
}

void HuffmanTree::showTree()
{
	for (int i = 0;i < size;i++)
	{
		cout << i << " " << tree[i].weight << " " << tree[i].parent << " " << tree[i].lchild << " " << tree[i].rchild << endl;
	}
}

HuffmanTree::HuffmanTree(int *p, int n)
{
	tree = new HTNode[2 * n - 1];
	leafSize = n;
	size = 2 * n - 1;

	for (int i = 0;i < n;i++)
	{
		tree[i].weight = p[i];
		tree[i].parent = 0;
		tree[i].lchild = 0;
		tree[i].rchild = 0;
	}

	for (int i = n;i < (2 * n - 1);i++)
	{
		tree[i].weight = INT16_MAX;
		tree[i].parent = 0;
		tree[i].lchild = 0;
		tree[i].rchild = 0;
	}

	for (int i = n;i < (2 * n - 1);i++)
	{
		int s1;
		int s2;
		int a = selectMin(tree, i, s1);
		int b = selectMin(tree, i, s2);
		cout << s1 << " " << s2 << " " << a << " " << b << endl;
		tree[i].weight = s1 + s2;
		tree[i].lchild = a;
		tree[i].rchild = b;
	}

}