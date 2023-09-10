/*
객지 LAB 2주차 swap
*/

#include<iostream>
#include<string>

using namespace std;

void swap(int a, int b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void swap(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int a[], int size) {
	int j;

	for (int i = 0; i < size / 2; i++) {
		j = size - 1 - i;
		swap(&a[i], &a[j]);
	}

	for (int i = 0; i < size; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


int main() {

	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10};
	int b[] = { 1, 2, 3, 4, 5, 6, 7, 8 ,9, 10, 11};

	reverse(a, 10);
	reverse(b, 11);

	return 0;
}