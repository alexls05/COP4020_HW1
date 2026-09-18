#include "shapes.hpp"

Rectangle::Rectangle(double x, double y)
{
    this->x = x;
    this->y = y;
}

double Rectangle::getArea() const
{
    return x * y;
}

double Rectangle::getPerimeter() const
{
    return 2 * (x + y);
}

double Rectangle::getLongestSegmentLength() const
{
    return x < y ? y : x;
}

double Rectangle::getSmallestSegmentLength() const
{
    return x < y ? x : y;
}

double Rectangle::getX() const
{
    return x;
}

double Rectangle::getY() const
{
    return y;
}

void Rectangle::setX(double x)
{
    this->x = x;
}

void Rectangle::setY(double y)
{
    this->y = y;
}