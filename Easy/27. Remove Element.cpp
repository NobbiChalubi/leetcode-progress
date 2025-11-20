#include <iostream>
#include <vector>

//Problem: Remove Element
//Link: https://leetcode.com/problems/remove-element/description/
//Date: 11/18/25
//Difficulty: Easy
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: Two Pointer, In Place
//Notes: Most others solution used a two pointer one reading through the array, the other writes good values to the front

int removeElement(std::vector<int>& nums, int val) {
    if(nums.empty()){ return 0;}
    int lasPosIndex = nums.size()-1;
    int fillPosIndex = nums.size()-1;
    int k = 0;
    while (fillPosIndex!=-1)
    {
        if(nums[fillPosIndex] == val){
            nums[fillPosIndex] = nums[lasPosIndex-k];
            --fillPosIndex;
            ++k;
        }else{
            --fillPosIndex;
        }
    }
    return nums.size()-k;

}

int main(){
    std::vector<int> nums = {0,0,1,2,2,3,4};
    int val = 2;
    std::cout<<removeElement(nums,val);

    return 0;
}