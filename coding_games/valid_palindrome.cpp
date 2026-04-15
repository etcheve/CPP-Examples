// https://leetcode.com/problems/valid-palindrome/
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        // clean sctring
        string mys ="";
        for (char c : s) {
            if (isalnum(c)) mys += tolower(c);  // keeps letters AND digits
        }
        
        int n= mys.size();
        if (n <2){
            return true;
        }

        for (int i = 0 ; 2*i<=n-1;++i){
            if(mys[i]!=mys[n-i-1]){
                return false;
            }
        }  

        return true;
    }
};