#include <bits/stdc++.h>

using namespace std;

void bubbleSort(vector<int> &nums){
    for(int i = 0; i < nums.size(); i++){
        bool swapped = false;
        for(int j = 0; j < nums.size()-1; j++){
            if(nums[j] > nums[j+1]){
                int temp = nums[j];
                nums[j] = nums[j+1];
                nums[j+1] = temp;
                swapped = true;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main() {
    vector<int> arr = {7, 5, 9, 2, 8};

    cout << "Before bubble sort" << endl;
    for(auto i : arr) {
        cout << i << " ";
    }
    cout << endl;

    bubbleSort(arr);

    cout << "After bubble sort" << endl;
    for(auto i : arr){
        cout << i << " ";
    }
    cout << endl;

    return 0;

}