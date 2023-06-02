// Task1_Months.cpp
#include <iostream>

enum class months
{
	january = 1,
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
	months mo = months::january;
	int m = -1;

	while (m) {
		std::cout << "Введите номер месяца: ";
		std::cin >> m;
		mo = static_cast <months> (m);

		switch (mo)
		{
		case static_cast <months> (0):
			std::cout << "До свидания " << std::endl;
			break;
		case months::january:
			std::cout << "Январь" << std::endl;
			break;
		case months::february:
			std::cout << "Февраль" << std::endl;
			break;
		case months::march:
			std::cout << "Март" << std::endl;
			break;
		case months::april:
			std::cout << "Апрель" << std::endl;
			break;
		case months::may:
			std::cout << "Май" << std::endl;
			break;
		case months::june:
			std::cout << "Июнь" << std::endl;
			break;
		case months::july:
			std::cout << "Июль" << std::endl;
			break;
		case months::august:
			std::cout << "Август" << std::endl;
			break;
		case months::september:
			std::cout << "Сентябрь" << std::endl;
			break;
		case months::october:
			std::cout << "Октябрь" << std::endl;
			break;
		case months::november:
			std::cout << "Ноябрь" << std::endl;
			break;
		case months::december:
			std::cout << "Декабрь" << std::endl;
			break;
		default:
			std::cout << "Неправильный номер!" << std::endl;
			break;
		}
	}
	return 0;
}
// Thanks for the tutorial!