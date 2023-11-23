#include<iostream>
#include<string>
using namespace std;

class Base{

int value; 
public: 
	Base(int value) : value(value) { } 
	virtual void print() { 
		cout << "Value: " << value << endl; 
	}
};

class Derived : public Base {
	string name; 
public: 
	Derived(int value, string name) : Base(value), name(name) {} 
	void print() { 
		Base::print(); 
		cout << "Name: " << name << endl; 
	}
	string getName() {
		return name;
	}
};

Base* getObject(bool flag) { //UpCasting
	if (flag) 
		return new Derived(1, "Apple"); 
	else 
		return new Base(2);
}

int main() {

	Base* b; 
	Derived* d;
	b = getObject(true); //b = new Derived(1, "Apple"); UpCasting

	b->print(); //Base의 print
	//b: Base 포인터타입 객체는 Derived

	d = (Derived*)b;  //DownCasting 
	d->print();
	
	b = d; 
	b->print();



	Base* b1 = new Base(1);
	Derived* d1;
	d1 = (Derived*)b1;

	//cout << "dd" << d1->getName() << endl; Error
	return 0;
}
