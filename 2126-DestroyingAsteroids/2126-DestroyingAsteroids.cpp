// Last updated: 9/5/2026, 12:23:18 AM
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long newMass = mass;
        
        for (int m : asteroids) {
            if (newMass < m)
                return false;
            newMass += (long long)m;
        }
        return true;
    }
};