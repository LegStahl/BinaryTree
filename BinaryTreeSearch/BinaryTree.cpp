#include<iostream>
#include<fstream>
#include<string>
#include <stdexcept>
#include "BinaryTree.h"


BinaryTree::BinaryTree() {
	Tree = nullptr;
	countTr = 0;
}

BinaryTree::~BinaryTree() {
	del(*&Tree);
}

void BinaryTree::CreateTree(std::string a) {
	std::ifstream f(a);
	float r = 0;
	if (f.is_open()) {
		std::string str1;
		std::string str((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
		for (int i = 0; str[i] != '\0';i++) {
			if (((char)str[i] >= '0' && (char)str[i] <= '9') || (str[i] == '-')) {
				int count = 0;
				for (int j = i; str[j] != ' ' && str[j] != '\0' && str[j]!='\n'; j++) {
					count++;
				}
				str1 = str.substr(i, count);
				r = std::stof(str1);
				push(r, Tree);
				i += count;
				if (i >= str.length()) {
					break;
				}
			}
		}
	}
	else {
		throw std::ios_base::failure("File not found");
	}
}

void BinaryTree::push(float x, Node*& Tree) {
	if (nullptr == Tree)
	{
		countTr++;
		Tree = new Node;
		Tree->x = x;
		Tree->l = Tree->r = nullptr;
	}

	if (x < Tree->x)
	{
		if (Tree->l != nullptr)
			push(x, Tree->l);
		else
		{
			countTr++;
			Tree->l = new Node;
			Tree->l->l = Tree->l->r = nullptr;
			Tree->l->x = x;
		}
	}

	if (x > Tree->x)
	{
		if (Tree->r != nullptr)
			push(x, Tree->r);
		else
		{
			countTr++;
			Tree->r = new Node;
			Tree->r->l = Tree->r->r = nullptr;
			Tree->r->x = x;
		}
	}
}
bool BinaryTree::find_el(float x) {
	if (countTr != 0) {
		Node* t;
		t = Tree;
		for (;;) {
			if (x == t->x) {
				return true;
			}
			if (x > t->x) {
				if (t->r == nullptr)
					return false;
				t = t->r;
			}
			else {
				if (t->l == nullptr)
					return false;
				t = t->l;
			}
		}
	}
	else
		throw std::logic_error("Its is empty");
}

/*void BinaryTree::print(Node*& Tree) {

	if (Tree != NULL)
	{
		print(Tree->l);
		std::cout << Tree->x << '\t';
		print(Tree->r);
	}
}
*/
void BinaryTree::del(Node*& Tree) {
	if (Tree != nullptr)
	{

		del(Tree->l);
		del(Tree->r);
		delete Tree;
		Tree = nullptr;
	}
	else
		countTr = 0;
}