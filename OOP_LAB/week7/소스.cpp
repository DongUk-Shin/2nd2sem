#include <iostream>
#include <string>
using namespace std;


class  Complex {
private:
	int real;
	int imag;

public:
	Complex(int r = 0, int i = 0): real(r), imag(i) {
		cout << "Constructor is calling: ";
		print();
	}	
	~Complex() {
		cout << "Destructor is calling: ";
		print();
	}
	Complex(Complex& c) {
		cout << "Copy Constructor is calling: ";
		print();
	}
	void print() {
		cout << real << " + " << imag << "i" << endl;
	}
	int getReal() {
		return real;
	}
	int getImag() {
		return imag;
	}
	void setReal(int r) {
		real = r;
	}
	void setImag(int i) {
		imag = i;
	}
};


Complex add(Complex a, Complex b) {
	Complex t;
	cout << "--------------------d-----------" << endl;
	int real = a.getReal() + b.getReal();
	int imag = a.getImag() + b.getImag();

	t.setReal(real);
	t.setImag(imag);
	
	return t;
}

int main() {

	Complex c1(1, 2);
	Complex c2(3, 4); 
	Complex t;

	cout << "-------------------------------" << endl;
	t = add(c1, c2);

	cout << "-------------------------------" << endl;
	t.print();


	return 0;
}