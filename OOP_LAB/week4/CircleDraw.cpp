#include<iostream>
#include<string>
#include<Windows.h>
#include<cstdlib> 
#include<ctime> 
using namespace std;

class Circle {

private:
	int radius;
	int x;
	int y;

public:
	Circle(int x=1, int y=1 , int r=1) : x(x), y(y), radius(r) {
		cout << "Circle with " << radius << " created" << endl;
	}


	void print() {
		cout << "radius: " << radius << endl;
	}
	void setRadius(int r) {
		radius = r;
	}
	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x-radius, y-radius, x+radius, y+radius);
	}
};

int main(void) {

	Circle arrCir[3];
	srand(time(NULL));
	for (Circle &circle : arrCir) {
		int x = rand() % 500 + 1;
		int y = 300 + rand() % 300 + 1;
		int r = rand() % 70 + 30;
		circle = Circle(x, y, r); 
		circle.draw();
	}


	return 0;
}