// Last updated: 4/3/2026, 1:54:27 PM
class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        vector<int> mpp(10, 0);
        vector<int> result;
        for (int i : digits) {
            mpp[i]++;
        }
        for (int i = 1; i < 10; i++) {
            if (mpp[i] == 0)
                continue;
            mpp[i]--;
            for (int j = 0; j < 10; j++) {
                if (mpp[j] == 0)
                    continue;
                mpp[j]--;
                for (int k = 0; k <= 8; k += 2) {
                    if (mpp[k] == 0)
                        continue;
                    mpp[k]--;
                    int num = (i * 100) + (j * 10) + k;
                    result.push_back(num);
                    mpp[k]++;
                }
                mpp[j]++;
            }
            mpp[i]++;
        }
        return result;
    }
};