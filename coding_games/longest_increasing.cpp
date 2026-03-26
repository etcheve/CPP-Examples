// https://leetcode.com/problems/longest-increasing-subsequence/?envType=study-plan-v2&envId=dynamic-programming

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        for (int i = 0 ; i < nums.size(); ++i){
            int max_=1;
            for (int j = 0 ; j < i; ++j){
                if(nums[i]>nums[j]){
                    max_ = max(max_,dp[j]+1);
                } 
            }
            dp[i]=max_;
        }
        return *max_element(dp.begin(), dp.end());
    }
};