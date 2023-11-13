#include <iostream>
#include <string>
#include <typeinfo>

using namespace std;

class Animal {
    string name;
    public:
    void speak() {
        cout << "Default" << endl;
    }
};

class Dog : public Animal {
    public:
    int age;
    void speak() {
        cout << "Dog" << endl;
    }
};

void printObjectType(const Animal* objPtr) {
    if (objPtr) {
        std::cout << "Object pointer type: " << typeid(*objPtr).name() << std::endl;
    } else {
        std::cout << "Object pointer is null." << std::endl;
    }
}


int main() {
    Animal *a1;
    Dog *d1 = new Dog;
    a1 = d1; //UpCasting 대입을 하더라도 타입은 Animal일뿐 타입이 변하지는 않음
    a1->speak();


    printObjectType(a1);

    delete a1;
    delete d1;
}