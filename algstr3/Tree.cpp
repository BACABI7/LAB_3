#include"Tree.h"
#include<iostream> 
#include"stack.h"

Tree::Tree()
{
	Root = nullptr;
}
Tree::~Tree(){}

void Tree::insert(int val)
{
	if (Root == NULL) 
	{
		Root = new Node(val, NULL, NULL);
	}
	else 
	{
		Node* cur;
		cur = Root;
		while(true) 
		{
			if (val <= cur->value) 
			{
				if (cur->left == NULL) 
				{
					cur->left = new Node(val, cur);
					break;
				}
				cur = cur->left;
			}
			else {
				if (cur->right == NULL) 
				{
					cur->right = new Node(val, cur);
					break;
				}
				cur = cur->right;
			}
		}
	}
}

void Tree::remove(int val)
{
	if (!contains(val)) 
	{
		throw "element is absent";
	}
	else 
	{
	Node* cur;
	cur = Root;
	if (cur->value == val) {
		if (cur->left == NULL && cur->right == NULL) 
		{
			delete cur;
			return;
		}
		if (cur->left != NULL && cur->right == NULL) 
		{
			cur->left->parent = cur->parent;
			Root = cur->left;
			delete cur;
			return;
		}
		if (cur->left == NULL && cur->right != NULL) 
		{
			cur->right->parent = cur->parent;
			Root = cur->right;
			delete cur;
			return;
		}
		else 
		{
			Node* supCurrent;
			supCurrent = cur->right;
			if (supCurrent->left != NULL) 
			{
				while (supCurrent->left != NULL) 
				{
					supCurrent = supCurrent->left;
				}
				supCurrent->parent->left = NULL;
			}
			else 
			{
				supCurrent->parent->right = supCurrent->right;
			}
			cur->left->parent = supCurrent;
			supCurrent->left = cur->left;
			supCurrent->parent = cur->parent;
			while (supCurrent->right != NULL)
			{
				supCurrent = supCurrent->right;
			}
			cur->right->parent = supCurrent;
			supCurrent->right = cur->right;
			return;
		}
	}
	while (true)
	{
		if (val <= cur->value) 
		{
			cur = cur->left;
			if (cur->parent->left->value == val) 
			{
				if (cur->left == NULL && cur->right == NULL) 
				{
					cur->parent->left = NULL;
					delete cur;
					break;
				}
				if (cur->left != NULL && cur->right == NULL) 
				{
					cur->parent->left = cur->left;
					cur->left->parent = cur->parent;
					delete cur;
					break;
				}
				if (cur->left == NULL && cur->right != NULL) 
				{
					cur->parent->left = cur->right;
					cur->right->parent = cur->parent;
					delete cur;
					break;
				}
				else 
				{
					Node* supCurrent;
					supCurrent = cur->right;
					if (supCurrent->left != NULL) 
					{
						while (supCurrent->left != NULL) 
						{
							supCurrent = supCurrent->left;
						}
						supCurrent->parent->left = NULL;
					}
					else 
					{
						supCurrent->parent->right = supCurrent->right;
					}
					cur->parent->left = supCurrent;
					cur->left->parent = supCurrent;
					supCurrent->left = cur->left;
					supCurrent->parent = cur->parent;
					while (supCurrent->right != NULL)
					{
						supCurrent = supCurrent->right;
					}
					cur->right->parent = supCurrent;
					supCurrent->right = cur->right;
					delete cur;
					break;
				}
			}
		}
		else 
		{
			cur = cur->right;
			if (cur->parent->right->value == val) 
			{
				if (cur->left == NULL && cur->right == NULL) 
				{
					cur->parent->right = NULL;
					delete cur;
					break;
				}
				if (cur->left != NULL && cur->right == NULL) 
				{
					cur->parent->right = cur->left;
					cur->left->parent = cur->parent;
					delete cur;
					break;
				}
				if (cur->left == NULL && cur->right != NULL) 
				{
					cur->parent->right = cur->right;
					cur->right->parent = cur->parent;
					delete cur;
					break;
				}
				else 
				{
					Node* supCurrent;
					supCurrent = cur->right;
					if (supCurrent->left != NULL)
					{
						while (supCurrent->left != NULL) 
						{
							supCurrent = supCurrent->left;
						}
						supCurrent->parent->left = NULL;
					}
					else
					{
						supCurrent->parent->right = supCurrent->right;
					}
					cur->parent->right = supCurrent;
					cur->left->parent = supCurrent;
					supCurrent->left = cur->left;
					supCurrent->parent = cur->parent;
					while (supCurrent->right != NULL)
					{
						supCurrent = supCurrent->right;
					}
					supCurrent->right = cur->right;
					cur->right->parent = supCurrent;
					delete cur;
					break;
				}
			}

		}
	}
	}

}

bool Tree::contains(int val)
{
	if (Root == NULL)
	{
		return 0;
	}
	else {
		Node* cur;
		cur = Root;
		for (;;) {
			if (val <= cur->value) {
				if (cur->value == val)
				{
					return 1;
				}
				if (cur->left == NULL)
				{
					return 0;
				}
				cur = cur->left;
			}
			else {
				if (cur->value == val)
				{
					return 1;
				}
				if (cur->right == NULL)
				{
					return 0;
				}
				cur = cur->right;
			}
		}
	}
}

Tree::DepthIterator::DepthIterator(Node* root) 
{
	cur = root;
	if (cur != nullptr) 
	{
		Stack.push(cur);
	}
	else {
		throw "Tree is empty";
	}
}

Tree::DepthIterator::~DepthIterator(){}

int Tree::DepthIterator::next() 
{
	int tmp = cur->value;
	if (!has_next()) {
		throw "Tree is empty";
	}
	if (cur->right != nullptr) 
	{
		if (check) {
			Stack.pop_front();
			check = false;
		}
		Stack.push(cur->right);
	}
	if (cur->left != nullptr) 
	{
		cur = cur->left;
	}
	else
	{
		if (check) {
			Stack.pop_front();
		}
		if (has_next()) {
			cur = Stack.head->date;
		}
		check = true;
	}
	return tmp;
}

bool Tree::DepthIterator::has_next()
{
	if (cur->left == nullptr && cur->right == nullptr && Stack.size == 0) return false;
	else return true;
}
Tree::WidthIterator::WidthIterator(Node* root) 
{
	cur = root;
	if (cur != nullptr) {
		Queue.push(cur);
	}
	else {
		throw "Tree is empty";
	}

}

Tree::WidthIterator::~WidthIterator() 
{
	delete cur;
	Queue.clear();
}

int Tree::WidthIterator::next() 
{

	if (!has_next()) 
	{
		throw "Tree is empty";
	}
	cur = Queue.head->Element;
	Queue.pop();
	if (cur->left != nullptr) 
	{
		Queue.push(cur->left);
	}
	if (cur->right != nullptr) 
	{
		Queue.push(cur->right);
	}
	return cur->value;
}

bool Tree::WidthIterator::has_next() 
{
	if (cur->left == nullptr && cur->right == nullptr && Queue.size == 0) return false;
	else return true;
}