// https://leetcode.com/problems/maximal-square/description/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<int>> res(m+1,vector<int>(n+1,0));
        int max_ = 0;
        for (int i = 1; i <= m ; ++i){
            for (int j = 1; j <= n; ++j ){
                if (matrix[i-1][j-1] == '0'){
                    res[i][j]= 0;
                    continue;
                }
                res[i][j] = 1 + min(min(res[i-1][j-1],res[i][j-1]), res[i-1][j]);
                max_ = max(max_,res[i][j]);
            }
        }
        return max_*max_;
    }
};