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

// FUNCTIONS TO SORT A STACK

void insertAtPos(stack<int> &st , int x)
{
    if(st.empty() || st.top()<=x)  // Condition where x needs to be pushed
    {
        st.push(x);
        return;
    }
    
    int temp = st.top();
    st.pop();
    insertAtPos(st,x);
    st.push(temp);
}


void sortStack(stack<int> &st)
{
    if(st.empty())
        return;

    int temp = st.top();  // storing the top value
    st.pop();  // poping the top value
    sortStack(st); // getting the sorted stack via recursive call
    insertAtPos(st , temp); // Inserting the value at correct position
}

int main()
{
    stack<int> st;
    st.push(3);
    st.push(-2);
    st.push(7);
    st.push(8);
    st.push(1);
    
    cout<<"Original Stack"<<endl;
    displayStack(st);

    sortStack(st);
    cout<<endl<<"Sorted stack"<<endl;
    displayStack(st);
    return 0;
}