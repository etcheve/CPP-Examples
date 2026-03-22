// Cost Climbing Stairs
// https://leetcode.com/problems/min-cost-climbing-stairs/description/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2){
            std::min(cost[0],cost[1]);
        }

        int prev1= cost[0];
        int current = cost[1];
        for (int i = 2; i < n; ++i){
            int aux = current;
            current = std::min(prev1,current);
            current += cost[i];
            prev1 = aux;
        }
        return std::min(prev1, current);
        
    }
};