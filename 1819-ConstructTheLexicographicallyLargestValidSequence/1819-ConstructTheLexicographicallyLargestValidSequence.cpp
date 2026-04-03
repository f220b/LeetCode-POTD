// Last updated: 4/3/2026, 1:55:41 PM
class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
        int size = 2 * n - 1;
        vector<int> result(size, 0);     // Initialize with 0 (empty)
        vector<bool> used(n + 1, false); // To track used numbers

        function<bool(int)> backtrack = [&](int index) {
            if (index == size)
                return true; // Base case: all positions filled

            if (result[index] != 0)
                return backtrack(index + 1); // Skip filled positions

            for (int num = n; num >= 1;
                 num--) { // Start from highest for lexicographical order
                if (used[num])
                    continue;

                if (num == 1) { // Place '1' (only once)
                    result[index] = 1;
                    used[1] = true;

                    if (backtrack(index + 1))
                        return true;

                    // Backtrack
                    result[index] = 0;
                    used[1] = false;
                } else { // Place 'num' at two valid positions
                    int secondIndex = index + num;
                    if (secondIndex < size && result[secondIndex] == 0) {
                        result[index] = result[secondIndex] = num;
                        used[num] = true;

                        if (backtrack(index + 1))
                            return true;

                        // Backtrack
                        result[index] = result[secondIndex] = 0;
                        used[num] = false;
                    }
                }
            }
            return false;
        };

        backtrack(0);
        return result;
    }
};
