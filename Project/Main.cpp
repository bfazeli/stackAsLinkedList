/***********************************************

	Class DoublyList

************************************************/

#include "DoublyList.h"

#include <iostream>
using namespace std;

int main()
{
	Stack stack1;
	for (int i = 0; i < 10; ++i)
	{
		stack1.insertTop(i);
	}

	stack1.print();
	Stack empty;

	Stack stack2(empty);

	stack2.print();

	cout << endl;
	system("Pause");
	return 0;
}

