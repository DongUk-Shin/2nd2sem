#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {

	ofstream os("dict.txt");
	if (!os) {
		cout << "파일 오픈 실패";
		exit(1);
	}

	ifstream is("test.txt");
	if (!is) {
		cout << "파일 오픈 실패";
		exit(1);
	}

	vector<string> vc;
	string s;
	while (is >> s) {
		vc.push_back(s);
	}

	sort(vc.begin(), vc.end(), [](string s1, string s2) {
		return s1 < s2;
	});

	for (auto s : vc) {
		cout << s << endl;
		os << s << endl;
	}
}