// Last updated: 4/3/2026, 1:49:27 PM
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        int n = code.size();
        vector<pair<string, string>> validCoupons;
        unordered_map<string, int> order = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

        // Validate coupons
        for (int i = 0; i < n; ++i) {
            if (!isActive[i]) continue;
            if (order.find(businessLine[i]) == order.end()) continue; // invalid businessLine
            if (code[i].empty()) continue;
            
            bool validCode = true;
            for (char c : code[i]) {
                if (!isalnum(c) && c != '_') {
                    validCode = false;
                    break;
                }
            }
            if (!validCode) continue;

            validCoupons.push_back({businessLine[i], code[i]});
        }

        // Sort by businessLine order first, then by code lexicographically
        sort(validCoupons.begin(), validCoupons.end(), [&](auto &a, auto &b) {
            if (order[a.first] != order[b.first])
                return order[a.first] < order[b.first];
            return a.second < b.second;
        });

        // Extract only the codes
        vector<string> result;
        for (auto &p : validCoupons) result.push_back(p.second);
        return result;
    }
};
