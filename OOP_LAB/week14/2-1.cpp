#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;


bool is_div4(int n) { //b
	return (n % 4 == 0);
}


int main() {
	vector<int> v = { 1, 7, 4, 9, 4, 8, 12, 10, 20 }; //a

	int count = count_if(v.begin(), v.end(), is_div4); //c
	cout << count << endl;


	auto is_div44 = [](int n) -> bool { //e , g
		return (n % 4 == 0);
		};
	int count2 = count_if(v.begin(), v.end(), is_div44);
	cout << count2 << endl;


	int count3 = count_if(v.begin(), v.end(), [](int n) { //f
		return (n % 4 == 0);
		});
	cout << count3 << endl;



}
