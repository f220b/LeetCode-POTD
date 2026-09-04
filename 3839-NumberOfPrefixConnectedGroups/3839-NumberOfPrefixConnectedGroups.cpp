// Last updated: 9/5/2026, 12:04:50 AM
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