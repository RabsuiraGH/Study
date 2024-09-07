#include <iostream>

using namespace std;

struct Item
{
public:
	char* name;
	int amount;
	double cost;

	Item()
	{
		name = new char[20];
		amount = 0;
		cost = 0;
	}

	void GetInfo()
	{
		cout << "name: " << name << " amount: " << amount << " cost: " << cost << endl;
	}
};

void Sorting(Item array[], int size)
{
	for (int i = 1; i < size; i++)
	{
		Item key = array[i];
		int j = i - 1;

		while (j >= 0 && strcmp(array[j].name, key.name) > 0)
		{
			array[j + 1] = array[j];
			j--;
		}

		array[j + 1] = key;
	}
}

int main()
{
	Item* storage;
	int size;

	cout << "Input storage size" << endl;
	cin >> size;

	storage = new Item[size];

	for (int i = 0; i < size; i++)
	{
		cout << "Input " << i << " item name " << endl;
		char name[20];
		cin.ignore();
		gets_s(name, 20);

		cout << "Input " << i << " item amount " << endl;
		int amount;
		cin >> amount;

		cout << "Input " << i << " item cost " << endl;
		double cost;
		cin >> cost;

		storage[i] = Item(name, amount, cost);
	}

	Sorting(storage, size);
	for (int i = 0; i < size; i++)
	{
		if (storage[i].amount > 10 && storage[i].amount < 100)
			storage[i].GetInfo();
	}
	return 0;
}