#include <iostream>
using namespace std;

class A {
	int a;
public:
	A(int a = 0) {
		a = a;
		cout << "Const A: " << a << endl;

	}
	~A() {
		cout << "Dist A" << endl;
	}
};

class B : public A {
	int b;
public:
	B(int a = 0, int b = 0) : A(a) {
		b = b;
		cout << "Const B: " << b << endl;
	}
	~B() {
		cout << "Dist B" << endl;
	}
};

class C : public B {
	int c;
public:
	C(int a = 0, int b = 0, int c = 0) : B(a, b) {
		c = c;
		cout << "Const C: " << c << endl;
	}
	~C() {
		cout << "Dist C" << endl;
	}
};

int main() {
	C c;
	return 0;
}