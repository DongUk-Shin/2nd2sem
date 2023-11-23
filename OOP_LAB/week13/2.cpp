#include <iostream>
#include <string>
using namespace std;

template<class T>
class Number {
	T num;
public:

	Number(T n) : num(n) {}
	T getNum();
};

template<class T>
T Number<T>::getNum() {
	return num;
}

int main() {
	Number<int> a(7);
	Number<double> b(7.7);

	cout << "int Number = " << a.getNum() << endl;
	cout << "double Number = " << b.getNum() << endl;
}