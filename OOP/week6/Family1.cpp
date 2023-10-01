#include <vector>
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
        vector<Person> vc;
        string surname;
        int num;

    public:
        Family(string n, int num): surname(n), num(num) { }

        void setMembers() {
            cout << "\n��� ������ �� �������� ���ؼ� �̸��� ���̸� �Է��ϼ���: " << endl;
            for (int i = 0; i < num; i++) {
                int age;
                string name;
                Person p;

                cout << "Enter a Name: ";
                cin >> name;
                p.setName(name);

                cout << "Enter a Age: ";
                cin >> age;
                p.setAge(age);

                vc.push_back(p);
            }
        }

        int getNum() {
            return num;
        }

        string getSurname() {
            return surname;
        }

        vector<Person> getVc() {
            return vc;
        }
};

void show(Family* f) {
    int num = f->getNum();
    string name = f->getSurname();
    vector<Person> vc = f->getVc();

    cout << "\n" << name << " �� ������ ������ ���� " << num << "�� �Դϴ�" << endl;
    cout << "Name           Age" << endl;

    for (auto& p : vc) {
        cout  << p.getName() << "              " << p.getAge() << endl;
    }
    cout << "You did a good job" << endl;
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