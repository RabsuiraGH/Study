#include <iostream>
using namespace std;
int main()
{
	int n, max_in_row{}, max_in_col{};
	cout << "write numbers of rows and columns" << endl;
	cin >> n;
	double sum{}, mult = 1;
	double** a;           //объявили указатели
	a = new double* [n]; // выделили под них память

	for (int i = 0; i < n; i++)  //выделяем память для одномерных массивов
	{
		a[i] = new double[n];
	}

	cout << "write elements" << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{ //вводим наши элементы
			cin >> a[i][j];
		}
	}

	cout << "elements " << endl; // выводим и смотрим
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}

	int center = n / 2;

	for (int i = 0; i < n; i++)
	{
		int from, to;

		if (n % 2 == 1)
		{
			from = n % center + 1;
			to = (n - (n % center)) - 1;

			if (i == center) continue;
		}

		else
		{
			if (i == center) center = n - 1;

			from = n % center;
			to = n - (n % center);
		}
		for (int j = from; j < to; j++)
		{
			cout << a[i][j] << endl;
			sum += a[i][j];
			mult *= a[i][j];
		}
	}

	cout << sum << endl;
	cout << mult << endl;
	// чистка
	for (int i = 0; i < n; i++)
	{
		delete[] a[i];
	}
	delete[] a;

	return 0;
}