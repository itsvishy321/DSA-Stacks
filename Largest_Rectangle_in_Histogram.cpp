// Given an array of integers heights representing the histogram's bar 
// height where the width of each bar is 1, 
// return the area of the largest rectangle in the histogram.

#include <bits/stdc++.h>
using namespace std;

class Solution {
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
};

int main()
{
    Solution obj;
    vector<int> heights = {2,1,5,6,2,3};
    
    int res =  obj.largestRectangleArea(heights);

    cout<<"Area of Largest Rectangle : "<<res;
    return 0;
}   