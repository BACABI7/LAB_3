#include "Tree.h"
#include<iostream>
int main()
{
	setlocale(LC_ALL, "Russian");
	Iterator* I1;
	Tree* Tree1 = new Tree;
	Tree1->insert(5);
	Tree1->insert(3);
	Tree1->insert(4);
	Tree1->insert(7);
	Tree1->insert(6);
	Tree1->insert(9);

	I1 = Tree1->CreateWidthIterator();
	std::cout << "Вывод итератора в ширину:";
	for (int i = 0; i < 6; i++) 
	{
		std::cout << I1->next() << " ";
	}
	std::cout << std::endl;
	I1 = Tree1->CreateDepthIterator();
	std::cout << "Вывод итератора в длинну: ";
	for (int i = 0; i < 6; i++) 
	{
		std::cout << I1->next() << " ";
	}
	return 0;
}