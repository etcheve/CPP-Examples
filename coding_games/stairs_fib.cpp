// https://leetcode.com/problems/climbing-stairs/description/

/*
You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n == 1 ) {return 1;}
        if (n == 2 ){return 2;}
        int val = 2;
    int prev =1;
    int aux = 0;
    for (int i = 2 ; i < n ; ++ i){
        aux = val;
        val = val+prev;
        prev =aux;
    }
    return val;
    }
};


