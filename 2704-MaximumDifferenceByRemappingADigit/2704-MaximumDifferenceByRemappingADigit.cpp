// Last updated: 4/3/2026, 1:52:48 PM
class Solution {
public:
    int remap(string s, char from, char to) {
        for (char& c : s) {
            if (c == from)
                c = to;
        }
        return stoi(s);
    }

    int minMaxDifference(int num) {
        string strNum = to_string(num);
        int minVal = num, maxVal = num;

        for (char d1 = '0'; d1 <= '9'; d1++) {
            for (char d2 = '0'; d2 <= '9'; d2++) {
                if (d1 == d2)
                    continue;
                string temp = strNum;
                int changed = remap(temp, d1, d2);
                minVal = min(minVal, changed);
                maxVal = max(maxVal, changed);
            }
        }

        return maxVal - minVal;
    }
};
