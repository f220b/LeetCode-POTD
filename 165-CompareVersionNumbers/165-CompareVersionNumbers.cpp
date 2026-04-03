// Last updated: 4/3/2026, 2:01:46 PM
class Solution {
private:
    vector<int> split(string& s) {
        vector<int> res;
        stringstream ss(s);
        string token;
        while (getline(ss, token, '.')) {
            res.push_back(stoi(token));
        }
        return res;
    }
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1 = split(version1);
        vector<int> v2 = split(version2);

        int n = max(v1.size(), v2.size());
        for (int i = 0; i < n; i++) {
            int a = (i < v1.size() ? v1[i] : 0);
            int b = (i < v2.size() ? v2[i] : 0);
            if (a < b)
                return -1;
            if (a > b)
                return 1;
        }
        return 0;
    }
};
