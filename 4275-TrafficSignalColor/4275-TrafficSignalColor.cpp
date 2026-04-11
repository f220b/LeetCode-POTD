// Last updated: 11/4/2026, 11:25:51 pm
class Solution {
public:
    string trafficSignal(int timer) {
        if (timer == 0)
            return "Green";
        else if (timer == 30)
            return "Orange";
        else if (timer > 30 && timer <= 90)
            return "Red";
        return "Invalid";
    }
};