//https://leetcode.com/problems/search-insert-position/description/

/*
Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.
*/
#include <vector>
using namespace std;
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int i = (nums.size()+1)/2;
        if (target <= nums[0]){
            return 0;
        }
         if (target > nums[h]){
            return h+1;
        }

        while(1){ 
            if (h-l <=1){
                return h;
            }
            if (nums[i] == target){
                return i;
            }
            if (nums[i] < target){
                l = i;
                i = (i + h+1)/2;
            }else {
                h = i;
                i = (i +l+1)/2;
            }
        }
        
    }
};