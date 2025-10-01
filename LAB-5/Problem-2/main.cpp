#include"Stack.h"
#include"Stack.cpp"
#include<iostream>
using namespace std;
int main() {
    Stack<int> *stack = new Stack<int>();

    string a = "93*42/-";
    string b = "56+78+*";

    cout << "1st Postfix: " << a << endl;
    cout << "Result: " << stack->evalPostfix(a) << endl;
    cout << "2nd Postfix: " << b << endl;
    cout << "Result: " << stack->evalPostfix(b) << endl;
    delete stack;
    return 0;
}