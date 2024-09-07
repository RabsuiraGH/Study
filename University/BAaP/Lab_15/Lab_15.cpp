#include <iostream>
#include <list>
#include <cstdlib>

using namespace std;

template <typename T> class DoubleLinkedList
{
public:
	template <typename T> struct Node
	{
		Node* next;
		Node* prev;
		T value;
	};

	Node<T>* head = nullptr;
	Node<T>* tail = nullptr;
	int size = 0;

	bool isEmpty()
	{
		return size;
	}

	Node<T>* getAt(int index)
	{
		if (index < 0 || index > size - 1) return nullptr;
		if (index == 0) return head;
		if (index == size - 1) return tail;

		int currentIndex = 0;
		Node<T>* current = head;
		while (current)
		{
			if (currentIndex == index)
			{
				return current;
			}
			currentIndex++;
			current = current->next;
		}
	}

	void push_back(T value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = value;
		newNode->next = nullptr;
		newNode->prev = tail;

		if (tail)
		{
			tail->next = newNode;
		}
		else
		{
			head = newNode;
		}
		tail = newNode;

		size++;
	}

	void pop_back()
	{
		if (tail)
		{
			Node<T>* toDelete = tail;
			tail = tail->prev;

			if (tail)
			{
				tail->next = nullptr;
			}
			else
			{
				head = nullptr;
			}

			delete toDelete;

			size--;
		}
	}

	template <typename T> void push_front(T value)
	{
		Node<T>* newNode = new Node<T>;
		newNode->value = value;
		newNode->next = head;
		newNode->prev = nullptr;

		if (head)
		{
			head->prev = newNode;
		}
		else
		{
			tail = newNode;
		}
		head = newNode;
		size++;
	}

	template <typename T> void pop_front()
	{
		if (head)
		{
			Node<T>* toDelete = head;
			head = head->next;

			if (head)
			{
				head->prev = nullptr;
			}
			else
			{
				tail = nullptr;
			}

			delete toDelete;
			size--;
		}
	}

	template <typename T> void remove(Node<T>* node)
	{
		Node<T>* current = head;
		while (current)
		{
			if (current->value == node->value)
			{
				if (current->next == nullptr)
				{
					tail = current->prev;
				}
				else
					current->next->prev = current->prev;

				if (current->prev == nullptr)
				{
					head = current->next;
				}
				else
					current->prev->next = current->next;
				delete current;
				size--;
				return;
			}
			current = current->next;
		}
	}

	template <typename T> void insert(T value, Node<T>* beforeNode)
	{
		if (!beforeNode) return;

		cout << "Before val: " << beforeNode->value << endl;

		Node<T>* newNode = new Node<T>;
		newNode->value = value;
		newNode->next = beforeNode;
		newNode->prev = beforeNode->prev;

		if (beforeNode->prev)
		{
			beforeNode->prev->next = newNode;
		}
		else
		{
			head = newNode;
		}
		beforeNode->prev = newNode;
		size++;
	}

	template <typename T> void insert(T value, int beforeIndex)
	{
		if (beforeIndex > size - 1 || beforeIndex < 0) return;
		if (beforeIndex == 0)
		{
			push_front(value);
			return;
		}

		Node<T>* insertBeforeNode = head;
		int index = 0;
		while (insertBeforeNode)
		{
			if (index == beforeIndex)
			{
				insert(value, insertBeforeNode);
				return;
			}

			index++;
			insertBeforeNode = insertBeforeNode->next;
		}
	}

	void print()
	{
		Node<T>* current = head;

		while (current)
		{
			cout << current->value << " ";
			current = current->next;
		}
		cout << endl;
	}

	void clear()
	{
		while (head)
		{
			Node<T>* toDelete = head;
			head = head->next;
			delete toDelete;
		}
		tail = nullptr;
	}
};

int main()
{
	char symbols[] = "-+*/%";
	DoubleLinkedList<char> list_1;
	DoubleLinkedList<int> list_2;

	int n = 0;
	char buffer = 0;
	cout << "Enter size: ";
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		cout << "Enter " << i << " value: ";
		cin >> buffer;
		list_1.push_front(buffer);
	}

	list_1.print();

	DoubleLinkedList<char>::Node<char>* bufferNode = nullptr;

	for (int i = 0; i < list_1.size; i++)
	{
		bufferNode = list_1.getAt(i);

		if (strchr(symbols, bufferNode->value))
		{
			list_1.remove(bufferNode);
			i--;
		}
	}

	list_1.print();
}