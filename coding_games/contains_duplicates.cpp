// https://leetcode.com/problems/contains-duplicate/
#include <unordered_map>
#include <vector>       
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> rep;
        for(int i = 0; i < nums.size(); ++i){
            if (rep.end()!=rep.find(nums[i])){
                return true;
            }
            rep[nums[i]]=1;
        }
        return false;
    }
        
};