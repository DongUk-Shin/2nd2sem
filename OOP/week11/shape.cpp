#include <vector>
#include <iostream>
#include <cmath>
using namespace std;

class Shape {

protected:
    string name;
    double area;
public:
    Shape(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    double getArea() {
        return area;
    }
};

class Circle : public Shape {
public:
    Circle(string name, int radius) : Shape(name) {
        area = radius * radius * 3.14;
    }
};

class Rectangle : public Shape {
public:
    Rectangle(string name, int width, int height) : Shape(name) {
        area = width * height;
    }
};


class Triangle : public Shape {
public:
    Triangle(string name, int side1, int side2, int side3) : Shape(name) {
        double p = (side1 + side2 + side3) / 2;
        area = sqrt(p * (p - side1) * (p - side2) * (p - side3));
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
}