// Last updated: 9/5/2026, 12:15:26 AM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(int i : apple)
            sum += i;
        
        sort(capacity.begin(), capacity.end(), greater<int>());
        int temp = 0, count = 0;
        for(int cap : capacity) {
            temp += cap;
            count++;
            if(temp >= sum)
                return count;
        }
        return 0;
    }
};