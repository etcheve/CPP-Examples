// https://leetcode.com/problems/range-sum-query-2d-immutable/
#include <vector>
using namespace std;
class NumMatrix {
public:
    vector<vector<int>> prec_;
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size()+1;
        int n = matrix[0].size()+1;
        prec_.assign(m , vector<int>(n, 0));
        for (int i = 1 ; i < m ; ++i){
            for (int j = 1; j < n; ++j){
              prec_[i][j] = matrix[i-1][j-1] 
                            + prec_[i-1][j] 
                            + prec_[i][j-1]
                            - prec_[i-1][j-1]; 
            }
        }

    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int totalSum = prec_[row2+1][col2+1] 
                    - prec_[row1][col2+1]
                    - prec_[row2+1][col1]
                    + prec_[row1][col1];
                
    return totalSum;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */