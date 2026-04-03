// Last updated: 4/3/2026, 1:55:43 PM
class Solution {
public:
    int maximumGain(string s, int x, int y) {
        char first = (x > y) ? 'a' : 'b';
        char second = (x > y) ? 'b' : 'a';
        int high = max(x, y), low = min(x, y);
        int maxGain = 0;

        stack<char> st1;
        for (char c : s) {
            if (!st1.empty() && st1.top() == first && c == second) {
                st1.pop();
                maxGain += high;
            } else {
                st1.push(c);
            }
        }

        string rem = "";
        while (!st1.empty()) {
            rem += st1.top();
            st1.pop();
        }

        for (int i = rem.length() - 1; i >= 0; i--) {
            char c = rem[i];
            if (!st1.empty() && st1.top() == second && c == first) {
                st1.pop();
                maxGain += low;
            } else {
                st1.push(c);
            }
        }

        return maxGain;
    }
};
