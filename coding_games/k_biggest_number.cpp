// https://leetcode.com/problems/kth-largest-element-in-an-array/
#include <vector>
#include <set>
using namespace std;    

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::multiset<int> maxNums;
        for(int i = 0; i < nums.size(); ++i){
            if(maxNums.size() < k ){
                maxNums.insert(nums[i]);
                continue;
            }
            auto first = *maxNums.begin();
            if (nums[i] > first){
                maxNums.erase(maxNums.begin());
                maxNums.insert(nums[i]);
            }


        }
        return *maxNums.begin();
    }
};