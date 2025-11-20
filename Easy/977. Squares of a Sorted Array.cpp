#include <iostream>
#include <vector>


//Problem: Squares of a Sorted Array
//Link: https://leetcode.com/problems/squares-of-a-sorted-array/
//Date: 11/18/25
//Difficulty: Easy
//Time Complexity: O(n)
//Space Complexity: O(n)
//Concepts: Two Pointers
//Notes: 

std::vector<int> sortedSquares(std::vector<int>& nums) {
    if(nums.empty()){return nums;}
    std::vector<int> newNums(nums.size());
    int firstIndexPos = 0;
    int lastPosIndex = nums.size()-1;
    int fillPosition = nums.size()-1;


    while(firstIndexPos<=lastPosIndex){
        if(nums[firstIndexPos] * nums[firstIndexPos] > nums[lastPosIndex] * nums[lastPosIndex]){
            newNums[fillPosition] = nums[firstIndexPos]*nums[firstIndexPos];
            --fillPosition; ++firstIndexPos;
        }else{
            newNums[fillPosition] = nums[lastPosIndex]*nums[lastPosIndex];
            --fillPosition; --lastPosIndex;
        }
    }



    return newNums;
    }

int main(){
    std::vector<int> nums = {-4,-1,0,3,10};
    for(int num : sortedSquares(nums)){
        std::cout<<num<<" ";
    }
    return 0;
}