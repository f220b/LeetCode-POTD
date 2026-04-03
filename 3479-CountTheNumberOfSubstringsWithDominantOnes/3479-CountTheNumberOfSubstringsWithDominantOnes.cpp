// Last updated: 4/3/2026, 1:51:16 PM
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.length();
        vector<int> prefixOnes(n, 0);
        prefixOnes[0] = (s[0] == '1') ? 1 : 0;
        for (int i = 1; i < n; i++) {
            if (s[i] == '1')
                prefixOnes[i] = prefixOnes[i - 1] + 1;
            else
                prefixOnes[i] = prefixOnes[i - 1];
        }
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                int ones =
                    prefixOnes[j] - ((i - 1 >= 0) ? prefixOnes[i - 1] : 0);
                int zero = (j - i + 1) - ones;
                if (zero * zero > ones) {
                    int needOnes = (zero * zero) - ones;
                    j += (needOnes -
                          1); // j++ in next step will otherwise skip this index
                } else if ((zero * zero) == ones) {
                    count += 1;
                } else {
                    count += 1;

                    int k = sqrt(ones) - zero;
                    int nextJ = j + k;

                    if (nextJ >= n) {
                        count += (n - j - 1);
                        break;
                    } else {
                        count += k;
                    }
                    j = nextJ;
                }
            }
        }
        return count;
    }
};