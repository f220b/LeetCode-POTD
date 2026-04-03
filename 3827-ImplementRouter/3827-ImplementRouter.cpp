// Last updated: 4/3/2026, 1:49:50 PM
#include <bits/stdc++.h>
using namespace std;

class Router {
    int memoryLimit;
    queue<tuple<int, int, int>> packets;
    unordered_set<string> seen;
    unordered_map<int, vector<int>> destMap;

    string makeKey(int s, int d, int t) {
        return to_string(s) + "#" + to_string(d) + "#" + to_string(t);
    }

    void removeOldest() {
        auto [s, d, t] = packets.front();
        packets.pop();
        seen.erase(makeKey(s, d, t));
        auto& v = destMap[d];
        int idx = lower_bound(v.begin(), v.end(), t) - v.begin();
        if (idx < v.size() && v[idx] == t)
            v.erase(v.begin() + idx);
    }

public:
    Router(int memoryLimit) { this->memoryLimit = memoryLimit; }

    bool addPacket(int source, int destination, int timestamp) {
        string key = makeKey(source, destination, timestamp);
        if (seen.count(key))
            return false;
        if (packets.size() == memoryLimit)
            removeOldest();
        packets.push({source, destination, timestamp});
        seen.insert(key);
        destMap[destination].push_back(timestamp); // monotonic
        return true;
    }

    vector<int> forwardPacket() {
        if (packets.empty())
            return {};
        auto [s, d, t] = packets.front();
        packets.pop();
        seen.erase(makeKey(s, d, t));
        auto& v = destMap[d];
        int idx = lower_bound(v.begin(), v.end(), t) - v.begin();
        if (idx < v.size() && v[idx] == t)
            v.erase(v.begin() + idx);
        return {s, d, t};
    }

    int getCount(int destination, int startTime, int endTime) {
        auto& v = destMap[destination];
        auto it1 = lower_bound(v.begin(), v.end(), startTime);
        auto it2 = upper_bound(v.begin(), v.end(), endTime);
        return it2 - it1;
    }
};
