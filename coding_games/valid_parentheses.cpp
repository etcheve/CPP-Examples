// https://leetcode.com/problems/valid-parentheses/description/
//Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> st;

        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {

                case '(':
                case '{':
                case '[':
                    st.push(s[i]);
                    break;

                case ')': {
                    if (st.empty()) return false;
                    char c = st.top();
                    st.pop();
                    if (c != '(') return false;
                    break;
                }

                case '}': {
                    if (st.empty()) return false;
                    char c = st.top();
                    st.pop();
                    if (c != '{') return false;
                    break;
                }

                case ']': {
                    if (st.empty()) return false;
                    char c = st.top();
                    st.pop();
                    if (c != '[') return false;
                    break;
                }

                default:
                    return false;
            }
        }

        return st.empty();
    }
};