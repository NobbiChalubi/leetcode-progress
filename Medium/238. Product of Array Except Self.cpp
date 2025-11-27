#include <iostream>
#include <unordered_map>    
#include <vector>
#include <random>

//Problem: Insert Delete GetRandomO(1)
//Link: https://leetcode.com/problems/product-of-array-except-self/description/
//Date: 11/25/25
//Difficulty: Medium
//Time Complexity: O(n)
//Space Complexity: O(1)//stated in question that output array did not count as space otherwise O(n)
//Concepts: 
//Notes: 

std::vector<int> productExceptSelf(std::vector<int>& nums) {
    int num = 1;
    std::vector<int> calculated = {};
    for(int i=0; i<nums.size(); ++i){
        if(i==0){calculated.push_back(1);num = nums[i];continue;}
        calculated.push_back(num);
        num*=nums[i];
    }

    num = 1;
    for(int x = nums.size()-1; x>0; --x){
        calculated[x-1]*=nums[x]*num;
        num*=nums[x];
    }

    return calculated;
}


int main(){
    std::vector<int> input = {0,0};

    for(int num : productExceptSelf(input)){
        std::cout<<num<<"\n";
    }




    return 0;
}