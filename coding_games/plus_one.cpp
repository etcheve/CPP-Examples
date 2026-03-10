// https://leetcode.com/problems/plus-one/description/

#include <vector>
using namespace std;    
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size()-1 ; 
        int rem = 1;
        while(rem > 0 && i >=0){
            if(digits[i]==9){
                rem=1;
                digits[i]=0;
                --i;
                continue;
            }
            rem =0;
            ++digits[i];
            --i;
        }
        if (rem == 1 && i <=0){
            digits.insert(digits.begin(), 1);
        }
        return digits;
        
    }
};