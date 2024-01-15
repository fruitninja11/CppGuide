/*

Object slicing occurs when you assign an object of a derived class to an object of a base class, and information specific to the derived class is lost in the process. 
This typically happens when you assign an object by value, and the assignment involves only the base class part of the derived class object.

*/


#include <iostream>
#include <string>

class Shape {
public:
    Shape(const std::string& shapeType) : shapeType(shapeType) {}

    virtual void printType() const {
        std::cout << "Shape Type: " << shapeType << std::endl;
    }

private:
    std::string shapeType;
};

class Circle : public Shape {
public:
    Circle(const std::string& shapeType, double radius) : Shape(shapeType), radius(radius) {}

    void printRadius() const {
        std::cout << "Circle Radius: " << radius << std::endl;
    }

private:
    double radius;
};

int main() {
    Circle circle("Circle", 5.0);
    Shape shape = circle; // Object slicing occurs here

    shape.printType(); // Output: Shape Type: Circle
    //shape.printRadius(); // This would be a compilation error, as shape is of type Shape, not Circle

    return 0;
}



/*
In this example:

There are two classes, Shape and Circle, where Circle is derived from Shape.
The Shape class has a virtual function printType that prints the type of the shape.
The Circle class has an additional member variable radius and a function printRadius to print the radius of the circle.
In the main function:

An instance of the Circle class (circle) is created.
Then, an object of the base class Shape is created and assigned the value of the circle object.

This assignment results in object slicing. The shape object now only contains the Shape part of the circle object, and the information related to the Circle part (e.g., radius) is lost. 
When calling printType on shape, it prints the type as if it were a Shape object, and attempting to call printRadius would result in a compilation error.

Object slicing can lead to unexpected behavior, and it's important to be aware of it when working with polymorphic objects and inheritance. 
To avoid slicing, you can use pointers or references to the base class instead of objects, or use techniques like virtual functions and polymorphism to preserve the derived class information.
*/