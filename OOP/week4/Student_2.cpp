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

	void setMarks(double m) {
		marks = m;
	}
	double getMarks() {
		return marks;
	}

	void setName(string s) {
		name = s;
	}

	string getName() {
		return name;
	}
};

void print(Student s[], int n) {
	for (int i = 0; i < n; i++) {
		cout << "Name: " << s[i].getName() << " Marks: " << s[i].getMarks() << endl;
	}
}

void update(Student &s) {
	string name;
	cout << "Enter a student name: ";
	cin >> name;
	s.setName(name);

	cout << "Enter the marks: ";
	double marks;
	cin >> marks;
	s.setMarks(marks);
}

int main() { 
	Student students[3];

	for (auto& s : students) { 
		update(s); 
	}

	print(students, 3);
	return 0;
}