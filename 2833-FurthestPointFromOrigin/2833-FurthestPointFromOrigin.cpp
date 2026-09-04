// Last updated: 9/5/2026, 12:17:31 AM
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