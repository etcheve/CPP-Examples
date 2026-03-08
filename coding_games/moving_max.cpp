//https://leetcode.com/problems/sliding-window-maximum/description/
#include <vector>
using namespace std;
class Solution {

struct Max{
    int max_;
    int count_;
    Max(int max, int count): max_(max), count_(count){    }
};    
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> result;
        int max  = nums[0] ;
        int maxCount = 1;
        if (k > nums.size() || nums.empty()){
            return result;
        }
        for (int j = 1; j < k ; ++j){
          if (max < nums[j]  ){
            max = nums[j];
            maxCount = 1;
          }else if (max == nums[j]  ){
            ++maxCount;
          }
        }
        result.push_back(max);
        for (int i = 0; i<  nums.size()-k; ++i){
            if (nums [i+k] > max) {
            max = nums [i+k];
            maxCount = 1;
            result.push_back(max);
            continue;
            }

            if (nums[i] == max ){
                --maxCount;
            }
            if (maxCount == 0 ) {
                auto currentMax=getMax(nums,k,(i+1));
                max = currentMax.max_;
                maxCount = currentMax.count_;
                // todo recompute 
            }
            
            result.push_back(max);
        }
        return result;
    }

    Max getMax(vector<int>& nums, int k, int index){
        int max = nums[index]; 
        int maxCount = 1;
        for (int j = index+1; j < index+k ; ++j){
          if (max < nums[j]  ){
            max = nums[j];
            maxCount = 1;
          }else if (max == nums[j]  ){
            ++maxCount;
          }
        }
        return Max(max,maxCount);
    }
};
