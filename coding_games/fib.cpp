// https://leetcode.com/problems/fibonacci-number/?envType=study-plan-v2&envId=dynamic-programming

class Solution {
public:
    int fib(int n) {
        if (n <= 1) return n;

        int prev = 0, curr = 1;
        for (int i = 1; i < n; ++i) {
            curr += prev;
            prev = curr - prev;
        }
        return curr;
    }
};