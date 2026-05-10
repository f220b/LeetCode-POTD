// Last updated: 10/5/2026, 10:18:31 am
class Solution {
public:
    vector<int> countWordOccurrences(vector<string>& chunks,
                                     vector<string>& queries) {
        string s = "";
        for (string str : chunks)
            s += str;

        int n = s.length();
        string temp = "";
        unordered_map<string, int> mpp;
        for (int i = 0; i < n; i++) {
            if (islower(s[i]))
                temp += s[i];
            else if (s[i] == '-' && i > 0 && i < n - 1 && islower(s[i - 1]) &&
                     islower(s[i + 1]))
                temp += s[i];
            else {
                if (!temp.empty()) {
                    mpp[temp]++;
                    temp = "";
                }
            }
        }
        if (!temp.empty()) {
            mpp[temp]++;
        }
        vector<int> answer;
        for (string query : queries)
            answer.push_back(mpp[query]);

        return answer;
    }
};