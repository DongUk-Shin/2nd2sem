#include "Employee.h"
#include <iostream>
using namespace std;

int main() {

    Employee em = { 1, "ted", 20};

    em.setId(50);
    cout << em.getId();
    return 0;
}