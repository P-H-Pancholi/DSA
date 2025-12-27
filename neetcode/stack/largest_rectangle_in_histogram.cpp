#include <bits/stdc++.h>
using namespace std;


int largestRectangleArea(vector<int>& heights) {
    stack<pair<int,int>> st;
    int res = 0, i = 0;
    while(i < heights.size()){
        int index = i; // for tracking the extension to the left
        while(!st.empty() && st.top().second > heights[i]){
            // If heights aren't in increasing order, they will be popped
            int curr_index = st.top().first, curr_height = st.top().second;
            // calculate max before popping
            res = max(res, (i-curr_index)*curr_height); // curr_height can be extended till i
            st.pop();
            index = curr_index; // i can be extended on the left
        }
        st.push({index, heights[i]});
        i++;
    }
    while (!st.empty())
    {
        // the heights in stack can be extended till the end
        int curr_index = st.top().first, curr_height = st.top().second;
        res = max(res, (i-curr_index)*curr_height);
        st.pop();
    }
    return res;
}

int main(){
    vector<int> heights = {7,1,7,2,2,4};
    cout << largestRectangleArea(heights) << endl;
    return 0;
}