#include <iostream>
using namespace std;


class Rect {

private:
    

public:
static int a;
    int i;
        Rect(int i = 1) {
            this->i = i;
        }
        ~Rect() {
            cout << "d " << i << endl;
        }
        Rect(Rect &r) {
            cout << " adsadsafdafa" << endl;
        }
};

void cop(Rect *r) {
        r->i *= 2;
}


class A {
    void asd() {
        Rect::a = 1;

    }
};

int main() {

    Rect::a = 0;

    return 0;
}