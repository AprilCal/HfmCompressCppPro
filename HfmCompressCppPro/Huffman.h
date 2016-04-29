#pragma once

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include<iostream>
using namespace std;

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
	HTNode * tree;
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
	HuffmanTree(int *p, int n);

	char** getHuffmanCodoArray();
	
	~HuffmanTree();

};

#endif // !HUFFMAN_H

