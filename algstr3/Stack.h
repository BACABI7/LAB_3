#ifndef Stack_H
#define Stack_H
#include"Tree.h"
#include"Node.h"
class stack
{
private:
	class stackNode {
	public:
		Node* date;
		stackNode* next;

		stackNode(Node* date = nullptr, stackNode* next = nullptr)
		{
			this->date = date;
			this->next = next;
		};
		~stackNode()
		{

		}

	};
public:
	stackNode* head;
	stackNode* tail;
	unsigned int size;
	stack() {
		head = nullptr;
		tail = nullptr;
		size = 0;
	}
	~stack() {
		clear();
	}
	void clear() {
		while (size != 0)
		{
			pop_front();
		}
	}
	void push(Node* date) {
		if (size == 0) {
			head = new stackNode(date);
			tail = head;
		}
		else {
			head = new stackNode(date, head);
		}
		size++;
	}
	void pop_front() {
		if (size == 0) {
			return;
		}
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			stackNode* cur = head;
			head = head->next;
			delete cur;
		}
		size--;

	}
	void pop_back() {
		if (size == 0) return;
		if (size == 1) {
			delete head;
			reset_list();
		}
		else {
			stackNode* cur = head;
			while (cur->next != tail) {
				cur = cur->next;
			}
			cur->next = nullptr;
			delete tail;
			tail = cur;
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