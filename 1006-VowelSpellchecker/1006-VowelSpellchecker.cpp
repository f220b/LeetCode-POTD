// Last updated: 4/3/2026, 1:58:13 PM
class Solution {
public:
    string toDevowel(string s) {
        for (auto& c : s) {
            c = tolower(c);
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return s;
    }

    vector<string> spellchecker(vector<string>& wordlist,
                                vector<string>& queries) {
        unordered_set<string> exact(wordlist.begin(), wordlist.end());
        unordered_map<string, string> capMap, vowelMap;

        for (string w : wordlist) {
            string lower = w;
            for (auto& c : lower)
                c = tolower(c);
            if (!capMap.count(lower))
                capMap[lower] = w;
            string vow = toDevowel(lower);
            if (!vowelMap.count(vow))
                vowelMap[vow] = w;
        }

        vector<string> ans;
        for (string q : queries) {
            if (exact.count(q)) {
                ans.push_back(q);
                continue;
            }
            string lower = q;
            for (auto& c : lower)
                c = tolower(c);
            if (capMap.count(lower)) {
                ans.push_back(capMap[lower]);
                continue;
            }
            string vow = toDevowel(lower);
            if (vowelMap.count(vow)) {
                ans.push_back(vowelMap[vow]);
                continue;
            }
            ans.push_back("");
        }
        return ans;
    }
};
