// Last updated: 4/3/2026, 1:56:31 PM
class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // Initialize the reachability matrix
        vector<vector<bool>> reachable(numCourses, vector<bool>(numCourses, false));

        // Mark direct prerequisites as reachable
        for (auto& prereq : prerequisites) {
            reachable[prereq[0]][prereq[1]] = true;
        }

        // Apply Floyd-Warshall algorithm to find all indirect prerequisites
        for (int k = 0; k < numCourses; k++) {
            for (int i = 0; i < numCourses; i++) {
                for (int j = 0; j < numCourses; j++) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }

        // Answer each query
        vector<bool> result;
        for (auto& query : queries) {
            result.push_back(reachable[query[0]][query[1]]);
        }

        return result;
    }
};
