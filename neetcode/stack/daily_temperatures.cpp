#include <bits/stdc++.h>

using namespace std;

vector<int> dailyTemperatures(vector<int>& temperatures) {
    stack<int> st;
    st.push(0);
    vector<int> res(temperatures.size(), 0);
    for(int i = 1; i < temperatures.size(); i++) {
        cout << st.top() << endl;
        while (!(st.empty()) && (temperatures[st.top()] < temperatures[i])){
            int curr = st.top();
            res[curr] = i-curr;
            st.pop();
        }
        st.push(i);
    }
    return res;
}

int main(){
    vector<int> arr = {30,38,30,36,35,40,28};
    vector<int> res = dailyTemperatures(arr);
    for(int i : res){
        cout << i << " ";
    }
    cout << endl;
    return 0;
}