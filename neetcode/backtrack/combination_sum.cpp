#include <bits/stdc++.h>
using namespace std;

void backtrack(vector<int> &nums, vector<vector<int>> &res, vector<int> curr, int target, int index)
{
    
    int currSum = accumulate(curr.begin(), curr.end(), 0);
    if (currSum == target)
    {
        res.push_back(curr);
        return;
    }
    if (currSum > target)
    {
        return;
    }
    for(int i = index; i < nums.size(); i++){
        curr.push_back(nums[i]);
        backtrack(nums, res, curr, target, i);
        curr.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &nums, int target)
{
    vector<vector<int>> res;
    vector<int> curr;
    backtrack(nums, res, curr, target,0);
    return res;
}

int main(){
    vector<int> nums = {2,5,6,9};
    vector<vector<int>> res = combinationSum(nums, 9);
    for(vector v : res){
        cout << "[ ";
        for(int i : v){
            cout << i << " ";
        }
        cout << " ] " ;
    }
    cout << endl;
}