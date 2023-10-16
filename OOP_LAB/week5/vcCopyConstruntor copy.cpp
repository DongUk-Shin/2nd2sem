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
        Circle(const Circle &c) {
            radius = 0;
            cout << "Copy " << radius << endl;
        }
        int getRadius() {
            return radius;
        }
};

int main() { 

    for (int i = 1; i < 4; i++) 
        Circle c(i); 
    
    return 0; 
}