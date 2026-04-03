// Last updated: 4/3/2026, 1:56:39 PM
class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);

        string a = s;
        for (char& ch : a) {
            if (ch != '9') {
                char target = ch;
                for (char& c : a)
                    if (c == target)
                        c = '9';
                break;
            }
        }

        string b = s;
        if (b[0] != '1') {
            char target = b[0];
            for (char& c : b)
                if (c == target)
                    c = '1';
        } else {
            for (int i = 1; i < b.size(); i++) {
                if (b[i] != '0' && b[i] != '1') {
                    char target = b[i];
                    for (int j = 1; j < b.size(); j++)
                        if (b[j] == target)
                            b[j] = '0';
                    break;
                }
            }
        }

        int maxVal = stoi(a);
        int minVal = stoi(b);
        return maxVal - minVal;
    }
};
