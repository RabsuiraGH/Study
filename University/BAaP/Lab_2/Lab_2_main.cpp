#include <iostream>
#include <math.h>
#include <string>
#include <iomanip>

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

int lab_2()
{
	cout << setprecision(3) << fixed;

	int func_type;
	double x;
	double y;

	double k;

	double func;

	while (true)
	{
		x = SafeInput<double>("Input X:", "Incorrect X input");

		y = SafeInput<double>("Input Y:", "Incorrect Y input");

		func_type = SafeInput<int>("Choose function f(x) : 1->sinh(x), 2->sqr(x), 3->exp(x)", "Incorrect Function input");

		switch (func_type)
		{
		case 1:
			func = sinh(x);
			break;
		case 2:
			func = x * x;
			break;
		case 3:
			func = exp(x);
			break;
		default:
			cout << "Invalid X or Y or Func input";
			continue;
		}
		break;
	}

	if (abs(x * y) > 10)
	{
		cout << "Current K formula is: ln(|f(x)| + |y|)" << endl;

		k = log(abs(func) + abs(y));
	}
	else if (abs(x * y) < 10)
	{
		cout << "Current K formula is: e^(f(x) + y)" << endl;
		k = exp(func + y);
	}
	else if (abs(x * y) == 10)
	{
		cout << "Current K formula is: |f(x)|^(1 / 3) + y" << endl;
		k = pow(abs(func), static_cast<double>(1) / 3) + y;
	}

	cout << "X: " << x << "\nY: " << y << "\nK: " << k << endl;

	return 0;
}