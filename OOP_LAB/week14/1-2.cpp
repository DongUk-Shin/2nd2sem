#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ofstream os("lined.txt");
	if (!os) {
		cout << "파일 오픈 실패";
		exit(1);
	}

	ifstream is("test.txt");
	if (!is) {
		cout << "파일 오픈 실패";
		exit(1);
	}

	string s;
	int num = 1;
	while (!is.eof()) {
		getline(is, s); //스트림을 삽입
		cout << num << ": " << s << endl;
		os << num << ": " << s << endl;
		num++;
	}

}