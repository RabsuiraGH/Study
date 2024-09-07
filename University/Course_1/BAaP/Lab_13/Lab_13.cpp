#include <iostream>
#include <string>
#include <cstdio>
#include <iomanip>
using namespace std;

struct Man
{
	Man()
	{
	}
	Man(string surname, int height, int weight)
	{
		this->surname = surname;
		this->height = height;
		this->weight = weight;
	}
	string surname = "";
	int height = -1;
	int weight = -1;

	void printInfo()
	{
		cout << fixed << setw(15) << "Surname: " << this->surname << setw(10) << " Weight: " << this->weight << setw(10) << " Height: " << this->height << endl;
	}
};

struct HashTable
{
public:
	HashTable(int size, int shiftModificator)
	{
		this->tableSize = size;
		this->shiftModificator = shiftModificator;
		initializeTable(tableSize);
		initializeShiftTable(tableSize);
	}

	void add(Man* data)
	{
		int i = abs(data->height % shiftModificator);
		for (int tryI = 0; hashTable[i] != NULL; tryI++)
		{
			i = (i + shiftArray[tryI]) % shiftModificator;

			if (i > tableSize)
			{
				cout << "Oops, hash table cannot handle this much elements! (" << i << ")" << endl;
				return;
			}
		}
		hashTable[i] = data;
	}

	void search(int key)
	{
		int i = abs(key % shiftModificator);
		for (int tryI = 0; hashTable[i] != NULL; tryI++)
		{
			if (hashTable[i]->height == key)
			{
				cout << "Element was found. Index: " << i << ". Info: ";
				hashTable[i]->printInfo();
				return;
			}
			i = (i + shiftArray[tryI]) % shiftModificator;
		}
	}

	void printTable()
	{
		cout << endl << "SHIFT ARRAY:" << endl;
		for (size_t i = 0; i < tableSize; i++)
		{
			cout << shiftArray[i] << " ";
		}

		cout << endl << "TABLE:" << endl;
		for (int i = 0; i < tableSize; i++)
		{
			cout << "Table element " << i << ": ";
			if (hashTable[i] == NULL)
				cout << hashTable[i] << endl;
			else
				hashTable[i]->printInfo();
		}
	}

	int size()
	{
		return tableSize;
	}

private:
	Man** hashTable = nullptr;
	int* shiftArray = nullptr;
	int shiftModificator = 0;
	int tableSize;

	void initializeShiftTable(int size)
	{
		srand(time(0));
		shiftArray = new int[size];
		for (int i = 0; i < size; i++)
		{
			shiftArray[i] = rand() % 10;
		}
	}

	void initializeTable(int size)
	{
		hashTable = new Man * [tableSize] {NULL};
	}
};

int main()
{
	HashTable hashTable(10, 10);

	string names[]{ "Vika", "Vova", "Dodo", "Alex", "Kirill", "Andrew", "Bob", "Ben", "Govard" };

	int count;
	cout << "Enter count of elements: ";
	cin >> count;

	Man* mans = new Man[count];
	int height;

	for (int i = 0; i < count; i++)
	{
		cout << "Enter height: ";
		cin >> height;
		//height = rand() % 100 + 100;
		Man* man = new Man(names[rand() % 9], height, rand() % 20 + 50);
		mans[i] = *man;
	}

	cout << endl;
	for (int i = 0; i < count; i++)
	{
		cout << "Man " << i << ": ";
		mans[i].printInfo();
		hashTable.add(&mans[i]);
	}

	hashTable.printTable();

	cout << endl << endl << endl;

	cout << "Enter required height: ";

	cin >> height;

	hashTable.search(height);
}