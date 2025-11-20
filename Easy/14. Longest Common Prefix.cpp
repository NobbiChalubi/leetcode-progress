#include <iostream>
#include <vector>
#include <string>

//Problem: Longest Common Prefix
//Link: https://leetcode.com/problems/longest-common-prefix/description/
//Date: 11/15/25
//Difficulty: Easy
//Time Complexity: O(n * m)
//Space Complexity: O(m)
//Concepts: String Manipulation
//Notes: string.erase allows you to remove sections of a string, you can also use += with strings to concatenate although -= is not supported.

std::string longestCommonPrefix(std::vector<std::string>& strs) {
	std::string first = strs[0];
	std::string abrv = first;
	std::string current = "";
	if (strs.size() > 1) {
		for (int i = 0; i < strs.size(); ++i) {
			if (i == 0) { continue; }
			current = strs[i];
			for (int x = 0; x < first.size(); ++x) {
				if (x > abrv.size()) { break; }
				if (x > current.size() - 1) { abrv.erase(abrv.begin() + x, abrv.end()); break; }
				if (first[x] != current[x]) {
					abrv.erase(abrv.begin() + x, abrv.end());;
					break;
				}
			}
		}
	}
	return abrv;

}

int main() {
	std::vector<std::string> vector = { "flower","flow","flight" };
	std::cout<<longestCommonPrefix(vector);

	return 0;
}

