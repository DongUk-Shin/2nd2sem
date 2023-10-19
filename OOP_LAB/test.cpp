#include <iostream>
using namespace std;


class Rect {
public:
    int i;
        Rect(int i = 1) {
            cout << " asdsadsad" << endl;
            this->i = i;
        }
        ~Rect() {
            cout << "d " << i << endl;
        }
        Rect(Rect &r) {
            i = r.i;
        }
};

int main() {
    Rect a; //Rect 1개
    Rect b[3]; //Rect 3개

    Rect *c;   // Rect를 가리키는 포인터(객체 생성 x)
    Rect *d[3]; //Rect 가리키는 포인터 3개
    
    Rect *e = new Rect(5); //객체 동적 생성
    Rect *f = new Rect[3]; //객체 동적 3개 생성



    cout << "=================" << endl;
    
    delete[] f;
    delete e;
    cout << "=================" << endl;
    

    return 0;
}