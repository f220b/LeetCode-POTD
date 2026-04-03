// Last updated: 4/3/2026, 1:53:17 PM
class Solution {
public:
    string robotWithString(string s) {
        int n = s.size();
        vector<char> min_suffix(n);
        min_suffix[n - 1] = s[n - 1];
        
        // Fill suffix min array
        for (int i = n - 2; i >= 0; --i) {
            min_suffix[i] = min(s[i], min_suffix[i + 1]);
        }

        string result;
        stack<char> t;

        for (int i = 0; i < n; ++i) {
            t.push(s[i]);

            // Pop from stack if it's ≤ min char remaining in s
            while (!t.empty() && (i == n - 1 || t.top() <= min_suffix[i + 1])) {
                result += t.top();
                t.pop();
            }
        }

        // Empty remaining stack
        while (!t.empty()) {
            result += t.top();
            t.pop();
        }

        return result;
    }
};
