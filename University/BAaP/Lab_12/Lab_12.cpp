#include <iostream>
#include <string>
#include "parser.hpp"

using namespace std;
using namespace	aria::csv;

template <typename T> void printArray(T, int);

template <typename T> void quickSort(T, int, int);

//template <typename T, typename V> int interpolationSearch(T, int, V);
template <typename T, typename V> int linearSearch(T, int, V);
template <typename T, typename V> int binarySearch(T, int, V);

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

	int arrayQS[100];

	int size = 0;

	for (auto& row : parser)
	{
		for (auto& field : row)
		{
			arrayQS[size++] = stoi(field);
		}
	}

	quickSort(arrayQS, 0, size - 1);

	cout << "Array: " << endl;
	printArray(arrayQS, size);
	cout << endl;

	cout << "Enter value to search: ";

	int value;

	cin >> value;
	cout << endl;

	int resultIndex = binarySearch(arrayQS, size, value);
	cout << "Binary search: " << endl;

	if (resultIndex == -1)
		cout << "No any values in array" << endl;
	else
		cout << "Searched index: " << resultIndex << endl;

	cout << endl;

	cout << "Linear search: " << endl;

	resultIndex = linearSearch(arrayQS, size, value);

	if (resultIndex == -1)
		cout << "No any values in array" << endl;
	else
		cout << "Searched index: " << resultIndex << endl;
}

template <typename T, typename V> int binarySearch(T arr, int size, V value)
{
	int left = 0;
	int right = size - 1;

	while (left <= right)
	{
		int mid = left + (right - left) / 2;

		if (arr[mid] == value)
			return mid;
		else if (arr[mid] < value)
			left = mid + 1;
		else
			right = mid - 1;
	}

	return -1;
}

template <typename T, typename V> int linearSearch(T arr, int size, V value)
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value) return i;
	}
	return -1;
}

//template <typename T, typename V> int interpolationSearch(T arr, int size, V value)
//{
//	int low = 0, high = (size - 1);
//
//	while (low <= high && value >= arr[low] && value <= arr[high])
//	{
//		if (low == high)
//		{
//			if (arr[low] == value) return low;
//			return -1;
//		}
//
//		int pos = low + (((double)(high - low) / (arr[high] - arr[low])) * (value - arr[low]));
//
//		if (arr[pos] == value)
//			return pos;
//
//		if (arr[pos] < value)
//			low = pos + 1;
//		else
//			high = pos - 1;
//	}
//	return -1;
//}
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

template <typename T> void printArray(T arr, int size)
{
	for (int i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}