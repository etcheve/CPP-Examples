// https://leetcode.com/problems/minimum-window-substring/
#include <unordered_map>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        if (s.empty() || t.empty()){ 
            return "";
            }
        if (s.size() < t.size()){
            return "";
        }

        std::unordered_map<char,int> need;
        for(char c : t){
            need[c]++;
        }
        std::unordered_map<char,int> have;
        int totalReq = need.size();

        // use to index left and right 
        int left = 0;
        int right = 0;
        int fullyMatchChar = 0;
        int bestLen = s.size()+1;
        int start  = 0;
        while (right < s.size()){
            char c = s[right];
            have[c]++;

            if (need.count(c) && need[c] == have[c]){
                ++fullyMatchChar;
            }

            //if fully mathc try to shink the window
            while (fullyMatchChar == totalReq && left <= right) {

                if (right - left + 1 < bestLen){
                    bestLen = right - left +1;
                    start = left;
                }
            
                char ls = s[left];
                have[ls]--;
                if(need.count(ls) && have[ls] < need[ls]){
                    --fullyMatchChar;
                }
                ++left;
            }

            ++right;

        }
    return  bestLen == (s.size()+1) ? "" : s.substr(start, bestLen);
    }
};