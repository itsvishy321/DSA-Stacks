//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
/*You are required to complete this method*/

class Solution{
  public:
    
    vector<int> nextSmaller(vector<int> v , int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i=n-1 ; i>=0 ; i--)
        {
            while(st.top() != -1 && v[st.top()] >= v[i])
                st.pop();

            ans[i] = st.top();
            st.push(i); // pushing the index of curr element
        }

        return ans;
    }
    
    vector<int> prevSmaller(vector<int> v , int n)
    {
        vector<int> ans(n);
        stack<int> st;
        st.push(-1);

        for(int i=0 ; i<n ; i++)
        {
            while(st.top()!= -1 && v[st.top()] >= v[i])
                st.pop();
            
            ans[i] = st.top();
            st.push(i); // pushing the index of curr element
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        // finding index of next smaller element for each element
        vector<int> next = nextSmaller(heights , heights.size());
        
        // finding index of prev smaller element for each element
        vector<int> prev = prevSmaller(heights , heights.size());

        int maxArea = INT_MIN;
        int area;

        for(int i=0 ; i<n ; i++)
        {
            int h = heights[i];

            // if there exist no next smaller element for an element
            // then width will expand till last index towards right side
            if(next[i] == -1)
                next[i] = n;

            int b = next[i] - prev[i] - 1;
            area = h * b;

            maxArea = max(maxArea , area);
        }

        return maxArea;
    }
    
    int maxArea(int M[4][4], int n, int m) {
        vector<int> heights(m);
        int maxResult;
        
        // Finding max area of rectangle from 1st row
        for(int i=0 ; i<m ; i++)
        {
            heights[i] = M[0][i];
        }
        
        maxResult = largestRectangleArea(heights);
        
        // Now for each subsequent row making histograms by adding heights from previous histogram
        for(int i=1 ; i<n ; i++)
        {
            for(int j=0 ; j<m ; j++)
            {
                if(M[i][j] == 0)
                    heights[j] = 0;
                
                else
                    heights[j] += 1;
            }
            
            int maxArea = largestRectangleArea(heights);
            maxResult = max(maxResult , maxArea);
        }
        
        return maxResult;
    }
};


//{ Driver Code Starts.
int main() {
    int M[4][4];
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> M[i][j];
        }
    }
    Solution obj;
    cout << obj.maxArea(M, n, m) << endl;
}

// } Driver Code Ends