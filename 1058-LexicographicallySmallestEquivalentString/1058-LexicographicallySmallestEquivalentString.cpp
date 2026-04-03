// Last updated: 4/3/2026, 1:57:58 PM
class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (parent[x] != x)
            parent[x] = find(parent[x], parent);
        return parent[x];
    }

    void unite(int x, int y, vector<int>& parent) {
        int px = find(x, parent);
        int py = find(y, parent);
        if (px == py) return;
        if (px < py) parent[py] = px;
        else parent[px] = py;
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i) parent[i] = i;

        for (int i = 0; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a', parent);
        }

        string res = "";
        for (char c : baseStr) {
            res += char(find(c - 'a', parent) + 'a');
        }

        return res;
    }
};