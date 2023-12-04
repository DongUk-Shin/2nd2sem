#include <iostream>
#include <string>
using namespace std;

class Circle {
    public:

    string name;
    int radius;
    Circle(string n, int r) : name(n), radius(r) {}

    friend ostream& operator<<(ostream &os, const Circle &c);

    bool operator<(const Circle &c) const {
        return this->radius < c.radius;
    }
};

template <class T>
T larger(T a, T b) { 
    return a < b ? b : a;
}   

string larger(Circle a, Circle b) {
    return a.radius < b.radius ? b.name : a.name;
};

ostream& operator<<(ostream &os, const Circle &c) {
    os << c.name;
    return os;
}


int main() {
    cout << larger<int>(5, 6) << endl; 
    cout << larger<char>('A', 'B') << endl; 
    cout << larger<float>(5.6, 3.2) << endl;
    cout << larger<string>("Hello", "Happy") << endl;

    Circle waffle("Waffle", 10), pizza("pizza", 30);
    cout << larger<Circle>(waffle, pizza) << endl;
}