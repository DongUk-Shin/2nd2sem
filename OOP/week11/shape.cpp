#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Shape {
    string name;
public:
    Shape(string name) : name(name) {}
    string getName() {
        return name;
    }
    virtual double getArea() = 0;
};

class Circle : public Shape {
    int radius;
public:
    Circle(string name, int radius) : Shape(name) {
        this->radius = radius;
    }
    double getArea() {
        return radius * radius * 3.14;
    }
};

class Rectangle : public Shape {
    int width;
    int height;
public:
    Rectangle(string name, int width, int height) : Shape(name) {
        this->width = width;
        this->height = height;
    }
    double getArea() {
        return width * height;
    }
};

class Triangle : public Shape {
    int side1, side2, side3;
public:
    Triangle(string name, int side1, int side2, int side3) : Shape(name) {
        this->side1 = side1;
        this->side2 = side2;
        this->side3 = side3;
    }
    double getArea() {
        double p = (side1 + side2 + side3) / 2;
        return sqrt(p * (p - side1) * (p - side2) * (p - side3));
    }
};

int main() {
    Shape* s[3];
    s[0] = new Circle("Circle", 20);
    s[1] = new Rectangle("Rectangle", 10, 20);
    s[2] = new Triangle("Triangle", 5, 6, 7);

    for (auto& e : s)
        cout << "Name: "<<e->getName() << "\tArea: " << e->getArea() << endl;

    for (auto& e : s)
        delete e;
    cout << endl;
}