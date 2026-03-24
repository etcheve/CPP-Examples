// https://leetcode.com/problems/longest-common-subsequence/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.size()+1,vector<int>(text2.size()+1,0));
        int longest = 0 ;
        for (int i = 0 ; i < text1.size(); ++i){
            for (int j = 0 ; j < text2.size(); ++j){
                if(text1[i] == text2[j]){
                    dp[i+1][j+1] = dp[i][j]+1;
                    longest = max (longest, dp[i+1][j+1]);
                }
                else {
                        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
                }
        }
        }
        return longest;

    }
};