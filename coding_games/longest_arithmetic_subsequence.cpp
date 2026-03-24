//https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/description/?envType=study-plan-v2&envId=dynamic-programming

#include <vector>
#include <unordered_map>
using namespace std;    
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        
        unordered_map<int,int> buff;
           for (int i = 0; i < arr.size(); ++i) {
            auto it = buff.find(arr[i] - difference);
            buff[arr[i]] = (it != buff.end()) ? it->second + 1 : 1;
        }
        int result=1;
        for (auto& v : buff ){
            result = max(result, v.second);
        }
        return result;
    }
};