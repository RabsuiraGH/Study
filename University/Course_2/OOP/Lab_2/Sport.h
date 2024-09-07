/*
Создать программу с классом Sport,
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

#pragma once
#include <string>

using namespace std;

class Sport
{
public:
	enum Sex
	{
		Male,
		Female
	};
	enum SportDegree
	{
		Youth,
		III,
		II,
		I,
		CMS
	};

	Sport(string full_name, string sport_section, Sex sex, int age, int height, SportDegree degree);
	Sport();
	~Sport();
	void PrintInfo();
	friend Sport* GetYoungest(Sport* group, const int& size);
	friend Sport* GetHighest(Sport* group, const int& size);

private:
	string full_name_ = "";
	string sport_section_ = "";
	Sex sex_ = Male;
	int age_ = -1;
	int height_ = -1;
	SportDegree sport_degree_ = Youth;

	void PrintSex();
	void PrintDegree();
};
