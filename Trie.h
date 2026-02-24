#pragma once
#include "Node.h"

class Trie
{
private:
	Node* root;
	int n, k;

	void Insert(int x);
	void CheckExistance(int x) const;
	void Delete(int x);
	void Print(void);
public:
	Trie(int n, int k);
	~Trie(void);

	void ReadCommand(void);
};

