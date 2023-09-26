
#include <iostream>
using namespace std;

class Circle {
    int radius;
    public:
    
    Circle() { radius = 1; }
    Circle(int r) { radius = r; }
    double getArea();
};

double Circle::getArea() {
    return 3.14*radius*radius;
}

int main() {
    Circle donut;
    
    cout << donut.getArea() << endl;
    Circle *p;

    p = &donut;
    cout << p->getArea() << endl;
    cout << (*p).getArea() <<endl;

    Circle pizza(30);
    p = &pizza;
    cout << p->getArea() << endl;
    cout << (*p).getArea() << endl;

    Circle *q = new Circle(5);
    cout << q->getArea() << endl;
    delete q;
}