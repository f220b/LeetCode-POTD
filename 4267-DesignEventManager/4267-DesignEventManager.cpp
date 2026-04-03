// Last updated: 4/3/2026, 1:48:15 PM
class EventManager {
public:
    map<int, set<int>> manager;
    unordered_map<int, int> eventMap;

    EventManager(vector<vector<int>>& events) {
        for (auto& e : events) {
            int eventId = e[0], priority = e[1];
            manager[priority].insert(eventId);
            eventMap[eventId] = priority;
        }
    }

    void updatePriority(int eventId, int newPriority) {
        if (eventMap.find(eventId) == eventMap.end())
            return;

        int oldPriority = eventMap[eventId];
        manager[oldPriority].erase(eventId);
        if (manager[oldPriority].empty())
            manager.erase(oldPriority);

        manager[newPriority].insert(eventId);
        eventMap[eventId] = newPriority;
    }

    int pollHighest() {
        if (manager.empty())
            return -1;

        auto mapIt = prev(manager.end());
        auto setIt = mapIt->second.begin();
        int eventId = *setIt;

        mapIt->second.erase(setIt);
        if (mapIt->second.empty())
            manager.erase(mapIt);
        eventMap.erase(eventId);

        return eventId;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */