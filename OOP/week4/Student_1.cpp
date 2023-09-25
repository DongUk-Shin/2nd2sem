#include<iostream>
#include<string>
using namespace std;

class Student {
private:
	double marks;
	string name;

public:
	Student() {
		name = "Anonymous";
		marks = 0;
		cout << name <<" is crying" << endl;
	}
	Student(string n, double m) {
		name = n;
		marks = m;
		cout << name << " is crying" << endl;
	}
	
	~Student() {
		cout << name << " is die" << endl;
	}

	double getMarks() {
		return marks;
	}
	string getName() {
		return name;
	}
};

void print(Student &s) {
    cout << "Name: " << s.getName() << " Marks: " << s.getMarks() << endl;
}

int main() {
	Student s1;
	Student s2("Gildong", 4.5);

    print(s1);
    print(s2);
    return 0;
}