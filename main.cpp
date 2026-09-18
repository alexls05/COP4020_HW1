#include <print>
#include <iostream>
#include <vector>
#include "shapes.hpp"
#include <memory>

void addShape(std::vector<std::shared_ptr<Shape>> *shapes);
void clearScreen();
void printShapes(const std::vector<std::shared_ptr<Shape>> *shapes);

int main(void)
{
    std::vector<std::shared_ptr<Shape>> shapes = {};
    int choice;

    while (true)
    {
        choice = 0;
        clearScreen();
        std::println("Shape Creator!");
        std::println("This program will create shapes and display its area and perimeter.");
        std::println("\n1 Add shape\n2 Done\n");
        std::cin >> choice;
        clearScreen();

        switch (choice)
        {
        case 1:
            addShape(&shapes);
            break;
        case 2:
            std::println("Done.");
            printShapes(&shapes);
            return 0;
        default:
            std::println("Invalid choice. Try again.");
            break;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
        }
    }

    return 0;
}

void addShape(std::vector<std::shared_ptr<Shape>> *shapes)
{
    int shapeChoice;

    std::println("Choose your shape:\n 1 Circle\n 2 Oval\n 3 Rectangle\n 4 Square\n 5 Triangle");
    std::cin >> shapeChoice;

    switch (shapeChoice)
    {
    case 1:
    {
        std::println("You chose Circle.");
        std::println("Enter the radius of the circle: ");
        double radius;
        std::cin >> radius;
        std::shared_ptr<Shape> circle = std::make_shared<Circle>(radius);
        shapes->push_back(circle);
        break;
    }
    case 2:
    {
        std::println("You chose Oval.");
        std::println("Enter the semi-major axis (a) of the oval: ");
        double a;
        std::cin >> a;
        std::println("Enter the semi-minor axis (b) of the oval: ");
        double b;
        std::cin >> b;
        std::shared_ptr<Shape> oval = std::make_shared<Oval>(a, b);
        shapes->push_back(oval);
        break;
    }
    case 3:
    {
        std::println("You chose Rectangle.");
        std::println("Enter the length of the rectangle: ");
        double length;
        std::cin >> length;
        std::println("Enter the width of the rectangle: ");
        double width;
        std::cin >> width;
        std::shared_ptr<Shape> rectangle = std::make_shared<Rectangle>(length, width);
        shapes->push_back(rectangle);
        break;
    }
    case 4:
    {
        std::println("You chose Square.");
        std::println("Enter the side length of the square: ");
        double side;
        std::cin >> side;
        std::shared_ptr<Shape> square = std::make_shared<Square>(side);
        shapes->push_back(square);
        break;
    }
    case 5:
    {
        std::println("You chose Triangle.");
        std::println("Enter the length of side x: ");
        double x;
        std::cin >> x;
        std::println("Enter the length of side y: ");
        double y;
        std::cin >> y;
        std::println("Enter the length of side z: ");
        double z;
        std::cin >> z;
        std::shared_ptr<Shape> triangle = std::make_shared<Triangle>(x, y, z);
        shapes->push_back(triangle);
        break;
    }
    default:
        std::println("Invalid choice. Try again.");
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        break;
    }
}

void printShapes(const std::vector<std::shared_ptr<Shape>> *shapes)
{
    clearScreen();
    std::println("Shapes stats:");
    int count = 0;
    for (auto &shape : *shapes)
    {
        count++;
        double sum = shape->getArea() + shape->getPerimeter();
        std::println("Shape {}: {}", count, sum);
    }
}

void clearScreen()
{
    // \033[2J clears the entire screen
    // \033[H moves the cursor to the top-left corner (home position)
    std::cout << "\033[2J\033[H" << std::flush;
}