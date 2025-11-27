#include <iostream>
#include <vector>
#include <algorithm>

//Problem: Rotate Array
//Link: https://leetcode.com/problems/rotate-array/description/
//Date: 11/21/25
//Difficulty: Medium
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: Reverse
//Notes:

std::vector<int> rotate(std::vector<int>& nums, int k) {
    if(nums.empty()){return nums;}
    if(k>nums.size()){
        k = k % nums.size();
    }

    std::reverse(nums.begin(),nums.end());
    std::reverse(nums.begin(),nums.begin()+k);
    std::reverse(nums.begin()+k,nums.end());
    return nums;
}

int main(){
    std::vector<int> nums = {1,2};
    int k = 7;
    for(int num : rotate(nums, k)){
        std::cout<<num;
    }
    return 0;
}