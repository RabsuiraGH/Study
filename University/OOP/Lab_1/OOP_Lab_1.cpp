/*
Консольное приложение. Запросить у пользователя размер массива и его элементы.
На печать вывести исходные и преобразованные массивы.
По окончании работы с массивом освободить занимаемую им память.

19.	Организовать циклическую перестановку элементов n-мерного массива в группах из трех элементов.
*/

#include <iostream>
#include <stdio.h>
#include <string>

using namespace std;

int Factorial(int);
int CalculateCombinationsCount(int, int);
int DivideFactorial(int, int);
void BufferInString(string&, int*, int*, int);

int main()
{
#define DEBUG  1
	const int COMBO_COUNT = 3;
	int size = -1;
	int all_combinations_count = -1;
	int* numbers;
	string* combinations;
	int* buffer = new int[3];

	cout << "Enter count of numbers: ";
	cin >> size;

	if (size < 3) return 1;

	numbers = new int[size];

#if DEBUG
	for (int i = 0; i < size; i++)
	{
		numbers[i] = (i + 1);
	}
#else
	cout << "Enter numbers: " << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Number " << i + 1 << ": ";
		cin >> numbers[i];
	}
#endif // DEBUG

	all_combinations_count = DivideFactorial(size, size - COMBO_COUNT) / Factorial(COMBO_COUNT);

	combinations = new string[all_combinations_count]{ "" };

	for (int i = 0; i < COMBO_COUNT; i++)
	{
		buffer[i] = i;
	}

	int counter = 0;
	while (true)
	{
		BufferInString(combinations[counter++], numbers, buffer, COMBO_COUNT);

		int i = COMBO_COUNT - 1;
		while (i >= 0 && buffer[i] == size - COMBO_COUNT + i)
		{
			--i;
		}

		if (i < 0)
		{
			break;
		}

		++buffer[i];

		for (int j = i + 1; j < COMBO_COUNT; ++j)
		{
			buffer[j] = buffer[j - 1] + 1;
		}
	}

	for (int i = 0; i < all_combinations_count; i++)
	{
		cout << "Combination " << i << ": " << combinations[i] << endl;
	}

	delete[] numbers;
	delete[] combinations;
	delete[] buffer;

	return 0;
}

void BufferInString(string& target, int* source, int* buffer, int bufferSize)
{
	target = "";
	for (int i = 0; i < bufferSize; i++)
	{
		target += to_string(source[buffer[i]]) + " ";
	}
}

int CalculateCombinationsCount(const int size, const int byFor)
{
	return 0;
}

int DivideFactorial(const int high, const int low)
{
	int result = 1;
	for (int i = low + 1; i <= high; i++)
	{
		result *= i;
	}
	return result;
}

int Factorial(const int n)
{
	int result = 1;
	if (n == 0 || n == 1) return result;

	for (int i = n; i > 0; i--)
	{
		result *= i;
	}

	return result;
}