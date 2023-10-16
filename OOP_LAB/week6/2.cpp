#include<iostream>
#include<string>
#include<Windows.h>
#include<cstdlib> 
#include<ctime> 
#include<algorithm> 
using namespace std;
class Rect {
private:
	int width;
	int height;
	int area;
public:
	Rect(int w = 0, int h = 0, int a = 0): width(w), height(h), area(a) {
	}
	~Rect() {
		cout << "Dying: Width: " << width << ", Height: " << height << endl;
	}

	void display() {
		cout << "width: " << width << ", height: " << height << ", area: " << area << endl;
	}
	void setWidth(int w) {
		width = w;
	}
	void setHeight(int h) {
		height = h;
	}

	void setArea(int a) {
		area = a;
	}

	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	int getArea() {
		return area;
	}
};
int calArea(Rect &r) {
	int area = r.getHeight() * r.getWidth();
	return area;
}

bool compare(Rect *a, Rect *b) {
	return a->getArea() < b->getArea();
}

int main(void) {
	Rect *ar[3];

	for (int i = 0; i < 3; i++) 
		ar[i] = new Rect;

	for (int i = 0; i < 3; i++) {
		ar[i]->setWidth(rand() % 10 + 1);
		ar[i]->setHeight(rand() % 10 + 1);
	}

	for (auto&a : ar) {
		a->setArea(calArea(*a));
	}

	for (auto &a : ar) {
		a->display();
	}
	cout << endl;

	sort(ar, ar + 3, compare);
	for (auto &a : ar) {
		a->display();
	}
	cout << endl;

	for (int i = 0; i < 3; i++) {
		delete ar[i];
	}
	cout << endl;
	return 0;
}
