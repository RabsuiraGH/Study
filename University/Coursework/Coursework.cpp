#include <iostream>
#include <iomanip>
#include <cmath>
#include <chrono>

using namespace std;

double functionV(double&);
double functionP(double&);
double functionD(double&);

int selectionMenu();
void changeFunction(int&);
void changeMethod(int&);

int vegshtain(double&, double&, double&, int&, double (*)(double&));
int bisecting(double&, double&, double&, int&, double (*)(double&));
int parabola(double&, double&, double&, int&, double (*)(double&));

int main()
{
	// массивы указателей на функции для удобства выбора
	double(*functionArray[])(double&) = { functionV, functionP, functionD };
	int (*methodArray[])(double&, double&, double&, int&, double (*)(double&)) = { vegshtain, bisecting, parabola };
	// массивы строк для удобного вывода
	char functionIntervals[3][10] =
	{
		"[4; 7]",
		"[4; 8]",
		"[2; 6]"
	};
	char functionStrings[3][25] =
	{
		"e^x / x^3 - sin(x)^3 - 2",
		"sqrt(x) - cos(x)^2 - 2",
		"ln(x) - 6 * sin(x) ^ 2"
	};
	char methodStrings[3][10] =
	{
		"vegshtain",
		"bisecting",
		"parabola"
	};

	// основные переменные, задающиеся условием
	double leftBorder = 0; // a
	double rightBorder = 0; // b
	int functionStepCount = 0; // m
	double functionStepValue = 0; // h
	double eps; // eps
	int itterationsCount; // it

	// переменные для работы с аргументами
	double* values;
	int index;
	double currentFunctionValue;

	// переменные для выбора границ поиска аргумента
	int x_min_index;
	int x_max_index;

	// переменные для меню выбора
	int menuIndex;
	int functionTypeIndex;
	int methodTypeIndex;
	bool shouldWork = true;

	// TO DELETE
	chrono::steady_clock::time_point start;
	chrono::steady_clock::time_point end;
	double avrgSum = 0;

	pair<int, int>* exes = new pair<int, int>[3];
	int pair_index = 0;
	//

	// первоначальный выбор функции и метода
	changeFunction(functionTypeIndex);
	changeMethod(methodTypeIndex);

	// цикл меню для удобного использования программы
	while (shouldWork)
	{
		// вывод текущей информации
		cout << endl << "Current function : " << functionStrings[functionTypeIndex] << "\nCurrent method : " << methodStrings[methodTypeIndex] << endl << endl;

		// выбор действия
		menuIndex = selectionMenu();

		switch (menuIndex)
		{
		case 1:
			changeFunction(functionTypeIndex);
			break;
		case 2:
			changeMethod(methodTypeIndex);
			break;
		case 3:
#pragma region CALCULATION

			// вывод/ввод требуемой информации
			cout << endl << "Current function: " << functionStrings[functionTypeIndex] << endl;
			cout << "Interval of function: " << functionIntervals[functionTypeIndex] << endl;

			cout << "Enter left border: ";
			cin >> leftBorder;

			cout << "Enter right border: ";
			cin >> rightBorder;

			cout << "Enter step count: ";
			cin >> functionStepCount;

			// подсчет и вывод аргументов и значений функции при них в виде таблицы. Аргумент изменяется с определенным шагом
			values = new double[functionStepCount] {0};

			functionStepValue = abs(leftBorder - rightBorder) / functionStepCount;

			cout << endl << left << setw(7) << "Index:" << setw(10) << "X:" << setw(10) << "f(X):" << endl;

			index = 0;

			for (double x = leftBorder; x <= rightBorder + functionStepValue / 2; x += functionStepValue)
			{
				currentFunctionValue = functionArray[functionTypeIndex](x);

				cout << left << setw(7) << index << " " << setw(10) << x << setw(10) << currentFunctionValue << setw(15);

				// вывод оповещения, что знак значения функции сменился
				if (index != 0 && functionArray[functionTypeIndex](values[index - 1]) * currentFunctionValue < 0)
				{
					cout << "Sign is changed" << endl;
					exes[pair_index++] = make_pair(index, index - 1);
				}
				else
					cout << endl;

				values[index++] = x;
			}

			//выбор минимального и максимального порога аргумента для более точного поиска
			cout << "Choose min x index: ";
			cin >> x_min_index;
			cout << "Choose max x index: ";
			cin >> x_max_index;

			// ввод точности и количества иттераций
			//cout << "Enter difference min difference between x's (near 0.01): ";
			//cin >> eps;
			//cout << "Enter max itterations: ";
			//cin >> itterationsCount;

			eps = 10E-10;
			itterationsCount = 1000;
			for (size_t i = 0; i < 10000; i++)
			{
				//start = std::chrono::high_resolution_clock::now();

				//avrgSum += 1000 - methodArray[methodTypeIndex](values[exes[re].first], values[exes[re].second], eps, itterationsCount, functionArray[functionTypeIndex]);

				methodArray[methodTypeIndex](values[x_min_index], values[x_max_index], eps, itterationsCount, functionArray[functionTypeIndex]);

				//end = std::chrono::high_resolution_clock::now();
				//std::chrono::duration<double> duration = end - start;
				//avrgSum += duration.count();
				//std::cout << "Time: " << duration.count() << " seconds" << std::endl;
			}

			//for (size_t re = 0; re < 3; re++)
			//{
			//	// вызов соответсвующей функции подсчета корня
			//	//avrgSum = 0;
			//
			cout << "AVERAGE " << ": " << avrgSum / 10000. << endl;
			//}

			break;
#pragma endregion
		case 4:
			// очистка консоли
			system("cls");
			break;
		case 5:
			// выход из цикла и завершение программы
			shouldWork = false;
			break;
		}
	}
	return 0;
}
/// <summary>
/// функция смены функции для вычисления
/// </summary>
void changeFunction(int& type)
{
	cout << "Choose function:\n1: e^x / x^3 - sin(x)^3 - 2\n2: sqrt(x) - cos(x)^2 - 2\n3: ln(x) - 5 * sin(x) ^ 2" << endl;
	cin >> type;
	type--;
	if (type < 0 || type > 2) type = 0;
}
/// <summary>
/// функция смены метода вычисления
/// </summary>
void changeMethod(int& method)
{
	cout << "Choose Method:\n1: vegshtain\n2: bisecting\n3: parabola" << endl;
	cin >> method;
	method--;
	if (method < 0 || method > 2) method = 0;
}
/// <summary>
/// функция выбора дальнейших действий
/// </summary>
int selectionMenu()
{
	int action = 0;
	cout << "Choose action:\n1: Change function\n2: Change method\n3: Calculate\n4: Clear console\n5: Exit" << endl;
	cin >> action;
	if (action <= 0 || action >= 6) action = 4;
	return action;
}
/// <summary>
/// изначальная фунцкция для метода Вегстейна
/// </summary>
double functionV(double& x)
{
	return exp(x) / pow(x, 3) - pow(sin(x), 3) - 2; //VEGSHTEIN
}
/// <summary>
/// изначальная фунцкция для метода Параболы
/// </summary>
double functionP(double& x)
{
	return sqrt(x) - pow(cos(x), 2) - 2; //PARABOLA
}
/// <summary>
/// изначальная фунцкция для метода Деления отрезка пополам
/// </summary>
double functionD(double& x)
{
	return log(x) - 5 * pow(sin(x), 2); //DIVISION
}
/// <summary>
/// функция подсчета корня методом Вегстейна
/// </summary>
int vegshtain(double& x_min, double& x_max, double& precision, int& itterationsCount, double (*function)(double&))
{
	double x_0 = x_min;
	double x_1 = x_max;
	double eps = precision;
	int k = itterationsCount;

	double y_0 = function(x_0); // вычисляет базовое значние функции в минимальном аргументе
	double y_1 = function(x_1); // вычисляет базовое значние функции в максимальном аргументе

	double x = 0;
	double shift = 0;

	while (fabs(x_1 - x_0) > eps) // выполняем цикл, сравнивая разницу между аргументами
	{
		shift = y_1 * (x_1 - x_0) / (y_1 - y_0); // подсчет сдвига

		x = x_1 - shift; // сдвигает аргумент для следющего вычисления

		x_0 = x_1; // заменяет первый аргумент на второй
		x_1 = x; // заменяет аргумент на новое потенциальное решение

		y_0 = y_1; // заменяет первое значение функции на второе

		y_1 = function(x); // вычисляет новое второе значение функции с новым аргументом

		// мы сравниваем, насколько близко значение функции к нулю с новыми x
		// и с каждым шагом смотрим, находимся ли мы дальше или ближе к 0,
		// и в зависимости от этого сдвигаем наш x на некоторое значение z

		// выход из функции в случае превышения количества иттераций
		if (--k == 0)
		{
			cout << "Cannot find any solutions. Out of irrotation" << endl;
			return k;
		}
	}
	return k;
	// выводим искомый аргумент с заданной точностью
	//cout << fixed << setprecision(static_cast<int>(ceil(-log10(eps)))) << "Solution: x = " << x << endl;
}
/// <summary>
/// функция подсчета корня методом Деления отрезка пополам
/// </summary>
int bisecting(double& x_min, double& x_max, double& precision, int& itterationsCount, double (*function)(double&))
{
	double x_0 = x_min;
	double x_1 = x_max;
	double eps = precision;
	int k = itterationsCount;

	double y_0 = function(x_0); // вычисляет базовое значние функции в минимальном аргументе
	double y_1 = function(x_1); // вычисляет базовое значние функции в максимальном аргументе

	double x;
	double y;

	while (fabs(x_1 - x_0) > eps) // выполняем цикл, сравнивая разницу между аргументами
	{
		x = (x_0 + x_1) / 2; // вычисдяем аргумент между 1 и 2 аргументами
		y = function(x); // вычисляем значение функции в среднем арументе

		if (y_0 * y < 0) // перемещаем ПРАВУЮ границу к среднему значению, если функция пересекает ось X
		{
			x_1 = x;
			y_1 = y;
		}
		else if (y_1 * y < 0) // перемещаем ЛЕВУЮ границу к среднему значению, если функция пересекает ось X
		{
			x_0 = x;
			y_0 = y;
		}
		else // выходит из функции, если на этих отрезках нет пересечений с осью Х
		{
			cout << "There is no or more than 1 solution between " << x_0 << " and " << x_1 << endl;
			return k;
		}

		// выход из функции в случае превышения количества иттераций
		if (--k == 0)
		{
			cout << "Cannot find any solutions. Out of irrotation" << endl;
			return k;
		}
	}
	return k;
	// выводим искомый аргумент с заданной точностью
	//cout << fixed << setprecision(static_cast<int>(ceil(-log10(eps)))) << "Solution: x = " << (x_0 + x_1) / 2 << endl;
}
/// <summary>
/// функция подсчета корня методом Параболы
/// </summary>
int parabola(double& x_min, double& x_max, double& precision, int& itterationsCount, double (*function)(double&))
{
	double a = x_min;
	double b = x_max;
	double eps = precision;
	int k = itterationsCount;

	double x_0;
	double x_1;
	double c;
	double x_s = 0;
	double x_p = 0;
	double f_a, f_b, f_c, f_x_s;
	double A, B, C;

	do
	{
		c = (a + b) / 2; // вычисляем среднюю точку параболы
		// вычисляем значения функций в точках параболы
		f_a = function(a);
		f_b = function(b);
		f_c = function(c);

		// вычисляем специальные коэффициенты для дальнейших вычислений
		A = (((f_b - f_c) / (b - c)) - ((f_c - f_a) / (c - a))) / (b - a);
		B = ((f_c - f_a) / (c - a)) + A * (a - c);
		C = f_a;

		// вычисляем аргументы при помощи формулы
		x_0 = a - 2 * C / (B + sqrt(B * B - 4 * A * C));
		x_1 = a - 2 * C / (B - sqrt(B * B - 4 * A * C));

		x_p = x_s;

		// выбираем аргументы, находящиеся внутри определенных границ
		if (a <= x_0 && x_0 <= b || a >= x_0 && x_0 >= b)
		{
			x_s = x_0;
		}
		else if (a <= x_1 && x_1 <= b || a >= x_1 && x_1 >= b)
		{
			x_s = x_1;
		}
		else
		{
			cout << "Cannot find any solutions" << endl;
			return k;
		}

		f_x_s = function(x_s);

		// выираем следующую границу, в зависимости от пересечения функцией оси Х
		if (f_a * f_x_s < 0)
		{
			b = x_s;
		}
		else if (f_b * f_x_s < 0)
		{
			a = x_s;
		}

		// выход из функции в случае превышения количества иттераций
		if (--k == 0)
		{
			cout << "Cannot find any solutions. Out of irrotation" << endl;
			return k;
		}
	} while (fabs(x_p - x_s) > eps); // выполняем цикл, сравнивая разницу между аргументами

	return k;
	// выводим искомый аргумент с заданной точностью
	//cout << fixed << setprecision(static_cast<int>(ceil(-log10(eps)))) << "Solution: x = " << x_s << endl;
}

