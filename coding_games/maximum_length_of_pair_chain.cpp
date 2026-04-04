// https://leetcode.com/problems/maximum-length-of-pair-chain/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
    sort(pairs.begin(), pairs.end(), 
        [](const vector<int>& a, const vector<int>& b){ return a[1] < b[1]; });
        vector<int> dp(pairs.size(), 1);
        for (int i = 0; i < pairs.size(); ++i){
            int max_ = 1;
            for (int j = 0 ; j < i; ++j){
                if(pairs[j][1] >= pairs[i][0]){
                    continue;
                }
                max_ = max(max_, dp[j]+1);
            }
            dp[i]=max_;
        }
        return *max_element(dp.begin(),dp.end());
    }
};