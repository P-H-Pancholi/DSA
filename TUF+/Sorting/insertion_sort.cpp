#include <bits/stdc++.h>

using namespace std;

void insertionSort(vector<int> &nums){
    for(int i = 1; i < nums.size(); i++){
        int curr = nums[i];

        int j = i-1; // nums[0...i-1] will be sorted.
        while(j >= 0 && nums[j] > curr){ // find curr element position in sorted nums list
            nums[j+1] = nums[j];
            j--;
        }
        nums[j+1] = curr;
    }
}



int main(){
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    cout << "before insertion sort" << endl;

    for(auto i : nums){
        cout << i << " ";
    }
    cout << endl;

    insertionSort(nums);

    cout << "after insertion sort" << endl;

    for(auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}