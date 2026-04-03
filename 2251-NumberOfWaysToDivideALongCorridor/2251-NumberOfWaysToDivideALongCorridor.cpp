// Last updated: 4/3/2026, 1:54:13 PM
class Solution {
public:
    int numberOfWays(string corridor) {
        const long long MOD = 1e9 + 7;
        vector<int> seatPos;
        
        for (int i = 0; i < corridor.size(); i++) {
            if (corridor[i] == 'S')
                seatPos.push_back(i);
        }
        
        int totalSeats = seatPos.size();
        if (totalSeats == 0 || totalSeats % 2 != 0)
            return 0;
        
        long long ways = 1;
        
        for (int i = 2; i < totalSeats; i += 2) {
            int plantsBetween = seatPos[i] - seatPos[i - 1] - 1;
            ways = (ways * (plantsBetween + 1)) % MOD;
        }
        
        return ways;
    }
};
