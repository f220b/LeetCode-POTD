// Last updated: 4/3/2026, 1:51:38 PM
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq;
        for (char c : word)
            freq[c]++;

        vector<int> freqList;
        for (auto &p : freq)
            freqList.push_back(p.second);

        sort(freqList.begin(), freqList.end());
        int n = freqList.size();
        int result = INT_MAX;

        // Try each freqList[i] as minFreq
        for (int i = 0; i < n; i++) {
            int minFreq = freqList[i];
            int maxFreq = minFreq + k;
            int deletions = 0;

            for (int j = 0; j < n; j++) {
                if (freqList[j] < minFreq)
                    deletions += freqList[j]; // delete all
                else if (freqList[j] > maxFreq)
                    deletions += freqList[j] - maxFreq; // trim excess
            }

            result = min(result, deletions);
        }

        return result;
    }
};
