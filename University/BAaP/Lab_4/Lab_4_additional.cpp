#include <iostream>
#include <string>

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
	double array[100];

	int usableAmount = SafeInput<int>("Input array work space", "Value should be type of Integer");

	for (int i = 0; i < usableAmount; i++)
	{
		//array[i] = SafeInput<double>("Input array element " + to_string(i), "Value should be number");
		array[i] = i;
	}

	int counter = 0;

	for (int i = 0; i < usableAmount; i++)
	{
		//counter++;
		
		//if (counter % 3 != 0) continue;

		if (i != 0 && i % 2 == 0)
		{
			for (int j = i; j < usableAmount; j++)
			{
				array[j] = array[j + 1];
			}
			//counter = 0;
			//i--;
			usableAmount--;
		}



	}

	cout << endl;

	for (int i = 0; i < usableAmount; i++)
	{
		cout << array[i] << endl;
	}
}

