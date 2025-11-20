#include<iostream>
#include<vector>
#include<algorithm>

//Problem: Palindrome Number
//Link: https://leetcode.com/problems/palindrome-number/
//Date: 11/15/25
//Difficulty: Easy
//Time Complexity: O(n * m)
//Space Complexity: O(m)
//Concepts: std::reverse
//Notes: Modulos %10 is very useful, it will get the first digit in a number(987%10=7) 

bool isPalindrome(int x) {
	std::vector<int> reverseNumTemp;
	if (x < 0) { return false; }
	while (x > 0) {
		reverseNumTemp.push_back(x%10);
		x /= 10;
	}
	std::vector<int> reverseNum = reverseNumTemp;
	std::reverse(reverseNumTemp.begin(), reverseNumTemp.end());
	if (reverseNum == reverseNumTemp) { return true; }
	else { return false; }
    }

int main(){
    int num = 0;
    std::cin>>num;
    isPalindrome(num);
    return 0;
}