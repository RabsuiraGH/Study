#include <iostream>

using namespace std;

template <typename T> struct SingleLinkedList
{
public:
	template <typename T> struct Node
	{
		Node* link;
		T value;
	};

	Node<T>* top = nullptr;

	bool isEmpty()
	{
		if (top) return false;
		else true;
	}

	void push_back(T value)
	{
		Node<T>* temp = new Node<T>;

		temp->value = value;
		temp->link = top;

		top = temp;
	}

	void pop_back()
	{
		Node<T>* temp = top;

		top = top->link;

		delete temp;
	}

	void removeAllNegatives()
	{
		if (top == nullptr)
			return;

		while (top != nullptr && top->value < 0)
		{
			Node<T>* temp = top;
			top = top->link;
			delete temp;
		}

		Node<T>* current = top;

		while (current != nullptr && current->link != nullptr)
		{
			if (current->link->value >= 0)
			{
				current = current->link;
				continue;
			}

			Node<T>* toDelete = current->link;
			current->link = toDelete->link;
			delete toDelete;
		}
	}

	/*void swapIt(int first, int second)
	{
		if (top == nullptr)
			return;
		if (first == second) return;

		Node<T>* current = top;
		Node<T>* temp = nullptr;

		if (first == 1 && second == 2)
		{
			temp = top;
			top = top->link;
			temp->link = top->link;
			top->link = temp;
			return;
		}

		int element = 0;
		while (current->link != nullptr)
		{
			if (first + element == 1)
			{
				temp = top;
				top = temp->link;
			}
			else if (element == first - 1 - 1)
			{
				temp = current->link;
				current->link = current->link->link;
				element++;
			}
			if (element == second - 1 - 1)
			{
				temp->link = current->link->link;
				current->link->link = temp;
				break;
			}

			element++;
			current = current->link;
		}
		current = top;
		element = 0;

		while (current->link != nullptr)
		{
			if (element == second - 1 - 2)
			{
				temp = current->link;
				current->link = current->link->link;
				break;
			}
			element++;
			current = current->link;
		}

		current = top;
		element = 0;

		while (current->link != nullptr)
		{
			if (first + element == 1)
			{
				temp->link = top;
				top = temp;
				break;
			}
			else if (element == first - 1 - 1)
			{
				temp->link = current->link;
				current->link = temp;

				break;
			}
			element++;
			current = current->link;
		}
	}

	Node<T>* getAt(int index)
	{
		Node<T>* current = top;
		int currentIndex = 0;

		while (current != nullptr)
		{
			if (currentIndex == index)
				return current;

			current = current->link;
			currentIndex++;
		}
	}

	void swap(Node<T>* first, Node<T>* second)
	{
		if (top == nullptr)
			return;
		if (first == second) return;

		Node<T>* current = top;

		if (first == top)
		{
			current = top->link;
			top->link = second->link;
			top = second;
			top->link = current;
		}

		while (current != nullptr)
		{
			cout << current->value << endl;

			if (current->link == first)
			{
				current->link = second;
				current = first->link;

				first->link = second->link;
				second->link = current;
			}

			if (current->link == second)
			{
				current->link = first;
				return;
			}

			current = current->link;
		}
	}*/

	void print()
	{
		Node<T>* current = top;

		while (current != nullptr)
		{
			cout << current->value << " ";
			current = current->link;
		}
		cout << endl;
	}

	void clear()
	{
		while (top != nullptr)
		{
			Node<T>* toDelete = top;
			top = top->link;
			delete toDelete;
		}
	}

	/*void check(int* arr)
	{
		Node<T>* current = top;
		int index = 0;
		bool good = true;
		while (current != nullptr && good)
		{
			if (arr[index] != current->value)
				good = false;
			index++;
			current = current->link;
		}

		cout << good;
	}*/
};

void printArr(int* arr, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main()
{
	SingleLinkedList<int> stack;

	const int size = 10;
	int arr[10]{ 0 };

	int count = 0;
	int element = 0;
	cout << "Enter elements count: ";
	cin >> count;

	for (int i = 0; i < count; i++)
	{
		cout << "Enter element " << i << ": ";
		cin >> element;
		stack.push_back(element);
		//stack.push_back(rand() % 10 - 5);
	}

	cout << "Current state of stack: ";
	stack.print();

	cout << "Without negative: ";
	stack.removeAllNegatives();

	stack.print();
}