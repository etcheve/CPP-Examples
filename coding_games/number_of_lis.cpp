// https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/?envType=study-plan-v2&envId=dynamic-programming

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> paths(nums.size(),0);
        for (int i = 0 ; i < nums.size();++i){
            int max_ = 1;
            int paths_ = 1;
            for (int j = 0; j < i ; ++j){
                if (nums[j]>=nums[i]){
                    continue;
                }
                if(max_< dp[j]+1){
                    max_= dp[j]+1;
                    paths_ = paths[j];;
                }else if (max_ == dp[j]+1){
                    paths_ += paths[j];;
                }

            }
            dp[i] = max_;
            paths[i]= paths_;
        }
        int max_IS = *max_element(dp.begin(),dp.end());
        int count = 0 ;
        for(int i = 0; i < dp.size(); ++i){
            if (dp[i]==max_IS){
                count+=paths[i];
            }
        }
        return count;
    }
};