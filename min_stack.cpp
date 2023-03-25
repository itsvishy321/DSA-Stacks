// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

#include <bits/stdc++.h>
using namespace std;

class MinStack {
public:
    stack<int> st;
    int min;

    MinStack() {
        min = INT_MAX;    
    }
    
    void push(int val) {
        if(st.empty())
        {
            st.push(val);
            min = val;
        }

        else
        {
            if(val < min)
            {
                long long  temp = 2*val - min;
                st.push(temp);
                min = val;
            }

            else
            {
                st.push(val);
            }
        }
    }
    
    void pop() {
        if(st.top() > min)
        {
            st.pop();
        }

        else
        {
            long long  temp = 2*min - st.top();
            min = temp;
            st.pop();
        }
    }
    
    int top() {
        if(st.top() < min)
            return min;
        
        else
            return st.top();
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */ 

int main()
{
    MinStack obj;
    obj.push(5);
    obj.push(3);
    cout<<obj.top()<<endl;
    cout<<obj.getMin()<<endl;

    return 0;
}