// Last updated: 9/5/2026, 12:03:47 AM
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        multiset<int> st;
        for(int bulb : bulbs) {
            if(st.count(bulb))
                st.erase(bulb);
            else
                st.insert(bulb);
        }
        vector<int> result;
        for(int i : st)
            result.push_back(i);
        return result;
    }
};