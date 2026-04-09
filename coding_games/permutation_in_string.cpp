// https://leetcode.com/problems/permutation-in-string/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int s1z = s1.size();
        int s2z = s2.size();

        if (s2z < s1z){
            return false;
        }
        vector<int> dp(26,0);
        for (char c : s1){
            ++dp[c-'a'];
        }

        int left=0;
        int right=0;

        while (right - left < s1z){
            --dp[s2[right]-'a'];
            ++right;
        }
       if (validate(dp)){
                return true;
        }

        while (right < s2z){
            ++dp[s2[left]-'a'];
            ++left;
          
            --dp[s2[right]-'a'];
            ++right;
            if (validate(dp)){
                return true;
            }
    
        }
        return false;   
    }

    bool validate(vector<int>& v){
        for (int i : v ){
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
};