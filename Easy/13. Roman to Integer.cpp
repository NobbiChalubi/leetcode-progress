#include <iostream>
#include <unordered_map>

//Problem: Roman to Integer
//Link: https://leetcode.com/problems/roman-to-integer/
//Date: 11/15/25
//Difficulty: Easy
//Time Complexity: O(n) 
//Space Complexity: O(1)
//Concepts: Static, char
//Notes: Static variables are only initialized once, in this case its a small optimization used for the map, char is a built in c++ data type its a singular character, similar to a string but one character.


int romanToInt(std::string s) {
    int value = 0;
	static std::unordered_map<char, int> map = {
		{'I',1},
		{'V',5},
		{'X',10},
		{'L',50},
		{'C',100},
		{'D',500},
		{'M',1000}
	};
	for (int c = 0; c < s.size();++c) {
		if (c<s.size()-1 && map[s[c]] < map[s[c + 1]]) {
			int addedValue = 0;
			addedValue = map[s[c+1]] - map[s[c]];
			value += addedValue;
			++c;
		}
		else { value += map[s[c]]; }
		}
	return value;
    }

int main(){
    std::string input = "";
    std::cin>>input;
    std::cout<<romanToInt(input);
    return 0;
}