// Task3_Structure_output.cpp
#include <iostream>

struct address       //Создаем структуру!
{
    std::string city;
    std::string street;
    int house_num;
    int apartment;
    int index;
};
                     // Функция 
void print_screen(std::string* const c, std::string* const s, int* const h, int* const a, int* const i)
{
    std::string str[5] =
    { "Город: ", "Улица: ", "Номер дома: ", "Номер квартиры: ", "Индекс: "};
    std::cout << str[0] << "\t" << *c << std::endl;
    std::cout << str[1] << "\t" << *s << std::endl;
    std::cout << str[2] << *h << std::endl;
    std::cout << str[3] << *a << std::endl;
    std::cout << str[4] << *i << std::endl;
    std::cout << std::endl;
}

int main()
{
    setlocale(LC_ALL, ".1251");
    address addr = { "City", "Street", 0, 0, 0};      //Инициализация структуры

    std::string* p_city = &addr.city;
    std::string* p_str = &addr.street;
    int* p_house_num = &addr.house_num;
    int* p_apartment = &addr.apartment;
    int* p_index = &addr.index;

    addr.city = "Москва";
    addr.street = "Арбат";
    addr.house_num = 12;
    addr.apartment = 8;
    addr.index = 123456;
    print_screen(p_city, p_str, p_house_num, p_apartment, p_index);

    addr.city = "Ижевск";
    addr.street = "Пушкина";
    addr.house_num = 59;
    addr.apartment = 143;
    addr.index = 953769;
    print_screen(p_city, p_str, p_house_num, p_apartment, p_index);
    return 0;
}
// Thanks for the tutorial!