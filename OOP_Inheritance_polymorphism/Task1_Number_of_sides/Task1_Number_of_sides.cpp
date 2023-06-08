// Task1_Number_of_sides.cpp :
#include <iostream>

class Figure
{
private:
    int num_sides;
protected:
    Figure(int i) {
        this->num_sides = i;
    }
public:
    Figure() {
        this->num_sides = 0;
    }
    void print_screen(void) const {
        switch (num_sides) {
        case 0: std::cout << "Фигура: ";
            break;
        case 3: std::cout << "Треугольник: ";
            break;
        case 4: std::cout << "Четырёхугольник: ";
            break;
        }
        std::cout << num_sides << std::endl;
    }
};
class Triangle : public Figure
{
public:
    Triangle() :Figure(3) {};
};
class Quadrate : public Figure
{
public:
    Quadrate() :Figure(4) {};
};

////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU");
    std::cout << "Количество сторон:" << std::endl;

    Figure figure;
    figure.print_screen();

    Triangle triangle;
    triangle.print_screen();

    Quadrate quadrate;
    quadrate.print_screen();

    return 0;
}
//* Thanks for the tutorial!