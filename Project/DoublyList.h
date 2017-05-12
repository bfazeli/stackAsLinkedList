#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <string>
#include <iostream>
using namespace std;

class Node
{
public:
	Node() : data(0), nextLink(NULL) {}
    Node (int theData, Node *next)
            : data(theData), nextLink(next) {}
    Node *getNextLink( ) const { return nextLink; }
    int getData( ) const { return data; }
    void setData(int theData) { data = theData; }
    void setNextLink(Node *pointer) { nextLink = pointer; }
	~Node(){}
private:
    int data;
    Node *nextLink;
};


class Stack
{
public:
	Stack();

	Stack(Node* last, int count);

	void insertTop(int newData);

	void print() const;

	void destroyList();
	~Stack();

	// Function declaration

private:	
    Node *last;		
	int count;		
};

#endif