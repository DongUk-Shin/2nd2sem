#include <iostream>
using namespace std;

class A {
	int a;
public:
	A() {
		a = 0;
		cout << "������ A: " << a << endl;

	}
	~A() {
		cout << "�Ҹ��� A" << endl;
	}
};

class B : public A {
	int b;
public:
	B() {
		b = 0;
		cout << "������ B: " << b << endl;
	}
	~B() {
		cout << "�Ҹ��� B" << endl;
	}
};

class C : public B {
	int c;
public:
	C() {
		c = 0;
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