// Task1_сalculator_of_two_numbers.cpp :
#include <iostream>

class Calculator
{
private:
    double num1;
    double num2;
public:
    Calculator(double num1, double num2) {
        this-> num1 = num1;
        this-> num2 = num2;
    }
    //* метод сложения num1 и num2
    double add(const double* num1, const double* num2) {
        return (*num1) + (*num2);
    }
    //* метод перемножения num1 и num2
    double multiply(const double* num1, const double* num2) {
        return (*num1) * (*num2);
    }
    //* метод вычитания num2 из num1
    double subtract_1_2(const double* num1, const double* num2) {
        return (*num1) - (*num2);
    }
    //* метод вычитания num1 из num2
    double subtract_2_1(const double* num1, const double* num2) {
        return (*num2) - (*num1);
    }
    //* метод деления num1 на num2
    double divide_1_2(const double* num1, const double* num2) {
        return (*num1)/(*num2);
    }
    //* метод деления num2 на num1
    double divide_2_1(const double* num1, const double* num2) {
        return (*num2)/(*num1);
    }
    /*  метод значение поля num1 равное num1, если значение не равно 0.
        Возвращает true, если успешно, в обратном случае false */
    bool set_num1(const double* num1) {
        if (static_cast <bool>(*num1)) {
            this -> num1 = *num1;
            return true;
        } else { return false;}
    }
    /* метод значение поля num2 равное num2, если значение не равно 0.
        Возвращает true, если успешно, в обратном случае false */
    bool set_num2(const double* num2) {
        if (static_cast <bool>(*num2)) {
            this -> num2 = *num2;
            return true;
        } else { return false;}
    }
};

void print_screen(bool b, char ch, double d)
{
    std::cout<<"num"<<(b ? "1" : "2")<<" "<< ch <<" num"<<(b ? "2" : "1")<<" = "<< d << std::endl;
}

void calc( void)
{
    double num1 = 0.0;
    double num2 = 0.0;
    Calculator calc = Calculator(num1, num2);
    while (1) {
        std::cout << "Введите num1: ";
        std::cin >> num1;
        if (calc.set_num1(&num1)) {
            while (1) {
                std::cout << "Введите num2: ";
                std::cin >> num2;
                if (calc.set_num2(&num2)) {
                    print_screen(true,  '+', calc.add           (&num1, &num2));
                    print_screen(true,  '-', calc.subtract_1_2  (&num1, &num2));
                    print_screen(false, '-', calc.subtract_2_1  (&num1, &num2));
                    print_screen(true,  '*', calc.multiply      (&num1, &num2));
                    print_screen(true,  '/', calc.divide_1_2    (&num1, &num2));
                    print_screen(false, '/', calc.divide_2_1    (&num1, &num2));
                }
                else { std::cout << "Неверный ввод!" << std::endl; continue;}
                break;
            }
        } else { std::cout << "Неверный ввод!" << std::endl; continue;}
    }
}

int main(int argc, char** argv)
{
    setlocale(LC_ALL, ".1251");
    calc();
    return 0;
}
// Thanks for the tutorial!