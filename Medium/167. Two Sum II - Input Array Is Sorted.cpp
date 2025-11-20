#include <iostream>
#include <vector>
#include <unordered_map>

//Problem: Two Sum II - Input Array Is Sorted
//Link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
//Date: 11/19/25
//Difficulty: Easy
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: Hash Table, or Two Pointers
//Notes:

std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int leftIndex = 0;
        int rightIndex = numbers.size()-1;
        int compliment = 0;
        for(int i=0; i<numbers.size(); ++i){
            if(numbers[leftIndex]+numbers[rightIndex]==target){return {leftIndex+1,rightIndex+1};}
            if(numbers[leftIndex]+numbers[rightIndex]>target){--rightIndex;}
            else{++leftIndex;}
        }
        return numbers;
}

int main(){
    std::vector<int> numbers = {-1,0};
    int target = -1;
    for(int num : twoSum(numbers, target)){
        std::cout<<num<<" ";
    }
    return 0;
}