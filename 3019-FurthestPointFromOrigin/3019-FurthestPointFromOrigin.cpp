// Last updated: 4/28/2026, 2:52:24 PM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int counts = 0;
        int wildcards = 0;

        for (char c : moves) {
            if (c == 'L') {
                counts--;
            } else if (c == 'R') {
                counts++;
            } else {
                wildcards++;
            }
        }

        return abs(counts) + wildcards;
    }
};