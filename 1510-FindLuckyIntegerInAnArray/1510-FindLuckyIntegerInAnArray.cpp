// Last updated: 4/3/2026, 1:56:47 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> freq;
        
        // Step 1: Count frequency
        for (int x : arr) {
            freq[x]++;
        }
        
        int ans = -1;

        // Step 2: Check lucky integers
        for (auto it : freq) {
            if (it.first == it.second) {
                ans = max(ans, it.first);
            }
        }
        
        return ans;
    }
};
