// https://leetcode.com/problems/n-th-tribonacci-number/?envType=study-plan-v2&envId=dynamic-programming
class Solution {
public:
    int tribonacci(int n) {
        int prev2 = 0;
        int prev1 = 1;
        int current = 1;
        if (n == 0){
            return 0;
        }
        if (n == 1){
            return 1;
        }
        if (n == 2){
            return 1;
        }
        for (int i = 2; i < n ; ++i){
            int aux = current;
            current += (prev1+prev2);
            prev2 = prev1;
            prev1 = aux;
        }
            return current;
    }
};