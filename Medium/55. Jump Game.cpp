#include <iostream>
#include <vector>

//Problem: Jump Game
//Link: https://leetcode.com/problems/jump-game/description/
//Date: 11/22/25
//Difficulty: Medium
//Time Complexity: O(n)
//Space Complexity: O(1)
//Concepts: Greedy
//Notes:

bool canJump(std::vector<int>& nums) {
    if(nums.empty()){return false;}
    if(nums.size()==1){return true;}


    int currentNum = nums[0];
    int currentNumIndex = 0;
    int currentNumReach = currentNumIndex+currentNum;

    int nextNum = 0;
    int nextNumIndex = 0;
    int nextNumReach = nextNumIndex+nextNum;

    int largestNumReach = nums[0];
    int largestNumReachIndex = 0;


    

    while(true){
        if(currentNum>=nums.size()){return true;}
        if(currentNum==0){return false;}
        


        for(int i = currentNumIndex; i<=currentNumReach;++i){
            if(currentNumReach>=nums.size()-1){return true;}
            if(currentNum==0){return false;}
            nextNum = nums[i];
            nextNumIndex = i;
            nextNumReach = nextNumIndex + nextNum;

            if(nextNumReach>=currentNumReach && nextNumReach>=largestNumReach){           
                largestNumReachIndex = nextNumIndex;
                largestNumReach = nums[nextNumIndex]+largestNumReachIndex;
            }
        }

        currentNum = nums[largestNumReachIndex];
        currentNumIndex = largestNumReachIndex;
        currentNumReach = largestNumReach;      

    }
}

int main(){
    std::vector<int> vec = {0,1};

    std::cout<<canJump(vec);

    return 0;
}