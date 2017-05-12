#include "DoublyList.h"

Stack::Stack()
{
	first = nullptr;
	last = nullptr;
	count = 0;
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


