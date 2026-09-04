// Last updated: 9/5/2026, 12:32:26 AM
class Solution {
public:
    int n;
    vector<int> visited;
    bool helper(vector<int>& arr, int i) {
        if (arr[i] == 0)
            return true;

        visited[i] = 1;
        bool case1 = false, case2 = false;
        if (i - arr[i] >= 0 && !visited[i - arr[i]])
            case1 = helper(arr, i - arr[i]);
        if (i + arr[i] < n && !visited[i + arr[i]])
            case2 = helper(arr, i + arr[i]);

        return case1 || case2;
    }
    bool canReach(vector<int>& arr, int start) {
        n = arr.size();
        visited.resize(n, 0);
        visited[start] = 1;
        return helper(arr, start);
    }
};