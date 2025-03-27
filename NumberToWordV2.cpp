#include "Numbers.h"
#include "Words.h"

#include <iostream>
#include <string>



int main()
{
	while (true)
	{
		try
		{
			setlocale(LC_ALL, "Russian");
			int number{ EnterNumber() };

			std::string result = writeText(number);
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


