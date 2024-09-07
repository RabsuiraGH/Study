#include <iostream>
#include "parser.hpp"
#include <fstream>
#include <iomanip>

using namespace std;
using namespace	aria::csv;

template <typename T> void printArray(T, int);
template <typename T> void quickSort(T, int, int);
//template <typename T> void insertionSort(T, int);
template <typename T> void selectionSort(T, int);

template <typename T, typename U> struct Pair
{
	Pair(T value, U value2)
	{
		this->first = value;
		this->second = value2;
	};

	T first;
	U second;
};

template <typename T> struct Node
{
	Node* link;
	T value;
};

template <typename T> struct SingleLinkedList
{
public:
	Node<T>* top = nullptr;

	Node<T>* Top()
	{
		return top;
	}

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

	void clear()
	{
		while (top != nullptr)
		{
			Node<T>* toDelete = top;
			top = top->link;
			delete toDelete;
		}
	}
};

int main()
{
	ifstream file("some_file_data.csv");
	CsvParser parser(file);

	int arrayQS[100], arrayIS[100];

	int size = 0;

	for (auto& row : parser)
	{
		for (auto& field : row)
		{
			arrayQS[size] = stoi(field);
			arrayIS[size] = stoi(field);
			size++;
		}
	}

	cout << setw(15) << left << "Array: ";;
	printArray(arrayQS, size);

	cout << setw(15) << left << "Quick sort: ";
	quickSort(arrayQS, 0, size - 1);
	printArray(arrayQS, size);

	cout << setw(15) << left << "Selection sort: ";
	selectionSort(arrayIS, size);
	printArray(arrayIS, size);


}

template <typename T> void quickSort(T arr, int low, int high)
{
	SingleLinkedList<pair<int, int>> stack;

	stack.push_back(make_pair(low, high));

	while (!stack.isEmpty())
	{
		low = stack.Top()->value.first;
		high = stack.Top()->value.second;
		stack.pop_back();

		while (low < high)
		{
			int pivot = arr[(low + high) / 2];
			int i = low;
			int j = high;

			while (i <= j)
			{
				while (arr[i] < pivot) i++;
				while (arr[j] > pivot) j--;
				if (i <= j)
				{
					swap(arr[i], arr[j]);
					i++;
					j--;
				}
			}
			cout << endl << "Array:";
			printArray(arr, 9);
			cout << "Pivot: " << pivot;
			cout << " i/j " << i << " " << j;
			cout << " Low/High " << low << " " << high << endl;
			if ((j - low) < (high - i))
			{
				if (i < high)
				{
					stack.push_back(make_pair(i, high));
				}
				high = j;
			}
			else
			{
				if (low < j)
				{
					stack.push_back(make_pair(low, j));
				}
				low = i;
			}
		}
	}
}

//template <typename T> void insertionSort(T arr, int size)
//{
//	int i, key, j;
//
//	for (i = 1; i <= size; i++)
//	{
//		key = arr[i];
//		j = i - 1;
//		while (j >= 0 && arr[j] > key)
//		{
//			arr[j + 1] = arr[j];
//			j = j - 1;
//		}
//		arr[j + 1] = key;
//	}
//}
template <typename T> void selectionSort(T arr, int size) 
{
	for (int i = 0; i < size - 1; i++)
	{
		int minIndex = i;

		for (int j = i + 1; j < size; j++)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		if (minIndex != i)
		{
			int temp = arr[i];
			arr[i] = arr[minIndex];
			arr[minIndex] = temp;
		}
	}
}

template <typename T> void printArray(T arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}