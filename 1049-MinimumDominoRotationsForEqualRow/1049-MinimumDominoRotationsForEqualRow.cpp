// Last updated: 4/3/2026, 1:58:03 PM
class Solution {
public:
    int rotationMatching(int num, vector<int>& first, vector<int>& second,
                         int size) {
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (first[i] == num) {
                continue;
            } else if (second[i] == num) {
                count++;
            } else {
                return INT_MAX;
            }
        }
        return count;
    }
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int minSwaps = INT_MAX;
        int n = tops.size();

        for (int i = 1; i <= 6; i++) {
            int countTops = rotationMatching(i, tops, bottoms, n);
            int countBottoms = INT_MAX;
            if (countTops != INT_MAX) {
                countBottoms = rotationMatching(i, bottoms, tops, n);
            }
            minSwaps = min(minSwaps, min(countTops, countBottoms));
        }
        return minSwaps == INT_MAX ? -1 : minSwaps;
    }
};