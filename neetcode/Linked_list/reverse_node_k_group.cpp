#include <bits/stdc++.h>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int v) : val(v), next(nullptr) {}
    ListNode(int v, ListNode* n) : val(v), next(n) {}
};
// Returns the kth node from curr, or nullptr if fewer than k nodes remain
ListNode* getkth(ListNode* curr, int k){
    while (curr && k)
    {
        curr = curr->next;
        k--;
    }
    return curr;
}

ListNode* reverseKGroup(ListNode* head, int k){
    ListNode* dummy = new ListNode(0, head);
    ListNode* prevGroup = dummy; // node just before the current k-group

    while(1){
        // Find the kth node from prevGroup — if it doesn't exist, remaining nodes < k, so we're done
        ListNode* kth = getkth(prevGroup, k);
        if(!kth){
            break;
        }

        ListNode* nextGroup = kth->next; // first node of the next k-group
        // Reverse the k nodes: prev starts at nextGroup so the reversed tail links to the next group
        ListNode* prev = kth->next;
        ListNode* curr = prevGroup->next;
        while(curr != nextGroup){
            ListNode* tmp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = tmp;
        }

        // After reversal, prevGroup->next (old first) is now the tail of this group
        ListNode* tmp = prevGroup->next;
        prevGroup->next = kth; // link previous group to the new head (kth node)
        prevGroup = tmp;       // advance prevGroup to the tail, ready for the next group
    }
    return dummy->next;
}

int main(){
    ListNode* prev = nullptr;
    int i = 5;
    while(i){
        ListNode* curr = new ListNode(i, prev);
        prev = curr;
        i--;
    }
    ListNode* curr = reverseKGroup(prev, 3);
    while(curr){
        cout << curr->val << " ";
        curr = curr->next;
    }
    return 0;
}