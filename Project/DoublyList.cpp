#include "DoublyList.h"

Stack::Stack()
{
	last = nullptr;
	count = 0;
}

Stack::Stack(Node* last, int count)
{
	this->last = last;
	this->count = count;
}

void Stack::insertTop(int data)
{
	last = new Node(data, last);
	++count;
}

void Stack::print() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = last;

		while (temp != nullptr)
		{
			cout << temp->getData() << " ";
			temp = temp->getNextLink();
		}
		cout << endl;
	}
}

void Stack::destroyList()
{
	Node *temp = last;

	while (last != nullptr)
	{
		last = last->getNextLink();
		delete temp;
		temp = last;
	}

	count = 0;
}

Stack::~Stack()
{
	destroyList();
}


