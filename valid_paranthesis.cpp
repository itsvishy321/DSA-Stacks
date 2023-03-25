#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0 ; i<s.length() ; i++)
        {
            // Each open bracket ( { [ is pushed into stack
            if(s[i] == '(' || s[i] == '[' || s[i] == '{')
                st.push(s[i]);
            

            // For a closed bracket if there is no open bracket present then INVALID
            else if(st.empty())
                return false;

            // For each closed the open bracket at top of the stack must be corresponding
            // Otherwise INVALID 
            else
            {
                if( (s[i] == ')' && st.top() != '(') || 
                    (s[i] == ']' && st.top() != '[') || 
                    (s[i] == '}' && st.top() != '{') )
                    return false;
                else
                    st.pop();
            }
        }

        // If stack is not empty then INVALID
        return st.empty();
    }
};

int main()
{
    Solution obj;
    string input;
    cin>>input;

    cout<<obj.isValid(input);
    
    return 0;
}