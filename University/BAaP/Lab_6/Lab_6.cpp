#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double y_function(double&);

double s_function(double&);

int main()
{
	double a = -0.5;
	double b = 0.5;
	double step = (b - a) / 10;


	cout << 10E309 / 10E309<< endl;


	/*for (double x = a; x < b + step / 2; x += step)
	{
		cout << x << setw(15) << y_function(x) << setw(15) << s_function(x) << endl;
	}*/

	return 0;
}

double y_function(double& x)
{
	return exp(x);
}

double s_function(double& x)
{
	double s = 1;
	double a = 1;

	double fact = 1;

	int n = 1;
	double const PRECISION = 10e-4;

	while (true)
	{
		a = pow(x, (2 * n - 1)) * (2 * n + x);

		fact /= ((2 * n - 1) * (2 * n));

		cout << "Fact is   " << fact << " A is    " << a << endl;

		a *= fact;

		if (abs(a) < PRECISION) break;
		s += a;

		n++;
	}
	return s;
}