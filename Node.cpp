#include <cstdio>
#include "Node.h"

Node::Node(int x) 
	: children(nullptr), x(x) {}

void Node::DeleteNodes(int k) {
	if (children != nullptr)
		for (int i = 0; i < k; i++)
			if (children[i] != nullptr)
			{
				children[i]->DeleteNodes(k);
				delete children[i];
			}
}

Node* Node::GetChild(int index) const{
	return children[index];
}

void Node::SetNode(int index, Node* newNode, int k) {
	if (children == nullptr)
	{
		children = new Node * [k];
		for (int i = 0; i < k; i++)
			children[i] = nullptr;
	}
	children[index] = newNode;
}

bool Node::IsValueX(int x) const {
	return this->x == x;
}

bool Node::IsLast(void) const {
	return children == nullptr;
}

bool Node::HasNoneChildren(int k) const {
	for (int i = 0; i < k; i++)
		if (children[i] != nullptr)
			return false;
	return true;
}

bool Node::IsChildEmpty(int index) const {
	return (children == nullptr || children[index] == nullptr);
}

int Node::LastNode(int k) {
	if(children==nullptr)
		return this->x;
	for (int i = 0; i < k; i++)
		if (children[i] != nullptr)
			return children[i]->LastNode(k);
	return this->x;
}

int Node::LastNode(int n, int k) {
	if (children == nullptr)
		return this->x;
	for (int i = 0; i < n; i++)
		if (children[i] != nullptr)
			return children[i]->LastNode(k);
	return this->x;
}

void Node::DeleteLastNode(int k) {
	for (int i = 0; i < k; i++)
		if (children[i] != nullptr)
		{
			if (children[i]->IsLast())
			{
				delete children[i];
				children[i] = nullptr;
				if(HasNoneChildren(k))
					children = nullptr;
			}
			else
				children[i]->DeleteLastNode(k);
			return;
		}
}

void Node::DeleteLastNode(int n, int k) {
	for (int i = 0; i < n; i++)
		if (children[i] != nullptr)
		{
			if (children[i]->IsLast())
			{
				delete children[i];
				children[i] = nullptr;
				if (HasNoneChildren(n))
					children = nullptr;
			}
			else
				children[i]->DeleteLastNode(k);
			return;
		}
}

void Node::SetX(int x) {
	this->x = x;
}

void Node::SetChildNull(int index, int k) {
	children[index] = nullptr;
	if (HasNoneChildren(k))
		children = nullptr;
}

void Node::PrintNodes(int k) {
	std::printf("%d ", x);
	if( !IsLast() )
		for (int i = 0; i < k; i++)
			if(children[i]!=nullptr)
				children[i]->PrintNodes(k);
}

void Node::PrintTrie(int n, int k) {
	std::printf("%d ", x);
	if (!IsLast())
		for (int i = 0; i < n; i++)
			if (children[i] != nullptr)
				children[i]->PrintNodes(k);
}