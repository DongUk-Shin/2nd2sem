#include <iostream>
using namespace std;

class A {
	int a;
public:
	A(int a = 0) {
		a = a;
		cout << "������ A: " << a << endl;

	}
	~A() {
		cout << "�Ҹ��� A" << endl;
	}
};

class B : public A {
	int b;
public:
	B(int a = 0, int b = 0) : A(a) {
		b = b;
		cout << "������ B: " << b << endl;
	}
	~B() {
		cout << "�Ҹ��� B" << endl;
	}
};

class C : public B {
	int c;
public:
	C(int a = 0, int b = 0, int c = 0) : B(a, b) {
		c = c;
		cout << "������ C: " << c << endl;
	}
	~C() {
		cout << "�Ҹ��� C" << endl;
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