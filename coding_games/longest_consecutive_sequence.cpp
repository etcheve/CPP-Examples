//https://leetcode.com/problems/longest-consecutive-sequence/description/
#include <vector>
#include <unordered_set>        
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numss_set;
        for (int num : nums){
                numss_set.insert(num);
        }
        // we can potentially have repeted starting point 
         unordered_set<int> tested;

        int ls=0;
        for (int num : numss_set){
            if (numss_set.find(num-1) != numss_set.end()){
                continue;
            }
            if (tested.find(num)!=tested.end()){
                continue;
            }
            tested.insert(num);
            int current_sec=1;
            // we are at the start of a set 
            while (numss_set.find(num+current_sec) != numss_set.end()){
                ++current_sec;
            }
            ls = max (ls,current_sec);
        }
        return ls;

    }
};