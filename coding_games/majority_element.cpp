// https://leetcode.com/problems/majority-element/description/?envType=study-plan-v2&envId=top-interview-150

#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        return nums[nums.size()/2];
    }
};



class Solution2 {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = nums[0];
        int count = 1;
        for (int i =1 ; i < nums.size(); ++i){
            if(candidate == nums[i]){
                ++count;
            }else{
                --count;
            }
            if (count == 0){
                candidate = nums[i];
                count = 1 ;
            }
        }
        return candidate;
    }
};