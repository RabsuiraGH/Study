#include "Sport.h"
#include <iostream>

using namespace std;

Sport::Sport
(
	string full_name, string sport_type, Sex sex, int age, int height, SportDegree sport_degree
)
{
	full_name_ = full_name;
	sport_section_ = sport_type;
	sex_ = sex;
	age_ = age;
	height_ = height;
	sport_degree_ = sport_degree;
}

Sport::Sport()
{
}

Sport::~Sport()
{
	cout << "Sportsman " << full_name_ << " was deleted!";
}

void Sport::PrintInfo()
{
	cout << "Sportsman: " << full_name_ << endl;
	cout << "Sport type: " << sport_section_ << endl;
	cout << "Sex: ";
	PrintSex();
	cout << "Age: " << age_ << endl;
	cout << "Height: " << height_ << endl;
	cout << "Sport degree: ";
	PrintDegree();
	cout << endl;
}

Sport* GetYoungest(Sport* group, const int& size)
{
	if (size == 0)
		return nullptr;

	Sport* youngest = &group[0];

	for (int i = 0; i < size; i++)
	{
		if (group[i].age_ < youngest->age_)
			youngest = &group[i];
	}

	return youngest;
}

Sport* GetHighest(Sport* group, const int& size)
{
	if (size == 0)
		return nullptr;

	Sport* highest = &group[0];

	for (int i = 0; i < size; i++)
	{
		if (group[i].height_ > highest->height_)
			highest = &group[i];
	}

	return highest;
}

void Sport::PrintSex()
{
	switch (sex_)
	{
	case Male:   cout << "Male" << endl;
	case Female: cout << "Female" << endl;
	}
}
void Sport::PrintDegree()

{
	switch (sport_degree_) {
	case Youth: cout << "Youth" << endl;
	case III:   cout << "III" << endl;
	case II:    cout << "II" << endl;
	case I:     cout << "I" << endl;
	case CMS:   cout << "CMS" << endl;
	}
}