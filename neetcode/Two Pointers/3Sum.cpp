#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> threeSum(vector<int>& nums){
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for(int i = 0; i < nums.size()-1; i++){
        if(i > 0 && nums[i-1] == nums[i]){
            continue;
        }
        int start = i+1, end = nums.size()-1;
        while(end > start){
            int curr = nums[i] + nums[start] + nums[end];
            if(curr == 0){
                vector<int> temp = {nums[i], nums[start], nums[end]};
                 cout << i << " : " << start << " : " << end << endl;
                ans.push_back(temp);
                start++;
                end--;
                while(nums[end] == nums[end+1]) end--;
                 while(nums[start] == nums[start-1]) start++;
            }else if(curr > 0){
                end--;
            }else{
                start++;
            }
        }
    }
    return ans;
} 


int main(){
    vector<int> nums = {-2,0,0,2,2};
    vector<vector<int>> ans = threeSum(nums);
    for(vector<int> v : ans){
        for(int i : v){
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}