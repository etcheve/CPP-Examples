// https://leetcode.com/problems/palindrome-number/description/
// Given an integer x, return true if x is a palindrome, and false otherwise.

#include <vector>   


class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0 ){
            return false;
        }
        if (x < 10 ){
            return true;
        }
        std::vector<int> nums;
        int rest = x;

        while (rest > 0 ){
            int a = rest%10;
            nums.push_back(a);
            rest = rest/10;

        }
        for (int i = 0 ; i < nums.size(); ++i){
           if (nums[i] != nums[nums.size()-i-1]){
            return false;}
        }
        return true;
    }
};