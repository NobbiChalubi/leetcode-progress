#include<iostream>
#include<vector>
#include<unordered_map>

//Problem: Two Sum
//Link: https://leetcode.com/problems/two-sum/
//Date: 11/12/25
//Difficulty: Easy
//Time Complexity: O(n)
//Space Complexity: O(n)
//Concepts: Hash Maps
//Notes: Using a hash map is significantly more efficient than nested loops


std::vector<int> twoSum(std::vector<int>& nums, int target) {
			std::unordered_map<int, int> map;
			for (int i = 0; i < nums.size(); ++i) {
				int compliment = target - nums[i];
				if (map.find(compliment) != map.end()) {
					return {i,map[compliment]};
				}
				map[nums[i]] = i;
			}
            return {};
        }

int main(){
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;


    for(int i : twoSum(nums, target)){
        std::cout<< i << " ";
    }

    return 0;
}