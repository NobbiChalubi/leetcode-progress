#include <iostream>
#include <unordered_map>
#include <vector>

//Problem: Move Zeroes
//Link: https://leetcode.com/problems/move-zeroes/description/
//Date: 11/18/25
//Difficulty: Easy
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: Two Pointers
//Notes:

void moveZeroes(std::vector<int>& nums) {
    if(nums.empty()){return;}
    int write = 0;
    int num = 0;
    for(int i=0; i<nums.size(); ++i){
        if(nums[i]!=0){
            num = nums[write];
            nums[write]=nums[i];
            nums[i] = num;
            ++write;
        }
    }
}

int main(){
    std::vector<int> vec = {1};
    moveZeroes(vec);
    return 0;
}