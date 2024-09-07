#include <iostream>
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
	char seppareter[] = " ";

	int length = SafeInput<int>("Enter string length", "Value should be integer");
	cin.ignore();

	char* charArray = new char[length];
	char* cutArray = NULL;
	char* word = NULL;

	cout << "Enter string " << endl;
	gets_s(charArray, length);

	cout << "Start string: ";
	puts(charArray);

	word = strtok_s(charArray, seppareter, &cutArray);

	while (word != NULL)
	{
	
		for (int i = 0; i < strlen(word); i++)
		{
			if (i == 2) cout << "*";
			else cout << word[i];
		}
		cout << " ";
		word = strtok_s(NULL, seppareter, &cutArray);
	}


	return 0;
}