#include<iostream>
#include<string>
#define PI 3.14

using namespace std;

class Circle {
private:
	int radius;
	double area;

public:
	Circle(int n = 10) {
		radius = n;
		cout << "Circle with radius " << radius << " is created" << endl;
	}
	~Circle() {
		cout << "Circle with radius " << radius << " is dying" << endl;
	}
	int getRadius() {
		return radius;
	}
	void calcArea() {
		area = radius * radius * PI;
	}
	void print() {
		cout << "Donut Size: " << radius << endl;
		cout << "Donut Area: " << area << endl;
	}
	void setRadius(int r) {
		radius = r;
	}
};

void update(Circle &c) {
	int r = c.getRadius();
	r = r * 2;
	c.setRadius(r);

}

int main() {
	Circle donut;

	donut.calcArea();
	donut.print();

	update(donut);

	donut.calcArea();
	donut.print();

	return 0;
}