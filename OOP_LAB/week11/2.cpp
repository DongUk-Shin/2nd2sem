#include <iostream>
using namespace std;

class A {
	int a;
public:
	A() {
		a = 0;
		cout << "Const A: " << a << endl;

	}
	~A() {
		cout << "Dist A" << endl;
	}
};

class B : public A {
	int b;
public:
	B() {
		b = 0;
		cout << "Const B: " << b << endl;
	}
	~B() {
		cout << "Dist B" << endl;
	}
};

class C : public B {
	int c;
public:
	C() {
		c = 0;
		cout << "Const C: " << c << endl;
	}
	~C() {
		cout << "Dist C" << endl;
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