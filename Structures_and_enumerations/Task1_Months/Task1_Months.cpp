// Task1_Months.cpp
#include <iostream>

enum class months
{
	unknown,
	january,
	february,
	march,
	april,
	may,
	june,
	july,
	august,
	september,
	october,
	november,
	december,
};

int main(int argc, char** argv)
{
	setlocale(LC_ALL, "ru_RU");
	int m = -1;

	while (m != static_cast <int> (months::unknown)) {
		std::cout << "Введите номер месяца: ";
		std::cin >> m;
		switch (m)
		{
		case (static_cast <int> (months::unknown)):
			std::cout << "До свидания " << std::endl;
			break;
		case (static_cast <int> (months::january)):
			std::cout << "Январь" << std::endl;
			break;
		case (static_cast <int> (months::february)):
			std::cout << "Февраль" << std::endl;
			break;
		case (static_cast <int> (months::march)):
			std::cout << "Март" << std::endl;
			break;
		case (static_cast <int> (months::april)):
			std::cout << "Апрель" << std::endl;
			break;
		case (static_cast <int> (months::may)):
			std::cout << "Май" << std::endl;
			break;
		case (static_cast <int> (months::june)):
			std::cout << "Июнь" << std::endl;
			break;
		case (static_cast <int> (months::july)):
			std::cout << "Июль" << std::endl;
			break;
		case (static_cast <int> (months::august)):
			std::cout << "Август" << std::endl;
			break;
		case (static_cast <int> (months::september)):
			std::cout << "Сентябрь" << std::endl;
			break;
		case (static_cast <int> (months::october)):
			std::cout << "Октябрь" << std::endl;
			break;
		case (static_cast <int> (months::november)):
			std::cout << "Ноябрь" << std::endl;
			break;
		case (static_cast <int> (months::december)):
			std::cout << "Декабрь" << std::endl;
			break;
		default:
			std::cout << "Неправильный номер!" << std::endl;
			break;
		}
	}
	return 0;
}