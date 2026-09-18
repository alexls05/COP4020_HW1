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


// wwyd, fix this code, pros and cons
// no keywords, not much memorization, no syntax