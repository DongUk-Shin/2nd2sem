
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

auto is_div_by(int divisor) {
	
	return [divisor](int n) {
		return n % divisor == 0;
	};
}

int main() {
	vector<int> v = { 1, 7, 4, 9, 4, 8, 12, 10, 20 }; //a
	int a[] = { 3, 4, 5 };

	for (int i : a) {
		count_if(v.begin(), v.end(), is_div_by(i));
		cout << "nuumbers divisible by: " << i << endl;
	}

}
