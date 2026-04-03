// Last updated: 4/3/2026, 1:48:59 PM
class RideSharingSystem {
public:
    queue<int> drivers;
    queue<int> riders;
    unordered_set<int> activeRiders;

    RideSharingSystem() {}

    void addRider(int riderId) {
        riders.push(riderId);
        activeRiders.insert(riderId);
    }

    void addDriver(int driverId) { drivers.push(driverId); }

    vector<int> matchDriverWithRider() {
        while (!riders.empty() &&
               activeRiders.find(riders.front()) == activeRiders.end())
            riders.pop();
        if (riders.empty() || drivers.empty())
            return {-1, -1};

        int driverId = drivers.front();
        drivers.pop();
        int riderId = riders.front();
        riders.pop();
        activeRiders.erase(riderId);

        return {driverId, riderId};
    }

    void cancelRider(int riderId) {
        if (activeRiders.count(riderId))
            activeRiders.erase(riderId);
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */