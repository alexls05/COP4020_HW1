class Shape
{
public:
    virtual double getArea() const = 0;
    virtual double getPerimeter() const = 0;
    virtual ~Shape() {};
};

class Polygon : public Shape
{
public:
    virtual double getLongestSegmentLength() const = 0;
    virtual double getSmallestSegmentLength() const = 0;
    virtual ~Polygon() {};
};

class Rectangle : public Polygon
{
public:
    Rectangle() = default;
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual double getLongestSegmentLength() const;
    virtual double getSmallestSegmentLength() const;
    Rectangle(double x, double y);
    double getX() const;
    double getY() const;
    void setX(double x);
    void setY(double y);
    virtual ~Rectangle() {};

private:
    double x;
    double y;
};

class Square : public Rectangle
{
public:
    Square(double x);
    // virtual double getArea() const;
    // virtual double getPerimeter() const;
    // // virtual double getLongestSegmentLength() const;
    // // virtual double getSmallestSegmentLength() const;
};

class Triangle : public Polygon
{
public:
    Triangle(double x, double y, double z);
    virtual double getArea() const;
    virtual double getPerimeter() const;
    virtual double getLongestSegmentLength() const;
    virtual double getSmallestSegmentLength() const;
    double getX() const;
    double getY() const;
    double getZ() const;
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    virtual ~Triangle() {};

private:
    double x;
    double y;
    double z;
};

class Oval : public Shape
{
public:
    Oval() = default;
    Oval(double a, double b);
    virtual double getArea() const;
    virtual double getPerimeter() const;
    double getA() const;
    double getB() const;
    void setA(double a);
    void setB(double b);
    virtual ~Oval() {};
private:
    double a;
    double b;
};

class Circle : public Oval
{
public:
    Circle(double r);
};

// wwyd, fix this code, pros and cons
// no keywords, not much memorization, no syntax