#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream is("test.txt");
	if (!is) {
		cout << "���� ���� ����";
		exit(1);
	}

	string s;
	while (!is.eof()) {
		getline(is, s); //��Ʈ���� ����
		cout << s << endl;
	}

}