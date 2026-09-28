#include "shapes.hpp"

/*
 * Initializes both oval axes to the circle's radius.
 * Accepts: The circle's radius.
 * Returns: Nothing.
 * Can go wrong: The radius is not checked for negativity or non-finite values.
 */
Circle::Circle(double r)
{
    setA(r);
    setB(r);
};

