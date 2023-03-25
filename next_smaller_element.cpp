#include <bits/stdc++.h>
using namespace std;


// Function for next smaller element
vector<int> nextSmallerElement(vector<int> nums)
{
    stack<int> st;
    vector<int> ans(nums.size());

    st.push(-1);

    for(int i = nums.size()-1 ; i>=0 ; i--)
    {
        int curr = nums[i];

        while (st.top() >= curr)
        {
            st.pop();
        }
        
        // stack ka top is the next smaller element
        ans[i] = st.top();
        st.push(curr);
    }

    return ans;
}

int main()
{
    vector<int> v = {3,4,1,2};
    
    vector<int> res = nextSmallerElement(v);
    for(int i : res)
        cout << i << " ";
    
    return 0;
}