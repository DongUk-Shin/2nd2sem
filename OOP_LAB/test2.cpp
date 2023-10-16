#include <iostream>
using namespace std;


class Rect {
public:
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

int main() {
    Rect r;
    Rect q = r;

    return 0;
}