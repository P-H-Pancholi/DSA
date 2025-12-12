#include <bits/stdc++.h>

using namespace std;

int characterReplacement(string s, int k) {
    int left = 0, right = 0, maxLength = 0;
    vector<int> freq_map(26, 0);
    
    while(right < s.size()){
        // Add current character first
        freq_map[s[right] - 'A']++;
        
        // Find max frequency
        int max_freq = 0;
        for(int count : freq_map){
            max_freq = max(count, max_freq);
        }
        
        // Shrink if invalid
        while((right - left + 1) - max_freq > k){
            freq_map[s[left] - 'A']--;
            left++;
        }
        
        // Update max (window is guaranteed valid here)
        maxLength = max(maxLength, right - left + 1);
        
        // Expand window
        right++;
    }
    
    return maxLength;
}
/*
**Why we don't decrease `max_freq` when shrinking:**
- It's an optimization trick
- We only care about finding LONGER valid windows
- If window shrinks, we won't get a better answer anyway
- This keeps time complexity strictly O(n)
*/
int main() {
    string s = "XYYX";
    int k = 2;
    cout << characterReplacement(s,k) << endl;
}