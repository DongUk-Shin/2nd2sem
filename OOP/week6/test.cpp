
#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        void setPerson() {
            cout << "Enter a name: ";
            cin >> name;
            
            cout << "Enter a age: ";
            cin >> age;
        }
};

class Family {
    private:
        string surname;
        int num;

    public:
        Family(string n, int num): surname(n), num(num) { }
        void setMembers() {
            Person p[10];

            for (int i = 0; i < num; i++) {
                p[i].setPerson();
            }
        }
};

void show() {

}

int main() {
    Family* f;
    string surname;
    int num;
    cout << "Enter your family name: ";
    cin >> surname;

    cout << "Enter How many people?: ";
    cin >> num;

    f = new Family(surname, num);
    f->setMembers(); 
    show(); 
    delete f;
}