//https://leetcode.com/problems/3sum/
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int i = 0;
        int j = 1;
        int k = nums.size()-1;
        vector<vector<int>> result;

        while (i < k-1) {
            if (nums[i]+nums[j]+nums[k]==0){
                result.push_back({nums[i],nums[j],nums[k]});
                --k; ++j;
                while (j < k && nums[j] == nums[j-1]) ++j;
                while (j < k && nums[k] == nums[k+1]) --k;
                if (j >= k) {
                    ++i;
                    while (i < k && nums[i] == nums[i-1]) ++i;
                    j = i+1;
                    k = nums.size()-1;
                }
            } else if (nums[i]+nums[j]+nums[k] < 0){
                ++j;
                if (j >= k){
                    ++i;
                    while (i < k && nums[i] == nums[i-1]) ++i;
                    j = i+1;
                    k = nums.size()-1;
                }
            } else {
                --k;
                if (j >= k){
                    ++i;
                    while (i < k && nums[i] == nums[i-1]) ++i;
                    j = i+1;
                    k = nums.size()-1;
                }
            }
        }
        return result;
    }
};