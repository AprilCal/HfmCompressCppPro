#pragma once

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<iostream>
using namespace std;

/*************************************************
Copyright: AprilCal
Author: AprilCal
Date: 2016-05-02
Description: A Huffman Tree contains method to
construct and get HuffmanCode
**************************************************/

struct HTNode
{
	int weight;
	int parent;
	int lchild;
	int rchild;
};

class HuffmanTree
{
private:
	// an array of HTNode
	// to store HuffmanCode
	char* huffmanCode[256];
	// the number of leaf node
	int leafSize;
	// number of all node
	int size;
	// select a minimal weight from {tree}
	int selectMin(HTNode *p, int n, int &s1);

	void showTree();

	void createHuffmanCode();
	
public:
	HTNode * tree;

	HuffmanTree(int *p, int n);

	char** getHuffmanCodoArray();
	
	~HuffmanTree();
};
#endif // !HUFFMAN_H

