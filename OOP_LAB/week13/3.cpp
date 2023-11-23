#include <iostream>
#include <string>
#define MAX 100

using namespace std;

template<class T>
class Stack {
	T arr[MAX];
	int top;
public:
	Stack() {
		top = -1;
	}
	void push(T item) {
		if (!is_full())
			arr[++top] = item;
	}
	T pop() {
		if (!is_empty()) {
			int temp = top;
			top--;
			return arr[temp];
		}
	}
	T peek() {
		if (!is_empty()) 
			return arr[top];
	}
	bool is_full() {
		return top == MAX;
	}
	bool is_empty() {
		return top == -1;
	}
};

int main() {
	Stack<int> integer_stack;
	Stack<string> string_stack;
	integer_stack.push(2);
	integer_stack.push(54);
	integer_stack.push(255);

	string_stack.push("Welcome");
	string_stack.push("to");
	string_stack.push("C++ World");

	cout << integer_stack.pop() << " is removed from stack" << endl;
	cout << string_stack.pop() << " is removed from stack " << endl;

	cout << "Top element is " << integer_stack.peek() << endl;

	cout << "Top element is " << string_stack.peek() << endl;

}