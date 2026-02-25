#include <bits/stdc++.h>
using namespace std;



// Process the most frequent element first.
// Use max heap to pop the max frequent element
// add the next element to the queue with the time available for that element
// i.e. curr_time + n.
int leastInterval(vector<char>& tasks, int n){
    unordered_map<char,int> freq_map;
    for(char c : tasks){
        freq_map[c]++;
    }
    priority_queue<int> pq;
    for(auto it : freq_map){
        pq.push(it.second);
    }
    queue<pair<int,int>> q;
    int time = 0;
    while(!pq.empty() || !q.empty()){
        if(!pq.empty()){
            int curr = pq.top(); pq.pop();
            curr--;
            if(curr > 0){
                q.push({curr, time+n});
            }
        }
        if(!q.empty()){
            if(q.front().second == time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        time++;
    }
    return time;
}



int main(){
    vector<char> tasks = {'A','C','A','B','D','B'};
    int n = 1;
    cout << leastInterval(tasks, n) << endl;
    return 0;
}