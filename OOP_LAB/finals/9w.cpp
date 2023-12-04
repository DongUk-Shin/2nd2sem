#include <iostream>
using namespace std;

class ArrayUtility {
    public:
    static void intToDouble(int x[], double y[], int n) {
        for (int i = 0; i < n; i++) {
            y[i] = (double) x[i];
        }
    }
    static void DoubleToInt(double z[], int x[], int n) {
        for (int i = 0; i < n; i++) {
            x[i] = (int) z[i];
        }
    }
};

int main() {
	int x[] = { 1,2,3,4,5 };
	double y[5];
	double z[] = { 9.9, 8.8, 7.7, 6.6, 5.5 };

	ArrayUtility::intToDouble(x, y, 5);
	for (int i = 0; i < 5; i++)
		cout << y[i] << ' ';
	cout << endl;

	ArrayUtility::DoubleToInt(z, x, 5);
	for (int i = 0; i < 5; i++)
		cout << x[i] << ' ';
	cout << endl;

}