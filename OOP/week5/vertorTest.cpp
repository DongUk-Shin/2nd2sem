#include <vector>
#include <iostream>
using namespace std;

int main() {

    vector<int> vc;

    for (int i = 0; i < 10; i++) {
        vc.push_back(i);
    }
    for (auto& a : vc) {
        cout << a << " ";
    }
    cout << endl;

    vector<int>::iterator p;
    for (auto p = vc.begin(); p != vc.end(); p++) {
        cout << *p << " ";
    }

    cout << endl;
    while (vc.empty() != true) {
        cout << vc.back() << " ";
        vc.pop_back();
    }
    return 0;
}