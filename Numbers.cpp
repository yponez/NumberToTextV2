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
		if (std::cin.good() and NumberLength(number)<10)
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

//проверка на числа от 10 до 19 в миллионах
std::string writeMillions(bool isTen, int number)
{
	std::string result;
	if (isTen)
	{
		result.append(tenMillions);
	}
	else
	{
		result.append(millions[number]);
	}
	return result;
}

//проверка на числа от 10 до 19 в тыс€чах
std::string writeThousands(bool isTen, int number)
{
	std::string result;
	if (isTen)
	{
		result.append(tenThousand);
	}
	else
	{
		result.append(thousands[number]);
	}
	return result;
}

//проверка на числа от 10 до 19 в рубл€х
std::string writeRubles(bool isTen, int number)
{
	std::string result;
	if (isTen)
	{
		result.append(tenRubles);
	}
	else
	{
		result.append(rubles[number]);
	}
	return result;
}

//пишет триплет от числа
std::string writeTriplet(int length, int number, bool& isTen, int externalRank)
{
	std::string result;
	for (int rank{ length }; rank > 0; rank--)
	{
		int digit = pow(10, rank - 1);
		int tempNumber = number / digit;
		if (rank == 2 and tempNumber == 1)//проверка на то что дес€ток равен 1
		{
			isTen = true;

		}
		if (rank == 1 and isTen)//пишет текстом цифры от 10 до 19
		{
			result.append(handleTeens[tempNumber]);
		}
		else
		{
			//externalRank нужен чтобы знать что передан трплет тыс€ч
			if (rank == 1 and externalRank < 7 and externalRank>3)//проверка нанаписание числа в тыс€чах 
			{
				result.append(unitThousands[tempNumber]);
			}
			else
			{
				result.append(units[rank - 1][tempNumber]);
			}
		}
		number = number % digit;
	}
	return result;
}

std::string writeText(int number)
{
	std::string result;
	int length = NumberLength(number);
	int rank = length;
	bool Ten = false;

	for (number; number != 0;) {
		int temp = length;
		int digit = length % 3 == 0 ? pow(10, length - 3) : pow(10, length - length % 3);

		int tempNumber = number / digit;
		int tempLength = NumberLength(tempNumber);

		result.append(writeTriplet(tempLength, tempNumber, Ten, rank));
		if (rank < 10 and rank>6)//проверка чтобы дописать миллионы
		{
			result.append(writeMillions(Ten, tempNumber % 10));
		}
		else if (rank < 7 and rank>3)//проверка чтобы дописать тыс€чи
		{
			result.append(writeThousands(Ten, tempNumber % 10));
		}
		else {//дописать рубли
			result.append(writeRubles(Ten, tempNumber % 10));
		}
		Ten = false;
		number = number % digit;
		rank -= tempLength;
		length = NumberLength(number);
	}
	return result;
}
