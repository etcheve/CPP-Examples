// https://leetcode.com/problems/unique-paths/description/?envType=study-plan-v2&envId=dynamic-programming
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        std::vector<std::vector<int>> poss(m+1, std::vector<int>(n+1, 0));
        poss[0][1]=1;
        for (int i = 1; i <= m; ++i){
            for (int j = 1; j <= n; ++j){
                poss[i][j]= poss[i-1][j]+poss[i][j-1];
            }
        }
        return poss[m][n];
    }
};