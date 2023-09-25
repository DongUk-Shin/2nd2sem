#include "Employee.h"


Employee::Employee() : id(0), name(""), salary(0.0) {}

Employee::Employee(int id, string name, double salary)
    : id(id), name(name), salary(salary) {}

int Employee::getId() {
    return id;
}

void Employee::setId(int id) {
    this->id = id;
}

string Employee::getName() {
    return name;
}

void Employee::setName(string name) {
    this->name = name;
}

double Employee::getSalary(){
    return salary;
}

void Employee::setSalary(double salary) {
    this->salary = salary;
}
