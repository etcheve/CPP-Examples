// https://leetcode.com/problems/product-of-array-except-self/
#include <vector>
using namespace std;
    
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size();
        vector<int> result(n, 1);

        for (int i = 1; i < n; ++i) {
            result[i] = result[i-1] * nums[i-1];
        }

        int right = 1;
        for (int i = n-1; i >= 0; --i) {
            result[i] *= right;
            right *= nums[i];
        }
        return result;
    }

};
