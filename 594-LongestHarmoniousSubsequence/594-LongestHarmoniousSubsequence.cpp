// Last updated: 4/3/2026, 1:59:33 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxLen = 0;
        for (auto& it : freq) {
            int num = it.first;
            if (freq.count(num + 1)) {
                maxLen = max(maxLen, freq[num] + freq[num + 1]);
            }
        }

        return maxLen;
    }
};
