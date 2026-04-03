// Last updated: 4/3/2026, 1:59:10 PM
class Solution {
public:
    unordered_map<string, vector<char>> mp;
    unordered_map<string, bool> dp;

    bool dfs(string curr) {
        if (curr.size() == 1)
            return true;

        if (dp.count(curr))
            return dp[curr];

        vector<string> nextRows;
        buildNextRows(curr, 0, "", nextRows);

        for (string& next : nextRows) {
            if (dfs(next))
                return dp[curr] = true;
        }

        return dp[curr] = false;
    }

    void buildNextRows(string& curr, int idx, string path,
                       vector<string>& res) {
        if (idx == curr.size() - 1) {
            res.push_back(path);
            return;
        }

        string key;
        key += curr[idx];
        key += curr[idx + 1];

        if (!mp.count(key))
            return;

        for (char ch : mp[key]) {
            buildNextRows(curr, idx + 1, path + ch, res);
        }
    }

    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for (string& a : allowed) {
            string key;
            key += a[0];
            key += a[1];
            mp[key].push_back(a[2]);
        }
        return dfs(bottom);
    }
};
