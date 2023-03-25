#include <iostream>
using namespace std;

class twoStack
{
public: 
    int *arr;
    int top1;
    int top2;
    int size;

    // constructor
    twoStack(int size)
    {
        this->size = size;
        top1 = -1;
        top2 = size;
        arr = new int[size];
    }

    // Push in satck 1
    void push1(int val)
    {
        if(top1+1 != top2)
        {
            top1++;
            arr[top1] = val;
        }
        else
            cout<<"Stack 1 Overlow"<<endl;
    }

    // Push in stack 2
    void push2(int val)
    {
        if(top2-1 != top1)
        {
            top2--;
            arr[top2] = val;
        }
        else    
            cout<<"Stack 2 Overflow"<<endl;
    }

    // Pop from stack 1
    void pop1()
    {
        if(top1 == -1)
            cout<<"Stack 1 Underflow"<<endl;
        else
            top1--;
    }

    // Pop from stack 2
    void pop2()
    {
        if(top2 == size)
            cout<<"Stack 2 Underflow"<<endl;
        else
            top2++;
    }

    // Peek on stack 1
    int peek1()
    {
        if(top1 == -1)
            cout<<"Stack 1 is Empty"<<endl;
        else
            return arr[top1];
    }
    
    // Peek on stack 2
    int peek2()
    {
        if(top2 == size)
            cout<<"Stack 2 is Empty"<<endl;
        else
            return arr[top2];
    }

    // Is Empty on stack 1
    bool isEmpty1()
    {
        if(top1 == -1)
            return true;
        else
            return false;
    }

    // Is Empty on stack 2
    bool isEmpty2()
    {
        if(top2 == size)
            return true;
        else
            return false;
    }
};

int main()
{
    twoStack st(10);

    st.push1(1);
    st.push1(2);
    st.push1(3);
    st.push1(5);
    st.push1(6);
    st.push1(4);

    st.push2(8);
    st.push2(7);
    st.push2(9);
    st.push2(10);
    st.push2(11);

    st.pop2();
    st.pop2();
    st.pop2();
    
    cout<<st.peek1()<<endl;
    cout<<st.peek2()<<endl;
    st.pop2();

    cout<<st.isEmpty2()<<endl;

    return 0;
}