//https://leetcode.com/problems/best-time-to-buy-and-sell-stock/description/
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<1){
            return 0;
        }
        int profit = 0 ; 
        int buyIndx=0;
        int sellIdx =1;
        while (sellIdx < prices.size()){
            int newProfit = prices[sellIdx] - prices[buyIndx];
            if(newProfit < 0){
               buyIndx = sellIdx;
                ++sellIdx;
                continue;
            }
            profit = max(profit,newProfit);
            ++sellIdx;
        }
        return profit;

 
        
    }
};