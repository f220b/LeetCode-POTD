// Last updated: 4/3/2026, 1:48:34 PM
class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<int, char> mpp;
        for (int i = 0; i < 26; i++)
            mpp[25 - i] = i + 'a';

        string result = "";
        for (string str : words) {
            int sum = 0;
            for (char ch : str) 
                sum += weights[ch - 'a'];
            sum %= 26;
            result = result + mpp[sum];
        }
        return result;
    }
};