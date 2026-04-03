// Last updated: 4/3/2026, 1:50:24 PM
class TaskManager {
    unordered_map<int, pair<int, int>> taskMap;
    priority_queue<tuple<int, int, int>> pq;

public:
    TaskManager(vector<vector<int>>& tasks) {
        for (auto& t : tasks) {
            int u = t[0], id = t[1], p = t[2];
            taskMap[id] = {u, p};
            pq.push({p, id, u});
        }
    }

    void add(int userId, int taskId, int priority) {
        taskMap[taskId] = {userId, priority};
        pq.push({priority, taskId, userId});
    }

    void edit(int taskId, int newPriority) {
        int userId = taskMap[taskId].first;
        taskMap[taskId] = {userId, newPriority};
        pq.push({newPriority, taskId, userId});
    }

    void rmv(int taskId) { taskMap.erase(taskId); }

    int execTop() {
        while (!pq.empty()) {
            auto [p, id, u] = pq.top();
            if (taskMap.count(id) && taskMap[id].second == p) {
                pq.pop();
                taskMap.erase(id);
                return u;
            }
            pq.pop();
        }
        return -1;
    }
};
