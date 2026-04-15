// https://leetcode.com/problems/word-break/description/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        std::vector<int> dp(s.size()+1,0);
        dp[0]=1;
        for (int i = 0; i < s.size(); ++i){
            if (dp[i] == 0 ){
                continue;
            }

            for (int j = 0; j < wordDict.size();++j){
                for (int k = 0 ; k < wordDict[j].size() && (i+k < s.size()); ++k){
                    if(s[i+k] != wordDict[j][k]){
                        break;
                    }
                    if(k ==  wordDict[j].size() -1 ){
                        dp[i+k+1]=1;
                    }
                }
            }

        }
        return dp[s.size()];
    }
};