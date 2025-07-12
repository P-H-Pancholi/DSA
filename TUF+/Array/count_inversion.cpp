#include <bits/stdc++.h>

using namespace std;

int merge(vector<int> &arr, int start, int mid, int end){
    int invCount = 0;
    vector<int> left(mid-start+1);
    vector<int> right(end-mid);
    for(int i = start; i <= mid; i++){
        left[i-start] = arr[i];
    }
    for(int i = mid+1; i <= end; i++){
        right[i-(mid+1)] = arr[i];
    }
    int i = 0;
    int j = 0;
    int k = start;
    while(k <= end){
        if(i >= left.size()){
            arr[k] = right[j];
            j++;
            k++;
            continue;
        }
        if(j >= right.size()){
            arr[k] = left[i];
            i++;
            k++;
            continue;
        }
        if(left[i] > right[j]){
            arr[k] = right[j];
            invCount += (left.size() - i);
            j++;
        }else{
            arr[k] = left[i];
            i++;
        }
        k++;
    }
    return invCount;
}

int mergeSort(vector<int> &arr, int start, int end){
    if(end > start){
        int mid = (start+end)/2;
        int c1 = mergeSort(arr, start, mid);
        int c2 = mergeSort(arr, mid+1, end);
        int c3 = merge(arr, start, mid, end);
        return c1+c2+c3;
    }
    return 0;
}

int main() {
    vector<int> arr = {2, 3, 7, 1, 3, 5};
    int c = mergeSort(arr, 0, arr.size()-1);
    cout << c << endl; 
    return 0;
}