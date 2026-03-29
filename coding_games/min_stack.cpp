// https://leetcode.com/problems/min-stack/description/

#include <stack>
using namespace std;

class MinStack {

private :
    stack<pair<int,int>> myStack;
    int elements = 0;
public:

    MinStack() {
        
    }
    
    void push(int val) {
        if (elements == 0){
            myStack.push({val,val});
        }else{
            myStack.push({val, min(myStack.top().second, val )});
        }
        ++elements;
    }
    
    void pop() {
        --elements;
        myStack.pop();
    }
    
    int top() {
        return myStack.top().first;
    }

    
    int getMin() {
        return myStack.top().second;
    };
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */