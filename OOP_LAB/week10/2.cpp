

#include <iostream>
using namespace std;

class Complex {
	double re, im;
public:
	Complex(double r = 0.0, double i = 0.0) {
		re = r;
		im = i;
	}
	void show() {
		cout << re << " + " << im << "i" << endl;
	}
	friend ostream& operator<<(ostream& os, Complex &c);
	
	friend Complex& operator++(Complex& c); //전위
	friend Complex& operator++(Complex& c, int n); //후위
	
	/*
	Complex& operator++() { //전위
		this->re++;
		this->im++;
		return *this;
	}
	Complex& operator++(int n) { //후위
		Complex temp = *this;
		this->re++;
		this->im++;
		return temp;
	}
	*/
};
ostream& operator<<(ostream& os, Complex& c) {
	os << c.re << " + " << c.im << "i ";
	return os;
}

Complex& operator++(Complex& c) { //전위
	c.re++;
	c.im++;
	return c;
}
Complex& operator++(Complex& c, int n) { //후위
	Complex temp = c;
	c.re++;
	c.im++;
	return temp;
}


int main() {
	Complex c1(1, 2), c2;

	cout << c1 << endl;
	cout << c2 << endl;

	c2 = ++c1;
	cout << "\nAfter prefix++: " << endl;
	cout << c1 << c2 << endl;

	c2 = c1++;
	cout << "\nAfter postfix++: " << endl;
	cout << c1 << c2 << endl;


}