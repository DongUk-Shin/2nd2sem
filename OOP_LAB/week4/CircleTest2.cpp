#include<iostream>
#include<string>
#define PI 3.14

using namespace std;

class Circle { 
	private: 
		int radius; 
	public: 
		Circle(int r = 0): radius(r) {
			cout << "Constructor: " << radius << endl;
		} 
		~Circle() {
			cout << "distructor: " << radius << endl;
		}
		Circle(Circle &c) {
			radius = 100;
			cout << "Copy Constructor: " << radius << endl;
		}
		void print() { 
			cout << "radius: " << radius << endl; 
		}
		void setRadius(int r) {
			radius = r;
		}
};

int main() { 
	Circle arrCir[3];
	cout << "1=====================" << endl;
	for (Circle c : arrCir) //Circle &c : arrCir
		c.setRadius(rand() % 100 + 1);
	cout << "2=====================" << endl;
	for (Circle c : arrCir) //Circle &c : arrCir
		c.print();
	cout << "3=====================" << endl;
	return 0;
}
