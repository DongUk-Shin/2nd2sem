#include<iostream>
#include<string>
#include<Windows.h>
#include<conio.h> 

using namespace std;

class Circle {


public:
	int radius;
	int x;
	int y;

	Circle(int x=1, int y=1, int r=1) {
		x = x;
		y = y;
		radius = r;
	}
	void setRadius(int r) {
		radius = r;
	}
	void draw() {
		HDC hdc = GetWindowDC(GetForegroundWindow());
		Ellipse(hdc, x - radius, y - radius, x + radius, y + radius);
	}
};

int main() {
	Circle circle[10];
	system("cls");

	while (true) {
		for (auto& c : circle) {
			c.x = rand() % 1000 + 1;
			c.y = rand() % 500 + 1;
			c.radius = rand() % 70 + 30;
			c.draw();
		}
		char ch = _getch();
		if (ch == 'q') break;
	}
	
}