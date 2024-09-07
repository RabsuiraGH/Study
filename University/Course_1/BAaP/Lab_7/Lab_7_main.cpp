#include <iostream>
#include <stdlib.h>
using namespace std;

template <typename T> T SafeInput(const string& inputMessage, const string& errorMessage)
{
	T tempValue;

	while (true)
	{
		cout << inputMessage << endl;

		if (!(cin >> tempValue) || (cin.peek() != '\n'))
		{
			cout << errorMessage << endl << "Restarting process" << endl << endl;
			cin.ignore(1000, '\n');
			cin.clear();
			continue;
		}
		return tempValue;
	}
};
int main()
{
	//11000011010010100011
	//11011010010111

	int length = SafeInput<int>("Enter string length", "Value should be integer");
	cin.ignore();

	char* charArray = new char[length];
	char* zeroPointer = NULL;


	cout << "Enter string " << endl;
	gets_s(charArray, length);

	cout << "Start string: ";
	puts(charArray);

	

	zeroPointer = strstr(charArray, "000");

	while (zeroPointer != NULL)
	{
		length -= 3;
		for (int j = zeroPointer - charArray; j < length; j++)
		{
			charArray[j] = charArray[j + 3];
		}

		zeroPointer = strstr(charArray, "000");
	}

	cout << endl;
	cout << "Final string: ";
	puts(charArray);

	return 0;
}