// Last updated: 9/5/2026, 12:05:54 AM
class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int peaks = 0, valleys = 0;
        for (int i = num1; i <= num2; i++) {
            if (i < 100)
                continue;

            string str = to_string(i);
            for (int i = 1; i < str.length() - 1; i++) {
                if (str[i] > str[i - 1] && str[i] > str[i + 1])
                    peaks++;
                else if (str[i] < str[i - 1] && str[i] < str[i + 1])
                    valleys++;
            }
        }
        return peaks + valleys;
    }
};