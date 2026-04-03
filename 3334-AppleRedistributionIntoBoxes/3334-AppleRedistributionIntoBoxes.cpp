// Last updated: 4/3/2026, 1:51:44 PM
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