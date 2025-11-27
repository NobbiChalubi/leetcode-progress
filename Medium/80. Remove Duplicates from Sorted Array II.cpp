#include <iostream>
#include <vector>

//Problem: Remove Duplicates from Sorted Array II
//Link: https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/?envType=study-plan-v2&envId=top-interview-150
//Date: 11/20/25
//Difficulty: Medium
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: Two Pointer
//Notes:

int removeDuplicates(std::vector<int>& nums) {
    if(nums.empty()){return 0;}
    if(nums.size()<=2){return nums.size();}
    int k = nums.size();

    int write = 2;

    for(int read = 2; read<nums.size(); ++read){
        if (nums[read]!=nums[write-2])
        {
            nums[write] = nums[read];
            ++write;
        }else{--k;}
        
    }


    return k;
}


int main(){
    std::vector<int> vec = {0,0,1,1,1,2};

    std::cout<<removeDuplicates(vec);
    return 0;
}