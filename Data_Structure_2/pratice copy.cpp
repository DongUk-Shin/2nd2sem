#include<stdio.h>
#include<iostream>
#include<string>
#include<Windows.h>
#include<cstdlib> 
#include<ctime> 
using namespace std;


int main() {
    int const *a;
    const int *b;

    int *ptr;
    int d = 1;
    ptr = &d;


    cout << *ptr << endl;
}