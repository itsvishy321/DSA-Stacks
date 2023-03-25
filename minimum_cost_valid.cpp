/*
Given an invalid string (brackets are not balanced)
in one move you can change '(' to ')' or vice versa

cost for one move is 1

Determine the minimum cost to make the string valid
*/

#include <iostream>
#include <stack>
using namespace std;

// FUNCTION TO RETURN MINIMUM COST TO MAKE THE STRING VALID
int minCost(string s)
{
    // check for odd length string or not
    if(s.length()%2 == 1)
        return -1;
    
    // removing the valid part from the string

    stack<char> st;
    for(char ch : s)
    {
        if(ch == '(')
        {
            st.push(ch);
        }
        
        else
        {
            if(!st.empty() && st.top() == '(')
            {
                st.pop();
            }

            else
                st.push(ch);
        }
    }

    // Now stack contains invalid expression
    int openCount = 0;
    int closeCount = 0;
    while(!st.empty())
    {
        if(st.top() == '(')
            openCount++;
        else
            closeCount++;
        
        st.pop();
    }

    int ans = (openCount+1)/2 + (closeCount+1)/2;
    return ans;
}

int main()
{
    string s = "{{{}";
    
    int res = minCost(s);

    cout<<res<<endl;

    return 0;
}