//https://leetcode.com/problems/longest-common-prefix/description/

/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".
*/
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        int j = 0;
        char a ;
        if (strs.empty()){
            result;
        }
        while(1){
            for(int i = 0; i < strs.size();++i){
                if (strs[i].size() <= j){
                 return result;
                }
                if (i == 0){
                    a =  strs[i][j];
                }else{
                    if( strs[i][j] != a){
                        return result;
                    }
                } 
            }
            result += strs[0][j];
                        ++j;
        }
        return result;
        
    }
};