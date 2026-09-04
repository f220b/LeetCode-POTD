// Last updated: 9/5/2026, 12:33:20 AM
class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        vector<string> result;
        result.push_back(words[0]);

        for (int i = 1; i < words.size(); ++i) {
            string prev = result.back(), curr = words[i];
            sort(prev.begin(), prev.end());
            sort(curr.begin(), curr.end());
            if (prev != curr)
                result.push_back(words[i]);
        }
        return result;
    }
};
