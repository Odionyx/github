// Task2_сounter.cpp :
#include <iostream>
#include <Windows.h>

class Counter
{
private:
    int num;
    int num2;
public:
    //* метод ++
    int inc(void) {
        return num++;
    }
    //* метод --
    int dec(void) {
        return num--;
    }
    //* метод initial point
    int set_count(const int* const num2) {
        return num = *num2;
    }
    //* метод = equal
    void get_count(void) {
        std::cout << num << std::endl;
        return;
    }
    Counter(void) {
        this->num = 1;
    }
    Counter(const int* const num2) {
        this->num = *num2;
    }
    /*
    Обратите внимание на то, что у внешнего кода не должно быть 
    возможности изменить внутреннее значение счётчика напрямую ??
    */
};

void counter()
{
    int num = 0;
    int num2 = 0;
    char ch = ' ';

    std::string str;
    std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
    std::cin >> str;
    int size = str.size();

    Counter count;
    if (size == 2) {
        std::cout << "Введите начальное значение счётчика: ";
        std::cin >> num;
        num = count.set_count(&num);
        Counter::Counter(&num);
    }
    if (size == 3) {
        Counter count = Counter::Counter();
    }
    while (ch != 'х') {
        std::cout << "Введите команду('+', '-', '=' или 'x'): ";
        std::cin >> ch;
        switch (ch)
        {
        case '+': //* увеличьте счётчик на 1
            count.inc();
            break;
        case '-': //* уменьшите счётчик на 1
            count.dec();
            break;
        case '=': //* выведите текущее значение счётчика
            count.get_count();
            break;
        case 'х': //* завершите работу программы
            std::cout << "До свидания!" << std::endl;
            break;
        }
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, ".1251");
    SetConsoleCP(1251);

    counter();
    return 0;
}
// Thanks for the tutorial!