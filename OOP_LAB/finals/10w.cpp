#include <iostream>
using namespace std;

class Circle {
    int radius;
public:
    Circle(int r = 0):radius(r) {}
    
    Circle& operator+(Circle &c) {
        Circle temp;
        temp = this->radius + c.radius;
        return temp;
    }

    friend ostream& operator<<(ostream &os, const Circle &c) {
        os << "Radius: " << c.radius;
        return os;
    }
};

int main() {
    Circle c0(0);
    Circle c1(1);
    Circle c2(2);

    c0 = c1 + c2;

    cout << c0;
}