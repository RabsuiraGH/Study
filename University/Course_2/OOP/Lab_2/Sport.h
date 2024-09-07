/*
������� ��������� � ������� Sport,
����������� ������� � ������ �� ���������� ���������� ������������.

����� �������� � ���� ��������� ����:
- ��� ������;
- ��� ������;
- ���;
- �������;
- ������ (�������� � ������� ������ (���), I ������, II ������, III ������, ��������� �������);
- ����;

� ��������� ������:
- ����������� �� ���������
- ����������;
- ����� ��������� �������� ��������� ��������;
- �������-����, ��������� ������ � ����� ������� ���������� � �������;
- �������-����, ��������� ������ � ����� ����� (����� ���� �������?) ���������� � �������.
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
