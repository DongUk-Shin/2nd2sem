#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {

	ifstream is("test.txt");
	if (!is) {
		cout << "파일 오픈 실패";
		exit(1);
	}

	string s;
	while (!is.eof()) {
		getline(is, s); //스트림을 삽입
		cout << s << endl;
	}

}