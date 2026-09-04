// Last updated: 9/5/2026, 12:02:04 AM
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0, counter = 0;
        for (string event : events) {
            if (counter == 10)
                return {score, counter};

            if (event == "W")
                counter++;
            else if (event == "WD" || event == "NB")
                score++;
            else
                score += stoi(event);
        }
        return {score, counter};
    }
};