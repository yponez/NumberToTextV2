#include "Numbers.h"
#include <iostream>


//����� ��� ����� �����, ����� ������ ������������� �������� 
int EnterNumber()
{

	std::cout << "������ �����" << std::endl;
	int number;
	while (true)
	{
		std::cin >> number;
		if (std::cin.good() and NumberLength(number) < 10)
		{
			number = (number < 0) ? -number : number;
			return number;
			break;
		}
		else
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			throw "������� ������� �����";
		}
	}
	return number;
}

//��������� ���������� ���� � �����
int NumberLength(int number)
{
	int count = 0;

	if (number == 0) {
		count = 1;
	}

	else
	{
		while (number > 0)
		{
			number /= 10;
			count++;
		}
	}
	return count;
}

//��������� ����� �� ������� 1 � �������� 
bool checkTen(int number)
{
	if (((number % 100) / 10) == 1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string parseTriplet(int number, bool& isTen, const int& rank)
{
	std::string result;
	int length{ NumberLength(number) };
	isTen = checkTen(number);

	for (int i{ length }; i > 0; i--)
	{
		int digit = pow(10, i - 1);
		int tempNumber = number / digit;
		//���� i ����� 1 ������� (i-isTen) ����� ������� i
		int index = (i == 1) ? i-isTen : i;
		// ���� (rank ����� 3, i ����� 1,� ������� �� 1) ������� rank ����� ������� 0
		int thousands = (rank == 3 and i == 1 and !isTen) ? 3 : 0;
		result.append(numberWords[index+thousands][tempNumber]);
			
		number = number % digit;
	}
	return result;
}

std::string parseNumber(int number)
{
	std::string result;
	int length{ NumberLength(number) };
	int rank{ length - 1 };
	int temp{ 0 };
	bool isTen = false;

	for (int i{ length }; i > 0; i--)
	{
		int digit = (pow(10, rank));

		temp += (number / digit) * digit;

		if (rank % 3 == 0) {
			result.append(parseTriplet(temp / digit, isTen, rank));

			if (isTen)
			{
				result.append(currencyUnitsPlural[rank / 3]);
			}
			else
			{
				result.append(currencyForms[rank / 3][number / digit]);
			}

			isTen = false;
			temp = 0;
		}
		number = number % digit;
		rank--;
	}
	return result;
}
