// Last updated: 4/3/2026, 1:55:40 PM
class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages,
                         vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> knows(m + 1);
        for (int i = 0; i < m; i++) {
            for (int lang : languages[i])
                knows[i + 1].insert(lang);
        }

        vector<pair<int, int>> needTeach;
        for (auto& f : friendships) {
            int u = f[0], v = f[1];
            bool ok = false;
            for (int lang : knows[u]) {
                if (knows[v].count(lang)) {
                    ok = true;
                    break;
                }
            }
            if (!ok)
                needTeach.push_back({u, v});
        }

        if (needTeach.empty())
            return 0;

        int ans = m;
        for (int lang = 1; lang <= n; lang++) {
            unordered_set<int> mustLearn;
            for (auto& p : needTeach) {
                if (!knows[p.first].count(lang))
                    mustLearn.insert(p.first);
                if (!knows[p.second].count(lang))
                    mustLearn.insert(p.second);
            }
            ans = min(ans, (int)mustLearn.size());
        }
        return ans;
    }
};
