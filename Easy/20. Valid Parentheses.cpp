#include <iostream>
#include <unordered_map>
#include <stack>

//Problem: Valid Parentheses
//Link: https://leetcode.com/problems/valid-parentheses/
//Date: 11/15/25
//Difficulty: Easy
//Time Complexity: O(n)
//Space Complexity: O(n)
//Concepts: Stack
//Notes: Stack basically means a stack of books you tap off the top FILO


bool isValid(std::string& s) {
	if (s.size() % 2 != 0) { return false; }
	std::stack<char> stack;
	static std::unordered_map<char, char> key{
		{')', '('},
		{'}','{'},
		{']','['},
	};

	for (char c : s) {
		if (c == '(' or c == '[' or c == '{') {
			stack.push(c);
		}
		else {
			if (stack.empty()) { return false; }
			else if (stack.top() != key[c]) { return false; }
			else if (stack.top() == key[c]) { stack.pop(); continue; }
		}
	}
	if (stack.empty()) { return true; }
	else { return false; }

}

int main() {
	std::string input;
	std::cin >> input;
	std::cout << isValid(input);
	return 0;
}
