#include <iostream>
#include <vector>
#include <algorithm>

//Problem: Merge Sorted Array
//Link: https://leetcode.com/problems/merge-sorted-array/
//Date: 11/18/25
//Difficulty: Easy
//Time Complexity: O(m + n)
//Space Complexity: O(1)
//Concepts: Dereferencing, Vector Functions
//Notes: nums2.begin() points to a memory address, if you dereference it you get the value at that location, make sure when changing things relating
//to index in loops you --index or ++index
    
std::vector<int> merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
if(n==0){return nums1;}
int nIndex = n-1;
int mIndex = m-1;
int lastPosOfPlaceHolder = m+n-1;

while (nIndex!=-1)
{
    if(mIndex >= 0 && nums1[mIndex] > nums2[nIndex]){
        nums1[lastPosOfPlaceHolder] = nums1[mIndex];
        --mIndex; --lastPosOfPlaceHolder;
    }
    else{
        nums1[lastPosOfPlaceHolder] = nums2[nIndex];
        --nIndex; --lastPosOfPlaceHolder;
    }
}

nums2.clear();


return nums1;
}

int main(){
std::vector<int> nums1 = {1,2,3,0,0,0};
int m = 3;
std::vector<int> nums2 = {2,5,6};
int n = 3;

for(int num : merge(nums1, m, nums2, n)){
    std::cout<<num<<" ";
}
return 0;
}