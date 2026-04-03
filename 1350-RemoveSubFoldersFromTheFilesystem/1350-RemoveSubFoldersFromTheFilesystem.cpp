// Last updated: 4/3/2026, 1:57:29 PM
class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(), folder.end());
        vector<string> ans;

        for (string& f : folder) {
            if (ans.empty() ||
                f.compare(0, ans.back().size(), ans.back()) != 0 ||
                f[ans.back().size()] != '/') {
                ans.push_back(f);
            }
        }

        return ans;
    }
};
