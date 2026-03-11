// https://leetcode.com/problems/reverse-integer/description/

//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

// Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

class Solution {
public:
    int reverse(int x) {
        int sign= x < 0 ? -1 : 1;
        if(x == -2147483648){
            return 0;
        }
        int rem = x*sign;
        int result = 0 ;
        int maxValueB = 214748364;
        int maxRem = sign == -1 ? 8:7;

        while (rem != 0){
            int r = rem % 10;
            if (result > maxValueB || 
            (result == maxValueB && r > maxRem )){
                return 0;
            }
            result = result * 10 + r;
            rem = rem / 10;
        }
        return result*sign;
        
    }
};