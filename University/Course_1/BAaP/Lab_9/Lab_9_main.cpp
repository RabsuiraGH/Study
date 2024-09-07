#include <iostream>
#include <io.h>
using namespace std;

struct Item
{
public:
	char name[20];
	int amount;
	double cost;

	Item()
	{
		name[0] = '\n';
		amount = 0;
		cost = 0;
	}

	void GetInfo()
	{
		cout << "name: " << name << " amount: " << amount << " cost: " << cost << endl;
	}
} item, *storage;

FILE* fl = nullptr;
char fileName[100] = "";

void Sorting(Item array[])
{
	int size = sizeof(array);
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
int Menu()
{
	cout << "Choose:" << endl;
	cout << "1. Enter data to file" << endl;
	cout << "2. Read and output data to console" << endl;
	cout << "3. Output data to text file" << endl;
	cout << "4. Exit" << endl;
	int i;
	cin >> i;
	return i;
}

char* InputFileName()
{
	cout << "Enter file name (dont forget about .bin or .txt) " << endl;
	cin.ignore();

	gets_s(fileName, 20);

	return fileName;
}

void CreateBinaryFile()
{
	char choice;
	if (fopen_s(&fl, InputFileName(), "ab"))
	{
		cout << "ERROR: error read file";
		return;
	}

	cout << fl << endl;

	if (fl != NULL)
	{
		cout << "File already exists, do you want tot override? (y/n)" << endl;
		cin >> choice;
		if (choice == 'y')
		{
			fclose(fl);
			fopen_s(&fl, fileName, "wb");
			if (fl == NULL)
			{
				cout << "ERROR: error create file" << endl;
				return;
			}
		}
		cin.ignore();
	}
	do
	{
		cout << "Input " << "" << " item name " << endl;

		gets_s(item.name, 20);

		cin.clear();

		cout << "Input " << "" << " item amount " << endl;
		cin >> item.amount;

		cout << "Input " << "" << " item cost " << endl;
		cin >> item.cost;

		fwrite(&item, sizeof(Item), 1, fl);

		cout << endl << "Do you want to continue? (y/n)" << endl;
		cin >> choice;
		cout << endl;
		cin.ignore();
	}
	while (choice == 'y');

	cin.clear();

	fclose(fl);
}

void ReadFileAndOutput()
{
	if (fopen_s(&fl, InputFileName(), "rb"))
	{
		cout << "ERROR: error read file";
		return;
	}

	int fileLength = _filelength(_fileno(fl)) / sizeof(Item);

	storage = new Item[fileLength];

	fread(storage, sizeof(Item), fileLength, fl);

	Sorting(storage);

	for (int i = 0; i < fileLength; i++)
	{
		if (storage[i].amount > 10 && storage[i].amount < 100)
			storage[i].GetInfo();
	}
	fclose(fl);
}
void OutputToFile()
{
	char fileName[20];
	FILE* ft;
	cout << "Enter textfile name" << endl;
	cin >> fileName;

	if (fopen_s(&ft, fileName, "w"))
	{
		cout << "ERROR: error create textfile" << endl; return;
	}

	if (fopen_s(&fl, InputFileName(), "rb"))
	{
		cout << "ERROR: error open textfile" << endl;
		return;
	}

	int fileLength = _filelength(_fileno(fl)) / sizeof(Item);

	storage = new Item[fileLength];

	fread(storage, sizeof(Item), fileLength, fl);

	Sorting(storage);

	for (int i = 0; i < fileLength; i++)
	{
		if (storage[i].amount > 10 && storage[i].amount < 100)
			item.GetInfo();

		fprintf(ft, "Name: %s, Amount: %d, Cost: %.2f\n", storage[i].name, storage[i].amount, storage[i].cost);
	}
	fclose(fl);
	fclose(ft);
}

int main()
{
	Item* storage = nullptr;
	int size = 0;


	while (true)
	{
		switch (Menu())
		{
		case 1: CreateBinaryFile(); break;
		case 2: ReadFileAndOutput(); break;
		case 3: OutputToFile(); break;
		case 4: return 0;
		default:
			"Enter right!";
		}
		puts("Press any key to continue");

		_fgetchar();

		system("cls");
	}
}