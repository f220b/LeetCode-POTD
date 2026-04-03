// Last updated: 4/3/2026, 1:58:27 PM
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> result;
        unordered_set<int> prev;

        for(int num : arr) {
            unordered_set<int> curr;
            curr.insert(num);

            for(int x : prev)
                curr.insert(x | num);
            
            prev = curr;

            for(int x : curr)
                result.insert(x);
        }
        return result.size();
    }
};