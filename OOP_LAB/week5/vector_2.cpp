#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
    private:
        int radius;

    public:
        Circle(int r): radius(r) {
            cout << "Crying " << radius << endl;
        }
        ~Circle() {
            cout << "Dying " << radius << endl;
        }
        int getRadius();
};

int Circle::getRadius() {
    return radius;
}

int main() { 

    vector<Circle> v;
    
    for (int i = 1; i < 4; i++) { 
        Circle c(i); 
        v.push_back(c); 
        //cout << "==========================" << endl;
    }

    //cout << "==========================" << endl;

    for (auto& c : v) 
        cout << c.getRadius() << endl;
    return 0; 
}