//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        
        // Push all the elements in stack
        for(int i=0 ; i<n ; i++)
            st.push(i);
        
        while(st.size() > 1)
        {
            int a = st.top(); 
            st.pop();
            
            int b = st.top();
            st.pop();
            
            if(M[a][b] == 1 && M[b][a] == 0)
                st.push(b);
            
            if(M[a][b] == 0 && M[b][a] == 1)
                st.push(a);
        }
        
        if(st.empty())
            return -1;
        
        // Remaining one element in the stack is a potential celebrity
        int potential = st.top();
        
        // Checking whether potential knows no one
        for(int i=0 ; i<n ; i++)
        {
            if(potential != i && M[potential][i] == 1)
                return -1;
        }
        
        // Checking whether Everyone knows potential
        for(int i=0 ; i<n ; i++)
        {
            if(potential != i && M[i][potential] == 0)
                return -1;
        }
        
        return potential;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends