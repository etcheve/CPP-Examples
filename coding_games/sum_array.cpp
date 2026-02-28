// https://leetcode.com/problems/subarray-sum-equals-k/description/
#include <unordered_map>
#include <vector>
using namespace std;
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        freq[0] = 1;                

        int runningSum = 0;
        int count = 0;

        for (int x : nums) {
            runningSum += x;

            int needed = runningSum - k;
            auto it = freq.find(needed);
            if (it != freq.end()) {
                count += it->second;
            }

            freq[runningSum]++;   
        }

        return count;
    }
};