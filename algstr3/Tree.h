#ifndef Tree_H
#define Tree_H

#include"Node.h"
#include"Queue.h"
#include"Stack.h"
#include "Iterator.h"

class Tree
{
private:
    Node* Root;
public:
    Tree();
    ~Tree();
    bool contains(int);
    void insert(int);
    void remove(int);

    Iterator* CreateWidthIterator() 
    {
        return new WidthIterator(Root);
    }
    Iterator* CreateDepthIterator()
    {
        return new DepthIterator(Root);
    }

    class WidthIterator : public Iterator 
    {
    private:
        Node* cur;
        queue Queue;
    public:
        WidthIterator(Node* root);
        ~WidthIterator();
        int next();
        bool has_next();
    };

    class DepthIterator : public Iterator 
    {
    private:
        Node* cur;
        stack Stack;
        bool check = true;
    public:
        DepthIterator(Node* root);
        ~DepthIterator();
        int next();
        bool has_next();
    };

};
#endif