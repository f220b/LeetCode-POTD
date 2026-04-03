// Last updated: 4/3/2026, 1:53:54 PM
class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        int left = 0, right = n - 1;

        // Remove leading L (they move left forever)
        while (left < n && directions[left] == 'L')
            left++;

        // Remove trailing R (they move right forever)
        while (right >= 0 && directions[right] == 'R')
            right--;

        int collisions = 0;
        for (int i = left; i <= right; i++) {
            if (directions[i] != 'S')
                collisions++;
        }
        return collisions;
    }
};
