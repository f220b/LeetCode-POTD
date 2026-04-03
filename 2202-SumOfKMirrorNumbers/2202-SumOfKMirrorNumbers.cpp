// Last updated: 4/3/2026, 1:54:30 PM
class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }

    string toBaseK(long long num, int k) {
        string res = "";
        while (num > 0) {
            res += to_string(num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;

        for (int length = 1; count < n; length++) {
            int start = pow(10, (length - 1) / 2);
            int end = pow(10, (length + 1) / 2);

            for (int half = start; half < end && count < n; half++) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());

                string full = (length % 2 == 0) ? s + rev : s + rev.substr(1);

                long long num = stoll(full);

                if (isPalindrome(toBaseK(num, k))) {
                    ans += num;
                    count++;
                }
            }
        }

        return ans;
    }
};
