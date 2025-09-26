#include<iostream>  
using namespace std;

unsigned long long  recursive_factorial(int n);
unsigned long long iterative_factorial(int n);

int main() {
    int num;
    cout << "Enter a non-negative integer: ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
        return 1;
    }
	cout << "value of num recursively is: " << recursive_factorial(num) << endl;
	cout << "value of num iteratively is: " << iterative_factorial(num) << endl;
	system("pause");
	return 0;
}

//Time Complexity: O(n) because the loop runs n times
// Space Complexity: O(n) as due to call stack depth
unsigned long long  recursive_factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * recursive_factorial(n - 1); 
}

//Time Complexity: O(n) because the loop runs n times
// Space Complexity: O(1) as it uses a constant amount of space
unsigned long long iterative_factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

/* Exercise 3:
Write a program to find the factorial of a given number
i. Iteratively
ii. Recursively.
Describe the difference in terms of time and space complexity, on top of the code in comments.
Please Note the Lab - 1 Contained only 1 Coding Question, the 2 before were theory.
*/