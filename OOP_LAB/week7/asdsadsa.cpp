#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Person {
private:
	string name;
	int age;
public:
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	void setName(string n) {
		name = n;
	}
	void setAge(int a) {
		age = a;
	}

};

bool compare(Person* p, Person* q) {
	return p->getAge() < q->getAge();
}

int main() {

	
	int age;
	char answer;
	string name;

	vector<Person*> vc;

	do {
		cout << "Enter a name: ";
		cin >> name;

		cout << "Enter an age: ";
		cin >> age;

		Person* p = new Person;
		p->setName(name);
		p->setAge(age);

		vc.push_back(p);
		
		cout << "Continue?(y/n): ";
		cin >> answer;

	} while (answer != 'n');

	sort(vc.begin(), vc.end(), compare);


	for (auto& a : vc) {
		cout << "Name: " << a->getName() << " Age: " << a->getAge() << endl;
	}

	return 0;
}