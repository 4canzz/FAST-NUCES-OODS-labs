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

/*Exercise 2: Application of Stack 
A postfix expression is an expression in which each operator follows its operands. The advantage of
this form is that there is no need to group sub-expressions in parentheses or to consider operator
precedence. Stack can be used to evaluate a postfix (or prefix) expression. Please implement the
C++ code given below to evaluate a postfix expression. 
1. Make a left to right scan of the postfix expression 
2. If the element is an operand push it on Stack 
3. If the element is operator, evaluate it using as operands the correct number from stack and
pushing the result onto the stack 
*/