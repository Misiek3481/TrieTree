#pragma once

class Node {
private:
	Node** children;
	int x;

	void PrintNodes(int k);
public:
	Node(int x);
	void DeleteNodes(int k);

	Node* GetChild(int index) const;
	void SetNode(int index, Node* newNode, int k);
	bool IsValueX(int x) const;
	bool IsChildEmpty(int index) const;
	bool IsLast(void) const;
	bool HasNoneChildren(int k) const;
	int LastNode(int k);
	int LastNode(int n, int k);
	void DeleteLastNode(int k);
	void DeleteLastNode(int n, int k);
	void SetX(int x);
	void SetChildNull(int index, int k);
	void PrintTrie(int n, int k);
};