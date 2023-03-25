/*
Given valid mathematical expressions in the form of a string. 
You are supposed to return true if the given expression contains a pair of redundant brackets, 
else return false. The given string only contains '(',')+ART and lowercase English letters.
Note:
A pair of brackets is said to be redundant when a subexpression is surrounded 
by needless/ useless brackets.
For Example:
((a+b)) has a pair of redundant brackets. The pair of brackets on the 
first and last index is needless. While (a + (b*c)) does not have any pair of 
redundant brackets.
*/

#include <iostream>
#include <stack>
using namespace std;

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    for(char ch:s)
    {
        // Adding each opening bracket and an operator into the stack
        if(ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
            st.push(ch);

        // For every closing bracket checking the top of the stack 
        else if(ch == ')')
        {
            // if top is opening bracket then redundant brackets are present
            if(st.top() == '(')
                return true;
            else
            {
                while(st.top() != '(')
                    st.pop();
                st.pop();
            }
        }
    }

    // No redundant brackets are present
    return false;

}

int main()
{
    string s = "(c)";
    bool result = findRedundantBrackets(s);
    if(result)
        cout<<"Contains Redundant Brackets"<<endl;
    else
        cout<<"Contains NO Redundant Brackets"<<endl;

    return 0;
}