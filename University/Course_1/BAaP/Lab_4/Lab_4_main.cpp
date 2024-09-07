#include <iostream>
#include <math.h>
#include <cmath>
#include <algorithm>

using namespace std;

int main()
{
	double array[] = { 6, 14, 151, 3, 5, 2, 5, 6, 2.12, 4.2 };

	double sum = 0;
	int maxIndex = 0;
	int minIndex = 0;

	//cout << array[78] << endl;
	//cout << sizeof(array) / sizeof(array[0]) << endl;

	for (int i = 0; i < sizeof(array) / sizeof(array[0]); i++)
	{
		minIndex = array[i] < array[minIndex] ? i : minIndex;
		maxIndex = array[i] > array[maxIndex] ? i : maxIndex;
	}

	for (int i = (minIndex < maxIndex ? minIndex : maxIndex) + 1; i < (minIndex > maxIndex ? minIndex : maxIndex); i++)
	{
		sum += array[i];
	}

	cout << sum << endl;

	return 0;
}

