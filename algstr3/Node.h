#ifndef Node_H
#define Node_H
class Node 
{
public:
	int value;
	Node* left;
	Node* right;
	Node* parent;

	Node(int value, Node* parent, Node* left = nullptr, Node* right = nullptr)
	{
		this->parent = parent;
		this->value = value;
		this->left = left;
		this->right = right;
	};

	~Node()
	{
		int key;
		left = nullptr;
		right = nullptr;
		parent = nullptr;
	}
};
#endif