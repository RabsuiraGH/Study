﻿#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

double y_func(double x)
{
	return (exp(x) + exp(-x)) / 2 ;
}

double s_func(double x, int start_n, int end_n)
{
	double a_s = 1;
	double s = a_s;

	for (int n = start_n + 1; n < end_n; n++)
	{
		a_s *= (x * x) / ((2 * n - 1 ) * (2 * n));
		s += a_s;
	}
	return s;
}

int main()
{
	int start_n = 0;
	int k = 150;

	double a = 0.1;
	double b = 0.5;
	double h = (b - a) / 10.;

	cout << setprecision(5) << left;
	cout << setw(10) << "X" << setw(10) << "Y" << setw(10) << "S" << endl;

	for (double x = a; x < b + h / 2; x += h)
	{
		cout << setw(10) << x << setw(10) << y_func(x) << setw(10) << s_func(x, start_n, k + 1) << endl;
		cout << endl;
	}



	return 0;
}
