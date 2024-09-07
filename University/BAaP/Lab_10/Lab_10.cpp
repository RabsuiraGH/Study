#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

// n = 2 y = 1.55377
// n = 3 y = 1.71227
// n = 4 y = 1.74876

double sqrt_loop(int, double = 1);
double sqrt_cycle(int);

int main()
{
	int n;

	cout << "Enter integer" << endl;

	cin >> n;

	cout << setprecision(10);

	cout << sqrt_loop(n) << endl;

	cout << sqrt_cycle(n) << endl;
}

double sqrt_loop(int n, double val)
{
	if (n <= 0) return 0;

	if (val >= n) return sqrt(val);

	return sqrt(val + sqrt_loop(n, val + 1));
}

double sqrt_cycle(int n)
{
	double sum = 0;

	for (int i = n; i > 0; i--)
	{
		sum += i;
		sum = sqrt(sum);
	}

	return sum;
}


















//n = SafeInput<int>("Enter positive integer", "Input error, try again");
//template <typename T> T SafeInput(const string&, const string&);
//template <typename T> T SafeInput(const string& inputMessage, const string& errorMessage)
//{
//	T tempValue;
//
//	while (true)
//	{
//		cout << inputMessage << endl;
//
//		if (!(cin >> tempValue) || (cin.peek() != '\n'))
//		{
//			cout << errorMessage << endl << "Restarting process" << endl << endl;
//			cin.clear();
//			cin.ignore(numeric_limits<streamsize>::max(), '\n');
//
//			continue;
//		}
//		return tempValue;
//	}
//}