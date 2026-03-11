//https://leetcode.com/problems/remove-element/description/
/*
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:
*/

#include <vector>
using namespace std;
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        int arrL =  nums.size() ;
        for(int i = 0 ;i < arrL-k; ++i){
            if (nums[i] == val){
                ++k;
                while( nums[arrL- k]== val){
                    if (arrL-k <= i) {
                        return (arrL - k);   
                    }
                    ++k;
                }
                nums[i] = nums[arrL - k];
            }
        }
                 return (arrL - k);   
    }
};