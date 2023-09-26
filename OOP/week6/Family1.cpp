
#include <iostream>
using namespace std;

class Person {
    private:
        string name;
        int age;

    public:
        void setName(string n) {
            name = n;
        }
        void setAge(int a) {
            age = a;
        }
        string getName() {
            return name;
        }
        int getAge() {
            return age;
        }
};

class Family {
    private:
        Person* p;
        string surname;
        int num;

    public:
        Family(string n, int num): surname(n), num(num) { 
            p = new Person[num];
        }
        ~Family() {
            delete p;
        }

        void setMembers() {
            int age;
            string name;
            for (int i = 0; i < num; i++) {
                cout << "Input Name: ";
                cin >> name;
                p[i].setName(name);

                cout << "Input Age: ";
                cin >> age;
                p[i].setAge(age);
            }
        }

        int getNum() {
            return num;
        }

        string getSurname() {
            return surname;
        }

        Person* getPeople() {
            return p;
        }
};

void show(Family* f) {
    int num = f->getNum();
    string name = f->getSurname();
    Person *p = f->getPeople();

    cout << "Family Name: " << name << endl;
    cout << "Family Members:" << endl;

    for (int i = 0; i < num; i++) {
        cout << "Name: " << p[i].getName() << ", Age: " << p[i].getAge() << endl;
    }
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
    show(f); 
    delete f;
}