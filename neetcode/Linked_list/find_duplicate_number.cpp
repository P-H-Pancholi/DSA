#include <bits/stdc++.h>
using namespace std;

// We will use linked list cycle & Floyd's algorithm for O(n) time and O(1) space complexity
int findDuplicate(vector<int>& nums) {
    // Imagine the array index i as node, pointing to the index = nums[i]
    // The repeating number index will have more than one nodes incoming.
    // repeating number node will be start of cycle.
    int slow = nums[0], fast = nums[nums[0]];
    while(slow != fast){
        slow = nums[slow];
        fast = nums[nums[fast]];
    }
    // Floyd's algorithm: Once we get intersecting pointer, than we can start two pointers
    // one from index 0 another one is continue the slow pointer, once they meet, the node will be start of cycle.
    int start = 0;
    while(start != slow){
        start = nums[start];
        slow = nums[slow];
    }
    return start;
}

int main(){

}