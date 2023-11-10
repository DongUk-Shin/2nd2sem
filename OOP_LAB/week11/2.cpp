#include <iostream>
using namespace std;

class A {
	int a;
public:
	A() {
		a = 0;
		cout << "持失切 A: " << a << endl;

	}
	~A() {
		cout << "社瑚切 A" << endl;
	}
};

class B : public A {
	int b;
public:
	B() {
		b = 0;
		cout << "持失切 B: " << b << endl;
	}
	~B() {
		cout << "社瑚切 B" << endl;
	}
};

class C : public B {
	int c;
public:
	C() {
		c = 0;
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