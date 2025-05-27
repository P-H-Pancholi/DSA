#include <bits/stdc++.h>

using namespace std;


void merge(vector<int> &arr, int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    vector<int> leftArray(leftSize);
    vector<int> rightArray(rightSize);

    // populate left and right array
    for(int i = 0; i < leftSize; i++){
        leftArray[i] = arr[start+i];
    }

    for(int i = 0; i < rightSize; i++){
        rightArray[i] = arr[mid+i+1];
    }

    // compare and combine
    int i = 0;
    int j = 0;
    int k = start;
    while(i < leftSize && j < rightSize){
        if(leftArray[i] < rightArray[j]){
            arr[k] = leftArray[i];
            i++;
        }else{
            arr[k] = rightArray[j];
            j++;
        }
        k++;
    }

    while(i < leftSize){
        arr[k] = leftArray[i];
        i++;
        k++;
    }

    while(j < rightSize){
        arr[k] = rightArray[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int> &arr, int start, int end){
    if(end > start){
        int mid = (end+start)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
    }
}

int main(){
    vector<int> nums = {13, 46, 24, 52, 20, 9};

    cout << "Before merge sort" << endl;

    for(auto i : nums){
        cout << i << " ";
    }
    cout << endl;

    mergeSort(nums, 0, nums.size()-1);

    cout << "After merge sort" << endl;

    for(auto i : nums) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}