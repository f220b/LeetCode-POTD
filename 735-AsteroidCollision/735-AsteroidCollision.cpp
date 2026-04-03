// Last updated: 4/3/2026, 1:59:13 PM
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st; 
        for (int asteroid : asteroids) {
            bool destroyed = false;     // To check if current asteroid survived or not
            while (!st.empty() && st.top() > 0 && asteroid < 0) {
                if (abs(asteroid) > abs(st.top())) {
                    st.pop();
                } else if (abs(asteroid) == abs(st.top())) {     // Both asteroids destroyed
                    st.pop();
                    destroyed = true;
                    break;
                } else {        // Current asteroid destroyed
                    destroyed = true;
                    break;
                }
            }
            if (destroyed == false)     // If current asteroid survived, push it into stack
                st.push(asteroid);
        }
        vector<int> result(st.size());
        for (int i = st.size() - 1; i >= 0; i--) {
            result[i] = st.top();
            st.pop();
        }
        return result;
    }
};