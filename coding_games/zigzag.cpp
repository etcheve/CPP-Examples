// https://leetcode.com/problems/zigzag-conversion/
#include <string>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) {
        string result="";
        if (numRows == 1){
            return s;
        }
        int diff = (numRows == 2) ? 0: (numRows-2);
        
        for (int i = 0; i < numRows; ++i){
            for (int j = 0; j*(numRows+diff)+i < s.size(); ++j){
                int nextID = j*(numRows+diff)+i ;
                result+= s[nextID];
                if (i != 0 && i != numRows-1){
                    if(nextID+ (numRows-1 - i)*2  < s.size()){
                        result +=  s[nextID + (numRows-1 - i)*2 ];
                  }
                }
            }
        }
        return result;
    }
};