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

int main()
{
    stack<int> st;
    for(int i=1 ; i<=5 ; i++)
        st.push(i);
    
    cout<<"Before"<<endl;
    displayStack(st);
    
    int x = 99;    
    insertBottom(st , x);

    cout<<endl<<"AFter"<<endl;
    displayStack(st);
    
    return 0;
}