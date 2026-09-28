#include <print>
#include <iostream>
#include <vector>
#include "shapes.hpp"
#include <memory>
#include <limits>

void addShape(std::vector<std::shared_ptr<Shape>> *shapes);
void clearScreen();
void printShapes(const std::vector<std::shared_ptr<Shape>> *shapes);
template <typename T>
bool readInput(T& value);

/*
 * Runs the interactive menu until the user chooses to display the shapes.
 * Accepts: No arguments.
 * Returns: Zero after a normal exit or end-of-file.
 * Can go wrong: Shape dimensions are accepted without validation.
 */
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
        if (!readInput(choice))
        {
            if (std::cin.eof())
            {
                return 0;
            }
            continue;
        }
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
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            break;
        }
    }

    return 0;
}

/*
 * Reads a value of type T from standard input.
 * Accepts: A reference to the value to read.
 * Returns: True if the input was valid, false otherwise.
 * Can go wrong: Input is not validated.
 */
template <typename T>
bool readInput(T& value)
{
    if (!(std::cin >> value))
    {
        std::println("Invalid input. Please try again.");
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return false;
    }
    return true;
}

/*
 * Displays the shape menu, reads the selected shape's dimensions, and adds it
 * to the collection.
 * Accepts: A pointer to the collection of shapes to update.
 * Returns: Nothing.
 * Can go wrong: Shape dimensions are not validated.
 */
void addShape(std::vector<std::shared_ptr<Shape>> *shapes)
{
    if (!shapes)
    {
        std::println("Error: Null shape collection.");
        return;
    }

    int shapeChoice;

    std::println("Choose your shape:\n 1 Circle\n 2 Oval\n 3 Rectangle\n 4 Square\n 5 Triangle");
    if (!readInput(shapeChoice))
    {
        return;
    }

    switch (shapeChoice)
    {
    case 1:
    {
        std::println("You chose Circle.");
        std::println("Enter the radius of the circle: ");
        double radius;
        if (!readInput(radius)) return;
        std::shared_ptr<Shape> circle = std::make_shared<Circle>(radius);
        shapes->push_back(circle);
        break;
    }
    case 2:
    {
        std::println("You chose Oval.");
        std::println("Enter the semi-major axis (a) of the oval: ");
        double a;
        if (!readInput(a)) return;
        std::println("Enter the semi-minor axis (b) of the oval: ");
        double b;
        if (!readInput(b)) return;
        std::shared_ptr<Shape> oval = std::make_shared<Oval>(a, b);
        shapes->push_back(oval);
        break;
    }
    case 3:
    {
        std::println("You chose Rectangle.");
        std::println("Enter the length of the rectangle: ");
        double length;
        if (!readInput(length)) return;
        std::println("Enter the width of the rectangle: ");
        double width;
        if (!readInput(width)) return;
        std::shared_ptr<Shape> rectangle = std::make_shared<Rectangle>(length, width);
        shapes->push_back(rectangle);
        break;
    }
    case 4:
    {
        std::println("You chose Square.");
        std::println("Enter the side length of the square: ");
        double side;
        if (!readInput(side)) return;
        std::shared_ptr<Shape> square = std::make_shared<Square>(side);
        shapes->push_back(square);
        break;
    }
    case 5:
    {
        std::println("You chose Triangle.");
        std::println("Enter the length of side x: ");
        double x;
        if (!readInput(x)) return;
        std::println("Enter the length of side y: ");
        double y;
        if (!readInput(y)) return;
        std::println("Enter the length of side z: ");
        double z;
        if (!readInput(z)) return;
        std::shared_ptr<Shape> triangle = std::make_shared<Triangle>(x, y, z);
        shapes->push_back(triangle);
        break;
    }
    default:
        std::println("Invalid choice. Try again.");
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        break;
    }
}

/*
 * Prints an area-plus-perimeter value for each shape.
 * Accepts: A pointer to the collection of shapes to display.
 * Returns: Nothing.
 */
void printShapes(const std::vector<std::shared_ptr<Shape>> *shapes)
{
    if (!shapes)
    {
        std::println("Error: Null shape collection.");
        return;
    }
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

/*
 * Sends terminal escape sequences to clear the screen and move the cursor home.
 * Accepts: No arguments.
 * Returns: Nothing.
 * Can go wrong: Terminals that do not support these escape sequences may not
 * clear or reposition the display.
 */
void clearScreen()
{
    // \033[2J clears the entire screen
    // \033[H moves the cursor to the top-left corner (home position)
    std::cout << "\033[2J\033[H" << std::flush;
}