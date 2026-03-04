// https://leetcode.com/problems/string-to-integer-atoi/description/
#include <string>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int sign = 1;
        int result= 0;
        const int minRem= 8;
        const int maxInt= 214748364;
        int maxRem= 7;


        // ignore leadign white space
        int j = 0;
        while (j < s.size() && s[j] == ' ' ){
            ++j;
        }
        for (int i = j ; i < s.size(); ++i){
            if(s[i] == '-' && i == j){
                sign =-1;
                maxRem = minRem;
                continue;
            }
            if(s[i] == '+' && i == j){
                continue;
            }
            int newv = 0;
            switch(s[i]) {
                case '1':
                newv = 1;
                break;

                case '2':
                newv =  2;
                break;

                case '3':
                newv =  3;
                break;

                case '4':
                newv =  4;
                break ;

                case '5':
                newv =  5;
                break ;

                case '6':
                newv =  6;
                break ;

                case '7':
                newv =  7;
                break ;

                case '8':
                newv =  8;
                break ;

                case '9':
                newv =  9;
                break ;

                case '0':
                newv =  0;
                break ;
                
                default:
                return result * sign;

            }
            // Round
            if (result > 214748364 || 
            (result == 214748364 && newv >= maxRem )){
                return sign ==  -1 ? -2147483648 : 2147483647;

            }
            result = 10*result + newv;

        }
        return result * sign;
    }
};