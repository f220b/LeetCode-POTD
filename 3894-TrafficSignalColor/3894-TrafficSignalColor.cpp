// Last updated: 9/5/2026, 12:02:15 AM
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