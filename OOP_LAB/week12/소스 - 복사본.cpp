#include<iostream>
#include<string>
using namespace std;


void f() throw(int, float, char) {
	int person;
	float num;
	char any = 'a';
	try {
		cout << "input a number of persons: ";
		cin >> person; cout << "input a number: ";
		cin >> num;
		if (person == 0)
			throw person; 
		if (num == 0) 
			throw num;
		if (num < 0)
			throw any;
	}
	catch (int e) {
		cout << "error:person " << e << endl; 
		throw;
	}
	cout << "Thr end of function " << endl;
}

int main() {
	try {
		f();
	}
	catch (float e) {
		cout << "error:number" << e << endl;
	}
	catch (...) {
		cout << "you entered a negative number" << endl;
	}
	cout << "The end of program" << endl;
}