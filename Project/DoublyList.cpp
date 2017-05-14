#include "DoublyList.h"

Stack::Stack()
{
	last = nullptr;
	count = 0;
}

Stack::Stack(Node* newLast, int count)
{
	last = newLast;
	this->count = count;
}

Stack::Stack(const Stack& otherStack)
{
	count = otherStack.count;
	if (!otherStack.isEmpty())
	{
		Node* temp = otherStack.last;

		last = new Node(temp->getData(), nullptr);

		if (count > 1)
		{
			Node* placeHolder = last;

			while (temp->getNextLink() != nullptr)
			{
				last->setNextLink(new Node(temp->getNextLink()->getData(), nullptr));
				temp = temp->getNextLink();
				last = last->getNextLink();
			}
			last = placeHolder;
		}
	}
	else
	{
		last = nullptr;
	}
}

Stack& Stack::operator=(const Stack& otherStack)
{
	if (this != &otherStack)
	{
		destroyList();

		if (!otherStack.isEmpty())
		{
			Node* temp = otherStack.last->getNextLink();
			count = otherStack.count;

			last = new Node(otherStack.last->getData(), nullptr);

			if (count > 1)
			{
				Node* iterStack = last;

				while (temp != nullptr)
				{
					iterStack->setNextLink(new Node(temp->getData(), nullptr));
					temp = temp->getNextLink();
					iterStack = iterStack->getNextLink();
				}
			}
		}
		else
		{
			last = nullptr;
		}
	}
	else
	{
		cerr << "Can't assign to self." << endl;
	}

	return *this;
}

int Stack::getTop() const
{
	return last->getData();
}

void Stack::insertTop(int data)
{
	last = new Node(data, last);
	++count;
}

void Stack::pop()
{
	if (!isEmpty())
	{
		Node *temp = last;
		last = last->getNextLink();
		delete temp;
		--count;
	}
	else
	{
		cout << "Stack is empty, can't pop from an empty stack." << endl;
	}
}

bool Stack::isEmpty() const
{
	return count == 0;
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

void Stack::destroyStack()
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


