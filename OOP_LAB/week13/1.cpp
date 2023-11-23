#include <iostream>
#include <string>
using namespace std;

class Circle {
	string name;
	int radius;
public:

	Circle(string n, int r) : name(n), radius(r) {}
	int getRadius() {
		return radius;
	}
	string getName() {
		return name;
	}
};

template <class T>
T larger(T a, T b) {
	return a < b ? b : a;
};


string larger(Circle a, Circle b) {
	return a.getRadius() < b.getRadius() ? b.getName() : a.getName();
};


int main() {
	cout << larger<int>(5, 6) << endl;
	cout << larger<char>('A', 'B') << endl;
	cout << larger<double>(5.6, 3.2) << endl;
	cout << larger<string>("Hello", "Happy") << endl;



	Circle waffle("waffle", 10), pizza("Pizza", 20);
	cout << larger(waffle, pizza) << endl;
	return 0;
}