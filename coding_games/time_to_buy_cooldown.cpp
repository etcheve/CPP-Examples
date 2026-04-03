// https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 1) return 0;
        
        int hold = -prices[0];
        int cool = 0;
        int free_ = 0;
        
        for (int i = 1; i < n; ++i) {
            int prev_hold = hold;
            int prev_cool = cool;
            int prev_free = free_;
            
            hold  = max(prev_hold, prev_free - prices[i]);
            cool  = prev_hold + prices[i];
            free_ = max(prev_free, prev_cool);
        }
        
        return max(free_, cool);
    }
};