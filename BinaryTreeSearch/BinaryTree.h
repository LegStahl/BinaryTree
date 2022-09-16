#ifndef BINARYTREE
#define BINARYTREE


class BinaryTree
{
private:
	struct Node
	{
		float x;
		Node* l;
		Node* r;
	};
	int countTr;
	void del(Node*& Tree);
	void push(float x, Node*& Tree);
	Node* Tree;
public:
	void CreateTree(std::string a);
	BinaryTree();
	~BinaryTree();
	bool find_el(float x);
};
#endif 