/*#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double functionV(double&);
double functionP(double&);
double functionD(double&);

int selectionMenu();
void changeFunction(int&);
void changeMethod(int&);

void vegshtain(double&, double&, double&, int&, double (*)(double&));
void bisecting(double&, double&, double&, int&, double (*)(double&));
void parabola(double&, double&, double&, int&, double (*)(double&));

int main()
{
	// массивы указателей на функции для удобства выбора
	double(*functionArray[])(double&) = { functionV, functionP, functionD };
	void (*methodArray[])(double&, double&, double&, int&, double (*)(double&)) = { vegshtain, bisecting, parabola };
	// массивы строк для удобного вывода
	char functionIntervals[3][10] =
	{
		"[4; 7]",
		"[4; 8]",
		"[2; 6]"
	};
	char functionStrings[3][25] =
	{
		"e^x / x^3 - sin(x)^3 - 2",
		"sqrt(x) - cos(x)^2 - 2",
		"ln(x) - 5 * sin(x) ^ 2"
	};
	char methodStrings[3][10] =
	{
		"vegshtain",
		"bisecting",
		"parabola"
	};

	// основные переменные, задающиеся условием
	double leftBorder = 0; // a
	double rightBorder = 0; // b
	int functionStepCount = 0; // m
	double functionStepValue = 0; // h
	double eps; // eps
	int itterationsCount; // it

	// переменные для работы с аргументами
	double* values;
	int index;
	double currentFunctionValue;

	// переменные для выбора границ поиска аргумента
	int x_min_index;
	int x_max_index;

	// переменные для меню выбора
	int menuIndex;
	int functionTypeIndex;
	int methodTypeIndex;
	bool shouldWork = true;

	// первоначальный выбор функции и метода
	changeFunction(functionTypeIndex);
	changeMethod(methodTypeIndex);

	// цикл меню для удобного использования программы
	while (shouldWork)
	{
		// вывод текущей информации
		cout << endl << "Current function : " << functionStrings[functionTypeIndex] << "\nCurrent method : " << methodStrings[methodTypeIndex] << endl << endl;

		// выбор действия
		menuIndex = selectionMenu();

		switch (menuIndex)
		{
		case 1:
			changeFunction(functionTypeIndex);
			break;
		case 2:
			changeMethod(methodTypeIndex);
			break;
		case 3:
#pragma region CALCULATION

			// вывод/ввод требуемой информации
			cout << endl << "Current function: " << functionStrings[functionTypeIndex] << endl;
			cout << "Interval of function: " << functionIntervals[functionTypeIndex] << endl;

			cout << "Enter left border: ";
			cin >> leftBorder;

			cout << "Enter right border: ";
			cin >> rightBorder;

			cout << "Enter step count: ";
			cin >> functionStepCount;

			// подсчет и вывод аргументов и значений функции при них в виде таблицы. Аргумент изменяется с определенным шагом
			values = new double[functionStepCount] {0};

			functionStepValue = abs(leftBorder - rightBorder) / functionStepCount;

			cout << endl << left << setw(7) << "Index:" << setw(10) << "X:" << setw(10) << "f(X):" << endl;

			index = 0;

			for (double x = leftBorder; x <= rightBorder + functionStepValue / 2; x += functionStepValue)
			{
				currentFunctionValue = functionArray[functionTypeIndex](x);

				cout << left << setw(7) << index << " " << setw(10) << x << setw(10) << currentFunctionValue << setw(15);

				// вывод оповещения, что знак значения функции сменился
				if (index != 0 && functionArray[functionTypeIndex](values[index - 1]) * currentFunctionValue < 0)
					cout << "Sign is changed" << endl;
				else
					cout << endl;

				values[index++] = x;
			}

			// выбор минимального и максимального порога аргумента для более точного поиска
			cout << "Choose min x index: ";
			cin >> x_min_index;
			cout << "Choose max x index: ";
			cin >> x_max_index;

			// ввод точности и количества иттераций
			cout << "Enter precision (near 0.01): ";
			cin >> eps;
			cout << "Enter max itterations: ";
			cin >> itterationsCount;

			// вызов соответсвующей функции подсчета корня
			methodArray[methodTypeIndex](values[x_min_index], values[x_max_index], eps, itterationsCount, functionArray[functionTypeIndex]);

			break;
#pragma endregion
		case 4:
			// очистка консоли
			system("cls");
			break;
		case 5:
			// выход из цикла и завершение программы
			shouldWork = false;
			break;
		}
	}
	return 0;
}
/// <summary>
/// функция смены функции для вычисления
/// </summary>
void changeFunction(int& type)
{
	cout << "Choose function:\n1: e^x / x^3 - sin(x)^3 - 2\n2: sqrt(x) - cos(x)^2 - 2\n3: ln(x) - 5 * sin(x) ^ 2" << endl;
	cin >> type;
	type--;
	if (type < 0 || type > 2) type = 0;
}
/// <summary>
/// функция смены метода вычисления
/// </summary>
void changeMethod(int& method)
{
	cout << "Choose Method:\n1: vegshtain\n2: bisecting\n3: parabola" << endl;
	cin >> method;
	method--;
	if (method < 0 || method > 2) method = 0;
}
/// <summary>
/// функция выбора дальнейших действий
/// </summary>
int selectionMenu()
{
	int action = 0;
	cout << "Choose action:\n1: Change function\n2: Change method\n3: Calculate\n4: Clear console\n5: Exit" << endl;
	cin >> action;
	if (action <= 0 || action >= 6) action = 4;
	return action;
}
/// <summary>
/// изначальная фунцкция для метода Вегстейна
/// </summary>
double functionV(double& x)
{
	return exp(x) / pow(x, 3) - pow(sin(x), 3) - 2; //VEGSHTEIN
}
/// <summary>
/// изначальная фунцкция для метода Параболы
/// </summary>
double functionP(double& x)
{
	return sqrt(x) - pow(cos(x), 2) - 2; //PARABOLA
}
/// <summary>
/// изначальная фунцкция для метода Деления отрезка пополам
/// </summary>
double functionD(double& x)
{
	return log(x) - 5 * pow(sin(x), 2); //DIVISION
}
/// <summary>
/// функция подсчета корня методом Вегстейна
/// </summary>
void vegshtain(double& x_min, double& x_max, double& precision, int& itterationsCount, double (*function)(double&))
{
	double x_0 = x_min;
	double x_1 = x_max;
	double eps = precision;
	int k = itterationsCount;

	double y_0 = function(x_0); // вычисляет базовое значние функции в минимальном аргументе
	double y_1 = function(x_1); // вычисляет базовое значние функции в максимальном аргументе

	double x = 0;

	while (fabs(x_1 - x_0) > eps) // выполняем цикл, сравнивая разницу между аргументами
	{
		x = x_1 - (y_1 * (x_1 - x_0) / (y_1 - y_0)); // сдвигает аргумент для следющего вычисления

		x_0 = x_1; // заменяет первый аргумент на второй
		x_1 = x; // заменяет аргумент на новое потенциальное решение

		y_0 = y_1; // заменяет первое значение функции на второе

		y_1 = function(x); // вычисляет новое второе значение функции с новым аргументом

		// мы сравниваем, насколько близко значение функции к нулю с новыми x
		// и с каждым шагом смотрим, находимся ли мы дальше или ближе к 0,
		// и в зависимости от этого сдвигаем наш x на некоторое значение z

		// выход из функции в случае превышения количества иттераций
		if (--k == 0)
		{
			cout << "Cannot find any solutions. Out of irrotation" << endl;
			return;
		}
	}
	// выводим искомый аргумент с заданной точностью
	cout << fixed << setprecision(static_cast<int>(ceil(-log10(eps)))) << "Solution: x = " << x << endl;
}
/// <summary>
/// функция подсчета корня методом Деления отрезка пополам
/// </summary>
void bisecting(double& x_min, double& x_max, double& precision, int& itterationsCount, double (*function)(double&))
{
	double x_0 = x_min;
	double x_1 = x_max;
	double eps = precision;
	int k = itterationsCount;

	double y_0 = function(x_0); // вычисляет базовое значние функции в минимальном аргументе
	double y_1 = function(x_1); // вычисляет базовое значние функции в максимальном аргументе

	double x;
	double y;

	while (fabs(x_1 - x_0) > eps) // выполняем цикл, сравнивая разницу между аргументами
	{
		x = (x_0 + x_1) / 2; // вычисдяем аргумент между 1 и 2 аргументами
		y = function(x); // вычисляем значение функции в среднем арументе

		if (y_0 * y < 0) // перемещаем ПРАВУЮ границу к среднему значению, если функция пересекает ось X
		{
			x_1 = x;
			y_1 = y;
		}
		else if (y_1 * y < 0) // перемещаем ЛЕВУЮ границу к среднему значению, если функция пересекает ось X
		{
			x_0 = x;
			y_0 = y;
		}
		else // выходит из функции, если на этих отрезках нет пересечений с осью Х
		{
			cout << "There is no or more than 1 solution between " << x_0 << " and " << x_1 << endl;
			return;
		}

		// выход из функции в случае превышения количества иттераций
		if (--k == 0)
		{
			cout << "Cannot find any solutions. Out of irrotation" << endl;
			return;
		}
	}

	// выводим искомый аргумент с заданной точностью
	cout << fixed << setprecision(static_cast<int>(ceil(-log10(eps)))) << "Solution: x = " << (x_0 + x_1) / 2 << endl;
}
/// <summary>
/// функция подсчета корня методом Параболы
/// </summary>
void parabola(double& x_min, double& x_max, double& precision, int& itterationsCount, double (*function)(double&))
{
	double a = x_min;
	double b = x_max;
	double eps = precision;
	int k = itterationsCount;

	double x_0;
	double x_1;
	double c;
	double x_s = 0;
	double x_p = 0;
	double f_a, f_b, f_c, f_x_s;
	double A, B, C;

	do
	{
		c = (a + b) / 2; // вычисляем среднюю точку параболы
		// вычисляем значения функций в точках параболы
		f_a = function(a);
		f_b = function(b);
		f_c = function(c);

		// вычисляем специальные коэффициенты для дальнейших вычислений
		A = (((f_b - f_c) / (b - c)) - ((f_c - f_a) / (c - a))) / (b - a);
		B = ((f_c - f_a) / (c - a)) + A * (a - c);
		C = f_a;

		// вычисляем аргументы при помощи формулы
		x_0 = a - 2 * C / (B + sqrt(B * B - 4 * A * C));
		x_1 = a - 2 * C / (B - sqrt(B * B - 4 * A * C));

		x_p = x_s;

		// выбираем аргументы, находящиеся внутри определенных границ
		if (a <= x_0 && x_0 <= b || a >= x_0 && x_0 >= b)
		{
			x_s = x_0;
		}
		else if (a <= x_1 && x_1 <= b || a >= x_1 && x_1 >= b)
		{
			x_s = x_1;
		}
		else
		{
			cout << "Cannot find any solutions" << endl;
			return;
		}

		f_x_s = function(x_s);

		// выираем следующую границу, в зависимости от пересечения функцией оси Х
		if (f_a * f_x_s < 0)
		{
			b = x_s;
		}
		else if (f_b * f_x_s < 0)
		{
			a = x_s;
		}

		// выход из функции в случае превышения количества иттераций
		if (--k == 0)
		{
			cout << "Cannot find any solutions. Out of irrotation" << endl;
			return;
		}
	} while (fabs(x_p - x_s) > eps); // выполняем цикл, сравнивая разницу между аргументами

	// выводим искомый аргумент с заданной точностью
	cout << fixed << setprecision(static_cast<int>(ceil(-log10(eps)))) << "Solution: x = " << x_s << endl;
}*/