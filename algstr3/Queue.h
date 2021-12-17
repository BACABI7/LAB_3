#ifndef Queue_H
#define Queue_H
#include"Tree.h"
#include"Node.h"

class queue
{
private:
	class QNode 
	{
	public:
		Node* Element;
		QNode* next;
		QNode(Node* element = nullptr, QNode* next = nullptr)
		{
			this->Element = element;this->next = next;
		};
		~QNode(){}
	};

public:
	QNode* head;
	QNode* tail;
	unsigned int size;

	queue()
	{
		tail = nullptr;
		head = nullptr;
		size = 0;
	}

	~queue() 
	{
		clear();
	}

	void clear()
	{
		while (size != 0)
		{
			pop();
		}
	}

	void push(Node* date) 
	{
		if (size == 0)
		{
			head = new QNode(date);
			tail = head;
		}
		else
		{
			tail->next = new QNode(date);
			tail = tail->next;
		}
		size++;
	}

	void pop()
	{
		if (size == 0) 
		{
			return;
		}
		if (size == 1) 
		{
			delete head;
			reset_list();
		}
		else
		{
			QNode* cur = head;
			head = head->next;
			delete cur;
		}
		size--;
	}

	void reset_list()
	{
		head = nullptr;
		tail = nullptr;
	}

};
#endif