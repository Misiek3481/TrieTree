#include <cstdio>
#include <cstdlib>
#include "Trie.h"

Trie::Trie(int n, int k)
	: root(nullptr), n(n), k(k) {}

Trie::~Trie(void) {
	for (int i = 0; i < n; i++)
		if (root->GetChild(i) != nullptr)
			root->GetChild(i)->DeleteNodes(k);
	delete root;
}

void Trie::ReadCommand(void) {
	char command;
	int x;
	if(std::scanf("\n%c", &command) != 1)
	{
		fprintf(stderr, "Error: Invalid command format provided.\n");
		exit(1);
	}
	switch (command) {
	case 'I':
		if(std::scanf("%d", &x) != 1)
		{
			fprintf(stderr, "Error: Invalid key format provided.\n");
			exit(1);
		}
		Insert(x);
		break;

	case 'L':
		if(std::scanf("%d", &x) != 1)
		{
			fprintf(stderr, "Error: Invalid key format provided.\n");
			exit(1);
		}
		CheckExistance(x);
		break;

	case 'D':
		if(std::scanf("%d", &x) != 1)
		{
			fprintf(stderr, "Error: Invalid key format provided.\n");
			exit(1);
		}
		Delete(x);
		break;

	case 'P':
		Print();
		break;
	}
}

void Trie::Insert(int x) {
	if (root == nullptr)
	{
		root = new Node(x);
		return;
	}
	Node* node = root;
	if (node->IsValueX(x))
	{
		std::printf("%d exist\n", x);
		return;
	}
	int rem = x % n;
	int div = x / n;
	while (!node->IsChildEmpty(rem))
	{
		node = node->GetChild(rem);
		if (node->IsValueX(x))
		{
			std::printf("%d exist\n", x);
			return;
		}
		rem = div % k;
		div = div / k;
	}
	if (node == root)
		node->SetNode(rem, new Node(x), n);
	else
		node->SetNode(rem, new Node(x), k);
}

void Trie::CheckExistance(int x) const{
	if (root == nullptr)
	{
		std::printf("%d not exist\n", x);
		return;
	}
	Node* node = root;
	if (node->IsValueX(x))
	{
		std::printf("%d exist\n", x);
		return;
	}
	int rem = x % n;
	int div = x / n;
	while (!node->IsChildEmpty(rem))
	{
		node = node->GetChild(rem);
		if (node->IsValueX(x))
		{
			std::printf("%d exist\n", x);
			return;
		}
		rem = div % k;
		div = div / k;
	}
	std::printf("%d not exist\n", x);
}

void Trie::Delete(int x) {
	if (root == nullptr)
	{
		std::printf("%d not exist\n", x);
		return;
	}
	Node* node = root;
	if (node->IsValueX(x))
	{
		if (node->IsLast())
		{
			delete node;
			root = nullptr;
		}
		else {
			node->SetX(node->LastNode(n, k));
			node->DeleteLastNode(n, k);
		}
		return;
	}
	int rem = x % n;
	int div = x / n;
	while (!node->IsChildEmpty(rem))
	{
		Node* temp = node;
		node = node->GetChild(rem);
		if (node->IsValueX(x))
		{
			if (node->IsLast())
			{
				delete node;
				if(temp==root)
					temp->SetChildNull(rem, n);
				else 
					temp->SetChildNull(rem, k);
			}
			else {
				node->SetX(node->LastNode(k));
				node->DeleteLastNode(k);
			}
			return;
		}
		rem = div % k;
		div = div / k;
	}
	std::printf("%d not exist\n", x);
}

void Trie::Print(void) {
	root->PrintTrie(n, k);
	std::printf("\n");
}
