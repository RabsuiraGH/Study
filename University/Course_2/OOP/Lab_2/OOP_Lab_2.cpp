/*
Консольное приложение.
Запросить у пользователя количество объектов и его поля (данные хранятся в составе класса).
Организовать проект, в котором объявление класса находится в заголовочном файле *.h,
а реализация (тело метода) – в исполняемом файле, с функцией main().
Создание объектов – с динамическим выделением памяти операцией new.
По окончании работы с массивом объектов освободить занимаемую им память.

Организовать простейшее меню
1 просмотр текущего состояния объектов,
2 создание объектов,
3 выполнение метода индивидуального задания,
4 выход

В шапку программы поместить как комментарий задание по варианту.

19.	Создать программу с классом Sport,
порождающий объекты – данные об участниках спортивных соревнований.

Класс включает в себя следующие поля:
- ФИО игрока;
- вид спорта;
- пол;
- возраст;
- разряд (кандидат в мастера спорта (КМС), I разряд, II разряд, III разряд, юношеские разряды);
- рост;

и следующие методы:
- конструктор по умолчанию
- деструктор;
- метод просмотра текущего состояния объектов;
- функция-друг, выводящая данные о самом молодом спортсмене в команде;
- функция-друг, выводящая данные о самом лёгком (может быть высоком?) спортсмене в команде.
*/

#include <iostream>
#include "Sport.h"

int main()
{
	int choice = -1;
	int max_group_size = 100;
	int current_group_size = 0;
	Sport* group = static_cast<Sport*>(operator new[](max_group_size * sizeof(Sport)));

	while (true)
	{
		cout << "Choose option: " << endl;
		cout << "1 - Show group info " << endl;
		cout << "2 - Add member " << endl;
		cout << "3 - Get youngest sportsman " << endl;
		cout << "4 - Get highest sportsman: " << endl;
		cout << "5 - Exit" << endl;
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			if (current_group_size == 0)
			{
				cout << "No one in group" << endl;
				break;
			}
			cout << "Group info: " << endl;
			for (int i = 0; i < current_group_size; i++)
			{
				cout << "Sportsmen " << i + 1 << ":" << endl;
				group[i].PrintInfo();
			}
			break;
		}
		case 2:
		{
			if (current_group_size >= 100)
			{
				cout << "Group already full!" << endl;
				break;
			}

			string name;
			string sport_section;
			int age;
			int height;
			int sex;
			int degree;

			cout << "Add sportsman number " << current_group_size + 1 << endl;
			cout << "Enter full name: ";
			cin.ignore(256, '\n');
			cin.clear();
			getline(cin, name);

			cout << "Enter sport section: ";
			getline(cin, sport_section);
			cout << "Enter age: ";
			cin >> age;

			cout << "Enter height: ";
			cin >> height;

			cout << "Choose sex:\n1 - Male\n2 - Female" << endl;
			cin >> sex;

			cout << "Choose degree:\n1 - Younth\n2 - III\n3 - II\n4 - I\n5 - CMS" << endl;
			cin >> degree;

			new(&group[current_group_size++]) Sport
			(
				name,
				sport_section,
				static_cast<Sport::Sex>(sex - 1),
				age,
				height,
				static_cast<Sport::SportDegree>(degree - 1)
			);
			break;
		}

		case 3:
		{
			cout << "Youngest sportsman: " << endl;
			auto youngest = GetYoungest(group, current_group_size);
			if (youngest != nullptr)
				youngest->PrintInfo();
			else
				cout << "No one found" << endl;
			break;
		}
		case 4:
		{
			cout << "Highest sportsman: " << endl;
			auto highest = GetHighest(group, current_group_size);
			if (highest != nullptr)
				highest->PrintInfo();
			else
				cout << "No one found" << endl;
			break;
		}

		case 5:
		{
			for (int i = 0; i < current_group_size; i++)
			{
				group[i].~Sport();
			}
			operator delete[](group);
			return 0;
		}
		case 6:
		{
			system("cls");
			break;
		}
		default:
		{
			cout << endl << endl << "Incorrect option!" << endl;
			choice = -1;
			cin.clear();
			cin.ignore(256, '\n');
			continue;
		}
		}
	}
}