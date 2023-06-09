﻿// Task2_Sides_and_corners.cpp :
#include <iostream>

class Figure
{
private:
    int num_sides;
protected:
    Figure(int num_sides) {
        this->num_sides = num_sides;
    }
public:
    Figure() {
        this->num_sides = 0;
    }
    virtual void print_info() {
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
    }
    void print_info() override {
        std::cout << "Треугольник:" << std::endl;
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
    }
    void print_info() override {
        std::cout << "Четырёхугольник:" << std::endl;
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
        this->C = 90;
    }
    void set_right_tri(const int* const a, const int* const b, const int* const c, int* const A, const int* const B, int* const C) {
        Right_tri(a, b, c, A, B, C);
    }
    void print_info() override {
        std::cout << "Прямоугольный треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};
/* равнобедренный треугольник (стороны a и c равны, углы A и C равны);*/
class Isosceles_tri : public Triangle
{
protected:
    Isosceles_tri( int* const a, const int* const b, int* const c, int* const A, const int* const B, int* const C)
    : Triangle(a, b, c, A, B, C) {
        (*c) = (*a);
        (*A) = (*C);
    }
public:
    Isosceles_tri() {
        this->c = a = c; this->a = c;
        this->A = C = A; this->C = A;
    }
    void set_isosceles_tri(int* const a, const int* const b, int* const c, int* const A, const int* const B, int* const C) {
        Isosceles_tri(a, b, c, A, B, C);
    }
    void print_info() override {
        std::cout << "Равнобедренный треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};
/* равносторонний треугольник (все стороны равны, все углы равны 60);*/
class Equilateral_tri : public Triangle
{
protected:
    Equilateral_tri( int* const a, int* const b, int* const c, int* const A, int* const B, int* const C) 
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
    void print_info() override {
        std::cout << "Равносторонний треугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }
};

/* параллелограмм (стороны a,c и b,d попарно равны, углы A,C и B,D попарно равны);*/
class Parallelogram : public Quadrilateral
{
protected:
    Parallelogram( int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, const int* const C, const int* const D) 
    : Quadrilateral (){
        (*a) = (*c); (*b) = (*d);
        (*A) = (*c); (*B) = (*D);
    }
public:
    Parallelogram() {
        this->a = 10; this->b = 20; this->c = 10; this->d = 20;
        this->A = 70; this->B = 110; this->C = 70; this->D = 110;
    }
    void set_parallelogram(int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, const int* const C, const int* const D) {
        Parallelogram(a, b, c, d, A, B, C, D);
    }
    void print_info() override {
        std::cout << "Параллелограмм:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};
/* прямоугольник (стороны a,c и b,d попарно равны, все углы равны 90);*/
class Rectangle : public Parallelogram
{
protected:
    Rectangle( int* const a, int* const b, const int* const c, const int* const d, int* const A, int* const B, int* const C, int* const D) 
    : Parallelogram( a, b, c, d, A, B, C, D) {
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
    void print_info() override {
        std::cout << "Прямоугольник:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};
/* ромб (все стороны равны, углы A,C и B,D попарно равны);*/
class Rhomb : public Parallelogram
{
protected:
    Rhomb( int* const a, int* const b, int* const c, int* const d, int* const A, int* const B, int* const C, int* const D) 
    : Parallelogram(a, b, c, d, A, B, C, D) {
        (*a) = (*b) = (*c) = (*d);
        (*A) = (*C); (*B) = (*D);
    }
public:
    Rhomb() {
        this->a = 20; this->b = 20; this->c = 20; this->d = 20;
        this->A = 60; this->B = 120; this->C = 60; this->D = 120;
    }
    void set_rhomb(int* const a, int* const b, int* const c, int* const d, int* const A, int* const B, int* const C, int* const D) {
        Rhomb(a, b, c, d, A, B, C, D);
    }
    void print_info() override {
        std::cout << "Ромб:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
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
    void print_info() override {
        std::cout << "Квадрат:" << std::endl;
        std::cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Углы:  A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
};


////////////////////////////////////////////////////////
int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru_RU");

    Figure figure;
    Triangle triangle;

    Figure* f = &triangle;
    f->print_info();

    Right_tri right_tri;
    f = &right_tri;
    f->print_info();

    Isosceles_tri isosceles_tri;
    f = &isosceles_tri;
    f->print_info();

    Equilateral_tri equilateral_tri;
    f = &equilateral_tri;
    f->print_info();

    Quadrilateral quadrilateral;
    f = &quadrilateral;
    f->print_info();

    Parallelogram parallelogram;
    f = &parallelogram;
    f->print_info();

    Rectangle rectangle;
    f = &rectangle;
    f->print_info();

    Rhomb rhomb;
    f = &rhomb;
    f->print_info();

    Quadrate quadrate;
    f = &quadrate;
    f->print_info();

    return 0;
}
/* Thanks for the tutorial! */