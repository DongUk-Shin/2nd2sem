#include <iostream>
#include <vector>
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
	void f() {
		cout << " f() in A" << endl;
	}
	virtual void v() {
		cout << " v() in A" << endl;
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
	void f() {
		cout << " f() in B" << endl;
	}
	void v() {
		cout << " v() in B" << endl;
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
	void f() {
		cout << " f() in C" << endl;
	}
	void v() {
		cout << " v() in C" << endl;
	}

};

int main() {

	A* a = new A;
	B* b = new B;
	C* c = new C;
	vector<A*> vc;
	vc.push_back(a);
	vc.push_back(b);
	vc.push_back(c);

	for (auto& a : vc) {
		a->f();
		a->v();
	}
}
	/*
	A a;
	B b;
	C c;
	A* pa;
	C* pc;
	cout << "===================================" << endl;
	pa = &b;
	pa->f(); // f() in A
	pa->v(); // v() in B

	cout << "===================================" << endl;

	pc = new C();
	pa = pc;
	pa->f(); // f() in A
	pa->v(); // v() in C

	cout << "===================================" << endl;
	delete pa;
	cout << "===================================" << endl;
	*/
