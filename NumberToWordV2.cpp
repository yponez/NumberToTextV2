#include "Numbers.h"
#include "Words.h"

#include <iostream>
#include <string>



int main()
{
	setlocale(LC_ALL, "Russian");
	while (true)
	{
		try
		{
			
			int number{ EnterNumber() };

			std::string result = parseNumber(number);
			std::cout << result << std::endl;

			std::cout << "Введите 'q' для выхода: ";
			char exit;
			std::cin >> exit;
			if (exit == 'q')
			{
				break;
			}

		}
		catch (const char* error_message)
		{
			std::cout << "ERROR: " << error_message << std::endl;
		}
	}
}


