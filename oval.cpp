#include "shapes.hpp"
#include <cmath>

/*
 * Initializes the oval's two semi-axis lengths.
 * Accepts: The semi-major and semi-minor axis lengths.
 * Returns: Nothing.
 * Can go wrong: Axis lengths are not checked for negativity or non-finite values.
 */
Oval::Oval(double x, double y)
{
    this->a = x;
    this->b = y;
};

/*
 * Computes the oval's area from its semi-axis lengths.
 * Accepts: No arguments; uses the current axis lengths.
 * Returns: The area in square units.
 * Can go wrong: Invalid or non-finite axis values can produce an invalid result.
 */
double Oval::getArea() const
{
    return 3.14159 * a * b;
}

/*
 * Estimates the oval's perimeter with an approximation based on both axes.
 * Accepts: No arguments; uses the current axis lengths.
 * Returns: The estimated perimeter in linear units.
 * Can go wrong: Extreme or non-finite axis values can produce an invalid result.
 */
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
