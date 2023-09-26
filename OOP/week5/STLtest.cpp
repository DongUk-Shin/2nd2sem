#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Person {
private:
    string name;
    int age;
public:
    Person(string n, int a) : name(n), age(a) {}
    string getName() const { return name; }
    int getAge() const { return age; }
};

bool compare(const Person &p, const Person &q) {
    return p.getAge() < q.getAge();
}

int main() {
    vector<Person> people;
    people.push_back(Person("Kim", 30));
    people.push_back(Person("Park", 22));
    people.push_back(Person("Lee", 26));

    sort(people.begin(), people.end(), compare);

    for (const auto &person : people) {
        cout << "Name: " << person.getName() << ", Age: " << person.getAge() << endl;
    }

    return 0;
}
