#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isPalindrome(string word) {
	stack<char> Stack;
	queue<char> Queue;

	for (int i = 0; i < word.length(); i++) {
		Stack.push(word[i]);
		Queue.push(word[i]);
	}
	for (int i = 0; i < word.length(); i++) {
		if (Stack.top() != Queue.front()) return false;
		Stack.pop();
		Queue.pop();
	}
	return true;
}

int main() {
	string palindrome = "detartrated";

	if (isPalindrome(palindrome)) cout << palindrome << " is a palindrome" << endl;
	else cout << palindrome << " is NOT a palindrome" << endl;

    palindrome = "furqan";

    if (isPalindrome(palindrome)) cout << palindrome << " is a palindrome" << endl;
	else cout << palindrome << " is NOT a palindrome" << endl;

	return 0;
}

/*Exercise 3:
Use the Queue you implemented in the inlab to check whether the word is a palindrome or not in a
non-member function as given below.
#include “Queue.h”
bool isPalindrome(string word);

Note: though this was to be done using my own implementation, 
the STL implementation of stack and queue was used instead due to time constriction in the lab*/