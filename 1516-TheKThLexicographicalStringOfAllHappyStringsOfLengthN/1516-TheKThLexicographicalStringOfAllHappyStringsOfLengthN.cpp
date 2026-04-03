// Last updated: 4/3/2026, 1:56:45 PM
class Solution {
public:
    string res = "";
    int count = 0;

    void solve(int n, int k, string& curr) {
        if (curr.length() == n) {
            count++;
            if (count == k)
                res = curr;
            return;
        }

        for (char ch : {'a', 'b', 'c'}) {
            if (res != "")
                return;
            if (curr.empty() || ch != curr.back()) {
                curr.push_back(ch);
                solve(n, k, curr);
                curr.pop_back();
            }
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        solve(n, k, curr);
        return res;
    }
};