#include <iostream>
using namespace std;

class A {
	int a;
public:
	A(int a = 0) {
		a = a;
		cout << "持失切 A: " << a << endl;

	}
	~A() {
		cout << "社瑚切 A" << endl;
	}
};

class B : public A {
	int b;
public:
	B(int a = 0, int b = 0) : A(a) {
		b = b;
		cout << "持失切 B: " << b << endl;
	}
	~B() {
		cout << "社瑚切 B" << endl;
	}
};

class C : public B {
	int c;
public:
	C(int a = 0, int b = 0, int c = 0) : B(a, b) {
		c = c;
		cout << "持失切 C: " << c << endl;
	}
	~C() {
		cout << "社瑚切 C" << endl;
	}
};

int main() {
	A a;
	cout << "===================================" << endl;
	B b;
	cout << "===================================" << endl;
	C c;
	cout << "===================================" << endl;

	
}