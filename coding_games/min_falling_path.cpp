// https://leetcode.com/problems/minimum-falling-path-sum/description/?envType=study-plan-v2&envId=dynamic-programming

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> cost(matrix);
        for (int i = 1; i < matrix.size(); ++i){
            cost[i][0]+=std::min(cost[i-1][0],cost[i-1][1]);
            cost[i][matrix.size()-1] += std::min(cost[i-1][matrix.size()-1],cost[i-1][matrix.size()-2]);
            for (int j = 1; j < matrix.size()-1; ++ j ){
                cost[i][j]+= std::min(std::min( cost[i-1][j],cost[i-1][j-1] ), cost[i-1][j+1]);
            }
        }
        return * min_element(cost[ matrix.size()-1].begin(),cost[ matrix.size()-1].end() );
    }
};