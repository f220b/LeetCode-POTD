// Last updated: 4/3/2026, 2:00:20 PM
class Solution {
public:
    int countBits(int n) {
        int cnt = 0;
        while (n) {
            n &= (n - 1);
            cnt++;
        }
        return cnt;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 60; j++) {
                if (countBits(i) + countBits(j) == turnedOn) {
                    string time =
                        to_string(i) + (j < 10 ? ":0" : ":") + to_string(j);
                    result.push_back(time);
                }
            }
        }
        return result;
    }
};