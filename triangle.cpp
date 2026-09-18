#include "shapes.hpp"
#include <cmath>
#include <algorithm>

Triangle::Triangle(double x, double y, double z)
{
    this->x = x;
    this->y = y;
    this->z = z;
}

double Triangle::getArea() const
{
    double s = getPerimeter() / 2;
    return sqrt(s * (s - this->x) * (s - this->y) * (s - this->z));
}

double Triangle::getPerimeter() const
{
    return this->x + this->y + this->z;
}

double Triangle::getLongestSegmentLength() const
{
    return std::max({this->x, this->y, this->z});
}

double Triangle::getSmallestSegmentLength() const
{
    return std::min({this->x, this->y, this->z});
}

double Triangle::getX() const
{
    return this->x;
}

double Triangle::getY() const
{
    return this->y;
}

double Triangle::getZ() const
{
    return this->z;
}

void Triangle::setX(double x)
{
    this->x = x;
}

void Triangle::setY(double y)
{
    this->y = y;
}

void Triangle::setZ(double z)
{
    this->z = z;
}
