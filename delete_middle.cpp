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


// FUNCTION TO DELETE THE MIDDLE NODE OF THE STACK
stack<int> deleteMiddle(stack<int> st)
{
    int middle = st.size()/2;
    stack<int> temp;
    for(int i=0 ; i<middle ; i++)
    {
        temp.push(st.top());
        st.pop();
    }
    st.pop();
    while(!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
    }
    return st;
}


int main()
{
    stack<int> st;
    for(int i=1 ; i<20 ; i++)
        st.push(i);
    
    cout<<"Original Stack"<<endl;
    displayStack(st);

    st = deleteMiddle(st);
    cout<<endl<<"Resulted stack"<<endl;
    displayStack(st);

    return 0;
}