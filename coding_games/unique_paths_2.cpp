// https://leetcode.com/problems/unique-paths-ii/?envType=study-plan-v2&envId=dynamic-programming
#include<vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        std::vector<std::vector<int>> poss(rows, std::vector<int>(cols, 0));
        
        if(obstacleGrid[0][0]==1){
            return 0;
        }
        poss[0][0]= obstacleGrid[0][0] == 1 ? 0 :1;

        for (int i = 1; i < rows; ++i){
            poss[i][0] = obstacleGrid[i][0] == 1 ? 0 : poss[i-1][0];
        }
        for (int j = 1; j < cols; ++j){
            poss[0][j] = obstacleGrid[0][j] == 1 ? 0 : poss[0][j-1];
        }

        for (int i = 1 ; i < rows ; ++i){
            for (int j = 1 ; j < cols; ++j){
                    if(obstacleGrid[i][j] == 1){
                        poss[i][j]=0;
                    }else{
                        poss[i][j]=poss[i-1][j] + poss[i][j-1];
                    }
            }
        }
        return poss[rows-1][cols-1];
    }
};