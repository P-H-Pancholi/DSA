#include <bits/stdc++.h>

using namespace std;


/*
------------------- Problem----------------------
input: nums=[4,5,6,7,0,1,2], k = 0
output: 4

------------------ Notes ------------------------------
whenever sorted & search is in problem desc, go for binary search

*/
int search_in_rotated_array(vector<int> nums, int k){
    // whenever we find mid, one half will be sorted other half will not be 
    // key is to find the sorted half
    int low = 0, high = nums.size()-1;
    while(low <= high){
        int mid = (low + high)/2; 
        if(nums[mid] == k){
            return mid;
        }
        // cout << "-----------------------" << endl;
        // cout << "low " << nums[low] << endl;
        // cout << "mid " << nums[mid] << endl;
        // cout << "high " << nums[high] << endl;
        // cout << "-----------------------" << endl;
        if(nums[low] <= nums[mid]){
            // left half is not sorted
            if(nums[low] <= k && k < nums[mid]){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(nums[high] >= nums[mid]){
            if(nums[high] >= k && k > nums[mid]){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
    }
    return -1;
}

/*
Problem: find min in rotated array
nums = [4,5,6,7,0,1,2,3]
Output: 0
*/

int find_min_in_rotated_array(vector<int> nums){
    int low = 0, high = nums.size()-1, ans = INT_MAX;
    while (low <= high)
    {
        int mid = (low + high)/2;
        if(nums[mid] > nums[low]){
            /*
                left part of array is sorted, so compare & store the minimum between low & ans.
                Now we need to search in right unsorted half only, as there might lie the pivot element
            */
           ans = min(ans, nums[low]);
           low = mid + 1; 
        } else {
            /*
                right part of array is sorted. so store the min & search for min in left half.
            */
           ans = min(ans, nums[mid]);
           high = mid - 1;
        }
    }
    return ans;
    
}

/*
Problem : find single element in array
A array will have pair of elements except one return that.
input:nums = [1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6]
Output:4 
*/
int singleNonDuplicate(vector<int> &nums) {
    if(nums.size() == 1) return nums[0];
    if(nums[0] != nums[1]) return nums[0];
    if(nums[nums.size()-1] != nums[nums.size()-2]) return nums[nums.size()-1];
    int low = 1, high = nums.size()-2;
    while(low <= high){
        int mid = (high+low)/2;
        if(nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
        if(mid%2 == 0){
            // mid is even, so if mid occurs before single element,
            // duplicate should be at mid+1.
            if(nums[mid] == nums[mid+1]){
                // Eliminate left half
                low = mid+1;
            }else{
                // Eliminate right half
                high = mid-1;
            }
        } else {
            if(nums[mid] == nums[mid-1]){
                low = mid+1;
            }else{
                // Eliminate right half
                high = mid-1;
            }
        }
    }
    return -1;
}

int main() {
    vector<int> nums = {4,5,6,7,0,1,2};
    int k = 0;
    cout << search_in_rotated_array(nums, k) << endl;
    k = 5;
    cout << search_in_rotated_array(nums, k) << endl;
    cout << find_min_in_rotated_array(nums) << endl;
    vector<int> nums1 = {4, 5, 6, 7, -7, 1, 2, 3};
    cout << find_min_in_rotated_array(nums1) << endl;
    return 0;
}