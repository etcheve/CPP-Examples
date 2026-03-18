
// https://leetcode.com/problems/house-robber/description/

/*
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        std::vector<int> sum(nums.size(),0);
        if(nums.size()==0){
            return 0;
        }
        if (nums.size()==1){
            return nums[0];
        }
        if (nums.size() ==2){
            return std::max(nums[0],nums[1]);
        }
        if (nums.size() ==3){
            return std::max(nums[0]+nums[2],nums[1]);
        }
        int max = std::max(nums[0]+nums[2],nums[1]); 
        sum[0]= nums[0];
        sum[1]= nums[1];
        sum[2] = nums[2]+nums[0];

        for (int i = 3; i< nums.size();++i){
            int localMax = std::max(nums[i]+sum[i-2], nums[i]+sum[i-3]);
            max = std::max(localMax,max);
            sum[i]=localMax;
        }
        return max;
    }
};