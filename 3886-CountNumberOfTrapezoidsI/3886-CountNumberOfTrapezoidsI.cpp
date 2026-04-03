// Last updated: 4/3/2026, 1:49:33 PM
class Solution {
public:
    typedef long long ll;
    int mod = 1000000007;
    int countTrapezoids(vector<vector<int>>& points) {
        map<int, ll> mpp;
        for(auto& itr : points) 
            mpp[itr[1]]++;
        for(auto& itr : mpp) {
            int key = itr.first;
            ll value = itr.second;
            itr.second = (value * (value - 1)) / 2;
            itr.second %= mod;
        }
        ll prod = 0, sum = 0;
        for(auto& itr : mpp) {
            ll val = itr.second;
            prod = (prod + (sum * val) % mod) % mod;
            sum = (sum + val) % mod;
        }
        return (int)prod;
    }
};