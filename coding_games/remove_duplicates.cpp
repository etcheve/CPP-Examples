// https://leetcode.com/problems/remove-duplicates-from-sorted-array/description/

/*
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.
*/

#include <vector>
using namespace std;    

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.empty()){
            return 0;
        }
        int k = 0; 
        for (int i = 1 ; i < nums.size(); ++i){
            if (nums[i] == nums[k]){
                continue;
            }
            ++k;
            nums[k]=nums[i];
        }
        return ++k;
    }
};