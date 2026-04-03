// Last updated: 4/3/2026, 1:54:24 PM
class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, 
                                  vector<vector<string>>& ingredients, 
                                  vector<string>& supplies) {
        unordered_set<string> available(supplies.begin(), supplies.end());
        unordered_map<string, vector<string>> graph;
        unordered_map<string, int> indegree;
        queue<string> q;
        vector<string> result;

        for (int i = 0; i < recipes.size(); i++) {
            indegree[recipes[i]] = ingredients[i].size();
            for (string& ing : ingredients[i]) {
                graph[ing].push_back(recipes[i]);
            }
        }

        for (string& item : supplies) {
            q.push(item);
        }

        while (!q.empty()) {
            string item = q.front();
            q.pop();

            if (indegree.find(item) != indegree.end()) {
                result.push_back(item);
            }

            for (string& next : graph[item]) {
                indegree[next]--;
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return result;
    }
};
