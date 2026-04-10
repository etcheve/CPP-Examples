// https://leetcode.com/problems/search-a-2d-matrix/description/

#include <vector>
using namespace std;    
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int col = matrix[0].size();
       int row = matrix.size();
       int left = 0;
       int right = col*row-1; 
        while (left <= right ){
            int pos = (right + left) / 2;
            int posr = pos / col;
            int posc = pos % col;
            if( matrix [posr][posc] == target){
                return true;
            }
            if (matrix [posr][posc] < target){
                left = pos+1;
            }
            else{
                right = pos-1;
            }

        }
       return false;

    }
};