#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

void f() throw(int, float, char) {
    int person;
    float num;
    char any = 'a';
    try {
        cout << "input a number of persons:";
        cin >> person;
        cout << "input a number: ";
        cin >> num;
    if (person == 0)
        throw person;
    if (num == 0)
        throw num;
    }
    catch (int e) {
        cout << "error:person "<< e << endl;
    }
    catch (float e) {
        cout << "error:number " << e << endl;
        throw;
    }
    cout << "The end of function" << endl;
}

int main() {
    try {
        f();
    }
    catch (float e) {
        cout << "error:number " << e << endl;
    }
    catch (...) {
        cout << "you entered a negative number" << endl;
    }
    cout << "The end of program" <<endl;
    return 0;
}
