#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
private:
    int id;
    string name;
    double salary;

public:
    Employee();  
    Employee(int id, string name, double salary);

    int getId();
    void setId(int id);
    string getName();
    void setName(string name);
    double getSalary();
    void setSalary(double salary);

};
#endif