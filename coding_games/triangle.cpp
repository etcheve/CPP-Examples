// https://leetcode.com/problems/triangle/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {

        std::vector<std::vector<int>> cost(triangle);
        cost[0][0] = triangle[0][0];
        int n = triangle.size();
        for(int i = 1; i < triangle.size(); ++i){
            cost[i][0]=cost[i-1][0]+ triangle[i][0];
            cost[i][i] = cost[i-1][i-1]+triangle[i][i];

            for (int j = 1; j < i; ++j ){
                cost[i][j]=std::min(cost[i-1][j], cost[i-1][j-1])+ triangle[i][j];
            }
        }
        return *std::min_element(cost[n-1].begin(),cost[n-1].end());
        
    }
};