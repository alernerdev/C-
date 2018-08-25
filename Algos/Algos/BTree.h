#pragma once

class BTree;

class Node
{
public:
	friend class BTree;

	Node()
	{
		value = 0;
		pLeft = nullptr;
		pRight = nullptr;
	}
	int value;

protected:
	Node *pLeft;
	Node *pRight;
};

class BTree
{
public:
	BTree();
	~BTree();
	Node * Search(int value);
	void Insert(int value);
	void Print();

private:
	void destroyTree(Node *pLeaf);
	void insert(int value, Node * pLeaf);
	Node * search(int value, Node *pLeaf);
	void print(Node *pLeaf);

	Node *pRoot;
};

