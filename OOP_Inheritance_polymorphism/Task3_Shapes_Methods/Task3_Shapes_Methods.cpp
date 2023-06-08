// Task3_Shapes_Methods.cpp :// Task2_Sides_and_corners.cpp :
#include <iostream>

class Figure
{
protected:
    bool bl;
    int num_sides;
protected:
    Figure(int num_sides) {
        this->bl = true;
        this->num_sides = num_sides;
    }
public:
    Figure() {
        this->bl = true;
        this->num_sides = 0;
    }
    virtual void print_name() {
        std::cout << "Фигура:" << std::endl;
    }
    virtual void check_data() {
    }
    void check_result_print() {
        std::cout << ( bl ? "Правильная" : "Неправильная") << std::endl;
    }
    virtual void print_info() {
        std::cout << "Количество сторон: "<< num_sides << std::endl;
        std::cout << std::endl;
    }
};
/* треугольник */
class Triangle : public Figure
{
protected:
    int a, b, c, A, B, C;
protected:
    Triangle(const int* const a, const int* const b, const int* const c, const int* const A, const int* const B, const int* const C)
        :Figure(3) {
        this->a = (*a); this->b = (*b); this->c = (*c);
        this->A = (*A); this->B = (*B); this->C = (*C);
    }
public:
    Triangle() {
        this->a = 10; this->b = 20; this->c = 30;
        this->A = 50; this->B = 60; this->C = 70;
        num_sides = 3;
    }
    virtual void check_data() override {
        if (!((bl && (num_sides == 3)) && (A+B+C)==180)) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Треугольник:" << std::endl;
    }
    void print_info() override {
        std::cout << "Количество сторон: " << num_sides << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};
/* четырёхугольник */
class Quadrilateral : public Figure
{
protected:
    int a, b, c, d, A, B, C, D;
protected:
    Quadrilateral(const int* const a, const int* const b, const int* const c, const int* const d, const int* const A, const int* const B, const int* const C, const int* const D)
        :Figure(4) {
        this->a = (*a); this->b = (*b); this->c = (*c); this->d = (*d);
        this->A = (*A); this->B = (*B); this->C = (*C); this->D = (*D);
    }
public:
    Quadrilateral() {
        this->a = 10; this->b = 20; this->c = 30; this->d = 40;
        this->A = 50; this->B = 60; this->C = 70; this->D = 80;
        num_sides = 4;
    }
    virtual void check_data() override {
        if (!(bl && (num_sides == 4) && ((A + B + C + D) == 360))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Четырёхугольник:" << std::endl;
    }
    void print_info() override {
        std::cout << "Количество сторон: " << num_sides << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};
///////////////////////////////
/* прямоугольный треугольник (угол C всегда равен 90);*/
class Right_tri : public Triangle
{
protected:
    Right_tri(const int* const a, const int* const b, const int* const c, int* const A, const int* const B, int* const C)
        : Triangle(a, b, c, A, B, C) {
        (*C) = 90;
    }
public:
    Right_tri() {
        this->a = 10; this->b = 20; this->c = 30;
        this->A = 50; this->B = 40; this->C = 90;
    }
    void set_right_tri(const int* const a, const int* const b, const int* const c, int* const A, const int* const B, int* const C) {
        Right_tri(a, b, c, A, B, C);
    }
    void check_data() override {
        if (!((bl&&(num_sides==3))&&((A+B+C)==180)&&(C==90))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Прямоугольный треугольник:" << std::endl;
    }
};
/* равнобедренный треугольник (стороны a и c равны, углы A и C равны);*/
class Isosceles_tri : public Triangle
{
protected:
    Isosceles_tri(int* const a, const int* const b, int* const c, int* const A, const int* const B, int* const C)
        : Triangle(a, b, c, A, B, C) {
        (*c) = (*a);
        (*A) = (*C);
    }
public:
    Isosceles_tri() {
        this->a = 10; this->b = 20; this->c = 10;
        this->A = 50; this->B = 60; this->C = 50;
    }
    void set_isosceles_tri(int* const a, const int* const b, int* const c, int* const A, const int* const B, int* const C) {
        Isosceles_tri(a, b, c, A, B, C);
    }
    void check_data() override {
        if (!(bl && (((a == c) && (A == C)) && ((A + B + C) == 180)))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Равнобедренный треугольник:" << std::endl;
    }
};
/* равносторонний треугольник (все стороны равны, все углы равны 60);*/
class Equilateral_tri : public Triangle
{
protected:
    Equilateral_tri(int* const a, int* const b, int* const c, int* const A, int* const B, int* const C)
        : Triangle(a, b, c, A, B, C) {
        (*a) = (*b) = (*c);
        (*A) = (*B) = (*C) = 60;
    }
public:
    Equilateral_tri() {
        this->a = 30; this->b = 30; this->c = 30;
        this->A = 60; this->B = 60; this->C = 60;
    }
    void set_equilateral_tri(int* const a, int* const b, int* const c, int* const A, int* const B, int* const C) {
        Equilateral_tri(a, b, c, A, B, C);
    }
    void check_data() override {
        if (!(bl && (((A + B + C) == 180)) && ((a == b)&& (b == c)) && (B==60) && (C==60))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Равносторонний треугольник:" << std::endl;
    }
};

/* параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);*/
class Parallelogram : public Quadrilateral
{
protected:
    Parallelogram(int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, const int* const C, const int* const D)
        : Quadrilateral() {
        (*a) = (*c); (*b) = (*d);
        (*A) = (*c); (*B) = (*D);
    }
public:
    Parallelogram() {
        this->a = 20; this->b = 30; this->c = 20; this->d = 30;
        this->A = 30; this->B = 40; this->C = 30; this->D = 40;
    }
    void set_parallelogram(int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, const int* const C, const int* const D) {
        Parallelogram(a, b, c, d, A, B, C, D);
    }
    void check_data() override {
        if (!((bl && (a==c) && (b == d) && (A == C) && (B == D)) && ((num_sides == 4) && ((A + B + C + D) == 360)))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Параллелограмм:" << std::endl;
    }
};
/* прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);*/
class Rectangle : public Parallelogram
{
protected:
    Rectangle(int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, int* const C, int* const D)
        : Parallelogram(a, b, c, d, A, B, C, D) {
        (*A) = (*B) = (*C) = (*D) = 90;
    }
public:
    Rectangle() {
        this->a = 10; this->b = 20; this->c = 10; this->d = 20;
        this->A = 90; this->B = 90; this->C = 90; this->D = 90;
    }
    void set_rectangle(int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, int* const C, int* const D) {
        Rectangle(a, b, c, d, A, B, C, D);
    }
    void check_data() override {
        if (!((bl && ((A == 90) && (C == 90)) && ((((a==c)&&(b==d))) && (num_sides == 4) && ((A + B + C + D) == 360))))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Прямоугольник:" << std::endl;
    }
};
/* ромб (все стороны равны, углы A,C и B,D попарно равны);*/
class Rhomb : public Parallelogram
{
protected:
    Rhomb(int* const a, int* const b, int* const c, int* const d, int* const A, int* const B, int* const C, int* const D)
        : Parallelogram(a, b, c, d, A, B, C, D) {
        (*a) = (*b) = (*c) = (*d);
        (*A) = (*C); (*B) = (*D);
    }
public:
    Rhomb() {
        this->a = 30; this->b = 30; this->c = 30; this->d = 30;
        this->A = 30; this->B = 40; this->C = 30; this->D = 40;
    }
    void set_rhomb(int* const a, int* const b, int* const c, int* const d, int* const A, int* const B, int* const C, int* const D) {
        Rhomb(a, b, c, d, A, B, C, D);
    }
    void check_data() override {
        if (!(bl && ((num_sides == 4) && ((A + B + C + D) == 360) && ((A == C) && (B == D) && ((a==c)&&(b==d)))))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Ромб:" << std::endl;
    }
};
/* квадрат (все стороны равны, все углы равны 90);*/
class Quadrate : public Rectangle
{
public:
    Quadrate(int* const a, int* const b, int* const c, int* const d, int* const A, int* const B, int* const C, int* const D)
        : Rectangle(a, b, c, d, A, B, C, D) {
        (*a) = (*b) = (*c) = (*d);
    }
public:
    Quadrate() {
        this->a = 20; this->b = 20; this->c = 20; this->d = 20;
        this->A = 90; this->B = 90; this->C = 90; this->D = 90;
    }
    void set_quadrate(int* const a, int* const b, int* const c, int* const d, int* const A, int* const B, int* const C, int* const D) {
        Quadrate(a, b, c, d, A, B, C, D);
    }
    void check_data() override {
        if (!(bl && ((num_sides == 4) && ((A + B + C + D) == 360) && ((A == 90) && (C == 90) && ((a == c) && (a == d)))))) {
            this->bl = false;
        }
    }
    void print_name() override {
        std::cout << "Квадрат:" << std::endl;
    }
};


////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU");
    Figure figure;
    Figure* f = &figure;

    Triangle triangle;                //triangle;
    Triangle* t = &triangle;
    Right_tri right_tri;
    Isosceles_tri isosceles_tri;
    Equilateral_tri equilateral_tri;

    Quadrilateral quadrilateral;      //quadrilateral;
    Quadrilateral* q = &quadrilateral;
    Parallelogram parallelogram;
    Parallelogram* p = &parallelogram;

    Rectangle rectangle;
    Rectangle* r = &rectangle;
    Rhomb rhomb;
    Quadrate quadrate;
    
    for (int x = 0; x < 10; x++) {
        f->print_name();
        f->check_data();
        f->check_result_print();
        f->print_info();
        switch (x)
        {
        case 0: f = &triangle;          break;
        case 1: f = &right_tri;         break;
        case 2: f = &isosceles_tri;     break;
        case 3: f = &equilateral_tri;   break;

        case 4: f = &quadrilateral;     break;
        case 5: f = &parallelogram;     break;
        case 6: f = &rectangle;         break;
        case 7: f = &rhomb;             break;
        case 8: f = &quadrate;          break;
        }
    }
    f = nullptr;
    t = nullptr;
    q = nullptr;
    p = nullptr;
    r = nullptr;
    return 0;
}
/* Thanks for the tutorial! */