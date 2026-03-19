//https://leetcode.com/problems/two-sum/ 
/*
Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.
*/
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int,int> missing;
        for (int i = 0; i < nums.size(); ++i){
            auto it = missing.find(nums[i]);
            if (it != missing.end()){
                return {i,it->second};
            }
            missing[target-nums[i]]=i;
        }
        return {};
    }
};