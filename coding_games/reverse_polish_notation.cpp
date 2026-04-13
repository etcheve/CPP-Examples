// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

#include <vector>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> myStack;
        for (const string s : tokens){
        if (s == "+" || s== "-" || s== "*" || s=="/"){
            int a = myStack.top();
            myStack.pop();
            int b = myStack.top();
            myStack.pop();
            int result=0;
            if(s == "+" ){
                result = a+b;
            }
            if(s == "*" ){
                result = a*b;
            }
            if(s == "-" ){
                result = b-a;
            }
            if(s == "/" ){
                result = b/a;
            }
            myStack.push(result);
        }else{
            myStack.push(stoi(s));
        }
        }
        return myStack.top();
        
    }
};