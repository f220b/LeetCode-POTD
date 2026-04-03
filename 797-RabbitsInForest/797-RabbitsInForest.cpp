// Last updated: 4/3/2026, 1:58:52 PM
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        int rabbits = 0;
        unordered_map<int, int> mpp;
        for (int ele : answers) {
            if (ele == 0) {
                rabbits++;
                continue;
            }
            mpp[ele]++;
            if (mpp[ele] == (ele + 1)) {
                rabbits += ele + 1;
                mpp[ele] = 0;
            }
        }
        for (auto& itr : mpp) {
            if (itr.second > 0) {
                rabbits += itr.first + 1;
            }
        }
        return rabbits;
    }
};