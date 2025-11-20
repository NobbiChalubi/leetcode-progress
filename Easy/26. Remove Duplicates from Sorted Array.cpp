#include <iostream>
#include <vector>


//Problem: Remove Duplicates from Sorted Array
//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/
//Date: 11/19/25
//Difficulty: Easy
//Time Complexity: 
//Space Complexity: 
//Concepts: Two Pointers
//Notes:

int removeDuplicates(std::vector<int>& nums) {
    if(nums.empty()){return 0;}
    int write = 1;

    for(int read = 1; read<nums.size(); ++read){
        if(nums[read]!=nums[write-1]){
            nums[write] = nums[read];
            ++write;
        }
    }
    return write;
}


int main(){
    std::vector<int> numbers = {0,1,1,1,1,2,2,3,3,4};
    std::cout<<removeDuplicates(numbers);

    return 0;
}