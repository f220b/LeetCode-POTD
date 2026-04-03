// Last updated: 4/3/2026, 1:53:58 PM
#include <numeric>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> st;
        for (int x : nums) {
            st.push_back(x);
            while (st.size() > 1) {
                int a = st[st.size() - 2];
                int b = st[st.size() - 1];
                int g = gcd(a, b);
                if (g == 1)
                    break;
                long long l = 1LL * a / g * b;
                st.pop_back();
                st.pop_back();
                st.push_back((int)l);
            }
        }
        return st;
    }
};
