// Task2_Accounts.cpp
#include <iostream>
#include <windows.h> /*system*/// для SetConsoleCP(1251);

struct person        //Создаем структуру!
{
    int num;               // номер счёта (целое число)
    std::string owner;     // здесь будет храниться имя владельца
    double value;          // количество денег на счету (дробное число)
};

// Функция должна принимать экземпляр структуры банковского счёта и новую сумму.
double data_input(double* const value,const double& i) 
{
    return *value = i;
}

int main()
{
    setlocale(LC_ALL, ".1251");
    SetConsoleCP(1251);                   //задаем кодировку для вывода символов на экран

    person pers = { 0, "Name", 0.0};      //Инициализация структуры
    double* ptr_value = &pers.value;
    std::string str[5] = 
    {"номер счёта: ", "имя владельца: ", "баланс: ", "новый баланс: ", "Ваш счёт: "};

    for (int x = 0; x < 4; x++)
    {
        std::cout << "Введите ";
        if (!x) {
            std::cout << str[x];
            std::cin >> pers.num;
        }
        else if (x == 1) {
            std::cout << str[x];
            std::cin >> pers.owner;
        }
        else {
            double i = 0.0;
            std::cout << str[x];
            std::cin >> i;
            data_input(ptr_value, i);              // функция
        }
        // std::cout << std::endl;
    }
    std::cout << str[4] << pers.owner << ", " << pers.num << ", " << pers.value << std::endl;
    return 0;
}
// Thanks for the tutorial!