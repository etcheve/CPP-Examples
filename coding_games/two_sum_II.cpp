//https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/
#include <unordered_map>
#include <vector>
using namespace std;
// Note you can't use memorisation here because of the sorted array constraint

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int j = numbers.size()-1;
            int i = 0;
           while (i < j ){
            if (numbers[i]+numbers[j]==target){
                return {i+1,j+1};
            }
            if ((numbers[i]+numbers[j]>target)){
                --j;
            }else{
                ++i;
            }
    
           }
           return {};
        }
        
    };