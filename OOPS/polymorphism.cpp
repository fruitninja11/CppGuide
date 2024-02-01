#include <iostream>

// Base class
class Shape {
public:
    // Virtual function to calculate the area (to be overridden in derived classes)
    virtual double calculateArea() {
        return 0.0;
    }

    // Virtual function to display the shape's type
    virtual void display() {
        std::cout << "This is a Shape." << std::endl;
    }
};

// Derived class: Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double calculateArea() override {
        return 3.141592 * radius * radius;
    }

    void display() override {
        std::cout << "This is a Circle." << std::endl;
    }
};

// Derived class: Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double calculateArea() override {
        return width * height;
    }

    void display() override {
        std::cout << "This is a Rectangle." << std::endl;
    }
};

int main() {
    Shape* shapes[2];

    Circle circle(5.0);
    Rectangle rectangle(4.0, 6.0);

    shapes[0] = &circle;
    shapes[1] = &rectangle;

    for (int i = 0; i < 2; i++) {
        shapes[i]->display();
        std::cout << "Area: " << shapes[i]->calculateArea() << std::endl;
    }

    return 0;
}
