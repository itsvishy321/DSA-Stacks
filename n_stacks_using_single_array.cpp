#include <bits/stdc++.h> 
using namespace std;

class NStack
{
private:
    int *arr;
    int *top;
    int *next;

    int n , s , freespot;

public:
    // Initialize your data structure.
    NStack(int N, int S)
    {
        // Write your code here.
        n = N;
        s = S;
        
        arr = new int[s];
        top = new int[n];
        next = new int[s];

        // top initialize
        for(int i=0 ; i<n ; i++)
            top[i] = -1;

        // next initalize
        for(int i=0 ; i<s ; i++)
            next[i] = i+1;
        
        // updating last value of next
        next[s-1] = -1;

        freespot = 0;

    }

    // Pushes 'X' into the Mth stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x, int m)
    {
        // check for overflow
        if(freespot == -1)
            return false;
        
        // find index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // insert in array
        arr[index] = x;

        // update next
        next[index] = top[m-1];

        // update top
        top[m-1] = index;
        
        return true;
    }

    // Pops top element from Mth Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(int m)
    {
        // check for underflow
        if(top[m-1] == -1)
            return -1;

        int index = top[m-1];

        top[m-1] = next[index];
        
        next[index] = freespot;

        freespot = index;

        return arr[index];
    }
};

int main()
{
    NStack stacks(3,6);
    
    stacks.push(10,1);
    stacks.push(15,1);

    stacks.push(20,2);
    stacks.push(25,2);
    
    stacks.push(30,3);
    stacks.push(35,3);
    stacks.push(40,3);

    cout<<stacks.pop(3)<<endl;
    cout<<stacks.pop(2)<<endl;
    cout<<stacks.pop(1)<<endl;
    cout<<stacks.pop(3)<<endl;
    cout<<stacks.pop(3)<<endl;

}