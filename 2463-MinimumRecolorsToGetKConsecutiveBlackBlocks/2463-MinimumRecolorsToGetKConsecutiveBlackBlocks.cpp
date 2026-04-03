// Last updated: 4/3/2026, 1:53:28 PM
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0, right = 0;
        unordered_map<char, int> freq;
        int minCount = INT_MAX;
        while(right < blocks.size()) {
            freq[blocks[right]]++;
            if(freq['B'] + freq['W'] == k) {
                minCount = min(minCount, freq['W']);
                freq[blocks[left]]--;
                left++;
            }
            right++;
        }
        return minCount;
    }
};