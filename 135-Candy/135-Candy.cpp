// Last updated: 4/3/2026, 2:02:12 PM
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        int curr = 1;
        int sum = 1;

        while(curr < n) {
            while(curr < n && ratings[curr] == ratings[curr - 1]) {
                sum += 1;
                curr++;
            }
            int peak = 1;
            while(curr < n && ratings[curr] > ratings[curr - 1]) {
                sum += ++peak;
                curr++;
            }
            int down = 1;
            while(curr < n && ratings[curr] < ratings[curr - 1]){
                sum += down++;
                curr++;
            }
            sum += (down > peak) ? (down - peak) : 0;
        }
        return sum;
    }
};