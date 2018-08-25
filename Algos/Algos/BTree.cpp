#include "stdafx.h"
#include <iostream>

#include "BTree.h"


BTree::BTree()
{
	pRoot = nullptr;
}


BTree::~BTree()
{
	destroyTree(pRoot);
}


void BTree::Insert(int value)
{
	if (!pRoot)
	{
		pRoot = new Node();
		pRoot->value = value;
		return;
	}

	insert(value, pRoot);
}

Node * BTree::Search(int value)
{
	if (!pRoot)
		return nullptr;

	search(value, pRoot);
}

Node * BTree::search(int value, Node *pLeaf)
{
	if (!pLeaf)
		return nullptr;

	if (value == pLeaf->value)
		return pLeaf;
	else if (value > pLeaf->pRight->value)
		return search(value, pLeaf->pRight);
	else
		return search(value, pLeaf->pLeft);
}

void BTree::insert(int value, Node * pLeaf)
{
	if (value < pLeaf->value)
	{
		if (pLeaf->pLeft)
			insert(value, pLeaf->pLeft);
		else
		{
			pLeaf->pLeft = new Node();
			pLeaf->pLeft->value = value;
		}
	}
	else
	{
		if (pLeaf->pRight)
			insert(value, pLeaf->pRight);
		else
		{
			pLeaf->pRight = new Node();
			pLeaf->pRight->value = value;
		}
	}
}

void BTree::Print()
{
	if (!pRoot)
		return;

	print(pRoot);
}

void BTree::print(Node *pLeaf)
{
	if (!pLeaf)
		return;

	print(pLeaf->pLeft);
	std::cout << pLeaf->value << " " << std::endl;
	print(pLeaf->pRight);
}

void BTree::destroyTree(Node *pLeaf)
{
	if (!pLeaf)
		return;

	destroyTree(pLeaf->pLeft);
	destroyTree(pLeaf->pRight);
	delete pLeaf;
}