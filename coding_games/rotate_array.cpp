// https://leetcode.com/problems/rotate-array/description/?envType=study-plan-v2&envId=top-interview-150


#include <vector>
#include <algorithm>    
using namespace std;

 // from internet 
 // im not this clever 

 class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k %= n; // handle k > n
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};
