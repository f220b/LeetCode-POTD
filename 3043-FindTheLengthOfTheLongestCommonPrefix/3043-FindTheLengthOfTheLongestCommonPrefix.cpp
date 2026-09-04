// Last updated: 9/5/2026, 12:15:31 AM
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st;
        // O(n * log(k))
        for(int num : arr1) {
            string str = to_string(num);
            string prefix = "";
            for(char ch : str) {
                prefix += ch;
                st.insert(prefix);
            }
        }
        // O(n * log(k))
        int maxLen = 0;
        for(int num : arr2) {
            string str = to_string(num);
            string prefix = "";
            int size = 0;
            for(char ch : str) {
                prefix += ch;
                size++;
                if(st.count(prefix)) 
                    maxLen = max(maxLen, size);
            }
        }
        return maxLen;
    }
};