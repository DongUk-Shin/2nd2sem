#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(string &p, string &q) {
    return p < q;
}


int main() {
    vector<string> vc;
    vc.push_back("MILK");
    vc.push_back("BUTTER");
    vc.push_back("BREAD");
    vc.push_back("SALAD");
    vc.push_back("CUCUMBER");

    for (auto &a : vc)
        cout << a << " ";

    cout << endl;

    vector<string>::iterator p;
    for (p = vc.begin(); p != vc.end(); p++)
        cout << *p << " ";

    cout << endl;
    sort(vc.begin(), vc.end(), compare);
    for (auto &a : vc)
        cout << a << " ";

    vc.pop_back();
    for (auto &a : vc)
        cout << a << " ";
    cout << endl;
    return 0;
}