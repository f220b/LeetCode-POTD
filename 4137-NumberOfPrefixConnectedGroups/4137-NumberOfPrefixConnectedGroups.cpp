// Last updated: 4/3/2026, 1:48:56 PM
class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string, int> mpp;
        for(string str : words) {
            if(str.length() < k)
                continue;
            string prefix = str.substr(0, k);
            mpp[prefix]++;
        }
        int count = 0;
        for(auto itr : mpp) {
            if(itr.second >= 2)
                count++;
        }
        return count;
    }
};