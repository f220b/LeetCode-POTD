// Last updated: 9/5/2026, 12:33:23 AM
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
