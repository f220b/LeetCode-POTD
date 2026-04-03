// Last updated: 4/3/2026, 1:55:56 PM
class Solution {
public:
    string findLexSmallestString(string s, int a, int b) {
        queue<string> q;
        unordered_map<string, bool> visited;

        q.push(s);
        visited[s] = true;
        string smallest = s;
        while (!q.empty()) {
            string str = q.front();
            q.pop();

            if (smallest > str)
                smallest = str;

            string temp = str;
            // Add a
            for (int i = 1; i < temp.length(); i += 2) {
                temp[i] = ((temp[i] - '0' + a) % 10) + '0';
            }
            if (!visited[temp]) {
                q.push(temp);
                visited[temp] = true;
            }
            // Rotate by b
            reverse(temp.begin(), temp.end());
            reverse(temp.begin(), temp.begin() + b);
            reverse(temp.begin() + b, temp.end());

            if (!visited[temp]) {
                q.push(temp);
                visited[temp] = true;
            }
        }
        return smallest;
    }
};