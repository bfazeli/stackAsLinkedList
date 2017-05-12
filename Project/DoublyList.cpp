#include "DoublyList.h"

Stack::Stack()
{
	first = nullptr;
	last = nullptr;
	count = 0;
}

Stack::Stack(Node* first, int count)
{
	this->first = first;
	last = first;
	this->count = count;
}

Stack::Stack(Node* first, Node* last, int count)
{
	this->first = first;
	this->last = last;
	this->count = count;
}

void Stack::insertTop(int data)
{
	if (count == 0)
	{
		first = new Node(data, nullptr);
		last = first;
	}
	else
	{
		last->setNextLink(new Node(data, nullptr));
		last = last->getNextLink();
	}
	++count;
}

void Stack::print() const
{
	if (count == 0)
		cerr << "List is empty. Cannot print." << endl;
	else
	{
		Node *temp = first;

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
	Node *temp = first;

	while (first != nullptr)
	{
		first = first->getNextLink();
		delete temp;
		temp = first;
	}

	count = 0;
}

Stack::~Stack()
{
	destroyList();
}


