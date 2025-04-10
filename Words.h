#ifndef WORDS_H
#define WORDS_H
#include <string>


const std::string numberWords[5][10]
{
		{"������ ", "����������� ", "���������� ", "���������� ","������������ ", "���������� ",
		"������������ ", "���������� ", "������������� ","������������� "},
		{ "", "���� ", "��� ", "��� ", "������ ", "���� ", "����� ", "���� ", "������ ", "������ ",},
		{ "", "", "�������� ", "�������� ", "����� ", "��������� ", "���������� ", "��������� ", "����������� ", "��������� " },
		{ "", "��� ", "������ ", "������ ", "��������� ", "������� ", "�������� ", "������� ", "��������� ", "��������� " },
		{ "","���� ","��� ","��� ","������ ","���� ","����� ","���� ","������ ","������ " },
		
};

const std::string currencyForms[3][10]
{
	{ "������", "�����", "�����", "�����", "�����",
	  "������", "������", "������", "������", "������" },

	  { "����� ", "������ ", "������ ", "������ ", "������ ",
	  "����� ", "����� ", "����� ", "����� ", "����� " },

	{ "��������� ", "������� ", "�������� ", "�������� ", "�������� ",
	  "��������� ", "��������� ", "��������� ", "��������� ", "��������� " },
};


const std::string currencyUnitsPlural[3]{ "������ ","����� ","��������� " };

#endif
