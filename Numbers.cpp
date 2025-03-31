#include "Numbers.h"
#include <iostream>


//нужно дл€ ввода числа, можно ввести отрицательное значение 
int EnterNumber()
{

	std::cout << "¬едите число" << std::endl;
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
			throw "Ќеверно введено число";
		}
	}
	return number;
}

//вычисл€ет количество цифр в числе
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

//провер€ет число на наличие 1 в дес€тках 
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
		//если i равен 1 вернуть (i-isTen) иначе вернуть i
		int index = (i == 1) ? i-isTen : i;
		// если (rank равен 3, i равен 1,в дес€ток не 1) вернуть rank иначе вернуть 0
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
