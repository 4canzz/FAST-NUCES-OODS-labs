#include <iostream>
#include <stack>
#include <queue>
#include <string>
using namespace std;

bool isPalindrome(string word) {
	stack<char> s;
	queue<char> q;

	for (int i = 0; i < word.length(); i++) {
		s.push(word[i]);
		q.push(word[i]);
	}
	for (int i = 0; i < word.length(); i++) {
		if (s.top() != q.front()) {
			return false;
		}
		s.pop();
		q.pop();
	}
	return true;
}

int main() {
	string palindrome = "detartrated";

	if (isPalindrome(palindrome)) cout << "This is a palindrome" << endl;
	else cout << "This is not a palindrome" << endl;

    palindrome = "furqan";

    if (isPalindrome(palindrome)) cout << "This is a palindrome" << endl;
	else cout << "This is not a palindrome" << endl;

	return 0;
}