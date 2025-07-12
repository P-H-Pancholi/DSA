#include <bits/stdc++.h>

using namespace std;

int secondLargestElement(vector<int>& nums) {
    //your code goes here
    int largest, secondLargest;
    largest = INT_MIN;
    secondLargest = INT_MIN;
    
    for(int i = 0; i < nums.size(); i++){
        cout << "current element " << nums[i] << endl;
        cout << "largest element " << largest << endl;
        cout << "second largest element " << secondLargest << endl;
        cout << "-------------------------" << endl;
        if(nums[i] > largest){
            secondLargest = largest;
            largest = nums[i];
        }else if(nums[i] > secondLargest && nums[i] != largest) {
            secondLargest = nums[i];
        }
    }
    if(secondLargest == INT_MIN){
        return -1;
    }
    return secondLargest;
      
}

int main() {
    vector<int> nums = {8, 8, 7, 6, 5};
    cout << secondLargestElement(nums) << endl;
    return 0;
}