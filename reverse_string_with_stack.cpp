#include <iostream>
#include <stack>
using namespace std;


// FUNCTION TO REVERSE A GIVEN STRING USING STACK
string reverseString(string str)
{
    string result;
    stack<char> st;

    // pushing values in stack from index 0 to last
    for(int i=0 ; i<str.length() ; i++)
    {
        st.push(str[i]);
    }

    // poping the values from stack and pushing in result 
    while(!st.empty())
    {
        result.push_back(st.top());
        st.pop();
    }

    return result;
}

int main()
{
    string str = "vishal";
    str = reverseString(str);

    cout<<"Reversed String: "<<str<<endl;

    return 0;
}