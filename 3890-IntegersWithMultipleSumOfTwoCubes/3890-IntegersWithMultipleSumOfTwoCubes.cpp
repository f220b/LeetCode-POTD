// Last updated: 9/5/2026, 12:02:27 AM
class Solution {
public:
    vector<int> findGoodIntegers(int n) {
        unordered_map<int, int> freq;
        int a = 1;
        while (2 * a * a * a <= n) {
            int b = a;
            while (a * a * a + b * b * b <= n) {
                int num = a * a * a + b * b * b;
                freq[num]++;
                b++;
            }
            a++;
        }
        vector<int> result;
        for (auto& [sum, count] : freq) {
            if (count >= 2)
                result.push_back(sum);
        }
        sort(result.begin(), result.end());
        return result;
    }
};