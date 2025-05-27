#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &nums, int start, int end){
    // partition the array around index i such that 
    // A[start..i-1] < pivot
    // A[i+1..end] > pivot
    int pivot = nums[end];
    int i = start-1;
    for(int j = start; j <= end; j++){
        if(nums[j] < pivot){
            i++;
            int temp = nums[j];
            nums[j] = nums[i];
            nums[i] = temp;
        }
    }
    nums[end] = nums[i+1];
    nums[i+1] = pivot;
    return i+1;
}


void quickSort(vector<int> &nums, int start, int end){
    if(start < end){
        int pivot = partition(nums, start, end);
        quickSort(nums, start, pivot-1);
        quickSort(nums, pivot+1, end);
    }
}

int main() {
    vector<int> arr = {4, 6, 2, 5, 7, 9, 1, 3};
    int n = arr.size();

    cout << "Before Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, 0, arr.size()-1);

    cout << "After Sorting Array: " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}