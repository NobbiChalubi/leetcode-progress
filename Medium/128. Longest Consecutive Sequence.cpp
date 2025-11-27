#include <iostream>
#include <unordered_map>    
#include <vector>
#include <unordered_set>

//Problem: Longest Consecutive Sequence
//Link: https://leetcode.com/problems/longest-consecutive-sequence/description/
//Date: 11/26/25
//Difficulty: Medium
//Time Complexity: 
//Space Complexity: 
//Concepts: Hash Table
//Notes: 

int longestConsecutive(std::vector<int>& nums) {
        if(nums.empty()){return 0;}
        int amount = 0;
        int LongestConsec = 0;
        int temp = 0;

        std::unordered_set<int> set(nums.begin(), nums.end());
        for (int x : set){
            if(set.find(x-1)==set.end()){
                amount = 0;
                while(set.find(x+temp)!=set.end()){
                    ++amount;
                    ++temp; 
                }
                if(amount>=LongestConsec){LongestConsec = amount;}
                temp = 0;
            }
        }
        return LongestConsec;
}




int main(){

    std::vector<int> nums = {1};
    std::cout<<longestConsecutive(nums);

    return 0;
}