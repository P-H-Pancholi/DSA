#include <bits/stdc++.h>

using namespace std;

void selectionSort(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        int minIndex = i;
        // find minimum elemnt from nums[i+1...n] & swap it with i
        for(int j = i+1; j < nums.size(); j++){
            if(nums[j] < nums[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = nums[minIndex];
            nums[minIndex] = nums[i];
            nums[i] = temp;
        }
    }
}


int main() {
    vector<int> arr = {7, 5, 9, 2, 8};

    cout << "Before selection sort" << endl;
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;\

    selectionSort(arr);

    cout << "After selection sort" << endl;
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;

}