#include<iostream>
#include<string>
#include<Windows.h>
#include<cstdlib> 
#include<ctime> 
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
};
//매우중요
int calArea(Rect &r) {
	int area = r.getHeight() * r.getWidth();
	return area;
}

int main(void) {
	Rect* r;
	r = new Rect();
	r->setWidth(10);
	r->setHeight(20);

	//매우중요
	r->setArea(calArea(*r));

	r->display();
	delete(r);

	return 0;
}
