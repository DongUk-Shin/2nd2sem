#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ofstream os("lined.txt");
	if (!os) {
		cout << "���� ���� ����";
		exit(1);
	}

	ifstream is("test.txt");
	if (!is) {
		cout << "���� ���� ����";
		exit(1);
	}

	string s;
	int num = 1;
	while (!is.eof()) {
		getline(is, s); //��Ʈ���� ����
		cout << num << ": " << s << endl;
		os << num << ": " << s << endl;
		num++;
	}

}