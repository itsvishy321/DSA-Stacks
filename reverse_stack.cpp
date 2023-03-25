#include <iostream>
#include <stack>
using namespace std;

// Function to display a stack
void displayStack(stack<int> st)
{
    while (!st.empty())
    {
        cout<<st.top()<<endl;
        st.pop();
    }
}

// Recursive function to insert an element at the bottom in the same stack
void insertBottom(stack<int> &st , int x)
{
    // Base case
    if(st.empty())
    {
        st.push(x);
        return;
    }
    int temp = st.top();
    st.pop();
    insertBottom(st , x);
    st.push(temp);
}

// FUNCTION TO REVERSE A STACK USING RECURSION
stack<int> reverseStack(stack<int> st)
{
    if(st.empty())
        return st;

    int temp = st.top();
    st.pop();
    st = reverseStack(st);
    insertBottom(st , temp);
    return st;
}

int main()
{
    stack<int> st;
    for(int i=1 ; i<=5 ; i++)
        st.push(i);
    cout<<"Before"<<endl;
    displayStack(st);

    st = reverseStack(st);
    
    cout<<"After"<<endl;
    displayStack(st);

    return 0;
}