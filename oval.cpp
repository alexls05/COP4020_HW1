#include "shapes.hpp"
#include <cmath>

Oval::Oval(double x, double y)
{
    this->a = x;
    this->b = y;
};

double Oval::getArea() const
{
    return 3.14159 * a * b;
}

double Oval::getPerimeter() const
{
    return 2 * 3.14159 * sqrt((a * a + b * b) / 2);
}

double Oval::getA() const
{
    return a;
}

double Oval::getB() const
{
    return b;
}

void Oval::setA(double a)
{
    this->a = a;
}

void Oval::setB(double b)
{
    this->b = b;
}
